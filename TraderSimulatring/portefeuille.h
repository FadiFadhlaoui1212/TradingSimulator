#ifndef PORTEFEUILLE_H_INCLUDED
#define PORTEFEUILLE_H_INCLUDED
#include<vector>

class Titre{
string action;
int quantite;
public:
    Titre(string action,int quantite):action(action),quantite(quantite){};
    ~Titre(){};
    string getAction{return action;};
    int getQuantite(return quantite;);
};

class Portefeuille
{
double solde;
static vector<Titre> Titres;
static int nbTitres;
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

};





#endif // PORTEFEUILLE_H_INCLUDED
