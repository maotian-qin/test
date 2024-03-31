//#include<stdio.h>
//#include<malloc.h>
//typedef char ElemType;
//
//typedef struct  LNode {
//	ElemType data;
//	struct LNode* next;
//}LinkNode;
//
//void CreateListF(LinkNode*& L, ElemType a[], int n) {
//	LinkNode* s;
//	L = (LinkNode*)malloc(sizeof(LinkNode));
//	L->next = NULL;
//	for (int i = 0; i < n; i++) {
//		s = (LinkNode*)malloc(sizeof(LinkNode));
//		s->data = a[i];
//		s->next = L->next;
//		L->next = s;
//	}
//}
//
//void CreateListR(LinkNode*& L, ElemType a[], int n) {
//	LinkNode* s, * r;
//	L = (LinkNode*)malloc(sizeof(LinkNode));
//	L->next = NULL;
//	r = L;
//	for (int i = 0; i < n; i++) {
//		s = (LinkNode*)malloc(sizeof(LinkNode));
//		s->data = a[i];
//		r->next = s;
//		r = s;
//	}
//	r->next = NULL;
//}
//
//void InitList(LinkNode*& L) {
//	L = (LinkNode*)malloc(sizeof(LinkNode));
//	L->next = NULL;
//}
//
//void DestroyList(LinkNode*& L) {
//	LinkNode* pre = L, * p = pre->next;
//	while (p != NULL) {
//		free(pre);
//		pre = p;
//		p = pre->next;
//	}
//	free(pre);
//}
//
//bool ListEmpty(LinkNode* L) {
//	return (L->next == NULL);
//}
//
//int ListLength(LinkNode* L) {
//	int i = 0;
//	LinkNode* p = L;
//	while (p->next != NULL) {
//		i++;
//		p = p->next;
//	}
//	return i;
//}
//
//void DispList(LinkNode* L) {
//	LinkNode* p = L->next;
//	while (p != NULL) {
//		printf("%c ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
//bool GetElem(LinkNode* L, int i, ElemType &e) {
//	int j = 0;
//	LinkNode* p = L;
//	if (i <= 0)
//		return false;
//	while (j < i && p != NULL) {
//		j++;
//		p = p->next;
//	}
//	if (p == NULL)
//		return false;
//	else {
//		e = p->data;
//		return true;
//	}
//}
//
//int LocateElem(LinkNode* L, ElemType e) {
//	int i = 1;
//	LinkNode* p = L->next;
//	while (p != NULL && p->data != e) {
//		p = p->next;
//		i++;
//	}
//	if (p == NULL)
//		return 0;
//	else
//		return i;
//}
//
//bool ListInsert(LinkNode*& L, int i, ElemType e) {
//	int j = 0;
//	LinkNode* p = L, *s;
//	if (i <= 0)
//		return false;
//	while (j < i - 1 && p!= NULL) {
//		j++;
//		p = p->next;
//	}
//	if (p == NULL)
//		return false;
//	else {
//		s = (LinkNode*)malloc(sizeof(LinkNode));
//		s->data = e;
//		s->next = p->next;
//		p->next = s;
//		return true;
//	}
//}
//
//bool ListDelete(LinkNode*& L, int i, ElemType& e) {
//	int j = 0;
//	LinkNode* p = L, * q;
//	if (j <= 0)
//		return false;
//	while (j < i - 1 && p != NULL) {
//		j++;
//		p = p->next;
//	}
//	if (p == NULL)
//		return false;
//	else {
//		q = p->next;
//		if (q == NULL)
//			return false;
//		e = q->data;
//		p->next = q->next;
//		free(q);
//		return true;
//	}
//}
//
//int main() {
//	LinkNode* h;
//	ElemType e;
//	printf("������Ļ�����������:\n");
//	printf("(1)��ʼ��������h\n");
//	InitList(h);
//	printf("(2)���β���β�巨����Ԫ��a,b,c,d,e\n");
//	ListInsert(h, 1, 'a');
//	ListInsert(h, 2, 'b');
//	ListInsert(h, 3, 'c');
//	ListInsert(h, 4, 'd');
//	ListInsert(h, 5, 'e');
//	printf("(3)���������h:"); DispList(h);
//	printf("(4)������h���ȣ�%d\n", ListLength(h));
//	printf("(5)������hΪ%s\n", (ListEmpty(h)?"��":"�ǿ�"));
//	GetElem(h, 3, e);
//	//DispList(h);
//	printf("(6)������h�ĵ�����Ԫ�أ�%c\n", e);
//	printf("(7)Ԫ��a��λ�ã�%d\n", LocateElem(h, 'a'));
//	printf("(8)�ڵ�4��Ԫ��λ���ϲ���Ԫ��f\n");
//	ListInsert(h, 4, 'f');
//	printf("(9)���������h:"); DispList(h);
//	printf("(10)ɾ��h�ĵ�����Ԫ��\n");
//	ListDelete(h, 3, e);
//	printf("(11)���������h:"); DispList(h);
//	printf("(12)�ͷŵ�����h\n");
//	DestroyList(h);
//	return 0;
//}