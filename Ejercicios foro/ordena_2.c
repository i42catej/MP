#include <stdio.h>
#include <stdlib.h>


void intercambia(int *num1, int *num2);
void ordena(int *num1, int *num2,int *num3);



int main(){

int num1,num2,num3;

printf("Introduce el numero 1: ");
scanf("%d",&num1);

printf("Introduce el numero 2: ");
scanf("%d",&num2);

printf("Introduce el numero 3: ");
scanf("%d",&num3);

printf("Nº1: %d   Nº2: %d    Nº3: %d\n",num1,num2,num3);

ordena(&num1,&num2,&num3);

printf("Tras la ordenacion...\n Nº1: %d   Nº2: %d    Nº3: %d\n",num1,num2,num3);


  return 0;
}





void ordena(int *num1, int *num2,int *num3){

	
	if(*num3<*num2){
		intercambia(num3,num2);
	}

	if(*num3<*num1){
		intercambia(num3,num1);
	}

	if(*num2<*num1){
		intercambia(num2,num1);
	}


}


void intercambia(int *num1, int *num2){

 int aux;
 
	aux=*num1;
	*num1=*num2;
	*num2=aux;
}
