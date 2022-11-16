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
    al_clear_to_color(al_map_rgb(89, 166, 8));
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

void faireClignoterBouton(EceCity *eceCity) {
    al_draw_rectangle(
            eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.x,
            eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.y,
            eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.x +
            eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].longueur,
            eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].coord.y +
            eceCity->tabBoutons[eceCity->phaseDeJeu.actuelle][eceCity->phaseDeJeu.boutonDetecteActuel].hauteur,
            al_map_rgb(4 * al_get_timer_count(eceCity->timer),0,0),
            7);
    al_flip_display();
}