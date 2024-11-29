#include "./include.c"

/* La fonction get_lexeme() permet de récupérer le dernier lexème reconu.
Elle utilise les fonctions malloc() et strncpy() déclarées,
respectivement, dans stdlib.h et string.h.
*/

char* get_lexeme(int* position, int debut, char* programme){

    int longueur=*(position)-debut; /* longueur du lexème */
    char* lexeme=(char*) malloc(longueur+1); /* réservation de l’espace mémoire.    */

    if(lexeme == NULL) {
        printf("ERREUR :Échec de l'allocation mémoire pour le lexème. \n");
        exit(1);
    } 

    strncpy(lexeme,programme+debut,longueur); /* le lexème commence à l’adresse programme+debut.  */

    lexeme[longueur]='\0';
    return lexeme;
}