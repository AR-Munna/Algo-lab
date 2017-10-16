#include<bits/stdc++.h>
using namespace std;

int pointFind(int a[], int low, int high)
{
    while(high>=low)
    {
        int mid = (low+high)/2;

        if(a[mid]==mid) return mid;

        else if(a[mid]>mid) high = mid-1;

        else low = mid+1;
    }

    return -1;
}

main()
{
    int a[] = {-10, -5, 2, 6, 7};

    int c;

    c = pointFind(a, 0, 4);

    if(c!=-1) cout<<"Fixed point is "<<c<<endl;

    else cout<<"No fixed point"<<endl;

    return 0;
}
