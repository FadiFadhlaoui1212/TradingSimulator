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
#include "triplet.h"
class Trader {
    public :
        virtual triplet prendreDecision( BourseVecteur& boursevecteur,  Portefeuille& portefeuille,date &date)=0;
        Trader(){};
};

class TraderAleatoire : public Trader {
    public :
        TraderAleatoire(){};
        triplet prendreDecision(BourseVecteur& boursevecteur, Portefeuille& portefeuille, date &date)
        {
            int choix=rand()%3;
            int x;
            int r;
            if(choix==0)
            {
                 int taille=boursevecteur.PrixJournaliersParDate(date).size();
                 int r=rand()%taille;
                 int a=floor(portefeuille.getSolde()/boursevecteur.PrixJournaliersParDate(date).at(r).getprix());
                 int x=rand()%a+1;
                 triplet t(choix,x,r);
                 cout<<choix<<","<<x<<","<<r<<"correspond a ";
                 return t;
            }
            else if(choix==1)
            {
                if(portefeuille.Titres.size()==0)
                {
                    x=0;
                    r=-1;
                    cout<<choix<<","<<x<<","<<r<<"correspond a ";
                    triplet t(choix,x,r);
                    return t;
                }
                else
                {
                    int taille=portefeuille.Titres.size();
                    r=rand()%taille;
                    int qte=portefeuille.Titres.at(r).getQuantite();
                    x=rand()%qte+1;
                    triplet t(choix,x,r);
                    cout<<choix<<","<<x<<","<<r<<"correspond a ";
                    return t;
                }

            }
            else
            {
                triplet t(2,0,-1);
                return t;
            }


        }

} ;


#endif // TRADER_H_INCLUDED
