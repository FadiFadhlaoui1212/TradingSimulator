#include <vector>
#include "prixjournalier.h"
#include "bourse.h"
#include "date.h"

class BourseVecteur: public Bourse  {
private:
    static vector<PrixJournalier> historique;
public:
    vector<string> getActionsDisponiblesParDate(date d) const{
    vector<string> actions;
    for(unsigned int i = 0; i < historique.size(); i++) {
        if(historique.at(i).getdate() == d)
            actions.push_back(historique.at(i).getaction());
    }
    return actions;
    }
    vector<PrixJournalier> PrixJournaliersParDate(date d)const {
    vector<PrixJournalier> pjd;
    for(unsigned int i = 0; i < historique.size(); i++) {
        if(historique.at(i).getdate() == d)
            pjd.push_back(historique.at(i));
    }
    return pjd;

    }
};

