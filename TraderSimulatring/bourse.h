#ifndef BOURSE_H_INCLUDED
#define BOURSE_H_INCLUDED
#include "date.h"


class Bourse {
    protected:
    date aujourdhui;
    public:
    Bourse(date ajd):aujourdhui(ajd){};
    virtual ~Bourse()=0;
    virtual vector<string> ActionDisponibles(date d)=0;
    virtual vector<PrixJournalier> PrixJournaliers(date d)=0;
    date getdateaujourdhui() const{return aujourdhui;}
};


#endif // BOURSE_H_INCLUDED
