/*************************************************************************
 Catalogue -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier v.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
	void Catalogue::Options()
	{
		char option;
		do
		{
			cout<<"Bonjour!"<<endl;
			cout<<"Rentrez '1' si vous voulez ajouter un trajet simple"<<endl;
			cout<<"Rentrez '2' si vous voulez ajouter un trajet composé"<<endl;
			cout<<"Rentrez '3' si vous voulez chercher un trajet simple"<<endl;
			cout<<"Rentrez '4' si vous voulez afficher tous les trajet"<<endl;
			cout<<"Rentrez '5' si vous voulez quitter"<<endl;
			cin>>option;
			switch(option)
			{
				case '1':
					Ajouter_TS();
					break;
				case '2':
					Ajouter_TC();
					break;
				case '3':
					Recherche();
					break;
				case '4':
					Afficher();
				case '5':
					cout<<"BYE"<<endl;
					break;
				default:
					cout<<"Veuillez rentrez un chiffre entre 1 et 5"<<endl;
					break;
			}
		}while (option != '5');
	}
	
	
	void Catalogue::Ajouter_TS ( )
	{
		char* nom;
		char* villeDepart;
		char* villeArrive;
		char* mTrans;
		Trajet** new_elmts ;
		cout<<"Veuillez rentrez un Trajet Simple..."<<endl;
		cout<<"Veuillez rentrez nom du Trajet"<<endl;
		cin>>nom;
		cout<<"Veuillez rentrez la ville de départ:"<<endl;
		cin>>villeDepart;
		cout<<"Veuillez rentrez la ville d'arrivé:"<<endl;
		cin>>villeArrive;
		cout<<"Veuillez rentrez la moyenne de transport:"<<endl;
		cin>>mTrans;
		TrajetSimple* ts = new TrajetSimple(nom, villeDepart,villeArrive,mTrans);
		new_elmts = new Trajet* [nbElmts + 1];
		for (int i = 0; i < nbElmts; i++)
		{
			new_elmts[i] = elmts[i];
		}
		new_elmts[nbElmts] = ts;
		elmts = new_elmts;
		delete [] new_elmts;
	}
	void Catalogue::Ajouter_TC ( )
	{
		char* nom;
		char* villeDepart;
		char* villeArrive;
		char* mTrans;
		Trajet** new_elmts ;
		new_elmts = new Trajet* [nbElmts + 1];
		//TrajetCompose TC;
		TrajetCompose *TC;
		int nbTrajet = 0;
		TrajetSimple *listeTS;
		cout<<"Veuillez rentrez un Trajet Composé.."<<endl;
		cout<<"Veuillez rentrez nom du Trajet"<<endl;
		cin>>nom;
		cout<<"Veuillez rentrez la ville de départ:"<<endl;
		cin>>villeDepart;
		cout<<"Veuillez rentrez la ville suivante "<<endl;
		cin>>villeArrive;
		nbTrajet ++;
		cout<<"Veuillez rentrez la moyenne de transport:"<<endl;
		cin>>mTrans;
		TrajetSimple *ts = new TrajetSimple(nom, villeDepart,villeArrive,mTrans);
		do
		{

			villeDepart = villeArrive;
			cout<<"Veuillez rentrez nom du Trajet"<<endl;
			cin>>nom;
			cout<<"Veuillez rentrez la ville suivante "<<endl;
			cin>>villeArrive;
			nbTrajet ++;
			cout<<"Veuillez rentrez la moyenne de transport:"<<endl;
			cin>>mTrans;
			TrajetSimple *ts = new TrajetSimple(nom, villeDepart,villeArrive,mTrans);
			TC->AjoutTrajet(ts);
			cout<<"Veuillez rentrez la ville suivante ( ou 'ok' pour valider Trajet)"<<endl;
			cin>>villeArrive;
		}while(strcmp(villeArrive,"ok"));
		for (int i = 0; i < nbElmts; i++)
		{
			new_elmts[i] = elmts[i];
		}
		new_elmts[nbElmts]
		 = TC;
		elmts = new_elmts;
		delete [] new_elmts;
	}

//------------------------------------------------- Surcharge d'opérateurs
Catalogue & Catalogue::operator = ( const Catalogue & unCatalogue )
// Algorithme :
//
{
} //----- Fin de operator =

//------------------------------------------------- Affichage de Catalogue
void Catalogue::Afficher()
  // Algorithme :
  //
{
#ifdef MAP
  cout << "Appel au Affichage de <Catalogue>" << endl;
#endif
  for(int i = 0; i<nbElmts;i++)
  {
	  elmts[i]->Afficher();
  }
} //----- Fin de Catalogue

void Catalogue::Recherche()
{
	char* villeDepart;
	char* villeArrive;
	cout<<"Veuillez rentrez la ville de départ:"<<endl;
	cin>>villeDepart;
	cout<<"Veuillez rentrez la ville d'arrivé:"<<endl;
	cin>>villeArrive;
	cout<<"Recherche en cours..."<<endl;
	bool trouve = false;
	for(int i = 0;i <nbElmts;i++)
	{
		if(!strcmp(elmts[i]->villeDepart(),villeDepart)&&strcmp(elmts[i]->villeArrive(),villeArrive))
		{
			(*elmts[i]).Afficher();
			trouve = true;
			
		}
	}

	if(!trouve)
	{
		cout<<"Opps, trajet non trouvé"<<endl;
	}
}


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif

} //----- Fin de Catalogue (constructeur de copie)

Catalogue::Catalogue()   
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
nbElmts = 0;
elmts = new Trajet*[0];
} //----- Fin de Catalogue

//------------------------------------------------- Surcharge d'opérateurs

Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
delete [] elmts;

} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

