#include<stdio.h>
 
using namespace std;
 
long int func(long int n)
{	
	if(n == 2)
		return 2;
	else if(n == 1)
		return 1;
	else if (n == 0)
		return 0;
	else
	{
		long int m = func(n / 2) + func(n / 3) + func(n / 4);
		if((n / m) != 0)
			return n;
		else 
			return m;
	}
}
 
int main()
{
	unsigned long int n;
	
	for (int i = 0; i < 10; ++i)
		if(scanf("%ld",&n)>0)
			printf("%ld \n", func(n));
			
	return 0;
} 