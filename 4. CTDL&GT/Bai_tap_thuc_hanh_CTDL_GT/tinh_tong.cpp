#include <bits/stdc++.h>
using namespace std;
void Less(int *a, int n)
{
    for (int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
        	if(a[i]<a[j])
                swap(a[i],a[j]);
        }
}
int total(int *a, int n, int s)
{
    Less(a,n);
    int i=0,p=0;
    while(i<n&&p<=s){
        p+=a[i];
        i++;
    }
    if(p>s)return i;
    else return -1;
}
void nhap(int *a,int n)
{
    for (int i=0;i<n;i++){
        cout<<"a["<<i<<"]=";
        cin>>a[i];
    }
}
int main()
{
    int *a,n,s;
    cout<<"Nhap so phan tu trong day: ";
    cin>>n;
    a=new int[n];
    nhap(a,n);

    cout<<"Nhap S=";
    cin>>s;
    if(total(a,n,s)==-1)
        cout<<"Mang khong thoa man tong nho hon S"<<endl;
    else
        cout<<"Can it nhat "<<total(a,n,s)<<" gia tri de tong nho hon S"<<endl;
    return 1;
}
