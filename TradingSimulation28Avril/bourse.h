#ifndef BOURSE_H_INCLUDED
#define BOURSE_H_INCLUDED
#include "date.h"


class Bourse {
    protected:
    date aujourdhui;
    public:
    Bourse(date ajd):aujourdhui(ajd){};
    virtual ~Bourse()=0;
    virtual vector<string> getActionDisponiblesParDate(date d)const=0;
    virtual vector<PrixJournalier> PrixJournaliersParDate(date d)const=0;
    date getdateaujourdhui() const{return aujourdhui;}
};


#endif // BOURSE_H_INCLUDED
