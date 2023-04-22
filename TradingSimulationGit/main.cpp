#include <iostream>
#include "PrixJournalier.h"
#include "BourseVecteur.h"
#include "PersistancePrixJournaliers.h"
using namespace std;

int main()
{

    PersistancePrixJournaliers extract ;
    vector<PrixJournalier> historique ;


    historique=extract.lirePrixJournaliersDUnFichier("prices_simple.csv");
for(int i=0;i<historique.size();i++)
{
    cout<<historique.at(i);
}

    return 0 ;
}
