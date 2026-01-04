#include <stdio.h>
#include <stdlib.h>
#include "bot.h"

#define MEM_MAX 100

static MemoireCarte mem[MEM_MAX];
static int nbMem = 0;

// Vérifie si une position est encore jouable 
int positionValide(int pos, int P[], int tailleP)
{
    for (int i = 0; i < tailleP; i++)
        if (P[i] == pos)
            return 1;
    return 0;
}

// Ajoute ou met à jour la mémoire 
void memoriserCarte(int pos, int val)
{
    if (val <= 0) return; // ignore Joker et cartes retirées

    for (int i = 0; i < nbMem; i++) {
        if (mem[i].position == pos) {
            mem[i].valeur = val;
            return;
        }
    }

    if (nbMem < MEM_MAX) {
        mem[nbMem].position = pos;
        mem[nbMem].valeur = val;
        nbMem++;
    }
}

// Supprime de la mémoire les cartes retirées 
void nettoyerMemoire(int P[], int tailleP)
{
    int i = 0;
    while (i < nbMem) {
        if (!positionValide(mem[i].position, P, tailleP)) {
            mem[i] = mem[nbMem - 1];
            nbMem--;
        } else {
            i++;
        }
    }
}

// Recherche une paire connue 
int chercherPaire(int *i1, int *i2)
{
    for (int i = 0; i < nbMem; i++) {
        for (int j = i + 1; j < nbMem; j++) {
            if (mem[i].valeur == mem[j].valeur) {
                *i1 = i;
                *i2 = j;
                return 1;
            }
        }
    }
    return 0;
}

// Choix aléatoire d'une position inconnue si possible 
int choisirPositionAleatoire(int P[], int tailleP)
{
    return P[rand() % tailleP];
}

// Tour du bot 
void tourBot(int T[], int P[], int *tailleP, Joueur *bot)
{
    int pos1, pos2;
    int i1, i2;

    nettoyerMemoire(P, *tailleP);

    if (chercherPaire(&i1, &i2)) {
        pos1 = mem[i1].position;
        pos2 = mem[i2].position;
    } else {
        pos1 = choisirPositionAleatoire(P, *tailleP);
        do {
            pos2 = choisirPositionAleatoire(P, *tailleP);
        } while (pos2 == pos1);
    }

    printf("\nBot joue %d et %d\n", pos1, pos2);

    int v1 = T[pos1];
    int v2 = T[pos2];

    // Gestion Joker 
    if (v1 == 0 || v2 == 0) {
        printf("Bot a tiré le Joker\n");
        jokgest(T, (v1 == 0 ? pos1 : pos2), P, *tailleP);
        return;
    }

    // Mémorisation 
    memoriserCarte(pos1, v1);
    memoriserCarte(pos2, v2);

    // Paire trouvée 
    if (v1 == v2) {
        printf("Paire trouvée par le bot !\n");
        bot->score++;

        retirerCarte(T, P, tailleP, pos1);
        retirerCarte(T, P, tailleP, pos2);

        nettoyerMemoire(P, *tailleP);
    }
}