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
		S = S + i;
		i++;
	}
	printf("\nTong 1+2+3+...+%d la: %ld", n, S);
	getch();
	return 0;
}
