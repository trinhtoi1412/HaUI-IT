#include<stdio.h>
#include<conio.h>

int main()
{
	int i, n;
	float S;
	S = 0;
	i = 1;
	printf("Nhap n: "); scanf("%d", &n);
	while(i <= n)
	{
		S = S + (float)i / (i + 1);
		i++;
	}
	printf("\nTong S = %f", S);
	getch();
	return 0;
}
