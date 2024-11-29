#include "./include.c"

/* La fonction car_suivant() retourne le code du prochain caractère du
programme source et incrémente la variable position. C'est cette fonction
qui assure la codification des caractères.
*/

int car_suivant(int* position, char* programme){
    int cc; /* caractère courant */
    int len = strlen(programme);
    if (position == NULL  ) {
        printf("ERREUR : le pointeur 'position' est NULL! \n");
        exit(1);
    }

    if (programme == NULL) {
        printf("ERREUR : le pointeur 'programme' est NULL! \n");
        exit(1);
    }

    if (*position >len ) return 0; /* fin du programme */

    cc= programme[(*position)++]; /* lecture du caractère et incrémentation de la variable position.*/

    if (cc=='\0') return 0;

    if (cc>='a' && cc<='z' && cc!='i' && cc!='f') return 1;
    if (cc=='i') return 2;
    if (cc=='f') return 3;
    if (cc>='0' && cc<='9') return 4;
    if (cc=='=') return 5;
    if (cc=='+' || cc=='-') return 6;
    if (cc=='(') return 7;
    if (cc==')') return 8;
    if (cc==';') return 9;
    if (cc==' ') return 10;
    return 11; /* autre */
}