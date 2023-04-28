#include <iostream>
#include "PrixJournalier.h"
#include "BourseVecteur.h"
#include "PersistancePrixJournaliers.h"
#include "simulation.h"
using namespace std;

int main()
{
 PersistancePrixJournaliers extract ;
    vector<PrixJournalier> historique ;


    historique=extract.lirePrixJournaliersDUnFichier("prices_simple.csv");
    date d1;
    cout<<"donner la date de début"<<endl;
    cin>>d1;
    date d2;
    cout<<"donner la date de fin"<<endl;
    cin>>d2;
    date d;
    cout<<"donner la date courante"<<endl;
    cin>>d;
    double budget;
    cout<<"donner le budget"<<endl;
    cin>>budget;
    Simulation S(d1,d,d2,budget);

    return 0 ;
}
