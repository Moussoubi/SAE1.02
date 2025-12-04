#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {

    int choix = 0;

        printf(" MENU PRINCIPAL \n");
        printf("\n 1 - Memoryx 1 joueur \n ");
        printf(" 2 - Memoryx 1 Joueur 1 Bot \n ");
        printf(" 3 - Mémoryx 2 joueurs \n ");
        printf(" 4 - Quitter le jeu \n ");
        printf("Veuillez faire votre choix :");
        choix = saisie();
        
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
         }while (choix != 4)
       

    return 0;
   
} 