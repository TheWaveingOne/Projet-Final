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
    Serial.print("dPositionHorizontal : ");
    Serial.println(dPositionHorizontal);
    Serial.print("Commande->Position.dDepartHorizontal : ");
    Serial.println(Commande->Position.dDepartHorizontal);
    Serial.print("dPositionVertical : ");
    Serial.println(dPositionVertical);
    Serial.print("Commande->Position.dDepartVertical : ");
    Serial.println(Commande->Position.dDepartVertical);

    // Déplacer les 2 moteurs a la bonne position pour commencer a dessiner.
    if ((dPositionHorizontal != Commande->Position.dDepartHorizontal || dPositionVertical != Commande->Position.dDepartVertical) && Commande->CodeCommande != CCBougerSansDessiner)
    {
        struct TCommande DeplacerMoteur;

        DeplacerMoteur.CodeCommande = CCBougerSansDessiner;

        DeplacerMoteur.Position.dDepartHorizontal = dPositionHorizontal;
        DeplacerMoteur.Position.dDepartVertical = dPositionVertical;

        DeplacerMoteur.Position.dFinVertical = Commande->Position.dDepartVertical;
        DeplacerMoteur.Position.dFinHorizontal = Commande->Position.dDepartHorizontal;

        Serial.println("Dans le if pour placer le moteur--------------------- ");
        Serial.print("DeplacerMoteur.Position.dDepartHorizontal : ");
        Serial.println(DeplacerMoteur.Position.dDepartHorizontal);
        Serial.print("DeplacerMoteur.Position.dFinHorizontal : ");
        Serial.println(DeplacerMoteur.Position.dFinHorizontal);
        Serial.print("DeplacerMoteur.Position.dDepartVertical : ");
        Serial.println(DeplacerMoteur.Position.dDepartVertical);
        Serial.print("DeplacerMoteur.Position.dFinVertical : ");
        Serial.println(DeplacerMoteur.Position.dFinVertical);
        ExecuterCommande(&DeplacerMoteur);
        Serial.println("sorti le if pour placer le moteur-------------------- ");
    }


    dMouvementHorizontal = dPositionHorizontal - Commande->Position.dDepartHorizontal;
    dMouvementVertical = dPositionVertical - Commande->Position.dDepartVertical;



    switch (Commande->CodeCommande) {
    //! Retourner a l'origine
    case CCOrigine:
        dMouvementHorizontal = -dPositionHorizontal;
        dMouvementVertical = -dPositionVertical;

        break;
    //! Executer un mouvement horizontal
    case CCHorizontal:
        // inutile? a y penser

        break;
    //! Executer un mouvement vertical
    case CCVertical:
        // inutile? a y penser

        break;
    //! Executer un mouvement diagonal
    case CCDiagonal:

        FlashLed(500);
        FlashLed(500);
        FlashLed(500);
        Driver_Z.move(MMtoStep(3.5));

        SDriver.startMove(MMtoStep(dMouvementHorizontal), MMtoStep(dMouvementVertical));


        Driver_Z.move(MMtoStep(-3.5));

        break;
    //! Dessiner un point
    case CCPoint:
    
    Serial.println("qwerty\nasdfg\nzxcvb");
        FlashLed(1000);
        FlashLed(1000);

        Driver_Z.move(MMtoStep(3.5));

        delay(250);

        Driver_Z.move(MMtoStep(-3.5));

        break;
    //! Bouger les moteurs sans dessiner
    case CCBougerSansDessiner:

        SDriver.startMove(MMtoStep(dMouvementHorizontal), MMtoStep(dMouvementVertical));
        FlashLed(2000);

        break;
    //! Mauvais code
    default:
        iCodeErreur = 1;
        FlashLed(500);
        FlashLed(500);
        FlashLed(500);
        FlashLed(500);
        FlashLed(500);
        break;
    }


    dPositionHorizontal  = Commande->Position.dFinHorizontal;
    dPositionVertical  = Commande->Position.dFinVertical;

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
