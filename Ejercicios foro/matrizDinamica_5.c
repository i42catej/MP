/* ----------------------------------------------------------------------------------
  Códigos de los ejemplos de las transparencias
  y de los vistos en clase
  
  Tema 3: Gestión de memoria dinámica 
 
  Ejercicio: Funciones para trabajar con matrices dinamicas
             ReservarMemoriaPorFilas
             ReservarM
/*---------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

//Prototipos
float ** reservaMatrizDinamicaPorFilas(int nFil, int nCol);
void rellenaMatriz(float ** m, int nFil, int nCol);
void visualizaMatriz(float ** m, int nFil, int nCol);
void liberaMatrizDinamicaPorFilas(float ** matriz, int nFil);
float ** reservaMatrizDinamicaUnSoloBloque(int nFil, int nCol);
void liberaMatrizDinamicaUnSoloBloque(float ** m);
int reservaMatrizDinamicaPorFilasRef(float *** matriz, int nFil, int nCol);
void liberaMatrizDinamicaPorFilasRef(float *** matriz, int nFil);

//Programa principal
int main(){
   float **matriz=NULL;
   int nFil,nCol;

   //Pedimos el nº de filas
   printf("Introduce el nº filas: ");
   scanf("%d",&nFil);

   //Pedimos el nº de columnas   
   printf("Introduce el nº columnas: ");
   scanf("%d",&nCol);

  //Reservamos la matriz por filas
  printf("Reservamos memoria para una matriz, por filas\n");
  matriz=reservaMatrizDinamicaPorFilas(nFil,nCol);
  printf("\tRellenamos la matriz\n");
  rellenaMatriz(matriz,nFil,nCol);
  printf("\tImprimimos la matriz\n");
  visualizaMatriz(matriz,nFil,nCol);
  printf("\tLiberamos la memoria\n");
  liberaMatrizDinamicaPorFilas(matriz,nFil);
  matriz=NULL;


  //Reservamos la matriz en un solo bloque
  printf("Reservamos memoria para una matriz, en un solo bloque\n");
  matriz=reservaMatrizDinamicaUnSoloBloque(nFil,nCol);
  printf("\tRellenamos la matriz\n");
  rellenaMatriz(matriz,nFil,nCol);
  printf("\tImprimimos la matriz\n");
  visualizaMatriz(matriz,nFil,nCol);
  printf("\tLiberamos la memoria\n");
  liberaMatrizDinamicaUnSoloBloque(matriz);
  matriz=NULL;

 //Reservamos la matriz por filas, pasando la matriz por referencia
  printf("Reservamos memoria para una matriz, por filas\n");
  reservaMatrizDinamicaPorFilasRef(&matriz,nFil,nCol);
  printf("\tRellenamos la matriz\n");
  rellenaMatriz(matriz,nFil,nCol);
  printf("\tImprimimos la matriz\n");
  visualizaMatriz(matriz,nFil,nCol);
  printf("\tLiberamos la memoria\n");
  liberaMatrizDinamicaPorFilasRef(&matriz,nFil);
  matriz=NULL;

  return 0;
}


//----------------------------- //
//    Definición de funciones   //
//-------------------- -------- //

/* ----------------------------------------------------
   Función que reserva una matriz dinámica por filas

   Se le pasa: nFil -> nº filas de la matriz
               nCol -> nº columnas de la matriz
   Devuelve: puntero al inicio de la matriz
             
   Utiliza: nada
   --------------------------------------------------*/
float ** reservaMatrizDinamicaPorFilas(int nFil, int nCol) {
   float ** matriz;
   int i, j, error = 0;

   matriz=(float**)malloc(sizeof(float*)*nFil);
   if (matriz==NULL)
      error=1;
   else {
      for (i=0;i<nFil;i++) {
         matriz[i]=(float*)malloc(sizeof(float)*nCol);
         if (matriz[i]==NULL)
            error=1;
       
      }
   }
   return(error?NULL:matriz);
}

/* ----------------------------------------------------
   Función que rellena una matriz dinámica

   Se le pasa: m -> puntero al inicio de la zona reservada
                    para la matriz
               nFil -> nº filas de la matriz
               nCol -> nº columnas de la matriz
   Devuelve: la matriz rellena
             
   Utiliza: nada
   --------------------------------------------------*/
