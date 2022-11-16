#include "affichage.h"
#include "jeu.h"

void affichageAcceuil(EceCity *eceCity) {
    affichageBitmapDeFond(eceCity, BITMAPACCEUIL);
    affichageBouton(eceCity);
}

void affichageChoixDuMode(EceCity *eceCity) {

}

void affichageRegles(EceCity *eceCity) {

}

void affichageJeu(EceCity *eceCity) {

}

void affichageParametres(EceCity *eceCity) {

}

void affichageBouton(EceCity *eceCity) {
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
                                 al_map_rgb(0, 0, 0));
        /*al_draw_textf(eceCity->ecrire.simsCityPoliceMoyen, eceCity->ecrire.couleurDuTexte,
                      eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.x -
                      (eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].longueur / 2) -
                      (al_get_text_width(eceCity->ecrire.simsCityPoliceMoyen,
                                         eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].nom) / 2),
                      eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].coord.y -
                      (eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].hauteur / 2), 0, "%s",
                      eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][i].nom);*/
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
            al_map_rgb(3 * al_get_timer_count(eceCity->timer), 0, 0),
            5);
    al_flip_display();
}