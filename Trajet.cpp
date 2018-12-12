/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include <cstring>

//------------------------------------------------------------- Constantes

//---------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Trajet:: Afficher() const
{
}

const char* Trajet:: villeDepart() const
{
 return "rien";
}

const char* Trajet:: villeArrive() const
{
 return "rien";
}

const char* Trajet:: Transport() const
{
 return "rien";
}

const char* Trajet:: Nom() const
{
 return "rien";
}


//------------------------------------------------- Surcharge d'opérateurs
Trajet & Trajet::operator = ( const Trajet & unTrajet )
// Algorithme :
//
{
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const Trajet & unTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
} //----- Fin de Trajet (constructeur de copie)


Trajet::Trajet (const char* N,const char* VD,const char* VA) 
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
    nom = new char[strlen(N)+1];
    strcpy(nom,N);
    villeD = new char[strlen(VD)+1];
    strcpy(villeD,VD);
    villeA = new char[strlen(VA)+1];
    strcpy(villeA,VA);
} //----- Fin de Trajet
Trajet::Trajet()
{

}

Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
delete nom;
delete villeD;
delete villeA;
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
