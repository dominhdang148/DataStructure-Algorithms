#pragma region Định nghĩa cây nhị phân
typedef int  KeyType;
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
void PreOrder(BSTree root);
void InOrder(BSTree root);
void PosOrder(BSTree root);
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
		if (root->key == x)
			return 0;
		else
		{
			if (root->key > x)
				return InsertNode(root->left, x);
			else
				return InsertNode(root->right, x);
		}
	}
	root = CreateNode(x);
	if (root == NULL)
		return -1;
	return 1;
}
int ReadFile(BSTree &root, char *filename)
{
	ifstream in(filename);
	if (!in)
		return 0;
	KeyType x;
	int kq;
	CreateBST(root);
	while (!in.eof())
	{
		in >> x;
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}
void PreOrder(BSTree root)
{
	if (root != NULL)
	{
		cout << root->key << '\t';
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
void InOrder(BSTree root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		cout << root->key << '\t';
		InOrder(root->right);
	}
}
void PosOrder(BSTree root)
{
	if (root != NULL)
	{
		PosOrder(root->left);
		PosOrder(root->right);
		cout << root->key << '\t';
	}
}
#pragma endregion

