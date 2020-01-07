#include <stdio.h>

int fibonacci(int n);

int main()
{
	int numero;

	printf("introduzca el numero de elemntos: ");
	scanf("%i", &numero);

	int i;

	for(i=1; i<= numero; i++)
	{

	printf("%i\t",fibonacci(i));
	}
	return 0;
}

int fibonacci(int n)
{

	if(n==0 || n==1)
	{
		return n;
	}
	else
	{
		return(fibonacci(n-1) + fibonacci(n-2));
	}

}
