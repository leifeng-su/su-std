#include<cstdio>

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

struct FENSHU
{
	int x,y;
	void sure(){int z=gcd(x,y);x=x/z;y=y/z;}
	FENSHU(int a=0,int b=1){x=a;y=b;sure();}
};
FENSHU operator +(FENSHU a,FENSHU b)
{
	a.x=a.x*b.y;
	b.x=b.x*a.y;
	a.y=a.y*b.y;
	a.x=a.x+b.x;
	a.sure();
	return a;
}

FENSHU operator -(FENSHU a,FENSHU b)
{
	a.x=a.x*b.y;
	b.x=b.x*a.y;
	a.y=a.y*b.y;
	a.x=a.x-b.x;
	a.sure();
	return a;
}

FENSHU operator *(FENSHU a,FENSHU b)
{
	a.x=a.x*b.x;
	a.y=a.y*b.y;
	a.sure();
	return a;
}

FENSHU operator /(FENSHU a,FENSHU b)
{
	a.x=a.x*b.y;
	a.y=a.y*b.x;
	a.sure();
	return a;
}




int main()
{
	
}