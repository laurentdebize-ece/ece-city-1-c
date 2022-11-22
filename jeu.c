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
            detectionSouris(eceCity);
            break;
        }

        case ALLEGRO_EVENT_TIMER: {
            if (eceCity->changementAffichage) {
                affichageAcceuil(eceCity);
                al_flip_display();
                eceCity->changementAffichage = false;
            }
            if (eceCity->phaseDeJeu.boutonDetecteActuel != -1) {
                faireClignoterBoutonMenu(eceCity, eceCity->ecrire.simsCityPoliceMoyen);
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
            detectionSouris(eceCity);
            break;
        }

        case ALLEGRO_EVENT_TIMER: {
            if (eceCity->changementAffichage) {
                affichageChoixDuMode(eceCity);
                al_flip_display();
                eceCity->changementAffichage = false;
            }
            if (eceCity->phaseDeJeu.boutonDetecteActuel != -1) {
                faireClignoterBoutonMenu(eceCity, eceCity->ecrire.simsCityPoliceMoyen);
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
                    ///tempo
                    eceCity->end = true;
                    break;
                }
                case ALLEGRO_KEY_S: {
                    eceCity->tabTouches[BAS] = true;
                    eceCity->changementAffichage = true;
                    break;
                }
                case ALLEGRO_KEY_Z: {
                    eceCity->tabTouches[HAUT] = true;
                    eceCity->changementAffichage = true;
                    break;
                }
                case ALLEGRO_KEY_Q: {
                    eceCity->tabTouches[GAUCHE] = true;
                    eceCity->changementAffichage = true;
                    break;
                }
                case ALLEGRO_KEY_D: {
                    eceCity->tabTouches[DROITE] = true;
                    eceCity->changementAffichage = true;
                    break;
                }
            }
            break;
        }
        case ALLEGRO_EVENT_KEY_UP: {
            switch (eceCity->event.keyboard.keycode) {
                case ALLEGRO_KEY_S: {
                    eceCity->tabTouches[BAS] = false;
                    eceCity->changementAffichage = true;
                    break;
                }
                case ALLEGRO_KEY_Z: {
                    eceCity->tabTouches[HAUT] = false;
                    eceCity->changementAffichage = true;
                    break;
                }
                case ALLEGRO_KEY_Q: {
                    eceCity->tabTouches[GAUCHE] = false;
                    eceCity->changementAffichage = true;
                    break;
                }
                case ALLEGRO_KEY_D: {
                    eceCity->tabTouches[DROITE] = false;
                    eceCity->changementAffichage = true;
                    break;
                }
            }
            break;
        }
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {
            boutonPresse(eceCity);
            if (eceCity->phaseDeJeu.batimenAConstruire != -1 && eceCity->phaseDeJeu.coordCaseDetecte.x != -1 &&
                eceCity->phaseDeJeu.coordCaseDetecte.y != -1) {
                construireBatiment(eceCity);
            }
            break;
        }
        case ALLEGRO_EVENT_MOUSE_AXES: {
            detectionSouris(eceCity);
            break;
        }

        case ALLEGRO_EVENT_TIMER: {
            eceCity->joueur->compteurTemps++;
            if(eceCity->joueur->compteurTemps==60){
                eceCity->joueur->temps++;
                eceCity->joueur->compteurTemps=0;
            }
            deplacerPlateau(eceCity);
            if (eceCity->changementAffichage || eceCity->phaseDeJeu.batimenAConstruire != -1) {
                affichageJeu(eceCity);
                al_flip_display();
                eceCity->changementAffichage = false;
            }
            if (eceCity->phaseDeJeu.boutonDetecteActuel != -1) {
                faireClignoterBoutonMenu(eceCity, eceCity->ecrire.simsCityPolicePetite);
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
            detectionSouris(eceCity);
            break;
        }

        case ALLEGRO_EVENT_TIMER: {
            if (eceCity->changementAffichage) {
                affichageParametres(eceCity);
                al_flip_display();
                eceCity->changementAffichage = false;
            }
            if (eceCity->phaseDeJeu.boutonDetecteActuel != -1) {
                faireClignoterBoutonMenu(eceCity, eceCity->ecrire.simsCityPoliceMoyen);
            }
        }
    }
}

