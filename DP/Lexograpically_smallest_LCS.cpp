#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;

// Define Some Variables
#define eps 1e-14
#define si 105
#define pi acos(-1.0)
#define inf (1<<30)-1
#define mod 1000000000 //10^9

//Define Some Functions
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

typedef long long i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int i,j,l,n,cs=1,l1,l2;
char ch1[si],ch2[si],res[si],dpc[si][si][si];
int dp[si][si];

i64 bmod(i64 a,i64 b)
{
    if(b==0)
        return 1;
    i64 x=bmod(a,b/2);
    x=(x*x)%mod;
    if(b%2==1)
        x=(x*a)%mod;
    return x;
}

int gcd(int a,int b)
{
    while(b>0)
    {
        a%=b;
        a^=b;
        b^=a;
        a^=b;
    }
    return a;
}


i64 lcm(i64 a,i64 b)
{
	return ((a*b)/gcd(a,b));
}

int rec(int i,int j,char* res)
{
    if(i==l1||j==l2)
    return 0;
    int &ret=dp[i][j];
    if(ret!=-1)
    {
        strcpy(res,dpc[i][j]);
        return ret;
    }

    int p,q,ll,x;
    char st1[si],st2[si];
    if(ch1[i]==ch2[j])
    {
        ret=1+rec(i+1,j+1,res);
        st1[0]=ch1[i];
        ll=strlen(res);
        rep(x,0,ll)
        st1[x+1]=res[x];
        st1[ll+1]=0;
        strcpy(res,st1);
        strcpy(dpc[i][j],res);
    }
    else
    {
        strcpy(st2,res);

        p=rec(i+1,j,res);
        strcpy(st1,res);

     //   strcpy(res,st2);
        q=rec(i,j+1,st2);
     //   strcpy(st2,res);

        if(p>q)
        strcpy(res,st1);
        else if(p<q)
        strcpy(res,st2);
        else
        {
            p=strcmp(st1,st2);
            if(p<0)
            strcpy(res,st1);
            else
            strcpy(res,st2);
        }

        ret=max(p,q);
        strcpy(dpc[i][j],res);
    }
    return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int t;
    scanf("%d",&t);
   	while(t--)
   	{
   	    scanf("%s%s",&ch1,ch2);
   	    l1=strlen(ch1);
   	    l2=strlen(ch2);
		mem(dp,-1);
		res[0]=0;
		int ans=rec(0,0,res);
		printf("Case %d: ",cs++);
		if(ans==0)
		puts(":(");
		else
        puts(res);
    }
   	return 0;
}
