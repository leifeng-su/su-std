#include<cstdio>
#include<stdlib.h> 
#include<ctime>


int main()
{
	freopen("test.txt","w",stdout);
	
	srand(time(NULL));
	int n=1;
	printf ("%d\n",n);
	for (int i=1;i<=n;i++)
	{
		printf ("%s ",rand()%2?"YES":"NO");
	}
}
