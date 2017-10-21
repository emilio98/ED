#include"cronologia.h"
#include<sstream>

void Cronologia::release(){
/*    for(int i=0; i>numFechas;i++)
        delete fechas[i];
*/
    if(fechas)
        delete[] fechas;
}
void Cronologia::resize(int tam){
    assert(tam>0);
    tamFechas = tam;
    FechaHistorica *tmp = new FechaHistorica[tamFechas];
    for(int i=0;i<numFechas;i++)
        tmp[i] = fechas[i];
    this->release();
    this->fechas = tmp;
}
FechaHistorica* Cronologia::buscar(int anio){
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
Cronologia::Cronologia(const Cronologia &otro){
    assert(otro.numFechas >0);
    release();
    this->numFechas = otro.numFechas;
    this->fechas = new FechaHistorica[this->numFechas];
    for(int i=0;i<this->numFechas;i++)
        this->fechas[i] = otro.fechas[i];
}
Cronologia& Cronologia::operator=(const Cronologia &otro){
    assert(otro.numFechas >0);    
    release();
    this->numFechas = otro.numFechas;
    this->fechas = new FechaHistorica[this->numFechas];
    for(int i=0;i<this->numFechas;i++)
        this->fechas[i] = otro.fechas[i];
    return *this;
}

bool Cronologia::add(const FechaHistorica &nueva){
    FechaHistorica *fecha = buscar(nueva.getanio());
    if(fecha)
        return false;
    if(numFechas+1 > tamFechas)
        resize(tamFechas*2+1);
    fechas[numFechas++] = nueva;
    return true;
}
void Cronologia::add(const FechaHistorica *fechasn,int numFechas){
    assert(numFechas > 0);
    for(int i=0;i<numFechas;i++)
        this->add(fechasn[i]);
}
int Cronologia::get(std::string suceso){
    // Falta por implementar metodos get de fecha_historica
    return -1;
}
std::string* get(int anio,int &numsucesos){
    return nullptr;
}

ostream& operator<< (ostream &os, const Cronologia &cr){
    int i = 0;
    while ( i<cr.numFechas && os << cr.fechas[i])
        i++;
    return os;
}
ifstream& operator>> (ifstream &is, Cronologia &cr){
    
    string linea;
    while( is.eof() != true ){
    	getline(is,linea,'\n');
	istringstream flujo(linea);
	FechaHistorica fecha;
	flujo >> fecha;
        cr.add(fecha);
        }
    return is;
}
