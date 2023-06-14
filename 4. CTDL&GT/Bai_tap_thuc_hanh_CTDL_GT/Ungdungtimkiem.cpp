#include <iostream>

using namespace std;

void nhap_n(int &n){
	do{
		cout<<"Nhap so sinh vien: ";
		cin>>n;
	}
	while(n < 2);
}
struct HOCSINH{
	char hoten[100];
	char gioitinh[100];
	int namsinh;
	float diem_tk;
};
void nhap(HOCSINH hs[], int n){
	for(int i = 0; i < n; i++){
		cout<<"\tNhap sinh vien thu "<<i + 1<<":"<<endl;
		cout<<"Nhap ho ten: ";
		cin.ignore();
		cin.getline(hs[i].hoten, 99);
		cout<<"Nhap gioi tinh: ";
		cin.ignore();
		cin.getline(hs[i].gioitinh, 99);
		cout<<"Nhap nam sinh: ";
		cin>>hs[i].namsinh;
		cout<<"Nhap diem tong ket: "; cin>>hs[i].diem_tk;
	}
}
void xuat(HOCSINH hs[], int n){
	cout<<"\n=======================================\n";
	for(int i = 0; i < n; i++){
		cout<<"\tSinh vien thu "<<i + 1<<":"<<endl;
		cout<<"Ho ten: "<<hs[i].hoten<<endl;
		cout<<"Gioi tinh: "<<hs[i].gioitinh<<endl;
		cout<<"Nam sinh: "<<hs[i].namsinh<<endl;
		cout<<"Diem tong ket: "<<hs[i].diem_tk<<endl;
	}
}

int Tim_Kiem_Tuan_Tu(HOCSINH hs[], int n, int k)
{
    int i = 0;
    while (i < n && hs[i] != k)
    {
        i++;
    }
    if (i < n)
        return i;
    else
        return -1;
}

int Tim_Kiem_Nhi_Phan(HOCSINH hs[], int left, int right, int k)
{
    if(left > right)
        return -1;
    else
    {
        int mid = (left + right) / 2;
        if (hs[mid] == k) return mid;
        else if (hs[mid] > k)
            return Tim_Kiem_Nhi_Phan(hs, left, mid - 1, k);
        else Tim_Kiem_Nhi_Phan(hs, mid + 1, right, k);
    }
}

int main()
{
    int n;
	nhap_n(n);
	HOCSINH hs[n];
	nhap(hs, n);
	xuat(hs, n);
    return 0;
}
