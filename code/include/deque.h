#ifndef deque_h
#define deque_h

#include <linklist.h>
#include <stdlib.h>

typedef struct deque
{
    void *top;
    size_t length;
    linkList *buffer;
} deque;

/**
 * @brief 队列的首个元素
 *
 * @param self
 */
#define deque_top(self, buf, type) \
    assert(self);                  \
    assert(buf);                   \
    (type *)buf = *(type *)self->top;

/**
 * @brief 队列初始化
 *
 * @param self
 */
void deque_init(deque *self);

/**
 * @brief 删除最后一个元素
 *
 * @param self
 */
void deque_pop_back(deque *self);

/**
 * @brief 删除第一个元素
 *
 * @param self
 */
void deque_pop_front(deque *self);

/**
 * @brief 向队尾添加一个元素
 *
 * @param self
 * @param val
 */
void deque_push_back(deque *self, void *val);

/**
 * @brief 向队头添加一个元素
 *
 * @param self
 * @param val
 */
void deque_push_front(deque *self, void *val);

/**
 * @brief 队列受否为空
 *
 * @param self
 * @return int
 */
int deque_empty(deque *self);

/**
 * @brief 队列的长度
 *
 * @param self
 * @return int
 */
int deque_length(deque *self);

#endif