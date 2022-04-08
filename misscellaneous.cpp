#include<bits/stdc++.h>
using namespace std;

void circle(){
    float r=2.56, a, pi=3.1416, c;
    //scanf("%d", &r);
    a = pi*r*r;
    printf("Area of circle is: %f\n", a);
    c = 2*pi*r;
    printf("Circumstance of Circle is: %f\n", c);
}

void ascii_value(){
    char c='A'; /* single qoute is used for single char, while double is used for char array*/
    char s[] = "ABCD";
    printf("Value of %c is: %d\n", c, c);
    printf("string is: %c", s[3]);
}

void leap_year(){
    int y = 2900;
    if((y%4==0 && y%100!=0) || y%400==0) printf("%d is leap year :)\n", y);
    else printf("%d is not leap year :|\n", y);
}

void matrix_multiply(){
    // Multiplying first and second matrices and storing it in result
   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         for (int k = 0; k < c1; ++k) {
            result[i][j] += first[i][k] * second[k][j];
         }
      }
   }
}

int main(){
    leap_year();
}