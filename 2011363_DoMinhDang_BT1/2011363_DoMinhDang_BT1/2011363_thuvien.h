#define MAX 100
struct SinhVien
{
	char maSV[8];
	char hoSV[10];
	char tenLot[10];
	char ten[10];
	char lop[6];
	int namSinh;
	double dtb;
	int tichLuy;
};
int TapTin_MangCT(char *filename, SinhVien a[MAX], int &n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	n = 0;
	while (!in.eof())
	{
		in >> a[n].maSV;
		in >> a[n].hoSV;
		in >> a[n].tenLot;
		in >> a[n].ten;
		in >> a[n].lop;
		in >> a[n].namSinh;
		in >> a[n].dtb;
		in >> a[n].tichLuy;
		n++;
	}
	in.close();
	return 1;
}
void TieuDe()
{
	int i;
	cout << endl;
	cout << ":";
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << endl;
	cout << setiosflags(ios::left);
	cout << ':';
	cout << setw(9) << "Ma SV"
		<< ':'
		<< setw(30) << "Ho va Ten sinh vien"
		<< ':'
		<< setw(10) << "Lop"
		<< ':'
		<< setw(6) << "NS"
		<< ':'
		<< setw(6) << "DTB"
		<< ':'
		<< setw(8) << "Tich luy"
		<< ':';
	cout << endl;
	cout << 'i';
	for (i = 1; i <= 74; i++)
	{
		cout << '=';
	}
	cout << ':';
	cout << endl;
}
void XuatSinhVien(SinhVien p)
{
	cout << ':';
	cout << setiosflags(ios::left)
		<< setw(9) << p.maSV
		<< ':'
		<< setw(10) << p.hoSV
		<< setw(10) << p.tenLot
		<< setw(10) << p.ten
		<< ':'
		<< setw(10) << p.lop
		<< ':'
		<< setw(6) << p.namSinh
		<< ':'
		<< setw(6) << setiosflags(ios::fixed) << setprecision(2) << p.dtb
		<< ':'
		<< setw(8) << p.tichLuy
		<< ':';
}
void XuatDanhSachSinhVien(SinhVien a[MAX], int n)
{
	TieuDe();
	for (int i = 0; i < n; i++)
	{
		XuatSinhVien(a[i]);
		cout << endl;
	}
	cout << ':';
	for (int i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << endl;
}
void TimTheoTen(SinhVien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
	{
		if (_stricmp(a[i].ten, "Hoa") == 0)
		{
			kq = 1;
			break;
		}
	}
	cout << "Thong tin sinh vien trong danh sach co ten Hoa ";
	cout << endl;
	TieuDe();
	for (i = 0; i < n; i++)
	{
		if (_stricmp(a[i].ten, "Hoa") == 0)
		{
			cout << endl;
			XuatSinhVien(a[i]);
		}
	}
}
void TimTheoLopVaTinChi(SinhVien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
	{
		if ((_stricmp(a[i].lop, "CTK37") == 0) && (a[i].tichLuy > 41))
		{
			kq = 1;
			break;
		}
	}

	cout << "Thong tin sinh vien trong danh sach thuoc lop CTK37 co so tin chi tich luy tren 41:";
	cout << endl;
	TieuDe();
	for (i = 0; i < n; i++)
	{
		if ((_stricmp(a[i].lop, "CTK37") == 0) && (a[i].tichLuy > 41))
		{
			cout << endl;
			XuatSinhVien(a[i]);
		}
	}
}
void TimTheoNamSinhVaDiemTrungBinh(SinhVien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
	{
		if ((a[i].namSinh>1993) && (a[i].dtb< 6.2))
		{
			kq = 1;
			break;
		}
	}

	cout << "Thong tin sinh vien trong danh sach sinh sau nam 1993 va co diem trung binh <= 6.2:";
	cout << endl;
	TieuDe();
	for (i = 0; i < n; i++)
	{
		if ((a[i].namSinh>1993) && (a[i].dtb <= 6.2))
		{
			cout << endl;
			XuatSinhVien(a[i]);
		}
	}
}
