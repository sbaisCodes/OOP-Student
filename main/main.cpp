#include <iostream>
#include<cstring>
#include<string.h>
#include "Etudiant.h"
using namespace std;



int main(int argc, char** argv) {
	
    
	Etudiant E1,E2("salah", 7);
	
    
	cout<<"\n-----E1 :OBJET INITIALISER PAR DEFAUT------\n";
	cout<<E1;
	cout<<"\n-----E1: OBJET INITIALISER PAR ARGUEMENT : operateur >> ------\n";
    cin>>E1;
	cout<<E1;

    cout<< "\n NOM d'etudiant 1 (par defaut) using getNom : "<<E2.getNom()<<endl;
    cout<< "\n Matricule d'etudiant 1 using getmatricule : "<<E1.getMatricule()<<endl;
    cout<< "\n Matricule d'etudiant 2 using getmatricule : "<<E2.getMatricule()<<endl;
    for(int i=0; i<E2.getNbrNotes(); i++){
    	E2.setTabNotes(i, 20);
	}
	cout<<"\n ---- la fonction moyenne : ---- \n";
	cout << "moyenne de XXXXX est : "<< E2.moyenne()<<endl;
	cout<<"\n ---- la fonction admis : ---- \n";
	cout << "Status de XXXXX: "<< E2.admis()<<endl;
	cout<<"\n ---- la fonction compare : ---- \n";
	if(E2.comparer(E1)){
		cout << "E1 = E2 ? > The same "<<endl;
	}else{
		cout << ">> Not the same"<<endl;
	}
	
	Etudiant E3(E2);
	cout<<E2;
    cout<<"\n-----E3(E2) : OBJET INITIALISER PAR RECOPIE : fonction affiche ------\n";
	E3.affiche();
	
	return 0;
}
