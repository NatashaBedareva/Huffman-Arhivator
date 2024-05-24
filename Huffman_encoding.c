#include "Huffman_encoding.h"

void create_grid(FILE* file,Grid *grid,Grid *grid_sorted){
    for(int i=0;i<256;i++)
    {
        unsigned char symbol;
        while(fscanf(file,"%c",&symbol)!= EOF)
        {
            grid[symbol].weight+=1;
            grid[symbol].symbol=symbol;

            grid_sorted[symbol].weight+=1;
            grid_sorted[symbol].symbol=symbol;
        }
    }
}
void creat_tree(Grid *sortedGrid,int next_sortedGrid,Vector* tree)
{
    for(int i=0;i<next_sortedGrid-1;i=i+2)
    {

        int w0 = sortedGrid[i].weight;
        int n0= sortedGrid[i].index_in_the_tree;
        int w1 = sortedGrid[i+1].weight;
        int n1= sortedGrid[i+1].index_in_the_tree;

        Node value;
        value.symbol='\0';
        value.branch=false;
        value.parent=-1;
        value.zero=n0;
        value.one=n1;
        push_back(tree,value);

        tree->arr[n0].parent=tree->size-1;
        tree->arr[n0].branch=false;
        tree->arr[n1].parent=tree->size-1;
        tree->arr[n1].branch=true;

        sortedGrid[next_sortedGrid].weight=w0+w1;
        sortedGrid[next_sortedGrid].index_in_the_tree=tree->size-1;
        next_sortedGrid++;
    }
}

void creat_date(FILE* file, VectorBool* data, Vector* tree,const int* charMap)
{
    for(int i=0;i<256;i++)
    {
        unsigned char symbol;
        while(fscanf(file,"%c",&symbol)!= EOF)
        {

            Node n = tree->arr[charMap[symbol]];
            VectorBool compressedChar;
            compressedChar.size=0;
            while(n.parent!=-1)
            {
                push_backBool(&compressedChar,n.branch);
                n=tree->arr[n.parent];
            }

            for(int j = compressedChar.size-1;j>=0;j--)
            {
                push_backBool(data,compressedChar.arr[j]);
            }

        }
    }
}

void write_file(FILE *Writefile,VectorBool* data)
{
    for(size_t i=0;i<=data->size/8;++i)
    {
        unsigned char ch = 0;
        for(int j=0;j<8;++j)
            if(data->arr[i*8+j])
                ch|=(1<<j);
        fprintf(Writefile,"%c",ch);
    }
}