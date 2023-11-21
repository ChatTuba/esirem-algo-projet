#include <stdio.h>
struct carte{
    /// cette structure définie les cartes de jeu
    int valeur;
    char couleur;
};

struct joueur{
    /// structure pour la main des joueurs ainsi que leur montant 
    struct deck deck;
    int montant;
    
};

enum couleurs {
    Carreau=1,
    Coeur=2,
    Trefle=3,
    Pique=4
};


struct deck{
    struct carte *liste;
};

int main() {
    printf("Bob Bob!\n");
    return 0;
}
