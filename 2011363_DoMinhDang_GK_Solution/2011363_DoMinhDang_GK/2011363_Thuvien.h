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
	cout << setw(10) << left << "MSHV";
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
	cout << endl << setw(65) << right << "DANH SACH HOC VIEN" << endl;
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
void SuaTinChiTichLuyCuaHocVien(char *maHocVien, List &l)
{
	int tctl;
	int kq = -1;
	NODE*p = l.pHead;
	for (int i = 0; p != NULL; p = p->pNext, i++)
	{
		if (strcmp(maHocVien, p->info.maSV) == 0)
		{
			kq = i;
			break;
		}
	}
	if (kq<0)
	{
		cout << endl << "Khong tim thay hoc vien nao co ma hoc vien: " << maHocVien << " trong danh sach";
		return;
	}
	else
	{
		cout << endl << "Xin hay nhap tin chi tich luy can sua: ";
		cin >> tctl;

		for (p = l.pHead; p != NULL; p = p->pNext)
		{
			if (strcmp(maHocVien, p->info.maSV) == 0)
				p->info.tichLuy = tctl;
		}
		return;
	}
}
void XuatDanhSachHVCuaLop(char *lop, List l)
{
	List Llop;
	CreateList(Llop);
	NODE *p;
	for (p = l.pHead; p != NULL; p = p->pNext)
	{
		if (strcmp(lop, p->info.lop) == 0)
			Insert_Tail(Llop, p->info);
	}
	cout << endl << "Danh sach hoc vien cua lop " << lop << " la: ";
	XuatDSSinhVien(Llop);
}
int Remove_First(List &l, int nam)
{
	NODE *p;
	NODE*q = NULL;
	for (p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->info.namSinh == nam)
			break;
		q = p;
	}
	if (p == NULL)
		return 0;
	if (q != NULL)
	{
		if (p == l.pTail)
			l.pTail = q;
		q->pNext = p->pNext;
	}
	if (q == NULL)
	{
		l.pHead = p->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;
	}
	delete p;
	return 1;
}
void XoaHocVienCoNamSinh(List &l, int nam)
{
	while (Remove_First(l, nam));
}