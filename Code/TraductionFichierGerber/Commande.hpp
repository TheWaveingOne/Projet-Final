/*!  @file                              Commande.hpp
     @version                           1.00
     @brief                             Déclaration pour une commande.

     @internal
 
     projet                             Graveur de circuit imprimé (PCB) sur machine CNC
 
     @note                              Note au programmeur.

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-03-03
     @author                            Benoit Houle
     @note                              Création du code.

     <hr width="100%" height="5">
 */
//** **************************************************************************

#ifndef COMMANDE_HPP
#define COMMANDE_HPP

#ifdef __cplusplus
extern "C"
{
#endif

//** ==========================================================================    
//** Insérer ici les déclarations.
//** ==========================================================================   
    


//! Les différentes commandes disponibles
enum TCodeCommande
{
    //! Retourner a l'origine
    CCOrigine = 0,
    //! Executer un mouvement horizontal
    CCHorizontal = 1,
    //! Executer un mouvement vertical
    CCVertical = 2,
    //! Executer un mouvement diagonal
    CCDiagonal = 3,
    //! Dessiner un point
    CCPoint = 4,
    //! Bouger les moteurs sans dessiner
    CCBougerSansDessiner = 5,
    CCDefault = CCOrigine,
    CCPremier = CCOrigine,
    CCDernier = CCBougerSansDessiner,
} ;

//! La position de départ et de fin des moteurs pour la commande
struct TPosition
{
    double dDepartHorizontal;
    double dDepartVertical;
    double dFinHorizontal;
    double dFinVertical;
} ;

//! Tous l'information nécesaire pour executer une commande
struct TCommande
{
    enum TCodeCommande CodeCommande;
    struct TPosition Position;
} ;


#ifdef __cplusplus
}
#endif

#endif /* COMMANDE_HPP */