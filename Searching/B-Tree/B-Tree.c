#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "B-Tree.h"

int deleteValFromNode(int val, struct BTreeNode* node);

struct BTreeNode* root;

/**
 * @brief 
 * 탐색 함수
 * 1. 루트 노드에서 시작하여 key들을 순회하면서 검사한다.
 *  1-1. 만일 k와 같은 key를 찾았다면 검색을 종료한다.
 *  1-2. 검색하는 값과 key들의 대소관계를 비교하여, 검색하는 값이 key보다 작으면 자식노드로 내려간다.
 * 2. 해당 과정을 리프노드에 도달할 때까지 반복한다. 만일 리프노드에도 k와 같은 key가 없다면 검색을 종료한다.
 * @param node 
 * @param val 
 * @return int 
 */
int searchNode(struct BTreeNode* node, int val){
    if (!node){
        printf("key %d does not exist",val);
        return 0;
    }

    struct BTreeNode* level = node;
    while (true){
        int pos;
        for (pos=0; pos<level->cnt_key; pos++){
            if (val== level->key[pos]){
                printf("key %d exists!",val);
                return 1;
            }
            else if (val<level->key[pos]){
                break;
            }
        }
        if (level->leaf) break;
        level = level->child[pos];
    }
    printf("key %d does not exist",val);
    return 0;
}

/**
 * @brief Create a Node object
 * 
 * @param val 
 * @return struct BTreeNode* 
 */
struct BTreeNode* createNode(int val){ 
    struct BTreeNode* newNode;
    newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    newNode -> leaf = false;
    newNode -> key[0] = val;
    newNode -> cnt_key = 1;
    newNode -> cnt_child = 0;
    return newNode;
}

/**
 * @brief 
 * 최대로 가질 수 있는 키의 개수를 넘어서면 자식노드에서부터 부모노드방향으로 올라가며 키를 분리함.
 * 부모노드로 키를 올려, 부모 노드에서 다시 최대로 가질 수 있는 키의 개수를 초과하면 위의 과정을 반복한다.
 * 키를 루트 노드로 올려야한다면 새 루트노드를 만든다.
 * @param pos 
 * @param node 
 * @param parent 
 * @return struct BTreeNode* 
 */
struct BTreeNode* splitNode(int pos, struct BTreeNode* node, struct BTreeNode* parent){
    //중앙값 이용
    int median;
    median = node->cnt_key / 2;
    struct BTreeNode* right_node;

    right_node = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    right_node-> leaf = node->leaf;
    right_node-> cnt_key = 0;
    right_node-> cnt_child = 0;
    
    int num_iter = node->cnt_key;
    for(int i = median+1; i< num_iter; i++){
        right_node->key[i-(median+1)] = node->key[i];
        right_node ->cnt_key++;
        node->cnt_key--;
    }

    if (!node->leaf){
        num_iter = node->cnt_child;
        for (int i = median+1; i < num_iter; i++ ) {
            right_node->child[i-(median+1)] = node ->child[i];
            right_node-> cnt_child++;
            node->cnt_child--;
        }
    }

    if (node==root) {
        struct BTreeNode* new_parent_node;
        new_parent_node = createNode(node->key[median]);
        node->cnt_key--;
        new_parent_node->child[0] = node;
        new_parent_node->child[1] = right_node;

        new_parent_node->cnt_child = 2;
        return new_parent_node; 
    }
    else {
        for (int i= parent->cnt_key; i> pos; i--){
            parent->key[i] = parent->key[i-1];
            parent->child[i+1] = parent->child[i];
        }

        parent->key[pos]= node->key[median];
        parent->cnt_key++;
        node->cnt_key--;
        parent-> child[pos+1] = right_node;
        parent->cnt_child+=1;
    }
    return node;
}

