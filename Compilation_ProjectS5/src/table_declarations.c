#include "../inc/table_declarations.h"
#include "../inc/declarations.h"


int i = 0;
int iregion = 1;
int idebordement = 0;
int nis = 0;
int nbparam = 0;
int nbchamp = 0;
int nbdimension = 0;



void init_dec(){
    //init tabledeclaration
    idebordement = 750;
    for(i=0;i<1000;i++){
        tabledeclaration[0][i] = 0;
        tabledeclaration[1][i] = -1;
        tabledeclaration[2][i] = -1;
        tabledeclaration[3][i] = -1;
        tabledeclaration[4][i] = 0;
    }
    tabledeclaration[3][0] = 0;
    tabledeclaration[3][1] = 1;
    tabledeclaration[3][2] = 2;
    tabledeclaration[3][3] = 3;
    tabledeclaration[3][4] = 4;
    tabledeclaration[2][0] = 0;
    tabledeclaration[2][1] = 0;
    tabledeclaration[2][2] = 0;
    tabledeclaration[2][3] = 0;
    tabledeclaration[2][4] = 0;
}

void declaration_type(char *nom){
    int i = 0,j;
    int dec = est_present(nom);

    //nature
    tabledeclaration[0][dec] = 1;

    //suivant
    if(tabledeclaration[1][dec] != -1){
        while (tabledeclaration[1][dec] != -1){
            dec = tabledeclaration[1][dec];
        }
        tabledeclaration[1][dec] = idebordement;
        dec = idebordement;
        idebordement++;
    }
    if(tabledeclaration[2][dec] != -1){
        tabledeclaration[1][dec] = idebordement;;
        dec = idebordement;
        idebordement ++;
    }

    //region
    if (nis == 0) {
        tabledeclaration[2][dec] = 0;
    }
    else {
        tabledeclaration[2][dec] = pile_regions[haut_pile-1];
    }

    //description
    for (i=0;tabletype[i] != -1;i++);
    tabledeclaration[3][dec] = i;

    //remplissage de la table des types
    tabletype[i] = nbchamp;
    i++;
    for(j=0;j<nbchamp;i++,j++){
        tabletype[i] = est_present(listechamps[j][0]);
        i++;
        tabletype[i] = est_present(listechamps[j][1]);
    }
    nbchamp = 0;
}


void declaration_tab(char *nom){
    int i = 0,j;
    int dec = est_present(nom);

    //nature
    tabledeclaration[0][dec] = 2;
      
    //suivant
    if(tabledeclaration[1][dec] != -1){
        while (tabledeclaration[1][dec] != -1){
            dec = tabledeclaration[1][dec];
        }
        tabledeclaration[1][dec] = idebordement;
        dec = idebordement;
        idebordement++;
    }
    if(tabledeclaration[2][dec] != -1){
        tabledeclaration[1][dec] = idebordement;;
        dec = idebordement;
        idebordement ++;
    }

    //region
    if (nis == 0) {
        tabledeclaration[2][dec] = 0;
    }
    else {
        tabledeclaration[2][dec] = pile_regions[haut_pile-1];
    }

    //description
    for (i=0;tabletype[i] != -1;i++);
    tabledeclaration[3][dec] = i;

    //remplissage de la table des types
    tabletype[i] = nbdimension;
    i++;
    for(j=0;j<nbdimension;i++,j++){
        tabletype[i] = listedimension[j][0];
        i++;
        tabletype[i] = listedimension[j][1];
    }
    nbdimension = 0;
}

void declaration_var(char* nom,char* type){
    int dec = est_present(nom);

    //nature
    tabledeclaration[0][dec] = 3;

    //suivant
    if(tabledeclaration[1][dec] != -1){
        while (tabledeclaration[1][dec] != -1){
            dec = tabledeclaration[1][dec];
        }
        tabledeclaration[1][dec] = idebordement;
        dec = idebordement;
        idebordement++;
    }
    if(tabledeclaration[2][dec] != -1){
        tabledeclaration[1][dec] = idebordement;;
        dec = idebordement;
        idebordement ++;
    }

    //region
    if (nis == 0) {
        tabledeclaration[2][dec] = 0;
    }
    else {
	tabledeclaration[2][dec] = pile_regions[haut_pile-1];
    }
    tabledeclaration[3][dec] = est_present(type);
}

