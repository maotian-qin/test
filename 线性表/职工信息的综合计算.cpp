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
		printf("提示：不能打开职工文件\n");
		return;
	}
	fclose(fp);
	DestroyEmp(L);
	L = (EmpList*)malloc(sizeof(EmpList));
	L->next = NULL;
	printf("提示：职工数据清除完毕\n");
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
			printf("提示：不能创建\n");
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
	printf("提示，建立完毕，由%d个记录\n", n);
}

void SaveFile(EmpList* L) {
	EmpList* p = L->next;
	int n = 0;
	FILE* fp;
	if ((fp = fopen("emp.dat", "wb")) == NULL) {
		printf("提示：不能创建文件emp.dat");
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
		printf("有%d个职工记录写入emp.dat\n", n);
	else
		printf("没有写入\n");
}

void InputEmp(EmpList*& L) {
	EmpType p;
	EmpList* s;
	printf(" >>输入职工号(-1)返回：");
	scanf("%d", &p.no);
	if (p.no == -1)
		return;
	printf(" >>输入姓名 部门号 工资：");
	scanf("%s%d%f", &p.name, &p.depno, &p.salary);
	s = (EmpList*)malloc(sizeof(EmpList));
	s->data = p;
	s->next = L->next;
	L->next = s;
	printf("提示：添加成功\n");
}

void DelEmp(EmpList*& L) {
	EmpList* pre = L, * p = L->next;
	int no;
	printf("  >>输入职工号（-1返回）：");
	scanf("%d", &no);
	if (no == -1)
		return;
	while (p != NULL && p->data.no != no) {
		pre = p;
		p = p->next;
	}
	if (p == NULL)
		printf("提示：指示的职工记录不存在\n");
	else {
		pre->next = p->next;
		free(p);
		printf("提示：删除成功\n");
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
	printf("提示：按no递增排列\n");
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
	printf("提示：按depno递增排列完毕\n");
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
	printf("提示：按salary递增排列完毕\n");
}

void DispEmp(EmpList* L) {
	EmpList* p = L->next;
	if (p == NULL)
		printf("提示：没有任何记录\n");
	else {
		printf("职工号   姓名   部门号       工资");
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
	printf("由emp.dat文件建立职工单链表L\n");
	ReadFile(L);
	do {
		printf(">1：添加2：显示3：按职工号排序4：按部门号排序5：按工资排序\n");
		printf(">6：删除9：全删0：退出 请选择:");
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