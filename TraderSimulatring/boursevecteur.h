#include <vector>
#include "prixjournalier.h"
#include "bourse.h"
#include "date.h"

class BourseVecteur: public Bourse {
private:
    static vector<PrixJournalier> historique;
public:
    vector<string> ActionsDisponibles(date d){
    vector<string> actions;
    for(int i = 0; i < historique.size(); i++) {
        if(historique.at(i).getdate() == d)
            actions.push_back(historique.at(i).getaction());
    }
    return actions;
    }
    friend vector<PrixJournalier> PrixJournaliers(date d){
    vector<PrixJournalier> pjd;
    for(int i = 0; i < historique.size(); i++) {
        if(historique.at(i).getdate() == d)
            pjd.push_back(historique.at(i));
    }
    return pjd;

    }
};

// Déclaration des fonctions amies
vector<string> ActionsDisponibles(date d);
vector<PrixJournalier> pjd(date d);



