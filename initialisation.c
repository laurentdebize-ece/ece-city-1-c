#include "initialisation.h"
#include "main.h"

void initialisationAll(EceCity *eceCity) {
    get_desktop_resolution(0, eceCity);
    initialisationEceCity(eceCity);
    initAllegro(eceCity);
    initJoueur(eceCity);
    initMusique(eceCity);
    initBitmaps(eceCity);
    initTabBoutons(eceCity);
    initPolice(eceCity);
    initPlateau(eceCity);
    initTabTouches(eceCity);
}

void initTabTouches(EceCity *eceCity) {
    for (int i = 0; i < NBT; ++i) {
        eceCity->tabTouches[i] = false;
    }
}

void initPlateau(EceCity *eceCity) {
    int cpt = 0;
    for (int i = 0; i < NBLIGNE; ++i) {
        for (int j = 0; j < NBCOLONNE; ++j) {
            eceCity->matricePlateau[i][j].coord.x = XDEPART + j * COTECASE;
            eceCity->matricePlateau[i][j].coord.y = YDEPART + i * COTECASE;
            eceCity->matricePlateau[i][j].num = cpt;
            eceCity->matricePlateau[i][j].firstMaison = false;
            cpt++;
        }
    }
    FILE *ifs = fopen("../FichiersTxt/matricePlateau.txt", "r");
    for (int i = 0; i < NBLIGNE; ++i) {
        for (int j = 0; j < NBCOLONNE; ++j) {
            fscanf(ifs, "%d", &eceCity->matricePlateau[i][j].type);
            if (eceCity->matricePlateau[i][j].type != 0) {
                eceCity->matricePlateau[i][j].construction = true;
            } else {
                eceCity->matricePlateau[i][j].construction = false;
            }
        }
    }
    fclose(ifs);
}

