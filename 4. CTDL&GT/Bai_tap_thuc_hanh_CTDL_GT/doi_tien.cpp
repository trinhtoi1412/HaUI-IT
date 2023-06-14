#include <bits/stdc++.h>
using namespace std;
void total(int s)
{
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0;
    int p=0;
    while(p<=s)
    {
        p+=500;
        a++;
    }
    if(p>s){
        p-=500;
        a--;
    }
    cout<<"So to tien 500 la: "<<a<<endl;
    while(p<=s)
    {
        p+=200;
        b+=1;
    }
    if(p>s){
        p-=200;
        b--;
    }
    cout<<"So to tien 200 la: "<<b<<endl;
    while(p<=s)
    {
        p+=100;
        c++;
    }
    if(p>s){
        p-=100;
        c--;
    }
    cout<<"So to tien 100 la: "<<c<<endl;
    while(p<=s)
    {
        p+=50;
        d++;
    }
    if(p>s){
        p-=50;
        d--;
    }
    cout<<"So to tien 50 la: "<<d<<endl;
    while(p<=s)
    {
        p+=20;
        e++;
    }
    if(p>s){
        p-=20;
        e--;
    }
    cout<<"So to tien 20 la: "<<e<<endl;
    while(p<=s)
    {
        p+=10;
        f++;
    }
    if(p>s){
        p-=10;
        f--;
    }
    cout<<"So to tien 10 la: "<<f<<endl;
    while(p<=s)
    {
        p+=5;
        g++;
    }
    if(p>s){
        p-=5;
        g--;
    }
    cout<<"So to tien 5 la: "<<g<<endl;
    while(p<=s)
    {
        p+=2;
        h++;
    }
    if(p>s){
        p-=2;
        h--;
    }
    cout<<"So to tien 2 la: "<<h<<endl;
    while(p<=s)
    {
        p+=1;
        i++;
    }
    if(p>s){
        p-=1;
        i--;
    }
    cout<<"So to tien 1 la: "<<i<<endl;
    cout<<"So to tien it nhat la: "<<a+b+c+d+e+f+g+h+i<<endl;
}
int main()
{
    int n;
    cout<<"Nhap so tien can doi ";
    cin>>n;
    total(n);
    return 0;
}
