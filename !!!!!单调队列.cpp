#include<cstdio>

struct quere
{
	int a[200],l,r;
	bool ifjian;
	void cls(bool x=true){l=r=1;a[1]=x;ifjian=x;}
	quere(bool x=true){cls(x);}
	void put(int x);
	int get(){return a[l];}
	void pop(){l++;}
}lie;
void quere::put(int x)
{
	for (;;r--)
	{
		if (((a[r-1]<x)==ifjian)||r==l)	break;
	}
	a[r]=x;
	r++;
}


int n,x;
int main()
{
	freopen("test.txt","r",stdin);
	scanf ("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf ("%d",&x);
		lie.put(x);
		for (int i=lie.l;i<lie.r;i++)
		{
			printf ("%d ",lie.a[i]);
		}
		printf ("\n");
	}
	return 0;
}
