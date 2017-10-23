#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

string s;

int dpfn(int l, int r)
{
    if(l==r) return 0;

    if(dp[l][r]!=-1) return dp[l][r];

    if(l+1 == r)
    {
        if(s[l]==s[r]) return 0;
        return 1;
    }

    if(s[l]!=s[r])
    {
        int x = 1+dpfn(l+1, r);
        int y = 1+dpfn(l, r-1);
        int z = 1+dpfn(l+1,r-1);

        return dp[l][r] = min(x, min(y, z));
    }

    return dp[l][r] = dpfn(l+1, r-1);
}

main()
{
    int test;

    cin>>test;

    for(int tc=1; tc<=test; tc++)
    {
        memset(dp, -1, sizeof(dp));

        cin>>s;

        int ln = s.length()-1;

        cout<<"Case "<<tc<<": "<<dpfn(0,ln)<<endl;
    }

    return 0;
}
