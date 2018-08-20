#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<string>
#include<iostream>
#include<ctime>
#include<cctype>

inline int read()
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
	for (int i=1;i<=10000;i++)
	{
		system("test.exe");/////数据生成
		int a;double t1,t2,t;
		t1=clock();
		system("!!!!!!!!猪国杀.exe");/////需验证代码
		t2=clock();
		t=(t2-t1)/1000;
	    	printf ("%d  %.4f\n",i,t);
		if (t>=1.0){
	        puts("TLE\n");/////时间超时
//	    	return 1;
		}
		for (;(t2-t1)/1000<1;t2=clock());
		
		
		system("!!!!!!!!猪国杀____网机.exe");/////暴力代码
		std::ifstream op;
	    std::string str1,str2;
	    op.open("ni.out");/////暴力输出文件
	    while(!op.eof())
	        str1+=op.get();
	    op.close();
	    op.open("ni1.out");/////待验输出文件
	    while(!op.eof())
	        str2+=op.get();
	    op.close();
	    if(str1!=str2){
	        puts("NO\n");/////答案错误
	    	return 1;
		}
	}
	printf ("art");
	return 0;
}
