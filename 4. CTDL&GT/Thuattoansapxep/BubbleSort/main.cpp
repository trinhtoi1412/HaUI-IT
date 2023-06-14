#include <bits/stdc++.h>

using namespace std;

void nhap(int *a, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"a["<<i<<"] = ";
        cin>>a[i];
    }
}

void xuat(int *a, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}

void bubbleSort(int *a, int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=n-1; j>i; j--)
        if(a[j]<a[j-1])
            {
                int tg=a[j];
                a[j]=a[j-1];
                a[j-1]=tg;
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
    bubbleSort(a, n);
    cout<<"\nMang sau khi duoc sap xep (bubble sort): ";
    xuat(a, n);
    return 0;
}

















