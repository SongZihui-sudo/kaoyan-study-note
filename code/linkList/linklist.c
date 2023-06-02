#include <linklist.h>

int linklist_empty(linkList *self)
{
    assert(self);
    if (!self->length)
    {
        return 1;
    }
    return 0;
}

int linklist_length(linkList *self)
{
    assert(self);
    return self->length;
}

/*－－－－－－－－－－－－ 带头节点的单链表 －－－－－－－－－－－－－－－－*/

void listWithhead_head_init(linkList *self, list *datas)
{
    self->linklistType.linklistHead.mHead = (linkListNode *)malloc(sizeof(linkListNode));
    if (datas)
    {
        self->length = datas->length;
        for (size_t i = 0; i < datas->length; i++)
        {
            linkListNode *newNode = (linkListNode *)malloc(sizeof(linkListNode));
            newNode->data = list_get(datas, i);
            newNode->ptr.next = self->linklistType.linklistHead.mHead;
            self->linklistType.linklistHead.mHead = newNode;
        }
    }
    else
    {
        self->length = 0;
    }
}

void listWithhead_tail_init(linkList *self, list *datas)
{
    self->linklistType.linklistHead.mHead = (linkListNode *)malloc(sizeof(linkListNode));
    if (datas)
    {
        self->length = datas->length;
        for (size_t i = 0; i < datas->length; i++)
        {
            linkListNode *newNode = (linkListNode *)malloc(sizeof(linkListNode));
            newNode->data = list_get(datas, i);
            self->linklistType.linklistHead.mHead->ptr.next = newNode;
            self->linklistType.linklistHead.mHead = newNode;
            self->length++;
        }
    }
    else
    {
        self->length = 0;
    }
}

const linkListNode *listWithhead_get(linkList *self, size_t index)
{
    assert(self);
    if (index < 0 || index > self->length)
    {
        printf("index is out of the range!");
        return NULL;
    }
    linkListNode *tmp = self->linklistType.linklistHead.mHead;
    while (index)
    {
        tmp = tmp->ptr.next;
    }
    return tmp;
}

void listWithhead_remove(linkList *self, size_t index)
{
    assert(self);
    if (index < 0 || index > self->length)
    {
        printf("index is out of the range!");
        return NULL;
    }
    linkListNode *pre;
    if (!index)
    {
        pre = self->linklistType.linklistHead.mHead;
    }
    else
    {
        pre = listWithhead_get(self, index - 1);
    }
    assert(pre->ptr.next->ptr.next);
    pre = pre->ptr.next->ptr.next;
    self->length--;
}

void listWithhead_replace(linkList *self, size_t index, void *data)
{
    assert(self);
    if (index < 0 || index > self->length)
    {
        printf("index is out of the range!");
        return NULL;
    }
    linkListNode *cur = listWithhead_get(self, index);
    cur->data = data;
}

void listWithhead_insert(linkList *self, size_t index, void *data)
{
    assert(self);
    if (index < 0 || index > self->length)
    {
        printf("index is out of the range!");
        return NULL;
    }
    linkListNode *cur;
    if (!index)
    {
        cur = self->linklistType.linklistHead.mHead;
    }
    else
    {
        cur = listWithhead_get(self, index - 1);
    }
    linkListNode *newNode = (linkListNode *)malloc(sizeof(linkListNode));
    newNode->data = data;
    linkList *tmp = cur->ptr.next;
    cur->ptr.next = newNode;
    newNode->ptr.next = tmp;
    self->length++;
}

/*－－－－－－－－－－－－－－ 带头节点与尾节点的双向循环链表 －－－－－－－－－－－－－－－－*/

