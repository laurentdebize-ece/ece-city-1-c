#include "initialisation.h"

void initialisationAll(EceCity *eceCity) {
    get_desktop_resolution(0, eceCity);
    initialisationEceCity(eceCity);
    initAllegro(eceCity);
    initJoueur(eceCity);
    initBitmaps(eceCity);
    initTabBoutons(eceCity);
    initPolice(eceCity);
}

void initPolice(EceCity *eceCity) {
    eceCity->ecrire.simsCityPolicePetite = al_load_font("../Fonts/AGAALER.ttf", 25, 0);
    assert(eceCity->ecrire.simsCityPolicePetite);
    eceCity->ecrire.simsCityPoliceMoyen = al_load_font("../Fonts/AGAALER.ttf", 50, 0);
    assert(eceCity->ecrire.simsCityPoliceMoyen);
    eceCity->ecrire.simsCityPoliceGrand = al_load_font("../Fonts/AGAALER.ttf", 100, 0);
    assert(eceCity->ecrire.simsCityPoliceGrand);
    eceCity->ecrire.couleurDuTexte = al_map_rgb(255, 255, 255);
}

void initTabBoutons(EceCity *eceCity) {
    eceCity->tabBoutons[ACCEUIL][NOUVELLEPARTIE].coord.x = 30;
    eceCity->tabBoutons[ACCEUIL][NOUVELLEPARTIE].coord.y = 225;
    eceCity->tabBoutons[ACCEUIL][NOUVELLEPARTIE].longueur = 717 - 30;
    eceCity->tabBoutons[ACCEUIL][NOUVELLEPARTIE].hauteur = 614 - 225;
    eceCity->tabBoutons[ACCEUIL][NOUVELLEPARTIE].nom = "Nouvelle Partie";
}

void initBitmaps(EceCity *eceCity) {
    eceCity->tabImages[BITMAPACCEUIL].image = al_load_bitmap("../Images/BitmapAcceuil.png");
    eceCity->tabImages[BITMAPACCEUIL].longueur = 1920;
    eceCity->tabImages[BITMAPACCEUIL].hauteur = 1080;
    eceCity->tabImages[BITMAPACCEUIL].coord.x = 0;
    eceCity->tabImages[BITMAPACCEUIL].coord.y = 0;
}

EceCity *creationEceCity() {
    EceCity *NewEceCity = (EceCity *) malloc(sizeof(EceCity));

    NewEceCity->matricePlateau = (Sol **) malloc(NBLIGNE * sizeof(Sol *));
    for (int i = 0; i < NBLIGNE; ++i) {
        NewEceCity->matricePlateau[i] = (Sol *) malloc(NBCOLONNE * sizeof(Sol));
    }

    NewEceCity->joueur = (Joueur *) malloc(sizeof(Joueur));

    NewEceCity->tabBatiments = (Batiment *) malloc(sizeof(Batiment));

    NewEceCity->tabCentrales = (Centrale *) malloc(sizeof(Centrale));

    NewEceCity->tabChateauEaux = (ChateauDeau *) malloc(sizeof(ChateauDeau));

    NewEceCity->tabImages = (Image *) malloc(NBDEBITMAP * sizeof(Image));

    NewEceCity->tabBoutons = (Case **) malloc(NBDEMENU * sizeof(Case *));
    NewEceCity->tabBoutons[ACCEUIL] = (Case *) malloc(NBDEBOUTONACCEUIL * sizeof(Case));
    NewEceCity->tabBoutons[CHOIXDUMODE] = (Case *) malloc(NBDEBOUTONCHOIXDUMODE * sizeof(Case));
    NewEceCity->tabBoutons[REGLES] = (Case *) malloc(NBDEBOUTONREGLES * sizeof(Case));
    NewEceCity->tabBoutons[JEU] = (Case *) malloc(NBDEBOUTONJEU * sizeof(Case));
    NewEceCity->tabBoutons[PARAMETRES] = (Case *) malloc(NBDEBOUTONPARAMETRES * sizeof(Case));

    return NewEceCity;
}

void initialisationEceCity(EceCity *eceCity) {
    eceCity->changementAffichage = true;
    eceCity->end = false;
    eceCity->phaseDeJeu.actuelle = ACCEUIL;
}

void initJoueur(EceCity *eceCity) {
    eceCity->joueur->monnaie = MONNAIEDEPART;
    eceCity->joueur->habitant = HABITANTDEPART;
    eceCity->joueur->capaciteEau = 0;
    eceCity->joueur->capaciteElec = 0;
}

void initBiblioAllegro() {
    al_init();
    assert(al_install_keyboard());
    assert(al_install_mouse());
    assert(al_init_primitives_addon());
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_audio();
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
    al_destroy_font(eceCity->ecrire.simsCityPoliceMoyen);
    al_destroy_font(eceCity->ecrire.simsCityPoliceGrand);
    al_destroy_timer(eceCity->timer);
    al_destroy_display(eceCity->display.window);
    al_destroy_event_queue(eceCity->queue);
    free(eceCity);
}