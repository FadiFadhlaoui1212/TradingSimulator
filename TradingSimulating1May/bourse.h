#ifndef BOURSE_H_INCLUDED
#define BOURSE_H_INCLUDED
#include "date.h"


class Bourse {
    protected:
    date aujourdhui;
    public:
    Bourse(){};
    Bourse(date ajd):aujourdhui(ajd){};
    virtual ~Bourse(){};
    virtual vector<string> getActionsDisponiblesParDate(date d)=0;
    virtual vector<PrixJournalier> PrixJournaliersParDate(date d)=0;
    date getdateaujourdhui() const{return aujourdhui;}
};


#endif // BOURSE_H_INCLUDED
