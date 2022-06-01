#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left_child;
    struct node *right_child;
}Node;

Node* create_Node(int n){
    Node *node=(Node *)malloc(sizeof(Node));
    node->data=n;
    node->left_child=NULL;
    node->right_child=NULL;
    return node;
}

void add(Node *root, int add_num){
    Node* tmp = root;
    
    while(1){
        if((tmp->data)<=add_num){
            //현재 노드의 값보다 key(n)이 크거나 같을 경우, 오른쪽 하위트리 탐색
            if((tmp->right_child==NULL)){
                tmp->right_child=create_Node(add_num);
                break;
            }
            else{
                tmp=tmp->right_child;
            }
        }else{
            //현재 노드의 값보다 key(n)이 작을 경우, 왼쪽 하위트리 탐색
            if((tmp->left_child==NULL)){
                tmp->left_child=create_Node(add_num);
            }
            else{
                tmp=tmp->left_child;
            }
        }
    }
}

void print_BST(Node *root){
    if(root!=NULL){
        print_BST(root->left_child);
        printf("%d->", root->data);
        print_BST(root->right_child);
    }
}

void search_key(Node *root, int key){
    Node *tmp = root;
    int flag = 1;

    while(tmp!=NULL){
        if((tmp->data)==key){
            printf("key=%d found!\n", key);
            flag=0;
            break;
        }else if((tmp->data)<key){
            tmp=tmp->right_child;
        }else{
            tmp=tmp->left_child;
        }
    }
    
    if(flag==1){
        printf("Key does not exist!\n");
    }
}

int main(){
    Node *root=create_Node(1);
    add(root, 2);
    add(root, 3);
    add(root, 4);
    add(root, 5);
    add(root, 6);
    add(root, 7);
    print_BST(root);
    printf("end\n");

    search_key(root, 6);
    search_key(root, 8);
}