#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a[5][5] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 3, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}};

    printf("address a[0][0]: %p\n", &a[0][0]);
    printf("address a[1][1]: %p\n", &a[1][0]);
    printf("address a[2][2]: %p\n", &a[2][2]);
    printf("address a[3][4]: %p\n", &a[3][3]);
    printf("address a[4][4]: %p\n", &a[4][4]);
    return 0;
}
