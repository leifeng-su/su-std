#include<cstdio>
#include<cstring>

inline void swap(int &x,int &y)
{x=x+y;y=x-y;x=x-y;}

const int N=100;
struct heap{
	int a[N];
	int top;
	heap(){memset(a,0,sizeof(a));top=0;}
	void put(int x);
	int get();
};
void heap::put(int x)
{
	a[++top]=x;
	for (int i=top;i>=2;i>>=1)
	{
		if (a[i]<a[i>>1])	return;
		swap(a[i],a[i>>1]);
	}
}
int heap::get()
{
	int z=a[1];
	a[1]=a[top];
	a[top--]=0;
	for (int i=2;i<=top;i<<=1)
	{
		if (a[i+1]>a[i]&&i<top)	i++;
		if (a[i>>1]>=a[i])	return z;
		swap(a[i>>1],a[i]);
	}
	return z;
}
/*
truct heap{
	int a[200020],top;
	heap(){top=0;}
	void put(int x);
	int get();
	int head(){return a[1];}
	bool empty(){return top>=1;}
};
void heap::put(int x)
{
	a[++top]=x;
	for (int i=top;i>=2;i=i>>1)
	{
		if (a[i>>1]<a[i])	return;
		swap(a[i>>1],a[i]);
	}
}
int heap::get()
{
	int z=a[1];
	a[1]=a[top];
	a[top--]=1<<20;
	for (int i=2;i<=top;i=i<<1)
	{
		if (a[i|1]<a[i])	i++;
		if (a[i>>1]<a[i])	return z;
		swap(a[i],a[i>>1]);
	}
	return z;
}
*/
int main()
{
	return 0;
}
