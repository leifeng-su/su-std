#include <cstdio>
inline int max(int a,int b){return a>b?a:b;}

int rmq[10000][10000];
void RMQ(int *a,int n)
{
	for (int i=1;i<=n;i++)	rmq[i][0]=a[i];
	for (int j=1;1<<j<=n;j++)
		for (int i=1;i+(1<<j)-1<=n;i++)
			rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
}

inline int topbit(int a)
{
	for (int i=30;i>=0;i--)
		if (a&(1<<i))	return i;
}

int main()
{
	freopen("test.txt","r",stdin);
	int n=20;
	int a[30];
	for (int i=1;i<=n;i++)	scanf ("%d",&a[i]);
	RMQ(a,n);
	int st=1,en=20;
	int k=topbit(en-st+1);
	int maxl=max(rmq[st][k],rmq[en-(1<<k)+1][k]);
	printf ("%d",maxl);
    return 0;
}
