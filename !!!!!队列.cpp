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


int mian()
{
	
	
	
}
