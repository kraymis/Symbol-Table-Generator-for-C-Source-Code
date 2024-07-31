#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define True 1
#define False 0


    typedef char* string;

typedef struct Maillon_Tb {
    char Nom[50];
    char Attribut[50];
    char Type[50];
    struct Maillon_Tb* Suiv;
    struct Maillon_Tb* Block;
} Maillon_Tb;

typedef struct Maillon_Tb *Pointeur_Tb;
void Allouer_Tb(Pointeur_Tb* P) {
    *P = (Pointeur_Tb)malloc(sizeof(Maillon_Tb));
    (*P) -> Suiv=NULL;
    (*P) -> Block=NULL;

    if (*P == NULL) {
        printf("Erreur d'allocation de memoire.\n");
        exit(1);
    }
}

void Liberer_Li(Pointeur_Tb P) {
    free(P);
}

Pointeur_Tb Suivant_Tb(Pointeur_Tb P) {
    return P->Suiv;
}

Pointeur_Tb Block_Tb(Pointeur_Tb P) {
    return P->Block;
}

char* Nom_Tb(Pointeur_Tb P) {
    return P->Nom;
}

char* Attribut_Tb(Pointeur_Tb P) {
    return P->Attribut;
}

char* Type_Tb(Pointeur_Tb P) {
    return P->Type;
}

void Aff_val_Maillon_Tb(Pointeur_Tb P, char* nom, char* attribut, char* type) {
    strcpy(P->Nom,nom);
    strcpy(P->Attribut,attribut);
    strcpy(P->Type, type);
}

void Aff_Suiv_Maillon_Tb(Pointeur_Tb P, Pointeur_Tb Q) {
    P->Suiv = Q;
}

void Aff_Block_Maillon_Tb(Pointeur_Tb P, Pointeur_Tb Q) {
    P->Block = Q;
}


void parcourir_liste(Pointeur_Tb ptr_tb) { //Fonction pour l'affichage de la liste
    Pointeur_Tb current_maillon = ptr_tb;
    char* rer;
    while (current_maillon != NULL) {
        rer=Nom_Tb(current_maillon);

        if (strcmp(rer, "Block") != 0)   
        {
        printf("\n");
        printf("________________\n");
        printf("\n");
        printf("| Nom: %s\n", Nom_Tb(current_maillon));
        printf("| Attribut: %s\n", Attribut_Tb(current_maillon));
        printf("| Type: %s\n ", Type_Tb(current_maillon));
        printf("________________\n");
        printf("\n");
        //system("pause");
        }   
        if (Block_Tb(current_maillon) != NULL)
        {
        printf("_____________________________________\n");
        if (strcmp(Type_Tb(current_maillon), "fon") == 0)   
        {
        printf("|          Bloc de fonction :       |\n"); 
        }
        else
        {
        printf("|         Nouveau bloc :             |\n");
        }
        printf("_____________________________________\n");


        }
        parcourir_liste(Block_Tb(current_maillon)); //on utilise la recursivité pour parcourire les sous-blocs
        if (Block_Tb(current_maillon) != NULL)
        {
        printf("_____________________________________\n");
        printf("|          Fin du bloc .            |\n");
        printf("_____________________________________\n");
        }
        current_maillon = Suivant_Tb(current_maillon); //on passe vers le prochain maillon
    }
}


bool isFonction(char* str) { //elle verifie si la declaration qu'on a trouvée est une declaration 'une fonction
        char* strCopy = strdup(str);

        char* openParen = strchr(strCopy, '(');
        char* closeParen = strchr(strCopy, ')');

        if (openParen == NULL && closeParen == NULL) {
            return false;
        } else if (openParen != NULL && closeParen != NULL && closeParen > openParen) {
            return true;
    }

}


bool isContained(char* str) {
    char types[6][15] = {"void","int","double","float","char","bool"};
    for (int i = 0; i < 6; i++) {
        char* strCopy = strdup(types[i]);
        if (strcmp(str, strCopy) == 0) {
            return 1;
        }
    }
    return false;
}


bool isDeclaration(char * line){
    char* strCopy = strdup(line);
    char* token = strtok(strCopy, " ");
    return isContained(token);
    //les deux fonctions isDeclaration et isContained sont reliés entre eux il permettent de verifier si il y'a une declaration de ces 5 types  
// "void","int","double","float","char","bool" au debut
}


