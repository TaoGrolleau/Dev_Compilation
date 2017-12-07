%{
#include "y.tab.h"
#include "inc/table_lexicographique.h"

int tablelex = 5;
int numligne = 1;
%}
%%

\n {numligne++;}
prog\: {return(PROG);}

\;\; {return(VIDE);}

\; {return(POINT_VIRGULE);}

\: {return(DEUX_POINTS);}
\-\> {return(FLECHE);}
\<\- {return(FLECHE_FONC);}
\< {return(OP_CMP);}
\> {return(OP_CMP);}
\>\= {return(OP_CMP);}
\<\= {return(OP_CMP);}
\=\= {return(OP_CMP);}
\&\& {return(OU);}
\|\| {return(ET);}

\! {return(OP_NON);}

\-\- {return(SYMB_DEC);}
\+\+ {return(SYMB_INC);}

type {return(TYPE);}


end {return(FIN);}

start {return(DEBUT);}

int {strcpy(yylval.a,yytext);return(ENTIER);}
float {strcpy(yylval.a,yytext);return(REEL);}
bool {strcpy(yylval.a,yytext);return(BOOLEEN);}
char {strcpy(yylval.a,yytext);return(CARACTERE);}
string {strcpy(yylval.a,yytext);return(CHAINE);}

struct\{ {return(STRUCT);}
\}fstruct {return(FSTRUCT);}

tab {return(TABLEAU);}
of {return(DE);}

\[ {return(CROCHET_OUVRANT);}
\] {return(CROCHET_FERMANT);}

\, {return(VIRGULE);}
\. {return(POINT);}

var {return(VARIABLE);}
proc {return(PROCEDURE);}
func {return(FONCTION);}
return {return(RETOURNE);}

\( {return(PARENTHESE_OUVRANTE);}
\) {return(PARENTHESE_FERMANTE);}

if {return(SI);}
then\{ {return(ALORS);}
\}else\{ {return(SINON);}

\} {return(FINBLOC);}

while {return(TANT_QUE);}
do\{ {return(FAIRE);}

\= {return(OPAFF);}

%[dcfs] {return(LETTRE_FORMAT);}

read {return(LIRE);}
write {return(ECRIRE);}

true {return (CSTE_BOOLEEN);}
false {return (CSTE_BOOLEEN);}

\"[a-zA-Z0-9 ]*\" {/*insere_lexeme((int)yyleng,yytext,tablelex);tablelex++ ;*/return(CSTE_CHAINE);} //mettre les caractère spéciaux en plus dans une chaine caractère
'[a-zA-Z0-9]' {yylval.c = yytext[0];/*insere_lexeme((int)yyleng,yytext,tablelex);tablelex++ ;*/return(CSTE_CARACTERE);}
0|[1-9][0-9]*|\-[1-9][0-9]* {yylval.e = atoi(yytext);/*insere_lexeme((int)yyleng,yytext,tablelex);tablelex++ ;*/return(CSTE_ENTIERE);}
(0|[1-9][0-9]*)\.[0-9]*|\-(0|[1-9][0-9]*)\.[0-9]* {yylval.f = atof(yytext) ;/*insere_lexeme((int)yyleng,yytext,tablelex);tablelex++ ;*/return(CSTE_REELLE);}


[a-zA-Z][a-zA-Z0-9]* {strcpy(yylval.a,yytext); tablelex = insere_lexeme((int)yyleng,yytext,tablelex); return(IDF);}


\+ {return(PLUS);}
\- {return(MOINS);}
\* {return(MULT);}
\/ {return(DIV);}

\' {}
\" {}
[ ]+ {}
\\t {}
%%

