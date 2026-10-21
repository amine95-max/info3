#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Chainon{
	char elmt[21];
	struct Chainon *suivant;
	struct Chainon *precedent;
}Chainon;

Chainon *creationChainon(int a){
	Chainon *n=malloc(sizeof(Chainon));
	if(n==NULL){
		exit(1);
		
	}
	printf(" mot dans le chainon : \n");
	scanf("%s", n->elmt);
	n->suivant=NULL;
	n->precedent=NULL;
	return n;	
}

int comparemot(char *mot1, char *mot2){
	if(strcmp(mot1, mot2)<0){
		return 1;
		
	
	}
	else{
		return 0;
	}
	
	return strcmp(mot1, mot2)<0;
}

Chainon *inserListe(Chainon *pliste){
	Chainon *nouveau=creationChainon();
	if (pliste==NULL || strcmp((nouveau->elmt),( < pliste->elmt))<=0{
	nouveau->suivant=pliste;
	return nouveau;
}

	Chainon *p1=pliste;
	while (p1->suivant != NULL && (strcmp(,(p1 ->suivant->elmt)<=0){
		p1=p1->suivant=nouveau;
	}	
	
	
		
void afficheListe(Chainon *pliste){ 
        Chainon *p1=pliste ;
        while(p1!=NULL){
                printf("%d \n", p1->elmt);
                p1=p1->suivant;
        }
}		

int main(){


	return 0;
}	
