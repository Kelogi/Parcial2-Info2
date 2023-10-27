#include "player.h"
#include <iostream>

using namespace std;

int main()
{
    int tamanio_tablero=8, tam_tablero=8;
    //se guarda la matriz del juego en memoria dinamica
    char **puntero_tablero = new char *[tam_tablero];
    for( int i = 0; i < tam_tablero; i++){
        puntero_tablero[i] = new char[tam_tablero];
    }

    // se colocan las fichas que van en el centro del tablero, las que estan vacias tienen un caracter: " ".
    for(int i = 0; i < tam_tablero; i++){
       for(int j = 0; j < tam_tablero; j++){


           if(i==(tamanio_tablero/2) and j==(tamanio_tablero/2) ){
               //ficha blanca (*)
               puntero_tablero[i][j]='*';
           }
           else if (i==(tamanio_tablero/2) and j==(tamanio_tablero/2)-1){
               //ficha negra (-)
               puntero_tablero[i][j]='-';
           }
           else if (i==(tamanio_tablero/2)-1 and j==(tamanio_tablero/2)-1){
               //ficha blanca (*)
               puntero_tablero[i][j]='*';
           }
           else if (i==(tamanio_tablero/2)-1 and j==(tamanio_tablero/2)){
               //ficha negra (-)
               puntero_tablero[i][j]='-';
           }

           else{
               puntero_tablero[i][j]=' ';
           }
      }
   }

    puntero_tablero[4][4]='*';
    puntero_tablero[4][3]='-';
    puntero_tablero[3][3]='*';
    puntero_tablero[3][4]='*';
    puntero_tablero[3][5]='-';
    puntero_tablero[2][6]='-';

    puntero_tablero[5][4]='-';
    puntero_tablero[5][5]='*';




   player negras(puntero_tablero,8, '-');
   negras.movimientoP1ayer();





    cout << "Hello World!" << endl;
    return 0;
}
