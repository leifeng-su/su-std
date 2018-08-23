#include<cstring>
#include<cstdio>

int a[10000020];
int vis[10000020];
void sslist(int *a,int n)////////////制素数表 
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

void ss_fac(int *a,int n)////////////用于因式分解(a[i]存i最大因数)
{
	for (int i=2;i<=n;i++)
		if (!a[i])	for (int j=i;j<=n;j+=i)	a[j]=i;
}

bool p[10000020];
void prime(int n)
{
	memset(p,true,sizeof(p));
	p[1]=false;
	for (int i=2;i<=n;i++)
	{
		if (p[i]==false)	continue;
		for (int j=i+i;j<=n;j+=i)	p[j]=false;
	}
}



void find_prime(int *a,int n)/////线性筛素数+制表 
{
	memset(p,true,sizeof(p));
	int topa=1;
	for(int i=2;i<=n;i++)
	{
		if(p[i])	a[topa++]=i;
		for(int j=1;j<=topa;j++)
		{
			if(i*a[j]>n)	break;
			p[i*a[j]]=false;
            if(i%a[j]==0) break;
        }
    }
}

/*
int main()
{
	int n,m,x;
//	freopen("test.txt","r",stdin);
	scanf ("%d %d",&n,&m);
	prime(n+2);
	for (int i=1;i<=m;i++)
	{
		scanf ("%d",&x);
		printf ("%s\n",p[x]?"Yes":"No");
	}
}
*/
int main()
{
	freopen("test.out","w",stdout);
	sslist(a,10000010);
	int i;
	for (i=1;a[i]!=0;i++);	/*printf ("%d ",a[i]);*/
	printf ("%d",i-1);
	return 0;
}
