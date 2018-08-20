#include<cstdio>

inline void swap(int &a,int &b){int c=a;a=b;b=c;}

int h[100020];
void half_sort(int *a,int l,int r)
{
	if (l>=r)	return;
	int m=(l+r)>>1;
	half_sort(a,l,m);
	half_sort(a,m+1,r);
	int x=l,y=m+1,i;
	for (i=l;i<=r;i++)
	{
		if (x>m||y>r)	break;
		if (a[x]<a[y])
		{
			h[i]=a[x];
			x++;
		}
		else
		{
			h[i]=a[y];
			y++;
		}
	}
	for (;i<=r;i++)
	{
		if (x<=m)
		{
			h[i]=a[x];
			x++;
		}
		if (y<=r)
		{
			h[i]=a[y];
			y++;
		}
	}
	for (i=l;i<=r;i++)	a[i]=h[i];
	return;
}

int a[100020];
int n;

int main()
{
//	freopen("test.txt","r",stdin);
	scanf ("%d",&n);
	for (int i=1;i<=n;i++)	scanf ("%d",&a[i]);
	half_sort(a,1,n);
	for (int i=1;i<=n;i++)	printf ("%d ",a[i]);
}
