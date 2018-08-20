#include<cstdio>

int f[10020];
int find(int a){return f[a]==a?a:f[a]=find(a[f]);}


int n,m,a,b,c;
int main()
{
//	freopen("test.txt","r",stdin);
	scanf ("%d %d",&n,&m);
	for (int i=1;i<=n;i++)	f[i]=i;
	for (int i=1;i<=m;i++)
	{
		scanf ("%d %d %d",&c,&a,&b);
		if (c==1)	f[find(a)]=find(b);
		if (c==2)	printf ("%c\n",find(a)==find(b)?'Y':'N');
	}
}
