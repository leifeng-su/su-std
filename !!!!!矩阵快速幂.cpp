#include<cstdio>
#include<cstring>


struct matrix{
	int n;
	int a[220][220];
	matrix(){n=0;memset(a,0,sizeof(a));}
	void print();
};
void matrix::print()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			printf ("%d ",a[i][j]);
		}
		printf ("\n");
	}
}

matrix operator *(matrix &a,matrix &b)
{
	matrix c;
	c.n=a.n;
	for (int i=1;i<=b.n;i++)
		for (int j=1;j<=b.n;j++)
			for (int k=1;k<=b.n;k++)
				c.a[i][j]+=a.a[i][k]*b.a[k][j];
	return c;
}


void unit(matrix &a,int n)
{
	a.n = n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i==j)	a.a[i][j]=1;
				else a.a[i][j]=0;
}
matrix power(matrix &a,int n,int len)
{
	matrix b;
	unit(b,len);
	for (;n;n=n>>1)
	{
		if (n&1==1)	b=b*a;
		a=a*a;
	}
	return b;
}

int main()
{
	freopen("test.txt","r",stdin);
	matrix a;
	scanf ("%d",&a.n);
	for (int i=1;i<=a.n;i++)
		for (int j=1;j<=a.n;j++)
			scanf ("%d",&a.a[i][j]);
	
	matrix b=a;
	for (int i=1;i<=10;i++)
	{
		printf ("*-%d:\n",i);
		b.print();
		printf ("\n");
		b=b*a;
	}
	
	return 0;
}
