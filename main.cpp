#include "player.h"
#include "tablero.h"
#include "manejo_archivos.h"
#include <iostream>

using namespace std;

int main()
{



    int tamanio_tablero=8;
    //se guarda la matriz del juego en memoria dinamica
    char **puntero_tablero = new char *[tamanio_tablero];
    for( int i = 0; i < tamanio_tablero; i++){
        puntero_tablero[i] = new char[tamanio_tablero];
    }

    // se colocan las fichas que van en el centro del tablero, las que estan vacias tienen un caracter: " ".
    for(int i = 0; i < tamanio_tablero; i++){
       for(int j = 0; j < tamanio_tablero; j++){


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

    //objeto tablero
   tablero tablerito(puntero_tablero);

   //dos objetos tipo jugador
   player fichasNegras(puntero_tablero,tamanio_tablero, '-');
   player fichasBlancas(puntero_tablero,tamanio_tablero, '*');


   int eleccion;
   cout<<"-Digite 1 para jugar."<<"\n";
   cout<<"-Digite 2 para observar el historial."<<"\n";
   cin>>eleccion;
   bool QuienJuega=true; //comienzan las negras
   for(;true;){

       if(eleccion ==1){

           if(tablerito.saberCantidadFichas()!=64){
               if(QuienJuega==true){

                   cout<<"Turno fichas negras"<<"\n";
                   if(fichasNegras.movimientoP1ayer()==true){
                       tablerito.imprimirTablero();
                       fichasNegras.recibirMov_Player();
                       tablerito.actualizarTableroGeneral(fichasNegras.SaberMovX(),fichasNegras.SaberMovY(),'-','*');
                   }
                   else{
                       cout<<"No tienes movimientos permitidos"<<"\n";

                   }
                   QuienJuega=false;
               }

               else{

                   cout<<"Turno fichas blancas"<<"\n";
                   if(fichasBlancas.movimientoP1ayer()==true){
                       tablerito.imprimirTablero();
                       fichasBlancas.recibirMov_Player();
                       tablerito.actualizarTableroGeneral(fichasBlancas.SaberMovX(),fichasBlancas.SaberMovY(),'*','-');
                   }
                   else{
                       cout<<"No tienes movmientos permitidos"<<"\n";

                   }
                   QuienJuega=true;

               }
            }
           else{
               cout<<"-----------FIN DEL JUEGO-----------";
               tablerito.imprimirTablero();
               string nameNegras,nameBlancas;
               cout<<"Nombre jugador-fichas negras: ";
               cin>>nameNegras;
               cout<<"Nombre jugador-fichas blancas: ";
               cin>>nameBlancas;
               cout<<"----------------RESULTADOS-------------"<<"\n";
               cout<<"fichas negras: "<<fichasNegras.cantidadFichas_Jugador()<<"\n";
               cout<<"fichas blancas: "<<fichasBlancas.cantidadFichas_Jugador()<<"\n";
               if(fichasNegras.cantidadFichas_Jugador()>fichasBlancas.cantidadFichas_Jugador()){
                   cout<<"FICHAS NEGRAS GANADORAS DEL JUEGO."<<"\n";
                    //actualizar datos de la partida
                   escribirArchivo(nameNegras,nameBlancas,nameNegras,to_string(fichasNegras.cantidadFichas_Jugador()));
                   break;
               }
               else if(fichasNegras.cantidadFichas_Jugador()<fichasBlancas.cantidadFichas_Jugador()){
                   cout<<"FICHAS BLANCAS GANADORAS DEL JUEGO."<<"\n";
                   //actualizar datos de la partida
                    escribirArchivo(nameNegras,nameBlancas,nameBlancas,to_string(fichasBlancas.cantidadFichas_Jugador()));
                   break;
               }
               else cout<<"EMPATE"<<"\n";
               break;
           }
      }

      else{
           saberhistorial();
           break;
       }

   }

    return 0;
}
