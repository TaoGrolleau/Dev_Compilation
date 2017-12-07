%{
#include "y.tab.h"
#include "inc/declarations.h"
#include "inc/table_declarations.h"
#include "inc/table_regions.h"
#include "inc/table_types.h"
#include "inc/analyse_semantique.h"
  
    extern int numligne;
    extern char *yytext;
    int haut_pile = 0;
    int verifdeclarationlex = 1;
    int pile_regions[100];
    %}

%union{
    char a[100];
    float f;
    int e;
    char c;
    unsigned int b;
 }
%type<e> CSTE_ENTIERE suite_declaration_type
%type<a> type_simple IDF nom_type CHAINE ENTIER REEL BOOLEEN CARACTERE VARIABLE 
%type<c> CSTE_CARACTERE 
%type<f> CSTE_REELLE
%type<b> CSTE_BOOLEEN


%token PROG DEBUT FIN
%token POINT POINT_VIRGULE DEUX_POINTS VIRGULE GUILLEMET

%token TYPE IDF STRUCT FSTRUCT TABLEAU DE
%token CROCHET_OUVRANT CROCHET_FERMANT PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
%token FLECHE FLECHE_FONC
%token ENTIER REEL BOOLEEN CARACTERE CHAINE
%token CSTE_ENTIERE CSTE_REELLE CSTE_BOOLEEN CSTE_CARACTERE CSTE_CHAINE
%token VARIABLE PROCEDURE FONCTION RETOURNE
%token VIDE
%token SI ALORS SINON TANT_QUE FAIRE FINBLOC
%token OPAFF
%token LETTRE_FORMAT LIRE ECRIRE
%token OP_NON ET OU OP_CMP
%token PLUS MOINS DIV MULT
%token SYMB_DEC SYMB_INC
%%
prog:programme

programme:PROG corps

corps:liste_declarations liste_instructions
|liste_instructions
;

liste_declarations:declaration
|liste_declarations POINT_VIRGULE declaration
;

liste_instructions:DEBUT suite_liste_inst FIN {
    if (nis == 0) {
        iregion = 1;
    }
 }

suite_liste_inst:instruction 
|suite_liste_inst POINT_VIRGULE instruction
;

declaration:declaration_type
|declaration_variable
|declaration_procedure 
|declaration_fonction
;

declaration_type:TYPE IDF DEUX_POINTS suite_declaration_type{
    if($4 == STRUCT){
        declaration_type($2);
    }
    else{
        declaration_tab($2);
    }
 }

suite_declaration_type:STRUCT liste_champs FSTRUCT{
    $$ = STRUCT;
 }
|TABLEAU dimension DE nom_type{
    nom_type($4);
    $$ = TABLEAU;
 }
;

dimension:CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT
;

liste_dimensions:une_dimension
|liste_dimensions VIRGULE une_dimension
;

une_dimension:CSTE_ENTIERE POINT POINT CSTE_ENTIERE{
    listedimension[nbdimension][0] = $1;
    listedimension[nbdimension][1] = $4;
    nbdimension += 1;
    if (verif_dimension_tab_dec($1, $4) == -1) {
        fprintf(stderr, "Erreur lors de la déclaration d'un tableau, la 1ere dimension est supérieure à la 2eme\n");
        exit(-1);
    }
 }
;

liste_champs:un_champ
|liste_champs POINT_VIRGULE un_champ
;

un_champ:IDF DEUX_POINTS nom_type{
    strcpy(listechamps[nbchamp][0],$3);
    strcpy(listechamps[nbchamp][1],$1);
    nbchamp += 1;
 }
;

nom_type:type_simple {strcpy($$,$1);}
|IDF {strcpy($$,$1);}
;

type_simple:ENTIER{strcpy($$,$1);}
|REEL {strcpy($$,$1);}
|BOOLEEN{strcpy($$,$1);}
|CARACTERE{strcpy($$,$1);}
|CHAINE CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT {strcpy($$,$1);}
;

declaration_variable:VARIABLE IDF DEUX_POINTS nom_type {
    declaration_var($2,$4);
 }
;

declaration_procedure:PROCEDURE {nis++;pile_regions[haut_pile] = iregion;haut_pile++;}IDF {declare_proc($3);}liste_parametres {insert_tab_type();} corps{
    haut_pile--;
    nis--;
}
;

declaration_fonction:FONCTION {nis++;pile_regions[haut_pile] = iregion;} IDF {declare_fonction($3);}liste_parametres {insert_tab_type_fonc();} RETOURNE type_simple corps{
    haut_pile--;
    nom_type($8);
    nis--;
 }
;

