/*!  @file                              ListeCommandes.cpp
     @version                           1.00
     @brief                             Implémentation pour pouvoir contrôler des moteurs.

     @internal
 
     projet                             Gerber (Gerber)
 
     @note                              Note au programmeur.

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-05-16
     @author                            Benoit Houle
     @note                              Entrée originale du code.

     <hr width="100%" height="5">
 */
//** **************************************************************************

using namespace std;

#include "ListeCommandes.h"


FILE * FichierResultat;
FILE * DebugFile;

list<string> LignesUtile;
list<struct TCommande> Commandes;

double dPositionXActuel = 0.0;
double dPositionYActuel = 0.0;

//Précision  des coordonées
int iEntierX = 0;
int iEntierY = 0;


//Coordoné horizontal avant d'etre transtypé en double
string sX;
//Coordoné vertical avant d'etre transtypé en double
string sY;

//** **************************************************************************

/*!  @brief                    Fonction principale. 
  
     @return                   Code d'erreur
     @retval  0000 0001        Le type d'unité est précisé
     @retval  0000 0010        La précision des coordonées
     @retval  0000 0100        Si la fin du fichier est valide
     @retval  0000 1000        ERREUR - Plus d'un type d'unité est précisés
     @retval  0001 0000        ERREUR - Plus d'une précision pour les coordonées est précisés
     @retval  0010 0000        ERREUR - Il y a plus d'une fin de fichier
     @retval  0100 0000        ERREUR - Le fichier Gerber n'a pas ouvert

     @internal

     <hr width="100%" height="5">
     <b>Historique</b>
     <hr width="100%" height="1">
     @date                              2020-05-16
     @author                            Benoit Houle
     @note                              Entrée du code.

     <hr width="100%" height="5">
 */
