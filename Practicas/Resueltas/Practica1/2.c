#include<stdio.h>
void main(){
int *px;//puntero de tipo int
float a, b;//float
float *pa=&a, *pb;//punteros de tipo float y *pa apunta a a
//float a=­0.167;//se inicializa a pero da fallo al volverse a declarar
//float *pa =&a;//pa apunta a a
char c1='I', c2='J', c3='K', cl='W';//char que se inicializan
char *pcl, *pc2, *pc3 =&cl;//punteros de tipo char y pc3 apunta a cl
pcl=&c1;
pc2=&c2;
a=0.167;
b=0.46;
pb=&b;
px=&a;
printf("Puntero apunta a A %f y a B %f .\n", *pa, *pb);
printf("Casting de px en A %f\n", *px);
printf("Los caracteres son %c %c %c\n\n", *pcl, *pc2, *pc3);
}
