#include<cstdio>
#include<cstring>

inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}


struct Zhan{
	int a[20020];
	int p[20020];
	int top,time;
	int pop()
	{p[a[top]]=-1;return a[top--];}
	void put(int x)
	{a[++top]=x;p[x]=++time;}
	int find(int x)
	{return p[x];}
	Zhan(){top=0;time=0;}
}zhan;

int to[110020],next[110020],top=10000+1;
int ljb(int x,int y)
{
	top++;
	next[top]=next[x];
	next[x]=top;
	to[top]=y;
}

int cln[10020],low[10020];
int clt;
int tarjan(int x)
{
	if (zhan.find(x)<0)	return 0;
	zhan.put(x);
	low[x]=zhan.find(x);
	for (int i=next[x];i!=0;i=next[i])
	{
		int z=zhan.find(to[i]);
		if (z==0)	low[x]=min(low[x],tarjan(to[i]));
		if (z>0)	low[x]=min(low[x],z);
	}
	
	if (low[x]==zhan.find(x))
	{
		clt++;
		cln[x]=clt;
		for (int i=zhan.pop();i!=x;i=zhan.pop())
			cln[i]=clt;
	}
	return low[x];
}

/////ÎÞÏòÍ¼tarjan
/*int to[110020],next[110020],top=10000+1; 
int ljb(int x,int y)
{
	top++;
	next[top]=next[x];
	next[x]=top;
	to[top]=y;
}

int cln[10020],low[10020];
int clt;
int tarjan(int x)
{
	if (zhan.find(x)<0)	return 0;
	zhan.put(x);
	low[x]=zhan.find(x);
	for (int i=next[x];i!=0;i=next[i])
	{
		int x=to[i^1];
		to[i^1]=to[i];
		int z=zhan.find(to[i]);
		if (z==0)	low[x]=min(low[x],tarjan(to[i]));
		if (z>0)	low[x]=min(low[x],z);
		to[i^1]=x;
	}
	
	if (low[x]==zhan.find(x))
	{
		clt++;
		cln[x]=clt;
		for (int i=zhan.pop();i!=x;i=zhan.pop())
			cln[i]=clt;
	}
	return low[x];
}*/ 




int n,m,a,b;
int num[10020];
int M,p;

int main()
{
//	freopen("test.txt","r",stdin);
	scanf ("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf ("%d %d",&a,&b);
		ljb(a+1,b+1);
	}
	for (int i=1;i<=n;i++)	tarjan(i);
	
	for (int i=1;i<=n;i++)	num[cln[i]]++;
	
	for (int i=1;i<=clt;i++)
	{
		if (num[i]>M)
		{p=0;M=num[i];}
		if (num[i]==M)	p=1;
	}
	
	if (p==0)
	{
		for (int i=1;i<=n;i++)
			if (num[cln[i]]==M)	printf ("%d ",i-1);
	}
	else
	{
		int po=0;
		for (int i=1;i<=n;i++)
		{
			if (p==0)
			{
				if (cln[i]==po)	printf ("%d ",i-1);
			}
			else
			{
				if (num[cln[i]]==M)
				{
					p=0;po=cln[i];
					printf ("%d ",i-1);
				}
			}
		}
		
	}
}
