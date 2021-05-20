#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;
#include"2011363_Thuvien.h"
#include"2011363_Menu.h"
void ChayChuongTrinh()
{
	int menu, soMenu = 5;
	List l;
	do
	{
		menu = ChonMenu(soMenu);
		XyLyMenu(menu, l);
		_getch();
	} while (menu > 0);
	
}
int main()
{
	ChayChuongTrinh();
	return 1;
}