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
    bool verificarMovArriba(int x, int y);
    bool verificarMovAbajo(int x, int y);
    bool verificarMovDerecha(int x, int y);
    bool verificarMovIzq(int x, int y);
    bool verificarMovD1(int x, int y);
    bool verificarMovD2(int x, int y);
    bool verificarMovD3(int x, int y);
    bool verificarMovD4(int x, int y);

    void recibirMov_Player();


private:
    char ficha_jugador;
    char ficha_contrario;
    int tamaniotablero;
    char **tableroPlayer; //Matriz del juego
    int cantidad_fichas=2;//cantidad de fichas negras Player1.
};

#endif // PLAYER_H
