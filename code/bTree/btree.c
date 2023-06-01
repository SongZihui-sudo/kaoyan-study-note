#include <btree.h>

void btree_init(btree *self, void *data)
{
}

void btree_push_back(btree *self, void *data)
{
}

size_t btree_num(btree *self)
{
}

size_t btree_height(btree *self) {}

int btree_empty(btree *self) {}

int btree_get(btree *self, string key) {}

int btree_pre_order(btree *self) {}

int btree_in_order(btree *self) {}

int btree_post_order(btree *self) {}

void btree_replace(btree *self, string key, void *value) {}

void btree_delete(btree *self, string key) {}