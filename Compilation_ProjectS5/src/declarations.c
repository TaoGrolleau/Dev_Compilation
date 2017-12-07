#include "../inc/table_regions.h"
#include "../inc/table_types.h"
#include "../inc/table_declarations.h"
#include "../inc/table_lexicographique.h"
#include "../inc/declarations.h"

void init_tab(){
  pile_regions[haut_pile] = 0;
  haut_pile++;
  init_lexico();
  init_regions();
  init_dec();
  init_types();
}
