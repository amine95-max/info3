#include <stdio.h>
#include <stdlib.h>

typedef struct arbre{
	int elmt;
	struct arbre *fg;
	struct arbre *fd;
}Arbre;

typedef Arbre* pArbre;

typedef struct Chainon{
	pArbre a; 
	struct Chainon* suivant;
}Chainon;

typedef struct File{
	Chainon *debut;
	Chainon *fin;
	 
}File;	
	
	
	
int estVide(pArbre a);
int estFeuille(pArbre a);
int existeFilsGauche(pArbre a);
int existeFilsDroite(pArbre a);
int ajouterFilsGauche(pArbre a, int e);
int ajouterFilsDroit(pArbre a, int e);
void affichePrefixe (pArbre a);	
void afficheInfixe (pArbre a);
File enfiler (File f, pArbre e);
File defiler (File f, pArbre * pa);
void parcours_largeur(pArbre a);
