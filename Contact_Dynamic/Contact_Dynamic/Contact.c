#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

void menu(void)		//菜单打印
{
	printf("\n");
	printf("\n");
	printf("		1.Add(增加)			2.Del(删除)			\n");
	printf("		3.Search(查找)			4.Modify(修改)		\n");
	printf("		5.Show(显示)			6.Sort(排序)		\n");
	printf("				0.Exit(退出)				\n");
	printf("\n");
	printf("\n");
}

//找到所要名字的位置
//返回值  i:所在位置下标    -1:未找到
//参数    ps   通讯录数组地址     name;要寻找的名字
int Find_Address(const Contact_Init* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0==strcmp(ps->DATA[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

//通讯录初始化
//返回值  无
//参数    *ps   通讯录数组地址
void Init_Contact(Contact_Init* ps)
{
	memset(ps->DATA, 0, sizeof(ps->DATA));//通讯录所有元素为0
	ps->size = 0;		//设置通讯录最初只有0个元素
}

//增加联系人信息到通讯录
//返回值  无
//参数    ps	通讯录数组地址
void Contact_Add(Contact_Init* ps)
{
	int i = 0;
	if (ps->size == MAX)
	{
		printf("通讯录已满,无法添加！\n");
	}
	else
	{
		printf("请输入要添加人的姓名:>");
		scanf("%s", ps->DATA[ps->size].name);
		printf("请输入要添加人的年龄:>");
		scanf("%d", &(ps->DATA[ps->size].age));
		printf("请输入要添加人的性别:>");
		scanf("%s", ps->DATA[ps->size].sex);
		printf("请输入要添加人的电话:>");
		scanf("%s", ps->DATA[ps->size].tele);
		printf("请输入要添加人的地址:>");
		scanf("%s", ps->DATA[ps->size].addr);

		ps->size++;
		printf("添加成功！\n");
	}
}

//删除指定联系人信息
//返回值  无
//参数    ps	通讯录数组地址
void Contact_Del(Contact_Init* ps)
{
	int j = 0;
	char name[MAX_NAME];
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	//找到要删除的人的位置
	int pos = Find_Address(ps, name);
	//删除
	if (-1 == pos)			
	{
		printf("要删除的人不存在!\n");
	}
	else
	{
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->DATA[j] = ps->DATA[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

//查找指定联系人信息
//返回值  无
//参数    ps	通讯录数组地址
void Contact_Search(Contact_Init* ps)
{
	int i = 0;
	char name[MAX_NAME];
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	//找到要查找的人的位置
	for (int i = 0; i < ps->size; i++)
	{
		if (0 == strncmp(ps->DATA[i].name, name,sizeof(name)))
		{
			printf("%10s\t %4d\t %5s\t %12s\t %20s\n",
				ps->DATA[i].name,
				ps->DATA[i].age,
				ps->DATA[i].sex,
				ps->DATA[i].tele,
				ps->DATA[i].addr);
		}
	}
	if(i==ps->size)
	{
		printf("找不到该联系人\n");
	}
}

//修改指定联系人信息
//返回值  无
//参数    ps	通讯录数组地址
void Contact_Modify(Contact_Init* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	//找到要修改的人的位置
	int pos = Find_Address(ps, name);
	//删除
	if (-1 == pos)
	{
		printf("要修改的人不存在!\n");
	}
	else
	{
		printf("请输入要添加人的姓名:>");
		scanf("%s", ps->DATA[pos].name);
		printf("请输入要添加人的年龄:>");
		scanf("%d", &(ps->DATA[pos].age));
		printf("请输入要添加人的性别:>");
		scanf("%s", ps->DATA[pos].sex);
		printf("请输入要添加人的电话:>");
		scanf("%s", ps->DATA[pos].tele);
		printf("请输入要添加人的地址:>");
		scanf("%s", ps->DATA[pos].addr);

		printf("修改成功\n");
	}
}

//按名字对通讯录进行排序
//返回值  str1>str2  返回 1，str1<str2  返回 -1，str1=str2  返回 0，
//参数    ps	通讯录数组地址
int Compare_Struct_Name(const void* str1, const void* str2)
{
	return strcmp(((Contact_Init*)str1)->DATA->name, ((Contact_Init*)str2)->DATA->name);
}

//对通讯录进行排序
//返回值  无
//参数    ps	通讯录数组地址
void Contact_Sort(Contact_Init* ps)
{
	qsort(ps, ps->size, sizeof(ps->DATA[0]), Compare_Struct_Name);
	printf("排序成功!\n");
}

//通讯录联系人信息打印
//返回值  无
//参数    ps	通讯录数组地址
void Contact_Show(Contact_Init* ps)
{
	int i = 0;
	if(ps->size==0)
	{
		printf("通讯录里面什么都没有！\n");
	}
	else
	{
		printf("%2s\t%10s\t %4s\t %5s\t %12s\t %20s\n","序号","姓名","年龄","性别","电话","地址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%2d.\t%10s\t %4d\t %5s\t %12s\t %20s\n",i+1,
				ps->DATA[i].name,
				ps->DATA[i].age,
				ps->DATA[i].sex,
				ps->DATA[i].tele,
				ps->DATA[i].addr);
		}
	}
}