#include<cstdio>
#include<algorithm>

struct treenode{
	int l,r;
	int ls,rs;
	int num;
}tree[200020*32];

int topnode=1;
int newnode(){return topnode++;}

int build(int l,int r)
{
	if (l==r)
	{
		int x=newnode();
		tree[x].l=tree[x].r=l;
		return x;
	}
	int m=(l+r)/2;
	int x=newnode();
	tree[x].ls=build(l,m);
	tree[x].rs=build(m+1,r);
	tree[x].l=l;
	tree[x].r=r;
	tree[x].num=0;
	return x;
}

int insert(int n,int k)
{
	int x=newnode();
	tree[x]=tree[n];
	tree[x].num++;
	if (tree[x].l==tree[x].r)	return	 x;
	int m=(tree[x].l+tree[x].r)/2;
	if (m>=k)	tree[x].ls=insert(tree[n].ls,k);
		else	tree[x].rs=insert(tree[n].rs,k);
	return x;
}

int query(int x,int y,int k)
{
	if (tree[x].l==tree[x].r)	return tree[x].l;
	int left=tree[tree[y].ls].num-tree[tree[x].ls].num;
	return left>=k?query(tree[x].ls,tree[y].ls,k):query(tree[x].rs,tree[y].rs,k-left);
}

int root[200020],topr=0;
void init(int n){root[topr++]=build(1,n);}
void change(int k){root[topr]=insert(root[topr-1],k);topr++;}
int find(int l,int r,int k){return query(root[l-1],root[r],k);}

struct asd{int a,num;}num[200020];
bool operator <(asd a,asd b){return a.num<b.num;}

int num_[200020];
int n,m;
int l,r,k;

int main()
{
//	freopen("test.txt","r",stdin);
	scanf ("%d %d",&n,&m);
	for (int i=1;i<=n;i++)	num[i].a=i;
	for (int i=1;i<=n;i++)	scanf ("%d",&num[i].num);
	
	std::sort(num+1,num+n+1);
	for (int i=1;i<=n;i++)	num_[num[i].a]=i;
	init(n);
	for (int i=1;i<=n;i++)	change(num_[i]);
	
	for (int i=1;i<=m;i++)
	{
		scanf ("%d %d %d",&l,&r,&k);
		printf ("%d\n",num[find(l,r,k)].num);
	}
}
