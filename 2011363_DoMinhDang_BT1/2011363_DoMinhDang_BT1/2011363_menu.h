void XuatMenu()
{
	cout << endl << "================================= HE THONG CHUC NANG =================================";
	cout << endl << "0. Thoat khoi chuong trinh";
	cout << endl << "1. Tao danh sach sinh vien";
	cout << endl << "2. Xem danh sach sinh vien";
	cout << endl << "3. Tim kiem theo lop va so tin chi";
	cout << endl << "4. Tim kiem theo ten";
	cout << endl << "5. Tim kiem theo nam sinh va diem trung binh";
	cout << endl << "======================================================================================";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << endl << "Nhap 1 so trong khoang [0.." << soMenu << "] de chon chuc nang tuong ung: ";
		cin >> stt;
		if (0 <= stt&&stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int menu, SinhVien a[MAX], int &n)
{
	int kq;
	char filename[MAX];
	system("CLS");
	switch (menu)
	{
	case 0:
		cout << endl << "Thoat khoi chuong trinh";
		break;
	case 1:
		cout << endl << "Tao danh sach sinh vien";
		do
		{
			cout << endl << "Nhap ten tap tin: ";
			cin >> filename;
			kq = TapTin_MangCT(filename, a, n);
		} while (!kq);
		cout << endl << "Danh sach sinh vien vua nhap: " << endl;
		XuatDanhSachSinhVien(a, n);
		cout << endl;
		break;
	case 2:
		cout << endl << "Xem danh sach sinh vien";
		cout << endl << "Danh sach sinh vien hien hanh: " << endl;
		XuatDanhSachSinhVien(a, n);
		break;
	case 3:
		cout << endl << "Tim kiem sinh vien CTK37 co so tin chi tich luy tren 41";
		TimTheoLopVaTinChi(a, n);
		break;
	case 4:
		cout << endl << "Tim kiem theo ten :Hoa";
		TimTheoTen(a, n);
		break;
	case 5:
		cout << endl << "Tim kiem sinh vien sinh sau nam 1993 va co diem trung binh <=6.2";
		TimTheoNamSinhVaDiemTrungBinh(a, n);
		break;
	}
	_getch();
}