#include<bits/stdc++.h>

using namespace std;

int f(int x)
{
	if(x < 10) return 1;
	else return 1 + f(x / 10);
}

int main(){
	int x;
	cout<<"Nhap x = ";
	cin>>x;
	cout<<"So chu so cua "<<x<<" la: "<<f(x)<<endl;
	return 0;
}
