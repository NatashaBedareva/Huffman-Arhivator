#pragma once
typedef struct Grid
{
    int index_in_the_tree;
    int weight;
    unsigned char symbol;
}Grid;
void quickSort(Grid* a,int left, int right);