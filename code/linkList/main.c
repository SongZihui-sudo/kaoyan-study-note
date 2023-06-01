#include <linklist.h>
#include <list.h>

int main(int argc, char const *argv[])
{
    list* datas = (list*)malloc(sizeof(list));
    list_init(datas, 10, NULL);
    for (size_t i = 0; i < 10; i++)
    {
        size_t *cur = (size_t *)malloc(sizeof(size_t));
        *cur = i;
        list_push_back(datas, cur);
    }
    linkList* link = (linkList*)malloc(sizeof(linkList));
    listWithhead_head_init(link, datas);
    listWithhead_print(link, printf("%d\n", *(size_t*)tmp->data));
    return 0;
}