bool open_block(char *line) { //une fonction pour verifier si il y'a une "{"
    if ((strncmp(line,"{" , 1)) == 0) {
        return true;
    }
    else {
        return false;
    }
}
bool close_block(char *line) { //une fonction pour verifier si il y'a une "}"
    if (strncmp(line, "}", 1)  == 0)  {
        return true;
    }
    else {
        return false;
    }
}
void extract_vars(char* line, char* type, char variables[][15], int* var_count) {
    sscanf(line, "%s", type);
    char* token = strtok(line, " ,;");
    while (token != NULL) {
        if (strcmp(token, type) != 0) {
            strcpy(variables[*var_count], token);
            (*var_count)++;
        }
        token = strtok(NULL, " ,;");
    }
}

void extract_info(const char* line, char* fun_type2, char* fun_name2, char* type_par2, char* name_par2) {
    int line_len = strlen(line);
    int open_paren_index = -1;
    int close_paren_index = -1;
    int space_before_paren_index = -1;
    int space_after_paren_index = -1;
    int space_before_param_index = -1;
    int space_before_close_paren_index = -1;
    int i;
    
        for (i = 0; i < line_len; i++) {
        if (line[i] == '(' ) {
            open_paren_index = i;
            break;
        } else if (line[i] == ' ' && space_before_paren_index == -1) {
            space_before_paren_index = i;
        }
    }
    

    for (i = open_paren_index + 1; i < line_len; i++) {
        if (line[i] == ')'){
            close_paren_index = i;
            break;
        } else if (line[i] == ' ' && space_after_paren_index == -1) {
            space_after_paren_index = i;
        } else if (line[i] == ' ' && space_before_param_index == -1) {
            space_before_param_index = i;
        }
    }

    for (i = close_paren_index - 1; i > open_paren_index; i--) {
        if (line[i] == ' ') {
            space_before_close_paren_index = i;
            break;
        }
    }
    
    if (close_paren_index - open_paren_index == 1) {
        strcpy(type_par2, "nothing");
        strcpy(name_par2, "nothing");
    } else {
        // Extraaire function name, parameter type, parameter name
        strncpy(type_par2, line + open_paren_index + 1, space_after_paren_index - open_paren_index - 1);
        type_par2[space_after_paren_index - open_paren_index - 1] = '\0';
        strncpy(name_par2, line + space_before_close_paren_index + 1, close_paren_index - space_before_close_paren_index - 1);
        name_par2[close_paren_index - space_before_close_paren_index - 1] = '\0';
    }
    
    strncpy(fun_type2, line, space_before_paren_index);
    fun_type2[space_before_paren_index] = '\0';
    strncpy(fun_name2, line + space_before_paren_index + 1, open_paren_index - space_before_paren_index - 1);
    fun_name2[open_paren_index - space_before_paren_index - 1] = '\0';
}

bool chercher(Pointeur_Tb L, string nom, string att, string typ) {
    while (L != NULL) {
        // Si l'element courant a les memes nom, attribut et type 
        if (strcmp(L->Nom, nom) == 0 && strcmp(L->Attribut, att) == 0 && strcmp(L->Type, typ) == 0) {
            return true; //On a trouvé l'element donc on retourne vrai
        }
        // Sinon, on passe à l'element suivant dans la liste
        L = Suivant_Tb(L); 
    }
    return false;
}

void insert_dec(Pointeur_Tb* P,char (*variables)[15],string att,string type,int var_count)
{
Pointeur_Tb Q=NULL;
for (int i=1 ; i < var_count ; i++) //boucle pour le cas si il y'a plusiers variable dans la meme ligne
{
Allouer_Tb(&Q);
Aff_val_Maillon_Tb(Q,variables[i-1],att,type); //inserer les valeurs dans le maillon 
Aff_Suiv_Maillon_Tb(*P,Q); //lier le maillon avec son precedent
*P=Q;
}
}

void insert_fon(Pointeur_Tb *P,string fun_type,string fun_name)
{
Pointeur_Tb Q=NULL;
Allouer_Tb(&Q);
string att="fon";
Aff_val_Maillon_Tb(Q,fun_name,fun_type,att); //affecter les valeurs dans le maillon de la fct
Aff_Suiv_Maillon_Tb(*P,Q); //lier le maillon de la fonction avec son precedent dans le mm niveau du bloc
*P=Q;
}

void remove_leading_spaces(char *line) {
    int i;
    for (i = 0; isspace(line[i]); ++i) {}

    if (i > 0 && line[i] != '\0') { 
        int j;
        for (j = 0; line[i] != '\0'; ++i, ++j) {
            line[j] = line[i];
        }
        line[j] = '\0';
    }
}


