/*!  @file                              Controleur.cpp
     @version                           1.00
     @brief                             Implémentation de la class pour controler des moteurs

     @internal

     projet                             Graveur de circuit imprimé (PCB) sur machine CNC

     @note                              Note au programmeur.

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-03-02
     @author                            Benoit Houle
     @note                              Entrée originale du code.
     @date                              2020-7-07
     @author                            Benoit Houle
     @note                              Ajout de TesterLimiteMoteurs().

     <hr width="100%" height="5">
*/
//****************************************************************************
#include <Arduino.h>
#include "Controleur.hpp"


DRV8834 Driver_X(MOTOR_STEPS, DIR_X, STEP_X);

DRV8834 Driver_Y(MOTOR_STEPS, DIR_Y, STEP_Y);

DRV8834 Driver_Z(MOTOR_STEPS, DIR_Z, STEP_Z);

MultiDriver MultiDrivers(Driver_X, Driver_Y);




TControleur::TControleur() {

  // Activer les moteurs

  Driver_X.begin(RPM, MICROSTEPS);
  Driver_Y.begin(RPM, MICROSTEPS);
  Driver_Z.begin(RPM, MICROSTEPS);

  Driver_X.setSpeedProfile(Driver_X.LINEAR_SPEED, MOTOR_ACCEL, MOTOR_DECEL);
  Driver_Y.setSpeedProfile(Driver_Y.LINEAR_SPEED, MOTOR_ACCEL, MOTOR_DECEL);
  Driver_Z.setSpeedProfile(Driver_Z.LINEAR_SPEED, MOTOR_ACCEL, MOTOR_DECEL);


  int iLimite_X = 0;
  int iLimite_Y = 0;
  int iLimite_Z = 0;

  double dPositionHorizontal = 0.0;
  double dPositionVertical = 0.0;

}




//** **************************************************************************


/*!  @brief                    Teste la limite d'un moteur

     @return                   Nombre de moteur qui n'ont pas touché la limite.
     @retval  0                Tous les moteurs ont touché leur limite.
     @retval  1                1 moteur n'a pas touché sa limite
     @retval  2                2 moteurs n'ont pas touchés leur limite
     @retval  3                3 moteurs n'ont pas touchés leur limite

     @internal

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-03-02
     @author                            Potato
     @note                              Entrée du code.

     <hr width="100%" height="5">
*/
int TControleur::TesterLimiteMoteurs() {
  int iCodeErreur = 0;

  //------------------------------------
  //Tester le moteur X.
  //------------------------------------
  Serial.print("Limite moteur X - Bouton jaune : ");
  Driver_X.startMove(TESTER_LIMITE_STEPS);
  for (iLimite_X = 0; digitalRead(LIMITE_X) && iLimite_X < TESTER_LIMITE_STEPS ; iLimite_X++)
  {
    Driver_X.nextAction();
  }
  Driver_X.stop();
  if (iLimite_X >= TESTER_LIMITE_STEPS) iCodeErreur++;
  Serial.println(iLimite_X);
  delay(250);

  //------------------------------------
  //Tester le moteur Y.
  //------------------------------------
  Serial.print("Limite moteur Y - Bouton Blanc : ");
  Driver_Y.startMove(TESTER_LIMITE_STEPS);
  for (iLimite_Y = 0; digitalRead(LIMITE_Y) && iLimite_Y < TESTER_LIMITE_STEPS ; iLimite_Y++)
  {
    Driver_Y.nextAction();
  }
  Driver_Y.stop();
  if (iLimite_Y >= TESTER_LIMITE_STEPS) iCodeErreur++;
  Serial.println(iLimite_Y);
  delay(250);

  //------------------------------------
  //Tester le moteur Z.
  //------------------------------------
  Serial.print("Limite moteur Z - Bouton Bleu  : ");
  Driver_Z.startMove(TESTER_LIMITE_STEPS);
  for (iLimite_Z = 0; digitalRead(LIMITE_Z) && iLimite_Z < TESTER_LIMITE_STEPS ; iLimite_Z++)
  {
    Driver_Z.nextAction();
  }
  Driver_Z.stop();
  if (iLimite_Z >= TESTER_LIMITE_STEPS) iCodeErreur++;
  Serial.println(iLimite_Z);
  delay(250);

  //------------------------------------
  //Replacer les 3 moteurs.
  //------------------------------------
  Driver_X.move(-iLimite_X);
  delay(250);
  Driver_Y.move(-iLimite_Y);
  delay(250);
  Driver_Z.move(-iLimite_Z);
  delay(250);

  //   Retourner le code d'erreur à la routine appelante.
  return iCodeErreur;
}

