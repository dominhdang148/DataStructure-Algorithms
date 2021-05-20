#define MAX 100
struct SinhVien
{
	char maSV[10];
	char ho[10];
	char tenLot[10];
	char ten[10];
	char lop[10];
	int namSinh;
	double dtb;
	int tichLuy;
};
typedef SinhVien Data;
struct tagNode
{
	Data info;
	tagNode *pNext;
};
typedef tagNode NODE;
struct List
{
	NODE *pHead;
	NODE *pTail;
};
///////////////////////////////////////////////
NODE *GetNode(Data x)
{
	NODE *p;
	p = new NODE;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}
void CreateList(List &l)
{
	l.pHead = l.pTail = NULL;
}
int KT_Rong(List l)
{
	if (l.pHead == NULL)
		return 1;
	return 0;
}
void Add_Tail(List &l, NODE *new_ele)
{
	if (KT_Rong(l))
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}
void Insert_Tail(List &l, Data x)
{
	NODE *new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << endl << "Loi cap phat bo nho, khong the thuc hien chuc nang nay";
		return;
	}
	Add_Tail(l, new_ele);
}
int Read_File(char *f, List &l)
{
	ifstream in(f);
	if (!in)
		return 0;
	CreateList(l);
	Data x;
	in >> x.maSV;
	in >> x.ho;
	in >> x.tenLot;
	in >> x.ten;
	in >> x.lop;
	in >> x.namSinh;
	in >> x.dtb;
	in >> x.tichLuy;
	Insert_Tail(l, x);
	while (!in.eof())
	{
		in >> x.maSV;
		in >> x.ho;
		in >> x.tenLot;
		in >> x.ten;
		in >> x.lop;
		in >> x.namSinh;
		in >> x.dtb;
		in >> x.tichLuy;
		Insert_Tail(l, x);
	}
	in.close();
	return 1;
}
void XuatKeNgangDoi()
{
	cout << setfill('=');
	cout << setw(115) << "=" << endl;
	cout << setfill(' ');
}
void XuatKeNgangDon()
{
	cout << setfill('-');
	cout << setw(115) << "-" << endl;
	cout << setfill(' ');
}
void XuatTieuDe()
{
	cout << setw(10) << left << "MSSV";
	cout << setw(10) << left << "Ho";
	cout << setw(15) << left << "Ten Lot";
	cout << setw(20) << left << "Ten";
	cout << setw(13) << left << "Lop";
	cout << setw(20) << left << "Nam sinh";
	cout << setw(15) << left << "Diem TB";
	cout << setw(10) << left << "Tich luy" << endl;
}
void XuatSinhVien(Data p)
{
	cout << setw(10) << left << p.maSV;
	cout << setw(10) << left << p.ho;
	cout << setw(15) << left << p.tenLot;
	cout << setw(20) << left << p.ten;
	cout << setw(13) << left << p.lop;
	cout << setw(20) << left << p.namSinh;
	cout << setw(15) << left << setiosflags(ios::fixed) << setprecision(2) << p.dtb;
	cout << setw(10) << left << p.tichLuy << endl;
}
void XuatDSSinhVien(List l)
{
	if (KT_Rong(l))
	{
		cout << endl << "Danh sach rong!";
		return;
	}
	cout << endl << setw(65) << right << "DANH SACH SINH VIEN" << endl;
	XuatKeNgangDoi();
	XuatTieuDe();
	XuatKeNgangDoi();
	NODE *p = l.pHead;
	int count = 0;
	while (p != NULL)
	{
		XuatSinhVien(p->info);
		count++;
		if (count % 5 == 0)
			XuatKeNgangDon();
		p = p->pNext;
	}
	XuatKeNgangDoi();
}