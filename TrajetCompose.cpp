/*************************************************************************
 TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include"TrajetSimple.h"
#include <cstring>



//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
	void TrajetCompose::Afficher () const
	{
		int i;
		for (i=0; i < nbTrajets; i++)
		{
			trajets[i]->Trajet::Afficher();
		}
	}

    const char* TrajetCompose:: villeDepart() const
    {
        return trajets[0]->Trajet::villeDepart();
    }

    const char* TrajetCompose:: villeArrive() const

    {
        return trajets[nbTrajets-1]->Trajet::villeArrive();
    }
    const char* TrajetCompose:: Transport() const

    {
        return "pas de transport pour un trajet compose";
        
    }
    const char* TrajetCompose:: Nom() const

    {
        return "pas de nom pour un trajet compose";
        
    }




//------------------------------------------------- Surcharge d'opérateurs
TrajetCompose & TrajetCompose::operator = ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
{
    this->~TrajetCompose();
    nbTrajets = unTrajetCompose.nbTrajets;
    trajets = new Trajet*[nbTrajets];
    for(int i = 0; i<nbTrajets;i++)
    {
        trajets[i] = new TrajetSimple(unTrajetCompose.trajets[i]->Nom(),unTrajetCompose.trajets[i]->villeDepart(),unTrajetCompose.trajets[i]->villeArrive(),unTrajetCompose.trajets[i]->Transport());
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose (constructeur de copie)


TrajetCompose::TrajetCompose () : trajets(new Trajet* [1]), nbTrajets(0)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose

void TrajetCompose::AjoutTrajet(TrajetSimple *ts)
{
#ifdef MAP
    cout << "Appel au fonction ajout trajet de <TrajetCompose>" << endl;
#endif
trajets [nbTrajets] = new TrajetSimple(ts->Nom(),ts->villeDepart(),ts->villeArrive(),ts->Transport());
nbTrajets ++;
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    for (int i =0; i<nbTrajets;i++)
    {
		trajets[i]->~Trajet();
	}
  delete [] trajets;
  trajets = NULL;
  
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

