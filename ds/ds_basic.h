#ifndef _DS_BASIC_H_
#define _DS_BASIC_H_

struct SLNode{
	int value;
	struct SLNode *next;
};
typedef struct SLNode SLNode;

struct STNode{
	int value;
	struct STNode *pre;
};
typedef struct STNode STNode;

struct TreeNode{
	int value;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
};
typedef struct TreeNode TNode;


#endif
