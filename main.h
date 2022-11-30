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

#define DPI 1
#define NBLIGNE 35
#define NBCOLONNE 45
#define COTECASE 50
#define XDEPART COTECASE*5
#define YDEPART COTECASE*5
#define MONNAIEDEPART 500000
#define VITESSE COTECASE/5
#define NBBATMAX 165
#define NBCENTRALEMAX 56
#define NBCHATEAUDEAUMAX 56
#define CYCLE 3
#define FPS 60
#define TAXE 10


enum {
    VIDE, ARBRE, ROUTE, RUINE, TERRAINVAGUE, CABANE, MAISON, IMMEUBLE, GRATTECIEL, CHATEAUDEAU, CENTRALE
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
    OUTIL,
    BOUTONPOUB,
    NBDEBOUTONJEU
};

enum {
    NBDEBOUTONPARAMETRES
};

enum {
    BITMAPACCEUIL,
    BITMAPCHOIXDUMODE,
    BITMAPHERBE,
    BITMAPCOMPTEUR,
    BITMAPMONNAIE,
    BITMAPOUTIL,
    BITMAPHAB,
    BITMAPEAU,
    BITMAPELEC,
    BitmapROUTEdroite,
    BitmapROUTEcroisement4,
    BitmapROUTEcroisement3,
    BitmapROUTEvirageD,
    BitmapROUTEvirageG,
    BitmapCentrale,
    BitmapChateauDeau,
    BITMAPCONSTROUTE,
    BITMAPCONSTMAISON,
    BITMAPCONSTCENTRALE,
    BITMAPCONSTCHATEAUDEAU,
    BITMAPRUINE,
    BITMAPTERRAINVAGUE,
    BITMAPMAISON,
    BITMAPCABANE,
    BITMAPARBRE,
    BITMAPIMMEUBLE,
    BITMAPGRATTECIEL,
    BITMAPPOUB,
    NBDEBITMAP
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
    bool firstMaison;
    bool construction;
    bool verif;
    Coord coord;
    Coord pred;
} Sol;

typedef struct {
    float monnaie;
    float habitant;
    int capaciteElec;
    int utilisationElec;
    int capaciteEau;
    int utilisationEau;
    int compteurTemps;
    int temps;
} Joueur;


typedef struct {
    Coord position;
    int capacite;
    int utile;
    int nbBatimentAlimente;
} ChateauDeau;

typedef struct {
    Coord position;
    int capacite;
    int utile;
    int nbBatimentAlimente;
} Centrale;

typedef struct {
    Coord position;
    int type;
    int nbHabitant;
    int compteur;
    int dEau;
    int dElec;
    Coord elecDep;
    Coord eauDep;
    bool elec;
    bool utilisationEau;
    bool high;
} Batiment;

typedef struct {
    int ancienne;
    int actuelle;
    int boutonDetecteActuel;
    int boutonDetecteAncien;
    int modeDeJeu;
    int batimenAConstruire;
    char *nomBatimenAConstruire;
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
    bool etatParticulier;
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