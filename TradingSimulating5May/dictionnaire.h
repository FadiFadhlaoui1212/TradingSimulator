#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED

#include<vector>
#include<fstream>
#include "prixjournalier.h"
using namespace std;

class dictionnairePrixJournaliers
{
public:
    map<int,PrixJournalier> lirePrixJournaliersDUnFichier(string chemin)
    {
        map<int,PrixJournalier> historique;
        ifstream f(chemin);
        int nbLignes= 0;
        string entete;
        if(f.is_open())
        {
            f>>entete;
            while(!f.eof())
            {
                PrixJournalier pj;
                f>>(pj);
                historique.insert(make_pair(nbLignes,pj));
                nbLignes++;
            }
        }
    }
};


#endif // DICTIONNAIRE_H_INCLUDED
