#ifndef _Contact_H_
#define _Contact_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX			1000 
#define MAX_NAME	10
#define MAX_SEX		5
#define MAX_TELE	12
#define MAX_ADDR	20

enum Option
{
	Exit,
	Add,
	Del,
	Search,
	Modify,
	Show,
	Sort
};

typedef struct PeoInfo				//��ϵ����Ϣ
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	int age;
}PeoInfo_Init;

typedef struct Contact
{
	PeoInfo_Init DATA[MAX];		//���MAX������Ϣ
	int size;					//��¼��ǰ�Ѿ��е�Ԫ�ظ���
}Contact_Init;

void menu(void);							//�˵���ӡ
void Contact_Add(Contact_Init* ps);			//������ϵ����Ϣ��ͨѶ¼
void Contact_Del(Contact_Init* ps);			//ɾ��ָ������ϵ����Ϣ
void Contact_Search(Contact_Init* ps);		//����ָ����ϵ����Ϣ
void Contact_Modify(Contact_Init* ps);		//�޸�ָ����ϵ����Ϣ
void Contact_Show(Contact_Init* ps);		//��ӡͨѶ¼����Ϣ
void Contact_Sort(Contact_Init* ps);

void Init_Contact(Contact_Init* ps);

#endif 

