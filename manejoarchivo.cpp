#include "manejoarchivo.h"


void escribir_archivo(std::string name1, std::string name2, std::string ganador, std::string fichas)
{
    time_t now;
    struct tm nowLocal;
    now=time(NULL);
    nowLocal=*localtime(&now);

    cout<<nowLocal.tm_mday;
    std::fstream archivo("historial.dat",std::fstream::app);

    archivo<<(name1+","+name2+","+fecha+","+hora+","+ganador+","+fichas);
    archivo.close();

}
