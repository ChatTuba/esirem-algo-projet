#include <stdio.h>
enum couleurs{
    Carreau=1,
    Coeur=2,
    Trefle=3,
    Pique=4
};

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
struct deck{// structure aussi bien pour une main que pour le deck(pioche)
    struct carte *liste;
};

struct joueur{
    /// structure pour la main des joueurs ainsi que leur montant 
    struct deck deck;
    int montant;
    
};






int main() {
    //printf("Bob Bob!\n");
    return 0;
}