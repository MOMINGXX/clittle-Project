#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

void (*ContactBuff[8])(Contact_Init*) = { 0, Contact_Add,
										 	 Contact_Del,
											 Contact_Search,
											 Contact_Modify,
											 Contact_Show,
											 Contact_Sort, 
										  	 Contact_Save};


int main()
{
	int input = 0;
	Contact_Init Con;
	Init_Contact(&Con);
	do
	{
		Contact_Menu();
		printf("ÇëÑ¡Ôñ:>");
		scanf_s("%d",&input);
		if (1 <= input && input <= 7)
		{
			ContactBuff[input](&Con);
		}
		else if(0 == input)
		{
			Contact_Save(&Con);
			Contact_Destory(&Con);
			return 0;
		}
		else
		{
			printf("Ñ¡Ôñ´íÎó!\n");
		}
	} while (input);
	return 0;
}