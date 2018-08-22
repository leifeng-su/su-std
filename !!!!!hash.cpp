#include<cstring>
#include<cstdio>

struct hush_map{
	int key[2000209];
	int next[2000209],mod,top;
	hush_map(){mod=1000003;top=1000004;}
	void cls();
	int deal(int a){return a<0?(-a)%mod:a%mod;}
	void in_put(int a);
	bool find(int a);
}map;
void hush_map::cls()
{
	memset(key,0,sizeof(key));
	memset(next,0,sizeof(next));
	mod=1000003;
	top=1000004;
}
void hush_map::in_put(int a)
{
	int x=deal(a);
	key[top]=a;
	next[top]=next[x];
	next[x]=top++;
}
bool hush_map::find(int a)
{
	for (int i=deal(a);i!=0;i=next[i])
		if (key[i]==a)	return true;
	return false;
}


int main()
{
	
	
	
}
