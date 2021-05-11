void XuatMenu()
{
	cout << endl << "============================ SAP XEP ============================";
	cout << endl << "0. Thoat chuong trinh";
	cout << endl << "1. Nhap du lieu";
	cout << endl << "2. Xem du lieu";
	cout << endl << "3. Thuat giai sap xep chon (Selection sort)";
	cout << endl << "4. Thuat giai sap xep chen (Insertion sort)";
	cout << endl << "5. Thuat giai sap xeo doi cho truc tiep (Interchange sort)";
	cout << endl << "6. Thuat giai sap xep noi bot (Bubble sort)";
	cout << endl << "=================================================================";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << endl << "Nhap 1 so [0.." << soMenu << "] de chon chuc nang tuong ung: ";
		cin >> stt;
		if (0 <= stt&&stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int menu, int a[MAX], int &n)
{

	system("CLS");
	switch (menu)
	{
	case 0:
		cout << endl << "Thoat chuong trinh.";
		cout << endl << "Nhan 1 phim de tiep tuc";
		break;
	case 1:
		cout << endl << "Nhap du lieu tu dong";
		ImportArray(a, n);
		cout << endl << "Nhap thanh cong! Mang vua nhap :" << endl;
		ExportArray(a, n);
		cout << endl << "Nhan 1 phim de tiep tuc";
		break;
	case 2:
		cout << endl << "Mang hien hanh:" << endl;
		ExportArray(a, n);
		cout << endl << "Nhan 1 phim de tiep tuc";
		break;
	case 3:
		cout << endl << "Thuat giai chon truc tiep:" << endl;
		SelectionSort(a, n);
		cout << endl << "Ket qua cua thuat giai" << endl;
		ExportArray(a, n);
		cout << endl << "Nhan 1 phim de tiep tuc";
		break;
	case 4:
		cout << endl << "Thuat giai chen truc tiep: " << endl;
		InsertionSort(a, n);
		cout << endl << "Ket qua cua thuat giai" << endl;
		ExportArray(a, n);
		cout << endl << "Nhan 1 phim de tiep tuc";
		break;
	case 5:
		cout << endl << "Thuat giai doi cho truc tiep (Interchange Sort): "<<endl;
		InterchangeSort(a, n);
		cout << endl << "Ket qua cua thuat giai: " << endl;
		ExportArray(a, n);
		cout << endl << "Nhan 1 phim de tiep tuc";
		break;
	case 6:
		cout << endl << "Thuat giai noi bot (Bubble Sort): " << endl;
		BubbleSort(a, n);
		cout << endl << "Kew qua cua thuat giai:" << endl;
		ExportArray(a, n);
		cout << endl << "Nhan 1 phim de tiep tuc";
		break;
	}
	_getch();
}