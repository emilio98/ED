#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include"fechahistorica.h"


class Cronologia
{
    int numFechas;
    int tamFechas;
    FechaHistorica *fechas;
    //bool badLoad = false;

    void resize(int num);
    void release();
    FechaHistorica* buscar(int anio);
public:
    Cronologia();
    Cronologia(FechaHistorica *fechas,int numFechas);
    Cronologia(const Cronologia &otro);
    ~Cronologia();

    bool add(const FechaHistorica &fecha);
    void add(const FechaHistorica (&fechas)[],int numFechas);

    int get(std::string suceso);
    std::string* get(int anio,int &numSucesos);

    Cronologia& operator=(const Cronologia &otro);
    
    friend ifstream& operator>>(ifstream &is, Cronologia &f);
    friend ofstream& operator<<(ofstream &o, const Cronologia &f);
};

ifstream& operator>>(ifstream &is,Cronologia &cr);
ofstream& operator<<(ofstream &os,const Cronologia &cr);





