#include<cstdio>


struct quere
{
	int a[1000020],maxn,l,r;
	quere(int n=1000010){maxn=n;l=r=0;}
	void put(int x){a[r=(r+1)%maxn]=x;}
	int get(){return a[l=(l+1)%maxn];}
	bool empty(){return (r+1)%maxn==l;}
	void cls(){l=r=0;}
}lie;


struct trie_node{
	int end;
	int next[27];
	char c;
	int lost;
	trie_node(){end=0;}
};
struct Trie{
	trie_node a[8000000];
	int top;
	Trie(){top=0;}
	void put(char *c,int n);
	int find(char *c,int n);
	void build();
	void travel(char *c);
}trie;
void Trie::put(char *c,int n=0)
{
	for (int i=1;c[i]!=0;i++)
	{
		if (a[n].next[c[i]-'a'+1]!=0)
		{
			n=a[n].next[c[i]-'a'+1];
		}
		else
		{
			n=a[n].next[c[i]-'a'+1]=++top;
			a[top].c=c[i];
		}
	}
	a[n].end++;
	/*
	
	if (c[1]==0){a[n].end++;return;}
	if (a[n].next[c[1]-'a'+1]!=0)	put(c+1,a[n].next[c[1]-'a'+1]);
	else
	{
		a[n].next[c[1]-'a'+1]=++top;
		a[top].c=c[1];
		put(c+1,top);
	}*/
}
int Trie::find(char *c,int n=0)
{
	if (c[1]==0){return a[n].end;}
	if (a[n].next[c[1]-'a'+1]!=0)	return find(c+1,a[n].next[c[1]-'a'+1]);
	return 0;
}
void Trie::build()
{
	lie.put(0);
	for (int x=0;!lie.empty();x=lie.get())
	{
//		printf ("%d  %d\n",x,a[x].end);
		for (int i=1;i<=26;i++)
		{
			if (a[x].next[i]==0)	continue;
//			if (x==0)	{a[a[x].next[i]].lost=0;continue;}
			int j=a[i].lost;
			for (;a[j].lost!=0;j=a[j].lost)
			{
				if (a[j].next[i]!=0)
				{
					a[a[x].next[i]].lost=a[j].next[i];
					break;
				}
			}
			if (j==0)	a[a[x].next[i]].lost=0;
			lie.put(a[x].next[i]);
		}
	}
}

void Trie::travel(char *c)
{
	int now=0;
	int ans=0;
	for (int i=1;c[i]!=0;i++)
	{
//		printf ("*---%d %d\n",now,a[now].end);
		for (;a[now].next[c[i]-'a'+1]==0;now=a[now].lost)
		{
			if (now==0)	break;
			ans+=a[now].end;
		}
//		ans+=a[now].end;
		now=a[now].next[c[i]-'a'+1];
	}
	printf ("*--%d %d \n",now,a[now].end);
	for (;now!=0;now=a[now].lost)	ans+=a[now].end;
	printf ("%lld",ans);
}


int n;
char c[1000020];
int main()
{
	freopen("test.txt","r",stdin);
	scanf ("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf ("%s",c+1);
		trie.put(c);
//		printf ("%s\n",c+1);
	}
	trie.build();
//	printf ("*----END\n");
	scanf ("%s",c+1);
	trie.travel(c);
//	for(;;);
}
