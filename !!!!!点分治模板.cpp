#include<algorithm>
#include<cstring>
#include<cstdio>

inline int max(int a,int b){return a>b?a:b;}
inline int swap(int &a,int &b){int c=a;a=b;b=c;}

int n,m,k;

int to[160000],next[160000],w[160000],topl=40020+1;
void ljb(int x,int y,int z)
{
	topl++;
	next[topl]=next[x];
	next[x]=topl;
	to[topl]=y;
	w[topl]=z;
}

int root,nowm=0;
int vis[40020],size[40020];
void dfs1(int a)
{
	int mson=0;
	vis[a]=1;
	size[a]=0;
	for (int i=next[a];i!=0;i=next[i])
	{
		if (vis[to[i]]==1)	continue;
		dfs1(to[i]);
		size[a]+=size[to[i]];
		if (mson<size[to[i]])	mson=size[to[i]];
	}
	vis[a]=0;
	size[a]++;
	mson=max(mson,n-size[a]);
	if (mson<nowm){root=a;nowm=mson;}
}


int dis[40020],topd;
void dfs_dis(int a,int d)
{
	vis[a]=1;
	dis[++topd]=d;
	for (int i=next[a];i!=0;i=next[i])
	{
		if (vis[to[i]]==1)	continue;
		dfs_dis(to[i],d+w[i]);
	}
	vis[a]=0;
}

int find_ans(int a,int point)
{
	int ans=0;
	topd=0;
	dfs_dis(a,point);
	std::sort(dis+1,dis+topd+1);
	for (int l=1,r=topd;l<=r;)
	{
		if (dis[l]+dis[r]<=k)	{if (dis[l]+dis[r]==k)	ans++;l++;}
		else	r--;
	}
	return ans;
}


int sovel(int a)
{
	int ans=find_ans(a,0);
	vis[a]=1;
	for (int i=next[a];i!=0;i=next[i])
	{
		if (vis[to[i]]==1)	continue;
		ans-=find_ans(to[i],w[i]);
		nowm=n;
		dfs1(to[i]);
		ans+=sovel(root);
	}
	vis[a]=0;
	return ans;
}

int a,b,c;
void work()
{
	memset(next,0,sizeof(next));
	topl=40020+1;
	nowm=n;
	for (int i=1;i<n;i++)
	{
		scanf ("%d %d %d",&a,&b,&c);
		ljb(a,b,c);
		ljb(b,a,c);
	}
	dfs1(1);
	dfs_dis(root,0);
	for (int i=1;i<=m;i++)
	{
		scanf ("%d",&k);
		printf ("%s\n",sovel(root)>0?"AYE":"NAY");
	}
}


int main()
{
//	freopen("test.txt","r",stdin);
	scanf ("%d %d",&n,&m);
	work();
//	for (;;);
	return 0;
}