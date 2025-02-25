#include <stdio.h>
#include <stdlib.h>
#include  "analyse_lexicale.h"


typedef enum {Q0,Q1,Q2} Etat;
Lexeme lc;//lexeme courant

void erreur_syntaxique(){
    printf("Erreur syntaxique (ligne %d,colonne %d)\n",lc.ligne,lc.colonne);
    exit(1);
}
void analyser (char *fichier){
    Etat ec ;// etat courant
    ec=Q0;//etat initiale
    while (!fin_de_sequence()){
        lc = lexeme_courant();
        switch (ec){
            case Q0:
                switch (lc.nature){
                    case ENTIER:
                        avancer();
                        ec=Q1;
                        break;
                    default:
                        erreur_syntaxique();
                }
                break;

            case Q1:
                switch (lc.nature){
                    case PLUS:
                    case MOINS:
                    case MUL:
                        avancer();
                        ec=Q2;
                        break;
                    default:
                        erreur_syntaxique();
            }
                break;
            case Q2:
               switch (lc.nature){
                    case ENTIER:
                        avancer();
                        ec=Q1;
                        break;
                    default:
                        erreur_syntaxique();
            }
                break;
    }
}
    
if (ec==Q1)
    printf("syntaxe correcte !\n");
else
    erreur_syntaxique();

}


