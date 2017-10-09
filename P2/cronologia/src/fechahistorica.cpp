#include <fechahistorica.h>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void FechaHistorica::resize(int tam){
	assert(tam>0 && numsucesos<=tam);
	if(tamstring>0){
		string *aux=new string[tam];
		for(int i=0;i<numsucesos;i++)
			aux[i]=sucesos[i];
		delete[] sucesos;
		sucesos=aux;
	}
	else
	sucesos=new string[tam];
	tamstring=tam;
}
	
FechaHistorica::FechaHistorica():anio(-1),sucesos(0),numsucesos(0),tamstring(0){}

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
			sucesos[i]=f.sucesos[i]
	}
	else 
	sucesos=0;
}

FechaHistorica::~FechaHistorica(){
	delete[]sucesos;
	sucesos=0;
}

void FechaHistorica::setanio(int a){
	anio=a;
}
int FechaHistorica::getanio() const{return anio}

void FechaHistorica::addsuceso(string suc){
	if(numsucesos==tamstring)
		resize((tamstring*2)+1);    //el +1 es por si tamstring=0
	sucesos[numsucesos]=suc;
	numsucesos++;
}
void FechaHistorica::addsucesos(string *suc, int n){
	assert(n>0);
	if(numsucesos+n>tamstring)
		resize(numsucesos+n);    
	for(int i=0;i<n;i++)
		sucesos[numsucesos+i]=suc[i];
	numsucesos=numsucesos+n;
}		
		
		
istream &operator>>(istream &i, const FechaHistorica &f){
	char s[500];
	char aux;
	string suc;
	i.getline(s,5,'#');
	f.anio=atoi(s);
	int nsucaniadidos=0;
	i.getline(s,500);
	for(int j=0;j<strlen(s)&& aux!='\n'&& i.get(aux) ;j++){
		if(aux!='#'&&)
			suc.insert(nsucaniadidos+j,1,aux);
		else{
			f.addsuceso(suc);
			nsucaniadidos++;
		}

ostream &operator>>(istream &i, const FechaHistorica &f){






	
