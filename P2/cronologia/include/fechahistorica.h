#ifndef _FECHAHISTORICA_H_
#define _FECHAHISTORICA_H_

#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
using namespace std;
class FechaHistorica{
private:

	int anio,numsucesos,tamstring;
	string* sucesos;
	void resize(int tam);
public:

FechaHistorica();

FechaHistorica(int fecha, string* suc, int numsuc);

FechaHistorica(const FechaHistorica &f);

~FechaHistorica();

void setanio(int a);
int getanio() const;
int getnumsucesos()const;
void addsuceso(string suc);
void addsucesos(string *suc, int n);
		
FechaHistorica &operator=(const FechaHistorica &f);
friend istream &operator>>(istream &is, FechaHistorica &f);
	

friend ostream &operator<<(ostream &o, const FechaHistorica &f);
};

istream &operator>>(istream &is, FechaHistorica &f);
	

ostream &operator<<(ostream &o, const FechaHistorica &f);
#endif
