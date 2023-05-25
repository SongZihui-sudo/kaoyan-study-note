#pragma once

#include <stdio.h>
#include <assert.h>

#include "list.h"

typedef struct linkListNode
{
    void* data;
    union
    {
        struct linkListNode* next;
        struct
        {
            struct linkListNode* next;
            struct linkListNode* pre;
        } nextAndpre;
    } ptr;
} linkListNode;

typedef struct linkList
{
    union
    {
        struct
        {
            struct linkListNode* mHead;
            size_t length;
        } linklistHead;
        struct
        {
            struct linkListNode* mHead;
            struct linkListNOde* mTail;
            size_t length;
        } linklistHeadTail;
    } linklistType;
} linkList;

void listWithhead_head_init(linkList* this, list* datas);

void listWithhead_tail_init(linkList* this, list* datas);

void listWithhead_remove(linkList* this, size_t index);

const linkListNode* listWithhead_get(linkList* this, size_t index);

void linstWithhead_replace(linkList* this, size_t index, void* data);