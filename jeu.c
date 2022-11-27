#include "jeu.h"
#include "affichage.h"
#include "fifo.h"

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
                break;
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
                eceCity->changementAffichage = false;
                al_flip_display();
            }
            if (eceCity->phaseDeJeu.boutonDetecteActuel != -1) {
                faireClignoterBoutonMenu(eceCity, eceCity->ecrire.simsCityPoliceMoyen);
            }
            break;
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
                case ALLEGRO_KEY_R: {
                    eceCity->phaseDeJeu.batimenAConstruire = ROUTE;
                    eceCity->phaseDeJeu.nomBatimenAConstruire = "ROUTE";
                    eceCity->changementAffichage = true;
                    break;
                }
                case ALLEGRO_KEY_B: {
                    if (eceCity->phaseDeJeu.batimenAConstruire == TERRAINVAGUE) {
                        eceCity->phaseDeJeu.batimenAConstruire = -1;
                    }
                    eceCity->phaseDeJeu.batimenAConstruire = TERRAINVAGUE;
                    eceCity->phaseDeJeu.nomBatimenAConstruire = "BATIMENT";
                    eceCity->changementAffichage = true;
                    break;
                }
                case ALLEGRO_KEY_O: {
                    if (eceCity->phaseDeJeu.batimenAConstruire == CHATEAUDEAU) {
                        eceCity->phaseDeJeu.batimenAConstruire = -1;
                    }
                    eceCity->phaseDeJeu.batimenAConstruire = CHATEAUDEAU;
                    eceCity->phaseDeJeu.nomBatimenAConstruire = "CHATEAU D'EAU";
                    eceCity->changementAffichage = true;
                    break;
                }
                case ALLEGRO_KEY_E: {
                    if (eceCity->phaseDeJeu.batimenAConstruire == CENTRALE) {
                        eceCity->phaseDeJeu.batimenAConstruire = -1;
                    }
                    eceCity->phaseDeJeu.batimenAConstruire = CENTRALE;
                    eceCity->phaseDeJeu.nomBatimenAConstruire = "CENTRALE";
                    eceCity->changementAffichage = true;
                    break;
                }
                case ALLEGRO_KEY_V: {
                    parcourBFSCentrales(eceCity);
                    remonterParPredEtCompterDistance(eceCity);
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
                eceCity->tabTouches[CLICK] = true;
            }
            break;
        }
        case ALLEGRO_EVENT_MOUSE_BUTTON_UP: {
            eceCity->tabTouches[CLICK] = false;
            break;
        }
        case ALLEGRO_EVENT_MOUSE_AXES: {
            detectionSouris(eceCity);
            break;
        }

        case ALLEGRO_EVENT_TIMER: {
            eceCity->joueur->compteurTemps++;
            if (eceCity->joueur->compteurTemps == FPS) {
                eceCity->joueur->temps++;
                eceCity->joueur->compteurTemps = 0;
                if (eceCity->joueur->temps % CYCLE == 0) {
                    eceCity->joueur->monnaie += TAXE * eceCity->joueur->habitant;
                }
                changerCompteurConstruction(eceCity);
                eceCity->changementAffichage = true;
            }
            deplacerPlateau(eceCity);
            if (eceCity->changementAffichage) {
                affichageJeu(eceCity);
                al_flip_display();
                eceCity->changementAffichage = false;
            }
            if (eceCity->phaseDeJeu.boutonDetecteActuel != -1) {
                faireClignoterBoutonMenu(eceCity, eceCity->ecrire.simsCityPolicePetite);
            }
            if (eceCity->phaseDeJeu.batimenAConstruire != -1 && eceCity->phaseDeJeu.coordCaseDetecte.x != -1 &&
                eceCity->phaseDeJeu.coordCaseDetecte.y != -1 && eceCity->tabTouches[CLICK]) {
                construireBatiment(eceCity);
                eceCity->changementAffichage = true;
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
        if (eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].etatParticulier == false || i == OUTIL) {
            if (eceCity->event.mouse.x * DPI >= eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.x &&
                eceCity->event.mouse.x * DPI <= eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.x +
                                                eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].longueur &&
                eceCity->event.mouse.y * DPI >= eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.y &&
                eceCity->event.mouse.y * DPI <= eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.y +
                                                eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].hauteur) {
                eceCity->phaseDeJeu.boutonDetecteActuel = i;
            }
            if (eceCity->phaseDeJeu.boutonDetecteActuel != eceCity->phaseDeJeu.boutonDetecteAncien) {
                eceCity->changementAffichage = true;
            }
            eceCity->phaseDeJeu.boutonDetecteAncien = eceCity->phaseDeJeu.boutonDetecteActuel;
        }
    }
    if (eceCity->phaseDeJeu.actuelle == JEU) {
        if (eceCity->event.mouse.x * DPI >= eceCity->matricePlateau[0][0].coord.x &&
            eceCity->event.mouse.x * DPI <=
            eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.x + COTECASE &&
            eceCity->event.mouse.y * DPI >= eceCity->matricePlateau[0][0].coord.y &&
            eceCity->event.mouse.y * DPI <=
            eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.y + COTECASE &&
            eceCity->phaseDeJeu.boutonDetecteActuel == -1) {
            eceCity->phaseDeJeu.coordCaseDetecte.x = 0;
            eceCity->phaseDeJeu.coordCaseDetecte.y = 0;
            while (eceCity->event.mouse.x * DPI >
                   eceCity->matricePlateau[0][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x + COTECASE) {
                eceCity->phaseDeJeu.coordCaseDetecte.x++;
            }
            while (eceCity->event.mouse.y * DPI >
                   eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][0].coord.y + COTECASE) {
                eceCity->phaseDeJeu.coordCaseDetecte.y++;
            }
            eceCity->changementAffichage = true;
        }
    }
}