void initMusique(EceCity *eceCity) {
    eceCity->sample = al_load_sample("../Sons/song.wav");
    eceCity->song = al_create_sample_instance(eceCity->sample);
    al_set_sample_instance_playmode(eceCity->song, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(eceCity->song, al_get_default_mixer());
    al_play_sample_instance(eceCity->song);
}

void initPolice(EceCity *eceCity) {
    eceCity->ecrire.simsCityPolicePetite = al_load_font("../Fonts/Police.TTF", 25, 0);
    assert(eceCity->ecrire.simsCityPolicePetite);
    eceCity->ecrire.simsCityPoliceMoyen = al_load_font("../Fonts/Police.TTF", 60, 0);
    assert(eceCity->ecrire.simsCityPoliceMoyen);
    eceCity->ecrire.simsCityPoliceGrand = al_load_font("../Fonts/Police.TTF", 200, 0);
    assert(eceCity->ecrire.simsCityPoliceGrand);
    eceCity->ecrire.couleurDuTexte = al_map_rgb(255, 255, 255);
}

void initTabBoutons(EceCity *eceCity) {
    eceCity->tabBoutons[ACCEUIL][NOUVELLEPARTIE].coord.x = 300;
    eceCity->tabBoutons[ACCEUIL][NOUVELLEPARTIE].coord.y = eceCity->display.hauteur / 2;
    eceCity->tabBoutons[ACCEUIL][NOUVELLEPARTIE].nom = "Nouvelle Partie";
    eceCity->tabBoutons[ACCEUIL][NOUVELLEPARTIE].longueur = 500;
    eceCity->tabBoutons[ACCEUIL][NOUVELLEPARTIE].hauteur = 150;
    eceCity->tabBoutons[ACCEUIL][NOUVELLEPARTIE].clignote = true;
    eceCity->tabBoutons[ACCEUIL][NOUVELLEPARTIE].cliquable = true;
    eceCity->tabBoutons[ACCEUIL][NOUVELLEPARTIE].etatParticulier = false;

    eceCity->tabBoutons[ACCEUIL][CHARGER].coord.x = 1100;
    eceCity->tabBoutons[ACCEUIL][CHARGER].coord.y = eceCity->display.hauteur / 2;
    eceCity->tabBoutons[ACCEUIL][CHARGER].nom = "Charger";
    eceCity->tabBoutons[ACCEUIL][CHARGER].longueur = 500;
    eceCity->tabBoutons[ACCEUIL][CHARGER].hauteur = 150;
    eceCity->tabBoutons[ACCEUIL][CHARGER].clignote = true;
    eceCity->tabBoutons[ACCEUIL][CHARGER].cliquable = false;
    eceCity->tabBoutons[ACCEUIL][CHARGER].etatParticulier = false;

    eceCity->tabBoutons[ACCEUIL][QUITTER].coord.x = 710;
    eceCity->tabBoutons[ACCEUIL][QUITTER].coord.y = 810;
    eceCity->tabBoutons[ACCEUIL][QUITTER].longueur = 500;
    eceCity->tabBoutons[ACCEUIL][QUITTER].hauteur = 150;
    eceCity->tabBoutons[ACCEUIL][QUITTER].nom = "Quitter";
    eceCity->tabBoutons[ACCEUIL][QUITTER].clignote = true;
    eceCity->tabBoutons[ACCEUIL][QUITTER].cliquable = true;
    eceCity->tabBoutons[ACCEUIL][QUITTER].etatParticulier = false;

    eceCity->tabBoutons[CHOIXDUMODE][COMMUNISTE].coord.x = 300;
    eceCity->tabBoutons[CHOIXDUMODE][COMMUNISTE].coord.y = eceCity->display.hauteur / 2;
    eceCity->tabBoutons[CHOIXDUMODE][COMMUNISTE].nom = "Communiste";
    eceCity->tabBoutons[CHOIXDUMODE][COMMUNISTE].longueur = 500;
    eceCity->tabBoutons[CHOIXDUMODE][COMMUNISTE].hauteur = 150;
    eceCity->tabBoutons[CHOIXDUMODE][COMMUNISTE].clignote = true;
    eceCity->tabBoutons[CHOIXDUMODE][COMMUNISTE].cliquable = true;
    eceCity->tabBoutons[CHOIXDUMODE][COMMUNISTE].etatParticulier = false;

    eceCity->tabBoutons[CHOIXDUMODE][CAPITALISTE].coord.x = 1100;
    eceCity->tabBoutons[CHOIXDUMODE][CAPITALISTE].coord.y = eceCity->display.hauteur / 2;
    eceCity->tabBoutons[CHOIXDUMODE][CAPITALISTE].nom = "Capitaliste";
    eceCity->tabBoutons[CHOIXDUMODE][CAPITALISTE].longueur = 500;
    eceCity->tabBoutons[CHOIXDUMODE][CAPITALISTE].hauteur = 150;
    eceCity->tabBoutons[CHOIXDUMODE][CAPITALISTE].clignote = true;
    eceCity->tabBoutons[CHOIXDUMODE][CAPITALISTE].cliquable = true;
    eceCity->tabBoutons[CHOIXDUMODE][CAPITALISTE].etatParticulier = false;

    eceCity->tabBoutons[JEU][BARREDOUTILS].coord.x = 560;
    eceCity->tabBoutons[JEU][BARREDOUTILS].coord.y = eceCity->display.hauteur * 8 / 9 - 25;
    eceCity->tabBoutons[JEU][BARREDOUTILS].nom = NULL;
    eceCity->tabBoutons[JEU][BARREDOUTILS].longueur = 900;
    eceCity->tabBoutons[JEU][BARREDOUTILS].hauteur = eceCity->display.hauteur;
    eceCity->tabBoutons[JEU][BARREDOUTILS].clignote = false;
    eceCity->tabBoutons[JEU][BARREDOUTILS].cliquable = false;
    eceCity->tabBoutons[JEU][BARREDOUTILS].etatParticulier = true;

    eceCity->tabBoutons[JEU][BARREDINFOS].coord.y = 100;
    eceCity->tabBoutons[JEU][BARREDINFOS].coord.x = eceCity->display.longueur * 8 / 9 - 25;
    eceCity->tabBoutons[JEU][BARREDINFOS].nom = NULL;
    eceCity->tabBoutons[JEU][BARREDINFOS].longueur = eceCity->display.longueur;
    eceCity->tabBoutons[JEU][BARREDINFOS].hauteur = eceCity->display.hauteur - 400;
    eceCity->tabBoutons[JEU][BARREDINFOS].clignote = false;
    eceCity->tabBoutons[JEU][BARREDINFOS].cliquable = false;
    eceCity->tabBoutons[JEU][BARREDINFOS].etatParticulier = false;

    eceCity->tabBoutons[JEU][CONSTRUIREROUTE].coord.x = 760;
    eceCity->tabBoutons[JEU][CONSTRUIREROUTE].coord.y = eceCity->display.hauteur * 8 / 9;
    eceCity->tabBoutons[JEU][CONSTRUIREROUTE].nom = NULL;
    eceCity->tabBoutons[JEU][CONSTRUIREROUTE].longueur = 80;
    eceCity->tabBoutons[JEU][CONSTRUIREROUTE].hauteur = 80;
    eceCity->tabBoutons[JEU][CONSTRUIREROUTE].clignote = true;
    eceCity->tabBoutons[JEU][CONSTRUIREROUTE].cliquable = true;
    eceCity->tabBoutons[JEU][CONSTRUIREROUTE].etatParticulier = true;

    eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].coord.x = 960;
    eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].coord.y = eceCity->display.hauteur * 8 / 9;
    eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].nom = NULL;
    eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].longueur = 80;
    eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].hauteur = 80;
    eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].clignote = true;
    eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].cliquable = true;
    eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].etatParticulier = true;

    eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].coord.x = 1160;
    eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].coord.y = eceCity->display.hauteur * 8 / 9;
    eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].nom = NULL;
    eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].longueur = 80;
    eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].hauteur = 80;
    eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].clignote = true;
    eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].cliquable = true;
    eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].etatParticulier = true;

    eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].coord.x = 1360;
    eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].coord.y = eceCity->display.hauteur * 8 / 9;
    eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].nom = NULL;
    eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].longueur = 80;
    eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].hauteur = 80;
    eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].clignote = true;
    eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].cliquable = true;
    eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].etatParticulier = true;

    eceCity->tabBoutons[JEU][OUTIL].coord.x = 600;
    eceCity->tabBoutons[JEU][OUTIL].coord.y = eceCity->display.hauteur * 8 / 9;
    eceCity->tabBoutons[JEU][OUTIL].nom = NULL;
    eceCity->tabBoutons[JEU][OUTIL].longueur = 80;
    eceCity->tabBoutons[JEU][OUTIL].hauteur = 80;
    eceCity->tabBoutons[JEU][OUTIL].clignote = false;
    eceCity->tabBoutons[JEU][OUTIL].cliquable = true;
    eceCity->tabBoutons[JEU][OUTIL].etatParticulier = false;
}

