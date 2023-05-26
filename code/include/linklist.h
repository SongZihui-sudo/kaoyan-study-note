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
    size_t length;
    union
    {
        struct
        {
            struct linkListNode* mHead;
        } linklistHead;
        struct
        {
            struct linkListNode* mHead;
            struct linkListNOde* mTail;
        } linklistHeadTail;
    } linklistType;
} linkList;

/*－－－－－－－－－－－－ 带头节点的单链表 －－－－－－－－－－－－－－－－*/

void listWithhead_head_init(linkList* this, list* datas);

void listWithhead_tail_init(linkList* this, list* datas);

void listWithhead_remove(linkList* this, size_t index);

const linkListNode* listWithhead_get(linkList* this, size_t index);

void listWithhead_replace(linkList* this, size_t index, void* data);

void listWithhead_insert(linkList* this, size_t index, void* data);

/*－－－－－－－－－－－－－－ 带头节点与尾节点的双向循环链表 －－－－－－－－－－－－－－－－*/

void listWithheadTail_head_init(linkList *this, list *datas);

void listWithheadTail_tail_init(linkList *this, list *datas);

void listWithheadTail_remove(linkList *this, size_t index);

const linkListNode *listWithheadTail_get(linkList *this, size_t index);

void listWithheadTail_replace(linkList *this, size_t index, void *data);

void listWithheadTail_insert(linkList *this, size_t index, void *data);