#include<bits/stdc++.h>
using namespace std;

#define MX 1005
vector<int>v;
int a[MX],value[MX],indx[MX];

int main()
{
    int n,i,lo,hi,mid,l=0,start;
    scanf("%d",&n);
    for(i=0; i<n; i++)  scanf("%d",&a[i]);
    fill(value,value+MX,INT_MAX);
    value[0] = INT_MIN;
    for(i=0; i<n; i++)
    {
        lo = 0;
        hi = l;
        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            if(value[mid]<a[i]) lo = mid+1;
            else    hi = mid-1;
        }
        value[lo] = a[i];
        indx[i] = lo;
        if(l<lo)    l = lo;
    }
    i = n-1;
    while(l)
    {
        if(indx[i]==l && (v.size()==0 || v[v.size()-1]>a[i]))
        {
            v.push_back(a[i]);
            l--;
            if(l==0)    start = i;
        }
        i--;
    }
    reverse(v.begin(),v.end());
    printf("Length of longest increasing subsequence is %d and starting position is %d\n",v.size(),start);
    for(i=0; i<v.size(); i++)
    {
        if(i)   printf(" ");
        printf("%d",v[i]);
    }
    puts("");
    return  0;
}

/**
7
5 0 9 2 7 3 4
*/

