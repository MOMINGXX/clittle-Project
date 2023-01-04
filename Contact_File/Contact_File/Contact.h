#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
#define NAME_MAX		20
#define SEX_MAX			5
#define TELE_MAX		12
#define ADDR_MAX		20

#define CAPACITY_INIT	3		//初始容量大小
#define INCREMENT		2		//每次需增加容量的大小
#define TITLE		(printf("%4s\t%-20s\t%-3s\t%5s\t%12s\t%20s\n","序号", "姓名", "年龄", "性别", "电话", "地址"))

//联系人信息	姓名 年龄 性别 电话 地址
typedef struct
{
	char name[NAME_MAX];
	int age;
	char Sex[SEX_MAX];
	char Tele[TELE_MAX];
	char Addr[ADDR_MAX];
}PeoInfo_Init;

//通讯录		联系人信息 通讯录大小  通讯录容量
typedef struct
{
	PeoInfo_Init* DATA;		//指向动态开辟空间。存放联系人信息
	int size;				//记录当前通讯录中有效信息个数
	int Capacity;			//记录当前通讯录容量大小
}Contact_Init;

//通讯录菜单打印
void Contact_Menu();
//通讯录初始化
void Init_Contact(Contact_Init *ps);
//增加通讯录中联系人信息
void Contact_Add(Contact_Init* ps);
//删除通讯录中指定联系人信息
void Contact_Del(Contact_Init* ps);
//查找通讯录中指定联系人信息
void Contact_Search(Contact_Init* ps);
//修改通讯录中指定联系人信息
void Contact_Modify(Contact_Init* ps);
//对通讯录中联系人排序
void Contact_Sort(Contact_Init* ps);
//保存通讯录中联系人信息
void Contact_Save(Contact_Init* ps);
//显示通讯录中信息
void Contact_Show(Contact_Init* ps);
//void Contact_Show(const Contact_Init* ps);	//防止内容被修改
//释放开辟的内存
void Contact_Destory(Contact_Init* ps);

