#include<cstdio>

inline void swap(int &a,int &b){int c=a;a=b;b=c;}

struct heap{
	int a[1000020],top;
	heap(){top=0;}
	void put(int x);
	int get();
}d;
void heap::put(int x)
{
	a[++top]=x;
	for (int i=top;i>=2;i=i>>1)
	{
		if (a[i]>a[i>>1])	return;
		swap(a[i],a[i>>1]);
	}
}
int heap::get()
{
	int z=a[1];
	a[1]=a[top];
	a[top--]=1<<30;
	for (int i=2;i<=top;i=i<<1){
		if (a[i+1]<a[i])	i++;
		if (a[i>>1]<a[i])	return z;
		swap(a[i],a[i>>1]);
	}
	return z;
}

int main()
{
	int n,x;
//	freopen("test.txt","r",stdin);
	scanf ("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf ("%d",&x);
		if (x==3)	d.get();
		if (x==2)	printf ("%d\n",d.a[1]);
		if (x==1){scanf ("%d",&x);d.put(x);}
	}
}
