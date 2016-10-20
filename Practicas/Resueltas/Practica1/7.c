#include<stdio.h>
#define TAM 6
void calcularNotas(float Notas[], float* mediaA,float* mediaB,float* maxA,float* maxB,float* minA,float* minB);

//MAIN
int main(){
float Notas[TAM], mediaA=0, mediaB=0, maxA, maxB, minA=100, minB=100;
int i;
for(i=0; i<TAM; i++){
printf("Introduzca las notas %d: ", i+1);
scanf("%f", &Notas[i]);
}
calcularNotas(Notas, &mediaA, &mediaB, &maxA, &maxB, &minA, &minB);
printf("Las notas A (pares): \nMaximo - %.2f \nMinimo - %.2f \nMedia - %.2f\n\n", maxA, minA, mediaA);
printf("Las notas B (impares): \nMaximo - %.2f \nMinimo - %.2f \nMedia - %.2f\n\n", maxB, minB, mediaB);
return 0;
}


//FUNCIONES
//Funcion que calcula las notas de A y B
void calcularNotas(float Notas[], float* mediaA,float* mediaB,float* maxA,float* maxB,float* minA,float* minB){
int i;
float sumaA, sumaB;
for(i=0; i<TAM; i++){
	if((i+1)%2==0){
//A --> Alumnos pares
		sumaA=sumaA+Notas[i];
		if(*maxA<Notas[i])
			*maxA=Notas[i];
		if(*minA>Notas[i])
			*minA=Notas[i];
}else{
//B --> Alumnos impares
sumaB=sumaB+Notas[i];
if(*maxB<Notas[i])
*maxB=Notas[i];
if(*minB>Notas[i])
*minB=Notas[i];
}
}
(*(mediaA))=sumaA/(TAM/2);
(*(mediaB))=sumaB/(TAM/2);
}
