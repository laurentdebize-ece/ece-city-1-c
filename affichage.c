#include "affichage.h"
#include "jeu.h"

void affichageAcceuil(EceCity *eceCity) {
    affichageBitmapDeFond(eceCity, BITMAPACCEUIL);
    al_draw_text(eceCity->ecrire.simsCityPoliceGrand, al_map_rgb(0, 0, 0), eceCity->display.longueur / 2,
                 (eceCity->display.hauteur * 5 / 12) -
                 al_get_font_line_height(eceCity->ecrire.simsCityPoliceGrand), ALLEGRO_ALIGN_CENTER, "ECE CITY");
    affichageBouton(eceCity, eceCity->ecrire.simsCityPoliceMoyen);
}

void affichageChoixDuMode(EceCity *eceCity) {
    affichageBitmapDeFond(eceCity, BITMAPCHOIXDUMODE);
    al_draw_text(eceCity->ecrire.simsCityPoliceGrand, al_map_rgb(0, 0, 0), eceCity->display.longueur / 2,
                 (eceCity->display.hauteur * 5 / 12) -
                 al_get_font_line_height(eceCity->ecrire.simsCityPoliceGrand), ALLEGRO_ALIGN_CENTER, "CHOIX DU MODE");
    affichageBouton(eceCity, eceCity->ecrire.simsCityPoliceMoyen);
}

void affichageJeu(EceCity *eceCity) {
    al_clear_to_color(al_map_rgb(200, 200, 200));
    dessinerGrille(eceCity);
    affichageBouton(eceCity, eceCity->ecrire.simsCityPolicePetite);
    if (eceCity->phaseDeJeu.batimenAConstruire != -1 && eceCity->phaseDeJeu.coordCaseDetecte.x != -1 &&
        eceCity->phaseDeJeu.coordCaseDetecte.y != -1) {
        dessinerBatimentAConstruire(eceCity);
    }
    affichageInfos(eceCity);
}

void affichageInfos(EceCity *eceCity) {
    al_draw_textf(eceCity->ecrire.simsCityPolicePetite, al_map_rgb(0, 0, 0), eceCity->display.longueur * 8 / 9 + 10,
                  200,
                  0,
                  "time %d",
                  eceCity->joueur->temps);
    al_draw_textf(eceCity->ecrire.simsCityPolicePetite, al_map_rgb(0, 0, 0), eceCity->display.longueur * 8 / 9 + 10,
                  300,
                  0,
                  "Hab %d",
                  eceCity->joueur->habitant);
    al_draw_textf(eceCity->ecrire.simsCityPolicePetite, al_map_rgb(0, 0, 0), eceCity->display.longueur * 8 / 9 + 10,
                  400,
                  0,
                  "Sous %d",
                  eceCity->joueur->monnaie);
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
            al_draw_scaled_bitmap(eceCity->tabImages[BitmapROUTEdroite].image, 0, 0, eceCity->tabImages[BitmapROUTEdroite].longueur,
                                  eceCity->tabImages[BitmapROUTEdroite].hauteur,
                                  eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x,
                                  eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y,
                                  eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x +
                                  COTECASE -
                                  eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x,
                                  eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y +
                                  COTECASE -
                                  eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y,
                                  0);

            break;
        }
        case TERRAINVAGUE: {
            if (eceCity->phaseDeJeu.coordCaseDetecte.x + 3 <= NBCOLONNE &&
                eceCity->phaseDeJeu.coordCaseDetecte.y + 3 <= NBLIGNE) {
                al_draw_tinted_scaled_bitmap(eceCity->tabImages[BitmapRuine].image, al_map_rgba(0, 0, 0, 30), 0, 0,
                                             eceCity->tabImages[BitmapRuine].longueur,
                                             eceCity->tabImages[BitmapRuine].hauteur,
                                             eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x,
                                             eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y -
                                             19,
                                             COTECASE * 3,
                                             COTECASE * 3 + 19,
                                             0);
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
                al_draw_tinted_scaled_bitmap(eceCity->tabImages[BitmapChateauDeau].image, al_map_rgba(0, 0, 0, 30), 0, 0,
                                             eceCity->tabImages[BitmapChateauDeau].longueur,
                                             eceCity->tabImages[BitmapChateauDeau].hauteur,
                                             eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x,
                                             eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y -
                                             19,
                                             COTECASE * 6,
                                             COTECASE * 4,
                                             0);
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
                al_draw_tinted_scaled_bitmap(eceCity->tabImages[BitmapCentrale].image, al_map_rgba(0, 0, 0, 30), 0, 0,
                                             eceCity->tabImages[BitmapCentrale].longueur,
                                             eceCity->tabImages[BitmapCentrale].hauteur,
                                             eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x,
                                             eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y -
                                             19,
                                             COTECASE * 6,
                                             COTECASE * 4,
                                             0);
            }
            break;
        }
    }
}

