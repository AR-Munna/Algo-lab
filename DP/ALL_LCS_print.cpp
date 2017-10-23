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

void all_lcs(int i,int j)
{
    if(!str1[i] || !str2[j])
    {
        cout << str << endl;
        return;
    }
    if(str1[i]==str2[j])
    {
        str += str1[i];
        all_lcs(i+1,j+1);
        str.erase(str.end()-1);
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1])  all_lcs(i+1,j);
        else if(dp[i+1][j]<dp[i][j+1])  all_lcs(i,j+1);
        else
        {
            all_lcs(i+1,j);
            all_lcs(i,j+1);
        }
    }
}

int main()
{
    gets(str1);
    gets(str2);
    memset(dp,-1,sizeof(dp));
    solve(0,0);
    all_lcs(0,0);
    return  0;
}
