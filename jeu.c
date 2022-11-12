#include "jeu.h"

void BouclePrincipale(EceCity* eceCity){
    while (!eceCity->end){
        switch (eceCity->phaseDeJeu) {
            case ACCEUIL:{

                break;
            }
            case JEU:{

                break;
            }
            case PARAMETRES:{

                break;
            }
            default:{
                break;
            };
        }
    }
}

bool creerBatiment(Coord coord){
    EceCity eceCity;
    bool verifCasesVide=true;
    for(int i=0 ; i<3 ;i++){
        for(int j=0; j<3; j++){
            if(eceCity.matricePlateau[coord.x-1+i][coord.x-1+j].type==VIDE || eceCity.matricePlateau[coord.x-1+i][coord.x-1+j].type==ARBRE){
                verifCasesVide=false;
                eceCity.matricePlateau[coord.x-1+i][coord.x-1+j].type=MAISON;
            }
        }
        return verifCasesVide;
    }
}