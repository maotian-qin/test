#include<stdio.h>
#include<malloc.h>

typedef struct {
	int no;
	char name[10];
	int depno;
	float salary;
}EmpType;
typedef struct node {
	EmpType data;
	struct node* next;
}EmpList;

void DestroyEmp(EmpList*& L) {
	EmpList* pre = L, * p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

void DelAll(EmpList*& L) {
	FILE* fp;
	if ((fp = fopen("emp.dat", "wb")) == NULL) {
		printf("��ʾ�����ܴ�ְ���ļ�\n");
		return;
	}
	fclose(fp);
	DestroyEmp(L);
	L = (EmpList*)malloc(sizeof(EmpList));
	L->next = NULL;
	printf("��ʾ��ְ������������\n");
}

void ReadFile(EmpList*& L) {
	FILE* fp;
	EmpType emp;
	EmpList* p, * r;
	int n = 0;
	L = (EmpList*)malloc(sizeof(EmpList));
	r = L;
	if ((fp = fopen("emp.dat", "rb")) == NULL) {
		if ((fp = fopen("emp.dat", "wb")) == NULL)
			printf("��ʾ�����ܴ���\n");
	}
	else {
		while (fread(&emp, sizeof(EmpType), 1, fp) == 1) {
			p = (EmpList*)malloc(sizeof(EmpList));
			p->data = emp;
			r->next = p;
			r = p;
			n++;
		}
	}
	r->next = NULL;
	printf("��ʾ��������ϣ���%d����¼\n", n);
}

void SaveFile(EmpList* L) {
	EmpList* p = L->next;
	int n = 0;
	FILE* fp;
	if ((fp = fopen("emp.dat", "wb")) == NULL) {
		printf("��ʾ�����ܴ����ļ�emp.dat");
		return;
	}
	while (p != NULL) {
		fwrite(&p->data, sizeof(EmpType), 1, fp);
		p = p->next;
		n++;
	}
	fclose(fp);
	DestroyEmp(L);
	if (n > 0)
		printf("��%d��ְ����¼д��emp.dat\n", n);
	else
		printf("û��д��\n");
}

void InputEmp(EmpList*& L) {
	EmpType p;
	EmpList* s;
	printf(" >>����ְ����(-1)���أ�");
	scanf("%d", &p.no);
	if (p.no == -1)
		return;
	printf(" >>�������� ���ź� ���ʣ�");
	scanf("%s%d%f", &p.name, &p.depno, &p.salary);
	s = (EmpList*)malloc(sizeof(EmpList));
	s->data = p;
	s->next = L->next;
	L->next = s;
	printf("��ʾ����ӳɹ�\n");
}

void DelEmp(EmpList*& L) {
	EmpList* pre = L, * p = L->next;
	int no;
	printf("  >>����ְ���ţ�-1���أ���");
	scanf("%d", &no);
	if (no == -1)
		return;
	while (p != NULL && p->data.no != no) {
		pre = p;
		p = p->next;
	}
	if (p == NULL)
		printf("��ʾ��ָʾ��ְ����¼������\n");
	else {
		pre->next = p->next;
		free(p);
		printf("��ʾ��ɾ���ɹ�\n");
	}
}

void Sortno(EmpList*& L) {
	EmpList* p, * pre, * q;
	p = L->next->next;
	if (p != NULL) {
		L->next->next = NULL;
		while (p != NULL) {
			q = p->next;
			pre = L;
			while (pre->next != NULL && pre->next->data.no < p->data.no)
				pre = pre->next;
			p->next = pre->next;
			pre->next = p;
			p = q;
		}
	}
	printf("��ʾ����no��������\n");
}

void Sortdepno(EmpList*& L) {
	EmpList* p, * pre, * q;
	p = L->next->next;
	if (p != NULL) {
		L->next->next = NULL;
		while (p != NULL) {
			q = p->next;
			pre = L;
			while (pre->next != NULL && pre->next->data.depno < p->data.depno)
				pre = pre->next;
			p->next = pre->next;
			pre->next = p;
			p = q;
		}
	}
	printf("��ʾ����depno�����������\n");
}

void Sortsalary(EmpList*& L) {
	EmpList* p, * pre, * q;
	p = L->next->next;
	if (p != NULL) {
		L->next->next = NULL;
		while (p != NULL) {
			q = p->next;
			pre = L;
			while (pre->next != NULL && pre->next->data.salary < p->data.salary)
				pre = pre->next;
			p->next = pre->next;
			pre->next = p;
			p = q;
		}
	}
	printf("��ʾ����salary�����������\n");
}

void DispEmp(EmpList* L) {
	EmpList* p = L->next;
	if (p == NULL)
		printf("��ʾ��û���κμ�¼\n");
	else {
		printf("ְ����   ����   ���ź�       ����");
		printf("-----------------------------------");
		while (p != NULL) {
			printf("%3d%10%-8d%7.2f\n", p->data.no, p->data.name, p->data.depno, p->data.salary);
			p = p->next;
		}
		printf("--------------------------------------");
	}
}

int main() {
	EmpList* L;
	int sel;
	printf("��emp.dat�ļ�����ְ��������L\n");
	ReadFile(L);
	do {
		printf(">1�����2����ʾ3����ְ��������4�������ź�����5������������\n");
		printf(">6��ɾ��9��ȫɾ0���˳� ��ѡ��:");
		scanf("%d", &sel);
		switch (sel) {
		case 9:DelAll(L); break;
		case 1:InputEmp(L); break;
		case 2:DispEmp(L); break;
		case 3:Sortno(L); break;
		case 4:Sortdepno(L); break;
		case 5:Sortsalary(L); break;
		case 6:DelEmp(L); break;
		}
	} while (sel != 0);
	SaveFile(L);
	return 1;
}