void dessinerGrille(EceCity *eceCity) {
    al_draw_filled_rectangle(eceCity->matricePlateau[0][0].coord.x,
                             eceCity->matricePlateau[0][0].coord.y,
                             eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.x + COTECASE,
                             eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.y + COTECASE,
                             al_map_rgb(89, 166, 8));
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
    for (int i = 0; i < NBLIGNE; ++i) {
        for (int j = 0; j < NBCOLONNE; ++j) {
            if (eceCity->matricePlateau[i][j].construction) {
                if (eceCity->matricePlateau[i][j].type == ARBRE) {
                    al_draw_scaled_bitmap(eceCity->tabImages[BitmapArbre].image, 0, 0, eceCity->tabImages[BitmapArbre].longueur,
                                          eceCity->tabImages[BitmapArbre].hauteur,
                                          eceCity->matricePlateau[i][j].coord.x -8,
                                          eceCity->matricePlateau[i][j].coord.y -15,
                                          COTECASE +15 ,
                                          COTECASE+17 ,
                                          0);
                } else if (eceCity->matricePlateau[i][j].type == ROUTE) {
                    al_draw_filled_rectangle(eceCity->matricePlateau[i][j].coord.x,
                                             eceCity->matricePlateau[i][j].coord.y,
                                             eceCity->matricePlateau[i][j].coord.x + COTECASE,
                                             eceCity->matricePlateau[i][j].coord.y + COTECASE,
                                             al_map_rgb(0, 0, 255));
                } else if (eceCity->matricePlateau[i][j].type == TERRAINVAGUE) {
                    al_draw_scaled_bitmap(eceCity->tabImages[BitmapTerrainVague].image, 0, 0, eceCity->tabImages[BitmapTerrainVague].longueur,
                                          eceCity->tabImages[BitmapTerrainVague].hauteur,
                                          eceCity->matricePlateau[i][j].coord.x,
                                          eceCity->matricePlateau[i][j].coord.y ,
                                          COTECASE * 3,
                                          COTECASE * 3,
                                          0);
                } else if (eceCity->matricePlateau[i][j].type == CENTRALE) {
                    al_draw_scaled_bitmap(eceCity->tabImages[BitmapCentrale].image, 0, 0, eceCity->tabImages[BitmapCentrale].longueur,
                                          eceCity->tabImages[BitmapCentrale].hauteur,
                                          eceCity->matricePlateau[i][j].coord.x,
                                          eceCity->matricePlateau[i][j].coord.y ,
                                          COTECASE * 6,
                                          COTECASE * 4 ,
                                          0);

                } else if (eceCity->matricePlateau[i][j].type == CHATEAUDEAU) {
                    /*al_draw_scaled_rotated_bitmap(eceCity->tabImages[BitmapChateauDeau].image, (eceCity->tabImages[BitmapChateauDeau].longueur), (eceCity->tabImages[BitmapChateauDeau].hauteur+50) /2,
                                                  eceCity->matricePlateau[i][j].coord.x+ (COTECASE*3),
                                                  eceCity->matricePlateau[i][j].coord.y+ (COTECASE*2) ,
                                                  1 ,
                                                  1 , 0.09, 0);*/

                    al_draw_scaled_bitmap(eceCity->tabImages[BitmapChateauDeau].image, 0, 0, eceCity->tabImages[BitmapChateauDeau].longueur,
                                          eceCity->tabImages[BitmapChateauDeau].hauteur,
                                          eceCity->matricePlateau[i][j].coord.x,
                                          eceCity->matricePlateau[i][j].coord.y ,
                                          COTECASE * 6,
                                          COTECASE * 4 ,
                                          0);

                } else if (eceCity->matricePlateau[i][j].type == CABANE) {
                    al_draw_scaled_bitmap(eceCity->tabImages[BitmapCabane].image, 0, 0, eceCity->tabImages[BitmapCabane].longueur,
                                          eceCity->tabImages[BitmapCabane].hauteur,
                                          eceCity->matricePlateau[i][j].coord.x,
                                          eceCity->matricePlateau[i][j].coord.y,
                                          COTECASE * 3,
                                          COTECASE * 3 +35,
                                          0);
                } else if (eceCity->matricePlateau[i][j].type == MAISON) {
                    al_draw_scaled_bitmap(eceCity->tabImages[BitmapMaison].image, 0, 0, eceCity->tabImages[BitmapMaison].longueur,
                                          eceCity->tabImages[BitmapMaison].hauteur,
                                          eceCity->matricePlateau[i][j].coord.x,
                                          eceCity->matricePlateau[i][j].coord.y - 26 ,
                                          COTECASE * 3,
                                          COTECASE * 3 + 26 ,
                                          0);
                } else if (eceCity->matricePlateau[i][j].type == IMMEUBLE) {
                    al_draw_scaled_bitmap(eceCity->tabImages[BitmapImmeuble].image, 0, 0, eceCity->tabImages[BitmapImmeuble].longueur,
                                          eceCity->tabImages[BitmapImmeuble].hauteur,
                                          eceCity->matricePlateau[i][j].coord.x,
                                          eceCity->matricePlateau[i][j].coord.y -40 ,
                                          COTECASE * 3,
                                          COTECASE * 3 +40 ,
                                          0);
                } else if (eceCity->matricePlateau[i][j].type == GRATTECIEL) {
                    al_draw_scaled_bitmap(eceCity->tabImages[BitmapGratteciel].image, 0, 0, eceCity->tabImages[BitmapGratteciel].longueur,
                                          eceCity->tabImages[BitmapGratteciel].hauteur,
                                          eceCity->matricePlateau[i][j].coord.x,
                                          eceCity->matricePlateau[i][j].coord.y -129 ,
                                          COTECASE * 3,
                                          COTECASE * 3 +123 ,
                                          0);
                }
            }
        }
    }
}

