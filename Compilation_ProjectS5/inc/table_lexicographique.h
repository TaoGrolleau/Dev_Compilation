
char tablelexico[3][1000][100];
int tablehash[32];



int insere_lexeme(int leng, char text[100], int tablelex);
/*
Ajoute le lexeme en arguments dans la table *tablelexico* a la ligne *tablelex*
Auteurs : Lucas Tao
 */

int est_present(char *chaine);
/*
Retourne la ligne dans la table *tablelexico* contenant le lexeme avec le meme nom *chaine* et retourne -1 si le lexeme n'est pas dans la table
 */

void init_lexico();
/*
Initialise tablelexico et tablehash
*/
