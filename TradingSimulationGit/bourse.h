#ifndef BOURSE_H_INCLUDED
#define BOURSE_H_INCLUDED
#include "date.h"


class Bourse {
    protected:
    date aujourdhui;
    public:
    virtual ~Bourse(){};
    virtual vector<string> getActionsDisponiblesParDate(date d);
    virtual vector<PrixJournalier> getPrixJournaliersParDate(date d);
    Bourse(date ajd):aujourdhui(ajd){};
    date getdateaujourdhui() const{return aujourdhui;}
};


#endif // BOURSE_H_INCLUDED
