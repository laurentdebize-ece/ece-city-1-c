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

void affichageRegles(EceCity *eceCity) {
    affichageBitmapDeFond(eceCity, BITMAPCHOIXDUMODE);
    affichageBouton(eceCity, eceCity->ecrire.simsCityPoliceMoyen);
}

void affichageJeu(EceCity *eceCity) {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    dessinerGrille(eceCity);
}

void deplacerPlateau(EceCity*eceCity){
    if (eceCity->tabTouches[BAS]){
        if (eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.y + (HAUTEURCASE * 2) >=
            eceCity->display.hauteur) {
            for (int i = 0; i < NBLIGNE; ++i) {
                for (int j = 0; j < NBCOLONNE; ++j) {
                    eceCity->matricePlateau[i][j].coord.y -= VITESSE;
                }
            }
        }
        eceCity->changementAffichage = true;
    }
    if (eceCity->tabTouches[HAUT]){
        if (eceCity->matricePlateau[0][0].coord.y - HAUTEURCASE/2 <= 0) {
            for (int i = 0; i < NBLIGNE; ++i) {
                for (int j = 0; j < NBCOLONNE; ++j) {
                    eceCity->matricePlateau[i][j].coord.y += VITESSE;
                }
            }
        }
        eceCity->changementAffichage = true;
    }
    if (eceCity->tabTouches[GAUCHE]){
        if (eceCity->matricePlateau[0][0].coord.x - LONGUEURCASE/2 <= 0) {
            for (int i = 0; i < NBLIGNE; ++i) {
                for (int j = 0; j < NBCOLONNE; ++j) {
                    eceCity->matricePlateau[i][j].coord.x += VITESSE;
                }
            }
        }
        eceCity->changementAffichage = true;
    }
    if (eceCity->tabTouches[DROITE]){
        if (eceCity->matricePlateau[NBLIGNE - 1][NBCOLONNE - 1].coord.x + (LONGUEURCASE * 2) >=
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
    for (int i = 0; i < NBLIGNE; ++i) {
        for (int j = 0; j < NBCOLONNE; ++j) {
            switch (eceCity->matricePlateau[i][j].type) {
                case VIDE: {
                    al_draw_filled_rectangle(eceCity->matricePlateau[i][j].coord.x,
                                             eceCity->matricePlateau[i][j].coord.y,
                                             eceCity->matricePlateau[i][j].coord.x + LONGUEURCASE,
                                             eceCity->matricePlateau[i][j].coord.y + HAUTEURCASE,
                                             al_map_rgb(89, 166, 8));
                    break;
                }
                case ARBRE: {
                    al_draw_filled_rectangle(eceCity->matricePlateau[i][j].coord.x,
                                             eceCity->matricePlateau[i][j].coord.y,
                                             eceCity->matricePlateau[i][j].coord.x + LONGUEURCASE,
                                             eceCity->matricePlateau[i][j].coord.y + HAUTEURCASE,
                                             al_map_rgb(128, 0, 0));
                    break;
                }
            }
        }
    }
    for (int i = 0; i < NBLIGNE + 1; ++i) {
        al_draw_line(eceCity->matricePlateau[0][0].coord.x, eceCity->matricePlateau[0][0].coord.y + i * HAUTEURCASE,
                     eceCity->matricePlateau[0][0].coord.x + NBCOLONNE * LONGUEURCASE,
                     eceCity->matricePlateau[0][0].coord.y + i * HAUTEURCASE, al_map_rgb(255, 255, 255), 2);
    }
    for (int i = 0; i < NBCOLONNE + 1; ++i) {
        al_draw_line(eceCity->matricePlateau[0][0].coord.x + i * LONGUEURCASE, eceCity->matricePlateau[0][0].coord.y,
                     eceCity->matricePlateau[0][0].coord.x + i * LONGUEURCASE, eceCity->matricePlateau[0][0].coord.y + NBLIGNE * HAUTEURCASE, al_map_rgb(255, 255, 255), 2);
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
        case REGLES: {
            nbBouton = NBDEBOUTONREGLES;
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

void faireClignoterBouton(EceCity *eceCity) {
    al_draw_rectangle(
            eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.x,
            eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.y,
            eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.x +
            eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].longueur,
            eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.y +
            eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].hauteur,
            al_map_rgb(4 * al_get_timer_count(eceCity->timer), 0, 0),
            7);
    al_flip_display();
}