#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED
#include "boursevecteur.h"
#include "bourse.h"
#include "trader.h"
#include "date.h"
#include "portefeuille.h"
#include "triplet.h"
#include <chrono>
#include <map>



class Simulation{
    date datedebut;
    date datefin;
    date datecourante;
    double budget;
public:
    Simulation(date d1,date d2,date d,double x):datedebut(d1),datefin(d2),datecourante(d),budget(x){};
    map<string,long> executer(BourseVecteur& boursevecteur,Trader& trader)
    {
       map<string,long> stats={
       {"NB_ACHAT",0},
       {"NB_VENTE",0},
       {"NB_RIEN",0},
       {"TEMPS_GET_ACTIONS_MICRO_SEC",0},
       {"TEMPS_SIMULATION_MICRO_SEC",0}
       };
       vector<string> actions;
       auto start = chrono::high_resolution_clock::now();
       auto actionsAujourdhui = boursevecteur.getActionsDisponiblesParDate(datedebut);
       auto stop = chrono::high_resolution_clock::now();
       auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
       stats["TEMPS_GET_ACTIONS_MICRO_SEC"]+=duration.count();
       auto start_simulation = chrono::high_resolution_clock::now();
       vector<Titre> Titres;
       Portefeuille portefeuille(budget,Titres);
       date d=datedebut;
       while(d<=datefin)
       {
           cout<<"le jour: ";
           cout<<d<<endl;
           cout<<" ";
           for(int i=0;i<100;i++)
           {
               triplet trp;
               trp=trader.prendreDecision(boursevecteur,portefeuille,d);
               int choix=trp.getchoix();
               int x=trp.getquantite();
               int r=trp.getposition();
               if(choix==0)
               {
                   if(r>0)
                   {
                       portefeuille.retirermontant(boursevecteur.PrixJournaliersParDate(d).at(r).getprix()*x);
                       string s=boursevecteur.getActionsDisponiblesParDate(d).at(r);
                       if(portefeuille.existe(s)==-1)
                       {
                           Titre t(s,x);
                           portefeuille.ajoutertitre(t);
                       }
                       else
                       {
                           portefeuille.Titres.at(portefeuille.existe(s)).ajouterQuantite(x);
                       }
                       cout<<"Le traideur a achete l'action ";
                       cout<<boursevecteur.getActionsDisponiblesParDate(d).at(r);
                       cout<<" d'une quantite ";
                       cout<<x;
                       cout<<" Le montant retire est donc ";
                       cout<<boursevecteur.PrixJournaliersParDate(d).at(r).getprix()*x<<endl;
                       stats["NB_ACHAT"]++;
                   }
                   else
                   {
                       cout<<"vente impossible"<<endl;
                   }
               }
               if(choix==1)
               {
                   if(r>=0)
                   {
                       portefeuille.Titres.at(r).retirerQuantite(x);
                       if(portefeuille.Titres.at(r).getQuantite()==0)
                       portefeuille.retirertitre(r);
                       portefeuille.deposermontant(boursevecteur.dernierprix(portefeuille.Titres.at(r).getAction(),d)*x);
                       cout<<" Le Traideur a vendu l'action ";
                       cout<<portefeuille.Titres.at(r).getAction();
                       cout<<" d'une quantite ";
                       cout<<x;
                       cout<<"Le montant depose est";
                       cout<<boursevecteur.dernierprix(portefeuille.Titres.at(r).getAction(),d)*x<<endl;
                       stats["NB_VENTE"]++;

                   }
                   else
                   cout<<"vente impossible"<<endl;

               }
               if(choix==2)
               {
                   cout<<"il n'a rien fait"<<endl;
                   stats["NB_RIEN"]++;
                   break;
               }
           }
           d++;
           }
        auto stop_simulation = chrono::high_resolution_clock::now();
        auto duration_simulation = chrono::duration_cast<chrono::microseconds>(stop_simulation - start_simulation);
        stats["TEMPS_SIMULATION_MICRO_SEC"]+=duration_simulation.count();
        cout<<"le budget final est "<<portefeuille.getSolde()<<endl;
        return stats;
       }
    };



#endif // SIMULATION_H_INCLUDED
