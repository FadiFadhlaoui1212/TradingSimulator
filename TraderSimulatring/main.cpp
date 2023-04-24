#include <iostream>
#include "PrixJournalier.h"
#include "BourseVecteur.h"
#include "PersistancePrixJournaliers.h"
using namespace std;

int main()
{
 PersistancePrixJournaliers extract ;
    vector<PrixJournalier> historique ;
    int i=0;

    historique=extract.lirePrixJournaliersDUnFichier("prices_simple.csv");
    while(i<historique.size()){
        cout<<historique.at(i);
        i++;
    }

    return 0 ;
}
