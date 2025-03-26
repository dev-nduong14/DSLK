#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	int data;
	struct node *next;//link
};
typedef struct node node; 
node* makeNode(int x){
//tao 1 node moi co data la so x
// cap phat dong 1 node
node *newNode = (node*)malloc(sizeof(node));
newNode->data = x;
newNode->next = NULL;
return newNode;
}

//them node vao DSLK
void pushFront(node **head,int x){
	 node *newNode = makeNode(x);
      newNode->next =(*head);
      (*head) = newNode;
}
void pushback(node **head,int x){
	node *newNode = makeNode(x);
	node *temp = (*head);
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}
void duyet(node *head){
	while(head !=NULL){
		printf("%d ",head->data);
		head =head->next;
	}
}
int size(node *head){
	int k = 0;
	while(head != NULL){
		++k;
		head = head->next;
	}
	return k;
}
void insert(node **head, int k, int x) {
    int n = size(*head);
    if (k < 1 || k > n + 1) {
        printf("V? trí không h?p l?!\n");
        return;
    }
    if (k == 1) { 
        pushFront(head, x);
    } else if (k == n + 1) {
        pushback(head, x);
    } else { 
        node *temp = *head;
        for (int i = 1; i < k - 1; i++) {
            temp = temp->next;
        }
        node *newNode = makeNode(x);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
int main(){
node *head = NULL;
while(1){
	printf("\n-----------------------\n");
	printf("1.Them vao cuoi \n");
	printf("2.Them vao dau\n");
	printf("3.chen vao giua\n");
	printf("4.Duyet vao dslk\n");
	printf("0.Thoat\n");
	printf("\n------------------------\n");
	printf("Nhap lua chon \n:");
	int lc;scanf("%d",&lc);
	if(lc ==1){
		printf("Nhap gia tri can them:");
		int x;scanf("%d",&x);
		pushFront(&head,x);
	}
	else if(lc == 2){
	int x;
	scanf("%d",&x);
	pushback(&head,x);
	}
	else if( lc == 3){
		printf("nhap vi tri chen : ");
	int k ; scanf("%d",&k);
	printf("Nhap gia tri can chen:");
	int x;scanf("%d",&x);
	insert(&head,k,x);
	
	}
	else if(lc ==4){
		duyet(head);
	}
	else if(lc == 0){
		break;
	}
}

	return 0;
}
