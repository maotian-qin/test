//#include<stdio.h>
//#include<malloc.h>
//typedef int ElemType;
//typedef struct DNode {
//	ElemType data;
//	struct DNode* prior;
//	struct DNode* next;
//}DLinkNode;
//
//void CreateListF(DLinkNode*& L, ElemType a[], int n) {
//	DLinkNode* s;
//	L = (DLinkNode*)malloc(sizeof(DLinkNode));
//	L->prior = L->next = NULL;
//	for (int i = 0; i < n; i++) {
//		s = (DLinkNode*)malloc(sizeof(DLinkNode));
//		s->data = a[i];
//		s->next = L->next;
//		if (L->next != NULL)
//			L->next->prior = s;
//		L->next = s;
//		s->prior = L;
//	}
//}
//
//void CreateListR(DLinkNode*& L, ElemType a[], int n) {
//	DLinkNode* s, * r;
//	L = (DLinkNode*)malloc(sizeof(DLinkNode));
//	L->prior = L->next = NULL;
//	r = L;
//	for (int i = 0; i < n; i++) {
//		s = (DLinkNode*)malloc(sizeof(DLinkNode));
//		s->data = a[i];
//		r->next = s;
//		s->prior = r;
//		r = s;
//	}
//}
//
//void InitList(DLinkNode*& L) {
//	L = (DLinkNode*)malloc(sizeof(DLinkNode));
//	L->prior = L->next = NULL;
//}
//
//void DestroyList(DLinkNode*& L) {
//	DLinkNode* pre = L, * p = pre->next;
//	while (p != NULL) {
//		free(pre);
//		pre = p;
//		p = pre->next;
//	}
//	free(p);
//}
//
//bool ListEmpty(DLinkNode* L) {
//	return (L->next == NULL);
//}
//
//int ListLength(DLinkNode* L) {
//	DLinkNode* p = L;
//	int i = 0;
//	while (p ->next!= NULL) {
//		p = p->next;
//		i++;
//	}
//	return i;
//}
//
//void DispList(DLinkNode* L) {
//	DLinkNode* p = L->next;
//	while (p != NULL) {
//		printf("%c", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
//bool GetElem(DLinkNode* L, int i, ElemType& e) {
//	int j=0;
//	DLinkNode* p = L;
//	if (i <= 0)
//		return false;
//	while (j < i && p != NULL) {
//		j++;
//		p = p->next;
//	}
//	if (p == NULL) {
//		return false;
//	}
//	else {
//		e = p->data;
//		return true;
//	}
//}
//
//int LocateElem(DLinkNode* L, ElemType e) {
//	int i = 1;
//	DLinkNode* p = L->next;
//	while (p != NULL && p->data != e) {
//		i++;
//		p = p->next;
//	}
//	if (p == NULL)
//		return 0;
//	else
//		return 1;
//}
//
//bool ListInsert(DLinkNode*& L, int i, ElemType e) {
//	int j = 0;
//	DLinkNode* p = L, * s;
//	if (i <= 0)
//		return false;
//	while (j < i - 1 && p != NULL) {
//		j++;
//		p = p->next;
//	}
//	if (p == NULL)
//		return false;
//	else {
//		s = (DLinkNode*)malloc(sizeof(DLinkNode));
//		s->data = e;
//		s->next = p->next;
//		if (p->next != NULL)
//			p->next->prior = s;
//		s->prior = p;
//		p->next = s;
//		return true;
//	}
//}
//
//	bool ListDelete(DLinkNode * &L, int i, ElemType & e) {
//			int j = 0;
//			DLinkNode* p = L, * q;
//			if (i<= 0)
//				return false;
//			while (j < i - 1 && p != NULL) {
//				j++;
//				p = p->next;
//			}
//			if (p == NULL)
//				return false;
//			else {
//				q = p->next;
//				if (q == NULL)
//					return false;
//				e = q->data;
//				p->next = q->next;
//				if (p->next != NULL)
//					p->next->prior = p;
//				free(q);
//				return true;
//			}
//		}
//
//	int main(){
//		DLinkNode* h;
//		ElemType e;
//		printf("双链表的基本运算如下:\n");
//		printf("（1）初始化双链表h\n");
//		InitList(h);
//		printf("（2）依次采用尾插法插入元素a,b,c,d,e\n");
//		ListInsert(h, 1, 'a');
//		ListInsert(h, 2, 'b');
//		ListInsert(h, 3, 'c');
//		ListInsert(h, 4, 'd');
//		ListInsert(h, 5, 'e');
//		printf("（3）输出双链表h:");
//		DispList(h);
//		printf("（4）双链表长度%d\n", ListLength(h));
//		printf("（5）双链表为%s\n", (ListEmpty(h) ? "空" : "非空"));
//		GetElem(h, 3, e);
//		printf("（6）双链表的第三个元素%c\n", e);
//		printf("（7）元素a的位置%d\n", LocateElem(h, 'a'));
//		printf("（8）在第4个元素位置上插入元素f\n");
//		ListInsert(h, 4, 'f');
//		printf("(9)输出双链表h");
//		DispList(h);
//		printf("（10）删除h的第三个元素\n");
//		ListDelete(h, 3, e);
//		printf("(11)输出双链表h:");
//		DispList(h);
//		printf("释放双链表h\n");
//		DestroyList(h);
//		return 1;
//	}
//
//
