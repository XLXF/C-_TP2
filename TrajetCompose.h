 /*************************************************************************
 TrajetCompose  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
  //----------------------------------------------------------------- PUBLIC
  
public:
  //----------------------------------------------------- Méthodes publiques
  void Afficher() const;

  const char* villeDepart() const;

  const char* villeArrive() const;

  const char* Transport() const;
  
  const char* Nom() const;

  void AjoutTrajet(TrajetSimple *ts);
  //------------------------------------------------- Surcharge d'opérateurs
  TrajetCompose & operator = ( const TrajetCompose & unTrajetCompose );
  // Mode d'emploi :
  //
  // Contrat :
  //
  
  
  //-------------------------------------------- Constructeurs - destructeur
  TrajetCompose ( const TrajetCompose & unTrajetCompose );
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //
  
  TrajetCompose ();
  // Mode d'emploi :
  //
  // Contrat :
  //
  
  virtual ~TrajetCompose ( );
  // Mode d'emploi :
  //
  // Contrat :
  //
  
  //------------------------------------------------------------------ PRIVE
  
protected:
  //----------------------------------------------------- Méthodes protégées
  
  //----------------------------------------------------- Attributs protégés
  Trajet** trajets;
  unsigned int nbTrajets;
};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H

