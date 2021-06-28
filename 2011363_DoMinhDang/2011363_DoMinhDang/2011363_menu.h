void XuatMenu()
{
	cout << endl << "======================== HE THONG MENU ========================";
	cout << endl << "0. Thoat chuong trinh";
	cout << endl << "1. Nhap du lieu";
	cout << endl << "2. Xem danh sach hien hanh";
	cout << endl << "3. Tinh so nut cua cay";
	cout << endl << "4. Thong tin nhan vien LD19022";
	cout << endl << "5. Sua nam sinh cua nhan vien LD18041 thanh 1990";
	cout << endl << "===============================================================";
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
	BSTree NV;
	system("CLS");
	switch (menu)
	{
	case 0:
		cout << endl << "Thoat chuong trinh";
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 1:
		cout << endl << "Nhap du lieu tu file";
		kq = ReadFile("bangluong.txt", root);
		if (!kq)
			cout << endl << "Nhap that bai";
		else
			cout << endl << "Nhap thanh cong";
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 2:
		Xuat_NV_LNR(root);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 3:
		cout << endl << "Dem so nut cua cay";
		kq = DemSoNut(root);
		cout << endl << "So nut cua cay hien hanh la: " << kq;
		cout << endl << "Danh sach nhan vien hien hanh:" << endl;
		Xuat_NV_LNR(root);
		break;
	case 4:
		cout << endl << "Thong tin cua nhan vien LD19022" << endl;
		NV = Search("LD19022", root);
		NV->left = NULL;
		NV->right = NULL;
		Xuat_NV_LNR(NV);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 5:
		cout << endl << "Sua nam sinh cua nhan vien LD18041 thanh 1990 ";
		kq = SuaThongTinNamSinh("LD18041",1990, root);
		cout << endl << "Danh sach nhan vien sau khi sua:" << endl;
		Xuat_NV_LNR(root);
		break;
	}
	_getch();
}
