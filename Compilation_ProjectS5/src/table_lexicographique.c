#include "../inc/table_lexicographique.h"
#include "../inc/declarations.h"

int insere_lexeme(int leng, char text[100], int tablelex ){
    int i,tmpcalcul,ligne_lex;
    
    ligne_lex = est_present(text);
    if(ligne_lex == -1){
        //Copie la longueur du lexeme (1ere case, ligne *tablelex*)
        sprintf(tablelexico[0][tablelex],"%d",leng);
        //Copie la chaine *text* (nom du lexeme) (2eme case, ligne *tablelex*)
        strcpy(tablelexico[1][tablelex],text);
        
        tmpcalcul = 0; //Utilise pour ajouter chaque caractere de la chaine *text*
        for(i = 0;i<leng;i++){
            tmpcalcul = tmpcalcul + text[i];
        }
        //tmpcalcul % 32 = hashcode du lexeme
        //si il n'y a pas de lexeme avec le meme hashcode, ajoute la ligne *tablelex* a la case numero tmpcalcul %32
        if (tablehash[tmpcalcul%32] == -1){
            tablehash[tmpcalcul%32] = tablelex;
        }
        //si il y a un lexeme avec le meme hashcode, ajoute la ligne *tablelex*, dans la 3eme case, a la ligne du lexeme precedent avec ce hashcode. Ajoute a la case tmpcalcul % 32 *, la ligne *tablelex* dans la table des hashcodes
        else{
            sprintf(tablelexico[2][tablehash[tmpcalcul%32]],"%d",tablelex);
            tablehash[tmpcalcul%32] = tablelex;
            
        }
        return tablelex + 1;
    }
    else {
        return tablelex;
    }
}


void init_lexico(){
    int i;
    
    for(i=0;i<1000;i++){
        strcpy(tablelexico[2][i],"-1");
	strcpy(tablelexico[1][i],"-1");
    }
    insere_lexeme(3, "int", 0);
    insere_lexeme(5, "float", 1);
    insere_lexeme(4, "bool", 2);
    insere_lexeme(4, "char", 3);
    insere_lexeme(6, "string", 4);
    //init tablehash
    for(i=0;i<32;i++){
        tablehash[i] = -1;
    }
}

/*
Retourne la ligne dans la table *tablelexico* ou se trouve le lexeme de nom *chaine* et retourne -1 si ce lexeme n'est pas dans la table
 */
int est_present(char* chaine){
  int i;
  
  for(i=0;i<1000;i++){
    if(strcmp(chaine,tablelexico[1][i]) == 0){
      return i;
    }
  }
  return -1;
}
