#include <stdio.h>
enum choix_joueur{
    Hit=1,
    Stand=2,
    Double=3,
    Surrend=4
};
struct carte{
    /// cette structure définie les cartes de jeu
    int valeur;
    char couleur;
};

struct deck{
    struct carte *liste;
};

struct joueur{
    /// structure pour la main des joueurs ainsi que leur montant 
    struct deck main;
    int montant;
    
};

enum couleurs {
    Carreau=1,
    Coeur=2,
    Trefle=3,
    Pique=4
};

void initialisation(void){
    struct joueur banque{{{0,}},0}
    struct joueur joueur;
    creer_deck();
}

int main() {
    printf("Bob Bob!\n");
    return 0;
}