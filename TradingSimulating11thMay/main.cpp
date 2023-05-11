#include <iostream>
#include <random>
#include "PrixJournalier.h"
#include "boursevecteur.h"
#include "PersistancePrixJournaliers.h"
#include "simulation.h"
#include "dictionnaire.h"
#include "boursedictionnaire.h"
#include "set.h"
#include "bourseset.h"
using namespace std;

int main()
{
 PersistancePrixJournaliers extract ;
    vector<PrixJournalier> historique ;
    historique=extract.lirePrixJournaliersDUnFichier("prices_simple.csv");
    srand(time(NULL));
    date d1,d2;
    cout<<"donner la date de debut au format : jj/mm/aaaa;";
    cin>>d1;
    cout<<"donner la date de fin : jj/mm/aaaa;";
    cin>>d2;
    double budget;
    cout<<"donner le budget"<<endl;
    cin>>budget;
    Simulation S(d1,d2,d1,budget);
    BourseDictionnaire bv(historique);
    TraderSemiAleatoire* Tr = new TraderSemiAleatoire();
    auto stats=S.executer(bv,*Tr);
    for(auto it:stats)
    {
        cout<<it.first<<" : "<<it.second<<endl;
    }



    return 0;}
