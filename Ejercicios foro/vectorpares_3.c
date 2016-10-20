#include <stdio.h>
#include <stdlib.h>
#define MAX 20


void leevector(int *v, int t){

int i;

for(i=0;i<t;i++){
	printf("Introduce el valor de v[%d]: ",i);
	scanf("%d",&v[i]);
}
}


void imprimevector(int *v,int t){

int i;

printf("IMPRIMIENDO VECTOR\n");

for(i=0;i<t;i++){
	printf("[%d]",v[i]);
}
printf("\n");
}




int copiapares(int *v, int t, int *v2){

int i,ta=0,t2=0;

for(i=0;i<t;i++){
	if(*(v+i)%2==0){
		*(v2+ta)=*(v+i);
		ta++;
		t2++;
	}
}
return t2;
}




int main(){

int tam,tam2;

printf("Introduce el tamaño del vector: ");
scanf("%d",&tam);

int vector1[tam];
int vector2[MAX];

leevector(vector1,tam);
imprimevector(vector1,tam);
tam2=copiapares(vector1,tam,vector2);
imprimevector(vector2,tam2);



 return 0;
}
