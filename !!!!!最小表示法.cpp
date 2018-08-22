#include<cstdio>


void swap(int &a,int &b){int c=a;a=b;b=a;}

char c[20020];
int n;
int work()/////返回从下标i开始字典序最小
{
	scanf ("%s",c+1);
	for (n=1;c[n+1]!=0;n++);
	for (int i=1;i<=n+1;i++)	c[n+i]=c[i];
	int i=1,j=2;
	for (;j<=n;)
	{
		int k;
		for (k=0;k<=n;k++)	if (c[i+k]!=c[j+k])	break;
		if (k>=n)	break;
		if (c[i+k]<c[j+k])	j=j+k+1;
			else	i=i+k+1;
		if (i>j)	swap(i,j);
		if (i==j)	j++;
	}
	return i;
}

int main()
{
//	freopen("test.txt","r",stdin);
	int n;
	scanf ("%d",&n);
	for (int i=1;i<=n;i++)	printf ("%d\n",work());
}
