#include "fifo.h"

File fileVide() {
    File F;
    F = (File)malloc(sizeof(struct _file));
    if (F == NULL) printf("erreur allocation fileVide");
    F->longueur = 0;
    F->tete = F->queue = NULL;
    return(F);
}

int longueur(File F) {
    if (F == NULL)printf("file existe pas - longueur");
    return(F->longueur);
}

void enfiler(File F, Coord coord) {
    Cellule cellule;
    if (F == NULL) printf ("file existe pas - enfiler");

    cellule = (Cellule)malloc(sizeof(struct _cellule));
    if (cellule == NULL) printf("erreur allocation memoire - enfiler");
    cellule->suivant = NULL;
    cellule->coord = coord;
    if (longueur(F) == 0){
        F->tete = F->queue = cellule;
    }
    else {
        F->queue->suivant = cellule;
        F->queue = cellule;
    }
    ++(F->longueur);
}

Coord tete(File F) {
    if (F == NULL || longueur(F) == 0) printf(" File existe pas - tete");
    return(F->tete->coord);
}

void decapiter(File F) {
    Cellule cellule;

    if (F == NULL || longueur(F) == 0)printf("File existe pas - defiler");
    cellule = F->tete;
    if (longueur(F) == 1)
        F->tete = F->queue = NULL;
    else
        F->tete = F->tete->suivant;
    --(F->longueur);
    free(cellule);
}

Coord defiler(File F) {
    Cellule cellule;
    Coord element;
    if (F == NULL || longueur(F) == 0) printf("File existe pas - defilement");
    cellule = F->tete;
    element = cellule->coord;
    if (longueur(F) == 1){
        F->tete = F->queue = NULL;
    }
    else{
        F->tete = F->tete->suivant;
    }
    free(cellule);
    --(F->longueur);
    return(element);
}