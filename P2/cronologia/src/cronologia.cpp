#include"cronologia.h"


Cronologia::Cronologia() : numFechas(0),fechas(nullptr) {}
Cronologia::~Cronologia() {
    delete[] fechas;
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

}