void initBitmaps(EceCity *eceCity) {
    eceCity->tabImages[BITMAPACCEUIL].image = al_load_bitmap("../Images/bitmapAcceuil.jpg");
    eceCity->tabImages[BITMAPACCEUIL].longueur = 1920;
    eceCity->tabImages[BITMAPACCEUIL].hauteur = 1080;
    eceCity->tabImages[BITMAPACCEUIL].coord.x = 0;
    eceCity->tabImages[BITMAPACCEUIL].coord.y = 200;

    eceCity->tabImages[BITMAPCHOIXDUMODE].image = al_load_bitmap("../Images/bitmapChoixModeDeJeu.png");
    eceCity->tabImages[BITMAPCHOIXDUMODE].longueur = 1920;
    eceCity->tabImages[BITMAPCHOIXDUMODE].hauteur = 1080;
    eceCity->tabImages[BITMAPCHOIXDUMODE].coord.x = 0;
    eceCity->tabImages[BITMAPCHOIXDUMODE].coord.y = 0;

    eceCity->tabImages[BITMAPHERBE].image = al_load_bitmap("../Images/allDecor.png");
    eceCity->tabImages[BITMAPHERBE].longueur = 41;
    eceCity->tabImages[BITMAPHERBE].hauteur = 41;
    eceCity->tabImages[BITMAPHERBE].coord.x = 653;
    eceCity->tabImages[BITMAPHERBE].coord.y = 436;

    eceCity->tabImages[BITMAPRUINE].image = al_load_bitmap("../Images/ruine.png");
    eceCity->tabImages[BITMAPRUINE].longueur = 82;
    eceCity->tabImages[BITMAPRUINE].hauteur = 97;
    eceCity->tabImages[BITMAPRUINE].coord.x = 0;
    eceCity->tabImages[BITMAPRUINE].coord.y = 0;

    eceCity->tabImages[BitmapROUTEdroite].image= al_load_bitmap("../Images/roadsTile.png");
    eceCity->tabImages[BitmapROUTEdroite].longueur = 150;
    eceCity->tabImages[BitmapROUTEdroite].hauteur = 150;
    eceCity->tabImages[BitmapROUTEdroite].coord.x = 0;
    eceCity->tabImages[BitmapROUTEdroite].coord.y = 0;

    eceCity->tabImages[BitmapROUTEcroisement3].image= al_load_bitmap("../Images/routeFois3.png");
    eceCity->tabImages[BitmapROUTEcroisement3].longueur = 80;
    eceCity->tabImages[BitmapROUTEcroisement3].hauteur = 83;
    eceCity->tabImages[BitmapROUTEcroisement3].coord.x = 0;
    eceCity->tabImages[BitmapROUTEcroisement3].coord.y = 0;

    eceCity->tabImages[BitmapROUTEcroisement4].image= al_load_bitmap("../Images/routeFois4.png");
    eceCity->tabImages[BitmapROUTEcroisement4].longueur = 72;
    eceCity->tabImages[BitmapROUTEcroisement4].hauteur = 93;
    eceCity->tabImages[BitmapROUTEcroisement4].coord.x = 0;
    eceCity->tabImages[BitmapROUTEcroisement4].coord.y = 0;

    eceCity->tabImages[BitmapROUTEvirageD].image= al_load_bitmap("../Images/routeVirageDroit.png");
    eceCity->tabImages[BitmapROUTEvirageD].longueur = 70;
    eceCity->tabImages[BitmapROUTEvirageD].hauteur = 94;
    eceCity->tabImages[BitmapROUTEvirageD].coord.x = 0;
    eceCity->tabImages[BitmapROUTEvirageD].coord.y = 0;

    eceCity->tabImages[BitmapROUTEvirageG].image= al_load_bitmap("../Images/routeVirageGauche.png");
    eceCity->tabImages[BitmapROUTEvirageG].longueur = 64;
    eceCity->tabImages[BitmapROUTEvirageG].hauteur = 95;
    eceCity->tabImages[BitmapROUTEvirageG].coord.x = 0;
    eceCity->tabImages[BitmapROUTEvirageG].coord.y = 0;

    eceCity->tabImages[BITMAPCABANE].image = al_load_bitmap("../Images/cabane 0.png");
    eceCity->tabImages[BITMAPCABANE].longueur = 81;
    eceCity->tabImages[BITMAPCABANE].hauteur = 90;
    eceCity->tabImages[BITMAPCABANE].coord.x = 0;
    eceCity->tabImages[BITMAPCABANE].coord.y = 0;

    eceCity->tabImages[BITMAPARBRE].image = al_load_bitmap("../Images/arbre0.png");
    eceCity->tabImages[BITMAPARBRE].longueur = 80;
    eceCity->tabImages[BITMAPARBRE].hauteur = 80;
    eceCity->tabImages[BITMAPARBRE].coord.x = 8;
    eceCity->tabImages[BITMAPARBRE].coord.y = 1;

    eceCity->tabImages[BITMAPMAISON].image= al_load_bitmap("../Images/Maison0.png");
    eceCity->tabImages[BITMAPMAISON].longueur = 80;
    eceCity->tabImages[BITMAPMAISON].hauteur = 106;
    eceCity->tabImages[BITMAPMAISON].coord.x = 0;
    eceCity->tabImages[BITMAPMAISON].coord.y = 0;

    eceCity->tabImages[BITMAPIMMEUBLE].image = al_load_bitmap("../Images/immeuble0.png");
    eceCity->tabImages[BITMAPIMMEUBLE].longueur = 94;
    eceCity->tabImages[BITMAPIMMEUBLE].hauteur = 118;
    eceCity->tabImages[BITMAPIMMEUBLE].coord.x = 0;
    eceCity->tabImages[BITMAPIMMEUBLE].coord.y = 0;

    eceCity->tabImages[BITMAPGRATTECIEL].image = al_load_bitmap("../Images/GratteCiel0.png");
    eceCity->tabImages[BITMAPGRATTECIEL].longueur = 118;
    eceCity->tabImages[BITMAPGRATTECIEL].hauteur = 217;
    eceCity->tabImages[BITMAPGRATTECIEL].coord.x = 0;
    eceCity->tabImages[BITMAPGRATTECIEL].coord.y = 0;

    eceCity->tabImages[BitmapChateauDeau].image= al_load_bitmap("../Images/chateau d'eau.png");
    eceCity->tabImages[BitmapChateauDeau].longueur = 309;
    eceCity->tabImages[BitmapChateauDeau].hauteur = 323;
    eceCity->tabImages[BitmapChateauDeau].coord.x = 0;
    eceCity->tabImages[BitmapChateauDeau].coord.y = 0;

    eceCity->tabImages[BitmapCentrale].image= al_load_bitmap("../Images/eoliennes.png");
    eceCity->tabImages[BitmapCentrale].longueur = 338;
    eceCity->tabImages[BitmapCentrale].hauteur = 279;
    eceCity->tabImages[BitmapCentrale].coord.x = 0;
    eceCity->tabImages[BitmapCentrale].coord.y = 0;

    eceCity->tabImages[BITMAPTERRAINVAGUE].image= al_load_bitmap("../Images/terrainVague.png");
    eceCity->tabImages[BITMAPTERRAINVAGUE].longueur = 47;
    eceCity->tabImages[BITMAPTERRAINVAGUE].hauteur = 46;
    eceCity->tabImages[BITMAPTERRAINVAGUE].coord.x = 0;
    eceCity->tabImages[BITMAPTERRAINVAGUE].coord.y = 0;

    eceCity->tabImages[BITMAPCOMPTEUR].image = al_load_bitmap("../Images/currency_time.png");
    eceCity->tabImages[BITMAPCOMPTEUR].longueur = 208;
    eceCity->tabImages[BITMAPCOMPTEUR].hauteur = 208;
    eceCity->tabImages[BITMAPCOMPTEUR].coord.x = 0;
    eceCity->tabImages[BITMAPCOMPTEUR].coord.y = 0;

    eceCity->tabImages[BITMAPMONNAIE].image = al_load_bitmap("../Images/simcash2.png");
    eceCity->tabImages[BITMAPMONNAIE].longueur = 312;
    eceCity->tabImages[BITMAPMONNAIE].hauteur = 312;
    eceCity->tabImages[BITMAPMONNAIE].coord.x = 0;
    eceCity->tabImages[BITMAPMONNAIE].coord.y = 0;

    eceCity->tabImages[BITMAPOUTIL].image = al_load_bitmap("../Images/main_settings.png");
    eceCity->tabImages[BITMAPOUTIL].longueur = 110;
    eceCity->tabImages[BITMAPOUTIL].hauteur = 100;
    eceCity->tabImages[BITMAPOUTIL].coord.x = 0;
    eceCity->tabImages[BITMAPOUTIL].coord.y = 0;

    eceCity->tabImages[BITMAPHAB].image = al_load_bitmap("../Images/currency_population.png");
    eceCity->tabImages[BITMAPHAB].longueur = 208;
    eceCity->tabImages[BITMAPHAB].hauteur = 208;
    eceCity->tabImages[BITMAPHAB].coord.x = 0;
    eceCity->tabImages[BITMAPHAB].coord.y = 0;

    eceCity->tabImages[BITMAPEAU].image = al_load_bitmap("../Images/services_02.png");
    eceCity->tabImages[BITMAPEAU].longueur = 208;
    eceCity->tabImages[BITMAPEAU].hauteur = 208;
    eceCity->tabImages[BITMAPEAU].coord.x = 0;
    eceCity->tabImages[BITMAPEAU].coord.y = 0;

    eceCity->tabImages[BITMAPELEC].image = al_load_bitmap("../Images/services_01.png");
    eceCity->tabImages[BITMAPELEC].longueur = 208;
    eceCity->tabImages[BITMAPELEC].hauteur = 208;
    eceCity->tabImages[BITMAPELEC].coord.x = 0;
    eceCity->tabImages[BITMAPELEC].coord.y = 0;

    eceCity->tabImages[BITMAPCONSTROUTE].image = al_load_bitmap("../Images/hud_roads.png");
    eceCity->tabImages[BITMAPCONSTROUTE].longueur = 208;
    eceCity->tabImages[BITMAPCONSTROUTE].hauteur = 208;
    eceCity->tabImages[BITMAPCONSTROUTE].coord.x = 0;
    eceCity->tabImages[BITMAPCONSTROUTE].coord.y = 0;

    eceCity->tabImages[BITMAPCONSTMAISON].image = al_load_bitmap("../Images/hud_residential.png");
    eceCity->tabImages[BITMAPCONSTMAISON].longueur = 212;
    eceCity->tabImages[BITMAPCONSTMAISON].hauteur = 212;
    eceCity->tabImages[BITMAPCONSTMAISON].coord.x = 0;
    eceCity->tabImages[BITMAPCONSTMAISON].coord.y = 0;

    eceCity->tabImages[BITMAPCONSTCENTRALE].image = al_load_bitmap("../Images/centrale.png");
    eceCity->tabImages[BITMAPCONSTCENTRALE].longueur = 512;
    eceCity->tabImages[BITMAPCONSTCENTRALE].hauteur = 512;
    eceCity->tabImages[BITMAPCONSTCENTRALE].coord.x = 0;
    eceCity->tabImages[BITMAPCONSTCENTRALE].coord.y = 0;

    eceCity->tabImages[BITMAPCONSTCHATEAUDEAU].image = al_load_bitmap("../Images/eau.png");
    eceCity->tabImages[BITMAPCONSTCHATEAUDEAU].longueur = 512;
    eceCity->tabImages[BITMAPCONSTCHATEAUDEAU].hauteur = 512;
    eceCity->tabImages[BITMAPCONSTCHATEAUDEAU].coord.x = 0;
    eceCity->tabImages[BITMAPCONSTCHATEAUDEAU].coord.y = 0;
}

