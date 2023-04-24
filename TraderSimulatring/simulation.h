#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED

class Simulation{
    date datedebut;
    date detefin;
    date datecourante;
    double budget;
public:
    static double executer(Boursevecteur& boursevecteur,Trader& trader,Simulation& simulation)
    {
       Portefeuille PF(budget);
       for(date=Simulation.datedebut; date<=Simulation.datefin; date++)
       {
           trader.effectuerTransaction(boursevecteur,portfeuille,date);
       }
           return(PF.getsolde());

    }

};

#endif // SIMULATION_H_INCLUDED
