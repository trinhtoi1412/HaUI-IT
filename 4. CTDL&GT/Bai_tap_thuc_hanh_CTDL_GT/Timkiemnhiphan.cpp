#include <iostream>

using namespace std;

void nhap(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"Phan tu thu "<<i+1<<" :";
        cin>>a[i];
    }
}

void xuat(int a[], int n)
{
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
}

int Tim_Kiem_Nhi_Phan(int a[], int left, int right, int k)
{
    if(left > right)
        return -1;
    else
    {
        int mid = (left + right) / 2;
        if (a[mid] == k) return mid;
        else if (a[mid] > k)
            return Tim_Kiem_Nhi_Phan(a, left, mid - 1, k);
        else Tim_Kiem_Nhi_Phan(a, mid + 1, right, k);
    }
}

int main()
{
    int a[1000], n, k, left, right;
    cout<<"Nhap so phan tu mang: ";
    cin>>n;
    nhap(a, n);
    cout<<"Mang vua nhap la: ";
    xuat(a, n);
    cout<<endl;
    cout<<"Nhap so can tim: "; cin>>k;
    if(Tim_Kiem_Nhi_Phan(a, left, right, k) == true)
        cout<<"So "<<k<<" o vi tri thu "<<Tim_Kiem_Nhi_Phan(a, left, right, k);
    else
        cout<<"Ket qua tim kiem khong hop le"<<endl;
    return 0;
}
