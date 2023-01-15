#define _CRT_SECURE_NO_WARNINGS 1

#include "Arr.h"

/****
	* @brief	数组初始化
	* @param   	pArr	数组类型地址
	* @param		Length	数组容量大小
	* @return   无
	* Sample usage:Arr_Init(&arr,5);
	*/
void Arr_Init(Arr_Typedef *pArr,int Length)
{
	pArr->Buff = (int*)malloc(Length * sizeof(int));
	//判断开辟成功与否
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
	* @brief	判断数组是否为空
	* @param   	pArr	数组类型地址
	* @return   true :	数组为空 
	*			false:	数组为非空
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
	* @brief	判断数组是否已满
	* @param   	pArr	数组类型地址
	* @return   true :	数组已满
	*			false:	数组没满
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
	* @brief	找到需要查找的数的下标
	* @param   	pArr	数组类型地址
	* @return   i		要查找数的下标
	*			-1		未找到该数
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
	* @brief	为数组扩容
	* @param   	Quantity	扩容增量
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
	* @brief	数组尾部追加值
	* @param   	pArr	数组类型地址
	* @param   	Valu	追加的值
	* @return   true :	追加成功
	*			false:	追加失败
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
	* @brief	在数组指定位置插入值
	* @param   	pArr		数组类型地址
	* @param   	Position	插入的位置 
	*						位置从 1 开始	且小于数组有效个数 +1 的值
	* @param   	Valu		插入的值
	* @return   true :		插入成功
	*			false:		插入失败
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
	* @brief	删除数组中指定位置的值
	* @param   	pArr		数组类型地址
	* @param   	Position	删除值的位置
	*						位置从 1 开始	且小于数组有效个数的值
	* @param   	Valu		删除的值		该参数用于读出删除位置的值
	* @return   true :		删除成功
	*			false:		删除失败
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
	* @brief	删除数组中指定位置的值
	* @param   	pArr		数组类型地址
	* @param   	Position	删除值的位置
	*						位置从 1 开始	且小于数组有效个数的值
	* @return   true :		删除成功
	*			false:		删除失败
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
	* @brief	删除数组中指定值
	* @param   	pArr	数组类型地址
	* @param   	Valu	指定的值
	* @return   true :	删除成功
	*			false:	删除失败
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
	* @brief	获取数组中指定值的地址
	* @param   	pArr	数组类型地址
	* @param   	Valu	指定值
	* @return   ret :	指定值的地址
	*			-1  :	未找到该数
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
	* @brief	数组打印
	@ param   	pArr	数组类型地址
	* Sample usage:Arr_Show(&arr);
	*/
void Arr_Show(const Arr_Typedef* pArr)
{
	int i = 0;
	if (0 == pArr->size)
	{
		printf("数组为空！\n");
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
	* @brief	释放动态开辟的空间
	@ param   	pArr	数组类型地址
	* Sample usage:Arr_Destory(&arr);
	*/
void Arr_Destory(Arr_Typedef* pArr)
{
	free(pArr->Buff);
	pArr->Buff = NULL;
}