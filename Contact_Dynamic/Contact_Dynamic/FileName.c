#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

//int main()
//{
//	int input = 0;
//	struct Contact Con;		//����ͨѶ¼
//	Init_Contact(&Con);		//ͨѶ¼��ʼ��
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
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 6)
//		{
//			Contact_arr[input](&Con);
//		}
//		else if (0 == input)
//		{
//			printf("�˳�\n");
//		}
//		else 
//		{
//			printf("ѡ�����!\n");
//			printf("������ѡ��!\n");
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
		printf("��ѡ��:>");
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
			printf("�˳�\n");
			Contact_Destory(&Con);
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}
