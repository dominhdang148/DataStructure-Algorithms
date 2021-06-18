#pragma region Khai báo nguyên mẫu hàm
int DemSoNut(BSTree root);
int DemSoNutNhoHon(BSTree root, KeyType x);
BSTree Search(KeyType x, BSTree root);
int IsLeaf_X(BSTree root, KeyType x);
int Count_Leaf(BSTree root);
int TinhMax(int a, int b);
int TinhChieuCao(BSTree root);
int TimLevel_X(BSTree root, KeyType x);
int SoSanh_Level(BSTree root, KeyType x, KeyType y);
KeyType Delete_Min(BSTree &root);
int DeleteNode(KeyType x, BSTree &root);
#pragma endregion
#pragma region Định nghĩa hàm
int DemSoNut(BSTree root)
{
	if (root == NULL)
		return 0;
	return 1 + DemSoNut(root->left) + DemSoNut(root->right);
}
int DemSoNutNhoHon(BSTree root, KeyType x)
{
	int soNut;
	if (root == 0)
		soNut = 0;
	else
	{
		if (root->key < x)
		{
			cout << root->key << '\t';
			soNut = DemSoNutNhoHon(root->left, x) + DemSoNutNhoHon(root->right, x) + 1;
		}
		else
		{
			soNut = DemSoNutNhoHon(root->left, x) + DemSoNutNhoHon(root->right, x);
		}
	}
	return soNut;
}
BSTree Search(KeyType x, BSTree root)
{
	if (root != NULL)
	{
		if (root->key == x)
			return root;
		else
		{
			if (root->key > x)
				return Search(x, root->left);
			else
				return Search(x, root->right);
		}
	}
	return NULL;
}
int IsLeaf_X(BSTree root, KeyType x)
{
	int kq = 0;
	BSTree test = Search(x, root);
	if (test == NULL)
		kq = -1;
	else
		kq = (test->left == NULL) && (test->right == NULL);
	return kq;
}
int Count_Leaf(BSTree root)
{
	int count;
	if (root == NULL)
		count = 0;
	else
	{
		if ((root->left == NULL) && (root->right == NULL))
		{
			cout << root->key << '\t';
			count = 1;
		}
		else
			count = Count_Leaf(root->left) + Count_Leaf(root->right);
	}
	return count;
}
int TinhMax(int a, int b)
{
	if (a >= b)
		return a;
	return b;
}
int TinhChieuCao(BSTree root)
{
	int h;
	if (root == NULL)
		h = -1;
	else
	{
		if (root->left == NULL&&root->right == NULL)
			h = 0;
		else
			h = 1 + TinhMax(TinhChieuCao(root->left), TinhChieuCao(root->right));
	}
	return h;
}
int TimLevel_X(BSTree root, KeyType x)
{
	int level = 0;
	BSTree T = root;
	while (T != NULL)
	{
		if (T->key == x)
			break;
		else
		{
			level++;
			if (T->key > x)
				T = T->left;
			else
				T = T->right;
		}
	}
	return level;
}
int SoSanh_Level(BSTree root, KeyType x, KeyType y)
{
	int kq1, kq2;
	kq1 = TimLevel_X(root, x);
	kq2 = TimLevel_X(root, y);
	if (kq1 > kq2)
		return 1;
	else
		if (kq1 < kq2)
			return -1;
		else
			return 0;
}
KeyType Delete_Min(BSTree &root)
{
	KeyType k;
	if (root->left == NULL)
	{
		k = root->key;
		root = root->right;
		return k;
	}
	else
		return Delete_Min(root->left);
}
int DeleteNode(KeyType x, BSTree &root)
{
	if (root != NULL)
	{
		if (x < root->key)
			DeleteNode(x, root->left);
		else
			if (x > root->key)
				DeleteNode(x, root->right);
			else
				if ((root->left == NULL) && (root->right == NULL))
					root = NULL;
				else
					if (root->left == NULL)
						root = root->right;
					else
						if (root->right == NULL)
							root = root->left;
						else
							root->key = Delete_Min(root->right);
		return 1;
	}
	return 0;
}
#pragma endregion


