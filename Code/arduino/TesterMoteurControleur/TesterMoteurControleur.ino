#include "Controleur.hpp"


TControleur Controleur;

struct TCommande CommandeRecu;
String readSerial;


void setup() {

    Serial.begin(19200);

    CommandeRecu.CodeCommande = CCVertical;


    CommandeRecu.Position.dDepartHorizontal = 0;
    CommandeRecu.Position.dDepartVertical = 0;
    CommandeRecu.Position.dFinHorizontal = 0;
    CommandeRecu.Position.dFinVertical = 0;



    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
}

void loop() {

    delay(100);
    // wait until there's serial data available
    if (Serial.available() > 0) {
        readSerial = Serial.readString();


        Serial.print("Recu : ");
        Serial.println(readSerial);

        FlashLed(1000);
        delay(3000);

        if (readSerial == "1")
        {
            CommandeRecu.CodeCommande = CCDiagonal;
        }
        else if (readSerial == "2")
        {
            CommandeRecu.CodeCommande = CCPoint;
        }
        else if (readSerial == "+")
        {

            CommandeRecu.Position.dDepartHorizontal++;
            CommandeRecu.Position.dDepartVertical++;
            CommandeRecu.Position.dFinHorizontal++;
            CommandeRecu.Position.dFinVertical++;

        }
        else if (readSerial == "reset")
        {

            CommandeRecu.Position.dDepartHorizontal = 0;
            CommandeRecu.Position.dDepartVertical = 0;
            CommandeRecu.Position.dFinHorizontal = 0;
            CommandeRecu.Position.dFinVertical = 0;

        }
        else
        {
            CommandeRecu.CodeCommande = CCBougerSansDessiner;
        }
        Serial.print("CommandeRecu.Position.dDepartHorizontal : ");
        Serial.println(CommandeRecu.Position.dDepartHorizontal);
        Serial.print("CommandeRecu.Position.dFinHorizontal : ");
        Serial.println(CommandeRecu.Position.dFinHorizontal);
        Serial.print("CommandeRecu.Position.dDepartVertical : ");
        Serial.println(CommandeRecu.Position.dDepartVertical);
        Serial.print("CommandeRecu.Position.dFinVertical : ");
        Serial.println(CommandeRecu.Position.dFinVertical);


        Controleur.ExecuterCommande(&CommandeRecu);


        Serial.print("Position final du moteur ------------------------");
        Serial.print("dPositionHorizontal :");
        Serial.println(Controleur.dPositionHorizontal);
        Serial.print("dPositionVertical : ");
        Serial.println(Controleur.dPositionVertical);
        Serial.println("\n");


    }











}