struct BTreeNode* insertNode(int parent_pos, int val, struct BTreeNode* node, struct BTreeNode* parent) {  
    int pos;
    for (pos =0; pos < node->cnt_key; pos++ ) {
        if (val == node -> key[pos]){
            //printf("Duplicates are not permitted!\n");
            return node;
        }
        else if (val< node->key[pos]){ 
            break;
        }
    }
    if (!node->leaf) {
        node -> child[pos] = insertNode(pos, val, node->child[pos] ,node);
        if (node->cnt_key == max_keys +1){ 
            node = splitNode(parent_pos, node,parent);
        }
    }
    else {
        for (int i = node->cnt_key; i > pos; i--) {
            node -> key[i] = node->key[i-1];
            node -> child[i+1] = node->child[i];
        }

        node -> key[pos] = val;
        node -> cnt_key++;
        if (node-> cnt_key == max_keys+1){
            node = splitNode(parent_pos, node,parent);
        }
    }   
    return node;
}

/**
 * @brief 
 * B-Tree에 val을 삽입한다.
 * @param val 
 */
void insert(int val){
    if (!root){
        root = createNode(val);
        root -> leaf = true ;
        return;
    }
    else{
        root = insertNode(0,val,root,root);
    }
}

void mergeNode(struct BTreeNode* par_node, int node_pos, int mer_node_pos){
    int merge_idx = par_node->child[mer_node_pos]->cnt_key;
    par_node->child[mer_node_pos]->key[merge_idx]= par_node->key[mer_node_pos];
    par_node->child[mer_node_pos]->cnt_key++;

    for(int i=0; i<par_node->child[node_pos]->cnt_key; i++){
        par_node->child[mer_node_pos]->key[merge_idx+1+i] = par_node->child[node_pos]->key[i];
        par_node->child[mer_node_pos]->cnt_key++;
    }

    int merge_childidx = par_node->child[mer_node_pos]->cnt_child; 
    for (int i=0; i<par_node->child[node_pos]->cnt_child; i++){
        par_node->child[mer_node_pos]->child[merge_childidx+i] = par_node->child[node_pos]->child[i];
        par_node->child[mer_node_pos]->cnt_child++;
    }

    free(par_node->child[node_pos]); 
    for(int i = mer_node_pos; i < (par_node->cnt_key)-1; i++) {
        par_node->key[i] = par_node->key[i+1];
    }
    par_node->cnt_key--;

    for(int i = mer_node_pos+1; i<(par_node->cnt_child)-1; i++){ 
        par_node->child[i] = par_node->child[i+1];
    }
    par_node->cnt_child--;
}

void borrowFromLeft(struct BTreeNode* par_node, int cur_node_pos){
    int tenant_idx = 0; 

    for (int i=0; i< par_node->child[cur_node_pos]->cnt_key; i++){ 
        par_node->child[cur_node_pos]->key[i+1] = par_node->child[cur_node_pos]->key[i];
    }
    par_node->child[cur_node_pos]->key[tenant_idx] = par_node->key[cur_node_pos-1];
    par_node->child[cur_node_pos]->cnt_key++;

    int idx_from_sib_topar= (par_node->child[cur_node_pos-1]->cnt_key) -1;
    par_node->key[cur_node_pos-1] = par_node->child[cur_node_pos-1]->key[idx_from_sib_topar]; 
    par_node->child[cur_node_pos-1]->cnt_key--;

    if (par_node->child[cur_node_pos-1]->cnt_child>0){
        int tenant_childidx = (par_node->child[cur_node_pos-1]->cnt_child)-1; 
        for (int i = par_node->child[cur_node_pos]->cnt_child; i > 0; i--){
            par_node->child[cur_node_pos]->child[i] = par_node->child[cur_node_pos]->child[i-1];
        }

        par_node->child[cur_node_pos]->child[0] = par_node->child[cur_node_pos-1]->child[tenant_childidx]; 
        par_node->child[cur_node_pos]->cnt_child++;

        par_node->child[cur_node_pos-1]->cnt_child--;
    }
}

