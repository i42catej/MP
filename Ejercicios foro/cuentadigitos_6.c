#include <stdio.h>

int cuenta(int num){

	int cont=0;

	if(num<=0){
		cont=0;
	} else {
		cont=cuenta(num/10)+1; //Se le suma 1 porque es el digito que no hemos contado al dividir entre 10
	}

 return cont;
}


int main (){

	int num,contador=0;
	
	printf("Introduzca el numero: ");
	scanf("%d",&num);

	contador=cuenta(num);

	printf("El total de digitos de %d es %d\n",num,contador);

 return 0;
}