void detectionSouris(EceCity *eceCity) {
    bool casParticulier = true;
    eceCity->phaseDeJeu.boutonDetecteActuel = -1;
    eceCity->phaseDeJeu.coordCaseDetecte.x = -1;
    eceCity->phaseDeJeu.coordCaseDetecte.y = -1;
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
    if (eceCity->event.mouse.x >= eceCity->matricePlateau[0][0].coord.x &&
        eceCity->event.mouse.x <= eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.x + COTECASE &&
        eceCity->event.mouse.y >= eceCity->matricePlateau[0][0].coord.y &&
        eceCity->event.mouse.y <=
        eceCity->display.hauteur - (eceCity->display.hauteur / 8 + 50)) {
        eceCity->phaseDeJeu.coordCaseDetecte.x = 0;
        eceCity->phaseDeJeu.coordCaseDetecte.y = 0;
        while (eceCity->event.mouse.x >
               eceCity->matricePlateau[0][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x + COTECASE) {
            eceCity->phaseDeJeu.coordCaseDetecte.x++;
        }
        while (eceCity->event.mouse.y >
               eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][0].coord.y + COTECASE &&
               casParticulier) {
            eceCity->phaseDeJeu.coordCaseDetecte.y++;
            if (eceCity->phaseDeJeu.coordCaseDetecte.y == NBLIGNE) {
                casParticulier = false;
                eceCity->phaseDeJeu.coordCaseDetecte.y = -1;
                eceCity->phaseDeJeu.coordCaseDetecte.x = -1;
            }
        }
        eceCity->changementAffichage = true;
    }
}


void construireBatiment(EceCity *eceCity) {
    if (verifSiEspaceBatiment(eceCity)) {
        int hauteur, longueur;
        switch (eceCity->phaseDeJeu.batimenAConstruire) {
            case ROUTE: {
                hauteur = longueur = 1;
                break;
            }
            case TERRAINVAGUE: {
                hauteur = longueur = 3;
                break;
            }
            case CHATEAUDEAU: {
                longueur = 6;
                hauteur = 4;
                break;
            }
            case CENTRALE: {
                longueur = 6;
                hauteur = 4;
                break;
            }
        }
        for (int i = eceCity->phaseDeJeu.coordCaseDetecte.y;
             i < eceCity->phaseDeJeu.coordCaseDetecte.y + hauteur; i++) {
            for (int j = eceCity->phaseDeJeu.coordCaseDetecte.x;
                 j < eceCity->phaseDeJeu.coordCaseDetecte.x + longueur; j++) {
                eceCity->matricePlateau[i][j].type = eceCity->phaseDeJeu.batimenAConstruire;
            }
        }
        eceCity->changementAffichage = true;
    }
}


bool verifSiEspaceBatiment(EceCity *eceCity) {
    bool verifCasesVide = false;
    int h, l;
    switch (eceCity->phaseDeJeu.batimenAConstruire) {
        case ROUTE: {
            h = l = 1;
            break;
        }
        case TERRAINVAGUE: {
            h = l = 3;
            break;
        }
        case CHATEAUDEAU: {
            l = 6;
            h = 4;
            break;
        }
        case CENTRALE: {
            l = 6;
            h = 4;
            break;
        }
    }
    if (eceCity->phaseDeJeu.coordCaseDetecte.x + l <= NBCOLONNE &&
        eceCity->phaseDeJeu.coordCaseDetecte.y + h <= NBLIGNE) {
        verifCasesVide = true;
    }
    for (int i = eceCity->phaseDeJeu.coordCaseDetecte.x; i < eceCity->phaseDeJeu.coordCaseDetecte.x + l; i++) {
        for (int j = eceCity->phaseDeJeu.coordCaseDetecte.y; j < eceCity->phaseDeJeu.coordCaseDetecte.y + h; j++) {
            if (eceCity->matricePlateau[j][i].type != VIDE &&
                eceCity->matricePlateau[j][i].type != ARBRE) {
                verifCasesVide = false;
            }
        }
    }
    return verifCasesVide;
}

