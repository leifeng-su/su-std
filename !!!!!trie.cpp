#include<cstdio>

struct trie_node{
	int end;
	int next[27];
	trie_node(){end=0;}
};
struct trie{
	trie_node a[1000020];
	int top;
	trie(){top=0;}
	
	void put(char *c,int n);
	int find(char *c,int n);
};
void trie::put(char *c,int n=0)
{
	if (c[1]==0){a[n].end++;return;}
	if (a[n].next[c[1]-'a'+1]!=0)	put(c+1,a[n].next[c[1]-'a'+1]);
	else
	{
		a[n].next[c[1]-'a'+1]=++top;
		put(c+1,top);
	}
}
int trie::find(char *c,int n=0)
{
	if (c[1]==0){return a[n].end;}
	if (a[n].next[c[1]-'a'+1]!=0)	return find(c+1,a[n].next[c[1]-'a'+1]);
	return 0;
}

int main()
{
	freopen("test.txt","r",stdin);
	
	
}
