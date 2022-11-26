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
#define NBBATMAX 165
#define NBCENTRALEMAX 56
#define NBCHATEAUDEAUMAX 56
#define CYCLE 15
#define FPS 60


enum {
    VIDE, ARBRE, ROUTE,  RUINE, TERRAINVAGUE, CABANE, MAISON, IMMEUBLE, GRATTECIEL, CHATEAUDEAU, CENTRALE ,
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
    BARREDOUTILS,
    BARREDINFOS,
    CONSTRUIREROUTE,
    CONSTRUIREBATIMENT,
    CONSTRUIRECHATEAUDEAU,
    CONSTRUIRECENTRALE,
    NBDEBOUTONJEU
};

enum {
    NBDEBOUTONPARAMETRES
};

enum {
    BITMAPACCEUIL, BITMAPCHOIXDUMODE, BITMAPJEU, BITMAPHERBE, BitmapROUTEdroite,BitmapROUTEcroisement3, BitmapROUTEcroisement4, BitmapROUTEvirageD, BitmapROUTEvirageG, BitmapArbre,
    BitmapRuine, BitmapTerrainVague, BitmapMaison, BitmapImmeuble, BitmapGratteciel, BitmapChateauDeau, BitmapCentrale, BitmapCabane, NBDEBITMAP
};

enum {
    HAUT, BAS, GAUCHE, DROITE, CLICK, NBT
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
    bool construction;
    bool elec;
    bool eau;
    Coord coord;
} Sol;

typedef struct {
    int monnaie;
    int habitant;
    int capaciteElec;
    int capaciteEau;
    int compteurTemps;
    int temps;
} Joueur;


typedef struct {
    Coord position;
    int capacite;
    int connexe;
} ChateauDeau;

typedef struct {
    Coord position;
    int capacite;
    int connexe;
} Centrale;

typedef struct {
    Coord position;
    int type;
    bool elec;
    bool eau;
    bool connexe;
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
    bool cliquable;
} Case;

typedef struct {
    ALLEGRO_FONT *simsCityPolicePetite;
    ALLEGRO_FONT *simsCityPoliceMoyen;
    ALLEGRO_FONT *simsCityPoliceGrand;
    ALLEGRO_COLOR couleurDuTexte;
} Ecrire;

typedef struct {
    int batiments;
    int chateauxDeau;
    int centrales;
} Compteur;

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
    Compteur compteur;
    Image *tabImages;
    Case **tabBoutons;
    bool *tabTouches;
    ALLEGRO_SAMPLE *sample;
    ALLEGRO_SAMPLE_INSTANCE *song;
} EceCity;

#endif //ECE_CITY_1_C_MAIN_H