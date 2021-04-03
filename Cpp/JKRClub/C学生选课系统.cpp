#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int k = 1;
int pass = 123; //设置管理员密码

typedef struct subjects
{
	int num;			//课程编号
	char name[20]; //课程名称
	char kind[20]; //课程性质
	int stime;		//总学时
	int ttime;		//授课学时
	int etime;		//实验或上机学时
	int score;		//学分
	int term;		//开课学期
	struct subjects *next;
} sub;
void admini(sub *&T, sub *&S);
void student(sub *&T, sub *&S);
void init(sub *&L) //链表初始化
{
	L = (sub *)malloc(sizeof(sub));
	L->next = NULL;
}
void choice(sub *&T) //学生选课
{
	sub *p = T;
	int a, sum = 0;
	printf("请输入你要选修的课程编号：");
	scanf("%d", &a);
	printf("确定输入完整的选修课程编号，请输入0:");
	while (a != 0) //第一次输入的编码
	{
		while (p->next != NULL) //进行逐一排查
		{
			p = p->next;
			if (a == p->num) //逐一配对
			{
				sum = p->score; //将分数给sum
				//pr=p;
				break;
			}
		}
		scanf("%d", &a);
	}
	if (sum < 60) //判断学分是否大于60
	{
		printf("选修总学分为%d,未达到60,选修失败!\n", sum);
		system("pause");
	}
	else
	{
		FILE *fp;
		fp = fopen("4.txt", "a");																															 //打开文件
		fprintf(fp, "%d %s %s %d %d %d %d %d \n", p->num, p->name, p->kind, p->stime, p->ttime, p->etime, p->score, p->term); //将数据存进文件里面
		fclose(fp);
		printf("\n*****选修成功!****\n");
		printf("\n您选修的课程总学分为%d,课程分别为:\n", sum);
		printf("\n课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期\n");
		printf("%5d%12s%9s%9d%9d%11d%11d%7d\n", p->num, p->name, p->kind, p->stime, p->ttime, p->etime, p->score, p->term); //显示出选修的课
		printf("\n以上信息全部保存在'4.txt'中\n");
		system("pause");
	}
}
void del(sub *&T) //课程删除
{
	sub *p, *pr;
	int a;
	printf("请输入你要删除的课程编码：");
	scanf("%d", &a);
	if (T->num == a) //判断是否刚好在链表第一个
	{
		pr = T;
		T = T->next; //将链表头移动到后面
		free(pr);
	}
	if (T == NULL) //链表为空的情况
	{
		printf("当前里面无课程。\n");
		return;
	}
	p = T;
	pr = T->next;
	while (pr)
	{
		if (pr->num == a) //判断是否相等
		{
			p->next = pr->next;
			free(pr);
		}
		else
			p = pr;
		pr = p->next;
	}
	printf("\n删除完毕,新信息存入文件中\n");
	system("pause");
}
void savefile(sub *&T) //保存全部课程信息写入文件
{
	sub *p;
	FILE *fp;
	fp = fopen("1.txt", "w"); //
	if (fp == NULL)
		return;
	printf("课程编号  课程名称  课程性质  总学时  授课学时  实验或上机学时  学分  开课学期\n");
	for (p = T->next; p; p = p->next)
		fprintf(fp, "%d %s %s %d %d %d %d %d \n", p->num, p->name, p->kind, p->stime, p->ttime, p->etime, p->score, p->term);

	fclose(fp);
	printf("创建后的信息已放入'1.txt'文件中\n");
}
void readlist(sub *&T) //读取文件信息
{
	sub *p, *s = T;
	FILE *fp;
	fp = fopen("1.txt", "r");
	while (!feof(fp))
	{
		p = (sub *)malloc(sizeof(sub));
		if (fscanf(fp, "%d%s%s%d%d%d%d%d", &p->num, p->name, p->kind, &p->stime, &p->ttime, &p->etime, &p->score, &p->term) != EOF)
		{
			//fscanf(fp,"%d%s%s%d%d%d%d%d",&p->num,p->name,p->kind,&p->stime,&p->ttime,&p->etime,&p->score,&p->term);
			// printf("%5d%12s%9s%9d%9d%11d%11d%7d\n",p->num,p->name,p->kind,p->stime,p->ttime,p->etime,p->score,p->term);
			s->next = p;
			p->next = NULL;
			s = p;
		}
	}
	free(p);
	fclose(fp);
}
void que(sub *&T) //查询课程信息
{
	int a, b = 1, d;
	sub *p = T;
	char name[20];
L1:
	system("cls");
	printf("-----------请选择查询方式-----------\n");
	printf("1、按课程名称查询\n");
	printf("2、按学分查询\n");
	printf("3、退出查询\n");
	printf("请选择你需要的菜单：");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		printf("请输入要查找的课程的名称:");
		scanf("%s", name);
		printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期\n");
		while (p->next != NULL)
		{
			p = p->next;
			if (strcmp(name, p->name) == 0)
			{
				printf("%5d%12s%9s%9d%9d%11d%11d%7d\n", p->num, p->name, p->kind, p->stime, p->ttime, p->etime, p->score, p->term);
				b = 0;
			}
		}
		if (b)
			printf("\t\n未找到!\n");
		b = 1;
		system("pause");
		goto L1;
		break;
	case 2:
		printf("请输入要查找的课程的学分:");
		scanf("%d", &d);
		printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期\n");
		while (p->next != NULL)
		{
			p = p->next;
			if (p->score == d)
			{
				printf("%5d%12s%9s%9d%9d%11d%11d%7d\n", p->num, p->name, p->kind, p->stime, p->ttime, p->etime, p->score, p->term);
				b = 0;
			}
		}
		if (b)
			printf("\t\n未找到!\n");
		b = 1;
		system("pause");
		goto L1;
		break;
	case 3:
		break;
	}
}
void prin(sub *&T) //浏览课程信息
{
	sub *p = T;
	//readlist(p);
	if (p->next == NULL)
	{
		printf("\n\n\t*********NO RECORDS!************\n");
		return;
	}
	printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期\n");
	while (p->next != NULL)
	{
		p = p->next;
		printf("%5d%12s%9s%9d%9d%11d%11d%7d\n", p->num, p->name, p->kind, p->stime, p->ttime, p->etime, p->score, p->term);
	}
	system("pause");
}
void prin1(sub *&T)
{
	sub *p, *s = T;
	FILE *fp;
	if ((fp = fopen("4.txt", "r")) == NULL)
		printf("目前你还没有选课。\n");
	else
	{
		printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期\n");
		while (!feof(fp))
		{
			p = (sub *)malloc(sizeof(sub));
			if (fscanf(fp, "%d%s%s%d%d%d%d%d", &p->num, p->name, p->kind, &p->stime, &p->ttime, &p->etime, &p->score, &p->term) != EOF)
			{
				//fscanf(fp,"%d%s%s%d%d%d%d%d",&p->num,p->name,p->kind,&p->stime,&p->ttime,&p->etime,&p->score,&p->term);
				printf("%5d%12s%9s%9d%9d%11d%11d%7d\n", p->num, p->name, p->kind, p->stime, p->ttime, p->etime, p->score, p->term);
				s->next = p;
				p->next = NULL;
				s = p;
			}
		}
		free(p);
		fclose(fp);
		system("pause");
	}
}
void inser(sub *&T) //添加课程信息
{
	sub *p, *h = T, *pr;
	while (h->next != NULL)
	{
		h = h->next;
	}
	p = (sub *)malloc(sizeof(sub));
	printf("输入你要添加的课程信息：\n");
	printf("\t请输入课程编号：");
	scanf("%d", &p->num);
	printf("\t请输入课程名称:");
	scanf("%s", p->name);
	printf("\t请输入课程性质:");
	scanf("%s", p->kind);
	printf("\t请输入总学时:");
	scanf("%d", &p->stime);
	printf("\t请输入授课学时:");
	scanf("%d", &p->ttime);
	printf("\t请输入实践或上机学时:");
	scanf("%d", &p->etime);
	printf("\t请输入学分:");
	scanf("%d", &p->score);
	printf("\t请输入开课学期:");
	scanf("%d", &p->term);
	if (h->next == NULL)
	{
		h->next = p;
		p->next = NULL;
	}
	else
	{
		for (pr = T; pr; pr = pr->next)
			if (pr->next == NULL)
			{
				pr->next = p;
				p->next = NULL;
				break;
			}
	}

	printf("\n添加完毕,新信息存入文件中\n");
	system("pause");
}
void menu(sub *&T, sub *&S) //菜单
{
	int a;
	system("cls");
	printf("----------学生选修课程系统----------\n");
	printf("\t1、以管理员模式进入！(密码：123)\n");
	printf("\t2、学生模式进入\n");
	printf("\t3、退出系统！\n");
	printf("请输入选择菜单：");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		admini(T, S);
		break;
	case 2:
		student(T, S);
		break;
	case 3:
		k = 0;
		break;
	default:
		printf("你输入的数超出范围，请重新输入。\n");
	}
}
bool password() //管理员密码登录
{
	int a;
	printf("请输入管理员密码：");
	scanf("%d", &a);
	if (a == pass)
		return true;
	else
		return false;
}
void admini(sub *&T, sub *&S) //管理员菜单
{
	int a;
	if (password())
	{
	A1:
		system("cls");
		printf("----------管理员菜单----------\n");
		printf("1、浏览课程。\n");
		printf("2、查询课程。\n");
		printf("3、添加课程。\n");
		printf("4、删除课程。\n");
		printf("5、返回主菜单。\n");
		printf("请输入你要选择的管理员菜单：");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			prin(T);
			goto A1;
			break;
		case 2:
			que(T);
			goto A1;
			break;
		case 3:
			inser(T);
			savefile(T);
			readlist(T);
			goto A1;
			break;
		case 4:
			del(T);
			savefile(T);
			goto A1;
			break;
		case 5:
			menu(T, S);
			break;
		default:
			printf("请输入的数超出范围，返回主菜单。");
		}
	}
}
void student(sub *&T, sub *&S) //学生菜单
{
	int a;
A2:
	system("cls");
	printf("--------学生菜单--------\n");
	printf("1、浏览所有课程。\n");
	printf("2、查询课程信息。\n");
	printf("3、选择选修课程。\n");
	printf("4、浏览我选修的课程。\n");
	printf("5、返回菜单。\n");
	printf("请输入你要选择的学生菜单：");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		prin(T);
		goto A2;
		break;
	case 2:
		que(T);
		goto A2;
		break;
	case 3:
		choice(T);
		goto A2;
		break;
	case 4:
		prin1(S);
		goto A2;
		break;
	case 5:
		menu(T, S);
		break;
	default:
		printf("请输入的数超出范围，返回主菜单。");
	}
}
int main() //主函数
{
	sub *E, *S;
	init(E);
	init(S);
	readlist(E);
	while (k)
	{
		menu(E, S);
	}
}
