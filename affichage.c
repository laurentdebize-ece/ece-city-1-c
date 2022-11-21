#include "affichage.h"
#include "jeu.h"

void affichageAcceuil(EceCity *eceCity) {
    affichageBitmapDeFond(eceCity, BITMAPACCEUIL);
    al_draw_text(eceCity->ecrire.simsCityPoliceGrand, al_map_rgb(0, 112, 255), eceCity->display.longueur / 2,
                 (eceCity->display.hauteur * 5 / 12) -
                 al_get_font_line_height(eceCity->ecrire.simsCityPoliceGrand), ALLEGRO_ALIGN_CENTER, "ECE CITY");
    affichageBouton(eceCity, eceCity->ecrire.simsCityPoliceMoyen);
}

void affichageChoixDuMode(EceCity *eceCity) {
    affichageBitmapDeFond(eceCity, BITMAPCHOIXDUMODE);
    affichageBouton(eceCity, eceCity->ecrire.simsCityPoliceMoyen);
}

void affichageJeu(EceCity *eceCity) {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    dessinerGrille(eceCity);
    affichageBarreDoutils(eceCity);
    affichageBouton(eceCity, eceCity->ecrire.simsCityPolicePetite);
    if (eceCity->phaseDeJeu.batimenAConstruire != -1 && eceCity->phaseDeJeu.coordCaseDetecte.x != -1 &&
        eceCity->phaseDeJeu.coordCaseDetecte.y != -1) {
        dessinerBatimentAConstruire(eceCity);
    }
}

void dessinerBatimentAConstruire(EceCity *eceCity) {
    switch (eceCity->phaseDeJeu.batimenAConstruire) {
        case ROUTE: {
            al_draw_filled_rectangle(
                    eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x,
                    eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y,
                    eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x +
                    COTECASE,
                    eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y +
                    COTECASE, al_map_rgba(0, 0, 255, 64));
            break;
        }
        case TERRAINVAGUE: {
            if (eceCity->phaseDeJeu.coordCaseDetecte.x + 3 <= NBCOLONNE &&
                eceCity->phaseDeJeu.coordCaseDetecte.y + 3 <= NBLIGNE) {
                al_draw_filled_rectangle(
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x,
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y,
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x +
                        COTECASE * 3,
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y +
                        COTECASE * 3, al_map_rgba(255, 0, 0, 64));
            }
            break;
        }
        case CHATEAUDEAU: {
            if (eceCity->phaseDeJeu.coordCaseDetecte.x + 6 <= NBCOLONNE &&
                eceCity->phaseDeJeu.coordCaseDetecte.y + 4 <= NBLIGNE) {
                al_draw_filled_rectangle(
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x,
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y,
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x +
                        COTECASE * 6,
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y +
                        COTECASE * 4, al_map_rgba(255, 0, 255, 64));
            }
            break;
        }
        case CENTRALE: {
            if (eceCity->phaseDeJeu.coordCaseDetecte.x + 6 <= NBCOLONNE &&
                eceCity->phaseDeJeu.coordCaseDetecte.y + 4 <= NBLIGNE) {
                al_draw_filled_rectangle(
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x,
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y,
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x +
                        COTECASE * 6,
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y +
                        COTECASE * 4, al_map_rgba(255, 255, 0, 64));
            }
            break;
        }
    }
}

void affichageBarreDoutils(EceCity *eceCity) {
    al_draw_filled_rectangle(0, eceCity->display.hauteur * 7 / 8 - 50, eceCity->display.longueur,
                             eceCity->display.hauteur,
                             al_map_rgba(0, 0, 0, 128));
    al_draw_rectangle(0, eceCity->display.hauteur * 7 / 8 - 50, eceCity->display.longueur, eceCity->display.hauteur,
                      al_map_rgb(255, 255, 255), 7);
}

