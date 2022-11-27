#ifndef ECE_CITY_1_C_FIFO_H
#define ECE_CITY_1_C_FIFO_H

#include "main.h"

#define fileEstVide(F) ((F)->longueur == 0)

struct _cellule {
    Coord coord;
    struct _cellule *suivant;
};

typedef struct _cellule *Cellule;

struct _file {
    int longueur;
    Cellule tete;
    Cellule queue;
};

typedef struct _file *File;

File fileVide();

int longueur(File F);

void enfiler(File F, Coord coord) ;

Coord tete(File F);

void decapiter(File F);

Coord defiler(File F);

#endif //ECE_CITY_1_C_FIFO_H
