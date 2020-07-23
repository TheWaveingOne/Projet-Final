/*!  @file                              main.cpp
     @version                           1.00
     @brief                             Description général de la fonction du programme.

     @internal
 
     projet                             Gerber (Gerber)
 
     @note                              Note au programmeur.

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-05-16
     @author                            Benoit Houle
     @note                              Entrée du code.

     <hr width="100%" height="5">
 */
//** **************************************************************************

using namespace std;


#include "ListeCommandes.h"
#include <cstdlib>
#include <cstdio>
#include <string>


//** **************************************************************************

/*!  @brief                             Description générale de la fonction du programme.

     @param      argc                   Nombre d'arguments sur la ligne de commande.
     @param      argv                   Matrice de pointeurs vers les chaînes de caractères de chaque argument sur la ligne de commande.
 
     @return                            Code d'erreur.
     @retval                            EXIT_SUCCESS(0)   Aucune erreur.
     @retval                            EXIT_FAILURE(1)   Échec.

     @internal

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-05-16
     @author                            Benoit Houle
     @note                              Entrée du code.

     <hr width="100%" height="5">
 */
int main( int argc, char** argv )
{
    if ( argc == 2 )
    {
        ListeCommandes( argv[1] );
    }
    else cerr << "<p>Erreur dans le nom du fichier.</p>";
    
    return EXIT_SUCCESS;
}
