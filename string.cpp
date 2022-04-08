#include<bits/stdc++.h>
using namespace std;

int vowel_count(char s[], int i, int l, int n){
    if(i>l) return n;
    if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') n++;
    return vowel_count(s, i+1, l, n);
}

void delete_vowel(char s[], int l){
    int k = 0;
    for(int i=0; i<l; i++){
       if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') continue;
       else{
           s[k] = s[i];
           k++;
       }
    }
    for(int i=0; i<k; i++) cout<<s[i];
}

void reverse_sentence(char s[], int l){
    char r[100];
    int i=0, j=0;

    for(i=l-1; i>=0; i--) {
        r[j]=s[i];
        j++;
    }

    for(int i=0; i<l; i++) cout<<r[i];
} 

void uppercase(char s[], int l){
    int i=0;
    while(s[i]!='\0'){
        if(s[i]>='a' && s[i]<='z') {
            s[i] = s[i]-32;
        }
        //cout<<s[i]<<endl;
        i++;
    }
    i=0;
    while(s[i]!='\0') {
        cout<<s[i];
        i++;
    }
    cout<<endl;
}

int palindrome(char s[], int left, int right){
    if(left>=right) return 1;
    else if(s[left]!=s[right]) return 0;
    return palindrome(s, left+1, right-1);
}

int substring_checker(char s[], char pattern[], int pattern_len){
    int i=0, j=0;
    while(s[i]!='\0'){
        if(pattern[j]==s[i]){
            if(j==pattern_len-1) return 1;
            j++;
        }
        else j=0;
        i++;
    }
    return 0;
}

void ip_address_class_checker(char ip[], int l){
    int i=0;
    while(ip[i]!='\0'){
        if(ip[i]=='.') {
            ip[i]='\0';
            break;
        }
        i++;
    }
    int x = atoi(ip);
    int class_check = (x>=0 && x<=127)?1:((x>=128 && x<= 191)?2:((x>=192 && x<=223)?3:((x>=224 && x<=239)?4:-1)));
    
    switch (class_check){
        case 1:
            cout<<"Class A"<<endl;
            break;
        case 2:
            cout<<"Class B"<<endl;
            break;
        case 3:
            cout<<"Class C"<<endl;
            break;
        case 4:
            cout<<"Class D"<<endl;
            break;
    
        default:
            cout<<"Invalid IP"<<endl;
            break;
    }
}

void complement(char s[], int l){
    char ones_complement[l], twos_complement[l];
    int k=l-1, first_one_found=0, x=0;
    while(k>=0){
        if(s[k]=='0' && first_one_found==0) twos_complement[k] = s[k];
        else if(s[k]=='1' && first_one_found==0){
            first_one_found=1;
            twos_complement[k]=s[k];
        }
        else if(first_one_found==1){
            if(s[k]=='0') twos_complement[k]='1';
            else twos_complement[k]='0';
        }
        k--;
    }
    while(s[x]!='\0'){
        if(s[x]=='0') ones_complement[x]='1';
        else ones_complement[x] = '0';
        x++;
    }
    cout<<"Original :        ";
    for(int i=0; i<l; i++) cout<<s[i];
    cout<<"\nTwo's Complement: ";
    for(int i=0; i<l; i++) cout<<twos_complement[i];
    cout<<"\nOne's Complement: ";
    for(int i=0; i<l; i++) cout<<ones_complement[i];
}

int main(){
    //char s[] = "1001001";
    
    char s[] = "11111111111111111111111111111111111122222222222227";
    char pattern[] = "xyzm";
    int i=0,l=0;

    while(s[i]!='\0'){
        l++;
        i++;
    }
    
    right_most_char[1] = '\0';
    int last_bit = atoi(right_most_char);
    cout<<last_bit<<endl;
    //complement(s, l);
    return 0;
}