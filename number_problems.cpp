#include<bits/stdc++.h>
using namespace std;

int palindrome_checker_bf(int n, int digit){
    int reverse_number=0, copied_number=n;
    for(int i=digit-1; i>=0; i--){
        reverse_number += (n%10)*pow(10, i);
        n = n/10;
    }
    cout<<reverse_number<<endl;
    if(copied_number==reverse_number) return 1;
    else return 0;
}

int palindrome_checker_recursion(int n, int copied_number, int reverse_number, int digit){
    if(digit<0 && copied_number!=reverse_number) return 0;
    else if(digit<0 && copied_number==reverse_number) return 1;
    reverse_number += (n%10)*pow(10, digit);
    return palindrome_checker_recursion(n/10, copied_number, reverse_number, digit-1);
}

/*
     A number is thought of as an Armstrong number if the sum of its own digits raised to the power number of digits gives the number itself. For example
     0, 1, 153, 370, 371, 407 are three-digit Armstrong numbers and, 1634, 8208, 9474
*/

int armstrong_checker_bf(int n, int digit){
    int tmp=0, copy_number=n;
    while (n)
    {
        tmp += pow((n%10), digit);
        n /= 10;
    }
    if(tmp==copy_number) return 1;
    else return 0;
}

int armstrong_checker_rc(int n, int m, int tmp, int digit){
    if(m==0 && tmp!=n) return 0;
    else if(m==0 && tmp==n) return 1; 
    tmp += pow((m%10), digit);
    return armstrong_checker_rc(n, m/10, tmp, digit);
}


int prime_checker_bf(int n){
    int limit = sqrt(n);
    for(int i=2; i<=limit; i++){
        if(n%i==0) return 0;
    }
    return 1;
}

int prime_checker_rc(int n, int i, int limit){
    if(n%i==0) return 0;
    else if(i>limit) return 1;
    return prime_checker_rc(n, i+1, limit);
}

int fibo_rc(int n){
    if(n==1) return 0;
    else if(n==2) return 1;
    return fibo_rc(n-1)+fibo_rc(n-2);
}

int fibo_bf(int n){
    int a=0, b=1, c;
    if(n==1) return a;
    else if(n==2) return b; 

    for(int i=3; i<=n; i++){
        c = a+b;
        a = b;
        b = c;
    }

    return c;
}

int factorial_bf(int n){
    int res=1;
    if(n==0) return 1;
    for(int i=1; i<=n; i++) res *= i;
    return res;
}

int factorial_rc(int n){
    if(n==0) return 1;
    return n*factorial_rc(n-1);
}

int gcd_bf(int a, int b){
    int c;
    if(a<b){
        int t = a;
        a = b; 
        b = t;
    }
    cout<<a<<" b: "<<b<<endl;
    while(1){
        c = a%b; 
        a = b;
        if(c==0) return b;
        b = c;
    }
}

int gcd_rc(int a, int b){
    if(b==0) return a;
    return gcd_rc(b, a%b);
}

int lcm_bf(int a, int b, int max){
    while(1){
        if(max%a==0 && max%b==0) return max;
        max++;
    }
}

int lcm_rc(int a, int b, int max){
    if(max%a==0 && max%b==0) return max;
    return lcm_rc(a, b, (max+1));
}

int bin_to_decimal(int n){
    int m = n, res=0, i=0;
    while(n){
        res += (n%10)*pow(2, i);
        n /= 10;
        cout<<"res: "<<res<<" n: "<<n<<endl;
        i++;
    }
    return res;
}

int bin_to_decimal_rc(int n, int res, int p){
    if(n==0) return res;
    res += (n%10)*pow(2, p);
    return bin_to_decimal_rc(n/10, res, p+1);
}

int decimal_to_bin(int n){
    int res = 0, p=0;
    while(n){
        res += (n%2)*pow(10, p);
        p++;
        n /= 2;
    }
    return res;
}

int decimal_to_bin_rc(int n, int res, int p){
    if(n==0) return res;
    res += (n%2)*pow(10, p);
    return decimal_to_bin_rc(n/2, res, p+1);
}

int sum_of_digits_given_num(int n){
    int res=0;
    while(n){
        res += (n%10);
        n = n/10;
    }
    return res;
}

int sum_of_digits_given_num_rc(int n, int res){
    if(n==0) return res;
    res += (n%10);
    return sum_of_digits_given_num_rc(n/10, res);
}

main(){
    int n=12345, m=30, digit=0;
    //cin>>n;
    /*m = n;
    while(n){
        n = n/10;
        digit++;
    }*/
    //int max = n>m?n:m;
    cout<<sum_of_digits_given_num_rc(n, 0)<<endl;
    //cout<<factorial_bf(n)<<endl;
    return 0;
}