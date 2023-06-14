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

void selectionSort(int *a, int n)
{
    for(int i=0; i<n; i++)
    {
        int m=i;
        for(int j=i+1; j<n; j++)
            if(a[j]<a[m])
                m=j;
        int tg= a[m];
        a[m]=a[i];
        a[i]=tg;
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
    selectionSort(a, n);
    cout<<"\nMang sau khi duoc sap xep (bubble sort): ";
    xuat(a, n);
    return 0;
}
