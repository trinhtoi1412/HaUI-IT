#include<bits/stdc++.h>

using namespace std;

unsigned long long f(int n)
{
	if(n < 0)
	{
		return -1;
	}
	else if(n==0||n==1)
		return 1;
	else
		return f(n-1)+f(n-2);
}
int main()
{
	int n;
	cin>>n;
	cout<<"So fibonaci thu "<<n<<" la: "<<f(n)<<endl;
	cout<<"Day so fibonaci cua "<<n<<" so hang la: "<<endl;
	for(int i=0; i<n; i++)
		cout<<f(i)<<" ";
	return 0;
}
