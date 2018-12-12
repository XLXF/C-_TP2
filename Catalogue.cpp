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
		int option=0;
                cout<<"Bonjour!"<<"\r\n";
		do
		{
                        cout<<"Rentrez '1' si vous voulez ajouter un trajet simple"<<"\r\n";
                        cout<<"Rentrez '2' si vous voulez ajouter un trajet composé"<<"\r\n";
                        cout<<"Rentrez '3' si vous voulez chercher un trajet"<<"\r\n";
                        cout<<"Rentrez '4' si vous voulez afficher tous les trajet"<<"\r\n";
                        cout<<"Rentrez '5' si vous voulez quitter"<<"\r\n";
			cin>>option;
			switch(option)
			{
				case 1:
					Ajouter_TS();
					break;
				case 2:
					Ajouter_TC();
					break;
				case 3:
					Recherche();
					break;
				case 4:
					Afficher();
					break;
				case 5:
                                        cout<<"BYE"<<"\r\n";
					break;
				default:
                                        cout<<"Veuillez rentrez un chiffre entre 1 et 5"<<"\r\n";
					break;
			}
		}while (option != 5);
	}
	
	
	void Catalogue::Ajouter_TS ( )
	{
		char* nom=new char[500];
		char* villeDepart=new char[500];
		char* villeArrive=new char[500];
		char* mTrans=new char[500];
		Trajet** new_elmts ;
                cout<<"Veuillez rentrez un Trajet Simple..."<<"\r\n";
                cout<<"Veuillez rentrez nom du Trajet"<<"\r\n";
		cin>>nom;
                cout<<"Veuillez rentrez la ville de départ:"<<"\r\n";
		cin>>villeDepart;
                cout<<"Veuillez rentrez la ville d'arrivé:"<<"\r\n";
		cin>>villeArrive;
                cout<<"Veuillez rentrez la moyenne de transport:"<<"\r\n";
		cin>>mTrans;
		TrajetSimple* ts = new TrajetSimple(nom, villeDepart,villeArrive,mTrans);
		new_elmts = new Trajet* [nbElmts + 1];
		for (int i = 0; i < nbElmts; i++)
		{
			new_elmts[i] = elmts[i];
		}
		new_elmts[nbElmts] = ts;
		delete [] elmts;
		elmts = new_elmts;
		nbElmts++;
                cout<<"Trajet simple a été ajouté dans le catalogue"<<"\r\n";
	}
	void Catalogue::Ajouter_TC ( )
	{
		char* nom=new char[500];
		char* villeDepart=new char[500];
		char* villeArrive=new char[500];
		char* mTrans=new char[500];
		Trajet** new_elmts ;
		new_elmts = new Trajet* [nbElmts + 1];
		TrajetCompose *TC = new TrajetCompose;
		int nbTrajet = 0;
                cout<<"Veuillez rentrez un Trajet Composé.."<<"\r\n";
                cout<<"Veuillez rentrez nom du Trajet"<<"\r\n";
		cin>>nom;
                cout<<"Veuillez rentrez la ville de départ:"<<"\r\n";
		cin>>villeDepart;
                cout<<"Veuillez rentrez la ville d'arrivé "<<"\r\n";
		cin>>villeArrive;
		nbTrajet ++;
                cout<<"Veuillez rentrez la moyenne de transport:"<<"\r\n";
		cin>>mTrans;
		TrajetSimple *ts = new TrajetSimple(nom, villeDepart,villeArrive,mTrans);
		TC->AjoutTrajet(ts);
		do
		{

                        strcpy(villeDepart, villeArrive);
                        cout<<"Veuillez rentrez nom du Trajet prochain"<<"\r\n";
			cin>>nom;
                        cout<<"Veuillez rentrez la ville suivante "<<"\r\n";
			cin>>villeArrive;
			nbTrajet ++;
                        cout<<"Veuillez rentrez la moyenne de transport:"<<"\r\n";
			cin>>mTrans;
			ts = new TrajetSimple(nom, villeDepart,villeArrive,mTrans);
			TC->AjoutTrajet(ts);
                        cout<<"Veuillez rentrez la ville suivante ( ou 'ok' pour valider Trajet)"<<"\r\n";
			cin>>villeArrive;
		}while(strcmp(villeArrive,"ok"));

		for (int i = 0; i < nbElmts; i++)
		{
			new_elmts[i] = elmts[i];
		}
		new_elmts[nbElmts]= TC;
		delete [] elmts;
		elmts = new_elmts;
		nbElmts++;
                cout<<"Trajet composé a été ajouté dans le catalogue"<<"\r\n";
	}

//------------------------------------------------- Surcharge d'opérateurs
/*Catalogue & Catalogue::operator = ( const Catalogue & unCatalogue )
// Algorithme :
//
{
	this->~Catalogue();
    nbElmts = unCatalogue.nbElmts;
    elmts = new Trajet*[nbElmts];
    for(int i = 0; i<nbElmts;i++)
    {
        elmts[i] = new Trajet(unCatalogue.[i]->Nom(),unTrajetCompose.trajets[i]->villeDepart(),unTrajetCompose.trajets[i]->villeArrive(),unTrajetCompose.trajets[i]->Transport());
    }
    return *this;
} //----- Fin de operator =
*/
//------------------------------------------------- Affichage de Catalogue
void Catalogue::Afficher()
  // Algorithme :
  //
{
#ifdef MAP
  cout << "Appel au Affichage de <Catalogue>" << "\r\n";
#endif
  for(int i = 0; i<nbElmts;i++)
  {
	  elmts[i]->Afficher();
  }
} //----- Fin de Catalogue

void Catalogue::Recherche()
{
	char* villeDepart=new char[500];
	char* villeArrive=new char[500];
        cout<<"Veuillez rentrez la ville de départ:"<<"\r\n";
	cin>>villeDepart;
        int n =strlen(villeDepart);
        char* villeD = new char[n+1];
        strncpy(villeD,villeDepart,n);
        cout<<"Veuillez rentrez la ville d'arrivé:"<<"\r\n";
	cin>>villeArrive;
        int m =strlen(villeArrive);
        char* villeA = new char[m+1];
        strncpy(villeA,villeArrive,m);
        cout<<"Recherche en cours..."<<"\r\n";
	bool trouve = false;
	for(int i = 0;i <nbElmts;i++)
	{
                //cout<<elmts[i]->villeDepart()<<"\r\n";
                //cout<<elmts[i]->villeArrive()<<"\r\n";
                if(!strncmp(elmts[i]->villeDepart(),villeD,n)&&strncmp(elmts[i]->villeArrive(),villeA,m))
		{
                        cout<<"Trajet trouvé:"<<"\r\n";
			elmts[i]->Afficher();
			trouve = true;
			
		}
	}

	if(!trouve)
	{
                cout<<"Opps, trajet non trouvé"<<"\r\n";
	}
}


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << "\r\n";
#endif

} //----- Fin de Catalogue (constructeur de copie)

Catalogue::Catalogue()   
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << "\r\n";
#endif
elmts = new Trajet*[1];
nbElmts = 0;
} //----- Fin de Catalogue

//------------------------------------------------- Surcharge d'opérateurs

Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << "\r\n";
#endif
	for (int i =0; i<nbElmts;i++)
    {
		elmts[i]->~Trajet();
	}
  	delete [] elmts;
  	elmts = NULL;

} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

