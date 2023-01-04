#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

static void Contact_Capacity_Check(Contact_Init* ps);

/****
	*@brief		ͨѶ¼�˵�
	*@param		��
	*@retval	��
*****/
void Contact_Menu()
{
	printf("\n");
	printf("/******************************************/\n");
	printf("\n");
	printf("***   1.Add(����)	2.Del(ɾ��)    ***\n");
	printf("***   3.Search(����)	4.Modify(�޸�) ***\n");
	printf("***   5.Show(��ʾ)	6.Sort(����)   ***\n");
	printf("***   7.Save(����)	0.Exit(�˳�)   ***\n");
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
	*@brief		ͨѶ¼��ʼ��
	*@param		ps  ͨѶ¼��ַ
	*@retval	��
*****/
void Init_Contact(Contact_Init* ps)
{
	ps->DATA = (PeoInfo_Init*)malloc(CAPACITY_INIT * sizeof(PeoInfo_Init));
	if (ps->DATA == NULL)
	{
		perror("Init_Contact:\n");
		return;
	}
	ps->size = 0;
	ps->Capacity = CAPACITY_INIT;

	//���ļ���ŵ���ϵ�˼���ͨѶ¼��
	Contact_Load(ps);
}

/****
	*@brief		ͨѶ¼�������
	*@param		ps  ͨѶ¼��ַ
	*@retval	��
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
			printf("���ݳɹ�!\n");
		}
		else
		{
			perror("Contact_Capacity_Check:\n");
			printf("����ʧ��!\n");
			return;
		}
	}
}

/****
	*@brief		�ҵ���Ҫ���ҵ���ϵ���±�
	*@param		ps	 ͨѶ¼��ַ
	*@param		name Ҫ�����˵�����
	*@retval	i/-1 δ�ҵ�����-1  ���ҵ��������±�
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
	*@brief		����ͨѶ¼����ϵ����Ϣ
	*@param		ps  ͨѶ¼��ַ
	*@retval	��
*****/
void Contact_Add(Contact_Init* ps)
{
	//���ͨѶ¼����
	//1.�������� ����> ��������
	//2.����û�� ����> ʲô������
	Contact_Capacity_Check(ps);

	printf("��������ϵ������:>");
	scanf("%s",ps->DATA[ps->size].name);
	printf("��������ϵ������:>");
	scanf("%d", &(ps->DATA[ps->size].age));
	printf("��������ϵ���Ա�:>");
	scanf("%s", ps->DATA[ps->size].Sex);
	printf("��������ϵ�˵绰:>");
	scanf("%s", ps->DATA[ps->size].Tele);
	printf("��������ϵ�˵�ַ:>");
	scanf("%s", ps->DATA[ps->size].Addr);

	ps->size++;
	printf("��ϵ����ӳɹ�!\n");
}

/****
	*@brief		ɾ��ͨѶ¼����ϵ����Ϣ
	*@param		ps  ͨѶ¼��ַ
	*@retval	��
*****/
void Contact_Del(Contact_Init* ps)
{
	int ret = 0;
	int i = 0;
	char name[NAME_MAX] = { 0 };
	printf("������Ҫɾ������ϵ��:>");
	scanf("%s", name);
	ret = Contact_Find(ps, name);
	if (-1 == ret)
	{
		printf("����ϵ��δ�ҵ���\n");
	}
	else
	{
		for (i = ret; i < ps->size - 1; i++)
		{
			ps->DATA[i] = ps->DATA[i + 1];
		}

		ps->size--;
		printf("ɾ���ɹ�!\n");
	}
}

/****
	*@brief		����ͨѶ¼����ϵ����Ϣ
	*@param		ps  ͨѶ¼��ַ
	*@retval	��
*****/
void Contact_Search(Contact_Init* ps)
{
	int ret = ps->size;
	int i = 0;
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ���ҵ���ϵ��:>");
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
		printf("�Ҳ�������ϵ��!\n");
	}
}

/****
	*@brief		�޸�ͨѶ¼��ָ����ϵ����Ϣ
	*@param		ps  ͨѶ¼��ַ
	*@retval	��
*****/
void Contact_Modify(Contact_Init* ps)
{
	int ret = 0;
	int i = 0;
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ�޸ĵ���ϵ��:>");
	scanf("%s", name);
	ret = Contact_Find(ps, name);
	if (-1 == ret)
	{
		printf("����ϵ��δ�ҵ���\n");
	}
	else
	{
		printf("��������ϵ������:>");
		scanf("%s", ps->DATA[ret].name);
		printf("��������ϵ������:>");
		scanf("%d", &(ps->DATA[ret].age));
		printf("��������ϵ���Ա�:>");
		scanf("%s", ps->DATA[ret].Sex);
		printf("��������ϵ�˵绰:>");
		scanf("%s", ps->DATA[ret].Tele);
		printf("��������ϵ�˵�ַ:>");
		scanf("%s", ps->DATA[ret].Addr);

		printf("��ϵ���޸ĳɹ�!\n");
	}
}

/****
	*@brief		��ͨѶ¼����ϵ������
	*@param		ps  ͨѶ¼��ַ
	*@retval	��
*****/
void Contact_Sort(Contact_Init* ps)
{
	;
}

/****
	*@brief		����ͨѶ¼����ϵ����Ϣ
	*@param		ps  ͨѶ¼��ַ
	*@retval	��
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
	printf("����ɹ�!\n");
}

/****
	*@brief		��ʾͨѶ¼����Ϣ
	*@param		ps  ͨѶ¼��ַ
	*@retval	��
*****/
void Contact_Show(Contact_Init* ps)
{
	int i = 0;
	if (ps->size == 0)
	{
		printf("ͨѶ¼����ʲô��û�У�\n");
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