#include<cstdio>


struct tree_node{int a,ls,rs,lazy;};

struct tree
{
	tree_node tree[100000];
	int top;
	int head;
	void add(int a);
	bool find(int a);
	void del(int a);
}tree;
void tree::add(int a)
{
	if (head==0)	{head=top++;tree[head].a=a;return;}
	for (int i=head;i!=0;)
	{
		if (a>tree[i].a)
		{
			if (tree[i].rs==0)
			{
				tree[i].rs=++top;
				tree[top].a=a;
				break;
			}
			else	i=tree[i].rs;
		}
		else
		{
			if (tree[i].ls==0)
			{
				tree[i].ls=++top;
				tree[top].a=a;
				break;
			}
			else	i=tree[i].ls;
		}
	}
}
bool tree::find(int a)
{
	for (int i=head;i!=0;)
	{
		if (tree[i].a==a&&tree[i].lazy==0)	return true;
		if (a>tree[i].a)	i=tree[i].rs;
			else	i=tree[i].ls;
	}
	return false;
}
void tree::del(int a)
{
	for (int i=head;i!=0;)
	{
		if (tree[i].a==a&&tree[i].lazy==0)
		{tree[i].lazy=1;return;}
		if (a>tree[i].a)	i=tree[i].rs;
			else	i=tree[i].ls;
	}
}



int main()
{
	freopen("test.txt","r",stdin);
	for(;;);
}