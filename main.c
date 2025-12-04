#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int choix() {
    int x;
    int ok;

    do {
        printf("Veuillez faire un choix entre 1 et 4 : ");
        ok = scanf("%d", &x); 
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        if (ok == 0 || x < 1 || x > 4) {
            printf("Erreur : veuillez entrer un nombre entier entre 1 et 4 !\n");
            ok = 0; // Force la continuité de la boucle
        } else {
            ok = 1; // La boucle s'arrêtera
        }

    } while (ok == 0); 
    
    return x;
}


int main() {

    int choix = 0;

        printf(" MENU PRINCIPAL \n");
        printf("\n 1 - Memoryx 1 joueur \n ");
        printf(" 2 - Memoryx 1 Joueur 1 Bot \n ");
        printf(" 3 - Mémoryx 2 joueurs \n ");
        printf(" 4 - Quitter le jeu \n ");
        choix = choix();
        
            switch (choix) 
            {
                case 1:
                    printf("Mode 1 joueur selectionné.\n");
                    break;
                case 2:
                
                    break;
                case 3:
                    
                    break;
                case 4:
                    printf("Fin de la session.\n");
                    break;
                default:
                    break;
            }
         while (choix != 4);
       

    return 0;
   
} 