#include<bits/stdc++.h>
using namespace std;

class SINHVIEN
{
	char MASV[30];
	char HOTEN[50];
	int TUOI;
	float DIEM;
	public:
		void NHAP();
		void XUAT();
};

void SINHVIEN::NHAP()
{
	cout<<"Nhap ma SV: "; fflush(stdin); cin.getline(MASV, 30);
	cout<<"Nhap ho ten SV: "; fflush(stdin); cin.getline(HOTEN, 50);
	cout<<"Nhap tuoi: "; cin>>TUOI;
	cout<<"Nhap diem: "; cin>>DIEM;
}

void SINHVIEN::XUAT()
{
	cout<<"Ma SV: "<<MASV<<endl;
	cout<<"Ten SV: "<<HOTEN<<endl;
	cout<<"Tuoi: "<<TUOI<<endl;
	cout<<"Diem: "<<DIEM<<endl;
}

int main()
{
	SINHVIEN a, b;
	cout<<"Nhap thong tin sinh vien a: "<<endl;
	a.NHAP();
	cout<<"Nhap thong tin sinh vien b: "<<endl;
	b.NHAP();
	cout<<"---------------------------"<<endl;
	cout<<"Sinh vien a: "<<endl;
	a.XUAT();
	cout<<"---------------------------"<<endl;
	cout<<"Sinh vien b: "<<endl;
	b.XUAT();
	return 0;
}

