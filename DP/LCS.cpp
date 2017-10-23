#include<bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[1005][1005], ln1, ln2;

int lcs(int posOfs1, int posOfs2)
{
    if(posOfs1>=ln1 || posOfs2>=ln2) return 0;

    if(dp[posOfs1][posOfs2]!=-1) return dp[posOfs1][posOfs2];

    int ans=0;

    if(s1[posOfs1]==s2[posOfs2]) ans = 1+lcs(posOfs1+1, posOfs2+1);

    else ans = max(lcs(posOfs1+1,posOfs2), lcs(posOfs1, posOfs2+1));

    return dp[posOfs1][posOfs2] = ans;
}

main()
{
    while(getline(cin,s1))
    {
        getline(cin,s2);

        ln1 = s1.length();
        ln2 = s2.length();

        memset(dp, -1, sizeof(dp));

        cout<<lcs(0,0)<<endl;

        s1="";
        s2="";
    }

    return 0;
}
