//#include<stdio.h>
//#include<malloc.h>
//typedef int ElemType;
//typedef struct DNode {
//	ElemType data;
//	struct DNode* prior;
//	struct DNode *next;
//}DLinkNode;
//
//void CreateListF(DLinkNode*& L, ElemType a[], int n) {
//	DLinkNode* s;
//	L = (DLinkNode*)malloc(sizeof(DLinkNode));
//	L->next = NULL;
//	for (int i = 0; i < n; i++) {
//		s = (DLinkNode*)malloc(sizeof(DLinkNode));
//		s->data = a[i];
//		s->next = L->next;
//		if (L->next != NULL)
//			L->next->prior = s;
//		L->next = s;
//		s->prior = L;
//	}
//	s = L->next;
//	while (s->next != NULL)
//		s = s->next;//查找尾节点，由s指向它
//	s->next = L;
//	L->prior = s;
//}
//
//void CreateListR(DLinkNode*& L, ElemType a[],int n) {
//	DLinkNode* s, * r;
//	L = (DLinkNode*)malloc(sizeof(DLinkNode));
//	L->next = NULL;
//	r = L;
//	for (int i = 0; i < n; i++) {
//		s = (DLinkNode*)malloc(sizeof(DLinkNode));
//		s->data = a[i];
//		r->next = s;
//		s->prior = L;
//		r = s;
//	}
//	r->next = L;
//	L->prior = r;
//}
//
//void InitList(DLinkNode*& L) {
//	L = (DLinkNode*)malloc(sizeof(DLinkNode));
//	L->next =L->prior=L;
//}
//
//void DestroyList(DLinkNode*& L) {
//	DLinkNode* pre = L, * p = pre->next;
//	while (p!= L) {
//		free(pre);
//		pre = p;
//		p = pre->next;
//	}
//	free(pre);
//}
//
//bool ListEmpty(DLinkNode* L) {
//	return (L->next == L);
//}
//
//int ListLength(DLinkNode* L) {
//	DLinkNode* p = L;
//	int i = 0;
//	while (p->next != L) {
//		i++;
//		p = p->next;
//	}
//	return i; 
//}
//
//void DispList(DLinkNode* L) {
//	DLinkNode* p = L->next;
//	while (p != L) {
//		printf(" %c", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
//bool GetElem(DLinkNode* L, int i, ElemType& e) {
//	int j = 1;
//	DLinkNode* p = L->next;
//	if (i <= 0 || L->next == L)
//		return false;
//	if (i == 1) {
//		e = L->next->data;
//		return true;
//	}
//	else {
//		while (j <= i - 1 && p != L) {
//			j++;
//			p = p->next;
//		}
//		if (p == L)
//			return false;
//		else {
//			e = p->data;
//			return true;
//		}
//	}
//}
//
//int LocateElem(DLinkNode* L, ElemType e) {
//	int i = 1;
//	DLinkNode* p = L->next;
//	while (p != L && p->data != e) {
//		i++;
//		p = p->next;
//	}
//	if (p == L)
//		return 0;
//	else
//		return i;
//}
//
//bool ListInsert(DLinkNode*& L, int i, ElemType e) {
//	int j = 1;
//	DLinkNode* p = L, * s;
//	if (i <= 0)
//		return false;
//	if (p->next == L) {
//		s = (DLinkNode*)malloc(sizeof(DLinkNode));
//		s->data = e;
//		p->next = s;
//		s->next = p;
//		p->prior = s;
//		s->prior = p;
//		return true;
//	}
//	else if (i == 1) {
//		s = (DLinkNode*)malloc(sizeof(DLinkNode));
//		s->data = e;
//		s->next = p->next;
//		p->next = s;
//		s->next->prior = s;
//		s->prior = p;
//		return true;
//	}
//	else {
//		p = L->next;
//		while (j <= i - 2 && p != L) {
//			j++;
//			p = p->next;
//		}
//		if (p == L)
//			return false;
//		else {
//			s = (DLinkNode*)malloc(sizeof(DLinkNode));
//			s->data = e;
//			s->next = p->next;
//			if (p->next != NULL)
//				p->next->prior = s;
//			s->prior = p;
//			p->next = s;
//			return true;
//		}
//	}
//}
//
//bool ListDelete(DLinkNode*& L, int i, ElemType& e) {
//	int j = 1;
//	DLinkNode* p = L, * q;
//	if (i <= 0 || L->next == L)
//		return false;
//	if (i == 1) {
//		q = L->next;
//		e = q->data;
//		L->next = q->next;
//		q->next->prior = L;
//		free(q);
//		return true;
//	}
//	else {
//		p = L->next;
//		while (j <= i - 2 && p != NULL) {
//			j++;
//			p = p->next;
//		}
//		if (p == NULL) {
//			return 0;
//		}
//		else {
//			q = p->next;
//			if (q == NULL)
//				return 0;
//			e = q->data;
//			p->next = q->next;
//			if (p->next != NULL)
//				p->next->prior = p;
//			free(q);
//			return true;
//		}
//	}
//}
//
//int main() {
//	DLinkNode* h;
//	ElemType e;
//	printf("单链表的基本运算如下:\n");
//	printf("(1)初始化单链表h\n");
//	InitList(h);
//	printf("(2)依次采用尾插法插入元素a,b,c,d,e\n");
//	printf("2");
//	ListInsert(h, 1, 'a');
//	ListInsert(h, 2, 'b');
//	ListInsert(h, 3, 'c');
//	ListInsert(h, 4, 'd');
//	ListInsert(h, 5, 'e');
//	printf("(3)输出单链表h:"); DispList(h);
//	printf("(4)单链表h长度：%d\n", ListLength(h));
//	printf("(5)单链表h为%s\n", (ListEmpty(h)?"空":"非空"));
//	GetElem(h, 3, e);
//	DispList(h);
//	printf("(6)单链表h的第三个元素：%c\n", e);
//	printf("(7)元素a的位置：%d\n", LocateElem(h, 'a'));
//	printf("(8)在第4个元素位置上插入元素f\n");
//	ListInsert(h, 4, 'f');
//	printf("(9)输出单链表h:"); DispList(h);
//	printf("(10)删除h的第三个元素\n");
//	ListDelete(h, 3, e);
//	printf("(11)输出单链表h:"); DispList(h);
//	printf("(12)释放单链表h\n");
//	DestroyList(h);
//	return 1;
//}
