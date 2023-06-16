#include<stdio.h>
#include<conio.h>

int main()
{
	int i, n;
	float S;
	S = 0;
	i = 1;
	do
	{
		printf("Nhap n: ");
		scanf("%d", &n);
		if(n < 1)
		{
			printf("Nhap lai! n phai lon hon hoac bang 1");
			printf("\n");
		}
	}
	while(n < 1);
	
	while(i <= n)
	{
		S = S + (1.0 / (i * (i + 1)));
		i++;
	}
	printf("\nTong S = %f", S);
	getch();
	return 0;
}