bool verifSiRouteACote(EceCity *eceCity) {
    if (eceCity->phaseDeJeu.batimenAConstruire == ROUTE) {
        return true;
    }
    int hauteur, longueur;
    switch (eceCity->phaseDeJeu.batimenAConstruire) {
        case TERRAINVAGUE: {
            hauteur = longueur = 3;
            break;
        }
        case CHATEAUDEAU:
        case CENTRALE: {
            longueur = 6;
            hauteur = 4;
            break;
        }
    }
    for (int i = eceCity->phaseDeJeu.coordCaseDetecte.y - 1;
         i < eceCity->phaseDeJeu.coordCaseDetecte.y + hauteur + 1; i += hauteur + 1) {
        for (int j = eceCity->phaseDeJeu.coordCaseDetecte.x;
             j < eceCity->phaseDeJeu.coordCaseDetecte.x + longueur; ++j) {
            if (i >= 0 && i < NBLIGNE && j >= 0 && j < NBCOLONNE) {
                if (eceCity->matricePlateau[i][j].type == ROUTE) {
                    return true;
                }
            }
        }
    }
    for (int i = eceCity->phaseDeJeu.coordCaseDetecte.x - 1;
         i < eceCity->phaseDeJeu.coordCaseDetecte.x + longueur + 1; i += longueur + 1) {
        for (int j = eceCity->phaseDeJeu.coordCaseDetecte.y;
             j < eceCity->phaseDeJeu.coordCaseDetecte.y + hauteur; ++j) {
            if (i >= 0 && i < NBCOLONNE && j >= 0 && j < NBLIGNE) {
                if (eceCity->matricePlateau[j][i].type == ROUTE) {
                    return true;
                }
            }
        }
    }
    return false;
}

