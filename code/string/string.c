#include <mystring.h>

void string_init(string *self, const char *str)
{
    assert(self);
    self->mBuffer = (wchar_t *)malloc(sizeof(wchar_t) * strlen(str));
    if (!self->mBuffer)
    {
        printf("memory create fail!");
        return;
    }
    strcpy(self->mBuffer, str);
    self->mLength = strlen(str);
    self->mSize = stringMaxSize;
}

int string_index(string *patten, string *str)
{
    /* KMP */
    int res = 0;
    int *next = (int *)malloc(sizeof(int) * str->mLength);
    int index = 0;
    
    /* Create next array */
    for (size_t i = 1; i < str->mLength;)
    {
        if (string_get(str, i) != string_get(str, index))
        {
            next[i] = index + 1;
            index++;
            i++;
        }
        else
        {
            if (index)
            {
                index = next[index - 1];
            }
            else
            {
                next[index - 1] = 0;
                i++;
            }
        }
    }
    
    int j = 0;
    int i = 0;
    /* substring search */
    while (i < patten->mLength && j < str->mLength)
    {
        if (string_get(patten, i) == string_get(str, j))
        {
            i++;
            j++;
        }
        else
        {
            if (!i)
            {
                j++;
            }
            else
            {
                i = next[i -1];
            }
        }
    }
    
    if (j == str->mLength)
    {
        res = j - 1;
    }

    free(next);
    return res;
}

const char *string_str(string *self)
{
    assert(self);
    return self->mBuffer;
}

void string_push_back(string *self, char c)
{
    assert(self);
    if (self->mLength + 1 > self->mSize)
    {
        printf("list is out of the range!");
        return;
    }
    self->mBuffer[self->mLength++] = c;
}

void string_copy(string *dst, string *src)
{
    assert(dst);
    assert(src);
    strcpy(dst->mBuffer, src->mBuffer);
    dst->mLength = src->mLength;
}

int string_cmp(string *dst, string *src)
{
    assert(dst);
    assert(src);
    if (dst->mLength != src->mLength)
    {
        return 1;
    }
    return strcmp(dst->mBuffer, src->mBuffer);
}

void string_add(string *dst, string *src)
{
    dst->mLength += src->mLength;
    char *tmp = (char *)malloc(sizeof(char) * dst->mLength);
    strcpy(tmp, dst->mBuffer);
    dst->mBuffer = (char *)malloc(sizeof(char) * (dst->mLength + src->mLength));
    strcpy(dst->mBuffer, tmp);
    free(tmp);
    strcat(dst->mBuffer, src);
}

void string_pop_back(string *self)
{
    if (self->mLength - 1 > 0)
    {
        printf("list is out of the range!");
        return;
    }
    self->mBuffer[self->mLength--] = '\0';
}

int string_empty(string *self)
{
    if (self->mLength)
    {
        return 1;
    }
    return 0;
}

int string_clear(string *self)
{
    assert(self);
    self->mBuffer[0] = '\0';
}

void string_destory(string *self)
{
    assert(self);
    free(self->mBuffer);
    self->mBuffer = NULL;
    self->mLength = self->mSize = 0;
}

int string_length(string *self)
{
    assert(self);
    return self->mLength;
}

char string_get(string* self, size_t index)
{
    assert(self);
    return self->mBuffer[index];
}

void string_print(string *self)
{
    assert(self);
    printf("%s", self->mBuffer);
}

void string_destory(string *self)
{
    assert(self);
    free(self->mBuffer);
    self->mLength = self->mSize = 0;
}