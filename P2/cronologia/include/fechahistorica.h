#ifndef FECHAHISTORICA_H
#define FECHAHISTORICA_H

class FechaHistorica{
private:

	int anio,numsucesos,tamstring;
	string *sucesos;
	void resize(int tam);
public:

FechaHistorica();

FechaHistorica(int fecha, string *suc, int numsuc);

FechaHistorica(const FechaHistorica &f);

~FechaHistorica();

void setanio(int a);
int getanio() const;

void addsuceso(string suc);
void addsucesos(string *suc, int n);
		
		
friend istream &operator>>(istream &i, const FechaHistorica &f);
	

friend ostream &operator>>(istream &i, const FechaHistorica &f);
};

istream &operator>>(istream &i, const FechaHistorica &f);
	

ostream &operator>>(istream &i, const FechaHistorica &f);
#endif
