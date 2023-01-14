#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

static void Contact_Capacity_Check(Contact_Init* ps);

/****
	*@brief		通讯录菜单
	*@param		无
	*@retval	无
*****/
void Contact_Menu()
{
	printf("\n");
	printf("/******************************************/\n");
	printf("\n");
	printf("***   1.Add(增加)	2.Del(删除)    ***\n");
	printf("***   3.Search(查找)	4.Modify(修改) ***\n");
	printf("***   5.Show(显示)	6.Sort(排序)   ***\n");
	printf("***   7.Save(保存)	0.Exit(退出)   ***\n");
	printf("\n");
	printf("/******************************************/\n");
	printf("\n");
}

void Contact_Load(Contact_Init* ps)
{
	PeoInfo_Init temp = { 0 };
	FILE* PfRead = fopen("Contact.dat", "r");
	if (PfRead == NULL)
	{
		perror("Contact_Load:\n");
		return;
	}

	while (fread(&temp, sizeof(PeoInfo_Init), 1, PfRead))
	{
		Contact_Capacity_Check(ps);
		ps->DATA[ps->size] = temp;
		ps->size++;
	}
	fclose(PfRead);
	PfRead = NULL;
}

/****
	*@brief		通讯录初始化
	*@param		ps  通讯录地址
	*@retval	无
*****/
void Init_Contact(Contact_Init* ps)
{
	ps->DATA = (PeoInfo_Init*)malloc(CAPACITY_INIT * sizeof(PeoInfo_Init));
	if (ps->DATA == NULL)
	{
		perror("Init_Contact");
		return;
	}
	ps->size = 0;
	ps->Capacity = CAPACITY_INIT;

	//把文件存放的联系人加载通讯录中
	Contact_Load(ps);
}

/****
	*@brief		通讯录容量检查
	*@param		ps  通讯录地址
	*@retval	无
*****/
static void Contact_Capacity_Check(Contact_Init* ps)
{
	PeoInfo_Init* ptr = NULL;
	if (ps->size == ps->Capacity)
	{
		ptr=(PeoInfo_Init*)realloc(ps->DATA, (ps->Capacity + INCREMENT) * sizeof(PeoInfo_Init));
		if (ptr != NULL)
		{
			ps->DATA = ptr;
			ps->Capacity += INCREMENT;
			printf("扩容成功!\n");
		}
		else
		{
			perror("Contact_Capacity_Check");
			printf("扩容失败!\n");
			return;
		}
	}
}

