#include <stdio.h>
#include <stdlib.h>
#include "bot.h"

static MemoireCarte mem[100];
static int nbMem = 0;

/* Cherche une paire connue */
int chercherPaire()
{
    for (int i = 0; i < nbMem; i++)
        for (int j = i + 1; j < nbMem; j++)
            if (mem[i].valeur == mem[j].valeur)
                return i;
    return -1;
}

/* Tour du bot */
void tourBot(int T[], int P[], int *tailleP, Joueur *bot)
{
    int pos1, pos2;
    int idx = chercherPaire();

    if (idx != -1) {
        pos1 = mem[idx].position;
        pos2 = mem[idx + 1].position;
    } else {
        pos1 = P[rand() % (*tailleP)];
        pos2 = P[rand() % (*tailleP)];
        while (pos2 == pos1)
            pos2 = P[rand() % (*tailleP)];
    }

    printf("\nBot joue %d et %d\n", pos1, pos2);

    int v1 = T[pos1];
    int v2 = T[pos2];

    if (v1 == 0 || v2 == 0) {
        printf("Bot a tiré le Joker\n");
        jokgest(T, (v1 == 0 ? pos1 : pos2), P, *tailleP);
        return;
    }

    if (v1 == v2) {
        printf("Paire trouvée par le bot !\n");
        bot->score++;
        retirerCarte(T, P, tailleP, pos1);
        retirerCarte(T, P, tailleP, pos2);
    } else {
        mem[nbMem++] = (MemoireCarte){pos1, v1};
        mem[nbMem++] = (MemoireCarte){pos2, v2};
    }
}