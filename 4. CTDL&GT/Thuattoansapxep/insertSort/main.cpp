#include <bits/stdc++.h>

using namespace std;

void nhap(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"a["<<i+1<<"] = ";
        cin>>a[i];
    }
}

void xuat(int *a, int n)
{
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
}

void insertSort(int *a, int n)
{
    for (int i=1; i<n; i++)
    {
        int tam=a[i];
        int j=i-1;
        while(j>-1 && a[j]>tam)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=tam;
    }
}

int main()
{
    int n;
    cout<<"Nhap so luong phan tu mang: ";
    cin>>n;
    int *a = new int [n];
    nhap(a, n);
    cout<<"\nMang vua nhap la: ";
    xuat(a, n);
    insertSort(a, n);
    cout<<"\nMang sau khi duoc sap xep (bubble sort): ";
    xuat(a, n);
    return 0;
}
