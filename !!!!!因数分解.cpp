#include<cstdio>


struct quere
{
	int a[100020],maxn,l,r;
	quere(int n=100010){maxn=n;l=r=0;}
	void put(int x){a[r=(r+1)%maxn]=x;}
	int get(){return a[l=(l+1)%maxn];}
	bool empty(){return (r+1)%maxn==l;}
	void cls(){l=r=0;}
}lie;

int a[10000020];
void ss_fac(int *a,int n)
{
	for (int i=2;i<=n;i++)
		if (!a[i])	for (int j=i;j<=n;j+=i)	a[j]=i;
}


void fenjie(int x)
{
	for (;x!=1;x=x/a[x])	lie.put(a[x]);
}


int main()
{
	freopen("test.txt","r",stdin);
	ss_fac(a,100000);

}