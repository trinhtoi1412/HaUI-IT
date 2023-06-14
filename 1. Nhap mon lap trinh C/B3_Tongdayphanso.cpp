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
			printf("\nNhap lai! n phai lon hon hoac bang 1!");
			printf("\n");
		}
	}
	while(n < 1);
	
	while (i <= n)
	{
		//S = S + (1.0 / i);
		//S = S + (1.0 / (2 * i));
		S = S + (1.0 / (2 * i + n));
		i++;
	}
	
	//printf("\nTong 1 + 1/2 + 1/3 + ... + 1/%d la: %f", n, S);
	//printf("\nTong 1/2 + 1/4 + ... + 1/(2 * %d) la: %f", n, S);
	printf("\nTong day so la: %f", S);
	getch();
	return 0;
}
