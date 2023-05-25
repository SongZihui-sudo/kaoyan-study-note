#include "linklist.h"

void listWithhead_head_init(linkList *this, list *datas)
{
    assert(datas);
    if (!this)
    {
        this = (linkList*)malloc(sizeof(linkList)); 
    }
    this->linklistType.linklistHead.mHead = (linkListNode*)malloc(sizeof( linkListNode));
    this->linklistType.linklistHead.length = datas->length;
    for (size_t i = 0; i < datas->length; i++)
    {
        linkListNode* newNode = (linkListNode*)malloc(sizeof(linkListNode));
        newNode->ptr.next->data = list_get(datas, i);
        newNode->ptr.next->ptr.next = this->linklistType.linklistHead.mHead;
        this->linklistType.linklistHead.mHead = newNode;
        this->linklistType.linklistHead.length++;
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
    this->linklistType.linklistHead.length = datas->length;
    for (size_t i = 0; i < datas->length; i++)
    {
        linkListNode *newNode = (linkListNode *)malloc(sizeof(linkListNode));
        newNode->ptr.next->data = list_get(datas, i);
        this->linklistType.linklistHead.mHead->ptr.next = newNode;
        this->linklistType.linklistHead.mHead = newNode;
        this->linklistType.linklistHead.length++;
    }
}
