#include<stdio.h>
#include<conio.h>

int main()
{
	int i, n;
	long S;
	S = 0;
	i = 1;
	printf("Nhap n: ");
	scanf("%d", &n);
	
	while (i <= n)
	{
		S = S + (i * i);
		i++;
	}
	
	printf("\nTong 1^2 + 2^2 + ... + %d^2 la: %d", n, S);
	getch();
	return 0;
}