void boutonPresse(EceCity *eceCity) {
    switch (eceCity->phaseDeJeu.actuelle) {
        case ACCEUIL: {
            switch (eceCity->phaseDeJeu.boutonDetecteActuel) {
                case NOUVELLEPARTIE: {
                    eceCity->phaseDeJeu.ancienne = eceCity->phaseDeJeu.actuelle;
                    eceCity->phaseDeJeu.actuelle = CHOIXDUMODE;
                    eceCity->changementAffichage = true;
                    break;
                }
                case CHARGER: {
                    eceCity->phaseDeJeu.ancienne = eceCity->phaseDeJeu.actuelle;
                    eceCity->phaseDeJeu.actuelle = JEU;
                    eceCity->changementAffichage = true;
                    break;
                }
                case QUITTER: {
                    eceCity->end = true;
                    break;
                }
            }
            break;
        }
        case CHOIXDUMODE: {
            switch (eceCity->phaseDeJeu.boutonDetecteActuel) {
                case COMMUNISTE: {
                    eceCity->phaseDeJeu.modeDeJeu = COMMUNISTE;
                    eceCity->phaseDeJeu.ancienne = eceCity->phaseDeJeu.actuelle;
                    eceCity->phaseDeJeu.actuelle = JEU;
                    eceCity->changementAffichage = true;
                    break;

                }
                case CAPITALISTE: {
                    eceCity->phaseDeJeu.modeDeJeu = CAPITALISTE;
                    eceCity->phaseDeJeu.ancienne = eceCity->phaseDeJeu.actuelle;
                    eceCity->phaseDeJeu.actuelle = JEU;
                    eceCity->changementAffichage = true;
                    break;

                }
            }
            break;
        }
        case JEU: {
            switch (eceCity->phaseDeJeu.boutonDetecteActuel) {
                case CONSTRUIREROUTE: {
                    if (eceCity->phaseDeJeu.batimenAConstruire == ROUTE) {
                        eceCity->phaseDeJeu.batimenAConstruire = -1;
                    } else {
                        eceCity->phaseDeJeu.batimenAConstruire = ROUTE;

                    }
                    eceCity->changementAffichage = true;
                    break;
                }
                case CONSTRUIREBATIMENT: {
                    if (eceCity->phaseDeJeu.batimenAConstruire == TERRAINVAGUE) {
                        eceCity->phaseDeJeu.batimenAConstruire = -1;
                    } else {
                        eceCity->phaseDeJeu.batimenAConstruire = TERRAINVAGUE;

                    }
                    eceCity->changementAffichage = true;
                    break;
                }
                case CONSTRUIRECHATEAUDEAU: {
                    if (eceCity->phaseDeJeu.batimenAConstruire == CHATEAUDEAU) {
                        eceCity->phaseDeJeu.batimenAConstruire = -1;
                    } else {
                        eceCity->phaseDeJeu.batimenAConstruire = CHATEAUDEAU;

                    }
                    eceCity->changementAffichage = true;
                    break;
                }
                case CONSTRUIRECENTRALE: {
                    if (eceCity->phaseDeJeu.batimenAConstruire == CENTRALE) {
                        eceCity->phaseDeJeu.batimenAConstruire = -1;
                    } else {
                        eceCity->phaseDeJeu.batimenAConstruire = CENTRALE;

                    }
                    eceCity->changementAffichage = true;
                    break;
                }
            }
            break;
        }
        case PARAMETRES: {

            break;
        }
    }
}