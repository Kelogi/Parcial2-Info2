#ifndef TABLERO_H
#define TABLERO_H


class tablero
{
public:
    tablero();

    void Actualizartablero(int MovX,int MovY, char ficha);
    void actualizarArriba(int movX,int movY, char Ficha, char Fichacontrario);


private:

    char **MatTablero;
    char fichaDelMov;

};

#endif // TABLERO_H
