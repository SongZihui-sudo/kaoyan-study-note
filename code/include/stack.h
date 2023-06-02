#ifndef stack_h
#define stack_h

#include <stdlib.h>
#include <linklist.h>

typedef struct stack
{
    void *top;
    linkList *buffer;
    size_t length;
} stack;

/**
 * @brief 栈初始化
 *
 * @param self
 */
void stack_init(stack *self);

/**
 * @brief 压入元素
 *
 * @param self
 * @param val
 */
void stack_push(stack *self, void *val);

/**
 * @brief 弹出元素
 *
 * @param self
 */
void stack_pop(stack *self);

/**
 * @brief 栈是否为空
 *
 * @param self
 * @return int
 */
int stack_empty(stack *self);

/**
 * @brief 栈的长度
 *
 * @param self
 * @return int
 */
int stack_length(stack *self);

/**
 * @brief 栈顶元素
 *
 */
#define stack_top(self, buf) \
    assert(self);            \
    assert(buf);             \
    (type *)buf = *(type *)self->top;

#endif