void construireBatiment(EceCity *eceCity) {
    if (verifSiEspaceBatiment(eceCity) && verifSiRouteACote(eceCity)) {
        int hauteur, longueur;
        float prix;
        switch (eceCity->phaseDeJeu.batimenAConstruire) {
            case ROUTE: {
                hauteur = longueur = 1;
                prix = 10;
                break;
            }
            case TERRAINVAGUE: {
                hauteur = longueur = 3;
                prix = 1000;
                break;
            }
            case CHATEAUDEAU:
            case CENTRALE: {
                longueur = 6;
                hauteur = 4;
                prix = 100000;
                break;
            }
        }
        if (eceCity->joueur->monnaie - prix >= 0) {
            for (int i = eceCity->phaseDeJeu.coordCaseDetecte.y;
                 i < eceCity->phaseDeJeu.coordCaseDetecte.y + hauteur; i++) {
                for (int j = eceCity->phaseDeJeu.coordCaseDetecte.x;
                     j < eceCity->phaseDeJeu.coordCaseDetecte.x + longueur; j++) {
                    eceCity->matricePlateau[i][j].type = eceCity->phaseDeJeu.batimenAConstruire;
                    eceCity->matricePlateau[i][j].construction = false;
                }
            }
            eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].construction = true;
            eceCity->changementAffichage = true;
            eceCity->joueur->monnaie -= prix;
            ajouterBatimentTab(eceCity);
        }
    }
}

bool verifSiEspaceBatiment(EceCity *eceCity) {
    bool verif = false;
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
        case CHATEAUDEAU:
        case CENTRALE: {
            l = 6;
            h = 4;
            break;
        }
    }
    if (eceCity->phaseDeJeu.coordCaseDetecte.x + l <= NBCOLONNE &&
        eceCity->phaseDeJeu.coordCaseDetecte.y + h <= NBLIGNE) {
        verif = true;
        for (int i = eceCity->phaseDeJeu.coordCaseDetecte.x; i < eceCity->phaseDeJeu.coordCaseDetecte.x + l; i++) {
            for (int j = eceCity->phaseDeJeu.coordCaseDetecte.y; j < eceCity->phaseDeJeu.coordCaseDetecte.y + h; j++) {
                if (eceCity->matricePlateau[j][i].type != VIDE &&
                    eceCity->matricePlateau[j][i].type != GRASS) {
                    verif = false;
                }
            }
        }
    }
    return verif;
}

void boutonPresse(EceCity *eceCity) {
    if (eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].cliquable) {
        switch (eceCity->phaseDeJeu.actuelle) {
            case ACCEUIL: {
                switch (eceCity->phaseDeJeu.boutonDetecteActuel) {
                    case NOUVELLEPARTIE: {
                        eceCity->phaseDeJeu.ancienne = eceCity->phaseDeJeu.actuelle;
                        eceCity->phaseDeJeu.boutonDetecteActuel = -1;
                        eceCity->phaseDeJeu.boutonDetecteAncien = -1;
                        eceCity->phaseDeJeu.ancienne = -1;
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
                            eceCity->phaseDeJeu.nomBatimenAConstruire = "ROUTE";
                        }
                        eceCity->changementAffichage = true;
                        break;
                    }
                    case CONSTRUIREBATIMENT: {
                        if (eceCity->phaseDeJeu.batimenAConstruire == TERRAINVAGUE) {
                            eceCity->phaseDeJeu.batimenAConstruire = -1;
                        } else {
                            eceCity->phaseDeJeu.batimenAConstruire = TERRAINVAGUE;
                            eceCity->phaseDeJeu.nomBatimenAConstruire = "BATIMENT";
                        }
                        eceCity->changementAffichage = true;
                        break;
                    }
                    case CONSTRUIRECHATEAUDEAU: {
                        if (eceCity->phaseDeJeu.batimenAConstruire == CHATEAUDEAU) {
                            eceCity->phaseDeJeu.batimenAConstruire = -1;
                        } else {
                            eceCity->phaseDeJeu.batimenAConstruire = CHATEAUDEAU;
                            eceCity->phaseDeJeu.nomBatimenAConstruire = "CHATEAU D'EAU";
                        }
                        eceCity->changementAffichage = true;
                        break;
                    }
                    case CONSTRUIRECENTRALE: {
                        if (eceCity->phaseDeJeu.batimenAConstruire == CENTRALE) {
                            eceCity->phaseDeJeu.batimenAConstruire = -1;
                        } else {
                            eceCity->phaseDeJeu.batimenAConstruire = CENTRALE;
                            eceCity->phaseDeJeu.nomBatimenAConstruire = "CENTRALE";
                        }
                        eceCity->changementAffichage = true;
                        break;
                    }
                    case OUTIL: {
                        if (eceCity->tabBoutons[JEU][OUTIL].etatParticulier) {
                            eceCity->tabBoutons[JEU][OUTIL].etatParticulier = false;
                            eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].etatParticulier = true;
                            eceCity->tabBoutons[JEU][CONSTRUIREROUTE].etatParticulier = true;
                            eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].etatParticulier = true;
                            eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].etatParticulier = true;
                            eceCity->tabBoutons[JEU][BARREDOUTILS].etatParticulier = true;
                        } else {
                            eceCity->tabBoutons[JEU][OUTIL].etatParticulier = true;
                            eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].etatParticulier = false;
                            eceCity->tabBoutons[JEU][CONSTRUIREROUTE].etatParticulier = false;
                            eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].etatParticulier = false;
                            eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].etatParticulier = false;
                            eceCity->tabBoutons[JEU][BARREDOUTILS].etatParticulier = false;
                        }
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
}

