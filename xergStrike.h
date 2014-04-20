#ifndef XERG_STRIKE_H
#define XERG_STRIKE_H
#include <stdbool.h>
#define MESSAGE_AIDE "\n\nhelp: affichage de l'aide\nmasque <masque> <texte> (sans les chevrons) : permet d'obtenir le résulta du masquage de texte par masque\n\n"
#define MESSAGE_NB_MAX_MASQUAGE "\n\nAttention le nombre max de masquage est 26 \n(Car texte + x*26mod(26)=texte )\n\n"
#define ERREUR_NB_MAX_MASQUE "\n\nErreur : \nnombre de masque incorrect\n\n"
void launcher(int,char **);
void masquage(char *,char*,char*);

int alphabetToInt(char);
char integerToAlpha(int);

void tabToTab(char *,char*);

#endif
