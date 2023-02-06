#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next; 
}node;

void push(node **head, int data){
    node *tmp = malloc(sizeof(node));
    tmp->next=*head;
    tmp->data=data;
    *head=tmp;

}

void print_list(const node *head){
    printf("stack: ");
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
}

int pop(node **head){
    int data;
    node *out;
    out=*head;
    data=out->data;
    *head=(*head)->next;
    free(out);
    return data;
}

int main(){
    node *head=NULL;
    push(&head,2);
    push(&head,4);
    push(&head,6);
    push(&head,9);
    print_list(head);
    pop(&head);
    print_list(head);
    
}