void deplacerPlateau(EceCity *eceCity) {
    if (eceCity->tabTouches[BAS]) {
        if (eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.y + (COTECASE * 6) >=
            eceCity->display.hauteur) {
            for (int i = 0; i < NBLIGNE; ++i) {
                for (int j = 0; j < NBCOLONNE; ++j) {
                    eceCity->matricePlateau[i][j].coord.y -= VITESSE;
                }
            }
        }
        eceCity->changementAffichage = true;
    }
    if (eceCity->tabTouches[HAUT]) {
        if (eceCity->matricePlateau[0][0].coord.y - COTECASE * 5 <= 0) {
            for (int i = 0; i < NBLIGNE; ++i) {
                for (int j = 0; j < NBCOLONNE; ++j) {
                    eceCity->matricePlateau[i][j].coord.y += VITESSE;
                }
            }
        }
        eceCity->changementAffichage = true;
    }
    if (eceCity->tabTouches[GAUCHE]) {
        if (eceCity->matricePlateau[0][0].coord.x - COTECASE * 5 <= 0) {
            for (int i = 0; i < NBLIGNE; ++i) {
                for (int j = 0; j < NBCOLONNE; ++j) {
                    eceCity->matricePlateau[i][j].coord.x += VITESSE;
                }
            }
        }
        eceCity->changementAffichage = true;
    }
    if (eceCity->tabTouches[DROITE]) {
        if (eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.x + (COTECASE * 6) >=
            eceCity->display.longueur) {
            for (int i = 0; i < NBLIGNE; ++i) {
                for (int j = 0; j < NBCOLONNE; ++j) {
                    eceCity->matricePlateau[i][j].coord.x -= VITESSE;
                }
            }
        }
        eceCity->changementAffichage = true;
    }
}

