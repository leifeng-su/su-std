#include<cstdio>
#include<cstring>

const int inf=1<<30;
int n=200020,m;

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

struct stack{
    int a[200020],top;
    void put(int x){a[++top]=x;}
    int get(){return a[top--];}
    bool empty(){return top!=0;}
    void cls(){top=0;}
    stack(){top=0;}
}lid;

struct LIE{
    int first,end;
    int lie[200020];
    void put(int x){lie[end=(end+1)%200010]=x;}
    int get(){return lie[first=(first+1)%200010];}
    bool empty(){return first==(end+1)%200010;}
    LIE(){first=end=0;memset(lie,0,sizeof(lie));}
    void cls(){first=end=0;}
}lie;


int to[600030],next[600030],w[600030],top=200020+1;
int ljb(int x,int y,int W)
{
    top++;
    next[top]=next[x];
    next[x]=top;
    to[top]=y;
    w[top]=W;
}


int dest[200020];
int p[200020],vis[200020];
bool SPFA(int first)
{
    memset(dest,127,sizeof(dest));
    memset(p,0,sizeof(p));
    memset(vis,0,sizeof(vis));
    dest[first]=0;
    p[first]=1;
    lie.cls();
    lie.put(first);
    
    for(int x=first;!lie.empty();x=lie.get())
    {
    	if (dest[first]<0)	return true;	
        for (int j=next[x];j!=0;j=next[j])
        {
            if (dest[x]+w[j]<dest[to[j]])
            {
                dest[to[j]]=dest[x]+w[j];
                if (p[to[j]]!=1)
                {
                    p[to[j]]=1;
                    if (vis[to[j]]>=n)	return true;
                    vis[to[j]]++;
                    lie.put(to[j]);
                }
            }
        }
        p[x]=0;
    }
    return false;
}

bool SPFA_dfs(int first)
{
    memset(dest,31,sizeof(dest));
    memset(p,0,sizeof(p));
    memset(vis,0,sizeof(vis));
    dest[first]=0;
    p[first]=1;
    lid.cls();
    lid.put(first);
    
    for(int x=first;!lid.empty();x=lid.get())
    {
    	if (dest[first]<0)	return true;
		for (int j=next[x];j!=0;j=next[j])
        {
            if (dest[x]+w[j]<dest[to[j]])
            {
                dest[to[j]]=dest[x]+w[j];
                if (p[to[j]]!=1)
                {
                    p[to[j]]=1;
                    lid.put(to[j]);
                }
            }
        }
        p[x]=0;
    }
    return false;
}

void work()
{
    memset(next,0,sizeof(next));
    top=200021;
    n=read();m=read();
    for (int i=1;i<=m;i++)
    {
        int x,y,w;
        x=read();y=read();w=read();
        ljb(x,y,w);
        if (w>0)	ljb(y,x,w);
    }
    printf ("%s\n",SPFA(1)?"YE5":"N0");
}

int main()
{
//	freopen("test.txt","r",stdin);
    int T;
    scanf ("%d",&T);
    for (int i=1;i<=T;i++)	work();
    
}
