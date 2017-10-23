#include<bits/stdc++.h>
using namespace std;
int b[205][205];
int dp[505][505], n;

int dpfn(int i, int j)
{
    if(i>2*n-1) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int x, y, ans=0;

    if(i<n-1)
    {
        x = b[i][j] + dpfn(i+1,j+1);
        y = b[i][j] + dpfn(i+1, j);
        ans += max(x,y);
    }

    else
    {
        x = b[i][j] + dpfn(i+1,j-1);
        y = b[i][j] + dpfn(i+1, j);
        ans += max(x,y);
    }

    return dp[i][j] = ans;
}

main()
{
    int t;

    cin>>t;

    for(int tc=1; tc<=t; tc++)
    {
        memset(dp, -1, sizeof(dp));
        memset(b, 0, sizeof(b));

        cin>>n;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++) cin>>b[i][j];
        }

        int l = 2*n-1;

        for(int i=n; i<l; i++)
        {
            for(int j=0; j<l-i; j++) cin>>b[i][j];
        }

        cout<<"Case "<<tc<<": "<<dpfn(0,0)<<endl;
    }

    return 0;
}
