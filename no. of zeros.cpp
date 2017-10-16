#include<bits/stdc++.h>
using namespace std;

int zeroCounter(int a[], int low, int high)
{
    int n = high;

    while(high>=low)
    {
        int mid = (low+high)/2;

        if(a[mid]==0 && (a[mid+1]==1 || mid==n)) return mid;

        else if(a[mid]>0) high = mid-1;

        else low = mid+1;
    }
    return -1;
}
main()
{
    int a[] = {1, 1,1,0, 1, 1};

    int n = sizeof(a)/sizeof(a[0]);

    sort(a, a+n);

    int c = zeroCounter(a, 0, n-1);

    if(c!=-1) cout<<"zero's count : "<<c+1<<endl;

    else cout<<"Not found"<<endl;

    return 0;
}
