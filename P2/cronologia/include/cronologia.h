#pragma once

#include<string>
#include"fechahistorica.h"


class Cronologia
{
    int numFechas;
    int tamFechas;
    FechaHistorica *fechas;

    void resize(int num);
    void release();
    FechaHistorica* buscar(int anio);
public:
    Cronologia();
    Cronologia(FechaHistorica *fechas,int numFechas);
    Cronologia(const Cronologia &otro);
    ~Cronologia();

    bool add(const FechaHistorica &fecha);
    bool add(const FechaHistorica (&fechas)[],int numFechas);


    int     fechaDeSuceso(std::string nombre);
    string* sucesosDeFecha(int anio);

    Cronologia& operator=(const Cronologia &otro);
    friend ostream& operator>>(ostream &i,const Cronologia &self);
};





