# Huffman's Archiver

This program compresses a text file.The program uses the Huffmon algorithm to compress data. This program is built for Linux.

### Features

- The Huffmon algorithm is used
- Compresses a text file
- Checks the compressed file
- Program starts from the console

### Principle of operation algorithm.
- A symbol frequency table is compiled and sorted from highest to lowest;
- From the resulting table, a tree is constructed, the value is the symbol, and the branches are 0 or 1. in order to correctly compose a tree, the goal is to encode a frequently encountered symbol in fewer bits;
- The result is a tree from which you can construct a Huffman code for any character in the text

## Used functions

create_grid() -- This function creates a table of character frequencies in the text

creat_tree() -- This function creates a tree. The value is the symbol, and the branches are 0 or 1

creat_date() -- This function creates an array of data

write_file() -- This function outputs the response to a file


```
//functions in Huffman_encoding.h

void create_grid(FILE* file,Grid *grid,Grid *grid_sorted);
void creat_tree(Grid *sortedGrid,int next_sortedGrid,Vector* tree);
void creat_date(FILE* file, VectorBool* date,Vector* tree,const int* charMap);
void write_file(FILE *Writefile,VectorBool* date);
```

## Getting started

output->
```
+--------------------------------------------------+
| Below are the commands:                          |
| help --  this command opens which you use;       |
| comp -- this command compresses a text file;     |
+--------------------------------------------------+
```
You will receive two files at the output. "output.txt" - compressed file and "test.txt" - decrypted file "output.txt"

There are three text files in the "input" folder where you can check the program. Example of setting a path

### input exemplar files
This file contains the text of the book "Harry Potter and the Sorcerer's Stone"
```
  ./input/input.txt
```

This file contains an excerpt of the text
```
  ./input/input2.txt
```

This file contains a couple of copies of the first text
```
  ./input/input3.txt
```

## Building and running
```
  gcc main.c Huffman_encoding.c quickSort.c Vector.c -o main
  ./main
```

