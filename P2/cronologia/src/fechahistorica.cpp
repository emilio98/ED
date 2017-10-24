#include "fechahistorica.h"
#include <sstream>
using namespace std;

void FechaHistorica::resize(int tam){
	assert(tam>0);
	if(tamstring>0){
		string *aux=new string[tam];
		for(int i=0;i<numsucesos && i<tam;i++)
			aux[i]=sucesos[i];
		delete[] sucesos;
		sucesos=aux;
	}
	else
	sucesos=new string[tam];
	tamstring=tam;
}
	
FechaHistorica::FechaHistorica():anio(-1),numsucesos(0),tamstring(0){sucesos=0;}
FechaHistorica::FechaHistorica(int fecha):anio(fecha),numsucesos(0),tamstring(0){sucesos=0;}
FechaHistorica::FechaHistorica(int fecha, string *suc, int numsuc){
	assert(fecha<=2018 && numsuc>0);
	numsucesos=numsuc;
	anio=fecha;
	tamstring=numsuc;
	sucesos=new string[numsuc];
	for(int i=0; i<numsucesos;i++)
		sucesos[i]=suc[i];
}

FechaHistorica::FechaHistorica(const FechaHistorica &f){
	anio=f.anio;
	numsucesos=f.numsucesos;
	tamstring=f.tamstring;
	if(tamstring>0){
		sucesos=new string[tamstring];
		for(int i=0;i<numsucesos;i++)
			sucesos[i]=f.sucesos[i];
	}
	else 
	sucesos=0;
}

FechaHistorica::~FechaHistorica(){
	delete[]sucesos;
	sucesos=0;
}

FechaHistorica &FechaHistorica::operator=(const FechaHistorica &f){
	anio=f.anio;
	numsucesos=f.numsucesos;
	if(tamstring>0)
		delete[]sucesos;
	if(f.tamstring>0){
	sucesos=new string[f.tamstring];
	for(int i=0;i<numsucesos;i++)
		sucesos[i]=f.sucesos[i];
	}
	else
		sucesos=0;
	tamstring=f.tamstring;
	return *this;
}
int FechaHistorica::getnumsucesos()const{return numsucesos;}

bool FechaHistorica::empty(){
	if(sucesos==0)
		return true;
	else
		return false;
}

string &FechaHistorica::operator[](int i){
	assert(!empty());
	return sucesos[i];
}

const string &FechaHistorica::operator[](int i) const{
	assert(sucesos!=0);
	return sucesos[i];
}

void FechaHistorica::setanio(int a){
	anio=a;
}
int FechaHistorica::getanio() const{return anio;}

bool FechaHistorica::buscar(const string clave){
	bool encontrado=false;
	for(int i=0;i<numsucesos && !encontrado;i++){
		if (sucesos[i].find(clave)!=string::npos)
			encontrado=true;
	}
	return encontrado;	
}

FechaHistorica FechaHistorica::subdivision(const string clave){
	if(buscar(clave)){
		FechaHistorica fecha(anio);
		for(int i=0;i<numsucesos;i++){
			if (sucesos[i].find(clave)!=string::npos)
				fecha.addsuceso(sucesos[i]);
		}
		return fecha;
	}
	else{
		FechaHistorica f;
		return f;
	}
}
	
bool FechaHistorica::addsuceso(const string suc){
	if (!buscar(suc)){
		if(numsucesos==tamstring)
			resize((tamstring*2)+1);    //el +1 es por si tamstring=0
		sucesos[numsucesos]=suc;
		numsucesos++;
		return true;
	}
	else
		return false;
}
void FechaHistorica::addsucesos(const string *suc, int n){
	assert(n>0);    
	int numaniadidos=0;
	for(int i=0;i<n;i++){
		if(addsuceso(suc[i]))
			numaniadidos++;
	}
	numsucesos=numsucesos+numaniadidos;
}		
		
		
istream &operator>>(istream &is, FechaHistorica &f){
	string aux;
	
	getline(is,aux,'#');
	f.anio=stoi(aux);
	
	while(is.eof()!=true){
		getline(is,aux,'#');
		f.addsuceso(aux);
	}
	return is;
}
		

ostream &operator<<(ostream &o, const FechaHistorica &f){
	o << f.anio;
	o << '#';
	for(int i=0;i<f.numsucesos;i++){
	o << f.sucesos[i];
	if(i<f.numsucesos-1)
		o << '#';
	}
	o<<'\n';
	return o;
}




	
