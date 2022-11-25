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
    al_init_acodec_addon();
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

    eceCity->tabBoutons[ACCEUIL][CHARGER].coord.x = 1100;
    eceCity->tabBoutons[ACCEUIL][CHARGER].coord.y = eceCity->display.hauteur / 2;
    eceCity->tabBoutons[ACCEUIL][CHARGER].nom = "Charger";
    eceCity->tabBoutons[ACCEUIL][CHARGER].longueur = 500;
    eceCity->tabBoutons[ACCEUIL][CHARGER].hauteur = 150;
    eceCity->tabBoutons[ACCEUIL][CHARGER].clignote = true;
    eceCity->tabBoutons[ACCEUIL][CHARGER].cliquable = true;

    eceCity->tabBoutons[ACCEUIL][QUITTER].coord.x = 710;
    eceCity->tabBoutons[ACCEUIL][QUITTER].coord.y = 810;
    eceCity->tabBoutons[ACCEUIL][QUITTER].longueur = 500;
    eceCity->tabBoutons[ACCEUIL][QUITTER].hauteur = 150;
    eceCity->tabBoutons[ACCEUIL][QUITTER].nom = "Quitter";
    eceCity->tabBoutons[ACCEUIL][QUITTER].clignote = true;
    eceCity->tabBoutons[ACCEUIL][QUITTER].cliquable = true;

    eceCity->tabBoutons[CHOIXDUMODE][COMMUNISTE].coord.x = 300;
    eceCity->tabBoutons[CHOIXDUMODE][COMMUNISTE].coord.y = eceCity->display.hauteur / 2;
    eceCity->tabBoutons[CHOIXDUMODE][COMMUNISTE].nom = "Communiste";
    eceCity->tabBoutons[CHOIXDUMODE][COMMUNISTE].longueur = 500;
    eceCity->tabBoutons[CHOIXDUMODE][COMMUNISTE].hauteur = 150;
    eceCity->tabBoutons[CHOIXDUMODE][COMMUNISTE].clignote = true;
    eceCity->tabBoutons[CHOIXDUMODE][COMMUNISTE].cliquable = true;

    eceCity->tabBoutons[CHOIXDUMODE][CAPITALISTE].coord.x = 1100;
    eceCity->tabBoutons[CHOIXDUMODE][CAPITALISTE].coord.y = eceCity->display.hauteur / 2;
    eceCity->tabBoutons[CHOIXDUMODE][CAPITALISTE].nom = "Capitaliste";
    eceCity->tabBoutons[CHOIXDUMODE][CAPITALISTE].longueur = 500;
    eceCity->tabBoutons[CHOIXDUMODE][CAPITALISTE].hauteur = 150;
    eceCity->tabBoutons[CHOIXDUMODE][CAPITALISTE].clignote = true;
    eceCity->tabBoutons[CHOIXDUMODE][CAPITALISTE].cliquable = true;

    eceCity->tabBoutons[JEU][BARREDOUTILS].coord.x = 560;
    eceCity->tabBoutons[JEU][BARREDOUTILS].coord.y = eceCity->display.hauteur * 8 / 9 - 25;
    eceCity->tabBoutons[JEU][BARREDOUTILS].nom = NULL;
    eceCity->tabBoutons[JEU][BARREDOUTILS].longueur = 900;
    eceCity->tabBoutons[JEU][BARREDOUTILS].hauteur = eceCity->display.hauteur;
    eceCity->tabBoutons[JEU][BARREDOUTILS].clignote = false;
    eceCity->tabBoutons[JEU][BARREDOUTILS].cliquable = false;

    eceCity->tabBoutons[JEU][BARREDINFOS].coord.y = 100;
    eceCity->tabBoutons[JEU][BARREDINFOS].coord.x = eceCity->display.longueur * 8 / 9 - 25;
    eceCity->tabBoutons[JEU][BARREDINFOS].nom = NULL;
    eceCity->tabBoutons[JEU][BARREDINFOS].longueur = eceCity->display.longueur;
    eceCity->tabBoutons[JEU][BARREDINFOS].hauteur = eceCity->display.hauteur - 400;
    eceCity->tabBoutons[JEU][BARREDINFOS].clignote = false;
    eceCity->tabBoutons[JEU][BARREDINFOS].cliquable = false;

    eceCity->tabBoutons[JEU][CONSTRUIREROUTE].coord.x = 760;
    eceCity->tabBoutons[JEU][CONSTRUIREROUTE].coord.y = eceCity->display.hauteur * 8 / 9;
    eceCity->tabBoutons[JEU][CONSTRUIREROUTE].nom = "Route";
    eceCity->tabBoutons[JEU][CONSTRUIREROUTE].longueur = 80;
    eceCity->tabBoutons[JEU][CONSTRUIREROUTE].hauteur = 80;
    eceCity->tabBoutons[JEU][CONSTRUIREROUTE].clignote = true;
    eceCity->tabBoutons[JEU][CONSTRUIREROUTE].cliquable = true;

    eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].coord.x = 960;
    eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].coord.y = eceCity->display.hauteur * 8 / 9;
    eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].nom = "Batiment";
    eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].longueur = 80;
    eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].hauteur = 80;
    eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].clignote = true;
    eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].cliquable = true;

    eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].coord.x = 1160;
    eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].coord.y = eceCity->display.hauteur * 8 / 9;
    eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].nom = "Centrale";
    eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].longueur = 80;
    eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].hauteur = 80;
    eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].clignote = true;
    eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].cliquable = true;

    eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].coord.x = 1360;
    eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].coord.y = eceCity->display.hauteur * 8 / 9;
    eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].nom = "Chateau d'eau";
    eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].longueur = 80;
    eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].hauteur = 80;
    eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].clignote = true;
    eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].cliquable = true;
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

    eceCity->tabImages[BITMAPHERBE].image = al_load_bitmap("../Images/grass.jpeg");
    eceCity->tabImages[BITMAPHERBE].longueur = 1500;
    eceCity->tabImages[BITMAPHERBE].hauteur = 1500;
    eceCity->tabImages[BITMAPHERBE].coord.x = 0;
    eceCity->tabImages[BITMAPHERBE].coord.y = 0;

    eceCity->tabImages[RUINE].image= al_load_bitmap("../Images/ruine.png");
    eceCity->tabImages[RUINE].longueur = 82;
    eceCity->tabImages[RUINE].hauteur = 97;
    eceCity->tabImages[RUINE].coord.x = 0;
    eceCity->tabImages[RUINE].coord.y = 0;

    eceCity->tabImages[CABANE].image= al_load_bitmap("../Images/cabane 0.png");
    eceCity->tabImages[CABANE].longueur = 81;
    eceCity->tabImages[CABANE].hauteur = 90;
    eceCity->tabImages[CABANE].coord.x = 0;
    eceCity->tabImages[CABANE].coord.y = 0;

    eceCity->tabImages[ARBRE].image= al_load_bitmap("../Images/arbre0.png");
    eceCity->tabImages[ARBRE].longueur = 94;
    eceCity->tabImages[ARBRE].hauteur = 80;
    eceCity->tabImages[ARBRE].coord.x = 0;
    eceCity->tabImages[ARBRE].coord.y = 0;

    eceCity->tabImages[IMMEUBLE].image= al_load_bitmap("../Images/immeuble0.png");
    eceCity->tabImages[IMMEUBLE].longueur = 94;
    eceCity->tabImages[IMMEUBLE].hauteur = 118;
    eceCity->tabImages[IMMEUBLE].coord.x = 0;
    eceCity->tabImages[IMMEUBLE].coord.y = 0;

    eceCity->tabImages[GRATTECIEL].image= al_load_bitmap("../Images/GratteCiel0.png");
    eceCity->tabImages[GRATTECIEL].longueur = 118;
    eceCity->tabImages[GRATTECIEL].hauteur = 217;
    eceCity->tabImages[GRATTECIEL].coord.x = 0;
    eceCity->tabImages[GRATTECIEL].coord.y = 0;


    eceCity->tabImages[BITMAPCOMPTEUR].image = al_load_bitmap("../Images/currency_time.png");
    eceCity->tabImages[BITMAPCOMPTEUR].longueur = 208;
    eceCity->tabImages[BITMAPCOMPTEUR].hauteur = 208;
    eceCity->tabImages[BITMAPCOMPTEUR].coord.x = 0;
    eceCity->tabImages[BITMAPCOMPTEUR].coord.y = 0;

    eceCity->tabImages[BITMAPMONNAIE].image = al_load_bitmap("../Images/simcash2.png");
    assert(eceCity->tabImages[BITMAPMONNAIE].image);
    eceCity->tabImages[BITMAPMONNAIE].longueur = 312;
    eceCity->tabImages[BITMAPMONNAIE].hauteur = 312;
    eceCity->tabImages[BITMAPMONNAIE].coord.x = 0;
    eceCity->tabImages[BITMAPMONNAIE].coord.y = 0;

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
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    eceCity->display.window = al_create_display(eceCity->display.longueur, eceCity->display.hauteur);
    al_set_window_position(eceCity->display.window, 0, 0);
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
    free(eceCity->joueur);
    free(eceCity->tabChateauEaux);
    free(eceCity->tabCentrales);
    free(eceCity->tabBatiments);
    for (int i = 0; i < NBDEMENU; ++i) {
        free(eceCity->tabBoutons[i]);
    }
    free(eceCity->tabBoutons);
    for (int i = 0; i < NBLIGNE; ++i) {
        free(eceCity->matricePlateau[i]);
    }
    free(eceCity->matricePlateau);
    al_destroy_font(eceCity->ecrire.simsCityPolicePetite);
    al_destroy_bitmap(eceCity->tabImages);
    al_destroy_font(eceCity->ecrire.simsCityPoliceMoyen);
    al_destroy_font(eceCity->ecrire.simsCityPoliceGrand);
    al_destroy_timer(eceCity->timer);
    al_destroy_display(eceCity->display.window);
    al_destroy_event_queue(eceCity->queue);
    al_destroy_sample_instance(eceCity->song);
    free(eceCity);
}