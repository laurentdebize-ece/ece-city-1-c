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
    al_clear_to_color(al_map_rgb(102, 102, 102));
    dessinerGrille(eceCity);
    affichageBouton(eceCity, eceCity->ecrire.simsCityPolicePetite);
    if (eceCity->phaseDeJeu.batimenAConstruire != -1 && eceCity->phaseDeJeu.coordCaseDetecte.x != -1 &&
        eceCity->phaseDeJeu.coordCaseDetecte.y != -1) {
        dessinerBatimentAConstruire(eceCity);
    }
    affichageInfos(eceCity);
}

void affichageInfos(EceCity *eceCity) {
    al_draw_textf(eceCity->ecrire.simsCityPolicePetite, al_map_rgb(255, 255, 255),
                  eceCity->display.longueur * 8 / 9 + 80,
                  200,
                  0,
                  " %d",
                  eceCity->joueur->temps);
    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPCOMPTEUR].image, 0,
                          0, 208,
                          208, eceCity->display.longueur * 8 / 9 + 5, 190, 50,
                          50, ALLEGRO_ALIGN_CENTER);
    float habitantAffichage = eceCity->joueur->habitant;
    if (habitantAffichage < 1000) {
        al_draw_textf(eceCity->ecrire.simsCityPolicePetite, al_map_rgb(255, 255, 255),
                      eceCity->display.longueur * 8 / 9 + 80,
                      300,
                      0,
                      "%.0f",
                      habitantAffichage);
    } else if (habitantAffichage < 1000000) {
        habitantAffichage /= 1000;
        al_draw_textf(eceCity->ecrire.simsCityPolicePetite, al_map_rgb(255, 255, 255),
                      eceCity->display.longueur * 8 / 9 + 80,
                      300,
                      0,
                      "%.1f k",
                      habitantAffichage);
    } else {
        habitantAffichage /= 1000000;
        al_draw_textf(eceCity->ecrire.simsCityPolicePetite, al_map_rgb(255, 255, 255),
                      eceCity->display.longueur * 8 / 9 + 80,
                      300,
                      0,
                      "%.1f M",
                      habitantAffichage);
    }
    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPHAB].image, 0,
                          0, 208,
                          208, eceCity->display.longueur * 8 / 9 + 5, 290, 50,
                          50, ALLEGRO_ALIGN_CENTER);
    float monnaieAffichage = eceCity->joueur->monnaie;
    if (monnaieAffichage < 1000) {
        al_draw_textf(eceCity->ecrire.simsCityPolicePetite, al_map_rgb(255, 255, 255),
                      eceCity->display.longueur * 8 / 9 + 80,
                      400,
                      0,
                      "%.0f",
                      monnaieAffichage);
    } else if (monnaieAffichage < 1000000 && monnaieAffichage > 1000) {
        monnaieAffichage /= 1000;
        al_draw_textf(eceCity->ecrire.simsCityPolicePetite, al_map_rgb(255, 255, 255),
                      eceCity->display.longueur * 8 / 9 + 80,
                      400,
                      0,
                      "%.1f k",
                      monnaieAffichage);
    } else {
        monnaieAffichage /= 1000000;
        al_draw_textf(eceCity->ecrire.simsCityPolicePetite, al_map_rgb(255, 255, 255),
                      eceCity->display.longueur * 8 / 9 + 80,
                      400,
                      0,
                      "%.1f M",
                      monnaieAffichage);
    }
    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPMONNAIE].image, 0,
                          0, 312,
                          312, eceCity->display.longueur * 8 / 9 - 20, 365, 100,
                          100, ALLEGRO_ALIGN_CENTER);
    al_draw_textf(eceCity->ecrire.simsCityPolicePetite, al_map_rgb(255, 255, 255),
                  eceCity->display.longueur * 8 / 9 + 80,
                  500,
                  0,
                  " %d/%d",
                  eceCity->joueur->utilisationEau, eceCity->joueur->capaciteEau);
    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPEAU].image, 0,
                          0, 208,
                          208, eceCity->display.longueur * 8 / 9 + 5, 490, 50,
                          50, ALLEGRO_ALIGN_CENTER);
    al_draw_textf(eceCity->ecrire.simsCityPolicePetite, al_map_rgb(255, 255, 255),
                  eceCity->display.longueur * 8 / 9 + 80,
                  600,
                  0,
                  " %d/%d",
                  eceCity->joueur->utilisationElec, eceCity->joueur->capaciteElec);
    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPELEC].image, 0,
                          0, 208,
                          208, eceCity->display.longueur * 8 / 9 + 5, 590, 50,
                          50, ALLEGRO_ALIGN_CENTER);
    if (eceCity->phaseDeJeu.batimenAConstruire != -1) {
        al_draw_textf(eceCity->ecrire.simsCityPolicePetite, al_map_rgb(255, 255, 255),
                      eceCity->display.longueur * 8 / 9 + 10,
                      700,
                      0,
                      "%s",
                      eceCity->phaseDeJeu.nomBatimenAConstruire);
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
                    COTECASE,
                    al_map_rgba(128, 128, 128, 100));
            break;
        }
        case TERRAINVAGUE: {
            if (eceCity->phaseDeJeu.coordCaseDetecte.x + 3 <= NBCOLONNE &&
                eceCity->phaseDeJeu.coordCaseDetecte.y + 3 <= NBLIGNE) {
                al_draw_tinted_scaled_bitmap(eceCity->tabImages[BITMAPTERRAINVAGUE].image,
                                             al_map_rgba(128, 128, 128, 100), 0, 0,
                                             eceCity->tabImages[BITMAPTERRAINVAGUE].longueur,
                                             eceCity->tabImages[BITMAPTERRAINVAGUE].hauteur,
                                             eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x,
                                             eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y,
                                             COTECASE * 3,
                                             COTECASE * 3,
                                             0);
            }
            break;
        }
        case CHATEAUDEAU: {
            if (eceCity->phaseDeJeu.coordCaseDetecte.x + 6 <= NBCOLONNE &&
                eceCity->phaseDeJeu.coordCaseDetecte.y + 4 <= NBLIGNE) {
                al_draw_tinted_scaled_bitmap(eceCity->tabImages[BitmapChateauDeau].image,
                                             al_map_rgba(128, 128, 128, 100), 0,
                                             0,
                                             eceCity->tabImages[BitmapChateauDeau].longueur,
                                             eceCity->tabImages[BitmapChateauDeau].hauteur + 20,
                                             eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x,
                                             eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y,
                                             COTECASE * 6,
                                             COTECASE * 4,
                                             0);
                al_draw_rectangle(
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x,
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y,
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x +
                        COTECASE * 6,
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y +
                        COTECASE * 4,
                        al_map_rgba(0, 200, 200, 100), 2);
            }
            break;
        }
        case CENTRALE: {
            if (eceCity->phaseDeJeu.coordCaseDetecte.x + 6 <= NBCOLONNE &&
                eceCity->phaseDeJeu.coordCaseDetecte.y + 4 <= NBLIGNE) {
                al_draw_tinted_scaled_bitmap(eceCity->tabImages[BitmapCentrale].image, al_map_rgba(128, 128, 128, 100),
                                             0, 0,
                                             eceCity->tabImages[BitmapCentrale].longueur,
                                             eceCity->tabImages[BitmapCentrale].hauteur + 20,
                                             eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x,
                                             eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y,
                                             COTECASE * 6,
                                             COTECASE * 4,
                                             0);
                al_draw_rectangle(
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x,
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y,
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.x +
                        COTECASE * 6,
                        eceCity->matricePlateau[eceCity->phaseDeJeu.coordCaseDetecte.y][eceCity->phaseDeJeu.coordCaseDetecte.x].coord.y +
                        COTECASE * 4,
                        al_map_rgba(200, 200, 0, 100), 2);
            }
            break;
        }
    }
}

