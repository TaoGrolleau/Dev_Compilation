int tabledeclaration[5][1000];
char listechamps[50][2][100];
char listeparametre[50][2][100];
int listedimension[50][2];


/*Initialise la table des declarations*/
void init_dec();
void insert_tab_type();
void nom_type(char *nom_fonc);
void declaration_type(/*char *nom*/);
void declaration_tab(/*char *nom*/);
void declaration_var(char* nom,char *type);
void declare_fonction(char *nom);
void insert_tab_type_fonc();
void declare_proc();
int est_present(char *chaine);
void ajouter_param(char* idf, char* type);
