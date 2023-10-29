#include "player.h"
#include "tablero.h"
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
               puntero_tablero[i][j]=' ';
           }
           else if (i==(tamanio_tablero/2) and j==(tamanio_tablero/2)-1){
               //ficha negra (-)
               puntero_tablero[i][j]=' ';
           }
           else if (i==(tamanio_tablero/2)-1 and j==(tamanio_tablero/2)-1){
               //ficha blanca (*)
               puntero_tablero[i][j]=' ';
           }
           else if (i==(tamanio_tablero/2)-1 and j==(tamanio_tablero/2)){
               //ficha negra (-)
               puntero_tablero[i][j]=' ';
           }

           else{
               puntero_tablero[i][j]=' ';
           }
      }
   }

    puntero_tablero[7][0]='-';
    puntero_tablero[6][1]='*';
    puntero_tablero[5][2]='*';
    puntero_tablero[4][3]='*';
    puntero_tablero[3][4]='*';
    puntero_tablero[2][5]='*';
    puntero_tablero[1][6]='*';





   tablero tablerito(puntero_tablero);

   tablerito.imprimirTablero();

   tablerito.actualizarD3(0,7,'-','*');
   cout<<"\n";
   cout<<"\n";
   cout<<"\n";
   //tablerito.actualizarArriba(3,2,'-','*');
   //tablerito.actualizarAbajo(3,2,'-','*');
   //tablerito.actualizarDerecha(3,2,'-','*');
   //tablerito.actualizarIzq(3,2,'-','*');
   tablerito.imprimirTablero();




    cout << "Hello World!" << endl;
    return 0;
}
