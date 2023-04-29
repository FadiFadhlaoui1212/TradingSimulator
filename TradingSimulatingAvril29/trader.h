#ifndef TRADER_H_INCLUDED
#define TRADER_H_INCLUDED
#include"boursevecteur.h"
#include"portefeuille.h"
#include"prixjournalier.h"
#include<vector>
#include <iostream>
#include <random>
#include <cmath>
class Trader {
    public :
        virtual void effectuerTransactions( BourseVecteur& boursevecteur,  Portefeuille& portefeuille,date &date)=0;
        Trader(){};
};

class TraderAleatoire : public Trader {
    public :
        TraderAleatoire(){};
        void effectuerTransactions (BourseVecteur& boursevecteur, Portefeuille &portefeuille, date &date)
        {
           int i=0;
           int s=rand()%3;
           while(i<100 && s!=2 )
           {
              s=rand()%3;
              int r;

              switch(s)
              {
                  case 0:
                      {
                        r=rand()%boursevecteur.getActionsDisponiblesParDate(date).size();
                        int a=floor(portefeuille.getSolde()/boursevecteur.PrixJournaliersParDate(date).at(r).getprix()); // partie entière de a/b
                        int x;
                        x=rand()%a+1;
                        portefeuille.retirermontant(boursevecteur.PrixJournaliersParDate(date).at(r).getprix()*x);
                        string s;
                        s=boursevecteur.PrixJournaliersParDate(date).at(r).getaction();
                        if(portefeuille.existe(s)==-1)
                        {
                            Titre t(boursevecteur.PrixJournaliersParDate(date).at(r).getaction(),x);
                            portefeuille.ajoutertitre(t);
                        }
                        else
                        {
                            portefeuille.Titres.at(portefeuille.existe(boursevecteur.PrixJournaliersParDate(date).at(r).getaction())).ajouterQuantite(x);
                        }



                      break;
                      }

                  case 1:
                      {
                          r=rand()%portefeuille.Titres.size();
                          int x;
                          x=rand()%(portefeuille.Titres.at(r).getQuantite()+1);
                          (portefeuille.Titres.at(r)).retirerQuantite(x);
                          if(portefeuille.Titres.at(r).getQuantite()==0)
                             portefeuille.retirertitre(r);
                          portefeuille.deposermontant(boursevecteur.PrixJournaliersParDate(date).at(r).getprix()*x);
                      }


              }
              i++;
           }
        }
} ;


#endif // TRADER_H_INCLUDED
