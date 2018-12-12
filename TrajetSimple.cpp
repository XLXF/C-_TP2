/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include<cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher (  ) const
{
	cout << nom << " : de " << villeD << " a " << villeA << " en " << mTrans << "\r\n";
} //----- Fin de Méthode

const char* TrajetSimple:: villeDepart() const
{
    return villeD;
}

const char* TrajetSimple:: villeArrive() const
{
    return villeA;
}

const char* TrajetSimple:: Transport() const
{
    return mTrans;
}

const char* TrajetSimple:: Nom() const
{
    return nom;
}

//------------------------------------------------- Surcharge d'opérateurs
TrajetSimple & TrajetSimple::operator = ( const TrajetSimple & unTrajetSimple )
// Algorithme :
//
{
	this->~TrajetSimple();
    nom = new char(strlen(unTrajetSimple.nom)+1);
    strcpy(nom,unTrajetSimple.nom);
    villeD = new char[strlen(unTrajetSimple.villeD)+1];
    strcpy(villeD,unTrajetSimple.villeD);
    villeA = new char[strlen(unTrajetSimple.villeA)+1];
    strcpy(villeA,unTrajetSimple.villeA);
    mTrans = new char[strlen(unTrajetSimple.mTrans)+1];
    strcpy(mTrans,unTrajetSimple.mTrans);
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const TrajetSimple &unTrajetSimple)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
    nom = new char(strlen(unTrajetSimple.nom)+1);
    strcpy(nom,unTrajetSimple.nom);
    villeD = new char[strlen(unTrajetSimple.villeD)+1];
    strcpy(villeD,unTrajetSimple.villeD);
    villeA = new char[strlen(unTrajetSimple.villeA)+1];
    strcpy(villeA,unTrajetSimple.villeA);
    mTrans = new char[strlen(unTrajetSimple.mTrans)+1];
    strcpy(mTrans,unTrajetSimple.mTrans);
} //----- Fin de TrajetSimple (constructeur de copie)


TrajetSimple::TrajetSimple ( const char* N, const char* VD,const char* VA ,const char* MT ) 
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    nom = new char[strlen(N)+1];
    strcpy(nom,N);
    villeD = new char[strlen(VD)+1];
    strcpy(villeD,VD);
    villeA = new char[strlen(VA)+1];
    strcpy(villeA,VA);
    mTrans = new char[strlen(MT)+1];
    strcpy(mTrans,MT);
} //----- Fin de TrajetSimple

TrajetSimple::TrajetSimple ()
{
#ifdef MAP
    cout << "Appel au constructeur sans param de <TrajetSimple>" << endl;
#endif
}

TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
delete mTrans;
delete nom;
delete villeA;
delete villeD;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

