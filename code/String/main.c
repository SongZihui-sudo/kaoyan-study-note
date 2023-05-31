#include "../include/string.h"

int main(int argc, char const *argv[])
{
    string *test2 = (string*)malloc(sizeof(string));
    string *test1 = (string *)malloc(sizeof(string));

    /* test case1 string init */
    string_init(test1, (const char *)"abcdefg");
    string_init(test2, (const char *)"cde");
    assert(test1);
    assert(test2);

    /* test case 4 string add */
    string_add(test1, test2);
    string_print(test1);

    /* test case 3 substring search */
    int res = string_index(test1, test2);
    assert(res);

    /* test case2 string destory */
    string_destory(test1);
    string_destory(test2);
    free(test1);
    free(test2);
    test2 = NULL;
    test1 = NULL;
    assert(!test1);
    assert(!test2);

    return 0;
}
