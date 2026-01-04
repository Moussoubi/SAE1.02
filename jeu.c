#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "jeu.h"

// Initialisation de P 
void posini(int P[], int taille)
{
    for (int i = 0; i < taille; i++)
        P[i] = i;
}

// Mélange de P 
void poschange(int P[], int taille)
{
    for (int i = 0; i < taille; i++) {
        int j = rand() % taille;
        int tmp = P[i];
        P[i] = P[j];
        P[j] = tmp;
    }
}

// Génération des cartes 
void gencartes(int T[], int P[], int n)
{
    T[P[0]] = 0; // Joker
    int idx = 1;

    for (int val = 1; val <= n; val++) {
        T[P[idx++]] = val;
        T[P[idx++]] = val;
    }
}

// Affichage faces cachées 
void affichCache(int P[], int tailleP, int L, int C)
{
    int present[MAX] = {0};

    for (int i = 0; i < tailleP; i++)
        present[P[i]] = 1;

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            int k = i * C + j;
            if (present[k])
                printf("%2d ", k);
            else
                printf("   ");
        }
        printf("\n");
    }
}

// Gestion du Joker 
void gestjoker(int T[], int posJoker, int P[], int tailleP)
{
    int r = rand() % tailleP;
    int autre = P[r];

    int tmp = T[posJoker];
    T[posJoker] = T[autre];
    T[autre] = tmp;
}

// Retirer une carte 
void retirerCarte(int T[], int P[], int *tailleP, int pos)
{
    T[pos] = -1;

    for (int i = 0; i < *tailleP; i++) {
        if (P[i] == pos) {
            P[i] = P[*tailleP - 1];
            (*tailleP)--;
            return;
        }
    }
}

// Tour joueur humain 
void tourHumain(int T[], int P[], int *tailleP, Joueur *j, int L, int C)
{
    int pos1, pos2;

    affichCache(P, *tailleP, L, C);

    printf("%s - Choix 1 : ", j->pseudo);
    scanf("%d", &pos1);
    printf("Carte : %d\n", T[pos1]);

    if (T[pos1] == 0) {
        printf("Joker !\n");
        gestjoker(T, pos1, P, *tailleP);
        return;
    }

    printf("Choix 2 : ");
    scanf("%d", &pos2);
    printf("Carte : %d\n", T[pos2]);

    if (T[pos2] == 0) {
        printf("Joker !\n");
        gestjoker(T, pos2, P, *tailleP);
        return;
    }

    if (T[pos1] == T[pos2]) {
        printf("Paire trouvée !\n");
        j->score++;
        retirerCarte(T, P, tailleP, pos1);
        retirerCarte(T, P, tailleP, pos2);
    } else {
        sleep(2);
    }
}