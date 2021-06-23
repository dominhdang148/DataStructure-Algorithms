#pragma region Một số lưu ý (PHẢI ĐỌC)
//Bài này tui code theo cách nhập điều kiện từ bàn phím (VD mng muốn tìm lớp CTK44 thì phải nhập CTK44 vô).
//Tui biết thầy yêu cầu phải thực hiện trực tiếp (không nhập điều kiện từ bàn phím) nhưng đây là 1 bài tập để ôn
//và tui cần phải kiểm tra xem hàm có chạy đúng với mọi trường hợp hay không.
//Mọi người có thể sửa lại để chương trình chạy trực tiếp cũng được. 
//Cảm ơn mọi người nhe (～o￣3￣)～
#pragma endregion
int SuaDiemTichLuyCuaHocVien(char *maHocVien, int dTL, BSTree &root)
{
	BSTree p = Search(maHocVien, root);
	if (p == NULL)
		return 0;
	else
	{
		p->key.tichLuy = dTL;
		return 1;
	}
}
int XoaHocVien(char *maHocVien, BSTree &root)
{
	BSTree p = Search(maHocVien, root);
	if (p == NULL)
		return 0;
	else
		return Delete_Node(p->key, root);
}
void TrichDanhSachLop(char *lop,BSTree root)
{
	if (root != NULL)
	{
		TrichDanhSachLop(lop, root->left);
		if (strcmp(lop, root->key.lop) == 0)
			Xuat1HocVien(root->key);
		TrichDanhSachLop(lop, root->right);
	}
}
void XuatDanhSachLop(char *lop, BSTree root)
{
	Line();
	Title();
	Line();
	TrichDanhSachLop(lop, root);
	Line();
}