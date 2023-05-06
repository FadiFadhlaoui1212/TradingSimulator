#ifndef BOURSEDICTIONNAIRE_H_INCLUDED
#define BOURSEDICTIONNAIRE_H_INCLUDED
#include "prixjournalier.h"
#include <map>
#include <vector>
#include <string>


class BourseDictionnaire:public Bourse
{
  private:
      map<int,PrixJournalier> historique;
  public:
      BourseDictionnaire(map<int,PrixJournalier>& h):historique(h){};
      ~BourseDictionnaire(){};
      vector<string> getActionsDisponiblesParDate(date d)
      {
          vector<string> actions;
          for(auto& elem: dict)
          {
              if(elem.second.getdate()==d)
              actions.push_back(elem.second.getaction()):
          }
          return actions;
      }
      vector<PrixJournalier> PrixJournaliersParDate(date d)
      {
          vector<PrixJournalier> pjd;
          for(auto& elem: dict)
          {
              if(elem.second.getdate()==d)
                actions.push_back(elem.second);
          }
          return pjd;
      }

      double dernierprix(string action,date d)
      {
          (for unsigned int i=historique.size();i>0;i--)
          {
              if(historique[i].getaction()==action)&&(historique[i].getdate()<=d)
                return historique[i].getprix();
          }
          return 0;
      }
};

#endif // BOURSEDICTIONNAIRE_H_INCLUDED
