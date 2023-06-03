#include <btree.h>

void btree_node_init(btree_node *self)
{
    assert(self);
    self->ltag = 1;
    self->rtag = 1;
    self->left = (btree_node *)malloc(sizeof(btree_node));
    self->right = (btree_node *)malloc(sizeof(btree_node));
}

void btree_node_destory(btree_node *self)
{
    assert(self);
    free(self->left);
    free(self->right);
    string_destory(&self->key);
    free(self->value);
}

void btree_init(btree *self, list *value, list *key)
{
    assert(self);
    assert(value);
    assert(key);
    if (key->length != value->length)
    {
        return;
    }
    self->root = (btree_node *)malloc(sizeof(btree_node));
    btree_node_init(self->root);
    deque *tmp = (deque *)malloc(sizeof(deque));
    self->root->value = list_get(value, 0);
    self->root->key = *(string *)list_get(key, 0);
    deque_init(tmp);
    deque_push_back(tmp, self->root);
    size_t i = 0;
    self->num = value->length;
    while (!deque_empty(tmp))
    {
        btree_node *cur = (btree_node *)tmp->top;
        btree_node_init(cur->left);
        cur->left->key = *(string *)list_get(key, ++i);
        cur->left->value = list_get(value, i);
        cur->ltag = 0;
        if (i > value->length)
        {
            break;
        }
        btree_node_init(cur->right);
        cur->right->key = *(string *)list_get(key, ++i);
        cur->right->value = list_get(value, i);
        cur->rtag = 0;
        if (i > value->length)
        {
            break;
        }
        deque_push_back(tmp, cur->left);
        deque_push_back(tmp, cur->right);
        self->h++;
    }
}

size_t btree_num(btree *self)
{
    assert(self);
    return self->num;
}

size_t btree_height(btree *self)
{
    assert(self);
    return self->h;
}

int btree_empty(btree *self)
{
    assert(self);
    if (!self->num)
    {
        return 1;
    }
    return 0;
}

btree_node* btree_pre_order(btree_node *self, string key)
{
    assert(self);
    if (!string_cmp(&self->key, &key))
    {
        return self;
    }
    if (self->left)
    {
        btree_pre_order(self->left, key);
    }
    if (self->right)
    {
        btree_pre_order(self->right, key);
    }
}

btree_node* btree_in_order(btree_node *self, string key)
{
    assert(self);
    if (self->left)
    {
        btree_pre_order(self->left, key);
    }
    if (!string_cmp(&self->key, &key))
    {
        return self;
    }
    if (self->right)
    {
        btree_pre_order(self->right, key);
    }
}

btree_node* btree_post_order(btree_node *self, string key)
{
    assert(self);
    if (self->left)
    {
        btree_pre_order(self->left, key);
    }
    if (self->right)
    {
        btree_pre_order(self->right, key);
    }
    if (!string_cmp(&self->key, &key))
    {
        return self;
    }
}

void btree_replace(btree *self, string key, void *value)
{
    assert(self);
    assert(value);
    btree_node *tmp = btree_pre_order(self->root, key);
    // btree_node *tmp = btree_in_order(self->root, key);
    // btree_node *tmp = btree_post_order(self->root, key);
    tmp->value = value;
}

void btree_delete(btree *self, string key)
{
    assert(self);
    btree_node *tmp = btree_pre_order(self->root, key);
    // btree_node *tmp = btree_in_order(self->root, key);
    // btree_node *tmp = btree_post_order(self->root, key);
    string_copy(&tmp->key, "");
    tmp->value = NULL;
}

void btree_destory(btree *self)
{
    assert(self);
    btree_node_destory(self->root);
    self->h = 0;
    self->num = 0;
}