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
    struct deck deck;
    int montant;
    
};

enum couleurs {
    Carreau=1,
    Coeur=2,
    Trefle=3,
    Pique=4
};

struct deck creer_deck(){
    struct deck deck;
    for(int i = 0;i < 52;i++){
        deck.liste[i].valeur = i%13+1;
    }
    return deck;
}
int main() {
    struct joueur joueur1;
    struct deck deck1 = creer_deck();
    joueur1.deck = deck1;


    return 0;
}