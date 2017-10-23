#include<bits/stdc++.h>
using namespace std;

long long dp[1005][1005];

long long dpfn(long long left, long long cur)
{
    if(left<0) return 0;

    if(left==0) return 1;

    long long ans = 0;

    if(dp[left][cur]!=-1) return dp[left][cur];

    ans += dpfn(left-1, cur+1) + dpfn(left-cur-1, cur+1);

    return dp[left][cur] = ans;
}

main()
{
    long long n, t;

    memset(dp, -1, sizeof(dp));

    scanf("%lld", &n);

    printf("%lld\n", dpfn(n-1,1)-1);

    return 0;
}
