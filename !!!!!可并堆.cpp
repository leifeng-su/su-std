#include<cstdio>

void swap(int &a,int &b){int c=a;a=b;b=c;}

struct deap_node{
	int a,dis,lson,rson;
	deap_node(){dis=a=lson=rson=0;}
};

struct deap{/////×óÆ«Ê÷ 
	deap_node tree[1000020];
	int top,root;
	deap(){top=0;root=0;}
	int merge(int a,int b);
	void put(int c);
	void del();
	void change(int z);
};
int deap::merge(int a,int b)
{
	if (a==0)	return b;
	if (b==0)	return a;
	if (tree[a].a<tree[b].a)	swap(a,b);
	tree[a].rson=merge(tree[a].rson,b);
	if (tree[tree[a].lson].dis<tree[tree[a].rson].dis)	swap(tree[a].lson,tree[a].rson);
	tree[a].dis=tree[tree[a].rson].dis+1;
	return a;
}
void deap::put(int c)
{
	top++;
	tree[top].a=c;
	root=merge(top,root);
}
void deap::del()
{root=merge(tree[root].lson,tree[root].rson);}
void deap::change(int z)
{
	tree[root].a=z;
	int x=root;
	root=merge(tree[root].lson,tree[root].rson);
	root=merge(root,x);
}


int main()
{
	freopen("test.txt","r",stdin);
	
	
	
}
