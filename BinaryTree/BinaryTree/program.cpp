#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
#include"bsTree.h"
#include"thuvien.h"
#include"menu.h"
void ChayChuongTrinh()
{
	int menu, soMenu = 12;
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