void dessinerGrille(EceCity *eceCity) {
    al_draw_filled_rectangle(eceCity->matricePlateau[0][0].coord.x - COTECASE * 2,
                             eceCity->matricePlateau[0][0].coord.y - COTECASE * 2,
                             eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.x + COTECASE * 3,
                             eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.y + COTECASE * 3,
                             al_map_rgb(89, 166, 8));
    for (int i = 0; i < NBLIGNE + 1; ++i) {
        al_draw_line(eceCity->matricePlateau[0][0].coord.x, eceCity->matricePlateau[0][0].coord.y + i * COTECASE,
                     eceCity->matricePlateau[0][0].coord.x + NBCOLONNE * COTECASE,
                     eceCity->matricePlateau[0][0].coord.y + i * COTECASE, al_map_rgb(255, 255, 255), 1);
    }
    for (int i = 0; i < NBCOLONNE + 1; ++i) {
        al_draw_line(eceCity->matricePlateau[0][0].coord.x + i * COTECASE, eceCity->matricePlateau[0][0].coord.y,
                     eceCity->matricePlateau[0][0].coord.x + i * COTECASE,
                     eceCity->matricePlateau[0][0].coord.y + NBLIGNE * COTECASE, al_map_rgb(255, 255, 255), 1);
    }
    dessinerBordureArbres(eceCity);
    for (int i = 0; i < NBLIGNE; ++i) {
        for (int j = 0; j < NBCOLONNE; ++j) {
            if (eceCity->matricePlateau[i][j].construction) {
                if (eceCity->matricePlateau[i][j].type == ARBRE) {
                    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPARBRE].image, 1, 1,
                                          eceCity->tabImages[BITMAPARBRE].longueur,
                                          eceCity->tabImages[BITMAPARBRE].hauteur,
                                          eceCity->matricePlateau[i][j].coord.x - 8,
                                          eceCity->matricePlateau[i][j].coord.y - 15,
                                          COTECASE + 15,
                                          COTECASE + 17,
                                          0);
                } else if (eceCity->matricePlateau[i][j].type == ROUTE) {
                    al_draw_filled_rectangle(eceCity->matricePlateau[i][j].coord.x,
                                             eceCity->matricePlateau[i][j].coord.y,
                                             eceCity->matricePlateau[i][j].coord.x + COTECASE,
                                             eceCity->matricePlateau[i][j].coord.y + COTECASE,
                                             al_map_rgb(128, 128, 128));
                } else if (eceCity->matricePlateau[i][j].type == TERRAINVAGUE) {
                    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPTERRAINVAGUE].image, 0, 0,
                                          eceCity->tabImages[BITMAPTERRAINVAGUE].longueur,
                                          eceCity->tabImages[BITMAPTERRAINVAGUE].hauteur,
                                          eceCity->matricePlateau[i][j].coord.x,
                                          eceCity->matricePlateau[i][j].coord.y,
                                          COTECASE * 3,
                                          COTECASE * 3,
                                          0);
                } else if (eceCity->matricePlateau[i][j].type == CENTRALE) {
                    al_draw_filled_rectangle(eceCity->matricePlateau[i][j].coord.x,
                                             eceCity->matricePlateau[i][j].coord.y,
                                             eceCity->matricePlateau[i][j].coord.x + COTECASE * 6,
                                             eceCity->matricePlateau[i][j].coord.y + COTECASE * 4,
                                             al_map_rgb(128, 128, 128));
                    al_draw_scaled_bitmap(eceCity->tabImages[BitmapCentrale].image, 0, 0,
                                          eceCity->tabImages[BitmapCentrale].longueur,
                                          eceCity->tabImages[BitmapCentrale].hauteur + 20,
                                          eceCity->matricePlateau[i][j].coord.x,
                                          eceCity->matricePlateau[i][j].coord.y,
                                          COTECASE * 6,
                                          COTECASE * 4,
                                          0);
                    al_draw_rectangle(
                            eceCity->matricePlateau[i][j].coord.x,
                            eceCity->matricePlateau[i][j].coord.y,
                            eceCity->matricePlateau[i][j].coord.x +
                            COTECASE * 6,
                            eceCity->matricePlateau[i][j].coord.y +
                            COTECASE * 4,
                            al_map_rgba(200, 200, 0, 100), 2);
                } else if (eceCity->matricePlateau[i][j].type == CHATEAUDEAU) {
                    al_draw_filled_rectangle(eceCity->matricePlateau[i][j].coord.x,
                                             eceCity->matricePlateau[i][j].coord.y,
                                             eceCity->matricePlateau[i][j].coord.x + COTECASE * 6,
                                             eceCity->matricePlateau[i][j].coord.y + COTECASE * 4,
                                             al_map_rgb(128, 128, 128));
                    al_draw_scaled_bitmap(eceCity->tabImages[BitmapChateauDeau].image, 0, 0,
                                          eceCity->tabImages[BitmapChateauDeau].longueur,
                                          eceCity->tabImages[BitmapChateauDeau].hauteur + 20,
                                          eceCity->matricePlateau[i][j].coord.x,
                                          eceCity->matricePlateau[i][j].coord.y,
                                          COTECASE * 6,
                                          COTECASE * 4,
                                          0);
                    al_draw_rectangle(
                            eceCity->matricePlateau[i][j].coord.x,
                            eceCity->matricePlateau[i][j].coord.y,
                            eceCity->matricePlateau[i][j].coord.x +
                            COTECASE * 6,
                            eceCity->matricePlateau[i][j].coord.y +
                            COTECASE * 4,
                            al_map_rgba(0, 200, 200, 100), 2);
                } else if (eceCity->matricePlateau[i][j].type == CABANE) {
                    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPCABANE].image, 0, 0,
                                          eceCity->tabImages[BITMAPCABANE].longueur,
                                          eceCity->tabImages[BITMAPCABANE].hauteur,
                                          eceCity->matricePlateau[i][j].coord.x,
                                          eceCity->matricePlateau[i][j].coord.y,
                                          COTECASE * 3,
                                          COTECASE * 3 + 35,
                                          0);
                } else if (eceCity->matricePlateau[i][j].type == MAISON) {
                    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPMAISON].image, 0, 0,
                                          eceCity->tabImages[BITMAPMAISON].longueur,
                                          eceCity->tabImages[BITMAPMAISON].hauteur,
                                          eceCity->matricePlateau[i][j].coord.x,
                                          eceCity->matricePlateau[i][j].coord.y - 26,
                                          COTECASE * 3,
                                          COTECASE * 3 + 26,
                                          0);
                } else if (eceCity->matricePlateau[i][j].type == IMMEUBLE) {
                    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPIMMEUBLE].image, 0, 0,
                                          eceCity->tabImages[BITMAPIMMEUBLE].longueur,
                                          eceCity->tabImages[BITMAPIMMEUBLE].hauteur,
                                          eceCity->matricePlateau[i][j].coord.x,
                                          eceCity->matricePlateau[i][j].coord.y - 40,
                                          COTECASE * 3,
                                          COTECASE * 3 + 40,
                                          0);
                } else if (eceCity->matricePlateau[i][j].type == GRATTECIEL) {
                    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPGRATTECIEL].image, 0, 0,
                                          eceCity->tabImages[BITMAPGRATTECIEL].longueur,
                                          eceCity->tabImages[BITMAPGRATTECIEL].hauteur,
                                          eceCity->matricePlateau[i][j].coord.x,
                                          eceCity->matricePlateau[i][j].coord.y - 129,
                                          COTECASE * 3,
                                          COTECASE * 3 + 123,
                                          0);
                }
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
}

