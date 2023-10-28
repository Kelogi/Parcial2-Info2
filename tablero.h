#ifndef TABLERO_H
#define TABLERO_H


class tablero
{
public:
    tablero();

    void Actualizartablero(int MovX,int MovY, char ficha);
    void actualizarArriba(int movX,int movY, char Ficha, char Fichacontrario);
    void actualizarAbajo(int movX,int movY, char Ficha, char Fichacontrario);
    void actualizarDerecha(int movX,int movY, char Ficha, char Fichacontrario);


private:

    char **MatTablero;
};

#endif // TABLERO_H
