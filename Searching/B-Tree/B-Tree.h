#ifndef _BTREE_HEADER_H
#define _BTREE_HEADER_H

#define M 5
#define max_children 2*M
#define max_keys max_children-1
#define min_keys M-1 // 최소 키개수 구하는 식

struct BTreeNode{
    bool leaf; // leaf여부 
    int key[max_keys+1]; // key를 담을 배열
    int cnt_key; // 키 개수 확인용
    struct BTreeNode* child[max_children+1]; // 자식 포인터배열 (노드들이 배열로)
    int cnt_child; // 자식 개수 확인용
};
struct BTreeNode* root;
struct BTreeNode* createNode(int val);
struct BTreeNode* splitNode(int pos, struct BTreeNode* node, struct BTreeNode* parent);
struct BTreeNode* insertNode(int parent_pos, int val, struct BTreeNode* node, struct BTreeNode* parent);

void insert(int val);

int searchNode(struct BTreeNode* node, int val);

void mergeNode(struct BTreeNode* par_node, int node_pos, int mer_node_pos);
void borrowFromLeft(struct BTreeNode* par_node, int cur_node_pos);
void borrowFromRight(struct BTreeNode* par_node, int cur_node_pos);
void balanceNode(struct BTreeNode* node, int child_pos);
int mergeChildNode(struct BTreeNode* par_node, int cur_node_pos);

int findPredecessor(struct BTreeNode* cur_node);
int overrideWithPredecessor(struct BTreeNode* par_node, int pos_std_search);
int findSuccessor(struct BTreeNode* cur_node);
int overrideWithSuccessor(struct BTreeNode* par_node, int pos_std_search);

int deleteValFromNode(int val, struct BTreeNode* node);
void deleteInnerNode(struct BTreeNode* cur_node, int cur_node_pos);
int deleteValFromNode(int val, struct BTreeNode* node);
void delete(struct BTreeNode* node, int val);

void printTree(struct BTreeNode* node, int level);

#endif /* _BTREE_HEADER_H*/