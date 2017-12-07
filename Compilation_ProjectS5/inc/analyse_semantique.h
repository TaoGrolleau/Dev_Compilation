#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_declarations.h"
#include "table_lexicographique.h"
#include "table_regions.h"
#include "table_types.h"

int verif_dimension_tab_dec(int dim1, int dim2);
/*
Vérifie que les dimensions d'un tableau soient exploitables.
Ex : type t : int[1..5]
*/

int est_deja_declare(char *nom, int ideclare, int iregion);
/*
Vérifie qu'un élément en train d'être déclaré n'est pas déjà déclaré.
*/

int verif_est_declare(char *nom, int ideclare, int region, int nis, int nature);
/*
Fonction appellée pour tous les IDF trouvés dans les instructions
Vérifie qu'un IDF (d'une certaine nature) est correctement déclaré, soit dans sa propre région, soit dans une région parente.
*/