EceCity *creationEceCity() {
    EceCity *NewEceCity = (EceCity *) malloc(sizeof(EceCity));

    NewEceCity->matricePlateau = (Sol **) malloc(NBLIGNE * sizeof(Sol *));
    for (int i = 0; i < NBLIGNE; ++i) {
        NewEceCity->matricePlateau[i] = (Sol *) malloc(NBCOLONNE * sizeof(Sol));
    }

    NewEceCity->joueur = (Joueur *) malloc(sizeof(Joueur));

    NewEceCity->tabBatiments = (Batiment *) malloc(NBBATMAX * sizeof(Batiment));

    NewEceCity->tabCentrales = (Centrale *) malloc(NBCENTRALEMAX * sizeof(Centrale));

    NewEceCity->tabChateauEaux = (ChateauDeau *) malloc(NBCHATEAUDEAUMAX * sizeof(ChateauDeau));

    NewEceCity->tabImages = (Image *) malloc(NBDEBITMAP * sizeof(Image));

    NewEceCity->tabBoutons = (Case **) malloc(NBDEMENU * sizeof(Case *));

    NewEceCity->tabBoutons[ACCEUIL] = (Case *) malloc(NBDEBOUTONACCEUIL * sizeof(Case));
    NewEceCity->tabBoutons[CHOIXDUMODE] = (Case *) malloc(NBDEBOUTONCHOIXDUMODE * sizeof(Case));
    NewEceCity->tabBoutons[JEU] = (Case *) malloc(NBDEBOUTONJEU * sizeof(Case));
    NewEceCity->tabBoutons[PARAMETRES] = (Case *) malloc(NBDEBOUTONPARAMETRES * sizeof(Case));

    NewEceCity->tabTouches = (bool *) malloc(NBT * sizeof(bool));

    return NewEceCity;
}

