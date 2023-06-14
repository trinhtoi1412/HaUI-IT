#include<bits/sdtc++.h>
using namespace std;
struct SV
{
	char msv[30];
	char hoDem[30];
	char ten[30];
	char gioiTinh[30];
	int namSinh;
	float diem;
}
struct Node
{
	SV infor;
	Node *next;
}
typedef Node *TRO;
TRO L;
void khoiTaoDanhSachRong(TRO &L)
{
	L = NULL;
}
int ktDanhSachRong(TRO L)
{
	return L == NULL;
}
void nhap(SV &x)
{
	cout<<"Ma SV:	";	fflush(stdin);	cin.getline(x.msv,30);
	cout<<"Ho dem:	";	fflush(stdin);	cin.getline(x.hoDem,30);
	cout<<"Ten:		";	fflush(stdin);	cin.getline(x.ten,30);
	cout<<"Gioi tinh:";	fflush(stdin);	cin.getline(x.gioiTinh,30);
	cout<<"Nam Sinh: ";	cin>>x.namSinh;
	cout<<"Diem TK: ";	cin>>x.diem;
}
void nhapDS(TRO &L)
{
	khoiTaoDanhSachRong(L);
	SV x;
	TRO P,Q;
	int i =1;
	do{
		cout<<"Nhap SV "<<i<<endl;
		nhap(x);
		if(strcmp(x.msv,"***")==0)
			return;
		P = new Node;
		P->infor = x;
		P->next = NULL;
		if(L == NULL)
			L = P;
		else
			Q->next = P;
		Q = P;
		i++;
	}while(1);
}
void hienThiDanhSachSV(TRO L)
{
	if(L == NULL)
	{
		cout<<"Danh sach rong"<<endl;
		return;
	}
	cout<<setw(5)<<"STT"<<setw(15)
	<<"MSV"<<setw(15)<<"Ho Dem"<<setw(15)
	<<"Ten"<<setw(15)<<"Gioi Tinh"<<setw(15)
	<<"Nam sinh"<<setw(15)<<"Diem TK"<<endl;
	TRO Q = L;
	int i =0;
	while(Q!= NULL)
	{
		SV x = Q->infor;
		cout<<setw (5) <<(1+1);
        cout<<setw(10)<<x. masv:
        cout<<setw (17) <<x. hodem;
        cout<<setw (8) <<x. ten:
        cout<<setw(10) <<X.namsinh;
        cout<<setw (10)<<X.diemtk<<endl;
        Q - Q->next;
	}
}
int Length(TRO L)
{
	int n=0;
    TRO Q - L;
    while (Q !=NULL){
    	Q = Q->next:
    	n++
	}
    return n;
}
void xoaSVDauTien(TRO &L)
{
	if(L != NULL)
	{
		TRO Q = L;
		L = L->next;
		delete Q;
		cout<<"DS sau xoa"<<endl;
		hienThiDanhSachSV(L);
		return;
	}
	cout<<"DS rong"<<endl;
}
TRO Search (TRO L, char *ma){
	TRO Q = L;
	while(Q !=NULL && strcmp(Q->infor.msv,ma)!=0)
		Q = Q->next;
	return Q;	
}
void xoaNutTroBoiConTroT(TRO &L,TRO T)
{
	TRO Q;
	if(T==L)
		L = T->next;
	else
	{
		Q = L;
		while(Q->next != T)
			Q = Q->next;
		Q->next = T->next;
	}
	delete T;
}
// ham xoa sv co ma sv8089
void xoa(TRO &L)
{
	TRO T = Search(l,"sv8089");
	if(T==NULL)
	{
		cout<<"khong co sv thoa man"<<endl;
		return;
	}
	xoaNutTroBoiConTroT(L,T);
	cout<<"DS vua xoa:"<<endl;
	hienThiDanhSachSV(L);
}
//ham bo sung vao dau danh sach
void themDau(TRO &L,SV x)
{
	TRO P;
	P = new Node;
	P->infor = x;
	P->next = L;
	L = P;
}
int main()
{
	
	return 0;
}
