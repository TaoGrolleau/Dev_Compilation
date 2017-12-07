#ifndef _DECLARATIONS_H
#define _DECLARATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int i;
extern int pile_regions[100];
extern int haut_pile;
extern int iregion;
extern int nis;
extern int idebordement;
extern int nbparam;
extern int nbchamp;
extern int nbdimension;
extern int listedimension[50][2];
extern char listechamps[50][2][100];
extern char listeparametre[50][2][100];

extern int tableregion[3][50];
/*
A commenter
*/
extern int tablehash[32];
/*
  Dans une case i (i etant le hashcode d'un lexeme) se trouve la ligne du dernier lexeme avec ce hashcode
*/

extern char tablelexico[3][1000][100];
/*
  1ere colonne : longueur du lexeme (nombre de caracteres)

  2eme colonne : chaine du nom du lexeme

  3eme colonne : lexeme suivant de meme hashcode

  Il y a 1000 lignes dans cette table

  Le nom d'un lexeme ne peut pas avoir plus de 100 caracteres
*/

extern int tabledeclaration[5][1000];
/* 
   1ere colonne : Nature des declarations
   - 1 : Declaration de structure
   - 2 : Declaration de tableau
   - 3 : Declaration de variable
   - 4 : Declaration de procedure
   - 5 : Declaration de fonction

   2eme colonne : Declaration suivante avec le meme nom (IDF) (presente dans la zone de debordement)

   3eme colonne : Numero de region

   4eme colonne : Description de la declaration
   - Si la nature de la declaration est egale a 1 ou 2 : Ligne de la table decrivant le type
   - Si la nature de la daclaratiob est egale a 3 : Description du type
   - 1 : Type = Int
   - 2 : Type = Float
   - 3 : Type = Booleen
   - 4 : Type = Caractere
   - 5 : Type = Chaine
   - Si la nature de la declaration est egale a 4 ou 5 : Ligne de la table type representant les arguments de la procedure ou de la fonction

   5eme colonne : Instructions a l'execution


   Il y a 1000 lignes dans cette table
   Seules LIMITE_MAX(750) declarations sont autorisees, si il y a une declaration avec le meme nom (IDF), elle est placee dans la zone de debordement
*/

extern int tablehash[32];
/*
  Dans une case i (i etant le hashcode d'un lexeme) se trouve la ligne du dernier lexeme avec ce hashcode
*/

extern int tabletype[1000];
/*
  Contient la description des tableaux, structures, procedures et fonctions declarees

  Si une structure est declaree : 
  - On place son nombre de champs
  - Pour chaque champ :
  - Type (ligne ou le type est present dans la table des declarations)
  - Numero lexicographique
  - Deplacement a l'execution

  Si un tableau est declare :
  - Type des elements (ligne ou le type est present dans la table des declarations)
  - Nombre de dimensions
  - Bornes inférieures et supérieures pour chaque dimension

  Si une procedure est declaree :
  - Nombre de parametres
  - Pour chaque parametre :
  - Numero lexicographique
  - Valeur du type (doit etre un type de base)

  Si une fonction est declaree : 
  - Valeur de retour de la fonction (doit etre un type de base)
  - Nombre de parametres
  - Pour chaque parametre :
  - Numero lexicographique
  - Valeur du type (doit etre un type de base)
*/
void init_tab();


#endif
