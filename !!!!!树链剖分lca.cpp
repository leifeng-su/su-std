#include<cstdio>

int to[2000020],next[2000020],topl=500020+1;
int ljb(int x,int y)
{
	topl++;
	next[topl]=next[x];
	next[x]=topl;
	to[topl]=y;
}

int lie[500020],fan_lie[500020],topd;
void lie_put(int a){lie[++topd]=a;fan_lie[topd]=a;}

int vis[500020],fa[500020],faw[500020],size[500020],son[500020],top[500020],d[500020];
void dfs1(int a,int b)
{
	vis[a]=1;d[a]=b;
	for (int i=next[a];i!=0;i=next[i])
	{
		if (vis[to[i]]==1)
		{
			fa[a]=to[i];
			continue;
		}
		dfs1(to[i],b+1);
		size[a]+=size[to[i]];
		if (size[to[i]]>size[son[a]])	son[a]=to[i];
	}
	size[a]++;
}

void dfs2(int a,int t)
{
	top[a]=t;
	lie_put(a);
	if (son[a]!=0)	dfs2(son[a],t);
	for (int i=next[a];i!=0;i=next[i])
	{
		if (to[i]==fa[a])	continue;
		if (to[i]==son[a])	continue;
		dfs2(to[i],to[i]);
	}
}

int find_lca(int a,int b)
{
	int x=top[a],y=top[b];
	if (x==y)	return d[a]<d[b]?a:b;
	return d[x]<d[y]?find_lca(a,fa[y]):find_lca(fa[x],b);
}

int n,q,a,b,k;
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
	dfs1(k,1);
	dfs2(k,k);
	for (int i=1;i<=q;i++)
	{
		scanf ("%d %d",&a,&b);
		printf ("%d\n",find_lca(a,b));
	}
}
