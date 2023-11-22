#include <stdio.h>
#include <stdlib.h>

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
    int compteur_couleur = 0;
    for(int i = 0;i < 52;i++){
        if(i%13+1 == 1){
            // Sachant que la couleur est comrpise entre 1 et 4, on incrémente
            // le compteur de couleur à chaque fois que l'on a 13 cartes de la même couleur, c'est à dire
            // à chaque fois que i%13+1 == 1.
            compteur_couleur++;
        }
        deck.liste[i].valeur = i%13+1;
        deck.liste[i].couleur = compteur_couleur;
    }
    // On mélange le deck
    for(int i = 0;i < 52;i++){
        int random = rand()%52;
        struct carte carte_temp = deck.liste[i];
        deck.liste[i] = deck.liste[random];
        deck.liste[random] = carte_temp;
    }

    return deck;
}

struct carte tirage_carte(struct deck deck){
    int random = rand()%52;
    return deck.liste[random];
}

void menu_joueur(){
    int ok = 0;

    while(!ok){
        printf("1. Hit\n");
        printf("2. Stand\n");
        printf("3. Double\n");
        printf("4. Surrend\n");
        printf("Votre choix : ");
        int choix;
        scanf("%d",&choix);
        if(choix >= 1 && choix <= 4){
            ok = 1;
        }
    }
}
int main() {
    struct joueur joueur1;
    struct deck deck1 = creer_deck();
    joueur1.deck = deck1;


    return 0;
}