void listWithheadTail_head_init(linkList *self, list *datas)
{
    self->linklistType.linklistHeadTail.mHead = (linkListNode *)malloc(sizeof(linkListNode));
    self->linklistType.linklistHeadTail.mTail = self->linklistType.linklistHeadTail.mHead;
    if (datas)
    {
        self->length = datas->length;
        for (size_t i = 0; i < datas->length; i++)
        {
            linkListNode *newNode = (linkListNode *)malloc(sizeof(linkListNode));
            newNode->data = list_get(datas, i);
            newNode->ptr.nextAndpre.next = self->linklistType.linklistHeadTail.mHead;
            self->linklistType.linklistHeadTail.mHead->ptr.nextAndpre.pre = newNode;
            self->linklistType.linklistHeadTail.mHead = newNode;
            self->linklistType.linklistHeadTail.mTail = newNode;
            self->length++;
        }
    }
    else
    {
        self->length = 0;
    }
}

void listWithheadTail_tail_init(linkList *self, list *datas)
{
    self->linklistType.linklistHeadTail.mHead = (linkListNode *)malloc(sizeof(linkListNode));
    self->linklistType.linklistHeadTail.mTail = self->linklistType.linklistHeadTail.mHead;
    if (datas)
    {
        self->length = datas->length;
        for (size_t i = 0; i < datas->length; i++)
        {
            linkListNode *newNode = (linkListNode *)malloc(sizeof(linkListNode));
            newNode->data = list_get(datas, i);
            self->linklistType.linklistHeadTail.mHead->ptr.nextAndpre.next = newNode;
            newNode->ptr.nextAndpre.pre = self->linklistType.linklistHeadTail.mHead;
            self->linklistType.linklistHeadTail.mHead = newNode;
            self->length++;
        }
    }
}

void listWithheadTail_remove(linkList *self, size_t index)
{
    assert(self);
    if (index < 0 || index > self->length)
    {
        printf("index is out of the range!");
        return NULL;
    }
    linkListNode *pre;
    if (!index)
    {
        pre = self->linklistType.linklistHeadTail.mHead;
    }
    else
    {
        pre = listWithheadTail_get(self, index - 1);
    }
    assert(pre);
    assert(pre->ptr.nextAndpre.next->ptr.nextAndpre.next);
    linkListNode *next = pre->ptr.nextAndpre.next->ptr.nextAndpre.next;
    linkList *tmp = pre;
    pre = next;
    if (index)
    {
        pre->ptr.nextAndpre.next->ptr.nextAndpre.next->ptr.nextAndpre.pre = tmp;
    }
}

const linkListNode *listWithheadTail_get(linkList *self, size_t index)
{
    assert(self);
    if (index < 0 || index > self->length)
    {
        printf("index is out of the range!");
        return NULL;
    }
    if (index > self->length / 2)
    {
        linkListNode *tmp = self->linklistType.linklistHeadTail.mHead;
        while (index)
        {
            tmp = tmp->ptr.nextAndpre.next;
        }
        return tmp;
    }
    linkListNode *tmp = self->linklistType.linklistHeadTail.mTail;
    while (index)
    {
        tmp = tmp->ptr.nextAndpre.pre;
    }
    return tmp;
}

void listWithheadTail_replace(linkList *self, size_t index, void *data)
{
    assert(self);
    if (index < 0 || index > self->length)
    {
        printf("index is out of the range!");
        return NULL;
    }
    linkListNode *cur = listWithheadTail_get(self, index);
    assert(cur);
    cur->data = data;
}

void listWithheadTail_insert(linkList *self, size_t index, void *data)
{
    assert(self);
    if (index < 0 || index > self->length)
    {
        printf("index is out of the range!");
        return NULL;
    }
    linkListNode *pre;
    if (!index)
    {
        pre = self->linklistType.linklistHeadTail.mHead;
    }
    else
    {
        pre = listWithheadTail_get(self, index - 1);
    }
    assert(pre);
    linkListNode *newNode = (linkListNode *)malloc(sizeof(linkListNode));
    newNode->data = data;
    linkListNode *tmp = pre->ptr.nextAndpre.next;
    pre->ptr.nextAndpre.next = newNode;
    newNode->ptr.nextAndpre.pre = tmp;
    newNode->ptr.nextAndpre.next = tmp;
    if (index)
    {
        tmp->ptr.nextAndpre.pre = newNode;
    }
    assert(tmp);
}