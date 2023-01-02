#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

//int main()
//{
//	int input = 0;
//	struct Contact Con;		//创建通讯录
//	Init_Contact(&Con);		//通讯录初始化
//	void (*Contact_arr[7])(Contact_Init*) = {	Destory_contact,
//												Contact_Add,
//												Contact_Del,
//												Contact_Search,
//												Contact_Modify,
//												Contact_Show,
//												Contact_Sort };
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 6)
//		{
//			Contact_arr[input](&Con);
//		}
//		else if (0 == input)
//		{
//			printf("退出\n");
//		}
//		else 
//		{
//			printf("选择错误!\n");
//			printf("请重新选择!\n");
//		}
//	} while (input);
//	return 0;
//}


int main()
{
	int input = 0;
	Contact_Init Con;
	Init_Contact(&Con);
	do
	{
		menu();
		printf("请选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case Add:
			Contact_Add(&Con);
			break;
		case Del:
			Contact_Del(&Con);
			break;
		case Search:
			Contact_Search(&Con);
			break;
		case Modify:
			Contact_Modify(&Con);
			break;
		case Show:
			Contact_Show(&Con);
			break;
		case Sort:
			Contact_Sort(&Con);
			break;
		case Exit:
			printf("退出\n");
			Contact_Destory(&Con);
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
