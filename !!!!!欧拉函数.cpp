#include<cstdio>



int a[10000020];
int vis[10000020];
void sslist(int *a,int n)////////////线性制素数表 
{
	int na=0;
	for (int i=2;i<=n;i++)
	{
		if (!vis[i])	a[++na]=i;
		for (int j=1;j<=na;j++)
		{
			if (i*a[j]>n)	break;
			vis[i*a[j]]=1;
			if (i%a[j]==0)	break;
		}
	}
}

long long Euler_work(long long n)/////单点查询 
{
	long long res=n;
	for (int k=1;a[k]*a[k]<=n;k++)
	{
		if (n%a[k]==0)
		{
			res=res/a[k]*(a[k]-1);
			for (;n%a[k]==0;)	n=n/a[k];
		}
	}
	if (n>1)	res=res/n*(n-1);
	return res;
}

int euler[1000020];
void Euler_list(int n)/////制函数表
{
	for (int i=2;i<=n;i++)
	{
		if (vis[i]==0)	euler[i]=i-1;
		for (int j=1;a[j]<=i;j++)
		{
			if (a[j]*i>n)	break;
			if (i%a[j]==0){euler[i*a[j]]=euler[i]*a[j];break;}
				else	euler[i*a[j]]=euler[i]*(a[j]-1);
		}
	}
}

long long ans[1000020];
void deal(int n){for (int i=1;i<=n;i++)	ans[i]=ans[i-1]+euler[i];}

/*
long long x;
int main()
{
//	freopen("test.txt","r",stdin);
	sslist(a,1000000);
	for (;scanf ("%lld",&x)!=EOF;)
	{
		if (x==0)	return 0;
		printf ("%lld\n",Euler_work(x));
	}
}*/


long long x;
int main()
{
//	freopen("test.txt","r",stdin);
	sslist(a,1000010);
	Euler_list(1000010);
	deal(1000010);
	for (;scanf ("%lld",&x)!=EOF;)
	{
		if (x==0)	return 0;
		printf ("%lld\n",ans[x]);
	}
}
