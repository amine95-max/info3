#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Chainon{
        int elmt;
        struct Chainon *suivant;
}Chainon;


Chainon *creationChainon(int a){
	Chainon *n=malloc(sizeof(Chainon));
	if(n==NULL){
		exit(1);
	}
	n->elmt=a;
	n->suivant=NULL;
	return n;	
}

Chainon *empiler(Chainon *ppile, int a){
	Chainon *nouveau=creationChainon(a);
	nouveau->suivant=ppile;
	return nouveau;
	
}

Chainon *depiler (Chainon *ppile, int *pa){
		if(ppile!=NULL){
			Chainon *p=ppile;
			*pa=ppile->elmt;
			ppile=ppile->suivant;
			free(p);
	}
	return ppile;
}
	
void afficheListe(Chainon *pliste){ 
        Chainon *p1=pliste ;
        while(p1!=NULL){
                printf("%d \n", p1->elmt);
                p1=p1->suivant;
        }
}	
	
int main(){
	Chainon *ppile=NULL;
	Chainon *ppilepaire=NULL;
	Chainon *ppileimpaire=NULL;
	int a=0;
	for(int i=1; i<21; i++){
		ppile=empiler(ppile,i);
	}
	afficheListe(ppile);
	printf
    
    return 0;
}

