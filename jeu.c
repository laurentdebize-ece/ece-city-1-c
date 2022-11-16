#include "jeu.h"
#include "affichage.h"

void bouclePrincipale(EceCity *eceCity) {
    while (!eceCity->end) {
        al_wait_for_event(eceCity->queue, &eceCity->event);
        switch (eceCity->phaseDeJeu.actuelle) {
            case ACCEUIL: {
                menuAcceuil(eceCity);
                break;
            }
            case CHOIXDUMODE: {
                menuChoixDuMode(eceCity);
            }
            case JEU: {
                menuJeu(eceCity);
                break;
            }
            case PARAMETRES: {
                menuParametres(eceCity);
                break;
            }
        }
    }
}

void menuAcceuil(EceCity *eceCity) {
    switch (eceCity->event.type) {
        case ALLEGRO_EVENT_KEY_DOWN: {
            switch (eceCity->event.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE: {
                    eceCity->end = true;
                    break;
                }
            }
            break;
        }
        case ALLEGRO_EVENT_KEY_UP: {

            break;
        }
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
            boutonPresse(eceCity);
            break;
        }
        case ALLEGRO_EVENT_MOUSE_AXES: {
            detectionSourisBouton(eceCity);
            break;
        }

        case ALLEGRO_EVENT_TIMER: {
            if (eceCity->changementAffichage) {
                affichageAcceuil(eceCity);
                al_flip_display();
                eceCity->changementAffichage = false;
            }
            if (eceCity->phaseDeJeu.boutonDetecteActuel != -1) {
                faireClignoterBouton(eceCity);
            }
            break;
        }
    }
}

void menuChoixDuMode(EceCity *eceCity) {
    switch (eceCity->event.type) {
        case ALLEGRO_EVENT_KEY_DOWN: {
            switch (eceCity->event.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE: {
                    eceCity->end = true;
                    break;
                }
            }
            break;
        }
        case ALLEGRO_EVENT_KEY_UP: {

            break;
        }
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
            boutonPresse(eceCity);
            break;
        }
        case ALLEGRO_EVENT_MOUSE_AXES: {
            detectionSourisBouton(eceCity);
            break;
        }

        case ALLEGRO_EVENT_TIMER: {
            if (eceCity->changementAffichage) {
                affichageChoixDuMode(eceCity);
                al_flip_display();
                eceCity->changementAffichage = false;
            }
            if (eceCity->phaseDeJeu.boutonDetecteActuel != -1) {
                faireClignoterBouton(eceCity);
            }
        }
    }
}

void menuRegles(EceCity *eceCity) {
    switch (eceCity->event.type) {
        case ALLEGRO_EVENT_KEY_DOWN: {
            switch (eceCity->event.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE: {
                    eceCity->phaseDeJeu.actuelle = eceCity->phaseDeJeu.ancienne;
                    eceCity->changementAffichage = true;
                    break;
                }
            }
            break;
        }
        case ALLEGRO_EVENT_KEY_UP: {

            break;
        }
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
            boutonPresse(eceCity);
            break;
        }
        case ALLEGRO_EVENT_MOUSE_AXES: {
            detectionSourisBouton(eceCity);
            break;
        }

        case ALLEGRO_EVENT_TIMER: {
            if (eceCity->changementAffichage) {
                affichageRegles(eceCity);
                al_flip_display();
                eceCity->changementAffichage = false;
            }
            if (eceCity->phaseDeJeu.boutonDetecteActuel != -1) {
                faireClignoterBouton(eceCity);
            }
        }
    }
}

void menuJeu(EceCity *eceCity) {
    switch (eceCity->event.type) {
        case ALLEGRO_EVENT_KEY_DOWN: {
            switch (eceCity->event.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE: {
                    eceCity->phaseDeJeu.ancienne = eceCity->phaseDeJeu.actuelle;
                    eceCity->phaseDeJeu.ancienne = PARAMETRES;
                    eceCity->changementAffichage = true;
                    break;
                }
            }
            break;
        }
        case ALLEGRO_EVENT_KEY_UP: {

            break;
        }
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
            boutonPresse(eceCity);
            break;
        }
        case ALLEGRO_EVENT_MOUSE_AXES: {
            detectionSourisBouton(eceCity);
            break;
        }

        case ALLEGRO_EVENT_TIMER: {
            if (eceCity->changementAffichage) {
                affichageJeu(eceCity);
                al_flip_display();
                eceCity->changementAffichage = false;
            }
            if (eceCity->phaseDeJeu.boutonDetecteActuel != -1) {
                faireClignoterBouton(eceCity);
            }
        }
    }
}