/****
	*@brief		找到需要查找的联系人下标
	*@param		ps	 通讯录地址
	*@param		name 要查找人的姓名
	*@retval	i/-1 未找到返回-1  ，找到返回其下标
*****/
static int Contact_Find(const Contact_Init* ps, char* name)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->DATA[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

/****
	*@brief		增加通讯录中联系人信息
	*@param		ps  通讯录地址
	*@retval	无
*****/
void Contact_Add(Contact_Init* ps)
{
	//检查通讯录容量
	//1.容量满了 ——> 增加容量
	//2.容量没满 ——> 什么都不做
	Contact_Capacity_Check(ps);

	printf("请输入联系人姓名:>");
	scanf("%s",ps->DATA[ps->size].name);
	printf("请输入联系人年龄:>");
	scanf("%d", &(ps->DATA[ps->size].age));
	printf("请输入联系人性别:>");
	scanf("%s", ps->DATA[ps->size].Sex);
	printf("请输入联系人电话:>");
	scanf("%s", ps->DATA[ps->size].Tele);
	printf("请输入联系人地址:>");
	scanf("%s", ps->DATA[ps->size].Addr);

	ps->size++;
	printf("联系人添加成功!\n");
}

/****
	*@brief		删除通讯录中联系人信息
	*@param		ps  通讯录地址
	*@retval	无
*****/
void Contact_Del(Contact_Init* ps)
{
	int ret = 0;
	int i = 0;
	char name[NAME_MAX] = { 0 };
	printf("请输入要删除的联系人:>");
	scanf("%s", name);
	ret = Contact_Find(ps, name);
	if (-1 == ret)
	{
		printf("该联系人未找到！\n");
	}
	else
	{
		for (i = ret; i < ps->size - 1; i++)
		{
			ps->DATA[i] = ps->DATA[i + 1];
		}

		ps->size--;
		printf("删除成功!\n");
	}
}

/****
	*@brief		查找通讯录中联系人信息
	*@param		ps  通讯录地址
	*@retval	无
*****/
void Contact_Search(Contact_Init* ps)
{
	int ret = ps->size;
	int i = 0;
	char name[NAME_MAX] = { 0 };
	printf("请输入要查找的联系人:>");
	scanf("%s", name);
	for(i=0;i<ps->size;i++)
	{
		if (0 == strcmp(ps->DATA[i].name, name))
		{
			printf("%10s\t %4d\t %5s\t %12s\t %20s\n",
					ps->DATA[i].name,
					ps->DATA[i].age,
					ps->DATA[i].Sex,
					ps->DATA[i].Tele,
					ps->DATA[i].Addr);
			ret--;
		}
	}
	if (ret == ps->size)
	{
		printf("找不到该联系人!\n");
	}
}

/****
	*@brief		修改通讯录中指定联系人信息
	*@param		ps  通讯录地址
	*@retval	无
*****/
void Contact_Modify(Contact_Init* ps)
{
	int ret = 0;
	int i = 0;
	char name[NAME_MAX] = { 0 };
	printf("请输入要修改的联系人:>");
	scanf("%s", name);
	ret = Contact_Find(ps, name);
	if (-1 == ret)
	{
		printf("该联系人未找到！\n");
	}
	else
	{
		printf("请输入联系人姓名:>");
		scanf("%s", ps->DATA[ret].name);
		printf("请输入联系人年龄:>");
		scanf("%d", &(ps->DATA[ret].age));
		printf("请输入联系人性别:>");
		scanf("%s", ps->DATA[ret].Sex);
		printf("请输入联系人电话:>");
		scanf("%s", ps->DATA[ret].Tele);
		printf("请输入联系人地址:>");
		scanf("%s", ps->DATA[ret].Addr);

		printf("联系人修改成功!\n");
	}
}

/****
	*@brief		对通讯录中联系人排序
	*@param		ps  通讯录地址
	*@retval	无
*****/
void Contact_Sort(Contact_Init* ps)
{
	;
}

/****
	*@brief		保存通讯录中联系人信息
	*@param		ps  通讯录地址
	*@retval	无
*****/
void Contact_Save(Contact_Init* ps)
{
	int i = 0;
	FILE* PfFile = fopen("Contact.dat", "w");
	if (PfFile == NULL)
	{
		perror("Contact_Save:\n");
		return;
	}
	for(i=0;i<ps->size;i++)
	{
		fwrite(&(ps->DATA[i]), sizeof(PeoInfo_Init), 1, PfFile);
	}
	
	fclose(PfFile);
	PfFile = NULL;
	printf("保存成功!\n");
}

/****
	*@brief		显示通讯录中信息
	*@param		ps  通讯录地址
	*@retval	无
*****/
void Contact_Show(Contact_Init* ps)
{
	int i = 0;
	if (ps->size == 0)
	{
		printf("通讯录里面什么都没有！\n");
	}
	else
	{
		TITLE;
		for (i = 0; i < ps->size; i++)
		{
			printf("%3d.\t%-20s\t%-3d\t%5s\t%12s\t%20s\n",i+1,
				ps->DATA[i].name,
				ps->DATA[i].age,
				ps->DATA[i].Sex,
				ps->DATA[i].Tele,
				ps->DATA[i].Addr);
		}
	}
}

void Contact_Destory(Contact_Init* ps)
{
	free(ps->DATA);
	ps->DATA = NULL;
}