void ajouterBatimentTab(EceCity *eceCity) {
    switch (eceCity->phaseDeJeu.batimenAConstruire) {
        case TERRAINVAGUE : {
            eceCity->tabBatiments[eceCity->compteur.batiments].compteur = 0;
            eceCity->tabBatiments[eceCity->compteur.batiments].type = TERRAINVAGUE;
            eceCity->tabBatiments[eceCity->compteur.batiments].position.x = eceCity->phaseDeJeu.coordCaseDetecte.x;
            eceCity->tabBatiments[eceCity->compteur.batiments].position.y = eceCity->phaseDeJeu.coordCaseDetecte.y;
            eceCity->tabBatiments[eceCity->compteur.batiments].utilisationEau = 0;
            eceCity->tabBatiments[eceCity->compteur.batiments].elec = false;
            eceCity->compteur.batiments++;
            break;
        }
        case CENTRALE: {
            eceCity->tabCentrales[eceCity->compteur.centrales].capacite = 5000;
            eceCity->tabCentrales[eceCity->compteur.centrales].utile = 0;
            eceCity->tabCentrales[eceCity->compteur.centrales].position.x = eceCity->phaseDeJeu.coordCaseDetecte.x;
            eceCity->tabCentrales[eceCity->compteur.centrales].position.y = eceCity->phaseDeJeu.coordCaseDetecte.y;
            eceCity->joueur->capaciteElec += eceCity->tabCentrales[eceCity->compteur.centrales].capacite;
            eceCity->compteur.centrales++;
            break;
        }
        case CHATEAUDEAU: {
            eceCity->tabChateauEaux[eceCity->compteur.chateauxDeau].capacite = 5000;
            eceCity->tabChateauEaux[eceCity->compteur.chateauxDeau].utile = 0;
            eceCity->tabChateauEaux[eceCity->compteur.chateauxDeau].position.x = eceCity->phaseDeJeu.coordCaseDetecte.x;
            eceCity->tabChateauEaux[eceCity->compteur.chateauxDeau].position.y = eceCity->phaseDeJeu.coordCaseDetecte.y;
            eceCity->joueur->capaciteEau += eceCity->tabChateauEaux[eceCity->compteur.chateauxDeau].capacite;
            eceCity->compteur.chateauxDeau++;
            break;
        }
    }
}

void changerCompteurConstruction(EceCity *eceCity) {
    int nbHab = 0;
    for (int i = 0; i < eceCity->compteur.batiments; ++i) {
        if (eceCity->tabBatiments[i].type != GRATTECIEL) {
            eceCity->tabBatiments[i].compteur++;
            if (eceCity->tabBatiments[i].compteur == CYCLE) {
                eceCity->tabBatiments[i].type++;
                eceCity->tabBatiments[i].compteur = 0;
                eceCity->matricePlateau[eceCity->tabBatiments[i].position.y][eceCity->tabBatiments[i].position.x].type = eceCity->tabBatiments[i].type;
            }
        }
        switch (eceCity->tabBatiments[i].type) {
            case CABANE : {
                nbHab += 10;
                break;
            }
            case MAISON : {
                nbHab += 50;
                break;
            }
            case IMMEUBLE : {
                nbHab += 100;
                break;
            }
            case GRATTECIEL : {
                nbHab += 1000;
                break;
            }
        }
    }
    eceCity->joueur->habitant = nbHab;
}

