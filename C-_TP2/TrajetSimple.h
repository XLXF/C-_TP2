
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H
//------------------------------------------------------------------------
// Rôle du module <TrajetSimple>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

  
//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC

class TrajetSimple: public Trajet
  {
  public:
    //----------------------------------------------------- Méthodes publiques
    void	Afficher () const;
    // Mode d'emploi :
    //
    // Contrat :
    //
    const char* villeDepart() const;

    const char* villeArrive() const;

    const char* Transport() const;

    const char* Nom() const;


    //------------------------------------------------- Surcharge d'opérateurs
    TrajetSimple & operator = ( const TrajetSimple &unTrajetSimple );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    
    //-------------------------------------------- Constructeurs - destructeur
    
    TrajetSimple(const TrajetSimple & unTrajetSimple);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    TrajetSimple ();

    TrajetSimple (const char* N,const char* VD,const char* VA ,const char* MT );


    ~TrajetSimple();
    // Mode d'emploi :
    //
    // Contrat :
    //
    //------------------------------------------------------------------ PRIVE
    
protected:
  //----------------------------------------------------- Méthodes protégées
  
  //----------------------------------------------------- Attributs protégés

  char* mTrans;

  };

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

