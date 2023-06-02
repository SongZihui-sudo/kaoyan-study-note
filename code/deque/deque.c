#include <deque.h>

void deque_init(deque *self)
{
    assert(self);
    self->length = 0;
    self->buffer = (linkList *)malloc(sizeof(linkList));
    listWithheadTail_head_init(self->buffer, NULL);
    self->top = self->buffer->linklistType.linklistHeadTail.mHead->data;
}

void deque_pop_front(deque *self)
{
    assert(self);
    if (!linklist_empty(self->buffer))
    {
        listWithheadTail_remove(self->buffer, 0);
    }
    self->length--;
    self->top = listWithheadTail_get(self->buffer, 0)->data;
}

void deque_pop_back(deque *self)
{
    assert(self);
    if (!linklist_empty(self->buffer))
    {
        listWithheadTail_remove(self->buffer, self->length);
    }
    self->length--;
}

void deque_push_back(deque *self, void *val)
{
    assert(self);
    assert(val);
    listWithheadTail_insert(self->buffer, self->length, val);
    self->length++;
}

void deque_push_front(deque *self, void *val)
{
    assert(self);
    assert(val);
    listWithheadTail_insert(self->buffer, 0, val);
    self->length++;
    self->top = listWithheadTail_get(self->buffer, 0)->data;
}

int deque_empty(deque *self)
{
    return linklist_empty(self->buffer);
}

int deque_length(deque *self)
{
    return self->length;
}