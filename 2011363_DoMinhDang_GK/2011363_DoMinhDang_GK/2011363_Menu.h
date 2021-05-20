void XuatMenu()
{
	cout << endl << "================================ QUAN  LY SINH VIEN ================================";
	cout << endl << "0. Thoat chuong trinh";
	cout << endl << "1. Nhap du lieu";
	cout << endl << "2. Xem danh sach sinh vien hien hanh";
	cout << endl << "3. Chuc nang 3";
	cout << endl << "4. Chuc nang 4";
	cout << endl << "5. Chuc nang 5";
	cout << endl << "====================================================================================";

}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << endl << "Chon 1 so trong [0.." << soMenu << "] de chon chuc nang tuong ung: ";
		cin >> stt;
		break;
	}
	return stt;
}
void XyLyMenu(int menu, List &l)
{
	char filename[80];
	int kq;
	int choose;
	system("CLS");
	switch (menu)
	{
	case 0:
		cout << endl << "Thoat chuong trinh";
		cout << endl << "Nhan 1 phim bat ki de tiep tuc!";
		break;
	case 1:
		cout << endl << "Nhap du lieu tu file!";
		cout << endl << "Chuong trinh se nhap du lieu tu file HocVien.txt! Ban co muon doi file khac khong?	";
		cout << endl << "1: Co";
		cout << endl << "0: Khong";
		cout << endl << "Xin hay nhap so de tra loi: ";
		cin >> choose;
		if (choose == 0)
		{
			system("CLS");
			kq = Read_File("HocVien.txt", l);
		}
		else
		{
			do
			{
				system("CLS");
				cout << endl << "Nhap du lieu tu file!";
				cout << endl << "Xin hay nhap ten tap tin: ";
				_flushall();
				cin >> filename;
				kq = Read_File(filename, l);
				if (kq == 0)
				{
					cout << endl << "Loi nhap file. Xin hay nhap lai!";
					_getch();
				}
			} while (kq == 0);
		}
		cout << endl << "Nhap thanh cong! Danh sach sinh vien sau khi nhap:" << endl;
		XuatDSSinhVien(l);
		break;
	case 2:
		XuatDSSinhVien(l);
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		cout << endl << "Loi! Xin hay nhap lai!";
		_getch();
		break;
	}
}