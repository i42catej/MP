/*Implementa un programa que pruebe la función anterior. Para ello, el programa deberá realizar las siguientes operaciones secuencialmente:

    Reservar memoria para una matriz,(H)
    Rellenar la matriz(H)
    Mostrar la matriz por pantalla.(H)
    Preguntar las coordenadas de la submatriz(H)
    Extraer la submatriz.(H*)
    Imprimir la submatriz extraída(H)
    Liberar toda la memoria reservada*/

#include <stdio.h>
#include <stdlib.h>


int ** reservamemoria(int nfil, int ncol);
void rellenamatriz(int **m, int nfil, int ncol);
void imprimematriz(int **m, int nfil, int ncol);
void extraesubmatriz(int **m, int **sub, int nfilsub, int ncolsub, int x1, int y1, int x2, int y2);
void liberamatriz(int **m, int nfil);




int main(){

	int **matriz=NULL;
	int **submatriz=NULL;
	int nfil, ncol;
	int nfilsub,ncolsub;
	int x1,y1,x2,y2;

	printf("Introduce el numero de filas: ");
	scanf("%d",&nfil);
	printf("Introduce el numero de columnas: ");
	scanf("%d",&ncol);

	printf("Reservando memoria...\n");
	matriz=reservamemoria(nfil,ncol);
	printf("Rellena la matriz...\n");
	rellenamatriz(matriz,nfil,ncol);
	printf("Imprimiendo la matriz...\n");
	imprimematriz(matriz,nfil,ncol);

	//Pregunta de coordenadas
	printf("Introduzca la coordenada x1: ");
	scanf("%d",&x1);
	printf("Introduzca la coordenada y1: ");
	scanf("%d",&y1);
	printf("Introduzca la coordenada x2: ");
	scanf("%d",&x2);
	printf("Introduzca la coordenada y2: ");
	scanf("%d",&y2);

	nfilsub=(x2-x1)+1;
	ncolsub=(y2-y1)+1;

	printf("Reservando memoria para la submatriz...\n");
	submatriz=reservamemoria(nfilsub,ncolsub);
	extraesubmatriz(matriz, submatriz, nfilsub, ncolsub, x1, y1, x2, y2);
	printf("Imprimiendo la submatriz...\n");
	imprimematriz(submatriz,nfilsub,ncolsub);

	printf("\n\nLiberando memoria...\n");
	liberamatriz(matriz,nfil);
	liberamatriz(submatriz,nfilsub);
	


 return 0;
}



//Reserva memoria para una matriz
int ** reservamemoria(int nfil, int ncol){
	int ** m=NULL;
	int i,j;

	m=(int**)malloc(sizeof(int*)*nfil);
	if(m==NULL){
		printf("Error en la reserva de memoria, la matriz apunta a NULL\n");
		exit (-1);
	}

	for(i=0;i<nfil;i++){
		m[i]=(int*)malloc(sizeof(int)*ncol);
		if(m[i]==NULL){
			printf("Error en la reserva de memoria, la matriz apunta a NULL\n");
		}
	}
  return m;
}






//Rellena una matriz
void rellenamatriz(int **m, int nfil, int ncol){
	int i,j;

	for(i=0;i<nfil;i++){
		for(j=0;j<ncol;j++){
			printf("Matriz[%d][%d]: ",i,j);
			scanf("%d",&m[i][j]);
		}
	}
}



//Imprime una matriz
void imprimematriz(int **m, int nfil, int ncol){
	int i,j;

	for(i=0;i<nfil;i++){
		for(j=0;j<ncol;j++){
			printf("%d ",m[i][j]);
		}
	   printf("\n");
	}
}



//Extrae la submatriz
void extraesubmatriz(int **m, int **sub, int nfilsub, int ncolsub, int x1, int y1, int x2, int y2){
	int i,j,contx=0,conty=0;
	
	for(i=x1;i<=x2;i++){
		for(j=y1;j<=y2;j++){
			sub[contx][conty]=m[i][j];
			if(conty<nfilsub){
				conty++;
			}
			if(conty==ncolsub-1){
				conty=0;
			}
		}
	 if(contx<ncolsub){
	   contx++;
	 }
	}
}




//Libera memoria
void liberamatriz(int **m, int nfil){
	int i;

	 for (i=0;i<nfil;i++) { 
      		free(m[i]); 
  	 }

   	 free (m);


}
