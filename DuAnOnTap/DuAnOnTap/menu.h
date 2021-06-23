#pragma region Một số lưu ý (PHẢI ĐỌC)
//Bài này tui code theo cách nhập điều kiện từ bàn phím (VD mng muốn tìm lớp CTK44 thì phải nhập CTK44 vô).
//Tui biết thầy yêu cầu phải thực hiện trực tiếp (không nhập điều kiện từ bàn phím) nhưng đây là 1 bài tập để ôn
//và tui cần phải kiểm tra xem hàm có chạy đúng với mọi trường hợp hay không.
//Mọi người có thể sửa lại để chương trình chạy trực tiếp cũng được. 
//Cảm ơn mọi người nhe (～o￣3￣)～
#pragma endregion
void XuatMenu()
{
	cout << endl << "==================== HE THONG MENU ====================";
	cout << endl << "0. Thoat chuong trinh";
	cout << endl << "1. Nhap du lieu";
	cout << endl << "2. Xem danh sach hoc vien";
	cout << endl << "3. Sua so tin chi cua hoc vien";
	cout << endl << "4. Xoa hoc vien co ma hoc vien cho truoc";
	cout << endl << "5. Trich danh sach hoc vien cua 1 lop";
	cout << endl << "=======================================================";
}
int ChonMenu(int soMenu)
{
	int stt;
	while (true)
	{
		system("CLS");
		XuatMenu();
		cout << endl << "Xin hay nhap 1 so [0.." << soMenu << "] de chon chuc nang tuong ung: ";
		cin >> stt;
		if (0 <= stt&&stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int menu, BSTree &root)
{
	int kq;
	int choose;
	char maHocVien[10];
	BSTree dsLop = NULL;
	system("CLS");
	switch (menu)
	{
#pragma region Case 0
	case 0:
		cout << endl << "Thoat chuong trinh";
		cout << endl << "Nhan 1 phim bat ky de tiep tuc!";
		break;
#pragma endregion
#pragma region Case 1
	case 1:

		cout << endl << "Nhap du lieu tu file";
		cout << endl << "Chuong trinh se nhap du lieu tu file 'HocVien.txt' . Ban co muon tiep tuc?";
		cout << endl << "1. Co";
		cout << '\t' << '\t' << "0. Khong, nhap du lieu tu file khac";
		cout << endl << "Chon 1 hoac 0 de chon chuc nang tuong ung: ";
		cin >> choose;
		system("CLS");
		if (choose == 1)
		{
			cout << endl << "Nhap du lieu tu file";
			kq = ReadFile(root, "HocVien.txt");
			if (kq == 1)
				cout << endl << "Da chuyen du lieu tu file 'HocVien.txt' thanh cong!";
			else
				cout << endl << "Loi! Xin hay thu lai";
		}
		else
		{
			char file[100];
			do
			{
				system("CLS");
				cout << endl << "Nhap du lieu tu file";
				cout << endl << "Xin hay nhap ten file: ";
				cin >> file;
				kq = ReadFile(root, file);
				if (kq == 0)
				{
					cout << endl << "Loi! Xin hay thu lai";
					_getch();
				}
				else
					cout << endl << "Da chuyen du lieu tu file '" << file << "' thanh cong!";
			} while (kq == 0);
		}
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
#pragma endregion
#pragma region Case 2
	case 2:
		
		XuatDanhSachHocVienTheoThuTu(root);
		break;
#pragma endregion
#pragma region Case 3
	case 3:
		int tLuy;
		cout << endl << "Sua diem tich luy cua hoc vien co ma hoc vien cho truoc";
		cout << endl << "Xin hay nhap ma hoc vien cua hoc vien can sua: ";
		cin >> maHocVien;
		cout << endl << "Xin hay nhap diem tich luy moi cua hoc vien: ";
		cin >> tLuy;
		kq = SuaDiemTichLuyCuaHocVien(maHocVien, tLuy, root);
		if (!kq)
			cout << endl << "Sua khong thanh cong!";
		else
		{
			system("CLS");
			cout << endl << "Sua thanh cong! Danh sach hoc vien sau khi sua: " << endl;
			XuatDanhSachHocVienTheoThuTu(root);
		}
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
#pragma endregion
#pragma region Case 4
	case 4:
		cout << endl << "Xoa 1 hoc vien co ma hoc vien cho truoc";
		cout << endl << "Xin hay nhap ma hoc vien: ";
		cin >> maHocVien;
		kq = XoaHocVien(maHocVien, root);
		if (!kq)
			cout << endl << "Xoa khong thanh cong";
		else
		{
			cout << endl << "Xoa thanh cong! Danh sach hoc vien hien hanh: ";
			XuatDanhSachHocVienTheoThuTu(root);
		}
		cout << endl << "Nhan 1 phim bay ky de tiep tuc";
		break;
#pragma endregion
#pragma region Case 5
	case 5:
		char lop[10];
		cout << endl << "Xuat danh sach hoc vien theo lop";
		cout << endl << "Xin hay nhap ten lop: ";
		cin >> lop;
		cout << endl << "Danh sach hoc vien lop " << lop << " la:" << endl;
		XuatDanhSachLop(lop, root);
		cout << endl << "Nhan 1 phim bay ky de tiep tuc";
		break;
#pragma endregion
	}
	_getch();
}


