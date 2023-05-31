#include <list.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    list* test = (list*)malloc(sizeof(list));
    list_init(test, 20);
    for (size_t i = 0; i < 10; i++)
    {
        list_push_back(test, i);
    }
    for (size_t i = 0; i < 10; i++)
    {
        size_t cur = *(size_t*)list_get(test, i);
        printf("cur: %d", cur);
    }
    return 0;
}
