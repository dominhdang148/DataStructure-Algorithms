#include<iostream>
#include<conio.h>
#include<iomanip>
#include<cstring>	
#include<fstream>
using namespace std;
#include"bstree.h"
#include"thuvien.h"
#include"menu.h"
void ChayChuongTrinh()
{
#pragma region Một số lưu ý (PHẢI ĐỌC)
	//Bài này tui code theo cách nhập điều kiện từ bàn phím (VD mng muốn tìm lớp CTK44 thì phải nhập CTK44 vô).
	//Tui biết thầy yêu cầu phải thực hiện trực tiếp (không nhập điều kiện từ bàn phím) nhưng đây là 1 bài tập để ôn
	//và tui cần phải kiểm tra xem hàm có chạy đúng với mọi trường hợp hay không.
	//Mọi người có thể sửa lại để chương trình chạy trực tiếp cũng được. 
	//Cảm ơn mọi người nhe (～o￣3￣)～
#pragma endregion
	int menu, soMenu = 5;
	BSTree root = NULL;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, root);
	} while (menu>0);
}
int main()
{
	ChayChuongTrinh();
	return 1;
}