 #include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {

    int choix;

        printf(" MENU PRINCIPAL \n");
        printf("\n 1 - Memoryx 1 joueur \n ");
        printf(" 2 - Memoryx 1 Joueur 1 Bot \n ");
        printf(" 3 - Mémoryx 2 joueurs \n ");
        printf(" 4 - Quitter le jeu \n ");

        
         while (choix < 1 || choix > 4){
            printf("Entrer votre choix : ");
            scanf("%d", &choix);
        }

        int score;
        switch (choix) {
            case 1:
                
                break;
            case 2:
               
                break;
            case 3:
                
                break;
            case 4:
                printf("Fin de la session.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }

    return 0;
}