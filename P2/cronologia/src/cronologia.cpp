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
/*
    int anio = nueva.getanio();
    int indice = numFechas;

    for(int i=0;i<numFechas;i++)
        if(fechas[i].getanio() < anio)
            indice = i;
    
*/

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


ostream& operator<< (ostream &os, const Cronologia &cr){
    int i = 0;
    while ( i<cr.numFechas && os << cr.fechas[i])
        i++;
    return os;
}
ifstream& operator>> (ifstream &is, Cronologia &cr){
    
    string linea;
    getline(is,linea,'\n');
    while( is.eof() != true ){
	istringstream flujo(linea);
	FechaHistorica fecha;
	flujo >> fecha;
        cr.add(fecha);
        getline(is,linea,'\n');
        }
    return is;
}

FechaHistorica& Cronologia::operator[](int index){
    assert(index<numFechas);
    return fechas[index];
}
Cronologia Cronologia::operator+(const Cronologia &otro){
    Cronologia temp;
    temp.add(this->fechas,this->numFechas);
    temp.add(otro.fechas,otro.numFechas);
    return temp;
}
int Cronologia::length(){
    return numFechas;
}
Cronologia Cronologia::get(int an_i,int an_f){
    assert(an_f>= an_i && an_i>0);
    int index_i = numFechas;
    int index_f = numFechas;
    for(int i=0;i<numFechas;i++){
        if(fechas[i].getanio() < an_i )
            index_i = i;
        if(fechas[i].getanio() < an_f)
            index_f = i;
    }
    if(index_i <= index_f && index_i < numFechas && index_f < numFechas){
        Cronologia temp(fechas+index_i,index_f-index_i+1);
        return temp;
    }else{
        Cronologia temp;
        return temp;
    }    
}
