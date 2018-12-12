#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"
#include <iostream>
#include <cstring>
using namespace std;

//programme utilisé pour les tests internes et le débuggage
int main(){
    /*TrajetSimple ts1("ts1","lyon","bordeaux","train");
    TrajetSimple* pt_ts1 = new TrajetSimple;
    pt_ts1=&ts1;
    TrajetSimple ts2("ts2","bordeaux","paris","avion");
    TrajetSimple* pt_ts2 = new TrajetSimple;
    pt_ts2=&ts2;
    ts1.Afficher();
    ts2.Afficher();
    TrajetCompose tc;
    tc.AjoutTrajet(pt_ts1);
    tc.AjoutTrajet(pt_ts2);
    tc.Afficher();
    ts1.~TrajetSimple();
    ts2.~TrajetSimple();
    tc.~TrajetCompose();
    */
    Catalogue C;
    C.Options();
    C.~Catalogue();
	return 0;
}
