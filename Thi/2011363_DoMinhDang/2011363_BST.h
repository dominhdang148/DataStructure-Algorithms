struct NhanVien
{
	char maNV[10];
	char hoNV[10];
	char tenLot[10];
	char tenNV[10];
	int namSinh;
	double luong;
};
typedef NhanVien KeyType;
struct  BSNode
{
	KeyType info;
	BSNode *left;
	BSNode *right;
};
typedef BSNode *BSTree;
BSNode *Create_Node(KeyType x)
{
	BSNode *p = new BSNode;
	if (p != NULL)
	{
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}
void Create_Empty_Tree(BSTree &root)
{
	root = NULL;
}
int Insert_Node(KeyType x, BSTree &root)
{
	if (root != NULL)
	{
		if (strcmp(root->info.maNV, x.maNV) == 0)
			return 0;
		else
			if (strcmp(root->info.maNV, x.maNV) > 0)
				return Insert_Node(x, root->left);
			else
				return Insert_Node(x, root->right);
	}
	else
	{
		root = Create_Node(x);
		if (root == NULL)
			return -1;
		return 1;
	}
}
void Line()
{
	cout << setfill('=');
	cout << setw(90) << "=" << endl;
	cout << setfill(' ');
}
void Title()
{
	cout << setw(15) << left << "Ma NV";
	cout << setw(13) << left << "Ho";
	cout << setw(15) << left << "Ten_Lot";
	cout << setw(20) << left << "Ten";
	cout << setw(15) << left << "Nam_Sinh";
	cout << setw(15) << left << "Luong" << endl;
}
void XuatMotNhanVien(NhanVien x)
{
	cout << setw(15) << left << x.maNV;
	cout << setw(13) << left << x.hoNV;
	cout << setw(15) << left << x.tenLot;
	cout << setw(20) << left << x.tenNV;
	cout << setw(15) << left << x.namSinh;
	cout << setw(15) << left << setiosflags(ios::fixed) << setprecision(0) << x.luong << endl;
}
void InOrder(BSTree root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		XuatMotNhanVien(root->info);
		InOrder(root->right);
	}
}
