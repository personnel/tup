#ifndef tup_tupid_tree
#define tup_tupid_tree

#include "linux/rbtree.h"
#include "tupid.h"

struct tupid_tree {
	struct rb_node rbn;
	tupid_t tupid;
};

struct tupid_tree *tupid_tree_search(struct rb_root *root, tupid_t tupid);
int tupid_tree_insert(struct rb_root *root, struct tupid_tree *data);
int tupid_tree_add(struct rb_root *root, tupid_t tupid, tupid_t cmdid);
int tupid_tree_add_dup(struct rb_root *root, tupid_t tupid);
void free_tupid_tree(struct rb_root *root);

#endif