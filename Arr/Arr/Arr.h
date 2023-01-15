#ifndef __ARR_H__
#define __ARR_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//����һ����������		�������������ֽ�struct Arr
typedef struct Arr
{
	int* Buff;			//�洢�����һ��Ԫ�ص�ַ
	int size;			//��¼��ǰ��������Ч����
	int Capacitty;		//��¼����������С
}Arr_Typedef;

void Arr_Init(Arr_Typedef* pArr, int Length);					 //�����ʼ��
bool Arr_Append(Arr_Typedef* pArr, int Valu);					 //��ĩβ��׷��
bool Arr_Insert(Arr_Typedef* pArr, int Position, int Valu);		 //��ָ��λ�ô����
bool Arr_Delete(Arr_Typedef* pArr, int Position, int* Valu);     //ɾ��ָ��Ԫ��
bool Arr_Delete_Position(Arr_Typedef* pArr, int Position);		 //ɾ��������ָ��λ�õ�ֵ
bool Arr_Delete_Value(Arr_Typedef* pArr, int Valu);				 //ɾ��������ָ��ֵ
int  Arr_GetAddr(const Arr_Typedef* pArr, int Valu);			 //�����±����ֵ
bool Is_Empty(const Arr_Typedef* pArr);							 //�ж������Ƿ�Ϊ��
bool Is_Full(const Arr_Typedef* pArr);							 //�ж������Ƿ�����
void Arr_Sort(const Arr_Typedef* pArr);							 //����
void Arr_Show(const Arr_Typedef* pArr);							 //��ʾ����
void Arr_Inversion(const Arr_Typedef* pArr);					 //���鵹��
void Arr_Destory(Arr_Typedef* pArr);							 //�ͷŶ�̬���ٵĿռ�
void Arr_Enlarge_Capacity(Arr_Typedef* pArr, int Quantity);		 //��������

#endif // !__ARR_H__