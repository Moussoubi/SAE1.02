#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"
#include "bot.h"

int main()
{
    srand(time(NULL));

    int L = 3, C = 7;
    int n = (L * C - 1) / 2;
    int tailleTot = L * C;

    int T[MAX];
    int P[MAX];
    int tailleP = tailleTot;

    Joueur j1 = {"Joueur", 0, 0};
    Joueur bot = {"Bot", 0, 1};

    posini(P, tailleTot);
    poschange(P, tailleTot);
    gencartes(T, P, n);

    while (tailleP > 1) {
        tourHumain(T, P, &tailleP, &j1, L, C);
        if (tailleP <= 1) break;
        tourBot(T, P, &tailleP, &bot);
    }

    printf("\nScores finaux :\n");
    printf("%s : %d\n", j1.pseudo, j1.score);
    printf("%s : %d\n", bot.pseudo, bot.score);

    return 0;
}