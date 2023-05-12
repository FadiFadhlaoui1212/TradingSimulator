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
        virtual Transaction prendreDecision( const Bourse& bourse, const Portefeuille& portefeuille,date &date)=0;
        Trader(){};
};

class TraderAleatoire : public Trader {
    public :
        TraderAleatoire(){};
        Transaction prendreDecision(const Bourse& bourse, const Portefeuille& portefeuille, date &date)
        {
            int choix=rand()%3;
            int x;
            int r;
            if(choix==0)
            {
                 cout<< "il a decide d'acheter"<<endl;
                 int taille=bourse.PrixJournaliersParDate(date).size();
                 if(taille>0)
                 {
                     int r=rand()%taille;
                     int a=floor(portefeuille.getSolde()/bourse.PrixJournaliersParDate(date).at(r).getprix());
                     if(a>=1)
                     {
                         int x=rand()%a+1;
                         Transaction t(ACHAT,x,bourse.getActionsDisponiblesParDate(date).at(r));
                         return t;
                     }
                     else
                     {
                         Transaction t(ACHAT,0,"N/A");
                         return t;
                     }
                 }
                else
                {
                    Transaction t(ACHAT,0,"N/A");
                    cout<<"bourse fermee ---->";
                    return t;
                }

            }
            if(choix==1)
            {
                cout<<"il a decide de vendre"<<endl;
                if(portefeuille.Titres.size()==0)
                {
                    x=0;
                    Transaction t(VENTE,x,"N/A");
                    cout<<"le portefeuille est vide ---->";
                    return t;
                }
                else
                {
                    int taille=portefeuille.Titres.size();
                    r=rand()%taille;
                    int qte=portefeuille.Titres.at(r).getQuantite();
                    x=rand()%qte+1;
                    Transaction t(VENTE,x,portefeuille.Titres.at(r).getAction());
                    return t;
                }

            }
            else
            {
                Transaction t(RIEN,0,"N/A");
                return t;
            }
        }
} ;

class TraderSemiAleatoire:public Trader{
    Transaction prendreDecision(const Bourse& bourse, const Portefeuille& portefeuille, date &date)
    {
        int choix;
        choix=rand()%3;
        if(choix==0)
        {
            if(bourse.PrixJournaliersParDate(date).size()>0)
            {
            PrixJournalier pj=bourse.PrixJournaliersParDate(date).at(0);
            for(unsigned int i=0;i<bourse.PrixJournaliersParDate(date).size();i++)
            {
                if(bourse.PrixJournaliersParDate(date).at(i).getprix()<pj.getprix())
                    pj=bourse.PrixJournaliersParDate(date).at(i);
            }
            if(portefeuille.getSolde()<pj.getprix())
            {
                Transaction t(ACHAT,0,"N/A");
                return t;
            }
            else
            {
                Transaction t(ACHAT,1,pj.getaction());
                return t;
            }
            }
            else
            {
                Transaction t(ACHAT,0,"N/A");
                return t;
            }
        }
        else if(choix==1)
        {
            cout<<"il a decide de vendre"<<endl;
            if(portefeuille.Titres.size()!=0)
            {
            Titre tre=portefeuille.Titres.at(0);
            for(unsigned int i=0;i<portefeuille.Titres.size();i++)
            {
                cout<<"le dernier prix est"<<bourse.dernierprix(tre.getAction())<<endl;
                if(bourse.dernierprix(portefeuille.Titres.at(i).getAction())<bourse.dernierprix(tre.getAction()))
                    tre=portefeuille.Titres.at(i);
            }
            Transaction t(VENTE,tre.getQuantite(),tre.getAction());
            return t;
            }
            else
            {
                Transaction t(VENTE,0,"N/A");
                return t;
            }
        }
        else
        {
            Transaction t(RIEN,0,"N/A");
            return t;
        }
    }
};

class TraderHumain : public Trader{
public:
    TraderHumain(){};
    Transaction prendreDecision(const Bourse& bourse, const Portefeuille& portefeuille, date &date)
    {
        int choix;
        int x;
        string action;
        cout<<"quelle action vous voulez effectuer"<<endl;
        cout<<"Tapez(0) si Vous voulez Acheter"<<endl;
        cout<<"Tapez(1) si vous voulez vendre"<<endl;
        cout<<"Tapez(2) si vous ne voulez rien faire"<<endl;
        cin>>choix;
        if(choix==0)
        {
            cout<<" vous avez "<<portefeuille.getSolde()<<" comme budget dans le portefeuille "<<endl;
            cout<<" tapez le nom de l'action que vous voulez acheter "<<endl;
            cin>>action;
            int r=PrixJournalier(date,action,0).existe(bourse.PrixJournaliersParDate(date));
            if(r>=0)
            {
                cout<<"le prix de cette action"<<bourse.PrixJournaliersParDate(date).at(r).getprix()<<endl;
                cout<<"Tapez la quantité que vous voulez achetez "<<endl;
                do
                {
                    cin>>x;
                }while(bourse.PrixJournaliersParDate(date).at(r).getprix()*x>portefeuille.getSolde());
                Transaction t(ACHAT,x,action);
                return t;
            }
            else
            {
                cout<<"cette action n'est pas disponible aujourdhui"<<endl;
                Transaction t(ACHAT,0,"N/A");
                return t;
            }
        }
        else if(choix==1)
        {
            if(portefeuille.Titres.size()==0)
            {
              cout<<" le portefeuille est vide "<<endl;
              Transaction t(VENTE,0,"N/A");
            }
            else
            {
                cout<<"__________________"<<endl;
                cout<<"|"<<"action"<<"|"<<"quantite"<<"|"<<endl;
                cout<<"__________________"<<endl;
                for(unsigned int i=0;i<portefeuille.Titres.size();i++)
                {
                    cout<<"|"<<portefeuille.Titres.at(i).getAction()<<"|"<<portefeuille.Titres.at(i).getQuantite()<<"|"<<endl;
                    cout<<"__________________"<<endl;
                }
                do
                {
                    cout<<" tapez le nom de l'action que vous voulez choisir "<<endl;
                    cin>>action;
                }while(portefeuille.existe(action)==-1);
                do
                {
                    cout<<" tapez la quantite que vous voulez acheter de l'action "<<action<<endl;
                    cin>>x;
                }while(x>portefeuille.Titres.at(portefeuille.existe(action)).getQuantite());
                Transaction t(VENTE,x,action);
                return t;
            }
        }
        else
        {
            Transaction t(RIEN,0,"N/A");
            return t;
        }

    }





};







#endif // TRADER_H_INCLUDED
