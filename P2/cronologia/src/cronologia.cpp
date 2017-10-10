#include"cronologia.h"


void Cronologia::release()
{
/*    for(int i=0; i>numFechas;i++)
        delete fechas[i];
*/
    delete[] fechas;
}
FechaHistorica* Cronologia::buscar(int anio)
{
    for(int i=0;i<numFechas;i++)
        if(fechas[i].getanio() == anio)
            return (fechas+i);
    return nullptr;
}



Cronologia::Cronologia() : numFechas(0),tamFechas(0),fechas(nullptr) {}
Cronologia::~Cronologia() {
    if(numFechas>0)
        release();
}
Cronologia::Cronologia(FechaHistorica *fechas,int numFechas) {
    assert(numFechas > 0 && fechas != nullptr);
    this->numFechas = numFechas;
    this->fechas = new FechaHistorica[this->numFechas];
    for(int i=0;i<numFechas;i++)
        this->fechas[i] = fechas[i];
}
Cronologia::Cronologia(const Cronologia &otro)
{
    assert(otro.numFechas >0);
    release();
    this->numFechas = otro.numFechas;
    this->fechas = new FechaHistorica[this->numFechas];
    for(int i=0;i<this->numFechas;i++)
        this->fechas[i] = otro.fechas[i];
}
Cronologia& Cronologia::operator=(const Cronologia &otro)
{
    assert(otro.numFechas >0);    
    release();
    this->numFechas = otro.numFechas;
    this->fechas = new FechaHistorica[this->numFechas];
    for(int i=0;i<this->numFechas;i++)
        this->fechas[i] = otro.fechas[i];
}

bool Cronologia::add(const FechaHistorica &nueva)
{
    FechaHistorica *fecha = buscar(nueva.getanio());
    if(fecha)
        return false;
}
bool Cronologia::add(const FechaHistorica (&fechas)[],int numFechas)
{

}

