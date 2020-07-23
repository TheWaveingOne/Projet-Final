/*!  @file                              ControleurDrivers.ino

     @version                           1.00
     @brief                             Utilisation de la class pour controler des moteurs

     @internal

     projet                             Graveur de circuit imprimé (PCB) sur machine CNC

     @note                              Note au programmeur.

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-03-02
     @author                            Benoit Houle
     @note                              Entrée originale du code.

     <hr width="100%" height="5">
*/
//****************************************************************************
#include "Controleur.hpp"

// Contrôleur pour commander les 3 drivers.
TControleur Controleur;

//Information recu
String readSerial;

//Commande recu
struct TCommande CommandeRecu;

void setup() {

  Serial.begin(19200);

  CommandeRecu.CodeCommande = CCDiagonal;

  CommandeRecu.Position.dDepartHorizontal = 0;
  CommandeRecu.Position.dDepartVertical = 0;
  CommandeRecu.Position.dFinHorizontal = 0;
  CommandeRecu.Position.dFinVertical = 0;


  pinMode(LIMITE_X, INPUT_PULLUP);
  pinMode(LIMITE_Y, INPUT_PULLUP);
  pinMode(LIMITE_Z, INPUT_PULLUP);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  if (Controleur.TesterLimiteMoteurs())
  {
    Serial.println("Un ou des moteurs n'ont pas touché leur limite.");
  }
}

void loop() {

  delay(100);
  // Attendre de recevoir de l'information
  if (Serial.available() > 0) {
    readSerial = Serial.readString();

    //Serial.print("\n\n\nRecu : ");
    //Serial.println(readSerial);


    char InfoRecu[100];
    strcpy(InfoRecu, readSerial.c_str());
    char * pch;

    pch = strtok (InfoRecu, "(,)");
    String SCodeCommande = pch;
    CommandeRecu.CodeCommande = SCodeCommande.toInt();

    pch = strtok (NULL, "(,)");
    String SDepartHorizontal = pch;
    CommandeRecu.Position.dDepartHorizontal = SDepartHorizontal.toFloat();

    pch = strtok (NULL, "(,)");
    String SDepartVertical = pch;
    CommandeRecu.Position.dDepartVertical = SDepartVertical.toFloat();

    pch = strtok (NULL, "(,)");
    String SFinHorizontal = pch;
    CommandeRecu.Position.dFinHorizontal = SFinHorizontal.toFloat();

    pch = strtok (NULL, "(,)");
    String SFinVertical = pch;
    CommandeRecu.Position.dFinVertical = SFinVertical.toFloat();


    Serial.print("exec:");
    Serial.println(Controleur.ExecuterCommande(&CommandeRecu));
    
  }
}
