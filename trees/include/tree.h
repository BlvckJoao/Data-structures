#ifndef _TREE_H_
#define _TREE_H_

typedef struct tree Tree;

Tree* tree_create();
int tree_search(Tree* t, int info);
int tree_insert(Tree** t, int info);
int tree_delete(Tree** t, int info);
void free_tree(Tree** t);
void tree_print(Tree* t);

#endif
