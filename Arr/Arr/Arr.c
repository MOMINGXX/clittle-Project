#define _CRT_SECURE_NO_WARNINGS 1

#include "Arr.h"

/****
	* @brief	�����ʼ��
	* @param   	pArr	�������͵�ַ
	* @param		Length	����������С
	* @return   ��
	* Sample usage:Arr_Init(&arr,5);
	*/
void Arr_Init(Arr_Typedef *pArr,int Length)
{
	pArr->Buff = (int*)malloc(Length * sizeof(int));
	//�жϿ��ٳɹ����
	if (NULL == pArr->Buff)
	{
		perror("Arr_Init");
		return;
	}
	pArr->size = 0;
	//pArr->Increment = 0;
	pArr->Capacitty = Length;
}

/****
	* @brief	�ж������Ƿ�Ϊ��
	* @param   	pArr	�������͵�ַ
	* @return   true :	����Ϊ�� 
	*			false:	����Ϊ�ǿ�
	* Sample usage:Is_Empty(&arr);
	*/
bool Is_Empty(const Arr_Typedef* pArr)
{
	if (0 == pArr->size)
	{
		return true;
	}
	return false;
}

/****
	* @brief	�ж������Ƿ�����
	* @param   	pArr	�������͵�ַ
	* @return   true :	��������
	*			false:	����û��
	* Sample usage:Is_Full(&arr);
	*/
bool Is_Full(const Arr_Typedef* pArr)
{
	if (pArr->Capacitty == pArr->size)
	{
		return true;
	}
	return false;
}

/****
	* @brief	�ҵ���Ҫ���ҵ������±�
	* @param   	pArr	�������͵�ַ
	* @return   i		Ҫ���������±�
	*			-1		δ�ҵ�����
	* Sample usage:Is_Full(&arr);
	*/
static int Arr_Find(const Arr_Typedef* pArr, int Valu)
{
	int i = 0;
	for (i = 0; i < pArr->size; i++)
	{
		if (pArr->Buff[i] == Valu)
		{
			return i;
		}
	}
	return -1;
}

/****
	* @brief	Ϊ��������
	* @param   	Quantity	��������
	* Sample usage:Arr_Enlarge_Capacity(&arr,2);
	*/
void Arr_Enlarge_Capacity(Arr_Typedef* pArr, int Quantity)
{
	int* ps = NULL;
	if (pArr->Capacitty == pArr->size)
	{
		ps = (int*)realloc(pArr->Buff, (pArr->Capacitty + Quantity) * sizeof(int));
		if (ps == NULL)
		{
			perror("Arr_Enlarge_Capacity");
			return;
		}
		pArr->Buff = ps;
		pArr->Capacitty += Quantity;
	}
}


/****
	* @brief	����β��׷��ֵ
	* @param   	pArr	�������͵�ַ
	* @param   	Valu	׷�ӵ�ֵ
	* @return   true :	׷�ӳɹ�
	*			false:	׷��ʧ��
	* Sample usage:Arr_Append(&arr,1);
	*/
bool Arr_Append(Arr_Typedef* pArr,int Valu)
{
	if (Is_Full(pArr))
	{
		return false;
	}
	else
	{
		pArr->Buff[pArr->size] = Valu;
		pArr->size++;
		return true; 
	}
}

/****
	* @brief	������ָ��λ�ò���ֵ
	* @param   	pArr		�������͵�ַ
	* @param   	Position	�����λ�� 
	*						λ�ô� 1 ��ʼ	��С��������Ч���� +1 ��ֵ
	* @param   	Valu		�����ֵ
	* @return   true :		����ɹ�
	*			false:		����ʧ��
	* Sample usage:Arr_Insert(&arr,2,6);
	*/
bool Arr_Insert(Arr_Typedef* pArr,int Position,int Valu)
{
	int i = 0;
	if (Is_Full(pArr))
	{
		return false;
	}
	if (Position <1 || Position >pArr->size + 1)
	{
		return false;
	}
	
	for (i = pArr->size - 1; i >= Position - 1; i--)
	{
		pArr->Buff[i + 1] = pArr->Buff[i];
	}
	pArr->Buff[Position-1] = Valu;
	pArr->size++;
	return true;
}

