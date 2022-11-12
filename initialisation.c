#include "initialisation.h"

void initialisationAll(EceCity* eceCity){
    initAllegro(eceCity);
    initialisationEceCity(eceCity);
}

EceCity *creationEceCity() {
    EceCity * NewEceCity = (EceCity *) malloc(sizeof(EceCity));
    NewEceCity->matricePlateau = (Sol **) malloc(NBLIGNE * sizeof(Sol *));
    for (int i = 0; i < NBLIGNE; ++i) {
        NewEceCity->matricePlateau[i] = (Sol *) malloc(NBCOLONNE * sizeof(Sol));
    }
    return NewEceCity;
}

void initialisationEceCity(EceCity *eceCity) {
    eceCity->eceFlouz = FLOUZDEPART;
    eceCity->changementAffichage = false;
    eceCity->end = false;
    eceCity->phaseDeJeu = ACCEUIL;
    for (int i = 0; i < NBLIGNE; ++i) {
        for (int j = 0; j < NBCOLONNE; ++j) {
            eceCity->matricePlateau[i][j].type = 0;
            eceCity->matricePlateau[i][j].plateau.x = i;
            eceCity->matricePlateau[i][j].plateau.y = j;
        }
    }
}

void initAllegro(EceCity *eceCity) {
    al_init();
    assert(al_install_keyboard());
    assert(al_install_mouse());
    assert(al_init_primitives_addon());
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_audio();
    eceCity->timer = al_create_timer(1.0 / 60.0);
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    eceCity->display.window = al_create_display(eceCity->display.w, eceCity->display.h);
    al_set_window_position(eceCity->display.window, 0, 0);
    eceCity->queue = al_create_event_queue();
    al_start_timer(eceCity->timer);
    al_register_event_source(eceCity->queue, al_get_mouse_event_source());
    al_register_event_source(eceCity->queue, al_get_display_event_source(eceCity->display.window));
    al_register_event_source(eceCity->queue, al_get_keyboard_event_source());
    al_register_event_source(eceCity->queue, al_get_timer_event_source(eceCity->timer));

}
