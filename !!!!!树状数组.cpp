#include<cstdio>

int n,m,x,y,p;

inline int lowbit(int a){return -a&a;}
int sum[500020];
void add(int x,int a)
{for (;x<=n;x+=lowbit(x))	sum[x]+=a;}
int find(int x)
{int ans=0;for (;x>0;x-=lowbit(x))	ans+=sum[x];return ans;}

int main()
{
//	freopen("test.txt","r",stdin);
	scanf ("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf ("%d",&x);
		add(i,x);
	}
	
	for (int i=1;i<=m;i++)
	{
		scanf ("%d %d %d",&p,&x,&y);
		if (p==1)	add(x,y);
		if (p==2)	printf ("%d\n",find(y)-find(x-1));
	}
}
