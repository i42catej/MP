#include<stdio.h>
double media(double x, double y);
void media_referencia(double x, double y, double * resultado);
int main(){
double x, y, media1, media2;
printf("Inserta x: ");
scanf("%lf", &x);
printf("Inserta y: ");
scanf("%lf", &y);
media1=media(x,y);
media_referencia(x, y, &media2);
printf("La media de x (%.3lf) e y (%.3lf) por valor es: %.3lf\n", x,y,media1);
printf("La media de x (%.3lf) e y (%.3lf) por referencia es: %.3lf\n\n",x,y, media2);
return 0;
}
//FUNCIONES
double media(double x, double y){
double resultado;
resultado=((x+y)/2);
return (resultado);
}
void media_referencia(double x, double y, double * resultado){
*resultado=((x+y)/2);
}
