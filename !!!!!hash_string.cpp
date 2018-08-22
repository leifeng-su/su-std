#include<cstdio>
/////自然溢出法
/////输入char数组(c[0]==0)
int seed=29;
unsigned int hush(char *c)
{
	unsigned int x=0;
	for (int i=1;c[i]!=0;i++)	x=x*seed+c[i]-'a'+1;
	return x;
}

int main()
{
	freopen("test.txt","r",stdin);
	
	
	
}
