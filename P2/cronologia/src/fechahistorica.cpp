#include "fechahistorica.h"
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
}
int FechaHistorica::getnumsucesos()const{return numsucesos;}

void FechaHistorica::setanio(int a){
	anio=a;
}
int FechaHistorica::getanio() const{return anio;}

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
		
		
istream &operator>>(istream &is, FechaHistorica &f){
	char s[500];
	char aux[100];
	string suc;
	is.getline(s,5,'#');
	f.anio=atoi(s);
	is.getline(s,500,'\n');
	int k=0;
	int j=0;

	while(s[j]!='\0'){
		if(s[j]!='#'){
			aux[k]=s[j];
			k++;
		}
		else{
			aux[k]='\0';
			suc=aux;
			f.addsuceso(suc);
			k=0;
		}
		j++;
	}
	aux[k]='\0';
	suc=aux;
	f.addsuceso(suc);
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




	
