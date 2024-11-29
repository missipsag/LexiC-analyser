#include "./include.c"

/* 
    token_suivant() est la fonction princiaple de l’analyseur lexical; c’est
    elle qui constitue l’implémentation du DFA. A chaque appel, elle retourne
    le prochain token dont elle place la valeur d’attribut dans la variable
    attribut.

*/

enum TOKEN {FIN=0, PV, IF, EGAL, ASSIGN,OP, PARG, PARD, ID, NUM};  /* codification des tokens */
enum CODEOPERATION {PLUS, MOINS}; /* codification des valeurs d’attribut du token OP */
typedef union attribut {
		char* nom;
		int valeur;
		enum CODEOPERATION cop;
	} attribut; /* cette variable contiendra la valeur d’attribut du dernier token reconu.*/

int car_suivant(int* position, char* programme);
void erreur_lexicale(int* position, char* programme);
char* get_lexeme(int* position, int debut, char* programme);
void reculer(int* position);

enum TOKEN token_suivant(int* position, char* programme, union attribut* attribut) {
	if (position == NULL  ) {
        printf("ERREUR : le pointeur 'position' est NULL! \n");
        exit(1);
    }

    if (programme == NULL) {
        printf("ERREUR : le pointeur 'programme' est NULL! \n");
        exit(1);
    }

    int cc;
    int etat; 
    int debut;

    etat = 0;
    while(1) {
        switch (etat) {
            case 0: debut = *(position);
                    cc = car_suivant(position, programme);
                    switch(cc) {
                        case 0: etat = 15;
                                break;
                        
                        case 1: etat=4;
                                break;
                        
                        case 2: etat=2;
                                break;

                        case 3: etat=4;
                                break;
                        
                        case 4: etat=1;
                                break;
                        
                        case 5: etat=5;
                                break;
                        
                        case 6: etat=12;
                                break;
                        
                        case 7: etat=14;
                                break;
                        
                        case 8: etat=13;
                                break;
                        
                        case 9: etat=6;
                                break;
                        
                        case 10: break;
                        
                        default: erreur_lexicale(position, programme);
                    }
                    break;
                
            case 1: cc = car_suivant(position, programme);
                        while(cc == 4)
                            cc = car_suivant(position, programme);
                        etat = 7;
                        break;

            case 2: cc= car_suivant(position, programme);
                        switch(cc) {
                            case 3: etat = 3;
                                    break;
                            
                            case 1:

                            case 2: 

                            case 4: etat = 4;
                                    break;

                            default: etat = 9;
                        }
                    break;

            case 3: cc= car_suivant(position, programme);
                        switch(cc) {
                            case 1: 

                            case 2: 

                            case 3:

                            case 4: etat = 4;
                                    break; 
                                
                            default: etat = 8;
                        }
                        break;

            case 4: cc= car_suivant(position, programme);
                    while( cc>= 1 && cc <= 4)
                        cc= car_suivant(position, programme);
                    etat = 9;
                    break; 

            case 5: cc= car_suivant(position, programme);
                    if(cc == 5) etat = 10;
                    else etat = 11;
                    break;

            case 6: return PV;

            case 7: reculer(position);
                    attribut->valeur= atoi(get_lexeme(position, debut, programme)); // calcul de la valeur
                    return NUM;

            case 8:  reculer(position);
                    return IF;

            case 9: reculer(position);
                	attribut->nom = get_lexeme(position, debut, programme);
                    return ID;
            
            case 10: return EGAL;

            case 11:  reculer(position);
                     return ASSIGN;

            case 12: if (get_lexeme(position, debut, programme) [0] == '+') attribut->cop = PLUS;
                     else attribut->cop = MOINS;
                     return OP;
            
            case 13: return PARD;

            case 14: return PARG;

            case 15: return FIN;
                                                                     
        }
    }
}