#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "xergStrike.h"
#include <string.h>

static bool usage(int a ,char **b)
{
  assert(a>1&&a<6);
  return true;
}
static bool estMinuscule(char a)
{
  return (a>='a'&&a<='z')?true:false;
}
static bool estMajuscule(char a)
{

  return (a>='A'&&a<='Z')?true:false;
}
static bool estLettre(char a)
{
  return (estMajuscule(a)||estMinuscule(a))?true:false;
}
static void afficherAide()
{
  printf("\n\n\nAide de la fonction \n ");
  printf("\nhelp: affichage de l'aide");
  printf("\nmasque <masque> <texte> (sans les chevrons) : permet d'obtenir le résulta du masquage de texte par masque");
  printf("\n\n");
 
}
static void afficherMessageMasquageTexte(int nbrMasque)
{
  printf("\n\n______________________\n\nMasquage de texte *%d\n______________________\n\n",nbrMasque>26?26:nbrMasque);
}


static void afficherResultatMasquageMultiple(char *masque,char *original,char *resultat,int rang){

      printf("\nmasque : %20s  \ntexte : %21s \nresultat : %18s  (rang %d)\n_____________\n",masque,original,resultat,rang);

}


int main(int argc,char **argv)
{
  if(!usage(argc,argv))
    return EXIT_FAILURE; 
  launcher(argc,argv);
  return EXIT_SUCCESS;
}

int alphabetToInt(char a)
{
 
  int i;
  for(i=0;i<26&&(i+'a')!=a;i++);

  return i;

}
char integerToAlpha(int a)
{
  assert(a>=0);
  while(a>=26)
    a-=26;
  return 'a'+a;
  

}
void masquage(char *masque,char *texte,char *final)
{

  
 
  for(int i=0,y=0;i<strlen(texte)+1;i++,y=y%strlen(masque)){
    if(estLettre(texte[i]))
       final[i]=integerToAlpha(alphabetToInt(masque[y++])+alphabetToInt(texte[i])+1);
    else
      final[i]=texte[i];
  }
 

  
}

static char* copierChaine(char *a)
{
  char *retour=malloc(sizeof(char)*strlen(a)+1);
  char *b=retour;
  for(;*a;a++,b++)
    *b=*a;
  *b=*a;
  return retour;
  
    
}
void tabToTab(char *a,char *b)
{
  for(;*b;b++,a++)
    *a=*b;
  *a=*b;

}


void affichageMasquageMultiple(int argc,char **argv)
{
  int nbrMasque=atoi(argv[4]);
  assert(nbrMasque>=1);
  int tailleFinal=strlen(argv[3])+1;
  char *final=copierChaine(argv[3]);
  char save[tailleFinal];
  char *masque=argv[2];
  afficherMessageMasquageTexte(nbrMasque);

  for(int i=0;i<nbrMasque&&i<26;i++)
    {
	
      tabToTab(save,final);

      masquage(masque,final,final);
      afficherResultatMasquageMultiple(masque,save,final,i+1);

    }

  if(nbrMasque>26)
      printf("\n\nAttention le nombre max de masquage est 26 \n(Car texte + x*26mod(26)=texte )\n\n");
  free(final);
   
}
void launcher (int argc,char **argv)
{
    
  if(strcmp(argv[1],"help")==0)
    return afficherAide();

  else if(strcmp(argv[1],"masque")==0)
    {

      if(argc==4)
	{
	  char final[strlen(argv[3])+1];   
	  masquage(argv[2],argv[3],final);
	  printf("\n\n%s\n\n",final);
   
	}
      else if(argc==5)
	{
	  affichageMasquageMultiple(argc,argv);

	}
      else
	printf("Erreur , arguments invalide \nTaper help pour obtenir de l'aide sur les commande\n\n");
 
    }
 
 
    



}


