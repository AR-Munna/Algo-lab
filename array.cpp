#include <bits/stdc++.h>
using namespace std;

void sum_of_array(int a[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++) res += a[i];
    cout << "sum: " << res << endl;
}

int sum_of_array_rc(int a[], int n, int i, int sum)
{
    if (i == n) return sum;
    sum += a[i];
    return sum_of_array_rc(a, n, i + 1, sum);
}

void print_array(int a[], int n){
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

void bubble_sort(int a[], int n)
{
    int t;
    for (int i = 0; i < n-1; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i] > a[j]){
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
        print_array(a, n);
    }
}

int binary_search(int a[], int left, int right, int key)
{
    if (right >= left)
    {
        int mid = (left + right) / 2;
        if (key == a[mid]) return mid;
        else if (key < a[mid]) return binary_search(a, left, mid - 1, key);
        else if (key > a[mid]) return binary_search(a, mid + 1, right, key);
    }
    return -1;
}

void delete_element(int a[], int n, int key){
    int index, k=0;
    for(int i=0; i<n; i++){
        if(a[i]==key) continue;
        else{
            a[k] = a[i];
            k++;
        }
    }

    print_array(a, k);
}

void insert_element(int a[], int n, int pos, int key){
    /*jei position e element rakhte hobe, tar porer sob element k 1 ghor kore sorai dilam*/
    for(int i=n; i>pos; i--){
        a[i] = a[i-1];
    }
    a[pos] = key;
    print_array(a, n+1);
}

void insertion_sort(int a[], int n){
    int current_element, j;
    for(int i=1; i<n; i++){
        current_element = a[i];
        j = i-1;
        /* If the element (a[j]) in the sorted array is smaller than the current element,
         then move to the next element. Else, shift greater elements in the array towards the right.*/
        while(current_element<=a[j] && j>=0){
            a[j+1] = a[j];
            j--;
            print_array(a,n);
        }
        //a[i] = a[j];
        cout<<"*\n";
        a[j+1] = current_element;
        
    }
}

main()
{
    int a[] = {3, 4, 1, 5, 2};

    int n = sizeof(a) / sizeof(a[0]);

    //insertion_sort(a, n);

    return 0;
}