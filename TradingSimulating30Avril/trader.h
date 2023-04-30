#ifndef TRADER_H_INCLUDED
#define TRADER_H_INCLUDED
#include"boursevecteur.h"
#include"portefeuille.h"
#include"prixjournalier.h"
#include<vector>
#include <iostream>
#include <random>
#include <cmath>
#include <cstdlib>
#include <ctime>
class Trader {
    public :
        virtual void effectuerTransactions( BourseVecteur& boursevecteur,  Portefeuille& portefeuille,date &date)=0;
        Trader(){};
};

class TraderAleatoire : public Trader {
    public :
        TraderAleatoire(){};
        void effectuerTransactions (BourseVecteur& boursevecteur, Portefeuille& portefeuille, date &date)
        {
            for(int i=0;i<100;i++)
            {
            int choix=rand()%3;
            if(choix==0)
            {
               int taille=boursevecteur.PrixJournaliersParDate(date).size();
            int r=rand()%taille;
            int a=floor(portefeuille.getSolde()/boursevecteur.PrixJournaliersParDate(date).at(r).getprix());
            int x=rand()%a;
            portefeuille.retirermontant(boursevecteur.PrixJournaliersParDate(date).at(r).getprix()*x);
            string s=boursevecteur.getActionsDisponiblesParDate(date).at(r);
            if(portefeuille.existe(s)==-1)
            {
                Titre t(s,x);
                portefeuille.ajoutertitre(t);
            }
            else
            {
                portefeuille.Titres.at(portefeuille.existe(s)).ajouterQuantite(x);
                cout<<portefeuille.Titres.at(portefeuille.existe(s)).getAction()<<portefeuille.Titres.at(portefeuille.existe(s)).getQuantite()<<endl;
            }
            cout<<"Le traideur a achete l'action ";
            cout<<boursevecteur.getActionsDisponiblesParDate(date).at(r);
            cout<<" d'une quantite ";
            cout<<x;
            cout<<" Le montant retire est donc ";
            cout<<boursevecteur.PrixJournaliersParDate(date).at(r).getprix()*x<<endl;
            }
            if(choix==1)
            {
                if(portefeuille.Titres.size()!=0)
            {

              int taille=portefeuille.Titres.size();
              int r=rand()%taille;
              int qte=portefeuille.Titres.at(r).getQuantite();
              int x=rand()%qte+1;
              portefeuille.Titres.at(r).retirerQuantite(x);
              if(portefeuille.Titres.at(r).getQuantite()==0)
              portefeuille.retirertitre(r);
              portefeuille.deposermontant(boursevecteur.dernierprix(portefeuille.Titres.at(r).getAction(),date));
              cout<<" Le Traideur a vendu l'action ";
              cout<<portefeuille.Titres.at(r).getAction();
              cout<<" d'une quantite ";
              cout<<x;
              cout<<"Le montant depose est";
              cout<<boursevecteur.dernierprix(portefeuille.Titres.at(r).getAction(),date)<<endl;
            }
            else
            cout<<"vente impossible ";
            }
            if(choix==2)
                {
                    cout<<"il n'a rien fait"<<endl;
                    break;
                }
            }



        }

} ;


#endif // TRADER_H_INCLUDED
