#include<bits/stdc++.h>
using namespace std;

int first(int arr[], int low, int high, int x, int n)
{
  while(high >= low)
  {
    int mid = (low + high)/2;
    if( ( mid == 0 || x > arr[mid-1]) && arr[mid] == x) return mid;
    else if(x > arr[mid])
        //return first(arr, (mid + 1), high, x, n);
        low = mid+1;
    else
        //return first(arr, low, (mid -1), x, n);
        high = mid-1;
  }
  return -1;
}

int last(int arr[], int low, int high, int x, int n)
{
  while(high >= low)
  {
    int mid = (low + high)/2;
    if( ( mid == n-1 || x < arr[mid+1]) && arr[mid] == x ) return mid;
    else if(x < arr[mid])
        //return last(arr, low, (mid -1), x, n);
        high = mid-1;
    else
        //return last(arr, (mid + 1), high, x, n);
        low = mid+1;
  }
  return -1;
}

int count(int arr[], int x, int n)
{
  int i, j;

  i = first(arr, 0, n-1, x, n);

  if(i == -1) return i;

  j = last(arr, i, n-1, x, n);

  return j-i+1;
}

int main()
{
  int arr[] = {1, 2, 2, 3, 3, 3, 3};
  int x = 4;  // Element to be counted in arr[]
  int n = sizeof(arr)/sizeof(arr[0]);
  int c = count(arr, x, n);
  if(c != -1) printf("%d occurs %d times \n", x, c);
  else cout<<x<<" not found"<<endl;
  return 0;
}
