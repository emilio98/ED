#include "cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){



  if (argc!=3){
      cout<<"Dime el nombre del fichero con la cronologia"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   Cronologia mi_cronologia;
   f>>mi_cronologia; //Cargamos en memoria la cronología.


   /* Exhibir aquí la funcionalidad programada para el TDA Cronologia / TDA FechaHistorica */ 

   // Algunas sugerencias: 
   // - Obtener los eventos acaecidos en un año dado
   // - Obtener la (sub)cronología de eventos históricos acaecidos en [anioDesde, anioHasta], donde anioDesde y anioHasta son proporcionados por el usuario
   // - Obtener la (sub)cronología de eventos históricos asociados a una palabra clave. Ejemplo: la cronología de eventos asociados a "Einstein"
   // - Operadores sobre cronologías, ejemplo: Unión de dos cronologías (la cronología resultante debería estar ordenada)
   // - Cualquier otra funcionalidad que consideréis de interés
   cout << mi_cronologia ;
   f.close();
   ofstream s (argv[2]);
   if (!s){
    cout<<"No puedo abrir el fichero de salida "<<argv[2]<<endl;
    return 0;
   }
   s << mi_cronologia;
   s.close();
   ifstream w (argv[2]);
   if (!w){
    cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
    return 0;
   }
   FechaHistorica mifecha;
   w >> mifecha;
   w.close();
   Cronologia mi_cronologia2;
   w.open(argv[2]);
   w >> mi_cronologia2;
   cout << mi_cronologia2 << mifecha;
   w.close();
}
