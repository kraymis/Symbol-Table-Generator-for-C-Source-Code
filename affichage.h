#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

// pause for a specified amount of time
void pause(unsigned int seconds, unsigned int nanoseconds) {
    struct timespec ts;
    ts.tv_sec = seconds;
    ts.tv_nsec = nanoseconds;
    nanosleep(&ts, NULL);
}


void affichage_avec_animation(int vitesse, char string[])
{
    char *c = string;
    while(*c != 0)
    {
        printf("%c", *c);
        c++;
        pause(0, vitesse);
    }
}

  void first (void)
  {   
    system("cls");
    printf("\033[47m");
    char message[] = "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tEcole Nationale Superieure d Informatique";
    int length = sizeof(message)/sizeof(message[0]);
    int i, j;
    
    for(i = 0; i < length; i++) {
        for(j = 0; j < i; j++) {
            printf(" ");
        }
        printf("\033[34m%c\033[0m\n", message[i]);
        pause(0, 100000); // pause for 100 milliseconds
        system("cls"); // clear the screen
    }
     printf("\033[34m                  E               S            I          \033[0m\n");
     pause(0, 700000);
     system("cls");
     printf("\033[34m                 Ecole Nationale Superieure d Informatique\033[0m\n");
     pause(0, 700000);
     system("cls");
     printf("\033[34m\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tE               S            I          \033[0m\n");
     printf("\n");
     printf("____________________________________________________________________");
     printf("\n");
     printf("\n");
     printf("\n");
     printf(" __________________________________________________ \n");
     printf("|  ______________________________________________  |\n");
     printf("| |                                              | |\n");
     printf("| |       _______     ______       _______       | |\n");                
     printf("| |      |__   __|   |  __  |     |__   __|      | |\n");
     printf("| |         | |      | |__| |        | |         | |\n"); 
     printf("| |         | |      |  ____|        | |         | |\n");
     printf("| |         | |      | |           __| |__       | |\n");   
     printf("| |         |_|      |_|          |_______|      | |\n");   
     printf("| |                                              | |\n");       
     printf("| |______________________________________________| |\n");
     printf("|__________________________________________________|\n");
  
  printf("\n"); 
  printf("\n");
 
  system("pause");
  
  }

  


