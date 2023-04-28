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
    date getdatedebut(){return datedebut;};
    date getdatefin(){return datefin;};
    Simulation(date d1,date d2,date d,double x):datedebut(d1),datefin(d2),datecourante(d),budget(x){};
    double executer(BourseVecteur& boursevecteur,Trader& trader,Simulation& simulation)
    {
       Portefeuille PF(budget);
       for(date d=simulation.getdatedebut(); d<=simulation.getdatefin(); d++)
       {
           trader.effectuerTransactions(boursevecteur,PF,d);
       }
           return(PF.getSolde());

    }

};

#endif // SIMULATION_H_INCLUDED
