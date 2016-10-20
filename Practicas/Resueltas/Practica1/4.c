#include<stdio.h>
int main(){
float a = 0.001;
float b = 0.003;
float c, *pa, *pb;
pa = &a;
(*pa) = 2*a;
pb = &b;
c = 3 * (*pb - *pa );
printf("El valor de a: %f , b: %f , c: %f\n\n", a, b,c);
return 0;
}
