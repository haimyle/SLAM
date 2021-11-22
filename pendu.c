#include <stdio.h> //LE Hai My SLAM1 2021
#include <ctype.h>

int main() {
    printf("[DEBUG] Avant : 'a', Après : '%c' ", toupper('a'));
    int tailleDuMot;
    char valideMot,nouvellePartie;
    printf("Bienvenue dans le jeu du Pendu !\n");
    do{

        printf("Joueur 1 : Saisissez la taille de votre mot: ");
        scanf("%d",&tailleDuMot);

        char motATrouver[tailleDuMot];
        char motEnCours[tailleDuMot];
        do {
            printf("Saisissez votre mot (carractère par carractère) \n");
            for (int i = 0; i < tailleDuMot; ++i) {
                getchar();

                printf("--> ");

                scanf("%c",&motATrouver[i]);
                motATrouver[i] = toupper(motATrouver[i]);
                if(i == 0 || i == tailleDuMot -1){
                    motEnCours[i] = motATrouver[i];
                }else{
                    motEnCours[i] = '_';
                }
            }
            printf("Vote mot a trouver est : ");
            for (int i = 0; i < tailleDuMot; ++i) {
                printf("%c",motATrouver[i]);
            }
            getchar();
            printf("\n Etes vous d'accord ? [O,N]: ");
            scanf("%c",&valideMot);
        } while (valideMot != 'O' && valideMot != 'o');
        //system("clear");
        printf("La partie commence ! \n");
        int estTrouve;
        int nbCoupRestant = 7;
        char proposition;
        int lettreExiste;
        do{
            estTrouve = 1;
            lettreExiste = 0;

            printf("le mot a trouver : ");
            for (int i = 0; i < tailleDuMot; ++i) {
                printf("%c",motEnCours[i]);
            }
            getchar();
            printf("\nSaisissez votre proposition : ");
            scanf("%c", &proposition);
            proposition = toupper(proposition);
            for (int i = 1; i < tailleDuMot -1; ++i) {
                if(proposition == motATrouver[i]){
                    motEnCours[i] = proposition;
                    lettreExiste = 1;
                }
            }
            for (int i = 1; i < tailleDuMot -1; ++i) {
                if('_' == motEnCours[i]){
                    estTrouve=0;
                }
            }
            if(estTrouve == 0 && lettreExiste == 0){
                nbCoupRestant--;
                switch (nbCoupRestant) {
                    case 6:
                        printf("\n");
                        printf("\n");
                        printf("\n");
                        printf("\n");
                        printf("\n");
                        printf("\n");
                        printf("_|__\n");
                        break;
                    case 5:
                        printf("\n");
                        printf(" |\n");
                        printf(" |\n");
                        printf(" |\n");
                        printf(" |\n");
                        printf(" |\n");
                        printf("_|__\n");
                        break;
                    case 4:
                        printf(" ___________\n");
                        printf(" |\n");
                        printf(" |\n");
                        printf(" |\n");
                        printf(" |\n");
                        printf(" |\n");
                        printf("_|__\n");
                        break;
                    case 3:
                        printf(" __________\n");
                        printf(" |      |\n");
                        printf(" |\n");
                        printf(" |\n");
                        printf(" |\n");
                        printf(" |\n");
                        printf("_|__\n");
                        break;
                    case 2:
                        printf(" __________\n");
                        printf(" |      |\n");
                        printf(" |      O\n");
                        printf(" |\n");
                        printf(" |\n");
                        printf(" |\n");
                        printf("_|__\n");
                        break;

                    case 1:
                        printf(" __________\n");
                        printf(" |      |\n");
                        printf(" |      O\n");
                        printf(" |     /|\\ \n");
                        printf(" |\n");
                        printf(" |\n");
                        printf("_|__\n");
                        break;
                    case 0:
                        printf(" __________\n");
                        printf(" |      |\n");
                        printf(" |      O\n");
                        printf(" |     /|\\ \n");
                        printf(" |     / \\ \n");
                        printf(" |\n");
                        printf("_|__\n");
                        break;
                }
                printf("Dommage... la lettre '%c' n'existe dans le mot ... Il vous reste %d tentative(s)",proposition,nbCoupRestant);
            }else{
                printf("Bravo ! la lettre '%c' existe dans le mot !",proposition);
            }
            printf("\n[DEBUG] estTrouve=%d",estTrouve);
            printf("\n[DEBUG] nbCoupRestant=%d\n\n",nbCoupRestant);
        } while (estTrouve == 0 && nbCoupRestant > 0);
        if(estTrouve == 1){
            printf("Bravo ! Vous avez trouvé le mot ");
            for (int i = 0; i < tailleDuMot; ++i) {
                printf("%c",motEnCours[i]);
            }
            printf(" en %d coup !",7-nbCoupRestant+1);
        }else{
            printf("Dommage... le mot a trouver était ");
            for (int i = 0; i < tailleDuMot; ++i) {
                printf("%c",motATrouver[i]);
            }
        }
        getchar();
        printf("\nVoulez-vous relancé une partie ? [O,N]: ");
        scanf("%c",&nouvellePartie);
    } while (nouvellePartie == 'O' || nouvellePartie =='o');
    printf("A bientôt !");
    return 0;
}
