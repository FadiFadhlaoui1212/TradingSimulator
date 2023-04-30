#ifndef TRIPLET_H_INCLUDED
#define TRIPLET_H_INCLUDED
class triplet
{
    int choix;
    int quantite;
    int position;
public:
    triplet(){};
    triplet(int c,int x,int position):choix(c),quantite(x),position(position){};
    ~triplet(){};
    int getchoix(){return choix;};
    int getquantite(){return quantite;};
    int getposition(){return position;}
};


#endif // TRIPLET_H_INCLUDED