void menuParametres(EceCity *eceCity) {
    switch (eceCity->event.type) {
        case ALLEGRO_EVENT_KEY_DOWN: {
            switch (eceCity->event.keyboard.keycode) {
                case ALLEGRO_KEY_ESCAPE: {
                    eceCity->phaseDeJeu.actuelle = eceCity->phaseDeJeu.ancienne;
                    eceCity->phaseDeJeu.ancienne = PARAMETRES;
                    eceCity->changementAffichage = true;
                    break;
                }
            }
            break;
        }
        case ALLEGRO_EVENT_KEY_UP: {

            break;
        }
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
            boutonPresse(eceCity);
            break;
        }
        case ALLEGRO_EVENT_MOUSE_AXES: {
            detectionSourisBouton(eceCity);
            break;
        }

        case ALLEGRO_EVENT_TIMER: {
            if (eceCity->changementAffichage) {
                affichageParametres(eceCity);
                al_flip_display();
                eceCity->changementAffichage = false;
            }
            if (eceCity->phaseDeJeu.boutonDetecteActuel != -1) {
                faireClignoterBouton(eceCity);
            }
        }
    }
}

void detectionSourisBouton(EceCity *eceCity) {
    eceCity->phaseDeJeu.boutonDetecteActuel = -1;
    int nbBouton;
    switch (eceCity->phaseDeJeu.actuelle) {
        case ACCEUIL: {
            nbBouton = NBDEBOUTONACCEUIL;
            break;
        }
        case CHOIXDUMODE: {
            nbBouton = NBDEBOUTONCHOIXDUMODE;
            break;
        }
        case JEU: {
            nbBouton = NBDEBOUTONJEU;
            break;
        }
        case PARAMETRES: {
            nbBouton = NBDEBOUTONPARAMETRES;
            break;
        }
    }
    for (int i = 0; i < nbBouton; ++i) {
        if (eceCity->event.mouse.x >= eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.x &&
            eceCity->event.mouse.x <= eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.x +
                                      eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].longueur &&
            eceCity->event.mouse.y >= eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.y &&
            eceCity->event.mouse.y <= eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.y +
                                      eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].hauteur) {
            eceCity->phaseDeJeu.boutonDetecteActuel = i;
        }
        if (eceCity->phaseDeJeu.boutonDetecteActuel != eceCity->phaseDeJeu.boutonDetecteAncien) {
            eceCity->changementAffichage = true;
        }
        eceCity->phaseDeJeu.boutonDetecteAncien = eceCity->phaseDeJeu.boutonDetecteActuel;
    }
}


void construireBatiment(EceCity eceCity, Coord coord, int tailleLongueur, int tailleLargeur, int batiment) {
    if (verifSiEspaceBatiment(eceCity, coord, tailleLongueur, tailleLargeur)) {
        for (int i = 0; i < tailleLongueur; ++i) {
            for (int j = 0; j < tailleLargeur; ++j) {
                eceCity.matricePlateau[coord.x - 1 + i][coord.x - 1 + j].type = batiment;
            }
        }
    }
}


bool verifSiEspaceBatiment(EceCity eceCity, Coord coord, int tailleLongueur, int tailleLargueur) {
    bool verifCasesVide = true;
    for (int i = 0; i < tailleLongueur; i++) {
        for (int j = 0; j < tailleLargueur; j++) {
            if (eceCity.matricePlateau[coord.x - 1 + i][coord.x - 1 + j].type != VIDE &&
                eceCity.matricePlateau[coord.x - 1 + i][coord.x - 1 + j].type != ARBRE) {
                verifCasesVide = false;
            }
        }
    }
    return verifCasesVide;
}

void boutonPresse(EceCity* eceCity){
    switch (eceCity->phaseDeJeu.actuelle) {
        case ACCEUIL: {
            switch (eceCity->phaseDeJeu.boutonDetecteActuel) {
                case NOUVELLEPARTIE:{
                    eceCity->phaseDeJeu.ancienne = eceCity->phaseDeJeu.actuelle;
                    eceCity->phaseDeJeu.actuelle = CHOIXDUMODE;
                    eceCity->changementAffichage = true;
                    break;
                }
                case CHARGER:{
                    eceCity->phaseDeJeu.ancienne = eceCity->phaseDeJeu.actuelle;
                    eceCity->phaseDeJeu.actuelle = JEU;
                    eceCity->changementAffichage = true;
                    break;
                }
                case QUITTER:{
                    eceCity->end = true;
                    break;
                }
            }
            break;
        }
        case CHOIXDUMODE: {
            switch (eceCity->phaseDeJeu.boutonDetecteActuel) {
                case COMMUNISTE: {
                    eceCity->phaseDeJeu.ancienne = eceCity->phaseDeJeu.actuelle;
                    eceCity->phaseDeJeu.actuelle = JEU;
                    eceCity->changementAffichage = true;
                    break;

                }
                case CAPITALISTE: {
                    eceCity->phaseDeJeu.ancienne = eceCity->phaseDeJeu.actuelle;
                    eceCity->phaseDeJeu.actuelle = JEU;
                    eceCity->changementAffichage = true;
                    break;

                }
            }

            break;
        }

        case JEU: {

            break;
        }
        case PARAMETRES: {

            break;
        }
    }
}