#include <bits/stdc++.h>

using namespace std;

int power(int a, int n)
{
    if (n == 1) return a;
    else
    {
        int x = pow(a, n / 2);
        if (n % 2 == 0)
            return x * x;
        else return x * x * a;
    }
}

int main()
{
    int a, n;
    cout<<"Nhap a, n: ";
    cin>>a>>n;
    cout<<"a^n = "<<power(a, n);
    return 0;
}
