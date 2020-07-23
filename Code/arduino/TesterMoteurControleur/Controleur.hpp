/*!  @file                              Controleur.hpp
     @version                           1.00
     @brief                             Déclaration pour un contrôleur de moteurs

     @internal

     projet                             Graveur de circuit imprimé (PCB) sur machine CNC

     @note                              Fait pour un Arduino.

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-03-02
     @author                            Benoit Houle
     @note                              Entrée du code.

     <hr width="100%" height="5">
 */
//** **************************************************************************


#ifndef CONTROLEUR_HPP
#define CONTROLEUR_HPP

#ifdef __cplusplus
extern "C"
{
#endif

//** ==========================================================================
//** Insérer ici les déclarations.
//** ==========================================================================
//!
#include "Commande.hpp"
#include "SyncDriver.h"
#include "DRV8834.h"

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200

//180 = trop vite. fiare des tests----------------------------------------
// Target RPM for cruise speed
#define RPM 60
// Acceleration and deceleration values are always in FULL steps / s^2
#define MOTOR_ACCEL 2000
#define MOTOR_DECEL 1000

// Microstepping mode. If you hardwired it to save pins, set to the same value here.
#define MICROSTEPS 1

// Pin pour le moteur horizontal
#define DIR_X 2
#define STEP_X 3

// Pin pour le moteur vertical
#define DIR_Y 4
#define STEP_Y 5

// Pin pour le moteur de l'axe des Z
#define DIR_Z 7
#define STEP_Z 8
void FlashLed(int iTemps);
class TControleur
{
public:

    //Constructeur par défaut
    TControleur();

    //! La commande a effectuer
    struct TCommande CommandeRecu;


    //! Attendre une instruction du serveur et l'executer
    void ObtenirInstruction();
    
    //! Execute une commande
    int ExecuterCommande(struct TCommande * Commande);

    double dPositionHorizontal;
    double dPositionVertical;

private:
    //! Le résultat de la commande. Si elle s'Est bien effectuer ou non.
    int iResultat;

    //! Teste la limite d'un moteur
    int TesterLimiteMoteur(DRV8834 * DriverTester);

    //! Convertie un nombre de millimetre en nombre de step pour le moteur.
    long MMtoStep(double dMM);

} ;


#ifdef __cplusplus
}
#endif

#endif /* CONTROLEUR_HPP */
