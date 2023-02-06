#include <stdio.h>
#include <stdlib.h>
#define MAX 50


struct Node  {
    int data;
    struct Node *left;
    struct Node *right;
};


struct Node *root = NULL;

struct Node *stack[MAX];
int top = -1;

void insert(struct Node **node, int val);
void search(struct Node *node, int val);


struct Node *createNode(int val) {
    struct Node *temp = NULL;
    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


void initStack() {
    for(int i=0; i<MAX; i++)
        stack[i] = NULL;
}

int isStackEmpty() {
    return (top==-1)?1:0;
}

int isStackFull() {
    return (top==MAX)?1:0;
}

void push(struct Node *node) {
        if(!isStackFull())
            stack[++top] = node;
        else printf("Stack is full...\n");
}

struct Node *pop() {
    if(!isStackEmpty())
        return stack[top--];
    else return NULL;
}


void inorder(struct Node *node) {
    struct Node *temp = NULL;
    temp = node;

    if(node == NULL) return;

    int flag = 0;
    
    initStack();
    while(!flag) {
        
        if(temp != NULL) {
            push(temp);
            temp = temp->left;
        } else {
            if(!isStackEmpty()) {
                temp = pop();
                printf("%d ",temp->data);

                temp = temp->right;
            } else flag = 1;
        }
    }
}

void insertNode(int val) {
    insert(&root, val);
}

void insert(struct Node **node, int val) {
    struct Node *temp = NULL;

    if(*node == NULL) {
        *node = createNode(val);
        return;
    } else {
        temp = *node;
        while(1) {
            if(val < temp->data) {
                if(temp->left == NULL) {
                    temp->left = createNode(val);
                    break;
                } 
                else 
                    temp = temp->left;
            } 
            else if(val > temp->data) {
                if(temp->right == NULL) {
                    temp->right = createNode(val);
                    break;
                } 
                else 
                    temp = temp->right;
            } 
        }
    }
    return;
}





/*void searchNode(int val) {
    search(root, val);
}*/

void search(struct Node *node, int val) {
    struct Node *temp = NULL;
    temp = node;

    if(temp == NULL) return;
    else {
        while(1) {
            if(val < temp->data) {
                if(temp->left != NULL) {
                    temp = temp->left;
                } else {
                    printf("No element ...\n");
                    break;
                }
            } else if(val > temp->data) {
                 if(temp->right != NULL) {
                    temp = temp->right;
                } else {
                    printf("No element ...\n");
                    break;
                }
            } else if (val == temp->data) {
                    printf("Element %d found .. \n", val);
                    break;
            }
        }

    }
}



int treeHeight(struct Node *node) {
    if(node == NULL) return 0;
    else {
        int leftheight = treeHeight(node->left);
        int rightheight = treeHeight(node->right);

        if(leftheight > rightheight)
            return leftheight+1;
        else
            return rightheight+1;
    }
}





int main() {

    insertNode(9);
    insertNode(7);
    insertNode(5);
    insertNode(8);
    insertNode(11);
    insertNode(10);
    insertNode(14);
    insertNode(15);

    inorder(root);

    printf("\n");

    search(root,7);

    printf("Height of the tree is : %d \n",treeHeight(root));
    
    

   
     return 0;
}
