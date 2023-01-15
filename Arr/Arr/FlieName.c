#define _CRT_SECURE_NO_WARNINGS 1

#include "Arr.h"

int main()
{
	int val;
	Arr_Typedef arr;
	Arr_Init(&arr, 5);
	Arr_Append(&arr, 1);
	Arr_Append(&arr, -3);
	Arr_Append(&arr, 7);
	Arr_Append(&arr, 9); 
	Arr_Append(&arr, 5);
	Arr_Show(&arr);
	if (Is_Full(&arr))
	{
		printf("ÒÑÂú!\n");
	}
	Arr_Enlarge_Capacity(&arr, 2);
	if (Is_Full(&arr))
	{
		printf("ÒÑÂú!\n");
	}
	else
	{
		printf("Î´Âú!\n");
	}
	/*Arr_Sort(&arr);
	Arr_Show(&arr);
	Arr_Inversion(&arr);
	Arr_Show(&arr);
	if (Arr_Delete(&arr, 3, &val))
	{
		printf("É¾³ý³É¹¦!\n");
		printf("Val=%d\n", val);
	}
	else
	{
		printf("É¾³ýÊ§°Ü!\n");
	}*/
	//Arr_Delete(&arr, 1, &val);
	//Arr_Delete_Position(&arr, 2);
	//Arr_Delete_Value(&arr, 2);
	Arr_Show(&arr);
	//printf("Value:%d",arr.Buff[Arr_GetAddr(&arr, 2)]);
	Arr_Destory(&arr);
	return 0;
}