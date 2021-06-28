#pragma region Một số lưu ý (PHẢI ĐỌC)
//Bài này tui code theo cách nhập điều kiện từ bàn phím (VD mng muốn tìm lớp CTK44 thì phải nhập CTK44 vô).
//Tui biết thầy yêu cầu phải thực hiện trực tiếp (không nhập điều kiện từ bàn phím) nhưng đây là 1 bài tập để ôn
//và tui cần phải kiểm tra xem hàm có chạy đúng với mọi trường hợp hay không.
//Mọi người có thể sửa lại để chương trình chạy trực tiếp cũng được. 
//Cảm ơn mọi người nhe (～o￣3￣)～
#pragma endregion
#pragma region Định nghĩa kiểu dữ liệu và cây nhị phân
struct HocVien
{
	char maHV[10];
	char hoHV[10];
	char tenLot[10];
	char tenHV[10];
	char lop[10];
	int namSinh;
	double dtb;
	int tichLuy;
};
typedef HocVien KeyType;
struct BSNode
{
	KeyType key;
	BSNode *left;
	BSNode *right;
};
typedef BSNode *BSTree;
#pragma endregion
#pragma region Khai báo nguyên mẫu hàm
void CreateBST(BSTree &root);
BSNode *CreateNode(KeyType x);
int InsertNode(BSTree &root, KeyType x);
int ReadFile(BSTree &root, char *filename);
void Line();
void Title();
void Xuat1HocVien(KeyType x);
void XuatDanhSachHocVienTheoThuTu(BSTree root);
void PreOrder(BSTree root);
void InOrder(BSTree root);
void PosOrder(BSTree root);
BSTree Search(char *maHocVien, BSTree root);
KeyType Delete_Min(BSTree &root);
int Delete_Node(KeyType x, BSTree &root);
#pragma endregion
#pragma region Định nghĩa hàm
BSNode *CreateNode(KeyType x)
{
	BSNode *p = new BSNode;
	if (p != NULL)
	{
		p->key = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}
void CreateBST(BSTree &root)
{
	root = NULL;
}
int InsertNode(BSTree &root, KeyType x)
{
	if (root != NULL)
	{
		if (strcmp(root->key.maHV, x.maHV) == 0)
			return 0;
		if (strcmp(root->key.maHV, x.maHV) > 0)
			return InsertNode(root->left, x);
		else
			return InsertNode(root->right, x);
	}
	root = CreateNode(x);
	if (root == NULL)
		return -1;
	return 1;
}
int ReadFile(BSTree &root, char *filename)
{
	fstream in(filename);
	if (!in)
		return 0;
	KeyType x;
	CreateBST(root);
	int kq;
	while (!in.eof())
	{
		in >> x.maHV;
		in >> x.hoHV;
		in >> x.tenLot;
		in >> x.tenHV;
		in >> x.lop;
		in >> x.namSinh;
		in >> x.dtb;
		in >> x.tichLuy;
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}
void Line()
{
	cout << setfill('=');
	cout << setw(115) << '=' << endl;
	cout << setfill(' ');
}
void Title()
{
	cout << setw(15) << left << "Ma Hoc Vien";
	cout << setw(10) << left << "Ho";
	cout << setw(15) << left << "Ten_lot";
	cout << setw(20) << left << "Ten";
	cout << setw(13) << left << "Lop";
	cout << setw(15) << left << "Nam Sinh";
	cout << setw(13) << left << "Diem TB";
	cout << setw(10) << left << "Tich Luy" << endl;
}
void Xuat1HocVien(KeyType x)
{
	cout << setw(15) << left << x.maHV;
	cout << setw(10) << left << x.hoHV;
	cout << setw(15) << left << x.tenLot;
	cout << setw(20) << left << x.tenHV;
	cout << setw(13) << left << x.lop;
	cout << setw(15) << left << x.namSinh;
	cout << setw(13) << left << setiosflags(ios::fixed) << setprecision(2) << x.dtb;
	cout << setw(10) << left << x.tichLuy << endl;
}
void PreOrder(BSTree root)
{

	if (root != NULL)
	{
		Xuat1HocVien(root->key);
		PreOrder(root->left);
		PreOrder(root->right);
	}

}
void InOrder(BSTree root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		Xuat1HocVien(root->key);
		InOrder(root->right);
	}
}
void PosOrder(BSTree root)
{
	if (root != NULL)
	{
		PosOrder(root->left);
		PosOrder(root->right);
		Xuat1HocVien(root->key);
	}
}
void XuatDanhSachHocVienTheoThuTu(BSTree root)
{
	cout << endl << setw(65) << right << "DANH SACH HOC VIEN " << endl;
	Line();
	Title();
	Line();
	InOrder(root);
	Line();
}
BSTree Search(char *maHocVien, BSTree root)
{
	if (root != NULL)
	{
		if (strcmp(root->key.maHV, maHocVien) == 0)
			return root;
		else
		{
			if (strcmp(root->key.maHV, maHocVien) > 0)
				return Search(maHocVien, root->left);
			else
				return Search(maHocVien, root->right);
		}
	}
	return NULL;
}
HocVien Delete_Min(BSTree &root)
{
	HocVien k;
	if (root->left == NULL)
	{
		k = root->key;
		root = root->right;
		return k;
	}
	else
		return Delete_Min(root->left);
}
int Delete_Node(KeyType x, BSTree &root)
{
	if (root != NULL)
	{
		if (strcmp(x.maHV, root->key.maHV) < 0)
			Delete_Node(x, root->left);
		else
			if (strcmp(x.maHV, root->key.maHV) > 0)
				Delete_Node(x, root->right);
			else
				if ((root->left == NULL) && (root->right == NULL))
					root = NULL;
				else
					if (root->left == NULL)
						root = root->right;
					else
						if (root->right == NULL)
							root - root->left;
						else
							root->key = Delete_Min(root->right);
		return 1;
	}
	return 0;
}

#pragma endregion

