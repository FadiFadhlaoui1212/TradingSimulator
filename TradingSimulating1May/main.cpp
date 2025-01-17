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
    cout<<"donner le jour de la date de d�but";
    cin>>jj1;
    int mm1;
    cout <<"donner le mois de la date de d�but";
    cin>>mm1;
    int aaaa1;
    cout <<"donner l'ann�e de la date de d�but";
    cin>>aaaa1;
    date d1(jj1,mm1,aaaa1);
    int jj2;
    cout<<"donner le jour de la date de fin";
    cin>>jj2;
    int mm2;
    cout <<"donner le mois de la date de fin";
    cin>>mm2;
    int aaaa2;
    cout <<"donner l'ann�e de la date de fin";
    cin>>aaaa2;
    date d2(jj2,mm2,aaaa2);
    int jj;
    cout<<"donner le jour de la date courante";
    cin>>jj;
    int mm;
    cout <<"donner le mois de la date courante";
    cin>>mm;
    int aaaa;
    cout <<"donner l'ann�e de la date courante";
    cin>>aaaa;
    date d(jj,mm,aaaa);
    double budget;
    cout<<"donner le budget"<<endl;
    cin>>budget;
    Simulation S(d1,d2,d,budget);
    BourseVecteur bv(historique);
    TraderAleatoire* Tr = new TraderAleatoire();
    double x;
    x=S.executer(bv,*Tr);
    cout<<"le budget final est "<<x<<endl;

    return 0 ;
}
