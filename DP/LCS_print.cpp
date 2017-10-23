#include<bits/stdc++.h>
using namespace std;

#define MX 1005
char str1[MX],str2[MX];
int dp[MX][MX];
string str;

int solve(int i,int j)
{
    if(!str1[i] || !str2[j])    return  0;
    else if(dp[i][j]!=-1)   return  dp[i][j];
    int res=0;
    if(str1[i]==str2[j])    res = 1+solve(i+1,j+1);
    else    res = max(solve(i+1,j),solve(i,j+1));
    dp[i][j] = res;
    return  dp[i][j];
}

void lcs(int i,int j)
{
    if(!str1[i] || !str2[j])    return;
    if(str1[i]==str2[j])
    {
        str += str1[i];
        lcs(i+1,j+1);
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1])   lcs(i+1,j);
        else    lcs(i,j+1);
    }
}

int main()
{
    gets(str1);
    gets(str2);
    memset(dp,-1,sizeof(dp));
    printf("Length of longest common subsequence: %d\n",solve(0,0));
    lcs(0,0);
    cout << str << endl;
    return  0;
}
