int ReadFile(char *filename, BSTree &root)
{
	ifstream in(filename);
	if (!in)
		return 0;
	KeyType x;
	Create_Empty_Tree(root);
	int kq;
	while (!in.eof())
	{
		in >> x.maNV;
		in >> x.hoNV;
		in >> x.tenLot;
		in >> x.tenNV;
		in >> x.namSinh;
		in >> x.luong;
		kq = Insert_Node(x, root);
		if (kq != 1)
			return 0;
	}
	in.close();
}
void Xuat_NV_LNR(BSTree root)
{
	cout << setw(50) << right << "DANH SACH NHAN VIEN" << endl;
	Line();
	Title();
	Line();
	InOrder(root);
	Line();
}
int DemSoNut(BSTree root)
{
	if (root == NULL)
		return 0;
	return 1 + DemSoNut(root->left) + DemSoNut(root->right);
}
BSTree Search(char *ma, BSTree root)
{
	if (root != NULL)
	{
		if (strcmp(root->info.maNV, ma) == 0)
			return root;
		else
		{
			if (strcmp(root->info.maNV, ma) > 0)
				return Search(ma, root->left);
			else
				return Search(ma, root->right);
		}
	}
	return NULL;
}
int SuaThongTinNamSinh(char *ma, int year, BSTree &root)
{
	BSTree obj = Search(ma, root);
	if (obj == NULL)
		return 0;
	else
	{
		obj->info.namSinh = year;
		return 1;
	}
}