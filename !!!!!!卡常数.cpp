#include<cstdio>
#include <ctime>
//////////////////////////////////////////////////////o2大法好 
//#pragma GCC optimize(2)
//////////////////////////////////////////////////////


/////神主保佑
/////东方灵异传
/////东方封魔录
/////东方梦时空
/////东方幻想乡
/////东方怪绮谈
/////东方红魔乡
/////东方妖妖梦
/////东方永夜抄
/////东方花映塚
/////东方风神录
/////东方地灵殿
/////东方星莲船
/////东方神灵庙
/////东方辉针城
/////东方绀珠传
/////东方天空璋


inline int f1(int a)
{
	int b=a;
	a=b;
}

int f2(int a)
{
	int b=a;
	a=b;
}

inline int read1()
{
	char c;bool f=false;int a=0;
	for (;!((((c=getchar())>='0')&&(c<='9'))||(c=='-')););
	if (c=='-')	f=true;
		else	{a=c-'0';}
	for (;(c=getchar())>='0'&&c<='9';)
	{a=a*10+c-'0';}
	return f?-a:a;
}

int read2()
{
	char c;bool f=false;int a=0;
	for (;!((((c=getchar())>='0')&&(c<='9'))||(c=='-')););
	if (c=='-')	f=true;
		else	{a=c-'0';}
	for (;(c=getchar())>='0'&&c<='9';)
	{a=a*10+c-'0';}
	return f?-a:a;
}

int main()
{
	double t1,t2,t;
	
/*	t1=clock();
	for (register int i=1;i<=100000000;i++);
	t2=clock();
	t=(t2-t1)/1000;
	printf ("register 卡常：%.4lf\n",t);
	t1=clock();
	for (int i=1;i<=100000000;i++);
	t2=clock();
	t=(t2-t1)/1000;
	printf ("register 不卡：%.4lf\n",t);
	
	t1=clock();
	for (int i=1;i<=100000000;++i);
	t2=clock();
	t=(t2-t1)/1000;
	printf ("++前置 卡常：%.4lf\n",t);
	t1=clock();
	for (int i=1;i<=100000000;i++);
	t2=clock();
	t=(t2-t1)/1000;
	printf ("++后置 不卡：%.4lf\n",t);
	
	bool a1=false;
	int a2=1;
	t1=clock();
	for (int i=1;i<=100000000;i++)	a1?1:2;
	t2=clock();
	t=(t2-t1)/1000;
	printf ("bool 比较 卡常：%.4lf\n",t);
	t1=clock();
	for (int i=1;i<=100000000;i++)	a2?1:2;
	t2=clock();
	t=(t2-t1)/1000;
	printf ("int  比较 不卡：%.4lf\n",t);
	
	t1=clock();
	for (int i=1;i<=100000000;i++)	f1(i);
	t2=clock();
	t=(t2-t1)/1000;
	printf ("inline 函数 卡常：%.4lf\n",t);/////迷之较慢 
	t1=clock();
	for (int i=1;i<=100000000;i++)	f2(i);
	t2=clock();
	t=(t2-t1)/1000;
	printf ("inline 函数 不卡：%.4lf\n",t);
	*/
	
	int a;
	freopen("test.txt","r",stdin);
	t1=clock();
	for (int i=1;i<=10000000;i += 4)
	{
		a = i;
		a = i+1;
		a = i+2;
		a = i+3;
	}
	t2=clock();
	t=(t2-t1)/1000;
	printf ("inline 函数 卡常：%.4lf\n",t);
	freopen("test.txt","r",stdin);
	t1=clock();
	for (int i=1;i<=10000000;i++)	a=i;
	t2=clock();
	t=(t2-t1)/1000;
	printf ("inline 函数 不卡：%.4lf\n",t);
}
