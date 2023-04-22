#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include<iostream>
using namespace std ;

class date {
	private:
		int jour;
		int mois;
		int annee;
	public:
		date(){};
		date(int jj,int mm,int aa);
		int getjour() const;
		int getmois() const;
		int getannee() const;
		bool bisextile(int a);
		int nbjoursmois(int mm,int aa );
		void incrementerdate();
		friend void operator++(date &d1,int );
		bool datevalide();
		friend ostream& operator<<(ostream& flux , const date& d);
		friend istream& operator>>(istream& flux,date&d); //instructions unclear
		friend bool operator==(const date d1,const date d2);
		friend bool operator<=(const date d1,const date d2);

};


date::date(int jj,int mm,int aa){        //CONSTRUCTEUR

	annee=aa;
	mois=mm;
	jour=jj;

	}


int date::getjour() const{                      //ACCESSEUR JOUR
    return jour ;
    }


int date::getmois() const{                      //ACCESSEUR MOIS
    return mois ;
    }


int date::getannee() const{                     //ACCESSEUR ANNEE

    return annee;
    }


bool date::bisextile(int a){              //ANNEE BISEXTILE

if (a%4==0)
    return true ;
else
    return false ;

}


int date::nbjoursmois(int mm,int aa ){    //NOMBRE DE JOURS DANS UN MOIS

    switch(mm){
        case 1 :
        case 3 :
        case 5 :
        case 7 :
        case 8 :
        case 10:
        case 12:
            return 31;
            break ;
        case 2 :
            if(bisextile(aa))
                return 29;
            else
                return 28;
            break ;
        case 4 :
        case 6 :
        case 9 :
        case 11:
            return 30;
            break ;
    }
}


void date::incrementerdate(){        //INCREMNTER DATE

	if(jour==nbjoursmois(mois,annee)){
            if(mois==12){
                jour=1;
                mois=1;
                annee++;
            }
            else{
                jour=1;
                mois++;
            }
	}
	else
        jour++;
}


bool date::datevalide(){                 //DATE VALIDE
bool b=false ;

if((1<=jour) && (jour<=nbjoursmois(mois,annee))&&(1<=mois)&&(mois<=12))
    b=true;
return b ;
}


void operator++(date& d1,int ){         //INCREMENTATION DE DATE PAR OPERATEUR ++
d1.incrementerdate();
}


ostream& operator<<(ostream& flux, const date& d ){        //OPERATEUR OSTREAM

	flux<<d.jour<<"/"<<d.mois<<"/"<<d.annee<<endl ;
	return flux ;
}


istream& operator>>(istream& flux,date&d){               //OPERATEUR ISTREAM

int jj,mm,aa;
char tab[12];

flux.getline(tab,12,'/');
jj=atoi(tab);
flux.getline(tab,12,'/');
mm=atoi(tab);
flux.getline(tab,12);
aa=atoi(tab);

d.jour=jj;
d.mois=mm;
d.annee=aa;
return flux;
}


bool operator==(const date d1,const date d2){                       //OPERATEUR ==
bool b=false;
if(d1.jour==d2.jour && d1.mois==d2.mois && d1.annee==d2.annee)
    b=true;
return b ;
}


bool operator<=(const date d1,const date d2){                      //OPERATEUR <=
bool b=false ;

    if( (d1.annee)<=(d2.annee))
        b=true;
    else if( (d1.annee==d2.annee) && (d1.mois<=d2.mois) )
        b=true;
    else if( (d1.annee==d2.annee) && (d1.mois==d2.mois) && (d1.jour<=d2.jour) )
        b=true;

    return b ;

}

#endif // DATE_H_INCLUDED
