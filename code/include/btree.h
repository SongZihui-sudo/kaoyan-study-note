#ifndef btree_h
#define btree_h

#include <stdlib.h>
#include <mystring.h>
#include <stack.h>
#include <deque.h>

typedef struct btree_node
{
    btree_node* left;
    btree_node *right;
    void* value;
    string key;
} btree_node;

typedef struct btree
{
    size_t* h;
    size_t* num;
    btree_node* root;
} btree;

/**
 * @brief 二叉树初始化
 * 
 * @param self 
 * @param data 
 */
void btree_init(btree* self, void* data);

/**
 * @brief 添加一个元素
 * 
 * @param self 
 * @param data 
 */
void btree_push_back(btree* self, void* data);

/**
 * @brief 二叉树的节点个数
 * 
 * @param self 
 * @return size_t 
 */
size_t btree_num(btree* self);

/**
 * @brief 二叉树的高度
 * 
 * @param self 
 * @return size_t 
 */
size_t btree_height(btree* self);

/**
 * @brief 是否为空
 * 
 * @param self 
 * @return int 
 */
int btree_empty(btree* self);

/**
 * @brief 获取指定键值的元素
 * 
 * @param self 
 * @param index 
 * @return int 
 */
int btree_get(btree *self, string key);

/**
 * @brief 先序遍历
 * 
 * @param self 
 * @return int 
 */
int btree_pre_order(btree *self);

/**
 * @brief 中序遍历
 * 
 * @param self 
 * @return int 
 */
int btree_in_order(btree *self);

/**
 * @brief 后序遍历
 *
 * @param self
 * @return int
 */
int btree_post_order(btree *self);

/**
 * @brief 修改指定键值元素
 * 
 * @param self 
 * @param key 
 * @param value 
 * @return int 
 */
void btree_replace(btree* self, string key, void* value);

/**
 * @brief 删除指定键值
 * 
 * @param self 
 * @param key 
 */
void btree_delete(btree* self, string key);

#endif