typedef Pointeur_Tb Typeelem_Pi ;
typedef struct Maillon_Pi * Pointeur_Pi ;

struct Maillon_Pi 
{
Typeelem_Pi Val ;
Pointeur_Pi Suiv ;
} ;

void Creerpile_Pi( Pointeur_Pi *P ) // pile vide 
{ *P = NULL ; } // *P reprï¿½sentera le sommet de la pile

bool Pilevide_Pi ( Pointeur_Pi P )
{ return (P == NULL ); }

void Empiler_Pi ( Pointeur_Pi *P, Typeelem_Pi Val )
{
Pointeur_Pi Q;
Q = (struct Maillon_Pi *) malloc( sizeof( struct Maillon_Pi)) ;
Q->Val = Val ;
Q->Suiv = *P; //  placer le maillon Q en sommet de pile
*P = Q; // dï¿½signer le nouveau sommet *P
}

void Depiler_Pi ( Pointeur_Pi *P, Typeelem_Pi *Val )
{
	
Pointeur_Pi Sauv;
if (! Pilevide_Pi (*P) )
{
*Val = (*P)->Val ;
Sauv = *P; // garder le sommet
*P = (*P)->Suiv;  // changer le sommet vers le suivant
Sauv->Suiv=NULL; // dï¿½tacher l'ancien sommet 
free(Sauv);
}
else printf ("Pile vide \n");
}
//****end of abstract machines 


