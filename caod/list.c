#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next; 
}node;

void add(node **head, int data){
    node *tmp=(node*)malloc(sizeof(node));
    tmp->data=data;
    tmp->next=(*head);
    (*head)=tmp;
}

int pop(node **head){
    node *prev=NULL;
    int val;
    if(head==NULL){
        exit(-1);
    }
    prev=*head;
    *head=(*head)->next;
    val=prev->data;
    free(prev);
    
    return val;

}

node* get_el(node* head, int n){
    int c=0;
    while(c<n && head){
        head=head->next;
        c++;
    }
    return head;
}

int delete(node **head,int n){
    if(n==0){
        return pop(head);
    }
    else{
        node *prev=get_el(*head,n-1);
        node *elm=prev->next;
        int val=elm->data;

        prev->next=elm->next;
        free(elm);
        return val;
    }


}

int forarr(node **head, int *arr, int size){
    int i=size-1;
    if(i==0 || arr==NULL)
        return 0;
    do{
        add(head,arr[i]);
    }while(i--!=0);
}






void print_list(const node *head){
    while(head){
        printf("%d ",head->data);
        head=head->next;

    }
}

int main(){
    
    int arr[]={2,7,6,9};
    node *head=NULL;
   
     
     
     
    
    //pop(&head);
    
    printf("\n");

    forarr(&head,arr,4);
    
    add(&head,4);
    add(&head,6);
    delete(&head,5);
    print_list(head);



}