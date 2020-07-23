/*!  @file                              Controleur.cpp
     @version                           1.00
     @brief                             Implémentation de la class pour controler des moteurs

     @internal

     projet                             Controleur (Controleur)

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
#include <arduino.h>
#include "Controleur.hpp"

void FlashLed(int iTemps)
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(iTemps);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);

}

DRV8834 Driver_X(MOTOR_STEPS, DIR_X, STEP_X);

DRV8834 Driver_Y(MOTOR_STEPS, DIR_Y, STEP_Y);

DRV8834 Driver_Z(MOTOR_STEPS, DIR_Z, STEP_Z);

SyncDriver SDriver(Driver_X, Driver_Y);


TControleur::TControleur() {

// Activer les moteurs

    Driver_X.begin(RPM, MICROSTEPS);
    Driver_Y.begin(RPM, MICROSTEPS);
    Driver_Z.begin(RPM, MICROSTEPS);

    Driver_X.setSpeedProfile(Driver_X.LINEAR_SPEED, MOTOR_ACCEL, MOTOR_DECEL);
    Driver_Y.setSpeedProfile(Driver_Y.LINEAR_SPEED, MOTOR_ACCEL, MOTOR_DECEL);
    Driver_Z.setSpeedProfile(Driver_Z.LINEAR_SPEED, MOTOR_ACCEL, MOTOR_DECEL);

}




//** **************************************************************************

/*!  @brief                    Attendre une instruction du serveur

     @param   parm             Description de ce paramètre.

     @return                   Code d'erreur
     @retval  EXIT_SUCCESS     Aucune erreur.
     @retval  EXIT_FAILED      Erreur (échec).

     @internal

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-03-02
     @author                            Potato
     @note                              Entrée du code.

     <hr width="100%" height="5">
 */
void TControleur::ObtenirInstruction() {



}

/*!  @brief                    Teste la limite d'un moteur

     @param   parm             *Moteur*

     @return                   Code d'erreur
     @retval  EXIT_SUCCESS     Aucune erreur.
     @retval  EXIT_FAILED      Erreur (échec).

     @internal

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-03-02
     @author                            Potato
     @note                              Entrée du code.

     <hr width="100%" height="5">
 */
int TControleur::TesterLimiteMoteur(DRV8834 * DriverTester) {

    int iCodeErreur = 0;



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

    Serial.println("Dans executer commande-----------------------------");
    Serial.print("Position actuel : ");
    Serial.print("(");
    Serial.print(dPositionHorizontal);
    Serial.print(",");
    Serial.print(dPositionVertical);
    Serial.println(")");



    if(Commande->CodeCommande == CCOrigine)
    {
        Serial.println("Commande->CodeCommande == CCOrigine");
        dMouvementHorizontal = -dPositionHorizontal;
        dMouvementVertical = -dPositionVertical;

        SDriver.startMove(MMtoStep(dMouvementHorizontal), MMtoStep(dMouvementVertical));

        dPositionHorizontal = 0;
        dPositionVertical = 0;
    }
    //Si on veux juste dessiner un point
    else if(Commande->CodeCommande == CCPoint)
    {
        Serial.println("Commande->CodeCommande == CCPoint");

        FlashLed(1000);
        FlashLed(1000);


        dMouvementHorizontal = Commande->Position.dDepartHorizontal - dPositionHorizontal;
        dMouvementVertical = Commande->Position.dDepartVertical - dPositionVertical;

        SDriver.startMove(MMtoStep(dMouvementHorizontal), MMtoStep(dMouvementVertical));
        

        Driver_Z.move(MMtoStep(3.5));

        delay(250);

        Driver_Z.move(MMtoStep(-3.5));

        dPositionHorizontal = Commande->Position.dDepartHorizontal;
        dPositionVertical = Commande->Position.dDepartVertical;

    }
    else
    {
        //Si on a besoin de déplacer les moteurs avant de dessiner
        if (dPositionHorizontal != Commande->Position.dDepartHorizontal || dPositionVertical != Commande->Position.dDepartVertical || Commande->CodeCommande == CCBougerSansDessiner)
        {
            Serial.println("bouger les moteurs");
            dMouvementHorizontal = Commande->Position.dDepartHorizontal - dPositionHorizontal;
            dMouvementVertical = Commande->Position.dDepartVertical - dPositionVertical;

            SDriver.startMove(MMtoStep(dMouvementHorizontal), MMtoStep(dMouvementVertical));

            if(Commande->CodeCommande == CCBougerSansDessiner)
            {
                dPositionHorizontal = Commande->Position.dFinHorizontal;
                dPositionVertical = Commande->Position.dFinVertical;
            }
            else
            {
                dPositionHorizontal = Commande->Position.dDepartHorizontal;
                dPositionVertical = Commande->Position.dDepartVertical;
            }

            FlashLed(2000);
        }

        //Dessiner une ligne
        if(Commande->CodeCommande == CCDiagonal)
        {
            Serial.println("Commande->CodeCommande == CCDiagonal");
            dMouvementHorizontal = Commande->Position.dFinHorizontal - Commande->Position.dDepartHorizontal;
            dMouvementVertical = Commande->Position.dFinVertical - Commande->Position.dDepartVertical;

            Driver_Z.move(MMtoStep(3.5));

            SDriver.startMove(MMtoStep(dMouvementHorizontal), MMtoStep(dMouvementVertical));

            Driver_Z.move(MMtoStep(-3.5));


            dPositionHorizontal = Commande->Position.dFinHorizontal;
            dPositionVertical = Commande->Position.dFinVertical;



            FlashLed(500);
            FlashLed(500);
            FlashLed(500);

        }

    }







    Serial.println("sorti executer commande----------------------------");
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
    long VariableTemporaire = dMM;
    return VariableTemporaire;

}
