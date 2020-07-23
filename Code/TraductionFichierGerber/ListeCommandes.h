/*!  @file                              ListeCommandes.h
     @version                           1.00
     @brief                             Déclaration pour pouvoir contrôler des moteurs.

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

#include <string>
#include <bitset>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <list>


#ifndef LISTECOMMANDES_H
#define LISTECOMMANDES_H

#ifdef __cplusplus
extern "C"
{
#endif


#include "Commande.hpp"


#define MILIM 0
#define POUCE 1

char ListeCommandes( string FichierGerberAOuvrir );

char TrierLignesUtileGerber( string FichierGerberAOuvrir );

void CreeListeCommandesDriver( );

void TraitementConversionPosition( char cmCoordonnes[], char cPremierCharactere );

#ifdef __cplusplus
}
#endif

#endif /* LISTECOMMANDES_H */