void dessinerBordureArbres(EceCity *eceCity) {
    for (int k = 1; k < 3; ++k) {
        for (int i = 0; i < NBCOLONNE; ++i) {
            al_draw_scaled_bitmap(eceCity->tabImages[BITMAPARBRE].image, eceCity->tabImages[BITMAPARBRE].coord.x,
                                  eceCity->tabImages[BITMAPARBRE].coord.y, eceCity->tabImages[BITMAPARBRE].longueur,
                                  eceCity->tabImages[BITMAPARBRE].hauteur, eceCity->matricePlateau[0][i].coord.x,
                                  eceCity->matricePlateau[0][i].coord.y - COTECASE * k, COTECASE, COTECASE, 0);
            al_draw_scaled_bitmap(eceCity->tabImages[BITMAPARBRE].image, eceCity->tabImages[BITMAPARBRE].coord.x,
                                  eceCity->tabImages[BITMAPARBRE].coord.y, eceCity->tabImages[BITMAPARBRE].longueur,
                                  eceCity->tabImages[BITMAPARBRE].hauteur,
                                  eceCity->matricePlateau[NBLIGNE - 1][i].coord.x,
                                  eceCity->matricePlateau[NBLIGNE - 1][i].coord.y + COTECASE * k, COTECASE, COTECASE,
                                  0);
        }
        for (int i = 0; i < NBLIGNE; ++i) {
            al_draw_scaled_bitmap(eceCity->tabImages[BITMAPARBRE].image, eceCity->tabImages[BITMAPARBRE].coord.x,
                                  eceCity->tabImages[BITMAPARBRE].coord.y, eceCity->tabImages[BITMAPARBRE].longueur,
                                  eceCity->tabImages[BITMAPARBRE].hauteur,
                                  eceCity->matricePlateau[i][0].coord.x - COTECASE * k,
                                  eceCity->matricePlateau[i][0].coord.y, COTECASE, COTECASE, 0);
            al_draw_scaled_bitmap(eceCity->tabImages[BITMAPARBRE].image, eceCity->tabImages[BITMAPARBRE].coord.x,
                                  eceCity->tabImages[BITMAPARBRE].coord.y, eceCity->tabImages[BITMAPARBRE].longueur,
                                  eceCity->tabImages[BITMAPARBRE].hauteur,
                                  eceCity->matricePlateau[i][NBCOLONNE - 1].coord.x + COTECASE * k,
                                  eceCity->matricePlateau[i][NBCOLONNE - 1].coord.y, COTECASE, COTECASE, 0);
        }
        al_draw_scaled_bitmap(eceCity->tabImages[BITMAPARBRE].image, eceCity->tabImages[BITMAPARBRE].coord.x,
                              eceCity->tabImages[BITMAPARBRE].coord.y, eceCity->tabImages[BITMAPARBRE].longueur,
                              eceCity->tabImages[BITMAPARBRE].hauteur,
                              eceCity->matricePlateau[0][0].coord.x - COTECASE * k,
                              eceCity->matricePlateau[0][0].coord.y - COTECASE * k, COTECASE, COTECASE, 0);
        al_draw_scaled_bitmap(eceCity->tabImages[BITMAPARBRE].image, eceCity->tabImages[BITMAPARBRE].coord.x,
                              eceCity->tabImages[BITMAPARBRE].coord.y, eceCity->tabImages[BITMAPARBRE].longueur,
                              eceCity->tabImages[BITMAPARBRE].hauteur,
                              eceCity->matricePlateau[0][NBCOLONNE - 1].coord.x + COTECASE * k,
                              eceCity->matricePlateau[0][NBCOLONNE - 1].coord.y - COTECASE * k, COTECASE, COTECASE, 0);
        al_draw_scaled_bitmap(eceCity->tabImages[BITMAPARBRE].image, eceCity->tabImages[BITMAPARBRE].coord.x,
                              eceCity->tabImages[BITMAPARBRE].coord.y, eceCity->tabImages[BITMAPARBRE].longueur,
                              eceCity->tabImages[BITMAPARBRE].hauteur,
                              eceCity->matricePlateau[NBLIGNE - 1][0].coord.x - COTECASE * k,
                              eceCity->matricePlateau[NBLIGNE - 1][0].coord.y + COTECASE * k, COTECASE, COTECASE, 0);
        al_draw_scaled_bitmap(eceCity->tabImages[BITMAPARBRE].image, eceCity->tabImages[BITMAPARBRE].coord.x,
                              eceCity->tabImages[BITMAPARBRE].coord.y, eceCity->tabImages[BITMAPARBRE].longueur,
                              eceCity->tabImages[BITMAPARBRE].hauteur,
                              eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.x + COTECASE * k,
                              eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.y + COTECASE * k, COTECASE,
                              COTECASE, 0);
    }
    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPARBRE].image, eceCity->tabImages[BITMAPARBRE].coord.x,
                          eceCity->tabImages[BITMAPARBRE].coord.y, eceCity->tabImages[BITMAPARBRE].longueur,
                          eceCity->tabImages[BITMAPARBRE].hauteur,
                          eceCity->matricePlateau[0][0].coord.x - COTECASE * 2,
                          eceCity->matricePlateau[0][0].coord.y - COTECASE, COTECASE, COTECASE, 0);
    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPARBRE].image, eceCity->tabImages[BITMAPARBRE].coord.x,
                          eceCity->tabImages[BITMAPARBRE].coord.y, eceCity->tabImages[BITMAPARBRE].longueur,
                          eceCity->tabImages[BITMAPARBRE].hauteur,
                          eceCity->matricePlateau[0][NBCOLONNE - 1].coord.x + COTECASE * 2,
                          eceCity->matricePlateau[0][NBCOLONNE - 1].coord.y - COTECASE, COTECASE, COTECASE, 0);
    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPARBRE].image, eceCity->tabImages[BITMAPARBRE].coord.x,
                          eceCity->tabImages[BITMAPARBRE].coord.y, eceCity->tabImages[BITMAPARBRE].longueur,
                          eceCity->tabImages[BITMAPARBRE].hauteur,
                          eceCity->matricePlateau[NBLIGNE - 1][0].coord.x - COTECASE * 2,
                          eceCity->matricePlateau[NBLIGNE - 1][0].coord.y + COTECASE, COTECASE, COTECASE, 0);
    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPARBRE].image, eceCity->tabImages[BITMAPARBRE].coord.x,
                          eceCity->tabImages[BITMAPARBRE].coord.y, eceCity->tabImages[BITMAPARBRE].longueur,
                          eceCity->tabImages[BITMAPARBRE].hauteur,
                          eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.x + COTECASE * 2,
                          eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.y + COTECASE, COTECASE, COTECASE,
                          0);
    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPARBRE].image, eceCity->tabImages[BITMAPARBRE].coord.x,
                          eceCity->tabImages[BITMAPARBRE].coord.y, eceCity->tabImages[BITMAPARBRE].longueur,
                          eceCity->tabImages[BITMAPARBRE].hauteur,
                          eceCity->matricePlateau[0][0].coord.x - COTECASE,
                          eceCity->matricePlateau[0][0].coord.y - COTECASE * 2, COTECASE, COTECASE, 0);
    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPARBRE].image, eceCity->tabImages[BITMAPARBRE].coord.x,
                          eceCity->tabImages[BITMAPARBRE].coord.y, eceCity->tabImages[BITMAPARBRE].longueur,
                          eceCity->tabImages[BITMAPARBRE].hauteur,
                          eceCity->matricePlateau[0][NBCOLONNE - 1].coord.x + COTECASE,
                          eceCity->matricePlateau[0][NBCOLONNE - 1].coord.y - COTECASE * 2, COTECASE, COTECASE, 0);
    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPARBRE].image, eceCity->tabImages[BITMAPARBRE].coord.x,
                          eceCity->tabImages[BITMAPARBRE].coord.y, eceCity->tabImages[BITMAPARBRE].longueur,
                          eceCity->tabImages[BITMAPARBRE].hauteur,
                          eceCity->matricePlateau[NBLIGNE - 1][0].coord.x - COTECASE,
                          eceCity->matricePlateau[NBLIGNE - 1][0].coord.y + COTECASE * 2, COTECASE, COTECASE, 0);
    al_draw_scaled_bitmap(eceCity->tabImages[BITMAPARBRE].image, eceCity->tabImages[BITMAPARBRE].coord.x,
                          eceCity->tabImages[BITMAPARBRE].coord.y, eceCity->tabImages[BITMAPARBRE].longueur,
                          eceCity->tabImages[BITMAPARBRE].hauteur,
                          eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.x + COTECASE,
                          eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.y + COTECASE * 2, COTECASE,
                          COTECASE, 0);
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
        if (eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].etatParticulier == false) {
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
    if (eceCity->phaseDeJeu.actuelle == JEU) {
        if (eceCity->tabBoutons[JEU][OUTIL].etatParticulier) {
            al_draw_scaled_bitmap(eceCity->tabImages[BITMAPCONSTROUTE].image,
                                  eceCity->tabImages[BITMAPCONSTROUTE].coord.x,
                                  eceCity->tabImages[BITMAPCONSTROUTE].coord.y,
                                  eceCity->tabImages[BITMAPCONSTROUTE].longueur,
                                  eceCity->tabImages[BITMAPCONSTROUTE].hauteur,
                                  eceCity->tabBoutons[JEU][CONSTRUIREROUTE].coord.x,
                                  eceCity->tabBoutons[JEU][CONSTRUIREROUTE].coord.y - 12,
                                  eceCity->tabBoutons[JEU][CONSTRUIREROUTE].longueur - 2,
                                  eceCity->tabBoutons[JEU][CONSTRUIREROUTE].hauteur, 0);
            al_draw_scaled_bitmap(eceCity->tabImages[BITMAPCONSTMAISON].image,
                                  eceCity->tabImages[BITMAPCONSTMAISON].coord.x,
                                  eceCity->tabImages[BITMAPCONSTMAISON].coord.y,
                                  eceCity->tabImages[BITMAPCONSTMAISON].longueur,
                                  eceCity->tabImages[BITMAPCONSTMAISON].hauteur,
                                  eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].coord.x,
                                  eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].coord.y - 5,
                                  eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].longueur,
                                  eceCity->tabBoutons[JEU][CONSTRUIREBATIMENT].hauteur - 2, 0);
            al_draw_scaled_bitmap(eceCity->tabImages[BITMAPCONSTCENTRALE].image,
                                  eceCity->tabImages[BITMAPCONSTCENTRALE].coord.x,
                                  eceCity->tabImages[BITMAPCONSTCENTRALE].coord.y,
                                  eceCity->tabImages[BITMAPCONSTCENTRALE].longueur,
                                  eceCity->tabImages[BITMAPCONSTCENTRALE].hauteur,
                                  eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].coord.x + 3,
                                  eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].coord.y,
                                  eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].longueur - 8,
                                  eceCity->tabBoutons[JEU][CONSTRUIRECENTRALE].hauteur, 0);

            al_draw_scaled_bitmap(eceCity->tabImages[BITMAPCONSTCHATEAUDEAU].image,
                                  eceCity->tabImages[BITMAPCONSTCHATEAUDEAU].coord.x,
                                  eceCity->tabImages[BITMAPCONSTCHATEAUDEAU].coord.y,
                                  eceCity->tabImages[BITMAPCONSTCHATEAUDEAU].longueur,
                                  eceCity->tabImages[BITMAPCONSTCHATEAUDEAU].hauteur,
                                  eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].coord.x,
                                  eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].coord.y + 3,
                                  eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].longueur,
                                  eceCity->tabBoutons[JEU][CONSTRUIRECHATEAUDEAU].hauteur - 8, 0);
        }
        al_draw_scaled_bitmap(eceCity->tabImages[BITMAPOUTIL].image, eceCity->tabImages[BITMAPCONSTROUTE].coord.x,
                              eceCity->tabImages[BITMAPOUTIL].coord.y,
                              eceCity->tabImages[BITMAPOUTIL].longueur,
                              eceCity->tabImages[BITMAPOUTIL].hauteur,
                              eceCity->tabBoutons[JEU][OUTIL].coord.x,
                              eceCity->tabBoutons[JEU][OUTIL].coord.y,
                              eceCity->tabBoutons[JEU][OUTIL].longueur,
                              eceCity->tabBoutons[JEU][OUTIL].hauteur, 0);
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
        if (eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].nom != NULL) {
            al_draw_text(police, al_map_rgb(4 * al_get_timer_count(eceCity->timer), 0, 0),
                         eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.x +
                         (eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].longueur /
                          2),
                         eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.y +
                         (eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].hauteur /
                          2) -
                         (al_get_font_line_height(police) / 2), ALLEGRO_ALIGN_CENTER,
                         eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].nom);
        }
        al_flip_display();
    }
}