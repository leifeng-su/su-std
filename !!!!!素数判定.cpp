#include<cstdio>

long long mod_mul(long long a, long long b, long long n)
{
	long long res=0;
	for (;b;b>>=1)
	{
		if(b&1)	res=(res+a)%n;
		a=(a+a)%n;
	}
	return res;
}

long long power(long long a,long long b,long long c)
{
	if (b==0)	return 1;
	long long x=power(a,b>>1,c)%c;
	return ((mod_mul(x,x,c))%c*(((b&1)==1?a:1)%c))%c;
}

long long r,d;
void if_prime_test_deal(long long n)
{for (r=0;(n&1)==0;r++)	n=n>>1;d=n;}

bool if_prime_test(long long a,long long n)
{
	if (n==a)	return true;
	if (n%a==0)	return false;
	long long x=power(a,d,n);
	bool ans=(x%n==1||x%n==n-1);
	for (int i=1;i<=r;i++)
	{
		x=mod_mul(x,x,n)%n;
		if (x!=1&&x!=n-1)	ans=false;
		if (x==n-1)	ans=true;
	}
	return ans;
}

bool if_prime(long long n)
{
	if (n==2)	return true;
	if (n==1)	return false;
	if ((n&1)==0)	return false;
	if_prime_test_deal(n-1);

	if (!if_prime_test(2,n))	return false;
	if (!if_prime_test(3,n))	return false;
	if (!if_prime_test(5,n))	return false;
	if (!if_prime_test(7,n))	return false;
	if (!if_prime_test(11,n))	return false;
	if (!if_prime_test(13,n))	return false;
	if (!if_prime_test(17,n))	return false;
	return	true;
}


int main()
{
	if_prime(3);
	for (int i=1;i<=1000;i++)
	{
		if (if_prime(i))	printf ("%d\n",i);
	}
	for (;;);
}