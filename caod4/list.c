#include <stdio.h>
#include <malloc.h>
#include <assert.h>
struct TList {
    int value;
    struct TList *next;

};
typedef struct TList* TList;
typedef struct TList list;



list *list_create(int val){
	TList l;
	l=(TList*)malloc(sizeof(TList));
	l->value=val;
	l->next=NULL;
	return l;

}

void list_print(TList *head){
	TList curr=head;
	while (curr!=NULL){
		printf("%d ",curr->value);
		curr=curr->next;
	}

}

void Remove(TList *A) {
assert(*A != NULL);
TList a = (*A)->next;
free(*A);
*A = a;
}


















/*list *list_create(int val, int val1){
    list *l;
    l=(list*)malloc(sizeof(list));
    l->value=val;
    l->value=val1;
    l->next=NULL;
    return l;

}

void list_print(list *head){
    list *curr=head;
    while (curr!=NULL){
        printf("%d ",curr->value);
        curr=curr->next;
    }

}
list *list_add(list *l, int num){
    list *t, *p;
    t=(list*)malloc(sizeof(list));
    p=l->next;
    l->next=t;
    t->value=num;
    t->next=p;
    return t ;

}


int main(){
    list *list_1=NULL;
    list_1=list_create(10, 19);
    list_print(list_1);
    list_1=list_add(list_1, 6);
    list_print(list_1);
    return 0;
}
*/

 