#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

void menu(void)		//�˵���ӡ
{
	printf("\n");
	printf("\n");
	printf("		1.Add(����)			2.Del(ɾ��)			\n");
	printf("		3.Search(����)			4.Modify(�޸�)		\n");
	printf("		5.Show(��ʾ)			6.Sort(����)		\n");
	printf("				0.Exit(�˳�)				\n");
	printf("\n");
	printf("\n");
}

//�ҵ���Ҫ���ֵ�λ��
//����ֵ  i:����λ���±�    -1:δ�ҵ�
//����    ps   ͨѶ¼�����ַ     name;ҪѰ�ҵ�����
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

//ͨѶ¼��ʼ��
//����ֵ  ��
//����    *ps   ͨѶ¼�����ַ
void Init_Contact(Contact_Init* ps)
{
	memset(ps->DATA, 0, sizeof(ps->DATA));//ͨѶ¼����Ԫ��Ϊ0
	ps->size = 0;		//����ͨѶ¼���ֻ��0��Ԫ��
}

//������ϵ����Ϣ��ͨѶ¼
//����ֵ  ��
//����    ps	ͨѶ¼�����ַ
void Contact_Add(Contact_Init* ps)
{
	int i = 0;
	if (ps->size == MAX)
	{
		printf("ͨѶ¼����,�޷���ӣ�\n");
	}
	else
	{
		printf("������Ҫ����˵�����:>");
		scanf("%s", ps->DATA[ps->size].name);
		printf("������Ҫ����˵�����:>");
		scanf("%d", &(ps->DATA[ps->size].age));
		printf("������Ҫ����˵��Ա�:>");
		scanf("%s", ps->DATA[ps->size].sex);
		printf("������Ҫ����˵ĵ绰:>");
		scanf("%s", ps->DATA[ps->size].tele);
		printf("������Ҫ����˵ĵ�ַ:>");
		scanf("%s", ps->DATA[ps->size].addr);

		ps->size++;
		printf("��ӳɹ���\n");
	}
}

//ɾ��ָ����ϵ����Ϣ
//����ֵ  ��
//����    ps	ͨѶ¼�����ַ
void Contact_Del(Contact_Init* ps)
{
	int j = 0;
	char name[MAX_NAME];
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	//�ҵ�Ҫɾ�����˵�λ��
	int pos = Find_Address(ps, name);
	//ɾ��
	if (-1 == pos)			
	{
		printf("Ҫɾ�����˲�����!\n");
	}
	else
	{
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->DATA[j] = ps->DATA[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

//����ָ����ϵ����Ϣ
//����ֵ  ��
//����    ps	ͨѶ¼�����ַ
void Contact_Search(Contact_Init* ps)
{
	int i = 0;
	char name[MAX_NAME];
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	//�ҵ�Ҫ���ҵ��˵�λ��
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
		printf("�Ҳ�������ϵ��\n");
	}
}

//�޸�ָ����ϵ����Ϣ
//����ֵ  ��
//����    ps	ͨѶ¼�����ַ
void Contact_Modify(Contact_Init* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	//�ҵ�Ҫ�޸ĵ��˵�λ��
	int pos = Find_Address(ps, name);
	//ɾ��
	if (-1 == pos)
	{
		printf("Ҫ�޸ĵ��˲�����!\n");
	}
	else
	{
		printf("������Ҫ����˵�����:>");
		scanf("%s", ps->DATA[pos].name);
		printf("������Ҫ����˵�����:>");
		scanf("%d", &(ps->DATA[pos].age));
		printf("������Ҫ����˵��Ա�:>");
		scanf("%s", ps->DATA[pos].sex);
		printf("������Ҫ����˵ĵ绰:>");
		scanf("%s", ps->DATA[pos].tele);
		printf("������Ҫ����˵ĵ�ַ:>");
		scanf("%s", ps->DATA[pos].addr);

		printf("�޸ĳɹ�\n");
	}
}

//�����ֶ�ͨѶ¼��������
//����ֵ  str1>str2  ���� 1��str1<str2  ���� -1��str1=str2  ���� 0��
//����    ps	ͨѶ¼�����ַ
int Compare_Struct_Name(const void* str1, const void* str2)
{
	return strcmp(((Contact_Init*)str1)->DATA->name, ((Contact_Init*)str2)->DATA->name);
}

//��ͨѶ¼��������
//����ֵ  ��
//����    ps	ͨѶ¼�����ַ
void Contact_Sort(Contact_Init* ps)
{
	qsort(ps, ps->size, sizeof(ps->DATA[0]), Compare_Struct_Name);
	printf("����ɹ�!\n");
}

//ͨѶ¼��ϵ����Ϣ��ӡ
//����ֵ  ��
//����    ps	ͨѶ¼�����ַ
void Contact_Show(Contact_Init* ps)
{
	int i = 0;
	if(ps->size==0)
	{
		printf("ͨѶ¼����ʲô��û�У�\n");
	}
	else
	{
		printf("%2s\t%10s\t %4s\t %5s\t %12s\t %20s\n","���","����","����","�Ա�","�绰","��ַ");
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