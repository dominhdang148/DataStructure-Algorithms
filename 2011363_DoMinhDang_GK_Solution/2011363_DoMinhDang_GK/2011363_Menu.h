void XuatMenu()
{
	cout << endl << "================================= QUAN LY HOC VIEN =================================";
	cout << endl << "0. Thoat chuong trinh";
	cout << endl << "1. Nhap du lieu";
	cout << endl << "2. Xem danh sach sinh vien hien hanh";
	cout << endl << "3. Sua so tin chi tich luy cua hoc vien";
	cout << endl << "4. Xuat danh sach hoc vien theo lop";
	cout << endl << "5. Xoa tat ca hoc vien co nam sinh";
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
	char lop[10];
	char maHocVien[10];
	char filename[80];
	List lkq;
	int kq;
	int nam;
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
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 3:
		cout << endl << "Sua so tin chi cua hoc vien";
		cout << endl << "Xin hay nhap ma so cua hoc vien can sua: ";
		cin >> maHocVien;
		SuaTinChiTichLuyCuaHocVien(maHocVien, l);
		cout << endl << "Danh sach hoc vien sau khi sua" << endl;
		XuatDSSinhVien(l);
		break;
	case 4:
		cout << endl << "Xuat danh sach hoc vien cua 1 lop";
		cout << endl << "Xin hay nhap lop can xuat: ";
		cin >> lop;
		XuatDanhSachHVCuaLop(lop, l);
		break;
	case 5:
		cout << endl << "Xoa hoc vien co nam sinh ra khoi danh sach";
		cout << endl << "Xin hay nhap nam sinh:";
		cin >> nam;
		XoaHocVienCoNamSinh(l, nam);
		cout << endl << "Danh sach hoc vien sau khi xoa: ";
		XuatDSSinhVien(l);
		break;
	default:
		cout << endl << "Loi! Xin hay nhap lai!";
		_getch();
		break;
	}
}