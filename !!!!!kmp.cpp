#include<cstdio>

int kmp_next[1000020];
char a_kmp[1000020];
void kmp_deal(char *c=a_kmp)
{
	int now=0;
	kmp_next[1]=0;
	for (int i=1;c[i]!=0;)
	{
		if (c[i]==c[now]||now==0)
			kmp_next[++i]=++now;
		else
			now=kmp_next[now];
	}
}

int kmp(char *p,char *a=a_kmp)
{
	int now=1;
	int i=1;
	for(;p[i]!=0&&(a[now]!=0||now==0);)
	{
		if (now==0||p[i]==a[now])
		{
			i++;
			now++;
		}
		else
		{
			now=kmp_next[now];
		}
	}
	return a[now]==0?i-now+1:0;
}



char c[10020];
int main()
{
	freopen("test.txt","r",stdin);
	scanf ("%s %s",c+1,a_kmp+1);
	kmp_deal();
	for (int i=1;c[i]!=0;)
	{
		int x=kmp(c+i-1);
		if (x==0)	break;
		printf ("%d\n",x+i-1);
		i+=x;
	}
	for (int i=1;a_kmp[i]!=0;i++)
	{
		printf ("%d ",kmp_next[i]);
	}
	for (;;);
}
