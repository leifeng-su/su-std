#include<cstdio>

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline void swap(int &a,int &b){a+=b;b=a-b;a=a-b;}

int to[2000020],next[2000020],top=500020+1;
int ljb(int x,int y)
{
	top++;
	next[top]=next[x];
	next[x]=top;
	to[top]=y;
}

int front[500020],end[500020];
int vis[500020];
int f[1000020],d[1000020],topf=0;
void dfs_Euler(int a,int s)
{
	vis[a]=1;
	f[++topf]=a;
	d[topf]=s;
	front[a]=topf;
	for (int i=next[a];i!=0;i=next[i])
	{
		if (vis[to[i]]==1)	continue;
		dfs_Euler(to[i],s+1);
		f[++topf]=a;
		d[topf]=s;
	}
	end[a]=topf;
}

int rmq[1000020][32];
void RMQ(int *a,int n)
{
	for (int i=1;i<=n;i++)	rmq[i][0]=i;
	for (int j=1;1<<j<=n;j++)
		for (int i=1;i+(1<<j)-1<=n;i++)
			rmq[i][j]=a[rmq[i][j-1]]<a[rmq[i+(1<<(j-1))][j-1]]?rmq[i][j-1]:rmq[i+(1<<(j-1))][j-1];
}

inline int topbit(int a)
{
	for (int i=30;i>=0;i--)
		if (a&(1<<i))	return i;
}

int find(int a,int b)
{
	a=front[a];b=front[b];
	if (a>b)	swap(a,b);
	int k=topbit(b-a+1);
	return f[d[rmq[a][k]]<d[rmq[b-(1<<k)+1][k]]?rmq[a][k]:rmq[b-(1<<k)+1][k]];
}

int n,q,k,a,b;
int main()
{
//	freopen("test.txt","r",stdin);
	scanf ("%d %d %d",&n,&q,&k);
	for (int i=1;i<n;i++)
	{
		scanf ("%d %d",&a,&b);
		ljb(a,b);
		ljb(b,a);
	}
	dfs_Euler(k,1);
	
	RMQ(d,topf);
	for (int i=1;i<=q;i++)
	{
		scanf ("%d %d",&a,&b);
		printf ("%d\n",find(a,b));
	}
}
