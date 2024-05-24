#include  "Vector.h"

void push_back(Vector* vector,Node value)
{
    int next = vector->size;
    if(next==0)
    {
        vector->arr=(Node*)malloc(sizeof (Node));
    }
    else
    {
        vector->arr = (Node*)realloc(vector->arr,(next + 1) * sizeof(Node));
    }
    vector->arr[next]=value;
    vector->size++;
}
void push_backBool(VectorBool* vector,bool value)
{
    int next = vector->size;
    if(next==0)
    {
        vector->arr=(bool*)malloc(sizeof (bool));
    }
    else
    {
        vector->arr = (bool*)realloc(vector->arr,(next + 1) * sizeof(bool));
    }
    vector->arr[next]=value;
    vector->size++;
}