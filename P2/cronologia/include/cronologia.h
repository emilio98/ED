#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include"fechahistorica.h"


class Cronologia
{
public:
    int numFechas;
    int tamFechas;
    FechaHistorica *fechas;
    //bool badLoad = false;

    void resize(int num);
    void release();
    FechaHistorica* buscar(int anio);

    Cronologia();
    Cronologia(FechaHistorica *fechas,int numFechas);
    Cronologia(const Cronologia &otro);
    ~Cronologia();

    bool add(const FechaHistorica &fecha);
    void add(const FechaHistorica *fechasn,int numFechas);

    int get(std::string suceso);
    std::string* get(int anio,int &numSucesos);

    Cronologia& operator=(const Cronologia &otro);
    
    friend ifstream& operator>>(ifstream &is, Cronologia &f);
    friend ostream& operator<<(ostream &os, const Cronologia &f);
};

ifstream& operator>>(ifstream &is,Cronologia &cr);
ostream& operator<<(ostream &os,const Cronologia &cr);





