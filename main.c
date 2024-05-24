#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "quickSort.h"
#include "Vector.h"
#include "Huffman_encoding.h"

void printf_help()
{
    printf("+--------------------------------------------------+\n");
    printf("| Below are the commands:                          |\n");
    printf("| help --  this command opens which you use;       |\n");
    printf("| comp -- this command compresses a text file;     |\n");
    printf("+--------------------------------------------------+\n");
    printf("Enter the command: ");
}

int main()
{
    //C:\\Users\\Bedareva\\Documents\\Progect\\input2.txt
    //..//input2.txt
    int end=1;
    printf_help();
    do {
        Grid grid[256]={0};
        Grid grid_sorted[256]={0};
        FILE *file;
        char name_input[1000]={0};

        int count_symbol=0;

        char command[10]={0};
        scanf("%s",command);

        if(strcmp(command,"help")==0)
        {
            printf_help();
        }
        else if(strcmp(command,"comp")==0)
        {
            do{
                printf("Enter the path to the file: \n");
                scanf("%s",name_input);
                file = fopen(name_input, "rb");
                if(file==NULL)
                {
                    printf("File opening error. Repeat the data entry\n");
                }
            }while(file==NULL);

            create_grid(file,grid,grid_sorted);

            fclose(file);

            quickSort(grid_sorted,0,255);


            Grid sortedGrid[1000]={0};
            int next_sortedGrid=0;

            Vector tree;
            int charMap[256];
            tree.size=0;

            for(int i=0;i<256;i++)
            {
                if(grid_sorted[i].weight>0)
                {
                    Node value;
                    value.symbol=grid_sorted[i].symbol;
                    value.parent=-1;
                    value.one=-1;
                    value.zero=-1;
                    value.branch=false;
                    push_back(&tree,value);

                    sortedGrid[next_sortedGrid].symbol=grid_sorted[i].symbol;
                    sortedGrid[next_sortedGrid].weight=grid_sorted[i].weight;
                    sortedGrid[next_sortedGrid].index_in_the_tree=tree.size-1;
                    next_sortedGrid++;
                    charMap[grid_sorted[i].symbol]=tree.size-1;
                }
            }

            creat_tree(sortedGrid,next_sortedGrid,&tree);
            file = fopen(name_input, "rb");
            char symbol2;
            while(fscanf(file,"%c",&symbol2)!= EOF) {
                count_symbol++;
            }
            fclose(file);

            file = fopen(name_input, "rb");
            VectorBool data;
            data.size=0;
            creat_date(file, &data,&tree,charMap);
            fclose(file);

            FILE *Writefile;
            Writefile = fopen("output.txt", "wb");
            write_file(Writefile,&data);
            fclose(Writefile);



            ///////////////////DECODER///////////////
            file = fopen("output.txt", "rb");
            if(file==NULL)
            {
                printf("File opening error");
                return 1;
            }
            VectorBool data2;
            data2.size=0;

            unsigned char symbol;
            while(feof(file)==0)
            {
                fscanf(file,"%c",&symbol);
                for(int i=0;i<8;++i)
                    push_backBool(&data2,(symbol&(1<<i))!=0);
            }
            fclose(file);


            int n=tree.size-1;
            int countt=0;
            Writefile = fopen("test.txt", "w");

            for(int i=0;i<data2.size;i++)
            {
                if(data2.arr[i]) n = tree.arr[n].one;
                else n = tree.arr[n].zero;

                if(tree.arr[n].one==-1)
                {
                    countt++;
                    if(countt>count_symbol) break;
                    fprintf(Writefile,"%c",tree.arr[n].symbol);
                    n=tree.size-1;
                }
            }
            fclose(Writefile);
            end=0;
        }
        else
        {
            printf("There is no such command. Repeat the input \n");
            printf("Enter the command: ");
        }
        
        if(end==0)
        	printf("The file has been successfully compressed.\nIt is located in output.txt .\nIn the file test.txt contains the decrypted file for verification.\n");



    }while(end);


    return 0;
}
