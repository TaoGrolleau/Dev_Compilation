#include "../inc/table_regions.h"
//#include "declarations.h"
int m = 1;
void init_regions(){
  int i;
  for(i=0;i<50;i++){
    tableregion[0][i] = -1;
    tableregion[1][i] = -1;
    tableregion[2][i] = -1;
  }
  tableregion[1][0] = 0;
}

/*void insert_in_tab_region(int v,int p){
  tableregion[1][p] = v;
  }*/

