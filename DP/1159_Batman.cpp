#include<bits/stdc++.h>
using namespace std;

string s1, s2, s3;
int dp[55][55][55], ln1, ln2, ln3;

int lcs(int i, int j, int k)
{
    if(i>=ln1 || j>=ln2 || k>=ln3) return 0;

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    int ans=0;

    if(s1[i]==s2[j] && s1[i]==s3[k]) ans = 1+lcs(i+1, j+1, k+1);

    else ans = max(lcs(i+1,j,k), max(lcs(i,j+1,k), lcs(i,j,k+1)));

    return dp[i][j][k] = ans;
}

main()
{
    int test;
    cin>>test;

    for(int tc=1; tc<=test; tc++)
    {
        cin>>s1>>s2>>s3;

        ln1 = s1.length();
        ln2 = s2.length();
        ln3 = s3.length();

        memset(dp, -1, sizeof(dp));

        cout<<"Case "<<tc<<": "<<lcs(0,0,0)<<endl;

        s1="";
        s2="";
        s3="";
    }

    return 0;
}