void initialisationEceCity(EceCity *eceCity) {
    eceCity->changementAffichage = true;
    eceCity->end = false;
    eceCity->phaseDeJeu.actuelle = ACCEUIL;
    eceCity->phaseDeJeu.ancienne = ACCEUIL;
    eceCity->phaseDeJeu.boutonDetecteActuel = -1;
    eceCity->phaseDeJeu.boutonDetecteAncien = -1;
    eceCity->phaseDeJeu.batimenAConstruire = -1;
    eceCity->phaseDeJeu.coordCaseDetecte.x = -1;
    eceCity->phaseDeJeu.coordCaseDetecte.y = -1;
}

void initJoueur(EceCity *eceCity) {
    eceCity->joueur->monnaie = MONNAIEDEPART;
    eceCity->joueur->habitant = 0;
    eceCity->joueur->capaciteEau = 0;
    eceCity->joueur->utilisationEau = 0;
    eceCity->joueur->capaciteElec = 0;
    eceCity->joueur->utilisationElec = 0;
    eceCity->joueur->compteurTemps = 0;
    eceCity->joueur->temps = 0;
    eceCity->compteur.batiments = 0;
    eceCity->compteur.centrales = 0;
    eceCity->compteur.chateauxDeau = 0;
}

void initBiblioAllegro() {
    al_init();
    assert(al_init_acodec_addon());
    assert(al_install_keyboard());
    assert(al_install_mouse());
    assert(al_init_primitives_addon());
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    assert(al_install_audio());
    assert(al_reserve_samples(1));


}

