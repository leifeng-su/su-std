#include<cstring>
#include<cstdio>


int main()
{
	for (int i=-127;i<=127;i++)
	{
		int a[2];
		memset(a,i,sizeof(a));
		printf ("%3d :%10d\n",i,a[1]);
	}
	
}
