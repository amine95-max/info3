#include "exo2.h"



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
    return a==NULL ? 1 :0;
}

int estFeuille(pArbre a){
    return a->fg==NULL && a->fd==NULL ? 1 :0;
}

int existeFilsGauche(pArbre a){
    return a->fg!=NULL ? 1:0;
}

int existeFilsDroit(pArbre a){
    return a->fd!=NULL ? 1:0;
}

int ajouterFilsGauche(pArbre a, int e){
    if(!estVide(a)){
        if(!existeFilsGauche(a)){
            pArbre nouveau=creationArbre(e);
            a->fg=nouveau;
            return 1;
        }
    }
}

int ajouterFilsDroit(pArbre a, int e){
    if(!estVide(a)){
        if(!existeFilsDroit(a)){
            pArbre nouveau=creationArbre(e);
            a->fd=nouveau;
            return 1;
        }
    }
}

void affichePrefixe (pArbre a){
    if(a!=NULL){
        printf("%d  ", a->elmt);
        affichePrefixe(a->fg);
        affichePrefixe(a->fd);
    }
}

void afficheInfixe (pArbre a){
    if(a!=NULL){
        afficheInfixe(a->fg);
        printf(" %d  ",a->elmt);
        afficheInfixe(a->fd);    
    }    
}



Chainon * creationChainon(pArbre e){
	Chainon *nouveau= malloc(sizeof(Chainon));
	if(nouveau==NULL){
		exit(1);
	}	
	nouveau->a=e;
	nouveau->suivant=NULL;
	return nouveau;
}	

File enfiler (File f, pArbre e){
	Chainon *n=creationChainon(e);
	if(f.debut==NULL){
		f.debut=n;
		f.fin=n;
		return f;
	}
	
	f.fin->suivant=n;
	f.fin=n;
	return f;
	
}	


File defiler (File f, pArbre * pa){
	if(f.debut!=NULL){
		Chainon *tmp=f.debut;
		*pa =tmp->a;
		f.debut=f.debut->suivant;
		free(tmp);
		if(f.debut==NULL){
			f.fin=NULL;
		}	
	}
	return f;
}


void parcours_largeur(pArbre a){
	File f;
	f.debut=NULL;
	f.fin=NULL;
	f=enfiler(f,a);
	pArbre arbre_defile=NULL;
	printf("\n\n---parcoursLargeurs -----\n\n");
	while(f.debut!=NULL){
		f=defiler(f, &arbre_defile);
		printf("%d ", arbre_defile->elmt);	
		if(existeFilsGauche(arbre_defile)){
			f=enfiler(f,arbre_defile->fg);
			
		}
		if(existeFilsDroit(arbre_defile)){
			f=enfiler(f, arbre_defile->fd);
		}
		
		printf("\n\n");		
			
	
}	

}

int nmbFeuille(pArbre a){
	if(a==NULL){
		return 0;
	}
	if(estFeuille(a)){
		return 1;
	}
	else{
		return nmbFeuille(a->fg)+nmbFeuille(a->fd);
	}			
}


int main(){
    pArbre a=NULL;
    pArbre *pa=NULL;
     File pf;
     pf.debut=NULL;
     pf.fin=NULL;

    a=creationArbre(1);
    ajouterFilsGauche(a, 2);
    ajouterFilsDroit(a, 8);
    ajouterFilsGauche(a->fg, 3);
    ajouterFilsDroit(a->fg, 6);
    ajouterFilsGauche(a->fd, 9);
    ajouterFilsDroit(a->fd, 10);
    ajouterFilsGauche(a->fg->fg, 4);
    ajouterFilsDroit(a->fg->fg, 5);
    ajouterFilsDroit(a->fg->fd, 7);
    printf("\nparcours prefixe\n\n");
    affichePrefixe(a);
    printf("\n\nparcours infixe\n\n");
    afficheInfixe(a);
    printf("\n");
    parcours_largeur(a);
    printf("\n\n");
    
    printf("nombre feuille : %d\n",nmbFeuille(a));
    
  
    return 0;
}	
