#include <stdlib.h>
#include <stdio.h>


int main(){

 int num1;
 int num2;

 int *dir1;
 int *dir2;
 int dir3;

printf("Introduzca el numero1: ");
scanf("%d",&num1);

printf("Introduzca el numero2: ");
scanf("%d",&num2);

dir1=&num1;
dir2=&num2;


dir3=*dir1;
*dir1=*dir2;
*dir2=dir3;


printf("Num1: %d y Num2: %d\n",num1,num2);




 return 0;
}
