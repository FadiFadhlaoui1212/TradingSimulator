#ifndef TRADER_H_INCLUDED
#define TRADER_H_INCLUDED
#include"boursevecteur.h"
#include"portefeuille.h"
#include<vector>
class Trader {
    public :
        virtual void effectuerTransactions(const BourseVecteur& boursevecteur, const Portefeuille& portefeuille)=0;
};

class TraderAleatoire : public Trader {
    public :
        void effectuerTransactions(const BourseVecteur& boursevecteur, const Portefeuille &portefeuille,const date &date)
        {
           int i=0;
           s=rand()%3;
           while(i<100 && s!=2 )
           {
              int r;
              r=rand()%boursevecteur.ActionDisponibles(date).size();
              switch(s)
              {
                  case 0:
                      portefeuille.retirermontant(boursevecteur.PrixJournaliers(date).at(r));
                  case 1:
                      portefeuille.deposermontant(boursevecteur.PrixJournaliers(date).at(r));

              }
              i++;
           }
        }
} ;


#endif // TRADER_H_INCLUDED