void deplacerPlateau(EceCity *eceCity) {
    if (eceCity->tabTouches[BAS]) {
        if (eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.y + (COTECASE * 5) >=
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
        if (eceCity->matricePlateau[0][0].coord.y - COTECASE*4 <= 0) {
            for (int i = 0; i < NBLIGNE; ++i) {
                for (int j = 0; j < NBCOLONNE; ++j) {
                    eceCity->matricePlateau[i][j].coord.y += VITESSE;
                }
            }
        }
        eceCity->changementAffichage = true;
    }
    if (eceCity->tabTouches[GAUCHE]) {
        if (eceCity->matricePlateau[0][0].coord.x - COTECASE*4 <= 0) {
            for (int i = 0; i < NBLIGNE; ++i) {
                for (int j = 0; j < NBCOLONNE; ++j) {
                    eceCity->matricePlateau[i][j].coord.x += VITESSE;
                }
            }
        }
        eceCity->changementAffichage = true;
    }
    if (eceCity->tabTouches[DROITE]) {
        if (eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.x + (COTECASE * 5) >=
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

void dessinerGrille(EceCity *eceCity) {
    al_draw_filled_rectangle(eceCity->matricePlateau[0][0].coord.x,
                             eceCity->matricePlateau[0][0].coord.y,
                             eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.x + COTECASE,
                             eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.y + COTECASE,
                             al_map_rgb(89, 166, 8));
    for (int i = 0; i < NBLIGNE; ++i) {
        for (int j = 0; j < NBCOLONNE; ++j) {
            if (eceCity->matricePlateau[i][j].type == ARBRE) {
                al_draw_filled_rectangle(eceCity->matricePlateau[i][j].coord.x,
                                         eceCity->matricePlateau[i][j].coord.y,
                                         eceCity->matricePlateau[i][j].coord.x + COTECASE,
                                         eceCity->matricePlateau[i][j].coord.y + COTECASE,
                                         al_map_rgb(128, 0, 0));
            } else if (eceCity->matricePlateau[i][j].type == ROUTE) {
                al_draw_filled_rectangle(eceCity->matricePlateau[i][j].coord.x,
                                         eceCity->matricePlateau[i][j].coord.y,
                                         eceCity->matricePlateau[i][j].coord.x + COTECASE,
                                         eceCity->matricePlateau[i][j].coord.y + COTECASE,
                                         al_map_rgb(0, 0, 255));
            } else if (eceCity->matricePlateau[i][j].type == TERRAINVAGUE) {
                al_draw_filled_rectangle(eceCity->matricePlateau[i][j].coord.x,
                                         eceCity->matricePlateau[i][j].coord.y,
                                         eceCity->matricePlateau[i][j].coord.x + COTECASE,
                                         eceCity->matricePlateau[i][j].coord.y + COTECASE,
                                         al_map_rgb(255, 0, 0));
            }else if (eceCity->matricePlateau[i][j].type == CENTRALE) {
                al_draw_filled_rectangle(eceCity->matricePlateau[i][j].coord.x,
                                         eceCity->matricePlateau[i][j].coord.y,
                                         eceCity->matricePlateau[i][j].coord.x + COTECASE,
                                         eceCity->matricePlateau[i][j].coord.y + COTECASE,
                                         al_map_rgb(255, 255, 0));
            }else if (eceCity->matricePlateau[i][j].type == CHATEAUDEAU) {
                al_draw_filled_rectangle(eceCity->matricePlateau[i][j].coord.x,
                                         eceCity->matricePlateau[i][j].coord.y,
                                         eceCity->matricePlateau[i][j].coord.x + COTECASE,
                                         eceCity->matricePlateau[i][j].coord.y + COTECASE,
                                         al_map_rgb(255, 0, 255));
            }else if (eceCity->matricePlateau[i][j].type == CABANE) {
                al_draw_filled_rectangle(eceCity->matricePlateau[i][j].coord.x,
                                         eceCity->matricePlateau[i][j].coord.y,
                                         eceCity->matricePlateau[i][j].coord.x + COTECASE,
                                         eceCity->matricePlateau[i][j].coord.y + COTECASE,
                                         al_map_rgb(128, 255, 128));
            }else if (eceCity->matricePlateau[i][j].type == MAISON) {
                al_draw_filled_rectangle(eceCity->matricePlateau[i][j].coord.x,
                                         eceCity->matricePlateau[i][j].coord.y,
                                         eceCity->matricePlateau[i][j].coord.x + COTECASE,
                                         eceCity->matricePlateau[i][j].coord.y + COTECASE,
                                         al_map_rgb(255, 255, 255));
            }else if (eceCity->matricePlateau[i][j].type == IMMEUBLE) {
                al_draw_filled_rectangle(eceCity->matricePlateau[i][j].coord.x,
                                         eceCity->matricePlateau[i][j].coord.y,
                                         eceCity->matricePlateau[i][j].coord.x + COTECASE,
                                         eceCity->matricePlateau[i][j].coord.y + COTECASE,
                                         al_map_rgb(128, 128, 128));
            }else if (eceCity->matricePlateau[i][j].type == GRATTECIEL) {
                al_draw_filled_rectangle(eceCity->matricePlateau[i][j].coord.x,
                                         eceCity->matricePlateau[i][j].coord.y,
                                         eceCity->matricePlateau[i][j].coord.x + COTECASE,
                                         eceCity->matricePlateau[i][j].coord.y + COTECASE,
                                         al_map_rgb(0, 0, 0));
            }
        }
    }
    if (eceCity->phaseDeJeu.coordCaseDetecte.x != -1 && eceCity->phaseDeJeu.coordCaseDetecte.y != -1 &&
        eceCity->tabTouches[BAS] == false &&
        eceCity->tabTouches[HAUT] == false && eceCity->tabTouches[DROITE] == false &&
        eceCity->tabTouches[GAUCHE] == false) {
        al_draw_filled_rectangle(
                eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x,
                eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y,
                eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x +
                COTECASE,
                eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y +
                COTECASE, al_map_rgba(0, 0, 0, 128));
    } else {
        eceCity->phaseDeJeu.coordCaseDetecte.x = -1;
        eceCity->phaseDeJeu.coordCaseDetecte.y = -1;
    }
    for (int i = 0; i < NBLIGNE + 1; ++i) {
        al_draw_line(eceCity->matricePlateau[0][0].coord.x, eceCity->matricePlateau[0][0].coord.y + i * COTECASE,
                     eceCity->matricePlateau[0][0].coord.x + NBCOLONNE * COTECASE,
                     eceCity->matricePlateau[0][0].coord.y + i * COTECASE, al_map_rgb(255, 255, 255), 2);
    }
    for (int i = 0; i < NBCOLONNE + 1; ++i) {
        al_draw_line(eceCity->matricePlateau[0][0].coord.x + i * COTECASE, eceCity->matricePlateau[0][0].coord.y,
                     eceCity->matricePlateau[0][0].coord.x + i * COTECASE,
                     eceCity->matricePlateau[0][0].coord.y + NBLIGNE * COTECASE, al_map_rgb(255, 255, 255), 2);
    }
}

void affichageParametres(EceCity *eceCity) {
    affichageBitmapDeFond(eceCity, BITMAPCHOIXDUMODE);
    affichageBouton(eceCity, eceCity->ecrire.simsCityPoliceMoyen);
}

void affichageBouton(EceCity *eceCity, ALLEGRO_FONT *police) {
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
        al_draw_filled_rectangle(eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.x,
                                 eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.y,
                                 eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.x +
                                 eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].longueur,
                                 eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.y +
                                 eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].hauteur,
                                 al_map_rgba(0, 0, 0, 128));
        al_draw_rectangle(eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.x,
                          eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.y,
                          eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.x +
                          eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].longueur,
                          eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.y +
                          eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].hauteur,
                          al_map_rgb(255, 255, 255), 10);
        al_draw_text(police, eceCity->ecrire.couleurDuTexte,
                     eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.x +
                     (eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].longueur / 2),
                     eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.y +
                     (eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].hauteur / 2) -
                     (al_get_font_line_height(police) / 2), ALLEGRO_ALIGN_CENTER,
                     eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].nom);
    }
}

void affichageBitmapDeFond(EceCity *eceCity, int numBitmap) {
    al_draw_scaled_bitmap(eceCity->tabImages[numBitmap].image, eceCity->tabImages[numBitmap].coord.x,
                          eceCity->tabImages[numBitmap].coord.y, eceCity->tabImages[numBitmap].longueur,
                          eceCity->tabImages[numBitmap].hauteur, 0, 0, eceCity->display.longueur,
                          eceCity->display.hauteur, 0);
}

void faireClignoterBoutonMenu(EceCity *eceCity, ALLEGRO_FONT *police) {
    if (eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].clignote) {
        al_draw_rectangle(
                eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.x,
                eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.y,
                eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.x +
                eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].longueur,
                eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.y +
                eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].hauteur,
                al_map_rgb(4 * al_get_timer_count(eceCity->timer), 0, 0),
                7);
        al_draw_text(police, al_map_rgb(4 * al_get_timer_count(eceCity->timer), 0, 0),
                     eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.x +
                     (eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].longueur /
                      2),
                     eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.y +
                     (eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].hauteur /
                      2) -
                     (al_get_font_line_height(police) / 2), ALLEGRO_ALIGN_CENTER,
                     eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].nom);
        al_flip_display();
    }
}