#define MAX_VARIABLES 50
void afficher_table_symboles( char filename[]) {
    char line[100];
    char type[15];
    char variables[MAX_VARIABLES][15];
    int var_count,depth=0;
    bool fctxdec=false,opbl=false,fctxop=false,BIGTETE=true,zoro=false;
    Pointeur_Tb P,P1,P2,L,Q,L2,L3,QS,K=NULL,PP;
    Pointeur_Pi Z,W,V;
    string att = "var";
    char fun_name[50], fun_type[50], type_par[50], name_par[50];    
    int cptK=-1;

    FILE* fp = fopen(filename, "r");

     Creerpile_Pi(&Z); //cette pile on la crée pour garder les ptrs des maillons des blocs parents
     Creerpile_Pi(&W); 
     Creerpile_Pi(&V);
     //les deux piles "W" et "V" vont etre utilisées pour garder le ptr du 1er maillon du sous-bloc mais 
     //la pile "V" est uniquement utilisée pour qu'on depile et faire la recherche du meme element dans le sous-bloc
     //en revanche la pile "V" est utilisée pour la manipulation et le linkage entre les blocs parents et les sous-bloc
    while (fgets(line, 100, fp) != NULL) {
        remove_leading_spaces(line); //on supprime les espaces au debut de chaque ligne
        var_count = 0;
         if (line[strlen(line) - 1] != '\n') {
            strcat(line, "\n");
        }


            if (zoro==true) // si la ligne precedente contient une declaration d'une fonction
            {
                if(strcmp(name_par, "nothing") != 0) // si dans la declaration d'une fonction il existe un parametre entre les parentheses
                {
                cptK=0;
                Allouer_Tb(&K);
                string typoo="par";
                Aff_val_Maillon_Tb(K,name_par,type_par,typoo);
                //on va allouer un maillon K , et on met dedans les informations sur les parametres de la fonction
                }

                zoro=false;
            }
            
            if (opbl==true) // if previous line is {
             {
             Allouer_Tb(&P);  //On alloue ptr du maillon du Debut du sous-bloc
             Empiler_Pi(&W,P);  //on empile le pointeur du premier maillon du sous-block
             Empiler_Pi(&V,P);   //on empile le pointeur du premier maillon du sous-block 
             if (K !=NULL)
             {
             cptK=2;
             Aff_Suiv_Maillon_Tb(P,K);
             P=K;   
             }

             opbl=false;
             fctxop=false;
             }

        if (isDeclaration(line)) 
        { 
            //   Traitement cas special si c la premiere declaration 
            //----On alloue le premier maillon de la table complète-------
            //------------------------------------------------------------
            if (BIGTETE==true)
             {
                Allouer_Tb(&P);
                L=P; //la premiere tete kamel de tout le code
                BIGTETE=false;
                //block=1;
                Empiler_Pi(&V,P);
                
             }
             //-------------------------------------------------------------

             ////////////////////////////////////////////////////////////////

             if (fctxdec==true) //si il y'a directement une delcaration de variable apres la declaration d'une fonction (fonction precedente vide)
             {
            Aff_Suiv_Maillon_Tb(P,K);
            P=K;
            cptK=2;
             }
            //---------------------------------------------------

            ////////////////////////////////////////////////////////////////////
                if (! isFonction(line)) // si c'est une delcaration d'une variable 
                {
           extract_vars(line, type, variables, &var_count); //extraire les infos de la ligne 

           Depiler_Pi(&V,&QS);
           //on va depiler de la pile "V" le pointeur du maiilon du debut du bloc qu'on travaille dedans.



           //_______ on effectue la recherche de cette variable si elle existe dans ce niveau de bloc 
           if (! chercher(Suivant_Tb(QS),variables[0],att,type))
           {
            insert_dec(&P,variables,att,type,var_count);
           }
          //__________ fin de recherche ____________________________________


            Empiler_Pi(&V,QS); //on empile une autre fois le pointeur du maillon du debut du niveau du bloc qu'on travaille dedans.
            
            }
            
            else 
            {

            //Ici on commence le bloc ou il trouve une fonction
            //----------------------------------------------------
            extract_info(line,fun_type,fun_name,type_par,name_par); // extraire les infos de la fonction
            insert_fon(&P,fun_type,fun_name); // on insère la fonction

            zoro=true; //une fonction est trouvée 
            fctxop=true; //ce boolean est utilisé pour verifier si apres la fonction il y'a une accolade "{"
            fctxdec=true; //ce boolean est utilisé pour verifier si apres la fonction il ya directement une declaration (fonction vide)
            //----------------------------------------------------
            }
        }
        else
        {
            // // //si c'est n'est pas une declaration
            // //---------------------------------
            if (open_block(line)) // on verifie si c'est une "{"
            {
            fctxdec=false;
            if (fctxop==true) //si la ligne precedente est une declaration d'une fonction et cette ligne commence par "{"
            {
            opbl=true; // the line is {
            Empiler_Pi(&Z,P); // On empile le pointeur du maillon de la fonction
            }

            else //si la ligne commence par "{" mais c'est un nouveau bloc independant (la ligne precedente n'est pas une fonction) 
            
            {
            Allouer_Tb(&Q);
            char* bl="Block";
            Aff_val_Maillon_Tb(Q,bl,bl,bl); //On alloue un maillon temporaire representant du sous bloc qui va nous permettre de le avec le bloc parent
            L3=Q; 
            Empiler_Pi(&Z,L3); // On sauvgarde le pointeur du maillon temporaire dans la pile          
            Aff_Suiv_Maillon_Tb(P,L3); //on relie ce maillon qui represente le sous-bloc avec le maillon precedent
            opbl=true; // Open_bloc est à vrai maitenant prsk c'est une "{"
            }
            }
            else 
            {

              fctxop=false; 
            }
            if (close_block(line)) //mtn si la ligne commence par "}"
            {
            Depiler_Pi(&Z,&P1); // on va depiler le pointeur du maillon du bloc père qu'on va lier avec le sous-bloc
            Depiler_Pi(&V,&PP); //on depile le ptr du premier maillon du bloc qu'on travaille dedans (cette pile est uniquement par la recherche donc on depile juste 
            //pour la vider du dernier element mais on va pas utiliser le resultat du depilement )

            if (! Pilevide_Pi(W))
            {
            Depiler_Pi(&W,&P2); //on depile le ptr du premier maillon du bloc qu'on travaille dedans
            L2=Suivant_Tb(P2);
            Liberer_Li(P2); 

            Aff_Block_Maillon_Tb(P1,L2); //on lie le bloc père avec son sous-bloc
            P=P1;
            }
            else 
            {
                Allouer_Tb(&Q);
                string typoo="par";
                Aff_val_Maillon_Tb(Q,name_par,type_par,typoo);
                Aff_Block_Maillon_Tb(P,Q);
            }
            opbl=false; //on mais open_bloc à false (reinitiallisation)
             }
     
            //--------------------------------
        }

        if (cptK==2)
        {
        K=NULL;
        //ce cptK est une variable utilisée seulement pour verification de si on est dans une fonction... ect
        }  
        }  
    
    fclose(fp);
    printf("_________________________________________________ \n");

//on re_adresse la tete-------- 
P=Suivant_Tb(L);
free(L);
L=P;
///////////////////////////////
parcourir_liste(L); //Affichage de la table
system("pause");
  } 