//#include<stdio.h>
//#include<malloc.h>¡¢
//#include<string.h>
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
//void Split1(LinkNode*& L) {
//	LinkNode* pre, * p, * q;
//	if (L->next == NULL || L->next->next == NULL)
//		return;
//	int x = L->next->data;
//	pre = L->next;
//	p = pre->next;
//	while (p != NULL) {
//		if (p->data < x) {
//			pre->next = p->next;
//			p->next = L->next;
//			L->next = p;
//			p = pre->next;
//		}
//		else {
//			pre = p;
//			p = pre->next;
//		}
//	}
//}
//
//void Split2(LinkNode*& L) {
//	LinkNode* p = L->next, * r, * L1, * r1;
//	if (L->next == NULL || L->next->next == NULL)
//		return;
//	int x = L->next->data;
//	r = L;
//	L1 = (LinkNode*)malloc(sizeof(LinkNode));
//	r1 = L1;
//	while (p != NULL) {
//		if (p->data < x) {
//			r->next = p;
//			r = p;
//			p = p->next;
//		}
//		else {
//			r1->next = p;
//			r1 = p;
//			p = p->next;
//		}
//	}
//	r1->next = NULL;
//	r->next = L1->next;
//	free(L1);
//}
//
//int main() {
//	LinkNode* L;
//	ElemType a[] = "dacaafaafafkqkopwfkeo";
//	int n = strlen(a);
//	printf("one\n");
//	CreateListR(L, a, n);
//	printf("L:"); DispList(L);
//	printf("\n");
//	Split1(L);
//	printf("L:"); DispList(L);
//	DestroyList(L);
//	printf("two\n");
//	CreateListR(L, a, n);
//	printf("L:"); DispList(L);
//	Split2(L);
//	printf("L:"); DispList(L);
//	DestroyList(L);
//	return 1;
//}