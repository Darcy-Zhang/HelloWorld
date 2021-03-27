#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct
{
	int num;
	float A;
	float B;
	float C;
	float D;
	float E;
	double av;
	double sum;
	char sex; //性别
} SD;			 //学生基本信息
typedef struct student
{
	char name[20]; //学生姓名
	SD XX;			//学生基本信息
	int rank;		//成绩排名
	struct student *next;
} Student, *List;

Student *startCheck(void);												  //密码检测
Student *createListHead(void);										  //创建链表的头
void menu(void);															  //主菜单
int Chioce(Student *pHead);											  //用户选择界面
int sortmenu(void);														  //选择的菜单
void passwordCheck(void);												  //密码检测
void changepw(void);														  //修改密码
void inputData(Student *pHead, Student *t);						  //输入信息
void readListfromFile(Student *pHead, const char *file_name); //从文件中读取数据，并保存在链表中
void lu(Student *pHead);												  //初始录入
void printList(Student *pHead);										  //打印链表
void add(Student *pHead);												  //增加功能
void del(Student *pHead);												  //删除学生信息
int delmenu(void);														  //删除的菜单
void saveList(Student *pHead);										  //将链表保存在文件里
void alter(Student *pHead);											  //修改学生信息
int altermenu(void);														  //修改的菜单
void find(Student *pHead);												  //查找
int findmenu(void);														  //查找的菜单
void sort(Student *pHead);												  //数组排序链表
void cr(Student *pHead);												  //插入数据
int turn(Student *p1, Student a[]);									  //链表数组转换
int main(void)
{
	Student *pHead;
	pHead = startCheck(); //读取信息
	while (1)
	{
		if (9 == Chioce(pHead)) //输入9的时候退出系统
		{
			break;
		}
	}

	return 0;
}
void menu(void)
{
	system("CLS"); //清屏

	printf("┏──────────────────────────────────┓\n");
	printf("│         学生成绩统计系统         │\n");
	printf("├──────────────────────────────────┤\n");
	printf("│         0   录入学生记录         │\n");
	printf("├──────────────────────────────────┤\n");
	printf("│         1   添加学生记录         │\n");
	printf("├──────────────────────────────────┤\n");
	printf("│         2   删除学生记录         │\n");
	printf("├──────────────────────────────────┤\n");
	printf("│         3   修改学生记录         │\n");
	printf("├──────────────────────────────────┤\n");
	printf("│         4   查找学生信息         │\n");
	printf("├──────────────────────────────────┤\n");
	printf("│         5   插入学生成绩         │\n");
	printf("├──────────────────────────────────┤\n");
	printf("│         6   浏览学生成绩         │\n");
	printf("├──────────────────────────────────┤\n");
	printf("│         7   排序学生成绩         │\n");
	printf("├──────────────────────────────────┤\n");
	printf("│         8  修改登陆密码          │\n");
	printf("├──────────────────────────────────┤\n");
	printf("│         9    退出系统            │\n");
	printf("├──────────────────────────────────┤\n");
}
Student *startCheck(void)
{
	Student *pHead;
	FILE *fp1;
	char password[20] = "123456";
	int i;

	if ((fp1 = fopen("password.dat", "rb")) == NULL) //若密码文件不存在，新建密码文件
	{
		fp1 = fopen("password.dat", "wb");
		fwrite(password, 20, 1, fp1);
		fclose(fp1);
		printf("欢迎使用本系统，密码初始化完成！（默认密码为：123456）");
		passwordCheck();
	}
	else
	{
		passwordCheck();
	}
	pHead = createListHead();
	readListfromFile(pHead, "stud.dat");

	return pHead;
}
int Chioce(Student *pHead)
{
	int a;
	menu();
	printf("请输入你要选择的选项序号：\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		lu(pHead);
		break;
	case 1:
		add(pHead);
		break;
	case 2:
		del(pHead);
		break;
	case 3:
		alter(pHead);
		break;
	case 4:
		find(pHead);
		break;
	case 5:
		cr(pHead);
		break;
	case 6:
		printList(pHead);
		break;
	case 7:
		sort(pHead);
		break;
	case 8:
		changepw();
		break;
	case 9:
		break;
	default:
		break;
	}

	return a;
}
void passwordCheck(void)
{
	char password[10], inputword[10];
	int i = 0, j = 0;
	char c = 0;
	FILE *fp = fopen("password.dat", "rb");
	fread(password, 6, 1, fp);
	for (i = 0; i < 5; i++)
	{
		printf("你还有%d次机会输入正确密码: ", 5 - i);
		j = 0;
		while (j < 6)
		{
			c = getch();
			if (c == '\b' && j > 0) //退格的功能
			{
				putchar('\b');
				putchar(' ');
				putchar('\b');
				j--;
			}
			else
			{
				putchar('*'); //保密功能
				inputword[j] = c;
				j++;
			}
		}
		inputword[j] = '\0';
		if (strcmp(inputword, password) == 0)
		{
			return;
		}
		else
		{
			system("CLS");
			printf("密码输入错误,请重新输入！");
		}
	}
	if (5 == i)
	{
		system("CLS");
		printf("你已浪费所有机会！程序即将退出！");
		exit(0);
	}
	fclose(fp);
	system("CLS");
	return;
}
void changepw(void)
{
	char password[6];
	FILE *fp;
	int i = 0;
	char c;
	system("CLS");
	printf("请输入新的密码：");
	while (i < 6)
	{
		c = getch();
		if (c == '\b' && i > 0)
		{
			putchar('\b');
			putchar(' ');
			putchar('\b');
			i--;
		}
		else
		{
			putchar('*');
			password[i] = c;
			i++;
		}
	}
	password[i] = '\0';
	printf("是否将密码修改为{%s}? (请输入Y或者N):", password);
	c = getch();
	if (c == 'Y' || c == 'y')
	{
		fp = fopen("password.dat", "wb");
		fwrite(password, 10, 1, fp);
		fclose(fp);
		printf("修改成功！\n");
	}
	else
	{
		return;
	}
}
Student *createListHead(void)
{
	Student *pHead;

	pHead = (List)malloc(sizeof(Student));
	pHead->next = NULL;

	return pHead;
}
void lu(Student *pHead)
{
	FILE *fp;
	Student *p1, *p2, *p3 = pHead;
	int rank = 0;
	char a;
	fp = fopen("stud.dat", "a");
	while (pHead->next)
	{
		pHead = pHead->next;
	}
	while (1)
	{
		p1 = (List)malloc(sizeof(Student));
		inputData(p3, p1);
		p1->next = NULL;
		pHead->next = p1;
		pHead = p1;
		fprintf(fp, "%d %s %c %f %f %f %f %f\n", p1->XX.num, p1->name, p1->XX.sex, p1->XX.A, p1->XX.B, p1->XX.C, p1->XX.D, p1->XX.E);
		printf("是否继续录入？(Y/N)");
		a = getch();
		if (a == 'n' || a == 'N')
		{
			break;
		}
	}
	SD d;
	char stu_name[20];
	for (p1 = p3->next; p1 != NULL; p1 = p1->next)
	{
		for (p2 = p1->next; p2 != NULL; p2 = p2->next)
		{
			if (p2->XX.sum > p1->XX.sum)
			{
				d = p2->XX;
				strcpy(stu_name, p2->name);
				p2->XX = p1->XX;
				strcpy(p2->name, p1->name);
				p1->XX = d;
				strcpy(p1->name, stu_name);
			}
		}
		p1->rank = ++rank; //初始排名
	}
	fclose(fp);
}
void add(Student *pHead)
{
	FILE *fp;
	Student *p1, *p2, *p3 = pHead;
	int rank = 0;
	char a;
	fp = fopen("stud.dat", "a");
	while (pHead->next)
	{
		pHead = pHead->next;
	}
	while (1)
	{
		p1 = (List)malloc(sizeof(Student));
		inputData(p3, p1); //结构体添加数据
		p1->next = NULL;
		pHead->next = p1;
		pHead = p1;
		fprintf(fp, "%d %s %c %f %f %f %f %f \n", p1->XX.num, p1->name, p1->XX.sex, p1->XX.A, p1->XX.B, p1->XX.C, p1->XX.D, p1->XX.E);
		printf("是否继续添加？(Y/N)");
		a = getch();
		if (a == 'n' || a == 'N')
		{
			break;
		}
	}
	SD d;
	char stu_name[20];
	for (p1 = p3->next; p1 != NULL; p1 = p1->next)
	{
		for (p2 = p1->next; p2 != NULL; p2 = p2->next)
		{
			if (p2->XX.sum > p1->XX.sum)
			{
				d = p2->XX;
				strcpy(stu_name, p2->name);
				p2->XX = p1->XX;
				strcpy(p2->name, p1->name);
				p1->XX = d;
				strcpy(p1->name, stu_name);
			}
		}
		p1->rank = ++rank; //初始排名
	}
	fclose(fp);
}
void inputData(Student *pHead, Student *t) //数据的输入以及判断数据是否符合要求
{
	Student *p1 = t, *p2, *p3 = pHead;
	system("CLS");
	printf("请依次输入学生的学号、姓名、性别、语文、数学、英语、化学、物理成绩\n");
	printf("注意:姓名不能有空格，性别男M表示，女W表示，各科成绩应该大于0小于100\n");
	scanf("%d %s %c %f %f %f %f %f", &p1->XX.num, p1->name, &p1->XX.sex, &p1->XX.A, &p1->XX.B,
			&p1->XX.C, &p1->XX.D, &p1->XX.E); //输入完成
														 //判断数据是否合法
	//学号
	p2 = p3->next;
	while (1)
	{
		if (p2 == NULL)
		{
			break;
		}
		if (p2->XX.num == p1->XX.num && p2 != t)
		{
			printf("该学号已存在，请重新输入学号:");
			scanf("%d", &p1->XX.num);
			p2 = p3->next;
		}
		else
		{
			p2 = p2->next;
		}
	}
	system("CLS");
	//性别
	while (1)
	{
		if (p1->XX.sex == 'w' || p1->XX.sex == 'W' || p1->XX.sex == 'M' || p1->XX.sex == 'm')
		{
			break;
		}
		else
		{
			printf("请重新输入正确的性别：\n");
			scanf("%c", &p1->XX.sex);
		};
	}
	system("CLS");
	//成绩
	int q;
	while (1)
	{
		q = 1;
		if (p1->XX.A < 0 || p1->XX.A > 100)
		{
			printf("语文成绩不合法，请重新输入：\n");
			scanf("%f", &p1->XX.A);
			q = 0;
		}
		if (p1->XX.B < 0 || p1->XX.B > 100)
		{
			printf("数学成绩不合法，请重新输入：\n");
			scanf("%f", &p1->XX.B);
			q = 0;
		}
		if (p1->XX.C < 0 || p1->XX.C > 100)
		{
			printf("英语成绩不合法，请重新输入：\n");
			scanf("%f", &p1->XX.C);
			q = 0;
		}
		if (p1->XX.D < 0 || p1->XX.D > 100)
		{
			printf("化学成绩不合法，请重新输入：\n");
			scanf("%f", &p1->XX.D);
			q = 0;
		}
		if (p1->XX.E < 0 || p1->XX.E > 100)
		{
			printf("物理成绩不合法，请重新输入：\n");
			scanf("%f", &p1->XX.E);
			q = 0;
		}
		if (q == 1)
		{
			break;
		}
	}
	system("CLS");
}

