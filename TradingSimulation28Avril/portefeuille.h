#ifndef PORTEFEUILLE_H_INCLUDED
#define PORTEFEUILLE_H_INCLUDED
#include<vector>

class Titre{
string action;
int quantite;
public:
    Titre(string action,int quantite):action(action),quantite(quantite){};
    ~Titre(){};
    string getAction(){return action;};
    int getQuantite(){return quantite;};
    void ajouterQuantite(int x){quantite+=x;};
    void retirerQuantite(int x){quantite-=x;};
};

class Portefeuille
{
double solde;
public:
static vector<Titre> Titres;
double getSolde()const{return solde;};
int nbTitres;
public:
    Portefeuille(double solde):solde(solde){};
    ~Portefeuille(){};
    void ajoutertitre(Titre t)
    {
      Titres.push_back(t);
      nbTitres++;
    }
    void retirertitre(int index)
    {
      Titres.erase(Titres.begin()+index);
      nbTitres--;
    }
    void deposermontant(double montant){solde+=montant;};
    void retirermontant(double montant){solde-=montant;};
    int existe(string action)
    {
        int s;
        s=0;
        for (unsigned int i=0;i<Titres.size();i++)
        {
            if(Titres.at(i).getAction()==action)
                return s;
            s++;
        }
        return -1;
    };

};





#endif // PORTEFEUILLE_H_INCLUDED
