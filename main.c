#include <stdio.h>
#include <stdlib.h>

enum couleurs {
    Carreau=1,
    Coeur=2,
    Trefle=3,
    Pique=4
};

enum valeur_carte{
    As=1,
    Deux=2,
    Trois=3,
    Quatre=4,
    Cinq=5,
    Six=6,
    Sept=7,
    Huit=8,
    Neuf=9,
    Dix=10,
    Valet=11,
    Dame=12,
    Roi=13
};

enum choix_joueur{
    Hit=1,
    Stand=2,
    Double=3,
    Surrend=4
};

struct carte{
    /// cette structure définie les cartes de jeu
    enum valeur_carte valeur;
    enum couleurs couleur;
};
//struct carte DC = {Dame,Carreau};
//struct carte RP={Roi,Pique};
//struct carte huitT={Huit,Trefle};

struct deck{
    struct carte carte_actuelle;
    struct deck *next;
};

//struct deck deck12 = {&DC, &RP, &huitT}; issou

void afficher_carte(struct carte c){
    if (c.valeur<=10){
        printf("%d",c.valeur);
    }
    if(c.valeur==11){
        printf("%s"," Valet");
    }
    if(c.valeur==12){
        printf("%s"," Dame");
    }
    if(c.valeur==13){
        printf("%s"," Roi");
    }
    if (c.couleur==Carreau){
        printf("%s","Carreau");
    }
    if (c.couleur==Coeur){
        printf("%s","Coeur");
    }
    if (c.couleur==Trefle){
        printf("%s","Trefle");
    }
    if (c.couleur==Pique){
        printf("%s","Pique");
    }
}

struct joueur{
    /// structure pour la main des joueurs ainsi que leur montant 
    struct deck main;
    int montant;
    
};



struct deck creer_deck(){
    struct deck deck;
    struct carte carte_temporaire;

    int compteur_couleur = 1;

    carte_temporaire.valeur = 1;
    carte_temporaire.couleur = 1;

    deck.carte_actuelle = carte_temporaire;
    struct deck deck_temporaire;

    for(int i = 1;i <= 52;i++) {
        if (i % 13 + 1 == 1) {
            printf("boucle couleur\n");
            // Sachant que la couleur est comprise entre 1 et 4, on incrémente
            // le compteur de couleur à chaque fois que l'on a 13 cartes de la même couleur, c'est à dire
            // à chaque fois que i%13+1 == 1.
            compteur_couleur++;
        }
        int valeur = i % 13 + 1;

        carte_temporaire.valeur = valeur;
        carte_temporaire.couleur = compteur_couleur;

        deck_temporaire.carte_actuelle = carte_temporaire;

        deck.next = &deck_temporaire;
        deck = deck_temporaire;
    }
    return deck;
}


void initialisation(void){
    // creaction de la main vide de la banque et du joueur
    struct joueur banque = {{{0,0}},0};
    struct joueur joueur = {{{0,0}},0};
    creer_deck();
}

struct carte tirage_carte(struct deck deck){
    int random = rand()%52;
    return deck.liste[random];

struct carte tirage_carte(struct deck deck){
    int random = rand()%52;
    struct carte carte_tiree = deck.liste[random];
    deck.liste[random].valeur = 0;
    deck.liste[random].couleur = 0;

    return carte_tiree;

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
        else{
            printf("merci de choisir un chiffre en entre 1 et 4! \n");
        }
    }
}


int main() {

    struct joueur joueur1;
    struct deck deck1 = creer_deck();
    joueur1.deck = deck1;


    //struct joueur joueur1;
    //struct deck deck1 = creer_deck();
    //joueur1.deck = deck1;
    /*for (int i=0;i<(sizeof(D.liste)/sizeof(D.liste));i++){
        afficher_carte(D.liste[i]);*/


    return 0;
}