char ListeCommandes ( string FichierGerberAOuvrir  )
{
    FichierResultat = fopen ( "/Gerber/FichierResultat", "w+" );
    DebugFile = fopen ( "/Gerber/DebugFile", "w+" );



    char cResultat = TrierLignesUtileGerber ( FichierGerberAOuvrir );

    //Si tous les éléments néssécaires sont présent
    if ( cResultat & 0b0000'0001 &&
         cResultat & 0b0000'0010 &&
         cResultat & 0b0000'0100 &&
         !( cResultat & 0b0100'0000 ) )
    {

        CreeListeCommandesDriver( );

        list<struct TCommande>::iterator IteratorCommande = Commandes.begin( );

        for ( IteratorCommande ; IteratorCommande != --Commandes.end( ); IteratorCommande++ )
        {

            if ( IteratorCommande->CodeCommande == CCDiagonal )
            {
                fprintf( FichierResultat, "Ligne diagonal : ( %.2f , %.2f ) vers ( %.2f , %.2f ).\n",
                         IteratorCommande->Position.dDepartHorizontal,
                         IteratorCommande->Position.dDepartVertical,
                         IteratorCommande->Position.dFinHorizontal,
                         IteratorCommande->Position.dFinVertical
                         );

                fprintf( DebugFile, "Ligne diagonal : ( %.2f , %.2f ) vers ( %.2f , %.2f ).\n",
                         IteratorCommande->Position.dDepartHorizontal,
                         IteratorCommande->Position.dDepartVertical,
                         IteratorCommande->Position.dFinHorizontal,
                         IteratorCommande->Position.dFinVertical
                         );
                cout << "3(";
            }
            else if ( IteratorCommande->CodeCommande == CCPoint )
            {
                fprintf( FichierResultat, "Point : ( %.2f , %.2f ).\n",
                         IteratorCommande->Position.dDepartHorizontal,
                         IteratorCommande->Position.dDepartVertical,
                         IteratorCommande->Position.dFinHorizontal,
                         IteratorCommande->Position.dFinVertical
                         );

                fprintf( DebugFile, "Point : ( %.2f , %.2f ).\n",
                         IteratorCommande->Position.dDepartHorizontal,
                         IteratorCommande->Position.dDepartVertical,
                         IteratorCommande->Position.dFinHorizontal,
                         IteratorCommande->Position.dFinVertical
                         );
                cout << "4(";
            }
            else
            {
                fprintf( FichierResultat, "Retourner a l'origine\n" );
                cout << "0(";
            }
            cout << IteratorCommande->Position.dDepartHorizontal << "," << IteratorCommande->Position.dDepartVertical << "," << IteratorCommande->Position.dFinHorizontal << "," << IteratorCommande->Position.dFinVertical << ")" << endl;
        }

        fprintf( FichierResultat, "Retourner a l'origine\n" );
        cout << "0(0,0,0,0)";

    }
    else
    {
        //-------------------------
        //Enregistrement des erreurs.
        //-------------------------
        cout << "<ul>";

        if ( !( cResultat & 0b0000'0001 ) )
        {
            //fprintf( FichierErreur, "<li>Le type d'unité n'est pas précisé.</li>\n" );
            cout << "<li>Le type d'unité n'est pas précisé.</li>";
        }
        if ( !( cResultat & 0b0000'00010 ) )
        {
            //fprintf( FichierErreur, "<li>La précision des coordonées n'est pas précisé.</li>\n" );
            cout << "<li>La précision des coordonées n'est pas précisé.</li>";
        }
        if ( !( cResultat & 0b0000'0100 ) )
        {
            //fprintf( FichierErreur, "<li>Il n'y a pas de fin de fichier.</li>\n" );
            cout << "<li>Il n'y a pas de fin de fichier.</li>";
        }
        if ( cResultat & 0b0100'0000 )
        {
            //fprintf( FichierErreur, "<li>Le fichier n'a pas pu être ouvert.</li>\n" );
            cout << "<li>Le fichier n'a pas pu être ouvert.</li>";
        }
        cout << "</ul>";
    }

    fclose ( DebugFile );
    fclose ( FichierResultat );
    //Retourner le code d'erreur à la routine appelante.
    return cResultat;
}

/*!  @brief                    Prend tous les lignes utiles du fichier Gerber.
 
 
@return                   Code d'erreur
@retval  0000 0001        Le type d'unité est précisé
@retval  0000 0010        La précision des coordonées
@retval  0000 0100        S'il y a une fin de fichier
@retval  0000 1000        ERREUR - Plus d'un type d'unité est précisés
@retval  0001 0000        ERREUR - Plus d'une précision pour les coordonées est précisés
@retval  0010 0000        ERREUR - Il y a plus d'une fin de fichier
@retval  0100 0000        ERREUR - Le fichier Gerber n'a pas ouvert

@internal

<hr width="100%" height="5">
<b>Historique</b>
<hr width="100%" height="1">
@date                              2020-05-16
@author                            Benoit Houle
@note                              Entrée du code.

<hr width="100%" height="5">
 */
char TrierLignesUtileGerber ( string FichierGerberAOuvrir  )
{

    //Fichier gerber a lire
    ifstream FichierGerber ( FichierGerberAOuvrir.c_str( ) );


    /*Pour avoir un fichier valide, on doit avoir au minimum 3 lignes :
    - MOMM ou MOIN     pour l'unité des dimention
    - FSLAX**Y**       pour la précision des dimentions
    - M02              pour la fin du fichier
    S'il manque une de ces trois lignes, le fichier est invalide.
     */
    bitset<8> cCodeErreur;

    if ( FichierGerber.is_open( ) )
    {
        string LigneLu;
        //-------------------------
        //Lire tous les lignes du ficher et placer ceux qui sont utilse dans un liste
        //-------------------------
        while ( getline ( FichierGerber, LigneLu ) )
        {
            if ( LigneLu.size ( ) > 0 )
            {

                //Pour savoir si on bouge les moteurs
                if ( LigneLu.rfind ( "D01*" ) != -1 || LigneLu.rfind ( "D02*" ) != -1 )
                {
                    LignesUtile.push_back ( LigneLu );
                }
                    //Pour savoir si les dimentions sont en milimètres ou en pouces.
                else if ( LigneLu.find ( "%MOMM" ) != -1 || LigneLu.find ( "%MOIN" ) != -1  )
                {
                    //Si je connais déjà la précision
                    if ( cCodeErreur.test( 0 ) )
                    {
                        cCodeErreur.set( 3 );
                    }
                    else
                    {
                        LignesUtile.push_back ( LigneLu );
                        cCodeErreur.set( 0 );
                    }
                }
                    //Pour savoir la précision utilisé
                else if ( LigneLu.find ( "%FSLAX" ) != -1 )
                {
                    if ( cCodeErreur.test( 1 ) )
                    {
                        cCodeErreur.set( 4 );
                    }
                    else
                    {
                        LignesUtile.push_back ( LigneLu );
                        cCodeErreur.set( 1 );
                    }
                }
                    //Pour savoir si c'est la fin du fichier
                else if ( LigneLu.find ( "M02*" ) != -1 )
                {
                    if ( cCodeErreur.test( 2 ) )
                    {
                        cCodeErreur.set( 5 );
                    }
                    else
                    {
                        LignesUtile.push_back ( LigneLu );
                        cCodeErreur.set( 2 );
                    }
                }
            }
        }
        //Fermer le fichier
        FichierGerber.close ( );

    }

    else cCodeErreur.set( 6 );


    return cCodeErreur.to_ulong( );
}

/*!  @brief                    Crée la liste de commande pour contrôler les drivers des moteurs.
 

@internal

<hr width="100%" height="5">
<b>Historique</b>
<hr width="100%" height="1">
@date                              2020-05-16
@author                            Benoit Houle
@note                              Entrée du code.

<hr width="100%" height="5">
 */
void CreeListeCommandesDriver ( )
{
    //Type d'unité choisi. Vu que je n'ai pas la machine, je ne peu pas faire de calibration, donc je n'utilise pas différente unité.
    bool Unite = MILIM;


    //utilisé pour pouvoir modifier une chaine non modifiable (const)
    char cmCoordonnes[256];


    //L'ittérateur pour traverser dans la liste de ligne utile
    list<string>::iterator IteratorLigne = LignesUtile.begin( );

    //La commande à ajouter a la liste de commande
    struct TCommande CommandeAAjouter;

    //------------------------------------------
    //Choisir si on utilise des milimètres ou des pouces
    //-----------------------------------------
    while ( IteratorLigne != --LignesUtile.end( ) )
    {
        if ( strncmp ( IteratorLigne->c_str( ) , "%MOMM%", 5 ) == 0 )
        {
            fprintf( DebugFile, "Ligne MO enlever :%s\n", IteratorLigne->c_str( ) );
            LignesUtile.erase( IteratorLigne ) ;
            IteratorLigne = --LignesUtile.end( );
        }
        else if ( strncmp ( IteratorLigne->c_str( ) , "%MOIN%", 5 ) == 0 )
        {
            fprintf( DebugFile, "Ligne MO enlever :%s\n", IteratorLigne->c_str( ) );
            bool Unite = POUCE;
            LignesUtile.erase( IteratorLigne ) ;
            IteratorLigne = --LignesUtile.end( );
        }
        else   IteratorLigne++;
    }

    //------------------------------------------
    //Calculer la précision
    //-----------------------------------------

    IteratorLigne = LignesUtile.begin( );
    while (  IteratorLigne != --LignesUtile.end( )  )
    {
        if (  strncmp ( IteratorLigne->c_str( ) , "%FSLA", 5 ) == 0 )
        {
            iEntierX = IteratorLigne->c_str( )[6] - '0';
            iEntierY = IteratorLigne->c_str( )[9] - '0';

            fprintf( DebugFile, "Ligne enlever :%s\n", IteratorLigne->c_str( ) );
            LignesUtile.erase( IteratorLigne ) ;
            IteratorLigne = --LignesUtile.end( );
        }
        else IteratorLigne++;
    }

    fprintf( DebugFile, "---------------------------\n" );
    for ( list<string>::iterator Iterator = LignesUtile.begin( ); Iterator != --LignesUtile.end( ); Iterator++ )
    {
        fprintf( DebugFile, "%s\n", Iterator->c_str( ) );
    }
    fprintf( DebugFile, "---------------------------\n" );


    //------------------------------------------
    //Mettre tous les déplacement des moteurs dans la liste de commande
    //-----------------------------------------

    for ( IteratorLigne = LignesUtile.begin( ); IteratorLigne != --LignesUtile.end( ); IteratorLigne++ )
    {
        fprintf( DebugFile, "%s\n", IteratorLigne->c_str( ) );

        strcpy( cmCoordonnes, IteratorLigne->c_str( ) );

        TraitementConversionPosition( cmCoordonnes, IteratorLigne->c_str( )[0] );

        fprintf( DebugFile, "D02 || D01 : %c || %c\n", IteratorLigne->c_str( )[IteratorLigne->size( ) - 3], IteratorLigne->c_str( )[IteratorLigne->size( ) - 2] );
        //------------------------------------------
        //Si les moteurs sont déjà a la bonne place
        //-----------------------------------------
        if ( IteratorLigne->c_str( )[IteratorLigne->size( ) - 3] == '1' || IteratorLigne->c_str( )[IteratorLigne->size( ) - 2] == '1' )
        {

            CommandeAAjouter.Position.dDepartHorizontal = dPositionXActuel;
            CommandeAAjouter.Position.dDepartVertical = dPositionYActuel;
            fprintf( DebugFile, "Debut----- \nsX : %f\nsY : %f\n", dPositionXActuel, dPositionYActuel );

            dPositionXActuel = strtod( sX.c_str( ), NULL );
            dPositionYActuel = strtod( sY.c_str( ), NULL );

            fprintf( DebugFile, "Fin------- \nsX : %s\nsY : %s\n", sX.c_str( ), sY.c_str( ) );
            CommandeAAjouter.Position.dFinHorizontal = dPositionXActuel;
            CommandeAAjouter.Position.dFinVertical = dPositionYActuel;

        }
            //------------------------------------------
            //Si on doit déplacer les moteurs avant de dessiner
            //-----------------------------------------
        else if ( IteratorLigne->c_str( )[IteratorLigne->size( ) - 3] == '2' || IteratorLigne->c_str( )[IteratorLigne->size( ) - 2] == '2' )
        {
            CommandeAAjouter.Position.dDepartHorizontal = strtod( sX.c_str( ), NULL );
            CommandeAAjouter.Position.dDepartVertical = strtod( sY.c_str( ), NULL );
            fprintf( DebugFile, "Debut----- \nsX : %s\nsY : %s\n", sX.c_str( ), sY.c_str( ) );

            IteratorLigne++;

            strcpy( cmCoordonnes, IteratorLigne->c_str( ) );

            TraitementConversionPosition( cmCoordonnes, IteratorLigne->c_str( )[0] );
            fprintf( DebugFile, "Fin------- \nsX : %s\nsY : %s\n", sX.c_str( ), sY.c_str( ) );

            dPositionXActuel = strtod( sX.c_str( ), NULL );
            dPositionYActuel = strtod( sY.c_str( ), NULL );

            CommandeAAjouter.Position.dFinHorizontal = dPositionXActuel;
            CommandeAAjouter.Position.dFinVertical = dPositionYActuel;
        }

        //------------------------------------------
        //Choisir le code de la commande
        //-----------------------------------------
        if ( CommandeAAjouter.Position.dDepartHorizontal != CommandeAAjouter.Position.dFinHorizontal || CommandeAAjouter.Position.dDepartVertical != CommandeAAjouter.Position.dFinVertical )

            CommandeAAjouter.CodeCommande = CCDiagonal;

        else if ( CommandeAAjouter.Position.dDepartHorizontal == CommandeAAjouter.Position.dFinHorizontal && CommandeAAjouter.Position.dDepartVertical == CommandeAAjouter.Position.dFinVertical )

            CommandeAAjouter.CodeCommande = CCPoint;

        else

            CommandeAAjouter.CodeCommande = CCOrigine;

        Commandes.push_back( CommandeAAjouter );


        fprintf( DebugFile, "---------------------------\n" );


    }


    //------------------------------------------
    //Reset la position des moteurs a l'origine.
    //-----------------------------------------

    CommandeAAjouter.Position.dDepartHorizontal = 0;
    CommandeAAjouter.Position.dDepartVertical = 0;
    CommandeAAjouter.Position.dFinHorizontal = 0;
    CommandeAAjouter.Position.dFinVertical = 0;
    CommandeAAjouter.CodeCommande = CCOrigine;

    Commandes.push_back( CommandeAAjouter );

}

/*!  @brief                         Traite une commande pour en séparer et traiter 2 coordonées (x ,y )
 
@param   cmCoordonnes          Ligne utilisé pour la modification
@param   cPremierCharactere    Premier caractère de la ligne 
 

@internal

<hr width="100%" height="5">
<b>Historique</b>
<hr width="100%" height="1">
@date                              2020-05-16
@author                            Benoit Houle
@note                              Entrée du code.

<hr width="100%" height="5">
 */
void TraitementConversionPosition( char cmCoordonnes[], char cPremierCharactere )
{

    sX = strtok ( cmCoordonnes, "XYD" );
    sY = strtok ( NULL, "XYD" );

    //------------------------------------------
    //S'il y a uniquement une coordonée a traiter
    //-----------------------------------------
    if ( sY.c_str( )[2] == '*' )
    {
        if ( cPremierCharactere == 'X' )
        {
            sY = to_string( dPositionYActuel );

            if ( sX.size( ) > iEntierX )
            {
                sX.insert( iEntierX, "." );
            }
        }
        else
        {
            sY = sX;
            sX = to_string( dPositionXActuel );

            if ( sY.size( ) > iEntierY )
            {
                sY.insert( iEntierY, "." );
            }
        }
    }
    else
    {
        if ( sX.size( ) > iEntierX )
        {
            sX.insert( iEntierX, "." );
        }
        if ( sY.size( ) > iEntierY )
        {
            sY.insert( iEntierY, "." );
        }
    }

}