void borrowFromRight(struct BTreeNode* par_node, int cur_node_pos){ 
    int tenant_idx = par_node->child[cur_node_pos]->cnt_key; 
    par_node->child[cur_node_pos]->key[tenant_idx] = par_node->key[cur_node_pos]; 
    par_node->child[cur_node_pos]->cnt_key++;

    int idx_from_sib_topar= 0;
    par_node->key[cur_node_pos] = par_node->child[cur_node_pos+1]->key[idx_from_sib_topar]; // 부모노드는 빌려준 형제노드의 키를 들고온다.

    for (int i=0; i< (par_node->child[cur_node_pos+1]->cnt_key)-1; i++){ 
        par_node->child[cur_node_pos+1]->key[i] = par_node->child[cur_node_pos+1]->key[i+1];
    }
    par_node->child[cur_node_pos+1]->cnt_key--;

    int idx_from_sib = 0;

    if (par_node->child[cur_node_pos+1]->cnt_child>0){
        int tenant_childidx = par_node->child[cur_node_pos]->cnt_child;
        par_node->child[cur_node_pos]->child[tenant_childidx] = par_node->child[cur_node_pos+1]->child[idx_from_sib]; // 형제 노드 자식 빌려옴.
        par_node->child[cur_node_pos]->cnt_child++;

        for (int i = 0; i<par_node->child[cur_node_pos+1]->cnt_child-1; i++){
            par_node->child[cur_node_pos+1]->child[i] = par_node->child[cur_node_pos+1]->child[i+1];
        }
        par_node->child[cur_node_pos+1]->cnt_child--;
    }
}

void balanceNode(struct BTreeNode* node, int child_pos){ 
    if (child_pos==0){ 
        if (node->child[child_pos+1]->cnt_key > min_keys){ 
            borrowFromRight(node,child_pos);
        }
        else{
            mergeNode(node,child_pos+1,child_pos); 
        }
        return;
    }

    else if (child_pos == (node->cnt_key)){ 
        if (node->child[child_pos-1]->cnt_key > min_keys){ 
            borrowFromLeft(node,child_pos);
        }
        else{
            mergeNode(node,child_pos,child_pos-1);
        }
        return;
    }
    else{
        if (node->child[child_pos-1]->cnt_key > min_keys){
            borrowFromLeft(node,child_pos); 
        }
        else if (node->child[child_pos+1]->cnt_key > min_keys){
            borrowFromRight(node,child_pos);
        }
        else{
            mergeNode(node,child_pos,child_pos-1);
        }
        return;
    }
}

int mergeChildNode(struct BTreeNode* par_node, int cur_node_pos){
    int mergeidx = par_node->child[cur_node_pos]->cnt_key;
    int val_par_node = par_node->key[cur_node_pos];
    par_node->child[cur_node_pos]->key[mergeidx] = par_node->key[cur_node_pos]; 
    par_node->child[cur_node_pos]->cnt_key++;

    for (int i=0; i < par_node->child[cur_node_pos+1]->cnt_key; i++){
        par_node->child[cur_node_pos]->key[mergeidx+1+i] = par_node->child[cur_node_pos+1]->key[i];
        par_node->child[cur_node_pos]->cnt_key++;
    }
    for (int i=0; i< par_node->child[cur_node_pos+1]->cnt_child; i++){
        par_node->child[cur_node_pos]->child[mergeidx+1+i] = par_node->child[cur_node_pos+1]->child[i];
        par_node->child[cur_node_pos]->cnt_child++;
    }

    for (int i= cur_node_pos; i<par_node->cnt_key; i++){
        par_node->key[i] = par_node->key[i+1];
        par_node->cnt_key--;
    }
    for (int i = cur_node_pos+1; i < par_node->cnt_child; i++){
        par_node->child[i]= par_node->child[i+1];
        par_node->cnt_child--;
    }
    return val_par_node; 

}


int findPredecessor(struct BTreeNode* cur_node){
    int predecessor;
    if (cur_node->leaf){
        return cur_node->key[cur_node->cnt_key-1];
    }
    return findPredecessor(cur_node->child[(cur_node->cnt_child)-1]); 
}

