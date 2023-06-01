#include <list.h>

void list_init(list *self, size_t size, void* ptr)
{
    if (!ptr)
    {
        self->ptr = (void **)malloc(sizeof(void *) * size);
    }
    else
    {
        self->ptr = &ptr;
    }    
    self->length = 0;
    self->size = size;
}

void list_insert(list* self, size_t index, void* data)
{
    assert(self);
    if (self->length + 1 > self->size || index < 0 || index > self->length)
    {
        printf("<<Error>> index out of the range!");
        return;
    }
    for (size_t i = self->length + 1; i > index; i--)
    {
        self->ptr[i] = self->ptr[i-1];
    }
    self->ptr[index] = data;
    self->length++;
}

const void* list_get(list* self, size_t index)
{
    assert(self);
    if (index < 0 || index > self->length)
    {
        printf("<<Error>> index out of the range!");
        return NULL;
    }
    return self->ptr[index];
}


int list_replace(list* self, int index, void* newVal)
{
    assert(self);
    if (index < 0 || index > self->length)
    {
        printf("<<Error>> index out of the range!");
        return -1;
    }
    self->ptr[index] = newVal;
}

int list_empty(list* self)
{
    assert(self);
    if (self->length)
    {
        return 1;
    }
    return 0;
}

void list_remove(list* self, size_t index)
{
    assert(self);
    if (index < 0 || index > self->length)
    {
        printf("<<Error>> index out of the range!");
        return;
    }
    for (size_t i = index; i < self->length; i++)
    {
        self->ptr[i] = self->ptr[i +1];
    }
    self->length--;
}

void list_push_back(list *self, void *data)
{
    assert(self);
    if (self->length + 1 > self->size)
    {
        printf("<<Error>> index out of the range!");
        return;
    }
    self->ptr[self->length] = data;
    self->length++;
}
