#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct list
{
    void** ptr;
    size_t size;
    size_t length;
} list;

void list_init(list *this, size_t size, void *ptr);

void list_insert(list *this, size_t index, void *data);

const void* list_get(list* this, size_t index);

int list_replace(list* this, int index, void* newVal);

int list_empty(list* this);

void list_remove(list* this, size_t index);

void list_push_back(list* this, void* data);