#include "Controleur.hpp"


TControleur Controleur;

struct TCommande CommandeRecu;
String readSerial;


void setup() {

    Serial.begin(19200);

    CommandeRecu.CodeCommande = CCOrigine;


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

        if (readSerial == "1")
        {
            CommandeRecu.CodeCommande = CCBougerSansDessiner;
        }
        else if (readSerial == "2")
        {
            CommandeRecu.CodeCommande = CCPoint;
        }
        else if (readSerial == "+")
        {
            CommandeRecu.Position.dFinHorizontal++;
            CommandeRecu.Position.dFinVertical++;
        }
        else if (readSerial == "++")
        {
            CommandeRecu.Position.dFinHorizontal = CommandeRecu.Position.dFinHorizontal + 2;
            CommandeRecu.Position.dFinVertical = CommandeRecu.Position.dFinVertical + 2;
        }
        else if (readSerial == "+++")
        {
            CommandeRecu.Position.dFinHorizontal = CommandeRecu.Position.dFinHorizontal + 3;
            CommandeRecu.Position.dFinVertical = CommandeRecu.Position.dFinVertical + 3;
        }
        else if (readSerial == "-")
        {
            CommandeRecu.Position.dDepartHorizontal++;
            CommandeRecu.Position.dDepartVertical++;
        }
        else if (readSerial == "reset")
        {
            CommandeRecu.Position.dFinHorizontal = 0;
            CommandeRecu.Position.dFinVertical = 0;

        }
        else
        {
            CommandeRecu.CodeCommande = CCDiagonal ;
        }
        Serial.print("Position de depart (x,y) : (");
        Serial.print(CommandeRecu.Position.dDepartHorizontal);
        Serial.print(",");
        Serial.print(CommandeRecu.Position.dDepartVertical);
        Serial.println(")");

        Serial.print("Position voulu (x,y)     : (");
        Serial.print(CommandeRecu.Position.dFinHorizontal);
        Serial.print(",");
        Serial.print(CommandeRecu.Position.dFinVertical);
        Serial.println(")");


        Controleur.ExecuterCommande(&CommandeRecu);


        Serial.print("Position final : ");
        Serial.print("(");
        Serial.print(Controleur.dPositionHorizontal);
        Serial.print(",");
        Serial.print(Controleur.dPositionVertical);
        Serial.println(")");
        Serial.println("\n");


    }











}
