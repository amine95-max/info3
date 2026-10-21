#include <stdio.h>
#include <stdlib.h>

typedef struct Chainon{
        int elmt;
        struct Chainon * suivant;
}Chainon;

typedef struct{
	Chainon *debut;
	Chainon *fin;
	
}File;

Chainon *creationChainon(int a){
	Chainon *n=malloc(sizeof(Chainon));
	if(n==NULL){
		exit(1);
	}
	n->elmt=a;
	n->suivant=NULL;
	return n;	
}
	
File enfiler(int a, File* pf){
	if(pf==NULL){
		free(p);
	}
	Chainon *n=creationChainon(a);
	if(pf->debut==NULL){
		pf->debut=n;
		pf->fin=n;
		
	}
	else{
		pf->fin->suivant=n;
		pf->fin=n;
}		
int defiler(File *pf={
	if(pf==NULL){
		exit(3);
	}
	if(pf->debut==NULL){// si file vide
		return 0;
	}
	if(pf->debut == pf->fin){
		int a=pf->debut->elmt;
		Chainon *p=pf->debut;
		pf->debut=NULL;
		pf->fin=NULL;
		free(p);
		return a;
	}	
	Chainon *p=pf->debut;
	pf->debut=pf->debut->suivant;
	inta=p->elmt;
	free(p);
	return a;	
	
}


int main(){
	File pf;
	f.debut=NULL;
	f.fin=NULL;
	enfiler(10, &f);
	return 0;
}		
