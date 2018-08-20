#include<cstdio>


long long power(long long a,long long b,long long c)
{
	if (b==0)	return 1;
	long long x=power(a,b>>1,c)%c;
	return ((x*x)%c*(((b&1)==1?a:1)%c))%c;
}

int main()
{
	printf ("%lld",power(2,10,9));
	
}