void second(void)
{ 
     system("cls"); 
     
     printf("\033[34m\t\t\t\t\t\t\t\t\t\tE               S            I          \033[0m\n");
     printf("____________________________________________________________________________________________________\n");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\033[34m");
     affichage_avec_animation(50000,"\t\t\t\tMade by Mahmoudi Samah and Maachi Mohamed Islem Aymen"); 
     printf("\n");
     printf("\n");
     printf("\033[34m");
     affichage_avec_animation(50000,"\t\t\t\t_____________________Groupe 12_______________________");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\033[47m"); // white background color
     printf("\033[30m");
     printf("\n");
     printf("\n");
     printf("   __________________________________________________________________  \n");
     printf("  |                                                                  | \n");
     printf("  |                                                                  | \n");
     affichage_avec_animation(50000,"  |     Ce programme lit un fichier entre par l'utilisateur et       | \n");
     affichage_avec_animation(50000,"  |     genere la table de symboles de ce fichier en utilisant       | \n");
     affichage_avec_animation(50000,"  |     des fonctions de recherche,insertion et affichage.           | \n");
     printf("  |                                                                  | \n");
     printf("  |                                                                  | \n");
     printf("  |                                                                  | \n");
     printf("  |                                                                  | \n");
     printf("  |__________________________________________________________________| \n");
     printf("\n");
     printf("\n");
     printf("\033[0m");
     system("pause");

}


void Quitter()
{
    system("cls");
      printf("\033[47m");
    char message[] = "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tEcole Nationale Superieure d Informatique";
    int length = sizeof(message)/sizeof(message[0]);
    int i, j;
    
    for(i = 0; i < length; i++) {
        for(j = 0; j < i; j++) {
            printf(" ");
        }
        printf("\033[34m%c\033[0m\n", message[i]);
        pause(0, 100000); // pause for 100 milliseconds
        system("cls"); // clear the screen
    }
     printf("\033[34m                  E               S            I          \033[0m\n");
     pause(0, 100000);
     system("cls");
     printf("\033[34m                 Ecole Nationale Superieure d Informatique\033[0m\n");
     pause(0, 100000);
     system("cls");
     printf("\033[34m\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tE               S            I          \033[0m\n");
     printf("\n");
     printf("____________________________________________________________________");
     printf("\n");
     printf("\n");
     printf("\n");
     printf(" __________________________________________________ \n");
     printf("|  ______________________________________________  |\n");
     printf("| |                                              | |\n");
     printf("| |       _______     ______       _______       | |\n");                
     printf("| |      |__   __|   |  __  |     |__   __|      | |\n");
     printf("| |         | |      | |__| |        | |         | |\n"); 
     printf("| |         | |      |  ____|        | |         | |\n");
     printf("| |         | |      | |           __| |__       | |\n");   
     printf("| |         |_|      |_|          |_______|      | |\n");   
     printf("| |                                              | |\n");       
     printf("| |______________________________________________| |\n");
     printf("|__________________________________________________|\n");
  
  printf("\n"); 
  printf("\n");
  printf("Merci de suivre notre TP nous esperons qu'il vous plaira!\n");
  printf("\n");
  printf("\n");
  system("pause");
   
}


void menu(void){
    int choix;
    bool open;
    bool retour=false;
    char nom_fichier[25];



     
    while (1) { // Infinite loop until user chooses to quit
        system("cls"); 

        printf("\n");
        printf("\n");
        printf("\033[31m                        Le menu\033[0m\n");
        printf("\n");
        printf("_____________________________________________________________________________\n");
        printf("\n");
        printf("1- Afficher la table des symboles de premier fichier propose. \n");
        printf("2- Afficher la table des symboles de deuxieme fichier propose. \n");
        printf("3- Afficher la table des symboles de troisieme fichier propose. \n");
        printf("4- Afficher la table des symboles d'un fichier externe.\n");
        printf("5- Quitter \n");
        printf("\n");
        printf("_____________________________________________________________________________\n");
        printf("\n");
        affichage_avec_animation(25000,"\033[34mOn a propose trois fichiers qu on a deja traite pour aider l utilisateur a connaitre le principe de notre programme \033[0m\n");
        printf("\n");
        affichage_avec_animation(50000,"Entrer votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                afficher_table_symboles("CODE1.txt"); 
                break;
            case 2:
                afficher_table_symboles("CODE2.txt");
                break;
            case 3:
                afficher_table_symboles("CODE3.txt");
                break ;  
            case 4:
              
                  printf("\n");
                  printf("Entrez le nom de ce fichier : ");
                  scanf("%s", &nom_fichier);
                  FILE* fp = fopen(nom_fichier, "r");
                  if (fp == NULL) {
                 open = false;}
                 else{(open=true);}
                 while ((!open)&&(!retour))
                {  system("cls"); 
                  printf("Ce fichier n'existe pas voulez vous entrer un nom d'un autre fichier : ");
                  printf("\n");
                  printf("_____________________________________________________________________________\n");
                  printf("1-Oui \n");
                  printf("2-Non \n");
                  printf("\n");
                  printf("_____________________________________________________________________________\n");
                  printf("\n");
                  int choix2 ;
                  printf("\n");
                  affichage_avec_animation(50000,"Entrer votre choix : ");
                  scanf("%d", &choix2);
                  switch (choix2)
                  {
                    case 1 :
                  printf("\n");
                  printf("Entrez le nom de ce fichier : ");
                  scanf("%s", &nom_fichier);
                  FILE* fp = fopen(nom_fichier, "r");
                  if (fp == NULL)
                   {
                  open = false;
                   }
                  
                  else {(open = true);}
                  break;
                   case 2:
                   retour=true;
                        break; // Exit the switch statement, but keep the while loop running
                    default:
                     printf("Votre choix est incorrect!");
                  }
                 
                }
                if(open){
                system("cls"); 
                
               

                printf("\033[31m                        Le menu\033[0m\n");
                printf("\n");
                printf("_____________________________________________________________________________\n");
                printf("\n");
                printf("1- Afficher la table des symboles de ce fichier \n");
                printf("2- retourner");
                printf("\n");
                printf("_____________________________________________________________________________\n");
                printf("\n");
                printf("\n");
                int choix1;
                affichage_avec_animation(50000,"Entrer votre choix : ");
                scanf("%d", &choix1);
                switch (choix1) {
                    case 1:
                        afficher_table_symboles(nom_fichier);
                        break;
                    case 2:
                        break; // Exit the switch statement, but keep the while loop running
                    default:
                        printf("votre choix est incorrect!");
                }
                }
                 
                break ;
                 
            case 5: 
                Quitter();
                return; // Exit the function and the program
            default:
                printf("votre choix est incorrect!");
        }
        
    }
}