liste_parametres:PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE
|PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
;

liste_param:un_param
|liste_param POINT_VIRGULE un_param
;

un_param:IDF DEUX_POINTS type_simple {
    declaration_var($1,$3);
    ajouter_param($1,$3);
 }
;

instruction:affectation
|condition
|tant_que
|appel
|lecture
|ecriture
|VIDE
|incrementation
|decrementation
|RETOURNE resultat_retourne
|fonction
;

resultat_retourne:expression
|%empty
;

appel:IDF liste_arguments
;

liste_arguments:PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE
|%empty
;

liste_args:un_arg
|liste_args VIRGULE un_arg
;

un_arg:expression
;

condition:SI /*PARENTHESE_OUVRANTE*/ expression /*PARENTHESE_FERMANTE*/
ALORS liste_instructions
SINON liste_instructions
FINBLOC
|SI expression ALORS liste_instructions FINBLOC
;

tant_que:TANT_QUE expression FAIRE liste_instructions FINBLOC
;

affectation:variable OPAFF expression
;

fonction:IDF FLECHE_FONC appel
;

variable:IDF
|IDF CROCHET_OUVRANT liste_entiers CROCHET_FERMANT 
|variable FLECHE IDF
;

liste_entiers:liste_entiers VIRGULE entier
|entier
;

entier:CSTE_ENTIERE
|IDF
;

expression:expression_bool
|expression_arith
;

expression_bool:operande OP_CMP operande expression_bool1
|OP_NON operande
;

expression_bool1: ET expression_bool
|OU expression_bool
|%empty
;

operande:CSTE_BOOLEEN
|expression_arith
;


expression_arith:expression_arith PLUS expression_arith1
|expression_arith MOINS expression_arith1
|expression_arith1
;

expression_arith1:expression_arith1 MULT expression_arith2
|expression_arith1 DIV expression_arith2
|expression_arith2
;

expression_arith2:PARENTHESE_OUVRANTE expression_arith PARENTHESE_FERMANTE
|CSTE_ENTIERE
|CSTE_REELLE
|CSTE_CHAINE 
|CSTE_CARACTERE
|variable
;

lecture:LIRE PARENTHESE_OUVRANTE liste_variables PARENTHESE_FERMANTE
;

ecriture:ECRIRE PARENTHESE_OUVRANTE format suite_ecriture PARENTHESE_FERMANTE
;

liste_variables:variable
|variable VIRGULE liste_variables
;

format:GUILLEMET un_format liste_format GUILLEMET
|%empty
;

liste_format:un_format liste_format
|%empty
;

un_format:CSTE_CHAINE
|LETTRE_FORMAT
;

suite_ecriture: VIRGULE variable suite_ecriture
|%empty
;

incrementation:IDF SYMB_INC
;

decrementation:IDF SYMB_DEC 
;

%%

int yyerror () {
    printf("Erreur de syntaxe à la ligne %d\n", numligne);
}

int main(){
    init_tab();
    yyparse();
}

int yywrap(){
    int i;
    i = 0;
    printf("tablelexico\n");
    while(/*strcmp(tablelexico[1][i], "-1")!=0*/ i <50){
        printf("%s \t%s \t%s\n",tablelexico[0][i],tablelexico[1][i],tablelexico[2][i]);
        i++;
    }

    i = 0;
    printf("\n\ntable declaration\n");
    while(/*tabledeclaration[3][i] != -1*/i<50){
        printf("%d \t%d \t%d \t%d \t%d \t%d\n",i,tabledeclaration[0][i],tabledeclaration[1][i],tabledeclaration[2][i],tabledeclaration[3][i],tabledeclaration[4][i]);
        i++;
    }
    i = 750;
    printf("Debordement\n");
    while(/*tabledeclaration[3][i] != -1*/i<800){
        printf("%d \t%d \t%d \t%d \t%d \t%d\n",i,tabledeclaration[0][i],tabledeclaration[1][i],tabledeclaration[2][i],tabledeclaration[3][i],tabledeclaration[4][i]);
        i++;
    }
    printf("\n\ntable hash\n");
    i = 0;

    while(i < 32){
        printf("%d\n", tablehash[i]); 
        i++;
    }

    printf("\n\ntable des types\n");
    i = 0;
    while(tabletype[i] != -1){
        printf("%d\n", tabletype[i]); 
        i++;
    }

    i = 0;
    printf("\n\ntable region\n");
  
    while(tableregion[1][i] != -1){
        printf("%d \t%d \t%d\n", tableregion[0][i], tableregion[1][i], tableregion[2][i]);
        i++;
    }
    return 1;
}
