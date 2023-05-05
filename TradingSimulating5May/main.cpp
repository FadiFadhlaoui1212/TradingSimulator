#include <iostream>
#include "PrixJournalier.h"
#include "boursevecteur.h"
#include "PersistancePrixJournaliers.h"
#include "simulation.h"
using namespace std;

int main()
{
 PersistancePrixJournaliers extract ;
    vector<PrixJournalier> historique ;
    historique=extract.lirePrixJournaliersDUnFichier("prices_simple.csv");

    int jj1;
    cout<<"donner le jour de la date de début";
    cin>>jj1;
    int mm1;
    cout <<"donner le mois de la date de début";
    cin>>mm1;
    int aaaa1;
    cout <<"donner l'année de la date de début";
    cin>>aaaa1;
    date d1(jj1,mm1,aaaa1);
    int jj2;
    cout<<"donner le jour de la date de fin";
    cin>>jj2;
    int mm2;
    cout <<"donner le mois de la date de fin";
    cin>>mm2;
    int aaaa2;
    cout <<"donner l'année de la date de fin";
    cin>>aaaa2;
    date d2(jj2,mm2,aaaa2);
    double budget;
    cout<<"donner le budget"<<endl;
    cin>>budget;
    Simulation S(d1,d2,d1,budget);
    BourseVecteur bv(historique);
    TraderAleatoire* Tr = new TraderAleatoire();
    auto stats=S.executer(bv,*Tr);
    for(auto it:stats)
    {
        cout<<it.first<<" : "<<it.second<<endl;
    }



    return 0;}
