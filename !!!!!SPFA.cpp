#include<cstdio>
#include<cstring>

const int N=100,M=3000;
const int inf=1<<30;
int n=N;

struct quere
{
	int a[100020],maxn,l,r;
	quere(int n=100010){maxn=n;l=r=0;}
	void put(int x){a[r=(r+1)%maxn]=x;}
	int get(){return a[l=(l+1)%maxn];}
	bool empty(){return (r+1)%maxn==l;}
	void cls(){l=r=0;}
}lie;


int to[M],next[M],w[M],top=N+1;
int ljb(int x,int y,int W)
{
	top++;
	next[top]=next[x];
	next[x]=top;
	to[top]=y;
	w[top]=W;
}


int dest[N],last[N];
int p[N];
void SPFA(int first)
{
	memset(dest,127,sizeof(dest));
	memset(p,0,sizeof(p));
	memset(last,0,sizeof(last));
	dest[first]=0;
	p[first]=1;
	lie.cls();
	lie.put(first);
	
	for(int x=first;!lie.empty();x=lie.get())
	{
		for (int j=next[x];j!=0;j=next[j])
		{
			if (dest[x]+w[j]<dest[to[j]])
			{
				dest[to[j]]=dest[x]+w[j];
				last[to[j]]=x;
				if (p[to[j]]!=1)
				{
					p[to[j]]=1;
					lie.put(to[j]);
				}
			}
		}
		p[x]=0;
	}
}


int main()
{
	freopen("test.txt","r",stdin);
	scanf ("%d",&n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			int x,y,w;
			scanf ("%d %d %d",&x,&y,&w);
			if (x!=0)	ljb(x,y,w);
		}
	}
	SPFA(1);
}
