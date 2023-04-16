#include<iostream>
using namespace std ;

class date {
	private:
		int jour;
		int mois;
		int annee;
	public:
		date(int jj,int mm,int aa);
		void incrementerdate();
		friend ostream& operator<<(ostream& flux , const date& d);
};

date::date(int jj=0,int mm=0,int aa=0){
bool b=true;

if((mm<1)||(mm>12))
	b=false;
else{
	switch(mm) {
		case 2:
			if(aa%4==0){
				if((jj>29)||(jj<1))
					b=false;
			}
			else {
				if((jj>28)||(jj<1))
					b=false;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if((jj>30)||(jj<1))
				b=false;
			break;
		default :
			if((jj>31)||(jj<1))
				b=false;
		}
	}

if(b){
	annee=aa;
	mois=mm;
	jour=jj;
	}
else{
	annee=0;
	mois=0;
	jour=0;
	}
}


void date::incrementerdate(){
	switch(mois){
		case 2 :
			if(annee%4==0)
				if(jour==29){
					jour=1;
					mois++;
				}
			else if (jour=28){
				jour=1;
				mois++;
			}
			else{
				jour++;
			}
			break ;
		case 4:
		case 6:
		case 9:
		case 11:
			if(jour==30){
				jour=1;
				mois++;
			}
			else{
				jour++;
			}
			break;
		case 12 :
			if(jour==31){
				jour=1;
				mois=1;
				annee++;
			}
			else
				jour++;
			break;
		default :
			if(jour==31){
				jour=1;
				mois++;
			}
			else
				jour++;
	}
}

ostream& operator<<(ostream& flux, const date& d ){

	flux<<d.jour<<"/"<<d.mois<<"/"<<d.annee<<endl ;
	return flux ;
}

class prixjournalier {
	private:
		date date;
		char[10] nomaction;
		double prix;
	public:
		prixjournalier(date d,char[10] nom,double p);
		date getdate();
	        char[10] getnomaction();
	        double getprix();
		friend ostream& operator<<(ostream& flux , const prixjournalier& pj);
};

class prixjournalier {
	private:
		date date;
                char nomaction[10];
		double prix;
	public:
		class date getdate(){return date;}
                double getprix(){return prix;}
                friend ostream& operator<<(ostream& flux , const prixjournalier& pj);
		prixjournalier (class date d,char nom[10],double p)
		{
		   date=d;
		   for (int i=0;i<10;i++)
           {
               nom[i]=nomaction[i];
           }

		   prix=p;
		}
};

ostream& operator<<(ostream& flux , const prixjournalier& pj)
		{
		    flux<<pj.date<<"/"<<pj.nomaction<<"/"<<pj.prix<<endl;
		    return flux ;
		}

int main(){
	date d(0,4,2011);
	cout<<"etant  donne la date : "<<endl;
	cout<<d<<endl;
	cout<<"on obtient la date : "<<endl;
	cout<<d<<endl;

	date d1(15,0,2011);
	cout<<"etant  donne la date : "<<endl;
	cout<<d1<<endl;
	cout<<"on obtient la date : "<<endl;
	cout<<d1<<endl;

	date d2(1,5,2011);
	cout<<"etant  donne la date : "<<endl;
	cout<<d2<<endl;
	cout<<"on obtient la date : "<<endl;
	cout<<d2<<endl;

	date d3(1,5,2011);
	cout<<"etant  donne la date : "<<endl;
	cout<<d3<<endl;
	cout<<"apres avoir incremente"<<endl;
	cout<<"on obtient la date : "<<endl;
	d3.incrementerdate();
	cout<<d3<<endl;


	date d4(30,4,2011);
	cout<<"etant  donne la date : "<<endl;
	cout<<d4<<endl;
	cout<<"apres avoir incremente"<<endl;
	cout<<"on obtient la date : "<<endl;
	d4.incrementerdate();
	cout<<d4<<endl;

	date d5(31,12,2011);
	cout<<"etant  donne la date : "<<endl;
	cout<<d5<<endl;
	cout<<"apres avoir incremente"<<endl;
	cout<<"on obtient la date : "<<endl;
	d5.incrementerdate();
	cout<<d5<<endl;



	return 0 ;

}
