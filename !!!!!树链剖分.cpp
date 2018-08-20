#include<cstdio>

inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}

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

struct line_tree
{
	long long A[120000];
	struct line_tree_node{
		int left,right;
		long long lazy;
		long long min,max;
		long long sum;
	}tree[820000];
	
	inline void pushup(int p)
	{
		tree[p].sum=tree[p<<1].sum+tree[p<<1|1].sum;
		tree[p].max=max(tree[p<<1].max,tree[p<<1|1].max);
		tree[p].min=min(tree[p<<1].min,tree[p<<1|1].min);
	}
	
	inline void pushdown(int p)
	{
		tree[p<<1].lazy+=tree[p].lazy;
		tree[p<<1|1].lazy+=tree[p].lazy;
		tree[p].sum=tree[p].sum+(tree[p].right-tree[p].left+1)*tree[p].lazy;
		tree[p].min=tree[p].min+tree[p].lazy;
		tree[p].max=tree[p].max+tree[p].lazy;
		tree[p].lazy=0;
	}
	
	void build(int p,int l,int r)
	{
		tree[p].left=l;
		tree[p].right=r;
		if (l==r)
		{
			tree[p].min=tree[p].max=A[l];
			tree[p].sum=A[l];
			return;
		}
		int m=(l+r)/2;
		build(p<<1,l,m);
		build(p<<1|1,m+1,r);
		pushup(p);
		return;
	}
	
	void change(int a,int c,int p)/////µã
	{
		int l=tree[p].left,r=tree[p].right;
		pushdown(p);
		if (a==l&&a==r)
		{
			tree[p].lazy=c;
			pushdown(p);
			return;
		}
		int m=(l+r)/2;
		if (m>=a)	change(a,c,p<<1);
		if (m<a)	change(a,c,p<<1|1);
		pushdown(p<<1);
		pushdown(p<<1|1);
		pushup(p);
	}
	
	void change(int a,int b,int c,int p)/////Çø¼ä
	{
		int l=tree[p].left,r=tree[p].right;
		pushdown(p);
		if (a<=l&&b>=r)
		{
			tree[p].lazy=c;
			pushdown(p);
			return;
		}
		int m=(l+r)/2;
		if (m>=a&&l<=b)	change(a,b,c,p<<1);
		if (m<b&&r>=a)	change(a,b,c,p<<1|1);
		pushdown(p<<1);
		pushdown(p<<1|1);
		pushup(p);
	}
	
	long long find_sum(int a,int b,int p)
	{
		pushdown(p);
		int l=tree[p].left,r=tree[p].right;
		if (l>=a&&r<=b)	return tree[p].sum;
		if (l>b)	return 0;
		if (r<a)	return 0;
		return (long long)find_sum(a,b,p<<1)+find_sum(a,b,p<<1|1);
	}
	long long find_min(int a,int b,int p)
	{
		pushdown(p);
		int l=tree[p].left,r=tree[p].right;
		if (l>=a&&r<=b)	return tree[p].min;
		if (l>b)	return 1<<30;
		if (r<a)	return 1<<30;
		return min(find_min(a,b,p<<1),find_min(a,b,p<<1|1));
	}
	long long find_max(int a,int b,int p)
	{
		pushdown(p);
		int l=tree[p].left,r=tree[p].right;
		if (l>=a&&r<=b)	return tree[p].max;
		if (l>b)	return 0;
		if (r<a)	return 0;
		return max(find_max(a,b,p<<1),find_max(a,b,p<<1|1));
	}
};




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