int overrideWithPredecessor(struct BTreeNode* par_node, int pos_std_search){
    int predecessor = findPredecessor(par_node->child[pos_std_search]); 
    par_node->key[pos_std_search] = predecessor;
    return predecessor;
}


int findSuccessor(struct BTreeNode* cur_node){
    int successor;
    if (cur_node->leaf){ 
        return cur_node->key[0]; 
    }
    return findSuccessor(cur_node->child[0]); 
}

int overrideWithSuccessor(struct BTreeNode* par_node, int pos_std_search){
    int successor = findSuccessor(par_node->child[pos_std_search+1]); 
    par_node->key[pos_std_search] = successor; 
    return successor;
}

void deleteInnerNode(struct BTreeNode* cur_node, int cur_node_pos){
    int cessor = 0;
    int deletion_for_merge = 0;

    if (cur_node->child[cur_node_pos]->cnt_key >= cur_node->child[cur_node_pos+1]->cnt_key){ 
        if(cur_node->child[cur_node_pos]->cnt_key > min_keys){ 
            cessor = overrideWithPredecessor(cur_node,cur_node_pos);
            deleteValFromNode(cessor,cur_node->child[cur_node_pos]); 
        }
        else{
            deletion_for_merge = mergeChildNode(cur_node,cur_node_pos);
            deleteValFromNode(deletion_for_merge, cur_node->child[cur_node_pos]);
        }
    }
    else {
        if (cur_node->child[cur_node_pos+1]->cnt_key > min_keys){
            cessor = overrideWithSuccessor(cur_node,cur_node_pos);
            deleteValFromNode(cessor,cur_node->child[cur_node_pos+1]);
        }
        else{
            deletion_for_merge = mergeChildNode(cur_node,cur_node_pos);
            deleteValFromNode(deletion_for_merge, cur_node->child[cur_node_pos]);
        }

    }

}

/**
 * @brief 
 * node에서 val을 삭제
 * @param val 
 * @param node 
 * @return int 
 */
int deleteValFromNode(int val, struct BTreeNode* node){ 
    int pos;    
    int flag = false;
    for (pos=0; pos < node->cnt_key; pos++){
        if (val == node->key[pos]){
            flag = true;
            break;
        }
        else if (val< node->key[pos]){
            break;
        }
    }
    if (flag){
        if (node->leaf){
            for (int i = pos; i<node->cnt_key; i++){
                node->key[i] = node->key[i+1];
            }
            node->cnt_key--;
        }
        else {
                deleteInnerNode(node,pos);
        }
        return flag;
    }
    else {
        if (node->leaf) {
            return flag;
        }
        else{
            flag = deleteValFromNode(val, node->child[pos]); 
        }
    }
    if (node->child[pos]->cnt_key < min_keys){
        balanceNode(node,pos);
    }

    return flag;    
}


/**
 * @brief 
 * val을 B-Tree에서 삭제한다.
 * @param node 
 * @param val 
 */
void delete(struct BTreeNode* node, int val){
    if (!node){
        //printf("Empty tree!!\n");
        return;
    }
    int flag = deleteValFromNode(val,node);
    if (!flag){
        //printf("key %d does not exist in this tree. \n", val);
        return;
    }
    if (node->cnt_key == 0){
        node = node->child[0];
    }
    root = node;

}

/**
 * @brief 
 * print B-Tree
 * @param node 
 * @param level 
 */
void printTree(struct BTreeNode* node, int level) {
	if (!node) { 											
		printf("Empty tree!!\n");
		return;
	}
	printf("Level %d :   ", level);
	for (int i = 0; i < level - 1; i++) {
		printf("            ");
	}
	for (int i = 0; i < node->cnt_key; i++) {
		printf("%d ", node->key[i]);
	}
	printf("\n");
	level++;
	for (int i = 0; i < node->cnt_child; i++) {
		printTree(node->child[i], level);
	}
}