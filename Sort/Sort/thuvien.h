#define MAX 100
void ImportArray(int a[MAX], int &n)
{
	cout << endl << "Xin hay nhap chieu dai cua mang: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % (20 - 0 + 1) - 0;
	}
}
void ExportArray(int a[MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << '\t';
	}
	cout << endl;
}
void SwitchPlace(int &a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}
void SelectionSort(int a[], int n)
{
	cout << endl << "Mang luc dau: " << endl;
	ExportArray(a, n);
	cout << endl << "Thuc hien thuat toan: " << endl;
	int i, j, min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		SwitchPlace(a[min], a[i]);
		ExportArray(a, n);
	}
}
void InsertionSort(int a[], int n)
{
	cout << endl << "Mang luc dau: " << endl;
	ExportArray(a, n);
	cout << endl << "Thuc hien thuat toan: " << endl;
	int pos, i, x;
	for (i = 1; i < n; i++)
	{
		x = a[i];
		pos = i - 1;
		while ((pos >= 0) && (a[pos] > x))
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
		ExportArray(a, n);
	}
}
void InterchangeSort(int a[], int n)
{
	cout << endl << "Mang luc dau: " << endl;
	ExportArray(a, n);
	cout << endl << "Thuc hien thuat toan" << endl;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				SwitchPlace(a[i], a[j]);
			ExportArray(a, n);
		}
	}
}
void BubbleSort(int a[], int n)
{
	cout << endl << "Mang luc dau: " << endl;
	ExportArray(a,n);
	cout << endl << "Bat dau thuat giai: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				SwitchPlace(a[j], a[j - 1]);
			}
			ExportArray(a, n);
		}
	}
}