#include<cstdio>

void exgcd(int a,int b,int &c,int &x,int &y)
{
	if (b==0)	{c=a;x=1;y=0;return;}
	exgcd(b,a%b,c,y,x);y-=x*(a/b);
}

int main()
{
//	freopen("test.txt","r",stdin);
	int n,p;
	scanf ("%d %d",&n,&p);
	
	for (int i=1;i<=n;i++)
	{
		int x,y,c;
		exgcd(i,p,c,x,y);
		for (;x<0;)x+=p;
		printf ("%d\n",x);
	}
}
