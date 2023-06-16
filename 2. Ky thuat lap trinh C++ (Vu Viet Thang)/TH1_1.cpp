#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	cout<<"Nhap so nguyen a: "; cin>>a;
	cout<<"Nhap so nguyen b: "; cin>>b;
	
	int Tong, Hieu, Tich, Du;
	float Thuong;
	Tong = a + b;
	Hieu = a - b;
	Tich = a * b;
	Thuong = (float) a / b;
	Du = a % b;
	cout<<"-------------------------------"<<endl;
	cout<<"Tong a + b = "<<Tong<<endl;
	cout<<"Hieu a - b = "<<Hieu<<endl;
	cout<<"Tich a * b = "<<Tich<<endl;
	cout<<"Thuong a / b = "<<Thuong<<endl;
	cout<<"So du a / b = "<<Du<<endl;
	return 0;
}
