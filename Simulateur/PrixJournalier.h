#ifndef PRIXJOURNALIER_H_INCLUDED
#define PRIXJOURNALIER_H_INCLUDED
#include<iostream>
#include "Date.h"


class PrixJournalier {
    private:
        date dateaction ;
        string action;
        double prix;
    public:
        PrixJournalier(){};
        PrixJournalier(date d,string na,double pj):dateaction(d),action(na),prix(pj){};
        date getdate();
        string getaction();
        double getprix();
        friend ostream& operator<<(ostream& flux , const PrixJournalier& pj);
        friend istream& operator>> (istream& flux, PrixJournalier& pj);
};


date PrixJournalier::getdate(){


return dateaction ;
}

string PrixJournalier::getaction(){

return action ;
}

double PrixJournalier::getprix(){

return prix ;
}

ostream& operator<<(ostream& flux , const PrixJournalier& pj){

flux<<"date : "<<pj.dateaction;
flux<<"action : "<<pj.action<<endl;
flux<<"prix : "<<pj.prix<<endl;
return flux ;

}

istream& operator>> (istream& flux, PrixJournalier& pj){

flux>>pj.dateaction;
char nomaction[15];
flux.getline(nomaction,15,'\n');
pj.action=nomaction;
flux>>pj.prix;

return flux ;

}



#endif // PRIXJOURNALIER_H_INCLUDED
