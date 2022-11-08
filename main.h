#ifndef ECE_CITY_1_C_MAIN_H
#define ECE_CITY_1_C_MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define NBLIGNE 35
#define NBCOLONNE 45
#define FLOUZDEPART 5000

typedef struct {
    int x,y;
}Coord;

typedef struct {
    int type;
    Coord plateau;
}Sol;

typedef struct {
    int eceFlouz;
    Sol** matricePlateau;
}EceCity;

//Structure du joueur
typedef struct {
    int compteur;
    int monnaie;
    int habitant;
    int capaciteElec;
    int capaciteEau;
}Joueur;


typedef struct {
    Coord* position;
    int capacite;
}ChateauEau;

typedef struct {
    Coord* position;
    int capacite;

}Centrale;

typedef struct {
    int etat ;// peut être faire des enums ici
    // par ex terrainvague=0; ruine=1; cabane=2; maison=3; immeuble=4; gratteciel=5

    int nbrhabitant;

}Construction;


#endif //ECE_CITY_1_C_MAIN_H
