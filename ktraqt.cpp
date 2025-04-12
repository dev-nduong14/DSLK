#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node {
    char tenhv[100];
    int mahv;
    int tong_diem;
    struct node *next;
};
typedef struct node node;
struct dslk{
	node *phead;
	node *ptail;
};
node *make(int ma,char ten[],int diem){
	node *p = (node*)malloc(sizeof(node));
	p->mahv = ma;
	strcpy(p->tenhv,ten);
	p->tong_diem = diem;
	p->next = NULL;
	return p;
}
void them(dslk *list, int ma,char ten[],int diem) {
    node *p = make(ma,ten,diem);
    if (list->phead == NULL) {
        list->phead = p;
        list->ptail = p;
    } else {
        list->ptail->next = p;
        list->ptail = p;
    }
}
void taods(dslk *list){
	int ma;
	char ten[100];
	int diem;
	getchar();
	printf("Nhap ma sinh vien can them: ");scanf("%d",&ma);getchar();
	printf("Nhap ten sinh vien can them: ");gets(ten);
	printf("Nhap tong diem cua sinh vien do: ");scanf("%d",&diem);
	them(list,ma,ten,diem);
}
void chen(dslk *list, int ma, char ten[], int diem, char name[]) {
    node *p = make(ma, ten, diem);
    if (list->phead != NULL && strcmp(list->phead->tenhv, name) == 0) {
        p->next = list->phead;
        list->phead = p;
        return;
    }
    for (node *k = list->phead; k != NULL && k->next != NULL; k = k->next) {
        if (strcmp(k->next->tenhv, name) == 0) {
            p->next = k->next;
            k->next = p;
            return;
        }
    }
}

void xoa(dslk *list, int diem) {
    for (node *t = list->phead, *k = NULL; t != NULL; ) {
        if (t->tong_diem == diem) {
            node *tmp = t;
            if (k == NULL) {
                list->phead = t->next;
                t = list->phead;
            } else {
                k->next = t->next;
                t = t->next;
            }
            free(tmp); 
        } else {
            k = t;
            t = t->next;
        }
    }
}
void xoa_diem_thap_nhat(dslk *list) {
    if (list->phead == NULL) return;

    // Bu?c 1: Tìm di?m th?p nh?t
    int min_diem = list->phead->tong_diem;
    for (node *t = list->phead->next; t != NULL; t = t->next) {
        if (t->tong_diem < min_diem) {
            min_diem = t->tong_diem;
        }
    }

    // Bu?c 2: Xóa các node có di?m == min_diem dùng vòng l?p for
    node *k = NULL;
    for (node *t = list->phead; t != NULL; ) {
        if (t->tong_diem == min_diem) {
            node *tmp = t;
            if (k == NULL) {
                list->phead = t->next;
                t = list->phead;
            } else {
                k->next = t->next;
                t = t->next;
            }
            free(tmp);
        } else {
            k = t;
            t = t->next;
        }
    }
}

void output(dslk *list){
	int i = 1;
	printf("\nSTT \t MA \t TEN \t DIEM\n");
	for(node *p = list->phead;p!=NULL;p=p->next){
		printf("%d \t %d \t %s \t %d.\n",i++,p->mahv,p->tenhv,p->tong_diem);
	}
}
int main(){
	dslk list;
	list.phead = NULL;
	list.ptail = NULL;
	while(1){
		printf("\n");
		printf("1.Tao danh sach sinh vien.\n");
		printf("2.Chen 1 sinh vien.\n");
		printf("3.Loai cac hoc vien co diem nhap tu ban phim.\n");
		printf("4.In danh sach.\n");
		int lc;
		printf("Chon: ");scanf("%d",&lc);
		if(lc == 1){
			int n ;
			printf("Nhap so luong hoc vine can them: ");scanf("%d",&n);
			for(int  i = 0 ; i < n;i++){
				taods(&list);
			}
		}
		if(lc == 2){
			int ma;
			char ten[100];
			char name[100];
			int diem;
			getchar();
			printf("Nhap ten can chen: ");gets(ten);
			printf("Vi tri can chen la sau ten: ");gets(name);
			printf("Nhap ma hoc vien: ");scanf("%d",&ma);
			printf("Nhap diem hoc vien: ");scanf("%d",&diem);
			chen(&list,ma,ten,diem,name);
		}
		else if(lc == 3){
			int d;
			printf("Nhap tong diem: ");scanf("%d",&d);
			xoa(&list,d);getchar();
		}
		else if(lc == 4){
			output(&list);
		}
		else if(lc == 5){
		xoa_diem_thap_nhat(&list);
		}
	}
}
