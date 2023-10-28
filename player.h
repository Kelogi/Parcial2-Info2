#ifndef PLAYER_H
#define PLAYER_H
using namespace std;
#include <iostream>


class player
{
public:
    player(char **ptr_cargar, int cargar_tam, char ficha);
    player();


    bool movimientoP1ayer();
    void recibirMov_Player();

    bool verificarMovArriba(int x, int y);
    bool verificarMovAbajo(int x, int y);
    bool verificarMovDerecha(int x, int y);
    bool verificarMovIzq(int x, int y);
    bool verificarMovD1(int x, int y);
    bool verificarMovD2(int x, int y);
    bool verificarMovD3(int x, int y);
    bool verificarMovD4(int x, int y);

    int SaberMovX();
    int SaberMovY();


private:
    char ficha_jugador;
    char ficha_contrario;
    int tamaniotablero;
    char **tableroPlayer; //Matriz del juego
    int cantidad_fichas=2;//cantidad de fichas negras Player1.

    // variables que contienen la informacion del movimiento.
    int MovX;
    char MovY;

};

#endif // PLAYER_H