void rellenaMatriz(float ** m, int nFil, int nCol) {
   int i,j;
   for (i=0; i<nFil; i++)
      for (j=0; j<nCol; j++) {
         printf("Elemento [%d][%d]: ",i,j);
         scanf("%f",&m[i][j]);
      }
}

/* ----------------------------------------------------
   Función que imprime por pantalla los valores de una
   matriz.

   Se le pasa: m -> puntero al inicio de la zona reservada
                    para la matriz
               nFil -> nº filas de la matriz
               nCol -> nº columnas de la matriz
   Devuelve: nada
             
   Utiliza: nada
   --------------------------------------------------*/
void visualizaMatriz(float ** m, int nFil, int nCol) {
   int i, j;

   for (i=0; i<nFil; i++){
      for (j=0; j<nCol; j++){
         printf("Elemento[%d][%d]=%f\n",i,j,m[i][j]);
      }
   }
}

/* ----------------------------------------------------
   Función que libera la memoria de una matriz dinámica
   reservada por filas
   Se le pasa: m -> puntero al inicio de la zona reservada
                    para la matriz
               nFil -> nº filas de la matriz              
   Devuelve: nada
             
   Utiliza: nada
   --------------------------------------------------*/
void liberaMatrizDinamicaPorFilas(float ** matriz, int nFil) {
   int i;

   for (i=0;i<nFil;i++) { 
      free(matriz[i]); 
   }

   free (matriz);
}

/* ----------------------------------------------------
   Función que reserva una matriz dinámica en un solo
   bloque

   Se le pasa: nFil -> nº filas de la matriz
               nCol -> nº columnas de la matriz
   Devuelve: puntero al inicio de la matriz
             
   Utiliza: nada
   --------------------------------------------------*/
float ** reservaMatrizDinamicaUnSoloBloque(int nFil, int nCol) {
   float ** matriz;
   int i, error = 0;

   matriz=(float**)malloc(sizeof(float*)*nFil);
   if (matriz==NULL)
      error=1;
   else {
      matriz[0]=(float*)malloc(sizeof(float)*nFil*nCol);
      if (matriz[0]==NULL)
         error=1;
      else
         for (i=1;i<nFil;i++)
            matriz[i]=matriz[i-1]+nCol;
   }
   return (error?NULL:matriz);
}

/* ----------------------------------------------------
   Función que libera la memoria de una matriz dinámica
   reservada en un solo bloque
   Se le pasa: m -> puntero al inicio de la zona reservada
                    para la matriz                            
   Devuelve: nada
             
   Utiliza: nada
   --------------------------------------------------*/
void liberaMatrizDinamicaUnSoloBloque(float ** matriz) {
   free (matriz[0]);
   free (matriz);
}

/* ----------------------------------------------------
   Función que reserva una matriz dinámica por filas,
   pero pasando la matriz por referencia

   Se le pasa: nFil -> nº filas de la matriz
               nCol -> nº columnas de la matriz
               matriz -> puntero doble a float
   Devuelve: puntero al inicio de la matriz
             
   Utiliza: nada
   --------------------------------------------------*/
int reservaMatrizDinamicaPorFilasRef(float *** matriz, int nFil, int nCol) {
   int i, j, error = 0;

   *matriz=(float**)malloc(sizeof(float*)*nFil);
   if (*matriz==NULL)
      error=1;
   else {
      for (i=0;i<nFil;i++) {
         (*matriz)[i]=(float*)malloc(sizeof(float)*nCol);
         if ((*matriz)[i]==NULL)
            error=1;
      }
   }
   return (error);
}

/* ----------------------------------------------------
   Función que libera la memoria de una matriz dinámica
   reservada por filas y actualiza el puntero a NULL
   (paso de la matriz por referencia)

   Se le pasa: m -> dirección de memoria del 
                    puntero al inicio de la zona reservada
                    para la matriz
               nFil -> nº filas de la matriz              
   Devuelve: nada
             
   Utiliza: nada
   --------------------------------------------------*/
void liberaMatrizDinamicaPorFilasRef(float *** matriz, int nFil) {
   int i;

   for (i=0;i<nFil;i++) {
     free((*matriz)[i]);        
   }
   free(*matriz);
   *matriz=NULL;
}
