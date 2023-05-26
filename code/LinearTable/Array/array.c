#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

int a[MAXSIZE][MAXSIZE] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}};

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < MAXSIZE; i++)
    {
        for (size_t j = 0; j < MAXSIZE; j++)
        {
            printf("(%d , %d) - address: %d -value: %d\n", i, j, &a[i][j], a[i][j]);
        }
        
    }
    
    return 0;
}
