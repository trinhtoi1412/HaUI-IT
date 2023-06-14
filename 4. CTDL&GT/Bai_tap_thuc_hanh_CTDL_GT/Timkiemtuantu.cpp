#include <bits/stdc++.h>

using namespace std;

void nhap(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"Phan tu thu "<<i + 1<<" :"<<endl;
        cin>>a[i];
    }
}

void xuat(int a[], int n)
{
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
}

int Tim_Kiem_Tuan_Tu(int a[], int n, int k)
{
    int i = 0;
    while (i < n && a[i] != k)
    {
        i++;
    }
    if (i < n)
        return i;
    else
        return -1;
}
int main()
{
    int a[1000], n, k;
    cout<<"Nhap so phan tu mang: ";
    cin>>n;
    nhap(a, n);
    cout<<"Mang vua nhap la: ";
    xuat(a, n);
    cout<<endl;
    cout<<"Nhap so can tim: "; cin>>k;
    if(Tim_Kiem_Tuan_Tu(a, n, k) == true)
        cout<<"So "<<k<<" o vi tri thu "<<Tim_kiem(a, n, k);
    else
        cout<<"Ket qua tim kiem khong hop le"<<endl;
}
