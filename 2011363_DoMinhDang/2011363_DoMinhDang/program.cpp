#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;
#include"2011363_BST.h"
#include"2011363_thuvien.h"
#include"2011363_menu.h"
void ChayChuongTrinh()
{
	int menu, soMenu = 5;
	BSTree root = NULL;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, root);
	} while (menu > 0);
}
int main()
{
	ChayChuongTrinh();
	
	return 1;
}