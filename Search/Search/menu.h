void XuatMenu()
{
	cout << endl << "====================== SEARCH ======================";
	cout << endl << "0. Thoat chuong trinh";
	cout << endl << "1. Nhap mang tu dong";
	cout << endl << "2. Xuat mang";
	cout << endl << "3. Linear Search";
	cout << endl << "4. Linear Search with Guard";
	cout << endl << "5. Binary Search";
	cout << endl << "6. Interpolation Search";
	cout << endl << "====================================================";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << endl << "Chon 1 so thu tu [0.." << soMenu << "] de chon chuc nang tuong ung: ";
		cin >> stt;
		if (0 <= stt&&stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int menu, int a[MAX], int &n)
{
	int x, kq;
	system("CLS");
	switch (menu)
	{
	case 0:
		cout << endl << "Thoat chuong trinh";
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 1:
		cout << endl << "Nhap mang";
		NhapMang(a,n);
		cout << endl << "Nhap thanh cong! Mang sau khi nhap:" << endl;
		XuatMang(a, n);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 2:
		cout << endl << "Mang hien hanh:" << endl;
		XuatMang(a, n);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 3:
		cout << endl << "Linear Search";
		cout << endl << "Mang ban dau: " << endl;
		XuatMang(a, n);
		cout << endl << "Nhap phan tu can tim kiem: ";
		cin >> x;
		kq = LinearSearchFirstElement(a, n, x);
		if (kq == -1)
			cout << endl << "Khong tim thay phan tu " << x << " trong mang!";
		else
			cout << endl << "Vi tri dau tien cua phan tu " << x << " la: " << kq;
		kq = LinearSearchLastElement(a, n, x);
		if (kq == -1)
			cout << endl << "Khong tim thay phan tu " << x << " trong mang!";
		else
			cout << endl << "Vi tri cuoi cung cua phan tu " << x << " la: " << kq;
		LinearSearchAllElement(a, n, x);
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 4:
		cout << endl << "Linear Search With Guard";
		cout << endl << "Mang ban dau: " << endl;
		XuatMang(a, n);
		cout << endl << "Nhap phan tu can tim kiem: ";
		cin >> x;
		kq = LinearSearchFirstElementWithGuard(a, n, x);
		if (kq == -1)
			cout << endl << "Khong tim thay phan tu " << x << " trong mang!";
		else
			cout << endl << "Vi tri dau tien cua phan tu " << x << " la: " << kq;
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 5:
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	case 6:
		cout << endl << "Nhan 1 phim bat ky de tiep tuc";
		break;
	}
}