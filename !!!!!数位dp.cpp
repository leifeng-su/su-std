#include<cstdio>
#include<cstring>

inline long long abs(long long a){return a<0?-a:a;}
inline int abs(int a){return a<0?-a:a;}
inline long long max(long long a,long long b){return a>b?a:b;}
inline int max(int a,int b){return a>b?a:b;}

long long dp[12][12],dp0[12];
void deal()/////预处理
{
	memset(dp,0,sizeof(dp));
	memset(dp0,0,sizeof(dp0));
	for (int i=0;i<=9;i++)	dp[1][i]=1;
	for (int i=2;i<=10;i++)
		for (int j=0;j<=9;j++)
			for (int k=0;k<=9;k++)
				if (abs(k-j)>=2)	dp[i][j]+=dp[i-1][k];
	dp0[1]=1;
	for (int i=2;i<=10;i++)	dp0[i]=dp0[i-1]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+dp[i-1][4]+dp[i-1][5]+dp[i-1][6]+dp[i-1][7]+dp[i-1][8]+dp[i-1][9];
}



int k=0;
int num[12];
void sovel(long long x)/////分解数位
{
	k=0;
	memset(num,0,sizeof(num));
	for (;x>0;x=x/10)	num[++k]=x%10;
	return;
}

long long ask(long long a)/////dp求解
{
	if (a==-1)	return 0;
	if (a==0)	return 1;
	sovel(a);
	long long ans=dp0[k];
	for (int i=k;i>=1;i--)
	{
		if (i==k)	ans-=dp[i][0];
		for (int j=0;j<num[i];j++)
		{
			if (abs(j-num[i+1])>=2||i==k)	ans+=dp[i][j];/////满足条件ans++
		}
		if (abs(num[i]-num[i+1])<=2&&i<k)	return ans;/////之后不满足，剪枝
		if (i==1&&num[i]>=2)	ans++;
//		printf ("%10lld : %lld %d-*\n",a,ans,i);
	}
//	printf ("\n");
//	printf ("\n*---- %lld %lld \n",dp[6][9],dp[5][1]+dp[5][2]+dp[5][3]+dp[5][4]+dp[5][5]+dp[5][6]+dp[5][7]+dp[5][0]);
	return ans;
}



int main()
{
//	freopen("test.txt","r",stdin);
	deal();
	long long a,b;
	scanf ("%lld %lld",&a,&b);
//	printf ("%lld %lld\n",ask(b),ask(a-1));
	printf ("%lld",ask(b)-ask(a-1));
}
