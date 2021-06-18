void XuatMenu()
{
	cout << endl << "=============================== HE THONG MENU ===============================";
	cout << endl << "0. Thoat chuong trinh";
	cout << endl << "1. Tao cay BST";
	cout << endl << "2. Xuat cay BST the thu tu tu truoc, giua, cuoi";
	cout << endl << "3. So nut cua cay";
	cout << endl << "4. Dem so nut co key < x";
	cout << endl << "5. Tim nut co khoa x";
	cout << endl << "6. Kiem tra nut co key cho truoc co phai la nut leaf";
	cout << endl << "7. Dem so nut leaf va xuat cac nut leaf";
	cout << endl << "8. Chieu cao cua cay";
	cout << endl << "9. Level cua nut co khoa x";
	cout << endl << "10. So sanh Level 2 nut";
	cout << endl << "11. Them khoa x vao cay";
	cout << endl << "12. Xoa nut co khoa x";
	cout << endl << "=============================================================================";
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
	char filename[80];
	int kq;
	int y;
	int x;
	system("CLS");
	switch (menu)
	{
#pragma region Case 0
	case 0:
		cout << endl << "Thoat khoi chuong trinh";
		cout << endl << "Xin hay nhan 1 phim bat ky de tiep tuc!";
		break;
#pragma endregion
#pragma region Case 1
	case 1:
		cout << endl << "Nhap du lieu tu file";
		cout << endl << "Xin hay nhap ten tap tin: ";
		cin >> filename;
		kq = ReadFile(root, filename);
		if (kq)
			cout << endl << "Da chuyen du lieu file " << filename << " vao cay BST";
		else
			cout << endl << "Khong thanh cong";
		cout << endl << "Xin hay nhan 1 phim bat ky de tiep tuc!";
		break;
#pragma endregion
#pragma region Case 2
	case 2:
		cout << endl << "Xuat cay BST theo thu tu giua";
		cout << endl << "Cay BST hien hanh, xuat theo thu tu NLR:" << endl;
		PreOrder(root);
		cout << endl << "Cay BST hien hanh, xuat theo thu tu LNR: " << endl;
		InOrder(root);
		cout << endl << "Cay BST hien hanh, xuat theo thu tu LRN:" << endl;
		PosOrder(root);
		cout << endl << "Xin hay nhan 1 phim bat ky de tiep tuc!";
		break;
#pragma endregion
#pragma region Case 3
	case 3:
		cout << endl << "Dem so nut cua cay";
		kq = DemSoNut(root);
		cout << endl << "So nut cua cay hien hanh la: " << kq;
		cout << endl << "Cay BST hien hanh: ";
		cout << endl << "NLR: " << endl;
		PreOrder(root);
		cout << endl << "LNR:" << endl;
		InOrder(root);
		cout << endl << "LRN:" << endl;
		PosOrder(root);
		cout << endl << "Xin hay nhan 1 phim bat ky de tiep tuc!";
		break;
#pragma endregion
#pragma region Case 4
	case 4:
		cout << endl << "Dem so nut nho hon x";
		cout << endl << "Xin hay nhap x: ";
		cin >> x;
		kq = DemSoNutNhoHon(root, x);
		cout << endl << "So nut nho hon " << x << " la: " << kq;
		cout << endl << "Cay BST hien hanh: ";
		cout << endl << "NLR: " << endl;
		PreOrder(root);
		cout << endl << "LNR:" << endl;
		InOrder(root);
		cout << endl << "LRN:" << endl;
		PosOrder(root);
		cout << endl << "Xin hay nhan 1 phim bat ky de tiep tuc!";
		break;
#pragma endregion
#pragma region Case 5
	case 5:
		cout << endl << "Tim nut co khoa x";
		cout << endl << "Cay BST hien hanh: ";
		cout << endl << "NLR: " << endl;
		PreOrder(root);
		cout << endl << "LNR:" << endl;
		InOrder(root);
		cout << endl << "LRN:" << endl;
		PosOrder(root);
		cout << endl << "Xin hay nhap x: ";
		cin >> x;
		if (Search(x, root) != NULL)
			cout << endl << x << " co trong cay BST";
		else
			cout << endl << x << " khong co trong cay BST";
		cout << endl << "Xin hay nhan 1 phim bat ky de tiep tuc!";
		break;
#pragma endregion
#pragma region Case 6
	case 6:
		cout << endl << "Kiem tra x co phai la nut la (leaf node).";
		cout << endl << "Cay BST hien hanh: ";
		cout << endl << "NLR: " << endl;
		PreOrder(root);
		cout << endl << "LNR:" << endl;
		InOrder(root);
		cout << endl << "LRN:" << endl;
		PosOrder(root);
		cout << endl << "Xin hay nhap khoa x can kiem tra: ";
		cin >> x;
		system("CLS");
		kq = IsLeaf_X(root, x);
		if (kq == -1)
			cout << endl << "Khong co nut nao co khoa " << x << " trong cay";
		else
			if (kq == 0)
				cout << endl << "Nut co khoa la " << x << " khong phai la nut leaf";
			else
				cout << endl << "Nut co khoa la " << x << " la nut leaf";
		cout << endl << "Xin hay nhan 1 phim bat ky de tiep tuc!";
		break;
#pragma endregion
#pragma region Case 7
	case 7:
		cout << endl << "Dem so nut leaf trong cay";
		cout << endl << "Cac nut leaf trong cay la: " << endl;
		kq = Count_Leaf(root);
		cout << endl << "Cay BST hien hanh co " << kq << " nut leaf";
		cout << endl << "Cay BST hien hanh: ";
		cout << endl << "NLR: " << endl;
		PreOrder(root);
		cout << endl << "LNR:" << endl;
		InOrder(root);
		cout << endl << "LRN:" << endl;
		PosOrder(root);
		cout << endl << "Xin hay nhan 1 phim bat ky de tiep tuc!";
		break;
#pragma endregion
#pragma region Case 8
	case 8:
		cout << endl << "Tinh chieu cao cua cay BST";
		kq = TinhChieuCao(root);
		cout << endl << "Cay BST hien hanh co chieu cao la: " << kq;
		cout << endl << "Cay BST hien hanh: ";
		cout << endl << "NLR: " << endl;
		PreOrder(root);
		cout << endl << "LNR:" << endl;
		InOrder(root);
		cout << endl << "LRN:" << endl;
		PosOrder(root);
		cout << endl << "Xin hay nhan 1 phim batky de tiep tuc!";
		break;
#pragma endregion
#pragma region Case 9
	case 9:
		cout << endl << "Tim level cua khoa x trong cay BST";
		cout << endl << "Xin hay nhap khoa can tim: x = ";
		cin >> x;
		kq = TimLevel_X(root, x);
		if (!Search(x, root))
			cout << endl << "Khong tim thay x trong cay BST";
		else
			cout << endl << "Level cua nut co khoa " << x << " : " << kq;
		cout << endl << "Cay BST hien hanh: ";
		cout << endl << "NLR: " << endl;
		PreOrder(root);
		cout << endl << "LNR:" << endl;
		InOrder(root);
		cout << endl << "LRN:" << endl;
		PosOrder(root);
		cout << endl << "Xin hay nhan 1 phim bat ky de tiep tuc!";
		break;
#pragma endregion
#pragma region Case 10
	case 10:
		cout << endl << "So sanh level cua 2 nut chua khoa x va y";
		cout << endl << "Xin hay nhap khoa x: ";
		cin >> x;
		cout << endl << "Xin hay nhap khoa y: ";
		cin >> y;
		if (!(Search(x, root) || Search(y, root))) //(!Search(x,root)&&!Search(y,root)) Luật De Morgan (～￣▽￣)～
			cout << endl << "Loi, khong tim thay nut chua khoa x hoac khoa y tren BST";
		else
		{
			if (SoSanh_Level(root, x, y) == 1)
				cout << endl << "Level cua nut chua khoa " << x << " sau hon level cua nut chua khoa " << y;
			else
				if (SoSanh_Level(root, x, y) == -1)
					cout << endl << "Level cua nut chua khoa " << y << " sau hon level cua nut chua khoa " << x;
				else
					cout << endl << "Nut chua khoa " << x << " va nut chua khoa " << y << " co cung level";
		}
		cout << endl << "Cay BST hien hanh: ";
		cout << endl << "NLR: " << endl;
		PreOrder(root);
		cout << endl << "LNR:" << endl;
		InOrder(root);
		cout << endl << "LRN:" << endl;
		PosOrder(root);
		cout << endl << "Xin hay nhan 1 phim bat ky de tiep tuc!";
		break;
#pragma endregion
#pragma region Case 11
	case 11:
		cout << endl << "Them 1 khoa x vao trong cay";
		cout << endl << "Xin hay nhap khoa can them: ";
		cin >> x;
		if (InsertNode(root, x) != 1)
			cout << endl << "Them khoa " << x << " khong thanh cong! Xin hay thu lai";
		else
		{
			cout << endl << "Da them khoa " << x << " thanh cong!";
			cout << endl << "Cay BST hien hanh: ";
			cout << endl << "NLR: " << endl;
			PreOrder(root);
			cout << endl << "LNR:" << endl;
			InOrder(root);
			cout << endl << "LRN:" << endl;
			PosOrder(root);
		}
		cout << endl << "Xin hay nhan 1 phim bat ky de tiep tuc!";
		break;
#pragma endregion
#pragma region Case 12
	case 12:
		cout << endl << "Xoa nut co khoa x ";
		cout << endl << "Xin hay nhap khoa can xoa: ";
		cin >> x;
		if (DeleteNode(x, root) == 0)
			cout << endl << "Xoa khong thanh cong!";
		else
		{
			cout << endl << "Xoa thanh cong!";
			cout << endl << "Cay BST hien hanh: ";
			cout << endl << "NLR: " << endl;
			PreOrder(root);
			cout << endl << "LNR:" << endl;
			InOrder(root);
			cout << endl << "LRN:" << endl;
			PosOrder(root);
		}
		cout << endl << "Xin hay nhan 1 phim bat ky de tiep tuc!";
		break;
#pragma endregion

	}
	_getch();
}