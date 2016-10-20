/*!
  \file  principal_punto.c
  \brief Programa que muestra el uso del TAD punto del plano euclídeo
  \author Nombre y apellidos
*/

/*!
	\mainpage Tipos abstractos de datos Punto2D y Recta2D
	\brief   Se muestra el uso del TAD punto del plano euclídeo
	\author  Nombre y apellidos
	\date   12 de febrero 2014
*/

/*
  Se muestra el uso del tipo abstracto de datos Punto2D 
*/ 

/* Ficheros de cabecera */

#include <stdio.h>

#include "punto2D.h"


int main(void)
{

  /* Uso de las funciones del TAD Punto2D */

  /* Declaración de variables locales */
  struct Punto2D p1, p2;

  /* Creación de puntos */
  p1 = crearPunto2D(0.0,0.0);

  p2 = crearPunto2D(1.0,1.0);

  /* Se escriben los puntos */

  printf("Se escriben las coordenadas de los puntos\n");
  printf("\n Primer punto --> " );
  escribirPunto2D(p1);
  printf("\n Segundo punto --> " );
  escribirPunto2D(p2);


  /* Se modifican los valores de un punto leyendo las coordenadas desde el teclado */
  leerPunto2D(&p2);

  printf("\n Punto modificado --> " );
  escribirPunto2D(p2);


  /* Uso de la distancia euclídea */
  printf("\n Distancia euclídea entre p1 y p2 %7.4f\n", calcularDistanciaEuclidea2D(p1,p2));


  /* Fin del programa */

  return 0;
}




