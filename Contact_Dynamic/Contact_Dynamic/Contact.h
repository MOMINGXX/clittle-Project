#ifndef _Contact_H_
#define _Contact_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define MAX			1000 
#define CAPC_INIT	3		//容量初始值
#define INCREMENT	2		//增量 每次扩容的数量

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

/*		//静态
typedef struct Contact
{
	PeoInfo_Init DATA[MAX];		//存放MAX个的信息
	int size;					//记录当前已经有的元素个数
}Contact_Init;
*/

//动态
typedef struct Contact
{
	PeoInfo_Init* DATA;	//指向动态申请的空间，存放联系人信息
	int size;			//记录当前通讯录中有效信息个数
	int Capacity;		//记录当前通讯录容量大小
}Contact_Init;

void menu(void);							//菜单打印
void Contact_Add(Contact_Init* ps);			//增加联系人信息到通讯录
void Contact_Del(Contact_Init* ps);			//删除指定的联系人信息
void Contact_Search(Contact_Init* ps);		//查找指定联系人信息
void Contact_Modify(Contact_Init* ps);		//修改指定联系人信息
void Contact_Show(Contact_Init* ps);		//打印通讯录中信息
void Contact_Sort(Contact_Init* ps);		//对通讯录进行排序
void Contact_Destory(Contact_Init* ps);		//释放动态内存

void Init_Contact(Contact_Init* ps);

#endif 

