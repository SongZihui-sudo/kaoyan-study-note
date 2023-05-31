#include <list.h>

void list_init(list *this, size_t size)
{
    this->ptr = (int*)malloc(sizeof(int) * size);
    this->length = 0;
    this->size = size;
}

void list_insert(list* this, size_t index, void* data)
{
    assert(this);
    if (this->length + 1 > this->size || index < 0 || index > this->length)
    {
        printf("<<Error>> index out of the range!");
        return;
    }
    for (size_t i = this->length + 1; i > index; i--)
    {
        this->ptr[i] = this->ptr[i-1];
    }
    this->ptr[index] = data;
    this->length++;
}

const void* list_get(list* this, size_t index)
{
    assert(this);
    if (index < 0 || index > this->length)
    {
        printf("<<Error>> index out of the range!");
        return NULL;
    }
    return this->ptr[index];
}


int list_replace(list* this, int index, void* newVal)
{
    assert(this);
    if (index < 0 || index > this->length)
    {
        printf("<<Error>> index out of the range!");
        return -1;
    }
    this->ptr[index] = newVal;
}

int list_empty(list* this)
{
    assert(this);
    if (this->length)
    {
        return 1;
    }
    return 0;
}

void list_remove(list* this, size_t index)
{
    assert(this);
    if (index < 0 || index > this->length)
    {
        printf("<<Error>> index out of the range!");
        return;
    }
    for (size_t i = index; i < this->length; i++)
    {
        this->ptr[i] = this->ptr[i +1];
    }
    this->length--;
}

void list_push_back(list *this, void *data)
{
    assert(this);
    if (this->length + 1 > this->size)
    {
        printf("<<Error>> index out of the range!");
        return;
    }
    this->ptr[this->length] = data;
    this->length++;
}
