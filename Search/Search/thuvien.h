#define MAX 100
void NhapMang(int a[MAX], int &n)
{
	cout << endl << "Xin hay nhap chieu dai mang: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%20;
	}
}
void XuatMang(int a[MAX], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << '\t';
		dem++;
		if (dem % 10 == 0)
			cout << endl;
	}
}
int LinearSearchFirstElement(int a[MAX], int n, int x)
{
	int i = 0;
	while ((i < n) && (a[i] != x))
		i++;
	if (i == n)
		return -1;
	return i;
}
int LinearSearchFirstElementWithGuard(int a[MAX], int n, int x)
{
	int i = 0;
	a[n] = x;
	while (a[i] != x)
		i++;
	if (i == n)
		return -1;
	return i;
}
int LinearSearchLastElement(int a[MAX], int n, int x)
{
	int i = n - 1;
	while ((i >= 0) && (a[i] != x))
		i--;
	return i;
}
void LinearSearchAllElement(int a[MAX], int n, int x)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			kq = 1;
			break;
		}	
	}
	if (kq == -1)
		cout << endl << x << " khong co trong mang a";
	else
	{
		cout << endl << x << " xuat hien trong mang tai cac vi tri: ";
		for (int i = 0; i < n; i++)
		{
			if (a[i] == x)
				cout << i << ", ";
		}
	}
}