void parcourBFSCentrales(EceCity *eceCity) {
    for (int i = 0; i < NBLIGNE; ++i) {
        for (int j = 0; j < NBCOLONNE; ++j) {
            eceCity->matricePlateau[i][j].verif = false;
            eceCity->matricePlateau[i][j].firstMaison = false;
            eceCity->matricePlateau[i][j].pred.x = -1;
            eceCity->matricePlateau[i][j].pred.y = -1;
        }
    }
    File f = fileVide();
    Coord cooTemp;
    Coord cooAEnfiler;
    if (eceCity->compteur.centrales != 0) {
        for (int k = 0; k < eceCity->compteur.centrales; ++k) {
            printf("%d:%d\n\n", eceCity->tabCentrales[eceCity->compteur.centrales].position.x, eceCity->tabCentrales[eceCity->compteur.centrales].position.y);
            for (int i = eceCity->tabCentrales[eceCity->compteur.centrales].position.y - 1;
                 i < eceCity->tabCentrales[eceCity->compteur.centrales].position.y + 4 + 1; i += 4 + 1) {
                for (int j = eceCity->tabCentrales[eceCity->compteur.centrales].position.x;
                     j < eceCity->tabCentrales[eceCity->compteur.centrales].position.x + 6; ++j) {
                    printf("%d:%d\n", i, j);
                    if (i >= 0 && i < NBLIGNE && j >= 0 && j < NBCOLONNE) {
                        if (eceCity->matricePlateau[i][j].type == ROUTE) {
                            cooAEnfiler.x = j;
                            cooAEnfiler.y = i;
                            eceCity->matricePlateau[i][j].pred.x = -9;
                            eceCity->matricePlateau[i][j].pred.y = -9;
                            eceCity->matricePlateau[i][j].verif = true;
                            enfiler(f, cooAEnfiler);
                        }
                    }
                }
            }
            for (int i = eceCity->tabCentrales[eceCity->compteur.centrales].position.x - 1;
                 i < eceCity->tabCentrales[eceCity->compteur.centrales].position.x + 6 + 1; i += 6 + 1) {
                for (int j = eceCity->tabCentrales[eceCity->compteur.centrales].position.y;
                     j < eceCity->tabCentrales[eceCity->compteur.centrales].position.y + 4; ++j) {
                    printf("%d:%d\n", j, i);
                    if (i >= 0 && i < NBCOLONNE && j >= 0 && j < NBLIGNE) {
                        if (eceCity->matricePlateau[j][i].type == ROUTE) {
                            cooAEnfiler.x = i;
                            cooAEnfiler.y = j;
                            eceCity->matricePlateau[j][i].pred.x = -9;
                            eceCity->matricePlateau[j][i].pred.y = -9;
                            eceCity->matricePlateau[j][i].verif = true;
                            enfiler(f, cooAEnfiler);
                        }
                    }
                }
            }
            while (longueur(f) != 0) {
                cooTemp = defiler(f);
                if (cooTemp.x >= 0 && cooTemp.x < NBCOLONNE && cooTemp.y + 1 >= 0 && cooTemp.y + 1 < NBLIGNE) {
                    if (eceCity->matricePlateau[cooTemp.y + 1][cooTemp.x].type == ROUTE &&
                        eceCity->matricePlateau[cooTemp.y + 1][cooTemp.x].verif == false) {
                        cooAEnfiler.x = cooTemp.x;
                        cooAEnfiler.y = cooTemp.y + 1;
                        eceCity->matricePlateau[cooAEnfiler.y][cooAEnfiler.x].pred.x = cooTemp.x;
                        eceCity->matricePlateau[cooAEnfiler.y][cooAEnfiler.x].pred.y = cooTemp.y + 1;
                        eceCity->matricePlateau[cooAEnfiler.y][cooAEnfiler.x].verif = true;
                        enfiler(f, cooAEnfiler);
                    }
                }
                if (cooTemp.x >= 0 && cooTemp.x < NBCOLONNE && cooTemp.y - 1 >= 0 && cooTemp.y - 1 < NBLIGNE) {
                    if (eceCity->matricePlateau[cooTemp.y - 1][cooTemp.x].type == ROUTE &&
                        eceCity->matricePlateau[cooTemp.y - 1][cooTemp.x].verif == false) {
                        cooAEnfiler.x = cooTemp.x;
                        cooAEnfiler.y = cooTemp.y - 1;
                        eceCity->matricePlateau[cooAEnfiler.y][cooAEnfiler.x].pred.x = cooTemp.x;
                        eceCity->matricePlateau[cooAEnfiler.y][cooAEnfiler.x].pred.y = cooTemp.y - 1;
                        eceCity->matricePlateau[cooAEnfiler.y][cooAEnfiler.x].verif = true;
                        enfiler(f, cooAEnfiler);
                    }
                }
                if (cooTemp.x + 1 >= 0 && cooTemp.x + 1 < NBCOLONNE && cooTemp.y >= 0 && cooTemp.y < NBLIGNE) {
                    if (eceCity->matricePlateau[cooTemp.y][cooTemp.x + 1].type == ROUTE &&
                        eceCity->matricePlateau[cooTemp.y][cooTemp.x + 1].verif == false) {
                        cooAEnfiler.x = cooTemp.x + 1;
                        cooAEnfiler.y = cooTemp.y;
                        eceCity->matricePlateau[cooAEnfiler.y][cooAEnfiler.x].pred.x = cooTemp.x + 1;
                        eceCity->matricePlateau[cooAEnfiler.y][cooAEnfiler.x].pred.y = cooTemp.y;
                        eceCity->matricePlateau[cooAEnfiler.y][cooAEnfiler.x].verif = true;
                        enfiler(f, cooAEnfiler);
                    }
                }
                if (cooTemp.x - 1 >= 0 && cooTemp.x - 1 < NBCOLONNE && cooTemp.y >= 0 && cooTemp.y < NBLIGNE) {
                    if (eceCity->matricePlateau[cooTemp.y][cooTemp.x - 1].type == ROUTE &&
                        eceCity->matricePlateau[cooTemp.y][cooTemp.x - 1].verif == false) {
                        cooAEnfiler.x = cooTemp.x - 1;
                        cooAEnfiler.y = cooTemp.y;
                        eceCity->matricePlateau[cooAEnfiler.y][cooAEnfiler.x].pred.x = cooTemp.x - 1;
                        eceCity->matricePlateau[cooAEnfiler.y][cooAEnfiler.x].pred.y = cooTemp.y;
                        eceCity->matricePlateau[cooAEnfiler.y][cooAEnfiler.x].verif = true;
                        enfiler(f, cooAEnfiler);
                    }
                }

                if (cooTemp.x >= 0 && cooTemp.x < NBCOLONNE && cooTemp.y + 1 >= 0 && cooTemp.y + 1 < NBLIGNE) {
                    if (eceCity->matricePlateau[cooTemp.y + 1][cooTemp.x].type == TERRAINVAGUE ||
                        eceCity->matricePlateau[cooTemp.y + 1][cooTemp.x].type == RUINE ||
                        eceCity->matricePlateau[cooTemp.y + 1][cooTemp.x].type == CABANE ||
                        eceCity->matricePlateau[cooTemp.y + 1][cooTemp.x].type == IMMEUBLE ||
                        eceCity->matricePlateau[cooTemp.y + 1][cooTemp.x].type == GRATTECIEL ||
                        eceCity->matricePlateau[cooTemp.y + 1][cooTemp.x].type == MAISON) {
                        eceCity->matricePlateau[cooTemp.y + 1][cooTemp.x].firstMaison = true;
                    }
                }
                if (cooTemp.x >= 0 && cooTemp.x < NBCOLONNE && cooTemp.y - 1 >= 0 && cooTemp.y - 1 < NBLIGNE) {
                    if (eceCity->matricePlateau[cooTemp.y - 1][cooTemp.x].type == TERRAINVAGUE ||
                        eceCity->matricePlateau[cooTemp.y - 1][cooTemp.x].type == RUINE ||
                        eceCity->matricePlateau[cooTemp.y - 1][cooTemp.x].type == CABANE ||
                        eceCity->matricePlateau[cooTemp.y - 1][cooTemp.x].type == IMMEUBLE ||
                        eceCity->matricePlateau[cooTemp.y - 1][cooTemp.x].type == GRATTECIEL ||
                        eceCity->matricePlateau[cooTemp.y - 1][cooTemp.x].type == MAISON) {
                        eceCity->matricePlateau[cooTemp.y - 1][cooTemp.x].firstMaison = true;
                    }
                }
                if (cooTemp.x + 1 >= 0 && cooTemp.x + 1 < NBCOLONNE && cooTemp.y >= 0 && cooTemp.y < NBLIGNE) {
                    if (eceCity->matricePlateau[cooTemp.y][cooTemp.x + 1].type == TERRAINVAGUE ||
                        eceCity->matricePlateau[cooTemp.y][cooTemp.x + 1].type == RUINE ||
                        eceCity->matricePlateau[cooTemp.y][cooTemp.x + 1].type == CABANE ||
                        eceCity->matricePlateau[cooTemp.y][cooTemp.x + 1].type == IMMEUBLE ||
                        eceCity->matricePlateau[cooTemp.y][cooTemp.x + 1].type == GRATTECIEL ||
                        eceCity->matricePlateau[cooTemp.y][cooTemp.x + 1].type == MAISON) {
                        eceCity->matricePlateau[cooTemp.y][cooTemp.x + 1].firstMaison = true;
                    }
                }
                if (cooTemp.x - 1 >= 0 && cooTemp.x - 1 < NBCOLONNE && cooTemp.y >= 0 && cooTemp.y < NBLIGNE) {
                    if (eceCity->matricePlateau[cooTemp.y][cooTemp.x - 1].type == TERRAINVAGUE ||
                        eceCity->matricePlateau[cooTemp.y][cooTemp.x - 1].type == RUINE ||
                        eceCity->matricePlateau[cooTemp.y][cooTemp.x - 1].type == CABANE ||
                        eceCity->matricePlateau[cooTemp.y][cooTemp.x - 1].type == IMMEUBLE ||
                        eceCity->matricePlateau[cooTemp.y][cooTemp.x - 1].type == GRATTECIEL ||
                        eceCity->matricePlateau[cooTemp.y][cooTemp.x - 1].type == MAISON) {
                        eceCity->matricePlateau[cooTemp.y][cooTemp.x - 1].firstMaison = true;
                    }
                }
            }
        }
    }
    free(f);
}

