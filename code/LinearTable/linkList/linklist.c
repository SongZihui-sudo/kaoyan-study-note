#include "../../include/linklist.h"

/*－－－－－－－－－－－－ 带头节点的单链表 －－－－－－－－－－－－－－－－*/

void listWithhead_head_init(linkList *this, list *datas)
{
    assert(datas);
    if (!this)
    {
        this = (linkList*)malloc(sizeof(linkList)); 
    }
    this->linklistType.linklistHead.mHead = (linkListNode*)malloc(sizeof( linkListNode));
    this->length = datas->length;
    for (size_t i = 0; i < datas->length; i++)
    {
        linkListNode* newNode = (linkListNode*)malloc(sizeof(linkListNode));
        newNode->data = list_get(datas, i);
        newNode->ptr.next = this->linklistType.linklistHead.mHead;
        this->linklistType.linklistHead.mHead = newNode;
        this->length++;
    }
}

void listWithhead_tail_init(linkList *this, list *datas)
{
    assert(datas);
    if (!this)
    {
        this = (linkList *)malloc(sizeof(linkList));
    }
    this->linklistType.linklistHead.mHead = (linkListNode *)malloc(sizeof(linkListNode));
    this->length = datas->length;
    for (size_t i = 0; i < datas->length; i++)
    {
        linkListNode *newNode = (linkListNode *)malloc(sizeof(linkListNode));
        newNode->data = list_get(datas, i);
        this->linklistType.linklistHead.mHead->ptr.next = newNode;
        this->linklistType.linklistHead.mHead = newNode;
        this->length++;
    }
}

const linkListNode *listWithhead_get(linkList *this, size_t index)
{
    assert(this);
    if (index < 0 || index > this->length)
    {
        printf("index is out of the range!");
        return NULL;
    }
    linkListNode* tmp = this->linklistType.linklistHead.mHead;
    while (index)
    {
        tmp = tmp->ptr.next;
    }
    return tmp;
}

void listWithhead_remove(linkList *this, size_t index)
{
    assert(this);
    if (index < 0 || index > this->length)
    {
        printf("index is out of the range!");
        return NULL;
    }
    linkListNode* pre = listWithhead_get(this, index - 1);
    assert(pre->ptr.next->ptr.next);
    pre = pre->ptr.next->ptr.next;
    this->length--;
}

void listWithhead_replace(linkList *this, size_t index, void *data)
{
    assert(this);
    if (index < 0 || index > this->length)
    {
        printf("index is out of the range!");
        return NULL;
    }
    linkListNode *cur = listWithhead_get(this, index);
    cur->data = data;
}

void listWithhead_insert(linkList *this, size_t index, void *data)
{
    assert(this);
    if (index < 0 || index > this->length)
    {
        printf("index is out of the range!");
        return NULL;
    }
    linkListNode *cur = listWithhead_get(this, index - 1);
    linkListNode* newNode = (linkListNode*)malloc(sizeof(linkListNode));
    newNode->data = data;
    linkList* tmp = cur->ptr.next;
    cur->ptr.next = newNode;
    newNode->ptr.next = tmp;
    this->length++;
}

/*－－－－－－－－－－－－－－ 带头节点与尾节点的双向循环链表 －－－－－－－－－－－－－－－－*/

void listWithheadTail_head_init(linkList *this, list *datas)
{
    assert(datas);
    if (!this)
    {
        this = (linkList *)malloc(sizeof(linkList));
    }
    this->linklistType.linklistHeadTail.mHead = (linkListNode *)malloc(sizeof(linkListNode));
    this->linklistType.linklistHeadTail.mTail = this->linklistType.linklistHeadTail.mHead;
    this->length = datas->length;
    for (size_t i = 0; i < datas->length; i++)
    {
        linkListNode *newNode = (linkListNode *)malloc(sizeof(linkListNode));
        newNode->data = list_get(datas, i);
        newNode->ptr.nextAndpre.next = this->linklistType.linklistHeadTail.mHead;
        this->linklistType.linklistHeadTail.mHead->ptr.nextAndpre.pre = newNode;
        this->linklistType.linklistHeadTail.mHead = newNode;
        this->linklistType.linklistHeadTail.mTail = newNode;
        this->length++;
    }
}

void listWithheadTail_tail_init(linkList *this, list *datas)
{
    assert(datas);
    if (!this)
    {
        this = (linkList *)malloc(sizeof(linkList));
    }
    this->linklistType.linklistHeadTail.mHead = (linkListNode *)malloc(sizeof(linkListNode));
    this->linklistType.linklistHeadTail.mTail = this->linklistType.linklistHeadTail.mHead;
    this->length = datas->length;
    for (size_t i = 0; i < datas->length; i++)
    {
        linkListNode *newNode = (linkListNode *)malloc(sizeof(linkListNode));
        newNode->data = list_get(datas, i);
        this->linklistType.linklistHeadTail.mHead->ptr.nextAndpre.next = newNode;
        newNode->ptr.nextAndpre.pre = this->linklistType.linklistHeadTail.mHead; this->linklistType.linklistHeadTail.mHead = newNode;
        this->length++;
    }
}

void listWithheadTail_remove(linkList *this, size_t index)
{
    assert(this);
    if (index < 0 || index > this->length)
    {
        printf("index is out of the range!");
        return NULL;
    }
    linkListNode* pre = listWithheadTail_get(this, index - 1);
    assert(pre);
    assert(pre->ptr.nextAndpre.next->ptr.nextAndpre.next);
    pre = pre->ptr.nextAndpre.next->ptr.nextAndpre.next;
    pre->ptr.nextAndpre.next->ptr.nextAndpre.next->ptr.nextAndpre.pre = pre;
}

const linkListNode *listWithheadTail_get(linkList *this, size_t index)
{
    assert(this);
    if (index < 0 || index > this->length)
    {
        printf("index is out of the range!");
        return NULL;
    }
    if (index > this->length / 2)
    {
        linkListNode* tmp = this->linklistType.linklistHeadTail.mHead;
        while (index)
        {
            tmp = tmp->ptr.nextAndpre.next;
        }
        return tmp;
    }
    linkListNode* tmp = this->linklistType.linklistHeadTail.mTail;
    while (index)
    {
        tmp = tmp->ptr.nextAndpre.pre;
    }
    return tmp;
}

void listWithheadTail_replace(linkList *this, size_t index, void *data)
{
    assert(this);
    if (index < 0 || index > this->length)
    {
        printf("index is out of the range!");
        return NULL;
    }
    linkListNode* cur = listWithheadTail_get(this, index);
    assert(cur);
    cur->data = data;
}

void listWithheadTail_insert(linkList *this, size_t index, void *data)
{
    assert(this);
    if (index < 0 || index > this->length)
    {
        printf("index is out of the range!");
        return NULL;
    }
    linkListNode* pre = listWithheadTail_get(this, index - 1);
    assert(pre);
    linkListNode* newNode = (linkListNode*)malloc(sizeof(linkListNode));
    newNode->data = data;
    linkListNode* tmp = pre->ptr.nextAndpre.next;
    assert(tmp);
    pre->ptr.nextAndpre.next = newNode;
    newNode->ptr.nextAndpre.pre = tmp;
    newNode->ptr.nextAndpre.next = tmp;
    tmp->ptr.nextAndpre.pre = newNode;
}