void nom_type(char *nom_fonc){
    for (i=0;tabletype[i] != -1;i++);
    if(strcmp("int",nom_fonc) == 0){
        tabletype[i] = 0;
    }
  
    if(strcmp("float",nom_fonc)==0){
        tabletype[i] = 1;
    }
  
    if(strcmp("bool",nom_fonc)==0){
        tabletype[i] = 2;
    }
  
    if(strcmp("char",nom_fonc)==0){
        tabletype[i] = 3;
    }
    if(strcmp("string",nom_fonc)==0){
        tabletype[i] = 4;
    }
  
}
void declare_fonction (char *nom) {
    int i = 0;
    int dec = est_present(nom);

    //nature
    tabledeclaration[0][dec] = 5;

    //suivant
    if(tabledeclaration[1][dec] != -1){
        while (tabledeclaration[1][dec] != -1){
            dec = tabledeclaration[1][dec];
        }
        
        tabledeclaration[1][dec] = idebordement;
        dec = idebordement;
        idebordement++;
    }
    if(tabledeclaration[2][dec] != -1){
        tabledeclaration[1][dec] = idebordement;
        dec = idebordement;
        idebordement ++;
    }

    //region
    if (nis == 0) {
        tabledeclaration[2][dec] = 0;
    }
    else {
        tabledeclaration[2][dec] = pile_regions[haut_pile-1];
    }
    tableregion[1][iregion] = nis;
    iregion++;

    //description
    for (i=0;tabletype[i] != -1;i++);
    tabledeclaration[3][dec] = i;

    //le remplissage de la table des types se fait dans le .y
}

void declare_proc (char *nom) {
    int i;
    int dec = est_present(nom);

    //nature
    tabledeclaration[0][dec] = 4;

    //suivant
    if(tabledeclaration[1][dec] != -1){
        while (tabledeclaration[1][dec] != -1){
            dec = tabledeclaration[1][dec];
        }
  
        tabledeclaration[1][dec] = idebordement;
        dec = idebordement;
        idebordement++;
    }
    if(tabledeclaration[2][dec] != -1){
        tabledeclaration[1][dec] = idebordement;
        dec = idebordement;
        idebordement ++;
    }

    //region
    if (nis == 0) {
        tabledeclaration[2][dec] = 0;
    }
    else {
        tabledeclaration[2][dec] = pile_regions[haut_pile-1];
    }
    tableregion[1][iregion] = nis;
    iregion++;
    
    //description
    for (i=0;tabletype[i] != -1;i++);
    tabledeclaration[3][dec] = i;

    //le remplissage de la table des types se fait dans le .y
}

void insert_tab_type(){
    int i,j=0;
    for (i=0;tabletype[i] != -1;i++);
    tabletype[i] = nbparam;
    i++;

  
    for(j=0;j<nbparam;j++){
        tabletype[i] = est_present(listeparametre[j][0]);
        i++;
        tabletype[i] = est_present(listeparametre[j][1]);
        i++;
    }
    nbparam = 0;
}

void insert_tab_type_fonc(){
    int i,j=0;
    for (i=0;tabletype[i] != -1;i++);
    i++;
    tabletype[i] = nbparam;
    i++;

  
    for(j=0;j<nbparam;j++){
        tabletype[i] = est_present(listeparametre[j][0]);
        i++;
        tabletype[i] = est_present(listeparametre[j][1]);
        i++;
    }
    nbparam = 0;
}

void ajouter_param(char* idf, char* type){  
    strcpy(listeparametre[nbparam][0],idf);
    strcpy(listeparametre[nbparam][1],type);
    nbparam += 1;
}



