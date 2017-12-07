#include "../inc/analyse_semantique.h"

int verif_dimension_tab_dec (int dim1, int dim2) {
    if (dim1 < dim2) {
        return 0;
    }
    else {
        return -1;
    }
}

int est_deja_declare (char *nom, int ideclare, int iregion) {
    int i;
    int lexeme_suivant = 0;
    int lexeme_courant = 0;
    for (i = 0; i < ideclare; i++) {
        if (strcmp(nom, tablelexico[1][i]) == 0) {
            //on a trouvé un lexème avec le même nom
            break;
        }
    }
    lexeme_courant = i;
    lexeme_suivant = atoi(tablelexico[2][i]);
    while (lexeme_suivant != -1) {
        if (strcmp(nom, tablelexico[1][lexeme_suivant]) == 0) {
            //tant qu'il reste des lexèmes avec le même nom
            if (iregion - 1 == tabledeclaration[2][lexeme_suivant]) {
                //si la region du lexème trouvé est la même que l'élément en train d'être déclaré
                if (tabledeclaration[3][lexeme_courant] != -1) {
                    //c'est un élément correctement déclaré, ie ce n'est pas un saut de ligne lors de la déclaration d'un type
                return -1;
                }
            }
        }
        //on passe au lexème suivant
        lexeme_courant = lexeme_suivant;
        lexeme_suivant = atoi(tablelexico[2][lexeme_suivant]);
    }
    return 0;
}

int verif_present_table_declaration (char *nom, int ideclare, int nature, int region) {
    //renvoie la ligne d'un élément déclaré avec un lexème *nom* et de nature *nature* et de région *région
    //renvoie -1 sinon
    int i;
    int trouve = 0;
    
    for (i = 0; i < ideclare; i++) { 
        if (strcmp(nom, tablelexico[1][i])==0) {
            if (tabledeclaration[0][i] == nature) {
                if (tabledeclaration[2][i] == region) {
                    //on a trouvé un élément de même lexème, de même nature et de bonne région
                    trouve = 1;
                    break;
                }
            }
        }
    }
    if (trouve == 1) {
        printf("%d i\n",i);
        return i;
    }
    else {
        printf("%d\n",trouve);
        return -1;
    }
}


int verif_est_declare (char *nom, int ideclare, int region, int nis, int nature) {
    int elem = 0;
    int nis_region_courante = nis;
    int region_prec = region-1;
    
    elem = verif_present_table_declaration(nom, ideclare, nature, region);
    printf("%d elem\n", elem);
    //on verifie si il y a un élément déclaré dans la région
    if (elem != -1) {
        return 0;
    }
    else {
        while (nis_region_courante > -1 || region_prec > 0) {
            //on cherche dans les regions parentes
            if (tableregion[1][region_prec] < nis_region_courante) {
                elem = verif_present_table_declaration(nom, ideclare, nature, region_prec);
                printf("%d\n", elem);
            if (elem != -1) {
                return 0;
            }
            }
            region_prec = region_prec - 1;
            nis_region_courante = tableregion[1][region_prec];
            
        }
        return -1;
    }
}
