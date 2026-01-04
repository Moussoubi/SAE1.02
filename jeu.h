#ifndef JEU_H
#define JEU_H

#define MAX 200

typedef struct {
    char pseudo[20];
    int score;
    int estBot;
} Joueur;

// Initialisation et génération 
void posini(int P[], int taille);
void poschange(int P[], int taille);
void gencartes(int T[], int P[], int n);

// Affichage 
void affichCache(int P[], int tailleP, int L, int C);

// Gestion du jeu 
void gestjoker(int T[], int posJoker, int P[], int tailleP);
void retirerCarte(int T[], int P[], int *tailleP, int pos);

// Tours 
void tourHumain(int T[], int P[], int *tailleP, Joueur *j, int L, int C);

#endif