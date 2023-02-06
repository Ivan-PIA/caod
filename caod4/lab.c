#include <stdio.h> 
#include <malloc.h>
#include <assert.h>

struct TList {
	int value;
	struct TList *next;

};

typedef struct TList list;
typedef struct TList* list_; 

list *list_create(int val){
	list *l;
	l=(list*)malloc(sizeof(list));
	l->value=val;
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

list *delhead(list *root){
	list *t;
	t=root->next;
	free(root);
	return  t ;

}
/*list  *remove(list *l,list *root){
	list *t;
	t=root;

	while(t->next!=l){
	t=t->*l;
	}
	t->next=*l->next;
	free(l);
	return (t);
}
*/
void Remove(list_ *A) {
assert(*A != NULL);
list_ a = (*A)->next;
free(*A);
*A = a;
}

int main(){
	list *list_1=NULL;
	list_1=list_create(19);
	list_print(list_1);
	list_1=list_add(list_1, 6);
	list_print(list_1);
	list_1=list_add(list_1, 4);
	list_print(list_1);
	Remove(list_1);
	//delhead(list_1);
	return 0;
}

