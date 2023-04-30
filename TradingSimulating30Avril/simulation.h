#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED
#include "boursevecteur.h"
#include "bourse.h"
#include "trader.h"
#include "date.h"
#include "portefeuille.h"

class Simulation{
    date datedebut;
    date datefin;
    date datecourante;
    double budget;
public:
    Simulation(date d1,date d2,date d,double x):datedebut(d1),datefin(d2),datecourante(d),budget(x){};
    double executer(BourseVecteur& boursevecteur,Trader& trader)
    {
       vector<Titre> Titres;
       Portefeuille PF(budget,Titres);
       date d=datedebut;
       while(d<=datefin)
       {
           cout<<"le jour: ";
           cout<<d;
           cout<<" ";
           trader.effectuerTransactions(boursevecteur,PF,d);
           d++;
       }
           return(PF.getSolde());

    }

};

#endif // SIMULATION_H_INCLUDED
