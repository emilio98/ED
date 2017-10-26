/**
  * @file fechahistorica.h
  * @brief Fichero cabecera del TDA FechaHistorica
  *
  */
#ifndef _FECHAHISTORICA_H_
#define _FECHAHISTORICA_H_

#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
using namespace std;
class FechaHistorica{
/**
  *  @brief T.D.A. FechaHistorica
  *
  * Una instancia @e c del tipo de dato abstracto @c FechaHistorica es un objeto
  * del conjunto de los acontecimientos históricos en una fecha, compuestos por 
  * un valor entero que representa el año y un conjunto de cadenas de caracteres
  * (strings) que representan los acontecimientos acaecidos ese año.
  * Un ejemplo de su uso:
  * @include pruebacronologia.cpp
  *
  * @author Emilio José Hoyo Medina 
  * @author Stefan Parvanov
  * @date Octubre 2017
  */
private:
/**
  * @page repConjunto Rep del TDA FechaHistorica
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e rep.año<=2018   rep.numsucesos>=0   rep.tamstring>=0
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA FechaHistorica representa a un conjunto
  * de sucesos históricos de cardinal rep.numsucesos (almacenados en el vector
  * dinámico de strings rep.sucesos, de tamaño rep.tamstring) y acaecidos en el 
  * año rep.anio.
  *
  */
	int anio; /**< año de los sucesos */
	int numsucesos;/**< número de sucesos */
	int tamstring;/**< tamaño del vector que almacena los sucesos */
	string* sucesos;/**< vector dinámico que almacena los sucesos */
	
/** @brief Cambia el tamaño del vector dinámico sucesos
  * @param tam Nuevo tamaño del vector dinámico sucesos
  * @pre tam debe ser mayor que 0
  */	
	void resize(int tam);

public:

/** @brief Constructor por defecto. Inicializa numsucesos y tamstring a 0, 
  *  anio a -1 y sucesos al puntero NULL
  */
FechaHistorica();
/** @brief Constructor de la clase
  * @param fecha Año de la FechaHistorica a construir
  * @pre fecha debe ser menor que 2018
  */
FechaHistorica(int fecha);
/** @brief Constructor de la clase
  * @param fecha Año de la FechaHistorica a construir
  * @param suc Vector de strings de sucesos de la FechaHistorica a construir
  * @param numsuc Número de sucesos de la FechaHistorica a construir
  * @pre numsuc debe ser mayor que 0 y la fecha menor que 2018 
  */
FechaHistorica(int fecha, string* suc, int numsuc);

/** @brief Constructor de copia de la clase
  * @param f FechaHistorica que se copiará en la FechaHistorica a construir
  */
FechaHistorica(const FechaHistorica &f);
/** @brief Destructor de la clase
  */
~FechaHistorica();

/** @brief Método set del año.
  * @param a Año al que se igualará la variable anio de la fecha histórica 
  * @pre La fecha debe ser menor que 2018 
  */
void setanio(int a);
/** @brief Método get del año.
  * @return Devuelve el año de la fecha histórica 
  */
int getanio() const;
/** @brief Método get del número de suceos.
  * @return Devuelve el número de sucesos de la fecha histórica
  */
int getnumsucesos()const;
/** @brief Método empty
  * @return devuelve true si la fecha histórica no tiene ningún suceso y falso 
  *  en caso contrario
  */
bool empty();
/** @brief Sobrecarga del operador[] no constante
  * @param i Posición del vector de sucesos a la que se desea acceder 
  * @pre i tiene que ser menor que numsucesos y sucesos no puede estar vacío
  * @return String en la posición i del vector de sucesos por referencia 
  */
string &operator[](int i);
/** @brief Sobrecarga del operador[] constante
  * @param i Posición del vector de sucesos a la que se desea acceder 
  * @pre i tiene que ser menor que numsucesos y sucesos no puede estar vacío
  * @return String en la posición i del vector de sucesos por referencia constante
  */
const string &operator[](int i) const;
/** @brief Busqueda de un string clave en el conjunto de los sucesos
  * @param clave String a buscar 
  * @return Devuelve true si la cadena de caracteres clave está contenida en algún 
  *  suceso de la fecha histórica y false en caso contrario 
  */
bool buscar(const string clave);
/** @brief Obtención de un subconjunto de sucesos de fecha histórica que contienen
  * un string clave
  * @param clave String utilizado como clave para obtener el subconjunto 
  * @return Devuelve una fecha histórica del mismo año con el subconjunto de los  
  *  sucesos que contienen clave
  */
FechaHistorica subFechaHistorica(const string clave);
/** @brief Añade un suceso a fecha histórica si este no está ya añadido
  * @param suc Suceso a añadir 
  * @return Devuelve true si el suceso se ha añadido y false en caso contrario
  */
bool addsuceso(const string suc);
/** @brief Añade a fecha histórica de entre un conjunto de sucesos aquellos que no están
  *  añadidos
  * @param suc Vector de sucesos a añadir
  * @param n Número de elementos del vector suc 
  */
void addsucesos(const string *suc, int n);
/** @brief Sobrecarga de operador de igualación
  * @param f FechaHistorica a la cual se igualará la fecha histórica que llama al 
  * operator =
  * @return Devuelve la fecha histórica que llama al operator = por referencia para
  *  igualaciones encadenadas
  */
FechaHistorica &operator=(const FechaHistorica &f);
/**
  * @brief Entrada de una fecha histórica desde istream
  * @param is stream de salida
  * @param f FechaHistórica a leer
  * @pre La FechaHistorica en is tendrá el formato:
  *  año\#suceso1\#suceso2\#...\#sucesoN
  */
friend istream &operator>>(istream &is, FechaHistorica &f);
/**
  * @brief Salida de una fecha histórica a ostream
  * @param o stream de salida
  * @param f FechaHistórica a escribir
  * @post Se obtiene en o la cadena con el formato:
  *  año\#suceso1\#suceso2\#...\#sucesoN
  *  donde N=numsucesos
  */
friend ostream &operator<<(ostream &o, const FechaHistorica &f);
};

istream &operator>>(istream &is, FechaHistorica &f);
ostream &operator<<(ostream &o, const FechaHistorica &f);
#endif