void printList(Student *pHead) //打印链表
{
	pHead = pHead->next;
	system("CLS");
	while (pHead)
	{
		pHead->XX.sum = (double)(pHead->XX.A + pHead->XX.B + pHead->XX.C + pHead->XX.D + pHead->XX.E);
		pHead->XX.av = pHead->XX.sum / 5;
		printf("学号:%-5d 姓名:%-4s 性别:%c 语文:%4.1f 数学:%4.1f 英语:%4.1f 化学:%4.1f 物理:%4.1f 平均分:%4.1f 总分:%5.1f 名次:%-3d \n", pHead->XX.num,
				 pHead->name, pHead->XX.sex, pHead->XX.A, pHead->XX.B,
				 pHead->XX.C, pHead->XX.D, pHead->XX.E, pHead->XX.av, pHead->XX.sum, pHead->rank);
		pHead = pHead->next;
	}
	getch();
}
int sortmenu(void)
{
	int a;

	system("CLS");
	printf("┏───────────────────────────────────────────┓\n");
	printf("┃                以什么方式查询 ？          ┃\n");
	printf("┣───────────────────────────────────────────┫\n");
	printf("┃             1   按成绩的高低              ┃\n");
	printf("┣───────────────────────────────────────────┫\n");
	printf("┃             2   按学号的升次              ┃\n");
	printf("┣───────────────────────────────────────────┫\n");
	printf("┃             3   返回主菜单                ┃\n");
	printf("┗───────────────────────────────────────────┛\n");
	printf("请输入选择：");
	a = (int)(getch() - '0');
	system("CLS");
	return a;
}
void readListfromFile(Student *pHead, const char *file_name)
{
	FILE *fp;
	Student *p1, *p2;
	int LEN, rank = 0;
	SD t;
	char stu_name[20];

	fp = fopen(file_name, "r");
	if (fp == NULL) //读取的文件不存在时，创建新的文件
	{
		fp = fopen(file_name, "w");
		fclose(fp);
		return;
	}
	fseek(fp, 0L, 2); //将文件指针移动到文件末尾
	LEN = ftell(fp);	//求出文件指针到文件首部的距离
	p1 = pHead;
	fp = fopen(file_name, "r");
	while (!feof(fp))
	{
		p2 = (List)malloc(sizeof(Student));
		fscanf(fp, "%d %s %c %f %f %f %f %f\n", &p2->XX.num, p2->name, &p2->XX.sex, &p2->XX.A, &p2->XX.B, &p2->XX.C, &p2->XX.D, &p2->XX.E);
		p2->XX.sum = (double)(p2->XX.A + p2->XX.B + p2->XX.C + p2->XX.D + p2->XX.E);
		p2->XX.av = p2->XX.sum / 5;
		p2->next = NULL;
		p1->next = p2;
		p1 = p2;
		if (ftell(fp) == LEN)
		{
			break;
		}
	}
	//将链表排序，并初始化排名
	for (p1 = pHead->next; p1 != NULL; p1 = p1->next)
	{
		for (p2 = p1->next; p2 != NULL; p2 = p2->next)
		{
			if (p2->XX.sum > p1->XX.sum)
			{
				t = p2->XX;
				strcpy(stu_name, p2->name);
				p2->XX = p1->XX;
				strcpy(p2->name, p1->name);
				p1->XX = t;
				strcpy(p1->name, stu_name);
			}
		}
		p1->rank = ++rank;
	}
	fclose(fp);
}
int altermenu()
{

	int a;

	system("CLS");
	printf("┏───────────────────────────────────────────┓\n");
	printf("┃                是否继续修改？             ┃\n");
	printf("┣───────────────────────────────────────────┫\n");
	printf("┃             1   是                        ┃\n");
	printf("┣───────────────────────────────────────────┫\n");
	printf("┃             2   否                        ┃\n");
	printf("┗───────────────────────────────────────────┛\n");
	printf("请输入序号：");
	scanf("%d", &a);
	system("CLS");

	return a;
}
void del(Student *pHead)
{
	Student *p1, *p2 = pHead;
	int a;
	int n, flag = 0;
	char student_name[20], c;
	a = delmenu();
	if (a == 1)
	{
		p1 = pHead->next;
		printf("请输入要删除学生的学号：");
		scanf("%d", &n);
		while (p1)
		{
			if (p1->XX.num == n)
			{
				flag = 1;
				printf("删除成功，删除的学生学号为：%d", n);
				if (p1->next == NULL) //在末尾时
				{
					pHead->next = NULL;
					break;
				}
				else
				{
					pHead->next = p1->next;
					free(p1);
					p1 = pHead->next;
				}
			}
			else
			{
				pHead = pHead->next;
				p1 = pHead->next;
			}
		}
	}
	else
	{
		if (a == 2)
		{
			return;
		}
		else
		{
			del(pHead);
		}
	}
	if (flag == 0)
	{
		printf("没有该学生信息！");
	}
	else
	{
		saveList(p2);
	}
	getch();
}
void saveList(Student *pHead) //将链表中数据存入文件
{
	FILE *fp;

	fp = fopen("stud.dat", "w+");
	pHead = pHead->next;
	while (pHead)
	{
		fprintf(fp, "%d %s %c %f %f %f %f %f\n", pHead->XX.num, pHead->name, pHead->XX.sex, pHead->XX.A,
				  pHead->XX.B, pHead->XX.C, pHead->XX.D, pHead->XX.E);
		pHead = pHead->next;
	}
	fclose(fp);
}
int delmenu()
{

	int a;

	system("CLS");
	printf("┏───────────────────────────────────────────┓\n");
	printf("┃                是否继续删除？             ┃\n");
	printf("┣───────────────────────────────────────────┫\n");
	printf("┃             1   是                        ┃\n");
	printf("┣───────────────────────────────────────────┫\n");
	printf("┃             2   否                        ┃\n");
	printf("┗───────────────────────────────────────────┛\n");
	printf("请输入序号：");
	scanf("%d", &a);
	system("CLS");

	return a;
}
void alter(Student *pHead) //数据修改
{
	int a, flag = 0, i = 0;
	int n;
	Student *p1 = pHead->next;
	a = altermenu();
	if (a == 1)
	{
		printf("请输入要修改学生的学号：");
		scanf("%d", &n);
		while (p1)
		{
			i++;
			if (p1->XX.num == n)
			{
				flag = 1;
				inputData(pHead, p1);
				break;
			}
			p1 = p1->next;
		}
		if (p1 == NULL)
		{
			printf("没有该学生信息！");
		}
	}

	if (flag == 0)
	{
		printf("没有该学生信息！");
	}
	else
	{
		if (a == 2)
		{
			return;
		}
		else
		{
			alter(pHead);
		}
	}

	saveList(pHead);
}
void find(Student *pHead) //查找学生
{
	int a, flag = 0;
	int n;
	char student_name[20];
	pHead = pHead->next;
	a = findmenu();
	if (a == 1)
	{
		printf("请输入该学生的学号：");
		scanf("%d", &n);
		while (pHead)
		{
			if (pHead->XX.num == n)
			{
				if (flag == 0)
				{
					flag = 1;
				}

				printf("学号:%-5d 姓名:%-4s 性别:%c 语文:%4.1f 数学:%4.1f 英语:%4.1f 化学:%4.1f 物理:%4.1f 平均分:%4.1f 总分:%5.1f 名次:%-3d \n", pHead->XX.num,
						 pHead->name, pHead->XX.sex, pHead->XX.A, pHead->XX.B, pHead->XX.C, pHead->XX.D, pHead->XX.E, pHead->XX.av, pHead->XX.sum, pHead->rank);
				break;
			}
			pHead = pHead->next;
		}
		if (pHead == NULL)
		{
			printf("没有该学生记录！\n");
		}
	}
	else
	{
		if (a == 2)
		{
			printf("请输入该学生姓名：");
			scanf("%s", student_name);
			while (pHead)
			{
				if (strcmp(student_name, pHead->name) == 0)
				{
					if (flag == 0)
					{
						printf("已经查到！\n");
						flag = 1;
					}
					printf("学号:%-5d 姓名:%-4s 性别:%c 语文:%4.1f 数学:%4.1f 英语:%4.1f 化学:%4.1f 物理:%4.1f 平均分:%4.1f 总分:%5.1f 名次:%-3d \n", pHead->XX.num,
							 pHead->name, pHead->XX.sex, pHead->XX.A, pHead->XX.B, pHead->XX.C, pHead->XX.D, pHead->XX.E, pHead->XX.av, pHead->XX.sum, pHead->rank);
				}
				pHead = pHead->next;
			}
			if (flag == 0)
			{
				printf("没有该学生记录！");
			}
		}
		else
		{
			if (a == 3)
			{
				return;
			}
			else
			{
				find(pHead);
			}
		}
	}
	getch();
}
int findmenu(void)
{
	int a;

	system("CLS");
	printf("┏──────────────────────────────────┓\n");
	printf("┃             查询方式             ┃\n");
	printf("┣──────────────────────────────────┫\n");
	printf("┃           1   按学号             ┃\n");
	printf("┣──────────────────────────────────┫\n");
	printf("┃           2   按姓名             ┃\n");
	printf("┣──────────────────────────────────┫\n");
	printf("┃           3   返回主菜单         ┃\n");
	printf("┗──────────────────────────────────┛\n");
	printf("请输入你要选择的选项序号：\n");
	scanf("%d", &a);
	system("CLS");
	return a;
}
void sort(Student *pHead) //排序
{
	system("CLS");
	readListfromFile(pHead, "stud.dat"); //从文件中提取数据
	int n = 0, j, k;
	char c;
	Student *p1, *p2;
	Student a[500], t;
	p1 = pHead;
	c = sortmenu();
	n = turn(p1, a); //将数据存入结构体数组中
	if (c == 1)
	{
		for (j = 0; j < n - 1; j++)
		{

			for (k = 0; k < n - j - 1; k++)
			{
				if (a[k].XX.av < a[k + 1].XX.av)
				{
					t = a[k];
					a[k] = a[k + 1];
					a[k + 1] = t;
					a[k].rank = k + 1;
					a[k + 1].rank = k + 2;
				}
			}
		}
		system("CLS");
		int i;
		for (i = 0; i < n; i++)
		{
			printf("学号:%-5d 姓名:%-4s 性别:%c 语文:%4.1f 数学:%4.1f 英语:%4.1f 化学:%4.1f 物理:%4.1f 平均分:%4.1f 总分:%5.1f 名次:%-3d \n",
					 a[i].XX.num, a[i].name, a[i].XX.sex, a[i].XX.A, a[i].XX.B,
					 a[i].XX.C, a[i].XX.D, a[i].XX.E, a[i].XX.av, a[i].XX.sum, a[i].rank);
		}
		getch();
	}
	if (c == 2)
	{
		for (j = 0; j < n - 1; j++)
		{

			for (k = 0; k < n - j - 1; k++)
			{
				if (a[k].XX.num > a[k + 1].XX.num)
				{
					t = a[k];
					a[k] = a[k + 1];
					a[k + 1] = t;
					a[k].rank = k + 1;
					a[k + 1].rank = k + 2;
				}
			}
		}
		system("CLS");
		int i;
		for (i = 0; i < n; i++)
		{
			printf("学号:%-5d 姓名:%-4s 性别:%c 语文:%4.1f 数学:%4.1f 英语:%4.1f 化学:%4.1f 物理:%4.1f 平均分:%4.1f 总分:%5.1f 名次:%-3d \n", a[i].XX.num,
					 a[i].name, a[i].XX.sex, a[i].XX.A, a[i].XX.B,
					 a[i].XX.C, a[i].XX.D, a[i].XX.E, a[i].XX.av, a[i].XX.sum, a[i].rank);
		}
		getch();
	}
	if (c == 3)
	{
		getch();
	}
	else
	{
		sort(pHead);
	}
}
void cr(Student *pHead) //数据插入
{
	Student *p1, *p2;
	system("CLS");
	int n, flag = 0;
	p2 = pHead;
	p1 = (List)malloc(sizeof(Student));
	inputData(p2, p1);
	p1->XX.sum = (double)(p1->XX.A + p1->XX.B + p1->XX.C + p1->XX.D + p1->XX.E);
	p1->XX.av = p1->XX.sum / 5;
	printf("请输入你要插入的位次：");
	scanf("%d", &n);
	p1->rank = n;
	while (p2->next)
	{
		if (pHead->rank == n) //插入的位次为首位
		{
			p1->next = pHead;
			pHead = p1;
			flag = 1;
			break;
		}
		if (p2->next->rank == n)
		{
			p1->next = p2->next;
			p2->next = p1;
			flag = 1;
			break;
		}
		if (p2->next->rank == n - 1 && p2->next->next == NULL) //插入的位置为末尾
		{
			p2->next->next = p1;
			p1->next = NULL;
			flag = 1;
			break;
		}
		p2 = p2->next;
	}
	if (flag == 1)
	{
		printf("插入成功！\n");
		getch();
	}
	if (flag == 0)
	{
		printf("插入失败！该名次不存在，请输入存在的位次！\n");
		getch();
	}
	saveList(pHead);
	getch();
}
int turn(Student *p1, Student a[]) //将链表的数据转入结构体数组
{
	int n = 0;
	p1 = p1->next;
	while (p1)
	{
		strcpy(a[n].name, p1->name);
		a[n].XX = p1->XX;
		a[n].rank = p1->rank;
		p1 = p1->next;
		n++;
	}
	return n;
}
