#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>;
using namespace std;
#include"thuvien.h"
#include"menu.h"
void ChayChuongTrinh();
void main()
{
	ChayChuongTrinh();
}
void ChayChuongTrinh()
{
	int menu, soMenu = 6;
	int n = 0;
	int a[MAX];
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
	} while (menu > 0);
	
}