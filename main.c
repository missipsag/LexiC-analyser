#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum TOKEN {FIN=0, PV, IF, EGAL, ASSIGN,OP, PARG, PARD, ID, NUM};  /* codification des tokens */
enum CODEOPERATION {PLUS, MOINS}; /* codification des valeurs d’attribut du token OP */
typedef union attribut {
		char* nom;
		int valeur;
		enum CODEOPERATION cop;
	} attribut; /* cette variable contiendra la valeur d’attribut du dernier token reconu.*/


int car_suivant(int* position, char* programme);
void reculer(int* position);
char* get_lexeme(int* position, int debut, char* programme);
enum TOKEN token_suivant(int* position, char* programme, attribut* attribut);
void erreur_lexicale(int* position, char* programme);

int main() {

    
	char programme[256]; /* contiendra la chaîne d’entrée; i.e., le programme source.*/


	int debut, position;
	union attribut* attribut = (union attribut*) malloc(sizeof(attribut));

    enum TOKEN tc;  // tocken courant

    printf("Taper un programme:\n");
    printf("------------------\n\n");
    scanf("%[\40-\176]", programme);

    position=0;
    printf("\n\nSéquence des couples <token, attribut>\n");
    printf("--------------------------------------\n");

    while (tc = token_suivant(&position, programme, attribut)){
        switch(tc){
            case PV: printf("<PV, >\n");
                    break;

            case IF: printf("<IF, >\n");
                    break;
            

            case EGAL: printf("<EGAL, >\n");
                    break;

            case ASSIGN: printf("<ASSIGN, >\n");
                        break;

            case OP: printf("<OP, ");
                    if (attribut->cop == PLUS) printf("PLUS>\n");
                    else printf("MOINS>\n");
                    break;

            case PARG: printf("<PARG, >\n");
                       break;

            case PARD: printf("<PARD, >\n");
                    break;

            case ID: printf("<ID, %s>\n",attribut->nom);
                    break;

            case NUM: printf("<NUM, %d>\n",attribut->valeur);
        }
    }
    printf("<FIN, >\n");
    return 0;
}