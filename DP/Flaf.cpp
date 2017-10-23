#include<bits/stdc++.h>
using namespace std;
long long dp[55][3];

long long dpfn(int n, int color)
{
    //color=0[white], color=1[red], color=2[blue];

    if(n<=0) return 0;

    if(n==1)
    {
        if(color==2) return 0;
        else return 1;
    }

    if(dp[n][color]!=-1) return dp[n][color];

    if(color == 2) dp[n][color] = dpfn(n-1, 0)+dpfn(n-1, 1);
    else if(color == 1) dp[n][color] = dpfn(n-1, 0)+dpfn(n-2, 0);
    else if(color == 0) dp[n][color] = dpfn(n-1, 1)+dpfn(n-2, 1);

    return dp[n][color];
}

main()
{
    int n;

    memset(dp, -1, sizeof(dp));

    cin>>n;

    cout<<dpfn(n,0)+dpfn(n,1)<<endl;

    return 0;
}
