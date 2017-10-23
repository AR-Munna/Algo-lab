#include<bits/stdc++.h>
using namespace std;

main()
{
    int test;

    cin>>test;

    for(int tc=1; tc<=test; tc++)
    {
        int n;

        cin>>n;

        int a[n][3];

        for(int i=0; i<n; i++) cin>>a[i][0]>>a[i][1]>>a[i][2];

        for(int i=1; i<n; i++)
        {
            a[i][0] += min(a[i-1][1], a[i-1][2]);
            a[i][1] += min(a[i-1][0], a[i-1][2]);
            a[i][2] += min(a[i-1][1], a[i-1][0]);
        }
        /*
        puts("");
        for(int i=0; i<n; i++)
            cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<endl;
        */

        int ans = min(a[n-1][0], min(a[n-1][1], a[n-1][2]));

        cout<<"Case "<<tc<<": "<<ans<<endl;
    }

    return 0;
}
