#ifndef linklist_h
#define linklist_h

#include <stdio.h>
#include <assert.h>

#include <list.h>

typedef struct linkListNode
{
    void *data;
    union
    {
        struct linkListNode *next;
        struct
        {
            struct linkListNode *next;
            struct linkListNode *pre;
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
            struct linkListNode *mHead;
        } linklistHead;
        struct
        {
            struct linkListNode *mHead;
            struct linkListNOde *mTail;
        } linklistHeadTail;
    } linklistType;
} linkList;

/**
 * @brief 链表是否为空
 *
 * @param self
 * @return int
 */
int linklist_empty(linkList *self);

/**
 * @brief 链表长度
 * 
 * @param self 
 * @return int 
 */
int linklist_length(linkList *self);

/*－－－－－－－－－－－－ 带头节点的单链表 －－－－－－－－－－－－－－－－*/

void listWithhead_head_init(linkList *self, list *datas);

void listWithhead_tail_init(linkList *self, list *datas);

void listWithhead_remove(linkList *self, size_t index);

const linkListNode *listWithhead_get(linkList *self, size_t index);

void listWithhead_replace(linkList *self, size_t index, void *data);

void listWithhead_insert(linkList *self, size_t index, void *data);

#define listWithhead_print(self, printfunc)                    \
    linkListNode *tmp = link->linklistType.linklistHead.mHead; \
    while (tmp)                                                \
    {                                                          \
        printfunc;                                             \
        tmp = tmp->ptr.next;                                   \
    }

/*－－－－－－－－－－－－－－ 带头节点与尾节点的双向循环链表 －－－－－－－－－－－－－－－－*/

void listWithhead_head_initlistWithhead_head_init(linkList *self, list *datas);

void listWithheadTail_tail_init(linkList *self, list *datas);

void listWithheadTail_remove(linkList *self, size_t index);

const linkListNode *listWithheadTail_get(linkList *self, size_t index);

void listWithheadTail_replace(linkList *self, size_t index, void *data);

void listWithheadTail_insert(linkList *self, size_t index, void *data);

#define listWithheadTail_print(self, printfunc)                    \
    linkListNode *tmp = self->linklistType.linklistHeadTail.mHead; \
    while (tmp)                                                    \
    {                                                              \
        printfunc;                                                 \
        tmp->ptr.nextAndpre.next;                                  \
    }
#endif