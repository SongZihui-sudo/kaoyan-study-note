#include <linklist.h>
#include <list.h>

int main(int argc, char const *argv[])
{
    list* datas = NULL;
    list_init(datas, 10);
    for (size_t i = 0; i < 10; i++)
    {
        list_push_back(datas, i);
    }
    linkList* link = NULL;
    listWithhead_head_init(link, datas);
    return 0;
}
