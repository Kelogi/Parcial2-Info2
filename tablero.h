#ifndef TABLERO_H
#define TABLERO_H
using namespace std;
#include <iostream>

class tablero
{
public:
    tablero();
    tablero( char **cargarMatriz);


    void actualizarTableroGeneral(int movX,int movY, char Ficha, char Fichacontrario);
    void actualizarArriba(int movX,int movY, char Ficha, char Fichacontrario);
    void actualizarAbajo(int movX,int movY, char Ficha, char Fichacontrario);
    void actualizarDerecha(int movX,int movY, char Ficha, char Fichacontrario);
    void actualizarIzq(int movX,int movY, char Ficha, char Fichacontrario);
    void actualizarD1(int movX,int movY, char Ficha, char Fichacontrario);
    void actualizarD2(int movX,int movY, char Ficha, char Fichacontrario);
    void actualizarD3(int movX,int movY, char Ficha, char Fichacontrario);
    void actualizarD4(int movX,int movY, char Ficha, char Fichacontrario);
    int saberCantidadFichas();

    void imprimirTablero();

private:
    int cantidadFichas;
    int tamanio_tablero=8;
    char **MatTablero;
};

#endif // TABLERO_H
