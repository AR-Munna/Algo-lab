#include<bits/stdc++.h>
using namespace std;

float MO2(int a, int b)
{
    return (a+b)/2.0;
}

float MO3(int a, int b, int c)
{
    return a+b+c - max(a, max(b,c)) - min(a, min(b,c));
}

float MO4(int a, int b, int c, int d)
{
    int max_x = max(a, max(b, max(c,d)));
    int min_n = min(a, min(b, min(c,d)));

    return (a+b+c+d-max_x-min_n);
}

float medianSingle(int a[], int n)
{
    if(n==0) return -1;
    if(n%2==0) return (a[n/2]+a[n/2-1])/2.0;
    return a[n/2];
}

float findMedianUtil(int a[], int n, int b[], int m)
{
    if(n==0) return medianSingle(b,m);

    if(n==1)
    {
        if(m==1) return MO2(a[0],b[0]);
        if(m&1) return MO2(b[m/2], MO3(a[0], b[m/2+1], b[m/2-1]));
        return MO3(b[m/2], b[m/2-1], a[0]);
    }

    else if(n==2)
    {
        if(m==2) return MO4(a[0], a[1], b[0], b[1]);
        if(m&1) return MO3(b[m/2], max(a[0],b[m/2-1]), min(a[1], b[m/2+1]));
        return MO4(b[m/2], b[m/2-1], max(a[0], b[m/2-2]), min(a[1], b[m/2+1]));
    }

    int idxA = (n-1)/2;
    int idxB = (n-1)/2;

    if(a[idxA] <= b[idxB]) return findMedianUtil(a+idxA, n/2+1, b, m-idxA);
    return findMedianUtil(a, n/2+1, b + idxA, m-idxA);
}

float findMedian(int a[], int n, int b[], int m)
{
    if(n>m) return findMedianUtil(b, m, a, n);
    return findMedianUtil(a, n, b, m);
}

main()
{
    int n, m;

    /*
    cin>>n>>m;

    int a[n], b[m];

    for(int i=0; i<n; i++) cin>>a[i];

    for(int i=0; i<m; i++) cin>>b[i];

    */

    int A[] = {900};
    int B[] = {5, 8, 10, 20};

    int N = sizeof(A) / sizeof(A[0]);
    int M = sizeof(B) / sizeof(B[0]);

    printf("%f", findMedian( A, N, B, M ) );

    return 0;
}
