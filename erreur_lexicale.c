#include "./include.c"

/* La fonction erreur_lexicale() est notre procédure de gestion d’erreurs
lexicales: elle affiche un diagnostic de l’erreur et arrète le programme
par appel à la fonction exit() déclarée dans stdlib.h.
*/
void erreur_lexicale(int* position, char* programme){
    
    if (position == NULL  ) {
        printf("ERREUR : le pointeur 'position' est NULL! \n");
        exit(1);
    }

    if (programme == NULL) {
        printf("ERREUR : le pointeur 'programme' est NULL! \n");
        exit(1);
    }
    if (programme[*position - 1] == '\0') {
        printf("ERREUR : addresse illegal d'accés");
        exit(1);
    }

    if (*position > 0) {
        printf("position %d: le caractère ’%c’ est illégal!\n",
            *position,programme[*position-1]);            
        exit(1);
    }
    else return;
    
}