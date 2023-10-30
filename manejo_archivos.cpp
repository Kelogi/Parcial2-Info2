#include "manejo_archivos.h"
#include <iostream>


void escribirArchivo(string name1, string name2, string ganador, string fichas)
{
    //saber datos actuales
    time_t now;
    struct tm nowLocal;
    now=time(NULL);
    nowLocal=*localtime(&now);
    string dia=to_string(nowLocal.tm_mday);
    string mes=to_string(nowLocal.tm_mon+1);
    string anio=to_string(nowLocal.tm_year+1900);
    string hora=to_string(nowLocal.tm_hour);
    string minutos=to_string(nowLocal.tm_min);
    string segundos=to_string(nowLocal.tm_sec);

    fstream Archivo("historialGame.txt", fstream::app);
    if(Archivo.is_open()) Archivo<<(name1+","+name2+","+ganador+","+fichas+","+dia+"/"+mes+"/"+anio+","+hora+":"+minutos+":"+segundos+"\n");

}

void saberhistorial()
{
    fstream Archivo("historialGame.txt", fstream::in);
    if(Archivo.is_open()){
        cout<<"HISTORIAL DEL JUEGO: "<<"\n";
        string linea="";
        while(!Archivo.eof()){
            getline(Archivo,linea);
            cout<<linea+"\n";
        }

    }


}
