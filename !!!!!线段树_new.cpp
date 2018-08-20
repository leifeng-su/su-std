#include<cstdio>

inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}

long long A[120000];
struct line_tree{
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

int n,m;
int a,b,k,p;
int main()
{
//	freopen("test.txt","r",stdin);
	scanf ("%d %d",&n,&m);
	for (int i=1;i<=n;i++)	scanf ("%lld",&A[i]);
	build(1,1,n);
	
	for (int i=1;i<=m;i++)
	{
		scanf ("%d %d %d",&p,&a,&b);
		if (p==1)
		{
			scanf ("%d",&k);
			change(a,b,k,1);
		}
		if (p==2)
		{
			printf ("%lld\n",find_sum(a,b,1));
		}
	}
	return 0;
}