/*!  @brief                    Executer une commande

     @param   Commande         La commande a executer

     @internal

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-03-02
     @author                            Potato
     @note                              Entrée du code.

     <hr width="100%" height="5">
*/
int TControleur::ExecuterCommande(struct TCommande * Commande) {
  int iCodeErreur = 0;
  double dMouvementHorizontal = 0;
  double dMouvementVertical = 0;


  //------------------------------------
  //Appliquer les limites.
  //------------------------------------
  if (Commande->Position.dDepartHorizontal > (double)iLimite_X)
  {
    Commande->Position.dDepartHorizontal = (double)iLimite_X;
    iCodeErreur++;
  }
  if (Commande->Position.dDepartVertical > (double)iLimite_Y)
  {
    Commande->Position.dDepartVertical = (double)iLimite_Y;
    iCodeErreur++;
  }
  if (Commande->Position.dFinHorizontal > (double)iLimite_X)
  {
    Commande->Position.dFinHorizontal = (double)iLimite_X;
    iCodeErreur++;
  }
  if (Commande->Position.dFinVertical > (double)iLimite_Y)
  {
    Commande->Position.dFinVertical = (double)iLimite_Y;
    iCodeErreur++;
  }

  //--------------------------------------
  //Executer la commande selon son code.
  //--------------------------------------

  if (Commande->CodeCommande == CCOrigine)
  {
    dMouvementHorizontal = -dPositionHorizontal;
    dMouvementVertical = -dPositionVertical;

    MultiDrivers.move(MMtoStep(dMouvementHorizontal), MMtoStep(dMouvementVertical));
    delay(1000);

    dPositionHorizontal = 0;
    dPositionVertical = 0;
  }
  else if (Commande->CodeCommande == CCPoint)
  {
    dMouvementHorizontal = Commande->Position.dDepartHorizontal - dPositionHorizontal;
    dMouvementVertical = Commande->Position.dDepartVertical - dPositionVertical;

    MultiDrivers.move(MMtoStep(dMouvementHorizontal), MMtoStep(dMouvementVertical));

    Driver_Z.move(25);
    delay(1000);
    Driver_Z.move(-25);
    delay(1000);

    dPositionHorizontal = Commande->Position.dDepartHorizontal;
    dPositionVertical = Commande->Position.dDepartVertical;
  }
  else
  {
    //Si on a besoin de déplacer les moteurs avant de dessiner
    if (dPositionHorizontal != Commande->Position.dDepartHorizontal || dPositionVertical != Commande->Position.dDepartVertical || Commande->CodeCommande == CCBougerSansDessiner)
    {
      dMouvementHorizontal = Commande->Position.dDepartHorizontal - dPositionHorizontal;
      dMouvementVertical = Commande->Position.dDepartVertical - dPositionVertical;

      delay(1000);
      MultiDrivers.move(MMtoStep(dMouvementHorizontal), MMtoStep(dMouvementVertical));
      delay(1000);

      if (Commande->CodeCommande == CCBougerSansDessiner)
      {
        dPositionHorizontal = Commande->Position.dFinHorizontal;
        dPositionVertical = Commande->Position.dFinVertical;
      }
      else
      {
        dPositionHorizontal = Commande->Position.dDepartHorizontal;
        dPositionVertical = Commande->Position.dDepartVertical;
      }
    }

    //Dessiner une ligne
    if (Commande->CodeCommande == CCDiagonal)
    {
      dMouvementHorizontal = Commande->Position.dFinHorizontal - Commande->Position.dDepartHorizontal;
      dMouvementVertical = Commande->Position.dFinVertical - Commande->Position.dDepartVertical;

      Driver_Z.move(25);
      delay(1000);

      MultiDrivers.move(MMtoStep(dMouvementHorizontal), MMtoStep(dMouvementVertical));
      delay(1000);

      Driver_Z.move(-25);
      delay(1000);

      dPositionHorizontal = Commande->Position.dFinHorizontal;
      dPositionVertical = Commande->Position.dFinVertical;
    }
  }
  //   Retourner le code d'erreur à la routine appelante.
  return iCodeErreur;
}


/*!  @brief                    Calcule le nombre de step pou un nombre de millimètre

     @param   dMM              Le nombre de millimètre

     @return                   Nombre de step

     @internal

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-03-02
     @author                            Potato
     @note                              En raison du COVID, cette fonction n'est pas utile.

     <hr width="100%" height="5">
*/
long TControleur::MMtoStep(double dMM)
{
  long lVariableTemporaire = (long)dMM;
  return lVariableTemporaire;
}
