#include<cstdio>
#include<cstring>

const int inf=1<<30;
int n;

inline void swap(int &a,int &b){int c=a;a=b;b=c;}

struct heap{
	int a[100020],num[100020];
	int place[100020];
	int top;
	heap(){memset(a,0,sizeof(a));top=0;}
	void put(int x,int y);
	void change(int a,int x);
	int get();
}dui;/////小根堆
void heap::put(int x,int y)
{
	a[++top]=x;
	num[top]=y;
	place[y]=top;
	for (int i=top;i>=2;i>>=1)
	{
		if (a[i]>a[i>>1])	return;
		swap(a[i],a[i>>1]);
		swap(place[num[i]],place[num[i>>1]]);
		swap(num[i],num[i>>1]);
	}
}
int heap::get()
{
	if (top<=0)	return -1;
	int z=num[1];
	a[1]=a[top];
	place[num[1]]=0;
	place[num[top]]=1;
	num[1]=num[top];
	a[top--]=0;
	for (int i=2;i<=top;i<<=1)
	{
		if (a[i+1]<a[i]&&i<top)	i++;
		if (a[i>>1]<=a[i])	return z;
		swap(a[i>>1],a[i]);
		swap(place[num[i]],place[num[i>>1]]);
		swap(num[i>>1],num[i]);
	}
	return z;
}
void heap::change(int x,int y)/////将编号x的情况价值变为y
{
	a[place[x]]=y;
	int i;
	for (i=place[x];i>=2;i=i>>1)
	{
		if (a[i]>a[i>>1])	break;
		swap(a[i],a[i>>1]);
		swap(place[num[i]],place[num[i>>1]]);
		swap(num[i],num[i>>1]);
	}
	
	for (;i<=top;i<<=1)
	{
		if (a[i+1]>a[i]&&i<top)	i++;
		if (a[i>>1]<=a[i])	return;
		swap(a[i>>1],a[i]);
		swap(place[num[i]],place[num[i>>1]]);
		swap(num[i>>1],num[i]);
	}
	return;
}

int to[520000],next[520000],w[520000],top=10000+1;
int ljb(int x,int y,int W)
{
	top++;
	next[top]=next[x];
	next[x]=top;
	to[top]=y;
	w[top]=W;
}

int dest[10020],last[10020];
int p[10020];
void DJ(int first)
{
	memset(dest,127,sizeof(dest));
	memset(p,0,sizeof(p));
	dest[first]=0;
	p[first]=1;
	dui.put(0,first);
	for(int x=first;x!=-1;x=dui.get())
	{
		for (int j=next[x];j!=0;j=next[j])
		{
			if (dest[x]+w[j]<dest[to[j]])
			{
				dest[to[j]]=dest[x]+w[j];
				if (p[to[j]]==0)
				{
					dui.put(dest[to[j]],to[j]);
					p[to[j]]=1;
				}
				else
				{
					dui.change(to[j],dest[to[j]]);
				}
			}
		}
	}
}

int m,q;

int main()
{
//	freopen("test.txt","r",stdin);
	scanf ("%d %d %d",&n,&m,&q);
	for (int i=1;i<=m;i++)
	{
		int x,y,w;
		scanf ("%d %d %d",&x,&y,&w);
		ljb(x,y,w);
	}
	
	DJ(q);
	for (int i=1;i<=n;i++)	printf ("%d ",dest[i]>200000000?2147483647:dest[i]);
}
