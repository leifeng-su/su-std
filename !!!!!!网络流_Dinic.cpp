#include<cstdio>
#include<cstring>

inline int min(int a,int b){return a<b?a:b;}

int to[800020],next[800020],w[800020],top=100020+1;
int ljb(int x,int y,int W)
{
	top++;
	next[top]=next[x];
	next[x]=top;
	to[top]=y;
	w[top]=W;
}

struct quere{
	int l,r,maxn;
	int a[100020];
	void put(int x){a[(++r)%maxn]=x;}
	int get(){return a[(++l)%maxn];}
	bool empty(){return l==(r+1)%maxn;}
	int cls(){memset(a,0,sizeof(a));l=r=0;}
	quere(){l=r=0;maxn=100010;}
}lie;

int D[100020],s,t;
bool bfs_liu(int s,int t)
{
	lie.cls();
	memset(D,0,sizeof(D));
	lie.put(s);
	D[s]=1;
	for (int i=lie.get();!lie.empty();i=lie.get())
	{
		for (int j=next[i];j!=0;j=next[j])
		{
			if (w[j]>0&&D[to[j]]==0)
			{
				D[to[j]]=D[i]+1;
				lie.put(to[j]);
			}
		}
	}
	return D[t]>0;
}
int dfs(int i,int t,int dest)
{
	if (i==t)	return dest;
	for (int j=next[i];j!=0;j=next[j])
	{
		if (D[to[j]]==D[i]+1&&w[j]!=0)
		{
			int d=dfs(to[j],t,min(dest,w[j]));
			if (d>0)
			{
				w[j]-=d;
				w[j^1]+=d;
				return d;
			}
		}
	}
	return 0;
}

int Dicnic()
{
	int ans=0;
	for (;bfs_liu(s,t);)
	{
		int x;
		for (;(x=dfs(s,t,1<<30))!=0;)	ans+=x;
	}
	return ans;
}


int n,m;
int main()
{
//	freopen("test.txt","r",stdin);
	scanf ("%d %d %d %d",&n,&m,&s,&t);
	for (int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		ljb(a,b,c);
		ljb(b,a,0);
	}
	printf ("%d",Dicnic());
}

/*
class Graph
{
private:
    int s,t;
    int cnt;
    int Head[maxN];
    int Next[maxM];
    int V[maxM];
    int W[maxM];
    int Depth[maxN];
public:
    int n;
    void init(int nn,int ss,int tt)//初始化
        {
            n=nn;
            s=ss;
            t=tt;
            cnt=-1;
            memset(Head,-1,sizeof(Head));
            memset(Next,-1,sizeof(Next));
            return;
        }
    void _Add(int u,int v,int w)
        {
            cnt++;
            Next[cnt]=Head[u];
            V[cnt]=v;
            W[cnt]=w;
            Head[u]=cnt;
        }
    void Add_Edge(int u,int v,int w)//加边，同时加正向和反向的
        {
            _Add(u,v,w);
            _Add(v,u,0);
        }
    int bfs()
        {
            //cout<<"Bfs.begin:"<<endl;
            queue<int> Q;
            while (!Q.empty())
                Q.pop();
            memset(Depth,0,sizeof(Depth));
            Depth[s]=1;
            Q.push(s);
            do
            {
                int u=Q.front();
                //cout<<u<<endl;
                Q.pop();
                for (int i=Head[u];i!=-1;i=Next[i])
                {
                    if ((W[i]>0)&&(Depth[V[i]]==0))
                    {
                        Depth[V[i]]=Depth[u]+1;
                        Q.push(V[i]);
                    }
                }
            }
            while (!Q.empty());
            //cout<<"Bfs.end"<<endl;
            if (Depth[t]>0)
                return 1;
            return 0;
        }
    int Dinic()
        {
            int Ans=0;
            while (bfs())
            {
                while (int d=dfs(s,inf))
                    Ans+=d;
            }
            return Ans;
        }
};*/
