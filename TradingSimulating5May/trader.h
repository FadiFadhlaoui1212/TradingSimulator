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
using namespace std;
class Trader {
    public :
        virtual triplet prendreDecision( Bourse& bourse,  Portefeuille& portefeuille,date &date)=0;
        Trader(){};
};

class TraderAleatoire : public Trader {
    public :
        TraderAleatoire(){};
        triplet prendreDecision(Bourse& bourse, Portefeuille& portefeuille, date &date)
        {
            int choix=rand()%3;
            int x;
            int r;
            if(choix==0)
            {
                 int taille=bourse.PrixJournaliersParDate(date).size();
                 if(taille>0)
                 {
                     int r=rand()%taille;
                     int a=floor(portefeuille.getSolde()/bourse.PrixJournaliersParDate(date).at(r).getprix());
                     if(a>=1)
                     {
                         int x=rand()%a+1;
                         triplet t(choix,x,r);
                         return t;
                     }
                     else
                     {
                         triplet t(0,0,0);
                         return t;
                     }
                 }
                else
                {
                    triplet t(0,0,0);
                    return t;
                }

            }
            if(choix==1)
            {
                if(portefeuille.Titres.size()==0)
                {
                    x=0;
                    r=-1;
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



class TraderSemiAleatoire: public Trader{
public:
    TraderSemiAleatoire(){};
    triplet prendreDecision(Bourse& bourse, Portefeuille& portefeuille, date& date)
    {
        int choix;
        int r;
        choix=rand()%3;
        if(choix==0)
        {
            if(bourse.PrixJournaliersParDate(date).size()==0)
            {
                triplet t(0,0,-1);
                return t;
            }
            else
            {
                r=0;
                for(unsigned int i=0;i<bourse.getActionsDisponiblesParDate(date).size();i++)
                {
                    if(bourse.PrixJournaliersParDate(date).at(i).getprix()<bourse.PrixJournaliersParDate(date).at(r).getprix())
                        r=i;
                }
                triplet t(0,1,r);
                return t;
            }
        }
        else if(choix==1)
        {
            if(portefeuille.Titres.size()==0)
            {
                triplet t(1,0,-1);
                return t;
            }
            else
            {
                r=0;
                for(unsigned int i=0;i<portefeuille.Titres.size();i++)
                {
                    if(bourse.dernierprix(portefeuille.Titres.at(i).getAction(),date)>bourse.dernierprix(portefeuille.Titres.at(r).getAction(),date))
                        r=i;
                }
                triplet t(1,portefeuille.Titres.at(r).getQuantite(),r);
                return t;
            }
        }
        else
        {
            triplet t(2,0,-1);
            return t;
        }
    }








};


class TraderUtilisateur: public Trader{
public:
    TraderUtilisateur(){};
    triplet prendreDecision(BourseVecteur& boursevecteur, Portefeuille& portefeuille, date &date)
    {
        int choix;
        unsigned int num;
        int qte;
        do
        {
            cout<<"quel est votre choix"<<endl;
            cout<<"1-Achat"<<endl;
            cout<<"2-Vente"<<endl;
            cout<<"3-Rien"<<endl;
            cin>>choix;
        }while((choix<1)||(choix>3));
    if(choix==1)
    {
        do
        {
          cin>>num;
        }while(num>boursevecteur.PrixJournaliersParDate(date).size());
        do
        {
            cout<<"entrez la quantité que vous voulez achetez"<<endl;
            cin>>qte;
        }while(boursevecteur.PrixJournaliersParDate(date).at(num-1).getprix()*qte>portefeuille.getSolde());
        triplet t(choix-1,qte,num-1);
        return t;
    }
    if(choix==2)
    {
        if(portefeuille.Titres.size()==0)
        {
            cout<<"vous n'avez rien a vendre"<<endl;
            triplet t(choix-1,0,-1);
            return t;
        }
        else
        {
            cout<<"voici les numeros des actions que vous avez dans le poretefeuille tapez ce vous voulez vendre"<<endl;
            for(unsigned int i=0;i<portefeuille.Titres.size();i++)
            {
                cout<<i+1;
                cout<<portefeuille.Titres.at(i).getAction();
                cout<<" quantite "<<portefeuille.Titres.at(i).getQuantite()<<"|";
            }
            do
            {
                cout<<"donner le num de l'action que vous voulez vendre"<<endl;
                cin>>num;
            }while ((portefeuille.Titres.size()<num)||(num<=0));
            do
            {
                cout<<"donner la quantite que vous voulez vendre"<<endl;
                cin>>qte;
            }while (qte>portefeuille.Titres.at(num-1).getQuantite());
            triplet t(choix-1,qte,num-1);
            return t;
        }
    }
    if(choix==3)
    {
        triplet t(2,0,-1);
        return t;
    }

    }
};


class Tradermod3:public Trader
{
    triplet prendreDecision(Bourse& bourse, Portefeuille& portefeuille, date &date)
    {
        if((date.getjour()+date.getmois()+date.getannee())%3==1)
        {
            int taille=bourse.PrixJournaliersParDate(date).size();
            int r=rand()%taille;
            int a=floor(portefeuille.getSolde()/bourse.PrixJournaliersParDate(date).at(r).getprix());
            cout<<portefeuille.getSolde()/bourse.PrixJournaliersParDate(date).at(r).getprix()<<endl;
            cout<<a<<endl;
            int x=rand()%a+1;
            triplet t(0,x,r);
            return t;
        }
        else if((date.getjour()+date.getmois()+date.getannee())%3==2)
        {
            int taille=portefeuille.Titres.size();
            int r=rand()%taille;
            int qte=portefeuille.Titres.at(r).getQuantite();
            int x=rand()%qte+1;
            triplet t(1,x,r);
            return t;
        }
        else
        {
            triplet t(2,0,-1);
            return t;
        }

    }
};


#endif // TRADER_H_INCLUDED
