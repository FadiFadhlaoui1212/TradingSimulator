#ifndef BOURSESET_H_INCLUDED
#define BOURSESET_H_INCLUDED
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
class BourseSet:public Bourse
{
private:
    set<PrixJournalier> historique;
public:
    BourseSet(set<PrixJournalier>& h):historique(h){};
    ~BourseSet(){};
    vector<string> getActionsDisponiblesParDate(date d)
    {
        vector<string> actions;
        auto it = historique.lower_bound(PrixJournalier(d,"", 0));
        while(!(it==historique.end())&& (it->getdate()==d))
        {
            actions.push_back(it->getaction());
            it++;
        }
        return actions;
    }
    vector<PrixJournalier> PrixJournaliersParDate(date d)
    {
        vector<PrixJournalier> pjd;
        auto it = historique.lower_bound(PrixJournalier(d,"", 0));
        while(!(it==historique.end())&& (it->getdate()==d))
        {
            pjd.push_back(*it);
            it++;
        }
        return pjd;
    }
    double dernierprix(string action,date d)
    {
        double x;
        for (auto it = historique.begin(); it != historique.end(); ++it)
        {
            if((it->getaction()==action)&&(it->getdate()<=d))
                x=it->getprix();
            if((d <= it->getdate()) && !(d == it->getdate()))
                break;
        }
        return x;
    }


};



#endif // BOURSESET_H_INCLUDED
