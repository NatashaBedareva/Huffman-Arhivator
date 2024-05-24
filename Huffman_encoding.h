#include <stdio.h>
#include  "quickSort.h"
#include  "Vector.h"

void create_grid(FILE* file,Grid *grid,Grid *grid_sorted);
void creat_tree(Grid *sortedGrid,int next_sortedGrid,Vector* tree);
void creat_date(FILE* file, VectorBool* date,Vector* tree,const int* charMap);
void write_file(FILE *Writefile,VectorBool* date);

