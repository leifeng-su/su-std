#include<cstdio>

struct quere
{
	int a[100020],maxn,l,r;
	quere(int n=100010){maxn=n;l=r=0;}
	void put(int x){a[r=(r+1)%maxn]=x;}
	int get(){return a[l=(l+1)%maxn];}
	bool empty(){return (r+1)%maxn==l;}
	void cls(){l=r=0;}
}lie;

struct tree_node{int a,ls,rs,lazy,size;};

struct tree
{
	tree_node A[100000];
	int top;
	quere mempool;
	tree(){for (int i=1;i<=80000;i++){mempool.put(i);}}
	int head;
	void add(int a);
	bool find(int a);
	void del(int a);
	void remade(int a);
	void dfs(int a);
	int sovel(int l,int r,int *a);
}tree;
void tree::add(int a)
{
	if (head==0)	{head=mempool.get();A[head].a=a;return;}
	int point=0;
	for (int i=head;i!=0;)
	{
		if (point==0&&(A[i].size*0.75<A[A[i].ls].size||A[i].size*0.75<A[A[i].rs].size))	point=i;
		A[i].size++;
		if (a>A[i].a)
		{
			if (A[i].rs==0)
			{
				A[i].rs=mempool.get();
				A[A[i].rs].a=a;
				A[A[i].rs].size=1;
				break;
			}
			else	i=A[i].rs;
		}   
		else
		{
			if (A[i].ls==0)
			{
				A[i].ls=mempool.get();
				A[A[i].ls].a=a;
				A[A[i].ls].size=1;
				break;
			}
			else	i=A[i].ls;
		}
	}
	if (point!=0)	remade(point);
}
bool tree::find(int a)
{
	for (int i=head;i!=0;)
	{
		if (A[i].a==a&&A[i].lazy==0)	return true;
		if (a>A[i].a)	i=A[i].rs;
			else	i=A[i].ls;
	}
	return false;
}
void tree::del(int a)
{
	for (int i=head;i!=0;)
	{
		A[i].size--;
		if (A[i].a==a&&A[i].lazy==0)
		{A[i].lazy=1;return;}
		if (a>A[i].a)	i=A[i].rs;
			else	i=A[i].ls;
	}
}
void tree::remade(int a)
{
	dfs(A[a].ls);
	lie.put(A[a].a);
	dfs(A[a].rs);
	int m=(lie.l+lie.r)>>1;
	A[a].a=lie.a[m];
	A[a].ls=sovel(lie.l,m-1,lie.a);
	A[a].rs=sovel(m+1,lie.r,lie.a);
	A[a].size=A[A[a].ls].size+A[A[a].rs].size+1;
}
void tree::dfs(int a)
{
	if (a==0)	return;
	dfs(A[a].ls);
	mempool.put(a);
	if (A[a].lazy==0)	lie.put(A[a].a);
	A[a].size=A[a].ls=A[a].rs=A[a].lazy=A[a].a=0;
	dfs(A[a].rs);
}
int tree::sovel(int l,int r,int *a)
{
	if (l>r)	return 0;
	int m=(l+r)>>1;
	int z=mempool.get();
	A[z].a=a[m];
	A[z].ls=sovel(l,m-1,a);
	A[z].rs=sovel(m+1,r,a);
	A[z].size=A[A[z].ls].size+A[A[z].rs].size+1;
	return z;
}

int read()
{
	char c;
	for (;scanf ("%c",&c)!=EOF;)
	{
		if (c=='D')	return 1;
		if (c=='I')	return 2;
	}
	return -1;
}

int n,a,p;
int main()
{
	freopen("test.txt","r",stdin);
	scanf ("%d",&n);
	for (int i=1;i<=n;i++)
	{
		p=read();
		scanf ("%d",&a);
		if (p==1)
		{
			if (!tree.find(a))
			{
				printf ("not exist\n");
				continue;
			}
			tree.del(a);
			printf ("delete success\n");
		}
		if (p==2)
		{
			if (tree.find(a))
			{
				printf ("has been\n");
				continue;
			}
			tree.add(a);
			printf ("insert success\n");
		}
	}
//	for(;;);
}
