#ifndef BOURSEVECTEUR_H
#define BOURSEVECTEUR_H

#include <vector>
#include "prixjournalier.h"
#include "bourse.h"
#include "date.h"

class BourseVecteur: public Bourse  {
private:
    vector<PrixJournalier> historique;
public:
    BourseVecteur(vector<PrixJournalier>& h):historique(h){};
    ~BourseVecteur(){};
    vector<string> getActionsDisponiblesParDate(date d) {
    vector<string> actions;
    for(unsigned int i = 0; i < historique.size(); i++) {
        if(historique.at(i).getdate() == d)
            actions.push_back(historique.at(i).getaction());
    }
    return actions;
    }
    vector<PrixJournalier> PrixJournaliersParDate(date d){
    vector<PrixJournalier> pjd;
    for(unsigned int i = 0; i < historique.size(); i++) {
        if(historique.at(i).getdate() == d)
            pjd.push_back(historique.at(i));
    }
    return pjd;

    }
    double dernierprix(string action,date d)
    {
        for(unsigned int i=historique.size()-1;i>0;i--)
        {
            if((historique.at(i).getaction()==action)&&(historique.at(i).getdate()<=d))
                return historique.at(i).getprix();

        }
        return 0;
    }
};
#endif
