#include<cstdio>
#include<cstring>

inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}

const int mod=10000;

struct l_int
{
	int top,p;
	int a[100];
	void cls();
	void print();
	l_int operator +(l_int b);
	l_int operator -(l_int b);
	l_int operator *(l_int b);
	l_int operator /(l_int b);
	l_int operator +(int b);
	l_int operator -(int b);
	l_int operator *(int b);
	l_int operator /(int b);
	bool operator <(l_int b);
	bool operator >(l_int b);
	l_int();
	l_int(char *c);
};

l_int::l_int(char *c)
{
	memset(a,0,sizeof(a));int cl=strlen(c);top=(cl-1)/4+1;p=1;
	for (int i=0;i<cl;i++)	{a[(cl-i-1)/4+1]*=10;a[(cl-i-1)/4+1]+=(c[i]-'0');}
}
l_int::l_int(){memset(a,0,sizeof(a));top=1;p=1;}
void l_int::cls()
{
	for (int i=1;i<top;i++)
	{
		if (a[i]>=mod)	{a[i+1]+=a[i]/mod;a[i]=a[i]%mod;}
		if (a[i]<0)	{a[i+1]-=(-a[i]-1)/mod+1;a[i]=a[i]%mod;if (a[i]<0)	a[i]+=mod;}
	}
	for (;a[top]>=mod;top++)	{a[top+1]+=a[top]/mod;a[top]=a[top]%mod;}
	if (a[top]<0)
	{
		for (int i=1;i<top;i++)	a[i]=mod-a[i]-1;
		p=-p;
		if (top==1)	{a[top]=-a[top];return;}
		a[top]++;a[top]=-a[top];a[1]++;
		for (;a[top]==0;)	top--;
		return;
	}
	for (;a[top]<=0&&top>=1;top--)	{a[top+1]-=(-a[top])/mod;a[top]=a[top]%mod;if (a[top]<0)	a[top]+=mod;}
	return;
}
void l_int::print()
{
	if (p==-1)	printf ("-");
	printf ("%d",a[top]);
	for (int i=top-1;i>=1;i--)
		printf ("%d%d%d%d",a[i]/1000%10,a[i]/100%10,a[i]/10%10,a[i]%10);
}

bool l_int::operator <(l_int b)
{return (top!=b.top)?top<b.top:a[top]*p<b.a[top]*b.p;}
bool l_int::operator >(l_int b)
{return (top!=b.top)?top>b.top:a[top]*p>b.a[top]*b.p;}
l_int l_int::operator +(l_int b)
{
	top=max(top,b.top);
	for (int i=1;i<=top;i++)	a[i]+=b.a[i]*b.p*p;
	cls();
	return *this;
}
l_int l_int::operator +(int b)
{
	a[1]+=b*p;
	cls();
	return *this;
}

l_int l_int::operator -(l_int b)
{
	top=max(top,b.top);
	for (int i=1;i<=top;i++)	a[i]-=b.a[i];
	cls();
	return *this;
}
l_int l_int::operator -(int b)
{
	a[1]-=b;
	cls();
	return *this;
}


char x[100];
int main()
{
	freopen("test.txt","r",stdin);
	scanf ("%s",x);
	l_int a(x);
	
	scanf ("%s",x);
	l_int b(x);
	
	scanf ("%s",x);
	l_int c(x);
	
	a+b;
	c-a;
	c.print();
}