/****
	* @brief	ɾ��������ָ��λ�õ�ֵ
	* @param   	pArr		�������͵�ַ
	* @param   	Position	ɾ��ֵ��λ��
	*						λ�ô� 1 ��ʼ	��С��������Ч������ֵ
	* @param   	Valu		ɾ����ֵ		�ò������ڶ���ɾ��λ�õ�ֵ
	* @return   true :		ɾ���ɹ�
	*			false:		ɾ��ʧ��
	* Sample usage:Arr_Delete(&arr,2,&val);
	*/
bool Arr_Delete(Arr_Typedef* pArr,int Position, int *Valu)
{
	int i = 0;
	if (Is_Empty(pArr))
	{
		return false;
	}
	if (Position <1 || Position >pArr->size)
	{
		return false;
	}

	*Valu = pArr->Buff[Position - 1];

	for (i = Position; i < pArr->size; i++)
	{
		pArr->Buff[i - 1] = pArr->Buff[i];
	}
	pArr->size--;
	return true;
}

/****
	* @brief	ɾ��������ָ��λ�õ�ֵ
	* @param   	pArr		�������͵�ַ
	* @param   	Position	ɾ��ֵ��λ��
	*						λ�ô� 1 ��ʼ	��С��������Ч������ֵ
	* @return   true :		ɾ���ɹ�
	*			false:		ɾ��ʧ��
	* Sample usage:Arr_Delete_Position(&arr,2);
	*/
bool Arr_Delete_Position(Arr_Typedef* pArr, int Position)
{
	int i = 0;
	if (Is_Empty(pArr) || (Position <1 || Position >pArr->size))
	{
		return false;
	}
	else
	{
		for (i = Position; i < pArr->size; i++)
		{
			pArr->Buff[i - 1] = pArr->Buff[i];
		}
		pArr->size--;
		return true;
	}
}

/****
	* @brief	ɾ��������ָ��ֵ
	* @param   	pArr	�������͵�ַ
	* @param   	Valu	ָ����ֵ
	* @return   true :	ɾ���ɹ�
	*			false:	ɾ��ʧ��
	* Sample usage:Arr_Delete_Value(&arr,2);
	*/
bool Arr_Delete_Value(Arr_Typedef* pArr, int Valu)
{
	int i = 0;
	int ret = Arr_Find(pArr, Valu);
	if (Is_Empty(pArr) || ret == -1)
	{
		return false;
	}
	else
	{
		for (i = ret; i < pArr->size; i++)
		{
			pArr->Buff[i] = pArr->Buff[i + 1];
		}
		pArr->size--;
		return true;
	}
}

/****
	* @brief	��ȡ������ָ��ֵ�ĵ�ַ
	* @param   	pArr	�������͵�ַ
	* @param   	Valu	ָ��ֵ
	* @return   ret :	ָ��ֵ�ĵ�ַ
	*			-1  :	δ�ҵ�����
	* Sample usage:Arr_GetAddr(&arr,2);
	*/
int Arr_GetAddr(const Arr_Typedef* pArr, int Valu)
{
	int ret = Arr_Find(pArr,Valu);
	if (-1 == ret)
	{
		return - 1;
	}
	return ret;
}

void Arr_Sort(const Arr_Typedef* pArr)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pArr->size; i++)
	{
		for (j = 0; j < pArr->size; j++)
		{
			if (pArr->Buff[i] < pArr->Buff[j])
			{
				int temp = pArr->Buff[i];
				pArr->Buff[i] = pArr->Buff[j];
				pArr->Buff[j] = temp;
			}
		}
	}
}

void Arr_Inversion(const Arr_Typedef* pArr)
{
	int left = 0;
	int right = pArr->size - 1;
	while (left < right)
	{
		int temp = pArr->Buff[left];
		pArr->Buff[left] = pArr->Buff[right];
		pArr->Buff[right] = temp;
		left++;
		right--;
	}
}

/****
	* @brief	�����ӡ
	@ param   	pArr	�������͵�ַ
	* Sample usage:Arr_Show(&arr);
	*/
void Arr_Show(const Arr_Typedef* pArr)
{
	int i = 0;
	if (0 == pArr->size)
	{
		printf("����Ϊ�գ�\n");
	}
	else
	{
		for (i = 0; i < pArr->size; i++)
		{
			printf("%d ", pArr->Buff[i]);
		}
		printf("\n");
	}
}

/****
	* @brief	�ͷŶ�̬���ٵĿռ�
	@ param   	pArr	�������͵�ַ
	* Sample usage:Arr_Destory(&arr);
	*/
void Arr_Destory(Arr_Typedef* pArr)
{
	free(pArr->Buff);
	pArr->Buff = NULL;
}