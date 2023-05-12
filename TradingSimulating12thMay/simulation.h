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
    map<string,long> executer(Bourse& bourse,Trader& trader)
    {
       map<string,long> stats={
       {"NB_ACHAT",0},
       {"NB_VENTE",0},
       {"NB_RIEN",0},
       {"TEMPS_GET_ACTIONS_NANO_SEC",0},
       {"TEMPS_SIMULATION_MICRO_SEC",0}
       };
       date d=datedebut;
       int s=0;
       vector<string> actions;
       bourse.setdateaujourdhui(datedebut);
       auto start_simulation = chrono::high_resolution_clock::now();
       vector<Titre> Titres;
       Portefeuille portefeuille(budget,Titres);
       while(d<=datefin)
       {
           if(bourse.getActionsDisponiblesParDate(d).size()!=0)
       {
          auto start = chrono::high_resolution_clock::now();
          auto actionsAujourdhui = bourse.getActionsDisponiblesParDate(d);
          auto stop = chrono::high_resolution_clock::now();
          auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
          stats["TEMPS_GET_ACTIONS_NANO_SEC"]+=duration.count();
          cout<<" la taille est "<<bourse.getActionsDisponiblesParDate(d).size()<<endl;
          cout<<" la duree de notre methode a la date"<<d<<" est "<<duration.count()<<endl;
          s++;
       }
           cout<<"le jour: ";
           cout<<d<<endl;
           cout<<" ";
           for(int i=0;i<100;i++)
           {
               Transaction tx;
               tx=trader.prendreDecision(bourse,portefeuille,d);
               TypeTransaction choix=tx.getchoix();
               int x=tx.getquantite();
               string action=tx.getaction();
               if(choix==ACHAT)
               {
                   if(action!="N/A")
                   {
                       date dd(4,1,2010);
                       PrixJournalier pj(dd,action,0);
                       int r=pj.existe(bourse.PrixJournaliersParDate(d));
                       portefeuille.retirermontant(bourse.PrixJournaliersParDate(d).at(r).getprix()*x);
                       if(portefeuille.existe(action)==-1)
                       {
                           Titre t(action,x);
                           portefeuille.ajoutertitre(t);
                       }
                       else
                       {
                           portefeuille.Titres.at(portefeuille.existe(action)).ajouterQuantite(x);
                       }
                       cout<<"   Le traideur a achete l'action   ";
                       cout<<bourse.getActionsDisponiblesParDate(d).at(r);
                       cout<<" d'une quantite ";
                       cout<<x;
                       cout<<"   Le montant retire est donc   ";
                       cout<<bourse.PrixJournaliersParDate(d).at(r).getprix()*x<<endl;
                       stats["NB_ACHAT"]++;
                   }
                   else
                   {
                       cout<<"achat impossible"<<endl;
                   }
               }
               if(choix==VENTE)
               {
                   if(action!="N/A")
                   {
                       int r=portefeuille.existe(action);
                       PrixJournalier px(d,action,0);
                       int p=px.existe(bourse.PrixJournaliersParDate(d));
                       date dd(4,1,2010);
                       PrixJournalier pj(dd,action,0);
                       if(bourse.PrixJournaliersParDate(d).size()!=0)
                       {
                       int ex=pj.existe(bourse.PrixJournaliersParDate(d));
                       if(ex>=0)
                       {
                       portefeuille.Titres.at(r).retirerQuantite(x);
                       portefeuille.deposermontant(bourse.dernierprix(portefeuille.Titres.at(r).getAction())*x);
                       cout<<" Le Traideur a vendu l'action ";
                       cout<<portefeuille.Titres.at(r).getAction();
                       cout<<" d'une quantite ";
                       cout<<x;
                       cout<<"Le montant depose est  ";
                       cout<<(bourse.PrixJournaliersParDate(d).at(p).getprix())*x<<endl;
                       stats["NB_VENTE"]++;
                       if(portefeuille.Titres.at(r).getQuantite()==0)
                       portefeuille.retirertitre(r);
                       }
                       else
                       {
                           cout<<"l'action "<<action<<" n'est pas disponible dans ce jour la"<<endl;
                       }
                       }
                       else
                       {
                           cout<<"pas d'actions disponibles aujourdhui"<<endl;
                       }
                   }
                   else
                   cout<<"vente impossible"<<endl;

               }
               if(choix==RIEN)
               {
                   cout<<"il n'a rien fait"<<endl;
                   stats["NB_RIEN"]++;
                   break;
               }
           }
           cout<<" le budget obtenu apres avoir realise les transactions de ce jour est "<<portefeuille.getSolde()<<endl;
           d++;
           bourse.setdateaujourdhui(d);
           }
        while(portefeuille.Titres.size()!=0)
        {
            int qte=portefeuille.Titres.at(0).getQuantite();
            double x=bourse.dernierprix(portefeuille.Titres.at(0).getAction());
            portefeuille.deposermontant(qte*x);
            portefeuille.retirertitre(0);
        }
        stats["TEMPS_GET_ACTIONS_NANO_SEC"]/=s;
        auto stop_simulation = chrono::high_resolution_clock::now();
        auto duration_simulation = chrono::duration_cast<chrono::microseconds>(stop_simulation - start_simulation);
        stats["TEMPS_SIMULATION_MICRO_SEC"]+=duration_simulation.count();
        cout<<"le budget final est "<<portefeuille.getSolde()<<endl;
        return stats;
       }
    };



#endif // SIMULATION_H_INCLUDED