void remonterParPredEtCompterDistance(EceCity *eceCity) {
    Coord cooTemp;
    int dTemp;
    for (int i = 0; i < eceCity->compteur.batiments; ++i) {
        eceCity->tabBatiments[i].dElec = 99999999;
        for (int j = eceCity->tabBatiments[i].position.x; j < eceCity->tabBatiments[i].position.x + 3; ++j) {
            for (int k = eceCity->tabBatiments[i].position.y; k < eceCity->tabBatiments[i].position.y + 3; ++k) {
                if (eceCity->matricePlateau[k][j].firstMaison) {
                    for (int l = 0; l < 2; ++l) {
                        dTemp = 0;
                        if (k + 1 - 2 * l > 0 && k + 1 - 2 * l < NBLIGNE && j > 0 && j < NBCOLONNE) {
                            if (eceCity->matricePlateau[k + 1 - 2 * l][j].type == ROUTE &&
                                eceCity->matricePlateau[k + 1 - 2 * l][j].pred.x != -1) {
                                printf("found");
                                cooTemp.x = j;
                                cooTemp.y = k + 1 - 2 * l;
                                dTemp++;
                            }
                            while (cooTemp.x != -9) {
                                cooTemp = eceCity->matricePlateau[cooTemp.y][cooTemp.x].pred;
                                dTemp++;
                            }
                            if (dTemp < eceCity->tabBatiments[i].dElec) {
                                eceCity->tabBatiments[i].dElec = dTemp;
                            }
                        }
                    }
                    for (int l = 0; l < 2; ++l) {
                        dTemp = 0;
                        if (k > 0 && k < NBLIGNE && j + 1 - 2 * l > 0 && j + 1 - 2 * l < NBCOLONNE) {
                            if (eceCity->matricePlateau[k][j + 1 - 2 * l].type == ROUTE &&
                                eceCity->matricePlateau[k][j + 1 - 2 * l].pred.x != -1) {
                                cooTemp.x = j + 1 - 2 * l;
                                cooTemp.y = k;
                                dTemp++;
                                while (cooTemp.x != -9) {
                                    cooTemp = eceCity->matricePlateau[cooTemp.y][cooTemp.x].pred;
                                    dTemp++;
                                }
                                if (dTemp < eceCity->tabBatiments[i].dElec) {
                                    eceCity->tabBatiments[i].dElec = dTemp;
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", eceCity->tabBatiments[i].dElec);
    }
}