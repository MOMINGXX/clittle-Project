#ifndef __ARR_H__
#define __ARR_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//定义一个数组类型		该数据类型名字叫struct Arr
typedef struct Arr
{
	int* Buff;			//存储数组的一个元素地址
	int size;			//记录当前数组中有效个数
	int Capacitty;		//记录数组容量大小
}Arr_Typedef;

void Arr_Init(Arr_Typedef* pArr, int Length);					 //数组初始化
bool Arr_Append(Arr_Typedef* pArr, int Valu);					 //在末尾处追加
bool Arr_Insert(Arr_Typedef* pArr, int Position, int Valu);		 //在指定位置处添加
bool Arr_Delete(Arr_Typedef* pArr, int Position, int* Valu);     //删除指定元素
bool Arr_Delete_Position(Arr_Typedef* pArr, int Position);		 //删除数组中指定位置的值
bool Arr_Delete_Value(Arr_Typedef* pArr, int Valu);				 //删除数组中指定值
int  Arr_GetAddr(const Arr_Typedef* pArr, int Valu);			 //根据下标查找值
bool Is_Empty(const Arr_Typedef* pArr);							 //判断数组是否为空
bool Is_Full(const Arr_Typedef* pArr);							 //判断数组是否已满
void Arr_Sort(const Arr_Typedef* pArr);							 //排序
void Arr_Show(const Arr_Typedef* pArr);							 //显示数组
void Arr_Inversion(const Arr_Typedef* pArr);					 //数组倒置
void Arr_Destory(Arr_Typedef* pArr);							 //释放动态开辟的空间
void Arr_Enlarge_Capacity(Arr_Typedef* pArr, int Quantity);		 //数组扩容

#endif // !__ARR_H__