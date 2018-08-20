#include<cstdio>
#include<stdlib.h> 
#include<ctime>



void exgcd(int a,int b,int &c,int &x,int &y)
{
	if (b==0){x=1,y=0;c=a;return;}
	exgcd(b,a%b,c,y,x);y-=a/b*x;
}

int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int r=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return r;
}

void EXgcd(int a,int b,int &c,int &x,int &y)/////ax=1(mod b)
{
	if (b==0){x=1;y=0;c=a;}/////a*x+b*y=c;
	else{EXgcd(b,a%b,c,y,x);y-=x*(a/b);}
}
///////////////(a/b)(mod m)=(a*x)(mod m)------EXgcd(b,f,1,x,y);-----!!!!!b”Îfª•÷ 

int main()
{
	
	
	
}
