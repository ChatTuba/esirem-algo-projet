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
    struct carte *liste;
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


void initialisation(void){
    // creaction de la main vide de la banque et du joueur
    struct joueur banque = {{{0,0}},0};
    struct joueur joueur = {{{0,0}},0};
    creer_deck();
}

struct carte tirage_carte(struct deck deck){
    int random = rand()%52;
    return deck.liste[random];
}
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
    }
}

void valeur_main(struct joueur joueur){
    int deck[]= creer_deck();
    int taille = sizeof(deck[]);
    for (int = 0; i<taille; i++){
        if (joueur.deck.carte.valeur_carte == As){
            joueur.montant += 1;
        }
        else if (joueur.deck.carte.valeur_carte == Deux){
            joueur.montant += 2;
        }
        else if (joueur.deck.carte.valeur_carte == Trois){
            joueur.montant += 3;
        }
        else if (joueur.deck.carte.valeur_carte == Quatre){
            joueur.montant += 4;
        }
        else if (joueur.deck.carte.valeur_carte == Cinq){
            joueur.montant += 5;
        }
        else if (joueur.deck.carte.valeur_carte == Six){
            joueur.montant += 6;
        }
        else if (joueur.deck.carte.valeur_carte == Sept){
            joueur.montant += 7;
        }
        else if (joueur.deck.carte.valeur_carte == Huit){
            joueur.montant += 8;
        }
        else if (joueur.deck.carte.valeur_carte == Neuf){
            joueur.montant += 9;
        }
        else if (joueur.deck.carte.valeur_carte == Dix){
            joueur.montant += 10;
        }
        else if (joueur.deck.carte.valeur_carte ==  Valet){
            joueur.montant += 11;
        }
        else if (joueur.deck.carte.valeur_carte == Dame){
            joueur.montant += 12;
        }
        else if (joueur.deck.carte.valeur_carte == Roi){
            joueur.montant += 13;
        }
    }
    printf("le montant de la main du joueur est %d", joueur.montant);
}

int main() {

    struct joueur joueur1;
    struct deck deck1 = creer_deck();
    //joueur1.deck = deck1;


    //struct joueur joueur1;
    //struct deck deck1 = creer_deck();
    //joueur1.deck = deck1;
    /*for (int i=0;i<(sizeof(D.liste)/sizeof(D.liste));i++){
        afficher_carte(D.liste[i]);*/


    return 0;
}