void initAllegro(EceCity *eceCity) {
    eceCity->timer = al_create_timer(1.0 / 60.0);
    al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    eceCity->display.window = al_create_display(eceCity->display.longueur, eceCity->display.hauteur);
    al_set_window_position(eceCity->display.window, 1, 1);
    eceCity->queue = al_create_event_queue();
    al_start_timer(eceCity->timer);
    al_register_event_source(eceCity->queue, al_get_mouse_event_source());
    al_register_event_source(eceCity->queue, al_get_display_event_source(eceCity->display.window));
    al_register_event_source(eceCity->queue, al_get_keyboard_event_source());
    al_register_event_source(eceCity->queue, al_get_timer_event_source(eceCity->timer));
}

void get_desktop_resolution(int adapter, EceCity *eceCity) {
    ALLEGRO_MONITOR_INFO info;
    al_get_monitor_info(adapter, &info);

    eceCity->display.longueur = info.x2 - info.x1;
    eceCity->display.hauteur = info.y2 - info.y1;
}

void destroyAll(EceCity *eceCity) {
    free(eceCity->tabChateauEaux);
    free(eceCity->tabCentrales);
    free(eceCity->tabBatiments);
    free(eceCity->tabBoutons);
    free(eceCity->matricePlateau);
    for (int i = 0; i < NBLIGNE; ++i) {
        free(eceCity->matricePlateau[i]);
    }
    free(eceCity->matricePlateau);
    al_destroy_font(eceCity->ecrire.simsCityPolicePetite);
    al_destroy_font(eceCity->ecrire.simsCityPoliceMoyen);
    al_destroy_font(eceCity->ecrire.simsCityPoliceGrand);
    al_destroy_timer(eceCity->timer);
    al_destroy_display(eceCity->display.window);
    al_destroy_event_queue(eceCity->queue);
    al_destroy_sample_instance(eceCity->song);
    al_destroy_sample(eceCity->sample);
    free(eceCity->joueur);
    for (int i = 0; i < NBDEBITMAP; ++i) {
        al_destroy_bitmap(eceCity->tabImages[i].image);
    }
    free(eceCity->tabImages);
    free(eceCity);
}