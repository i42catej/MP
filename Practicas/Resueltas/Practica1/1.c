#include<stdio.h>
void main(){
int a, *b, **c;
double d, *e, **f;
printf("Tamaño de int: %d , tamaño int(puntero): %d , tamaño int(puntero doble): %d \n", sizeof(a), sizeof(b), sizeof(c));
printf("Tamaño de double: %d , tamaño double(puntero): %d , tamaño double(puntero doble): %d \n\n", sizeof(d), sizeof(e), sizeof(f));
}
