#include<cstdio>


int half_find(int l,int r,int c,int *a)
{
	int ans=0;
	for (;;)
	{
		int m=(l+r)>>1;
		if (a[m]<=c)
		{
			ans=m;
			l=m+1;
		}
		else	r=m-1;
	}
}


int main()
{

}