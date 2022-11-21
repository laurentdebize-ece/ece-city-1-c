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
#define COTECASE 50
#define XDEPART COTECASE*4
#define YDEPART COTECASE*3
#define MONNAIEDEPART 5000
#define VITESSE COTECASE/5


enum {
    VIDE, ARBRE, ROUTE, TERRAINVAGUE, RUINE, CABANE, MAISON, IMMEUBLE, GRATTECIEL, CHATEAUDEAU, CENTRALE
};

enum {
    ACCEUIL, CHOIXDUMODE, JEU, PARAMETRES, NBDEMENU
};

enum {
    NOUVELLEPARTIE, CHARGER, QUITTER, NBDEBOUTONACCEUIL
};

enum {
    COMMUNISTE, CAPITALISTE, NBDEBOUTONCHOIXDUMODE
};

enum {
    CONSTRUIREROUTE, CONSTRUIREBATIMENT, CONSTRUIRECHATEAUDEAU, CONSTRUIRECENTRALE, NBDEBOUTONJEU
};

enum {
    NBDEBOUTONPARAMETRES
};

enum {
    BITMAPACCEUIL, BITMAPCHOIXDUMODE, BITMAPJEU, NBDEBITMAP
};

enum {
    HAUT, BAS, GAUCHE, DROITE, NBT
};


typedef struct {
    int x, y;
} Coord;

typedef struct {
    int longueur;
    int hauteur;
    int Dpi;
    ALLEGRO_DISPLAY *window;
} Display;

typedef struct {
    int type;
    int num;
    bool elec;
    bool eau;
    Coord coord;
} Sol;

typedef struct {
    int monnaie;
    int habitant;
    int capaciteElec;
    int capaciteEau;
} Joueur;


typedef struct {
    Coord *position;
    int capacite;
} ChateauDeau;

typedef struct {
    Coord *position;
    int capacite;
} Centrale;

typedef struct {
    Coord *position;
    int etat;
    int nbHabitant;
    int compteur;
} Batiment;

typedef struct {
    int ancienne;
    int actuelle;
    int boutonDetecteActuel;
    int boutonDetecteAncien;
    int modeDeJeu;
    int batimenAConstruire;
    Coord coordCaseDetecte;
} Phase;

typedef struct {
    ALLEGRO_BITMAP *image;
    int hauteur;
    int longueur;
    Coord coord;
} Image;

typedef struct {
    Coord coord;
    int longueur;
    int hauteur;
    char *nom;
    bool clignote;
} Case;

typedef struct {
    ALLEGRO_FONT *simsCityPolicePetite;
    ALLEGRO_FONT *simsCityPoliceMoyen;
    ALLEGRO_FONT *simsCityPoliceGrand;
    ALLEGRO_COLOR couleurDuTexte;
} Ecrire;

typedef struct {
    bool end;
    bool changementAffichage;
    Ecrire ecrire;
    Phase phaseDeJeu;
    Display display;
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_TIMER *timer;
    Sol **matricePlateau;
    Joueur *joueur;
    Batiment *tabBatiments;
    Centrale *tabCentrales;
    ChateauDeau *tabChateauEaux;
    Image *tabImages;
    Case **tabBoutons;
    bool *tabTouches;
} EceCity;

#endif //ECE_CITY_1_C_MAIN_H