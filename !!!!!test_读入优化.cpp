#include<cstdio>
#include<iostream>
using namespace std;
#include <cctype>
#include <ctime>
#define aaa ch-'0'
#define P(a) while(a isdigit(c=getchar()))
void U(int &x) {int c;P(!);x=c-48;P()x=x*10+c-48;}

inline void get(int &x)
{
	char ch;
	while(!isdigit(ch=getchar()));
	for(x=aaa;isdigit(ch=getchar());x=x*10+aaa);
}

inline int read()
{
	char c;bool f=false;int a=0;
	for (;(!(((c=getchar())>='0')&&(c<='9'))||(c=='-')););
	if (c=='-')	f=true;
		else	{a=c-'0';}
	for (;(c=getchar())>='0'&&c<='9';)
	{a=a*10+c-'0';}
	return f?-a:a;
}


inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int _read(){
    char ch=nc();int sum=0;
    while(!isdigit(ch=nc()))
    while(isdigit(ch=nc()))sum=sum*10+ch-48;
    return sum;
}


int main()
{
	double t1,t2;
//	ios::sync_with_stdio(false);
	freopen("test.txt","r",stdin);
	int a,n,b;
	t1=clock();
	n=read();
	for (int i=1;i<=n;i++)
//		get(a);
//		a=read();
//		a=_read();
//		scanf ("%d",&a);
//		U(a);
		std::cin>>a>>b;
//		cin>>a;
	t2=clock();
//	printf ("# get:%.4lf",(t2-t1)/1000);
//	printf ("#read:%.4lf",(t2-t1)/1000);
//	printf ("scanf:%.4lf",(t2-t1)/1000);
//	printf ("#  U:%.4lf",(t2-t1)/1000);
//	printf ("#cin:%.4lf",(t2-t1)/1000);
	printf ("_read:%.4lf",(t2-t1)/1000);
}
