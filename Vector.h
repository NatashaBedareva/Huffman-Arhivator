#pragma once
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    unsigned char symbol;
    int parent;
    int zero;
    int one;
    bool branch;
}Node;
typedef struct Vector
{
    Node* arr;
    int size;
}Vector;
typedef struct VectorBool
{
    bool* arr;
    int size;
}VectorBool;

void push_back(Vector* vector,Node value);
void push_backBool(VectorBool* vector,bool value);