#include"exo2.h"

pArbre creationArbre(int a){
	pArbre n=malloc(sizeof(Arbre));
	if(n==NULL){
		exit(1);
	}
	n->elmt=a;
	n->fg=NULL;
	n->fd=NULL;
	return n;
	
}

int estVide(pArbre a){
	return a==NULL ? 1 : 0;
}			

int estFeuille(pAbre a){
	return a->fg==NULL && a->fd ==NULL ? 1 : 0;
	
}	

int existeFilsGauche(pAbre a){
	return a->fg!=NULL ? 1 : 0
}

int existeFilsDroite(pAbre a){
	return a->fd!=NULL ? 1 : 0
}
int ajouteFilsGauche(pArbre a, int c){
	if(!estvide(a)){
		if(!existeFilsGauche(a)){
			pArbre nouveau=creationArbre(e);
			a->fg=nouveau;
			return 1;
			}
	 }
	 return 0;
}

int ajouteFilsDroite(pArbre a, int e){
	if(!estvide(a)){
		if(!existeFilsDroite(a)){
			pArbre nouveau=creationArbre(e);
			a->fd=nouveau;
			return 1;
			}
	 }
	 return 0;
}
	 	 

void afficheInfixe(pAbre a){
	if(a!=NULL){
		affichePrefixe(a->fg);
		printf("%d ", a->elmt);
		affichePrefixe(a->fd);
	}
}	


void afficheInfixe(pAbre a){
	if(a!=NULL){
		afficheInfixe(a->fg);
		printf("%d ", a->elmt);
		afficheInfixe(a->fd);
	}
}		 

		
	



	 
int main(){
	pArbre a=NULL;
	a=creationAbre(1);
	ajouteFilsGauche(a,2);
	ajouteFilsGauche(a->fg,3);
	return 0;
}	
	 	
