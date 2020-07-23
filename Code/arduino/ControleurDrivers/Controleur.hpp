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

#include "Commande.hpp"
#include "SyncDriver.h"
#include "DRV8834.h"

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200

// Target RPM for cruise speed
#define RPM 60
// Acceleration and deceleration values are always in FULL steps / s^2
#define MOTOR_ACCEL 2000
#define MOTOR_DECEL 1000

// Microstepping mode. If you hardwired it to save pins, set to the same value here.
#define MICROSTEPS 1

// Faire tourner un moteur pendant 60 secondes. (MOTOR_STEPS*MICROSTEPS*RPM)
#define TESTER_LIMITE_STEPS (MOTOR_STEPS*MICROSTEPS*RPM)

// Pin pour le moteur horizontal
#define DIR_X 2
#define STEP_X 3

// Pin pour le moteur vertical
#define DIR_Y 4
#define STEP_Y 5

// Pin pour le moteur de l'axe des Z
#define DIR_Z 6
#define STEP_Z 7

// Pin pour les boutons de limite
#define LIMITE_X 8
#define LIMITE_Y 9
#define LIMITE_Z 10

class TControleur
{
public:

    //Constructeur par défaut
    TControleur();

    //! La commande a effectuer
    struct TCommande CommandeRecu;

    
    //! Execute une commande
    int ExecuterCommande(struct TCommande * Commande);


    //! Teste la limite d'un moteur
    int TesterLimiteMoteurs();


private:
    //! Le résultat de la commande. Si elle s'Est bien effectuer ou non.
    int iResultat;

    //! Convertie un nombre de millimetre en nombre de step pour le moteur.
    long MMtoStep(double dMM);

    int iLimite_X;
    int iLimite_Y;
    int iLimite_Z;
    
    double dPositionHorizontal;
    double dPositionVertical;

} ;


#ifdef __cplusplus
}
#endif

#endif /* CONTROLEUR_HPP */
