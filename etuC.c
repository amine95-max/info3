#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAILLE 10 
typedef struct{
	char prenom[100];
	char *nom;
	int groupe;
	float note[TAILLE];
}Etudiant;	

typedef struct chainon{
	Etudiant e;
	struct chainon* suivant;
	
}chainon;


Etudiant constructeurEtudiant(){
	Etudiant a;
	char tmp[1000];
	printf("prenom?\n");
	scanf("%s",a.prenom);
	printf("nom?\n");
	scanf("%s", tmp);
	a.nom=malloc(sizeof(char)*(strlen(tmp)+1));
	if(a.nom==NULL){
		exit(1);
	}
	strcpy(a.nom, tmp);
	do{
	
	   	printf("groupe de %s %s?\n", a.prenom, a.nom);
	   	scanf("%d",&a.groupe);
	}while(a.groupe<0);
	for(int i=0; i<TAILLE; i++){
	   	a.note[i]=rand()%81/4.0;
	   	
	}
	return a;			
	   		
}

chainon *creationchainon(){
	Etudiant a=constructeurEtudiant();
	chainon *n=malloc(sizeof(chainon));
	if(n==NULL){
		exit(2);
	}
	n->e=a;
	n->suivant=NULL;
	return n;

}			


chainon *insertDebut(chainon *p1){
         chainon *nouveau=creationchainon();
         nouveau->suivant=p1;
         p1=nouveau;
         return p1;
}


void afficheListe(chainon *pliste){ 
    chainon *p1 = pliste;

    while(p1 != NULL){
        printf("Prenom : %s\n", p1->e.prenom);
        printf("Nom : %s\n", p1->e.nom);
        printf("Groupe : %d\n", p1->e.groupe);

        for(int i = 0; i < TAILLE; i++){
            printf("Note %d : %.2f\n", i + 1, p1->e.note[i]);
        }

        printf("\n");
        p1 = p1->suivant;
    }
}


int main(){
	chainon *lstEtudiant=NULL;
	srand(time(NULL));
	lstEtudiant=insertDebut(lstEtudiant);
        lstEtudiant=insertDebut(lstEtudiant);
        afficheListe(lstEtudiant);
	return 0;
	
}	
