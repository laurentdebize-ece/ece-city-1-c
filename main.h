#ifndef ECE_CITY_1_C_MAIN_H
#define ECE_CITY_1_C_MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>

#define NBLIGNE 35
#define NBCOLONNE 45
#define FLOUZDEPART 5000

enum {
    TERRAINVAGUE = 0, RUINE = 1, CABANE = 2, MAISON = 3, IMMEUBLE = 4, GRATTECIEL = 5
};

typedef struct {
    int x, y;
} Coord;

typedef struct {
    int type;
    Coord plateau;
} Sol;

typedef struct {
    int eceFlouz;
    Sol **matricePlateau;
} EceCity;

//Structure du joueur
typedef struct {
    int compteur;
    int monnaie;
    int habitant;
    int capaciteElec;
    int capaciteEau;
} Joueur;


typedef struct {
    Coord *position;
    int capacite;
} ChateauEau;

typedef struct {
    Coord *position;
    int capacite;
} Centrale;

typedef struct {
    int etat;
    int nbHabitant;
} Construction;


#endif //ECE_CITY_1_C_MAIN_H
