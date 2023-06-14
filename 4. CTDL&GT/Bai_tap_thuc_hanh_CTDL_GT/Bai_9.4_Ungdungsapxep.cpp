#include <bits/stdc++.h>

using namespace std;

struct SinhVien
{
    char hoTen[50];
    char gioiTinh[20];
    int namSinh;
    float diemTK;
};

void nhap(SinhVien *sv, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"Nhap thong tin sinh vien thu "<<i+1<<" la: "<<endl;
        cout<<"\tHo ten: "; fflush(stdin); gets(sv[i].hoTen);
        cout<<"\tGioi tinh: "; fflush(stdin); gets(sv[i].gioiTinh);
        cout<<"\tNam sinh: "; cin>>sv[i].namSinh;
        cout<<"\tDiem tong ket: "; cin>>sv[i].diemTK;
    }
}

void xuat(SinhVien *sv, int n)
{
    for(int i = 0; i < n; i++)
        cout<<right<<sv[i].hoTen<<right<<setw(15)<<sv[i].gioiTinh<<right<<setw(15)<<sv[i].namSinh<<right<<setw(25)<<sv[i].diemTK<<endl;
}

//Sap xep noi bot
void bubbleSort(SinhVien *sv, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (strcmp(sv[j].hoTen, sv[j - 1].hoTen) < 0)
            {
                SinhVien tg = sv[j];
                sv[j] = sv[j - 1];
                sv[j - 1] = tg;
            }
}

//Sap xep lua chon
void selectionSort(SinhVien *sv, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
            if (sv[j].namSinh < sv[m].namSinh)
                m = j;
        SinhVien tg = sv[m]; sv[m] = sv[i];
        sv[i] = tg;
    }
}

//Sap xep chen
void insertionSort(SinhVien *sv, int n)
{
    for (int i = 1; i < n; i++)
    {
        SinhVien tam = sv[i]; int j = i-1;
        while (j > -1 && sv[j].diemTK < tam.diemTK)
        {
            sv[j + 1] = sv[j];
            j--;
        }
        sv[j + 1] = tam;
    }
}
int main()
{
    int n;
    cout<<"Nhap so luong sinh vien: ";
    cin>>n;
    SinhVien *sv = new SinhVien [n];
    nhap(sv, n);
    cout<<"\t\tTHONG TIN SINH VIEN"<<endl;
    cout<<right<<"Ho ten"<<right<<setw(15)<<"Gioi tinh"<<right<<setw(15)<<"Nam sinh"<<right<<setw(25)<<"Diem tong ket"<<endl;
    xuat(sv, n);
    ////////////
    bubbleSort(sv, n);
    cout<<"\tSap xep noi bot theo ten: "<<endl;
    xuat(sv, n);
    cout<<"-------------------------------------------"<<endl;
    selectionSort(sv, n);
    cout<<"\tSap xep lua chon theo tuoi: "<<endl;
    xuat(sv, n);
    cout<<"-------------------------------------------"<<endl;
    insertionSort(sv, n);
    cout<<"\tSap xep chen theo diem tong ket: "<<endl;
    xuat(sv, n);
    return 0;
}
