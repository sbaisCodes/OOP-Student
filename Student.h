#include<iostream>
#include<cstring>
#include<string.h>
#ifndef ETUDIANT_H
#define ETUDIANT_H


using namespace std;


class Etudiant{
	
	private: 
	   int matricule; 
	   char* nom;
	   int nbrNotes;
	   float *tabNotes;
	   static int n; // pour l'auto incrementation de matricule
	
	public: 
	    Etudiant();
	    Etudiant(char* name, int N);
	    ~Etudiant();
	    Etudiant(const Etudiant &E);
	    
	    // getters 
	    int getMatricule();
	    char* getNom();
	    int getNbrNotes();
	    float* getTabNotes();
	    
	    // setters
	    void setMatricule(int);
	    void setNom(char*);
	    void setNbrNotes(int);
	    void setTabNotes(int, float);
	    
	    // surcharge des operateurs
	    
	     friend istream& operator>>(istream&, Etudiant &);
		 friend ostream& operator<<(ostream&, const Etudiant &);

       
	    // les methodes 
	    void affiche();
	    float moyenne();
	    bool admis(); // true : moyenne >= 10
	    bool comparer(Etudiant E);// compare moyenne , true : meme moyenne 
};



#endif
