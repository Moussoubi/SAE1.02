#ifndef BOT_H
#define BOT_H

#include "jeu.h"

typedef struct {
    int position;
    int valeur;
} MemoireCarte;

void tourBot(int T[], int P[], int *tailleP, Joueur *bot);

#endif