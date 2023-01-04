#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
#define NAME_MAX		20
#define SEX_MAX			5
#define TELE_MAX		12
#define ADDR_MAX		20

#define CAPACITY_INIT	3		//��ʼ������С
#define INCREMENT		2		//ÿ�������������Ĵ�С
#define TITLE		(printf("%4s\t%-20s\t%-3s\t%5s\t%12s\t%20s\n","���", "����", "����", "�Ա�", "�绰", "��ַ"))

//��ϵ����Ϣ	���� ���� �Ա� �绰 ��ַ
typedef struct
{
	char name[NAME_MAX];
	int age;
	char Sex[SEX_MAX];
	char Tele[TELE_MAX];
	char Addr[ADDR_MAX];
}PeoInfo_Init;

//ͨѶ¼		��ϵ����Ϣ ͨѶ¼��С  ͨѶ¼����
typedef struct
{
	PeoInfo_Init* DATA;		//ָ��̬���ٿռ䡣�����ϵ����Ϣ
	int size;				//��¼��ǰͨѶ¼����Ч��Ϣ����
	int Capacity;			//��¼��ǰͨѶ¼������С
}Contact_Init;

//ͨѶ¼�˵���ӡ
void Contact_Menu();
//ͨѶ¼��ʼ��
void Init_Contact(Contact_Init *ps);
//����ͨѶ¼����ϵ����Ϣ
void Contact_Add(Contact_Init* ps);
//ɾ��ͨѶ¼��ָ����ϵ����Ϣ
void Contact_Del(Contact_Init* ps);
//����ͨѶ¼��ָ����ϵ����Ϣ
void Contact_Search(Contact_Init* ps);
//�޸�ͨѶ¼��ָ����ϵ����Ϣ
void Contact_Modify(Contact_Init* ps);
//��ͨѶ¼����ϵ������
void Contact_Sort(Contact_Init* ps);
//����ͨѶ¼����ϵ����Ϣ
void Contact_Save(Contact_Init* ps);
//��ʾͨѶ¼����Ϣ
void Contact_Show(Contact_Init* ps);
//void Contact_Show(const Contact_Init* ps);	//��ֹ���ݱ��޸�
//�ͷſ��ٵ��ڴ�
void Contact_Destory(Contact_Init* ps);

