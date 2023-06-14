#include <bits/stdc++.h>
using namespace std;
void nhap(int **a, int n)
{
    for (int i=0;i<2;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
}
void sortt(int **a,int n)
{
    for (int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[1][i]/a[0][i]<a[1][j]/a[0][j])
            {
            swap(a[1][i],a[1][j]);
            swap(a[0][i],a[0][j]);
            }
}
void total( int **a, int n, int w)
{
    sortt(a,n);
    for(int j=0; j<2;j++)
        {
        for(int k=0;k<n;k++)
            cout<<a[j][k]<<"   ";
        cout<<endl;
        }

    int i=0,p=0;
    while(w>=a[0][i]){
        w-=a[0][i];
        p+=a[1][i];
        i++;
    }
    if(w==0){
    cout<<"So luong do vat duoc sap xep hoan hao vao trong balo la: "<<i<<endl;
    cout<<"Nhung do vat khong duoc xep vao balo la: "<<endl;
    for(int j=0; j<2;j++)
        {
        for(int k=i;k<n;k++)
            cout<<a[j][k]<<"   ";
        cout<<endl;
        }
    cout<<"Gia tri lon nhat dat duoc la: "<<p<<endl;
    }
    else{
    cout<<"So luong do vat duoc sap xep hoan hao vao trong balo la: "<<i<<endl;
    cout<<"Do vat thu "<<i+1<<" xep duoc "<<setprecision(3)<<(float)w/a[0][i]<<" phan do vat vao ba lo"<<endl;
    p+=a[1][i];
    cout<<"Nhung do vat khong duoc xep vao balo la: "<<endl;
    for(int j=0; j<2;j++)
        {
        for(int k=i+1;k<n;k++)
            cout<<a[j][k]<<"   ";
        cout<<endl;
        }
    cout<<"Gia tri lon nhat dat duoc la: "<<p<<endl;
    }
}

int main()
{
    int **a,n,w;
    cout<<"Nhap so luong do vat: ";
    cin>>n;
    a = (int **)malloc(2 * sizeof(int *));
    for (int i = 0; i < 2; i++)
        a[i] = (int *)malloc(n * sizeof(int));
    nhap(a,n);
    cout<<"Nhap W=";
    cin>>w;
    total(a,n,w);
    return 0;
}
