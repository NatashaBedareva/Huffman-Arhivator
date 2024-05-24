#include "quickSort.h"
void quickSort(Grid* a,int left, int right)
{

    if(left>right) return;

    Grid p =a[(left+right)/2];
    if ((left+right)/2+1<right )p =a[(left+right)/2+1];
    int i = left;
    int j = right;

    while(i<=j)
    {
        while (a[i].weight<p.weight) i++;

        while (a[j].weight>p.weight) j--;

        if(i<=j){
            Grid buf = a[i];
            a[i]=a[j];
            a[j]=buf;
            i++;
            j--;
        }
    }
    quickSort(a,left,j);

    quickSort(a,i,right);
}