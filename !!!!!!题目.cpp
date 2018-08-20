#include<cstdio>
#include<cstring>

struct node{
	int n;/////µã
	int rws,css;/////ÈÎÎñÍê³ÉÇé¿ö£¬´«ËÍÃÅÇé¿ö£» 
	node(int A=0,int B=0,int C=0){n=A;rws=B;css=C;}
};


const int inf=1<<30;
int n;
int TO[1020];
int NUM[1020];
int POINT[800];

inline int min(int a,int b){return a<b?a:b;}
inline void swap(int &a,int &b){int c=a;a=b;b=c;}


int to[52000],next[52000],w[52000],top=1000+1;
int ljb(int x,int y,int W=1)
{
	top++;
	next[top]=next[x];
	next[x]=top;
	to[top]=y;
	w[top]=W;
}

struct quere
{
	node a[100020];
	int maxn,l,r;
	quere(int n=100010){maxn=n;l=r=0;}
	void put(node x){a[r=(r+1)%maxn]=x;}
	node get(){return a[l=(l+1)%maxn];}
	bool empty(){return (r+1)%maxn==l;}
	void cls(){l=r=0;}
}lie;


int dest[820][130][130];
int p[820][130][130];
void SPFA(int first)
{
	memset(dest,31,sizeof(dest));
	memset(p,0,sizeof(p));
	dest[first][0][0]=0;
	p[first][0][0]=1;
	lie.cls();
	lie.put(first);
	
	for(node x(first);!lie.empty();x=lie.get())
	{
		if (TO[x.n]!=0)/////�д����� 
		{
			if (((1<<(NUM[x.n]-1))&x.rws)!=0)/////��Կ��
			{
				if (dest[TO[x.n]][x.rws][x.css]>dest[x.n][x.rws][x.css])
				{
					dest[TO[x.n]][x.rws][x.css]=dest[x.n][x.rws][x.css];
					if (p[TO[x.n]][x.rws][x.css]!=1)
					{
						p[TO[x.n]][x.rws][x.css]=1;
						lie.put(node(TO[x.n],x.rws,x.css));
					}
				}
			}
			else
			{
				if (((1<<(NUM[x.n]-1))&x.css)==0)/////û�߹�
				{
					if (dest[TO[x.n]][x.rws][x.css|(1<<(NUM[x.n]-1))]>dest[x.n][x.rws][x.css])
					{
						dest[TO[x.n]][x.rws][x.css|(1<<(NUM[x.n]-1))]=dest[x.n][x.rws][x.css];
						if (p[TO[x.n]][x.rws][x.css|(1<<(NUM[x.n]-1))]!=1)
						{
							p[TO[x.n]][x.rws][x.css|(1<<(NUM[x.n]-1))]=1;
							lie.put(node(TO[x.n],x.rws,x.css|(1<<(NUM[x.n]-1))));
						}
					}
					p[x.n][x.rws][x.css]=0;
					continue;
				}
			}
		}
		
		
		if (POINT[x.n]!=0)
		{
			if (((1<<(POINT[x.n]-1))&x.rws)==0)/////ûԿ�� 
			{
				if (dest[x.n][x.rws|(1<<(POINT[x.n]-1))][x.css]>dest[x.n][x.rws][x.css])
				{
					dest[x.n][x.rws|(1<<(POINT[x.n]-1))][x.css]=dest[x.n][x.rws][x.css];
					if (p[x.n][x.rws|(1<<(POINT[x.n]-1))][x.css]!=1)
					{
						p[x.n][x.rws|(1<<(POINT[x.n]-1))][x.css]=1;
						lie.put(node(x.n,x.rws|(1<<(POINT[x.n]-1)),x.css));
					}
				}
				p[x.n][x.rws][x.css]=0;
				continue;
			}
		}
		
		
		for (int j=next[x.n];j!=0;j=next[j])
		{
			if (to[j]==x.n)	break;
			if (dest[x.n][x.rws][x.css]+w[j]<dest[to[j]][x.rws][x.css])
			{
				dest[to[j]][x.rws][x.css]=dest[x.n][x.rws][x.css]+w[j];
				if (p[to[j]][x.rws][x.css]!=1)
				{
					p[to[j]][x.rws][x.css]=1;
					lie.put(node(to[j],x.rws,x.css));
				}
			}
		}
		p[x.n][x.rws][x.css]=0;
	}
}

int dealawerfipaer(int a,int b)
{
	if (a==b)	return a;
	for (int i=0;i<=10;i++)
	{
		bool A=(a&(1<<i))!=0;
		bool B=(b&(1<<i))!=0;
		if (A&&(!B))	return a;
		if ((!A)&&B)	return b;
	}
}

int count(int a)
{
	int s=0;
	for (;a!=0;a=a>>1)	if (a&1!=0)	s++;
	return s;
}

int compler(int a,int b)
{
	int A=count(a),B=count(b);
	if (A==B)	return dealawerfipaer(a,b);
	return A<B?a:b;
}

int m,k,x,y;
int main()
{
	freopen("test.txt","r",stdin);
//	freopen("test.out","w",stdout);
	scanf ("%d %d %d",&n,&m,&k);
	for (int i=1;i<=m;i++)
	{
		scanf ("%d %d",&x,&y);
		ljb(x,y);
	}
	for (int i=1;i<=k;i++)
	{
		scanf ("%d %d",&x,&y);
		TO[x]=y;
		TO[y]=x;
		NUM[x]=NUM[y]=i;
		scanf ("%d",&x);
		POINT[x]=i;
	}
	
	SPFA(1);
	
	int ans=1<<30,ans_s=127;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j+1<=1<<k;j++)/////等待重新理顺序
		{
			if (ans==dest[i][(1<<k)-1][j])	ans_s=compler(ans_s,j);
			if (ans>dest[i][(1<<k)-1][j])
			{
				ans=dest[i][(1<<k)-1][j];
				ans_s=j;
			}
		}
	}
	if (ans>=522133279)
	{
		printf ("NO");
		return 0;
	}
	printf ("YES\n");
	printf ("%d\n",ans);
	if (ans_s==0)	printf ("0");
	for (int i=1;ans_s!=0;ans_s=ans_s>>1)
	{
		if (ans_s&1==1)	printf ("%d ",i);
		i++;
	}
}
