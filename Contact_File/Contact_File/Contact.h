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

typedef struct PeoInfo				//联系人信息
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	int age;
}PeoInfo_Init;

typedef struct Contact
{
	PeoInfo_Init DATA[MAX];		//存放MAX个的信息
	int size;					//记录当前已经有的元素个数
}Contact_Init;

void menu(void);							//菜单打印
void Contact_Add(Contact_Init* ps);			//增加联系人信息到通讯录
void Contact_Del(Contact_Init* ps);			//删除指定的联系人信息
void Contact_Search(Contact_Init* ps);		//查找指定联系人信息
void Contact_Modify(Contact_Init* ps);		//修改指定联系人信息
void Contact_Show(Contact_Init* ps);		//打印通讯录中信息
void Contact_Sort(Contact_Init* ps);

void Init_Contact(Contact_Init* ps);

#endif 

