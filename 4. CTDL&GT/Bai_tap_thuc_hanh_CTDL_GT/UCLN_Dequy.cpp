#include<bits/stdc++.h>

using namespace std;

//Giai thuat de quy
int UCLN(int p, int q){
    int r = p % q;
    if(r == 0) return q;
    else return UCLN(q, r);
}

//Giai thuat lap
/*
int UCLN(int p, int q)
{
    int r = p % q;
    while(r != 0)
    {
        p = q; q = r;
        r = p % q;
    }
    return q;
}
*/

int main(){
    int p, q;
    cout<<"nhap p, q: ";
    cin>>p>>q;
    cout<<"Uoc so chung lon nhat: "<<UCLN(p, q);
    return 0;
}
