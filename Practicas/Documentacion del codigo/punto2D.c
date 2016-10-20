/*!
  \file punto2D.c
  \brief Codificación de las funciones del TAD punto del plano eucĺideo
  \author Nombre y apellidos
*/

/* Ficheros de cabecera */
#include <stdio.h>

/*  Permite el uso de sqrt */
#include <math.h> 

#include "punto2D.h"

/* 
 Definiciones de las funciones auxiliares del struct Punto2D
*/

double getX(struct Punto2D p)
{
	return p._x;
}


double getY(struct Punto2D p)
{
	return p._y;
}



void setX(struct Punto2D *p, double v)
{
	(*p)._x = v;
}

void setY(struct Punto2D *p, double v)
{
	(*p)._y = v;
}


struct Punto2D crearPunto2D(double x, double y)
{
	struct Punto2D p;

	setX(&p,x);
	setY(&p,y);

	return p;
}


void leerPunto2D(struct Punto2D *p)
{

  double x, y;

  printf("\n Lectura de las coordenadas de un punto: P(x,y)\n");

  printf(" Abscisa: x --> ");
  scanf("%lf",&x);

  printf(" Ordenada: y --> ");
  scanf("%lf",&y);

  /*
     Se asignan los valores leídos a los atributos del punto   
     Se utilizan las funciones de modificación de Punto2D
   */
  setX(p,x);
  setY(p,y);
}


void escribirPunto2D(struct Punto2D p)
{
	printf("(%7.4lf,%7.4lf)", getX(p), getY(p));
}



double calcularDistanciaEuclidea2D(struct Punto2D p1, struct Punto2D p2)
{
 double resultado;

 resultado = sqrt(    ((getX(p2) - (getX(p1))) * (getX(p2) - (getX(p1))))
                    +  ((getY(p2) - (getY(p1))) * (getY(p2) - (getY(p1))))
		);

 return resultado;
}