void affichageParametres(EceCity *eceCity) {
    affichageBitmapDeFond(eceCity, BITMAPCHOIXDUMODE);
    affichageBouton(eceCity, eceCity->ecrire.simsCityPoliceMoyen);
}

void affichageBouton(EceCity *eceCity, ALLEGRO_FONT *police) {
    int nbBouton;
    float t;
    switch (eceCity->phaseDeJeu.actuelle) {
        case ACCEUIL: {
            nbBouton = NBDEBOUTONACCEUIL;
            t = 7;
            break;
        }
        case CHOIXDUMODE: {
            nbBouton = NBDEBOUTONCHOIXDUMODE;
            t = 7;
            break;
        }
        case JEU: {
            nbBouton = NBDEBOUTONJEU;
            t = 3;
            break;
        }
        case PARAMETRES: {
            nbBouton = NBDEBOUTONPARAMETRES;
            t = 7;
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
                          al_map_rgb(255, 255, 255), t);
        if (eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].nom != NULL) {
            al_draw_text(police, eceCity->ecrire.couleurDuTexte,
                         eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.x +
                         (eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].longueur / 2),
                         eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.y +
                         (eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].hauteur / 2) -
                         (al_get_font_line_height(police) / 2), ALLEGRO_ALIGN_CENTER,
                         eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].nom);
        }
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
        float t;
        switch (eceCity->phaseDeJeu.actuelle) {
            case ACCEUIL: {
                t = 5;
                break;
            }
            case CHOIXDUMODE: {
                t = 5;
                break;
            }
            case JEU: {
                t = 3;
                break;
            }
            case PARAMETRES: {
                t = 5;
                break;
            }
        }
        al_draw_rectangle(
                eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.x,
                eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.y,
                eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.x +
                eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].longueur,
                eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.y +
                eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].hauteur,
                al_map_rgb(4 * al_get_timer_count(eceCity->timer), 0, 0),
                t);
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