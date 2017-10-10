#pragma once

#include<string>
#include"fechahistorica.h"


class Cronologia
{
    int numFechas;
    FechaHistorica *fechas;

public:
    Cronologia();
    Cronologia(FechaHistorica *fechas,int numFechas);
    Cronologia(const Cronologia &otro);
    ~Cronologia();

    void nuevaFecha(FechaHistorica *nueva);

    Cronologia& operator=(const Cronologia &otro);

    int     fechaDeSuceso(std::string nombre);
    string* sucesosDeFecha(int anio);


    friend ostream& operator>>(ostream &i,const Cronologia &self);
};





