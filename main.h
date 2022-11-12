#ifndef ECE_CITY_1_C_MAIN_H
#define ECE_CITY_1_C_MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#define NBLIGNE 35
#define NBCOLONNE 45
#define FLOUZDEPART 5000

enum {
    VIDE, ARBRE,
    TERRAINVAGUE, RUINE, CABANE, MAISON, IMMEUBLE, GRATTECIEL,
    ACCEUIL, REGLES, JEU, PARAMETRES
};


typedef struct {
    int x, y;
} Coord;

typedef struct {
    int w;
    int h;
    int Dpi;
    ALLEGRO_DISPLAY *window;
} Window;

typedef struct {
    int type;
    Coord plateau;
} Sol;

typedef struct {
    int eceFlouz;
    bool end;
    bool changementAffichage;
    int phaseDeJeu;
    Window display;
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_TIMER *timer;
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
