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
              int s;
              s=rand()%3;
              int r;

              switch(s)
              {
                  case 0:
                      {
                        r=rand()%boursevecteur.getActionsDisponiblesParDate(date).size();
                        int max_x = static_cast<int>(floor(portefeuille.getSolde()/boursevecteur.PrixJournaliersParDate(date).at(r).getprix())); // partie entière de a/b
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<> dis(1, max_x);
                        int x = dis(gen);
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
                            Portefeuille::Titres.at(portefeuille.existe(boursevecteur.PrixJournaliersParDate(date).at(r).getaction())).ajouterQuantite(x);
                        }



                      break;
                      }

                  case 1:
                      {
                          r=rand()%Portefeuille::Titres.size();
                          int x;
                          x=rand()%(Portefeuille::Titres.at(r).getQuantite()+1);
                          (Portefeuille::Titres.at(r)).retirerQuantite(x);
                          if(Portefeuille::Titres.at(r).getQuantite()==0)
                             portefeuille.retirertitre(r);
                          portefeuille.deposermontant(boursevecteur.PrixJournaliersParDate(date).at(r).getprix()*x);
                      }


              }
              i++;
           }
        }
} ;


#endif // TRADER_H_INCLUDED
