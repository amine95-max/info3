#include <stdio.h>
#include <stdlib.h>

typedef struct Chainon{
        int elmt;
        struct Chainon * suivant;
}Chainon;

Chainon *creationChainon(int a){
        Chainon* nouveau =malloc(sizeof(Chainon));
        if(nouveau == NULL){
                exit(1);
        }
        
        nouveau->elmt=a;
        nouveau->suivant = NULL;
        return nouveau;

} 	

Chainon *insertTrie(int a, Chainon *pliste){
	Chainon *nouveau=creationChainon(a);
	if (pliste==NULL || a < pliste->elmt){
	nouveau->suivant=pliste;
	return nouveau;
}

	Chainon *p1=pliste;
	while (p1->suivant != NULL && p1 ->suivant->elmt < a){
		p1=p1->suivant=nouveau;
	}
	
	nouveau->suivant = p1->suivant;
	p1->suivant = nouveau;
	
	return pliste;
}	
       
Chainon* insertDebut(int a, Chainon *p1){
         Chainon *nouveau=creationChainon(a);
         nouveau->suivant=p1;
         p1=nouveau;
         return p1;
}

Chainon* insertFin(int a, Chainon *pliste){
         Chainon *nouveau=creationChainon(a);
         if(pliste==NULL){
                  pliste=nouveau;
                  
         }
         else{
                  
                  Chainon *p1=pliste;
                  while(p1->suivant!=NULL){
                          p1=p1->suivant;
                  }          
                  p1->suivant=nouveau;
         }
         return pliste;
}         

void afficheListe(Chainon *pliste){ 
        Chainon *p1=pliste ;
        while(p1!=NULL){
                printf("%d \n", p1->elmt);
                p1=p1->suivant;
        }
}
                   

int main(){
        Chainon *pliste = NULL;
        pliste=insertTrie(5,pliste);                         
        pliste=insertTrie(9,pliste);   
        pliste=insertTrie(2,pliste);
        pliste=insertTrie(1, pliste);
        pliste=insertTrie(2, pliste);
        pliste=insertTrie(3, pliste);
        afficheListe(pliste);
        return 0;

}           


