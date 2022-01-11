#include<iostream>
#include<cstring>
#include<cstdlib>


#include "Etudiant.h"
using namespace std;



int Etudiant::n = 0;


Etudiant::Etudiant(){
	cout<<"DEFAULT CONSTRUCTOR : ACTIVE";
	matricule = 0;
	//nom = "NONE"; !! don't do this 
	nom = (char*)malloc(sizeof("NONE"));
	strcpy(nom, "NONE");
	nbrNotes = 0;
	tabNotes = new float[nbrNotes];
}

Etudiant::Etudiant(char* name, int N){
    ++n;
	matricule = n;
	//nom = name;
	nom = (char*)malloc(sizeof(name));
	strcpy(nom, name);
	nbrNotes = N;
	tabNotes = new float[N];
}

Etudiant::~Etudiant(){
	delete [] tabNotes;
	cout<<"--Destructeur active: tableau detruit --- GOOD WORK"<<endl;
}



Etudiant::Etudiant(const Etudiant &E){
	matricule = E.matricule;
	nom = (char*)malloc(sizeof(E.nom));
	//nom = E.nom;
	strcpy(nom, E.nom);
	nbrNotes = E.nbrNotes;
	tabNotes = new float[nbrNotes];
	for(int i=0; i< nbrNotes ; i++){
		tabNotes[i] = E.tabNotes[i];
	}
}

int Etudiant::getMatricule(){
	return matricule;
}

char* Etudiant::getNom(){
	return nom;
}

int Etudiant::getNbrNotes(){
	return nbrNotes;
}

float* Etudiant::getTabNotes(){
	return tabNotes;
}
	    
	    
	    
void Etudiant::setMatricule(int id){
	matricule = id;
}

void Etudiant::setNom(char* name){
	//nom=name;
	nom = (char*)malloc(sizeof(name));
	strcpy(nom, name);
}
void Etudiant::setNbrNotes(int n){
	nbrNotes = n;
}

void Etudiant::setTabNotes(int position, float Newnote){
	for(int i=0; i<nbrNotes; i++){
		if(i == position){
			tabNotes[i] = Newnote;
		}
		
	}
}


ostream & operator<<(ostream &out, const Etudiant &E){
     cout<< "\n----STUDENT INFORMATION -----\n";
     out<<"> NOM : "<< E.nom<<endl;
     out<<"> Number of grades : "<< E.nbrNotes<<endl;
     out<<"> liste of grades : \n";
     for(int i =0; i<E.nbrNotes; i++){
		out<<"-note "<<i+1<< ": " <<E.tabNotes[i]<<endl;
	}
	cout<< "------------------------\n";
	return out;
	
}


istream& operator>>(istream& in, Etudiant& E){

	cout << "Enter the name of student : "<<endl;
	in>> E.nom;
	
	cout << "Enter the number of grades : "<<endl;
	in>> E.nbrNotes;
	
	cout << "Enter the list of grades: ";
	for(int i =0; i<E.nbrNotes; i++){
		cout<< "note "<< i+1 << "> ";
		in>> E.tabNotes[i];
	}
	
	return in;
}

void Etudiant::affiche(){
			cout<< "\n----STUDENT INFORMATION -----\n";
		     cout<<"> NOM : "<< nom<<endl;
		     cout<<"\n> Number of grades : "<< nbrNotes<<endl;
		     cout<<"\n> liste of grades : \n";
		     for(int i =0; i<nbrNotes; i++){
				cout<<"-note "<<i+1<<" : " <<tabNotes[i]<<endl;
			}
			cout<< "\n------------------------\n";
};

float Etudiant::moyenne(){
	float sum = 0.0;
	for(int i=0; i<nbrNotes; i++){
		sum += tabNotes[i];
	}
	
	return sum/nbrNotes;
}

bool Etudiant::admis(){
	return( moyenne()>=10 );
}

bool Etudiant::comparer(Etudiant E){
	return ( moyenne()==E.moyenne() ); 
}

