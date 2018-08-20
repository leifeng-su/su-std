#include<cstdio>


struct splay_node
{
	int a,size,lson,rson;
	void set(int A,int B=1,int C=0,int D=0){a=A;size=B;lson=C;rson=D;}
};
1
struct splay{
	splay_node a[1000000];
	int vis[1000000],top;
	void put(int x){vis[++top]=x;}
	splay(){top=0;vis[0]=0;}
	int lson_root(int n);
	int rson_root(int n);
	void swap_to(int n);
	void find(int n,int a);
};
int splay::lson_root(int n)
{
	int m=a[n].lson;
	a[n].lson=a[m].rson;
	a[m].rson=n;
	a[n].size=a[a[n].lson].size+a[a[n].rson].size+1;
	a[m].size=a[a[m].lson].size+a[a[m].rson].size+1;
	return n;
}
int splay::rson_root(int n)
{
	int m=a[n].rson;
	a[n].rson=a[m].lson;
	a[m].lson=n;
	a[n].size=a[a[n].lson].size+a[a[n].rson].size+1;
	a[m].size=a[a[m].lson].size+a[a[m].rson].size+1;
	return m;
}
void splay::swap_to(int n=1)/////1=root
{
	for (;top>=n;top-=2)
	{
		if (top-n<=1)
		{
			if (a[vis[n]].lson==vis[top])
			{
				if (a[vis[n-1]].lson==vis[n])	a[vis[n-1]].lson=lson_root(vis[n]);
					else	a[vis[n-1]].rson=lson_root(vis[n]);
			}
			else
			{
				if (a[vis[n-1]].lson==vis[n])	a[vis[n-1]].lson=rson_root(vis[n]);
					else	a[vis[n-1]].rson=rson_root(vis[n]);
			}
			top=n;
			return;
		}
		if (a[vis[top-3]].lson==vis[top-2])
		{
			if (a[vis[top-2]].lson==vis[top-1])
			{
				if (a[vis[top-1]].lson==vis[top])
				{
					lson_root(vis[top-2]);
					a[vis[top-3]].lson=lson_root(vis[top-1]);
				}
				else
				{
					rson_root(vis[top-1]);
					a[vis[top-3]].lson=lson_root(vis[top-2]);
				}
			}
			else
			{
				if (a[vis[top-1]].lson==vis[top])
				{
					lson_root(vis[top-1]);
					a[vis[top-3]].lson=rson_root(vis[top-2]);
				}
				else
				{
					rson_root(vis[top-2]);
					a[vis[top-3]].lson=rson_root(vis[top-1]);
				}
			}
		}
		else
		{
			if (a[vis[top-2]].lson==vis[top-1])
			{
				if (a[vis[top-1]].lson==vis[top])
				{
					lson_root(vis[top-2]);
					a[vis[top-3]].rson=lson_root(vis[top-1]);
				}
				else
				{
					rson_root(vis[top-1]);
					a[vis[top-3]].rson=lson_root(vis[top-2]);
				}
			}
			else
			{
				if (a[vis[top-1]].lson==vis[top])
				{
					lson_root(vis[top-1]);
					a[vis[top-3]].rson=rson_root(vis[top-2]);
				}
				else
				{
					rson_root(vis[top-2]);
					a[vis[top-3]].rson=rson_root(vis[top-1]);
				}
			}
		}
		vis[top-2]=vis[top];
	}
}


int splay::find(int n,int a)
{
	
}




int main()
{
	freopen("test.txt","r",stdin);

}