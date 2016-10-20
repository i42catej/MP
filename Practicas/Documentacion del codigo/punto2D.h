/*!
  \file punto2D.h
  \brief Se representa el TAD punto del plano eucĺideo
  \author Nombre y apellidos
*/

/* Se introducen las guardas de seguridad del fichero de cabecera */
#ifndef PUNTO2D_H_
#define PUNTO2D_H_


/*!  Definición del tipo abstrado de datos struct Punto2D  */
struct Punto2D 
{
      	double _x; /*!< abscisa del struct Punto2D */
	double _y; /*!< ordenada del struct Punto2D */
};

/*! \name Funciones de consulta de struct Punto2D */

/*! 
	\fn double getX(struct Punto2D p)
	\brief Devuelve la coordenada "x" (abscisa) de un Punto2D
 	\param p Punto2D pasado por valor
	\return componente "x" del Punto2D
	\pre El struct Punto2D debe existir
	\post Ninguna
	\sa getY()
*/
double getX(struct Punto2D p);


/*! 
	\fn double getY(struct Punto2D p)
	\brief Devuelve la coordenada "y" (ordenada) de un Punto2D
 	\param p Punto2D pasado por valor
	\return componente "y" del Punto2D
	\pre El Punto2D debe existir
	\post Ninguna
	\sa getY()
*/
double getY(struct Punto2D p);


/*! \name Funciones de modificación de Punto2D */

/*! 
	\fn    void setX(struct Punto2D *p, double v)
	\brief Asigna un valor "v" a la coordenada "x"  (abscisa) de un Punto2D
     	\param p Punto2D pasado por referencia
	\param v double
	\pre El Punto2D debe existir
	\post Ninguna
	\sa setY()
*/
void setX(struct Punto2D *p, double v);


/*! 
	\fn void setX(struct Punto2D *p, double v)
	\brief Asigna un valor "v" a la coordenada "y" (ordenada) de un Punto2D
     	\param p Punto2D pasado por referencia
	\param v double
	\pre El Punto2D debe existir
	\post Ninguna
	\sa setY()
*/
void setX(struct Punto2D *p, double v);


/*! \name Funciones de creación de Punto2D */

/*! 
	\fn  struct Punto2D crearPunto2D(double x, double y)
	\brief Crea un struct Punto2D a partir de sus coordenadas x e y
	\param x double, representa la abscisa del punto
	\param y double, representa la ordenada del ponto
     	\return Devuelve un Punto2D
	\pre Ninguna
	\post Ninguna
	\sa setX(), setY()
*/
struct Punto2D crearPunto2D(double x, double y);


/*! \name Otras funciones auxiliares de Punto2D */

/*! 
	\fn    void leerPunto2D(struct Punto2D *p)
	\brief Asigna a un struct Punto2D las coordenadas "x" e "y" leídas desde el teclado
	\param p Punto2D pasado por referencia
	\pre El Punto2D p debe existir
	\post Ninguna
	\warning Se deben teclear números reales
	\sa setX(), setY()
*/
void leerPunto2D(struct Punto2D *p);


/*! 
	\fn void escribirPunto2D(struct Punto2D p)
	\brief Escribe las coordenadas de un Punto2D 
	\param p Punto2D pasado por valor
	\pre El Punto2D p debe existir
	\post Ninguna
	\sa getX(), getY()
*/
void escribirPunto2D(struct Punto2D p);


/*! 
	\fn double calcularDistanciaEuclidea2D(struct Punto2D p1, struct Punto2D p2)
	\brief Calcula la distancia euclídea de dos puntos  
	\param p1  Punto2D pasado por valor
	\param p2  Punto2D pasado por valor
     	\return la distancia euclídea entre los puntos p1 y p2
	\pre Los puntos p1 y p2 deben existir
	\post Ninguna
	\sa getX(), getY()
*/
double calcularDistanciaEuclidea2D(struct Punto2D p1, struct Punto2D p2);


/*! _PUNTO2D_H_ */
#endif 
