/**
 * @file cronologia.cpp
 * @brief Fichero cabecera del TDA Cronologia
 * */
#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include"fechahistorica.h"


class Cronologia
{
/**
  *  @brief T.D.A. Cronologia
  *
  * Una instancia @e c del tipo de dato abstracto @c Cronologia es un objeto
  * del conjunto de fechas históricas compuestos por un valor entero que
  * representa el numero de fechas, otro que representa el tamaño del vector 
  * dinamico utilizado y el vector dinamico de fechas.
  * Un ejemplo de su uso:
  * @include cronologia.cpp
  *
  * @author Emilio José Hoyo Medina 
  * @author Stefan Parvanov
  * @date Octubre 2017
  */
private:
/**
 * @page repConjunto Rep del TDA Cronologia.
 * @section faConjunto Funcion de abstraccion
 * 
 * Un objeto valido @e rep del TDA Cronologia representa a un conjunto 
 * de fechas historicas de cardinal rep.numFechas( almacenadas en el 
 * vector dinamico rep.fechas de tamaño rep.tamFechas).
 * */
    int numFechas;          /**< numero de fechas **/
    int tamFechas;          /**< tamaño del vector fechas **/
    FechaHistorica *fechas; /**< vector dinamico de fechas **/

/**
 * @brief Cambia el tamaño del vector
 * @param num Nuevo tamaño.
 * @pre num ha de ser mayor que cero.
 **/
    void resize(int num);
/** 
 * @brief Borra el vector y libera la memoria dinamica.
 **/
    void release();
/**
 * @brief Funcion que busca si existe una fecha dado su año.
 * @return Devuelve la fecha si existe o una fecha vacia si no.
 **/
    FechaHistorica* buscar(int anio);
public:
/**
 * @brief Constructor por defecto. Inicializa numFechas y tamFechas a 0,
 * y el puntero fechas a nullptr.
 * */
    Cronologia();
/**
 * @brief Constructor de la clase
 * @param fechas vector de fechas historicas
 * @pre las fechas han de estar ordenadas.
 * */
    Cronologia(FechaHistorica *fechas,int numFechas);
/**
 * @brief Constructor de copia.
 * @param otro Otra cronologia.
 * @pre otro debe ser una cronologia valida.
 * */
    Cronologia(const Cronologia &otro);
/**
 * @brief Destructor de la clase
 * */    
    ~Cronologia();

/** 
 * @brief Metodo que añade una fecha historica a la cronologia.
 * @param fecha La fecha que se desea añadir.
 **/
    bool add(const FechaHistorica &fecha);
/**
 * @brief Metodo que añade un conjunto de fechas histroicas.
 * @param fechas Fechas que se desean añadir.
 * @pre Ha de ser un vector no nulo.
 * @param numFechas Numero de fechas en el vector.
 * @pre Ha de ser un valor positivo.
 * */
    void add(const FechaHistorica *fechas,int numFechas);
/**
 * @brief Metodo get que devuelve una subcronologia.
 * @param an_i Año inicial de la subcronologia.
 * @pre Ha de ser un valor positivo y menor que numFechas
 * @param an_f Año final de la subcronologia.
 * @pre Ha de ser mayor que an_i y menor que numFechas
 * @return Devuelve la subcronologia.
 * */
    Cronologia get(int an_i,int an_f);
/**
 * @brief Metodo que devuelve la fecha historica dado un año.
 * @param anio Es el año del que deseamos obtener la fechahistorica.
 * @return Devuelve la fecha historica o una fecha vacia si no existe.
 * */
    FechaHistorica& get(int anio);
/**
 * @brief Metodo que devuelve el numero de fechas historicas.
 * @return Devuelve el numero de fechas historicas.
 * */
    int length();

/**
 * @brief Operador de asignacion
 * @param otro Otra cronologia.
 * @return devuelve la asignacion.
 * */
    Cronologia& operator=(const Cronologia &otro);
/**
 * @brief Operador de indexado
 * @param index El indice de la fecha que quieramos.
 * @pre Ha de ser menor que numFechas
 * @return Devuelva la n-esima fecha historica.
 * */
    FechaHistorica& operator[](int index);
/**
 * @brief Operador de union de cronologias. Une dos cronologias cogiendo todas
 * las fechas historicas de las dos. No se hace la union de fechas, es decir
 * si dos fechas tienen el mismo año se toman como iguales sin considerar sus sucesos.
 * @param otro Otra cronologia con la que hacer la union.
 * @return Devuelve la union de cronologias.
 * */
    Cronologia operator+(const Cronologia &otro);
/**
 * @brief Operador de entrada de stream.
 * @param is ifstream de entrada
 * @param f cronologia de entrada
 * */
    friend ifstream& operator>>(ifstream &is, Cronologia &f);
/** 
 * @brief Operador de salida de stream.
 * @param os Ofstream de salida.
 * @param f Cronologia de salida.
 * */
    friend ostream& operator<<(ostream &os, const Cronologia &f);
};

ifstream& operator>>(ifstream &is,Cronologia &cr);
ostream& operator<<(ostream &os,const Cronologia &cr);





