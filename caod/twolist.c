#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

typedef struct dlinklist{
    int size;
    struct dlinklist *tail;
    struct dlinklist *head;
}list;

// cоздаем вторую структуру tail-null head-null
list* creatlinklist(){
    list *tmp=(list*)malloc(sizeof(list*));
    tmp->size=0;
    tmp->head=tmp->tail=NULL;
    return tmp;
} 


void push(list *l, int data){
    node *tmp=(node*)malloc(sizeof(node));
    if(tmp==NULL)
        exit(-1);
    tmp->data=data;
    tmp->next=l->head;
    tmp->prev=NULL;
    if(l->head){
        l->head=tmp->prev;
    }
    l->head=tmp;
    if(l->tail==NULL){
        l->tail=tmp;
    }
    l->size++;

}

void add(node **head, int data){
    node *tmp=(node*)malloc(sizeof(node));
    tmp->data=data;
    tmp->next=(*head);
    (*head)=tmp;
}


int main(){
    list *l=NULL;
}