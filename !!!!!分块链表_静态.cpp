#include<cstring>
#include<cstdio>
#include<cmath>

inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
struct stack
{
	int a[100020],top;
	stack(){top=0;}
	void put(int x){a[++top]=x;}
	int get(){return a[top--];}
	bool empty(){return top<1;}
	void cls(){top=0;}
};

struct list_node{
	int l,r,lazy_plus;
	list_node *next;
	list_node(){lazy_plus=l=r=0;next=NULL;}
};
struct list{
	int A[60000];
	list_node a[1020];
	list_node *top;
	stack mempool;
	list(){for (int i=0;i<=1000;i++)	mempool.put(i);}
	void build(int n,int *a);
	void add(int L,int R,int c);
	int find(int a);
}lie;
void list::build(int n,int *A=NULL)
{
	int m=sqrt(n)+0.5;
	top=a+mempool.get();
	top->l=1;
	top->r=1+m;
	list_node *now=top;
	for (int i=m+2;i<=n;i+=m+1)
	{
		now->next=a+mempool.get();
		now=now->next;
		now->l=i;now->r=min(i+m,n);
	}
	now->next=NULL;
}

void list::add(int L,int R,int c)
{
	for (list_node *i=top;i!=NULL;i=i->next)
	{
		if (L<=i->l&&R>=i->r){i->lazy_plus+=c;continue;}
		int l=max(i->l,L);
		int r=min(i->r,R);
		for (int j=l;j<=r;j++)	A[j]+=c;
	}
}
int list::find(int a)
{
	for (list_node *i=top;i!=NULL;i=i->next)	if (i->l<=a&&i->r>=a)	return A[a]+i->lazy_plus;
	return -1;
}

int n,p,a,b,c;
int main()
{
	freopen("test.txt","r",stdin);
	scanf ("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		lie.A[i]=a;
	}
	lie.build(n);
	
	for (int i=1;i<=n;i++)
	{
		scanf ("%d %d %d %d",&p,&a,&b,&c);
		if (p==0)	lie.add(a,b,c);
		if (p==1)	printf ("%d\n",lie.find(b));
	}
//	for(;;);
}
