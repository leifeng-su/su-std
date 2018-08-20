#include<cstdio>
#include<cstring>
#include<algorithm>

struct node{
	int x,y,w;
	int set(int a,int b,int c){x=a;y=b;w=c;}
}x[200020];
bool operator <(node a,node b){return a.w<b.w;}

int f[5020];
int find(int a){return a==f[a]?a:f[a]=find(f[a]);}

void kruskal(int n,int m)
{
	long long ans=0;
	for (int i=1;i<=n;i++)	f[i]=i;
	for (int i=1;i<=m;i++)
	{
		if (find(x[i].x)!=find(x[i].y))
		{
			ans+=x[i].w;
			f[find(x[i].x)]=find(x[i].y);
			n--;
		}
	}
	printf ("%lld",n<=1?ans:-1);
	return;
}


int main()
{
//	freopen("test.txt","r",stdin);
	int n,m;
	scanf ("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf ("%d %d %d",&a,&b,&c);
		x[i].set(a,b,c);
	}
	std::sort(x+1,x+m+1);
	
	kruskal(n,m);
}
