#include <stack.h>

void stack_init(stack *self)
{
    assert(self);
    self->length = 0;
    self->buffer = (linkList *)malloc(sizeof(linkList));
    listWithhead_head_init(self->buffer, NULL);
    self->top = self->buffer->linklistType.linklistHead.mHead->data;
}

void stack_push(stack *self, void *val) 
{
    assert(self);
    assert(val);
    listWithhead_insert(self->buffer, 0, val);
    self->length++;
    self->top = listWithhead_get(self->buffer, 0);
}

void stack_pop(stack *self) 
{
    assert(self);
    listWithhead_remove(self->buffer, 0);
    self->length++;
    self->top = listWithhead_get(self->buffer, 0);
}

int stack_empty(stack *self) 
{
    return linklist_empty(self->buffer);
}

int stack_length(stack *self) 
{
    return self->length;
}