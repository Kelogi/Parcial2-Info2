#include "player.h"
player::player()
{

}


player::player(char **ptr_cargar, int cargar_tam, char ficha)
{
    tableroPlayer=ptr_cargar;
    tamaniotablero=cargar_tam;
    ficha_jugador=ficha;

    if(ficha_jugador=='-') ficha_contrario='*';

    else ficha_contrario='-';
}

bool player::movimientoP1ayer()
{

    bool verificacionArriba=false;
    bool verificacionAbajo=false;
    bool verificacionIzq=false;
    bool verificacionDerecha=false;
    bool verificacionD1=false;
    bool verificacionD2=false;
    bool verificacionD3=false;
    bool verifiacionD4=false;

    int cantidad_Movimientos=0;
    //Verificar que P1 puede realizar movmientos, si puede, se le informa cuales puede realizar.
    for(int i = 0; i < tamaniotablero; i++){
       for(int j = 0; j < tamaniotablero; j++){
           //verificar movimientos verticales y horizontales en esa casilla en especifico

           if(tableroPlayer[i][j]==' '){
              verificacionArriba = verificarMovArriba(i,j);
              verificacionAbajo = verificarMovAbajo(i,j);
              verificacionDerecha = verificarMovDerecha(i,j);

              verificacionIzq = verificarMovIzq(i,j);
              //verificar movimiento en diagonales en esa casilla en especifico
              verificacionD1 = verificarMovD1(i,j);
              verificacionD2 = verificarMovD2(i,j);
              verificacionD3 = verificarMovD3(i,j);
              verifiacionD4 = verificarMovD4(i,j);

              if(verificacionArriba==true or verificacionAbajo==true or verificacionDerecha==true or verificacionIzq==true or
                      verificacionD1==true or verificacionD2==true or verificacionD3==true or verifiacionD4==true){
                       cout<<"Movimiento en, fila: "<<j+1<<" columna: "<<i+1<<"\n";
                       cantidad_Movimientos+=1;
              }
          }

      }
   }

    if(cantidad_Movimientos==0) return false;
    else return true;

}



bool player::verificarMovArriba(int x, int y)
{
    int Fichas=0; // Para Contar la cantidad de fichas opuestas a las que el presenta un objeto de la clase (Jugador) para  verificar posible saduche en una casilla en especifico.

    if(y>1){
        for(int k=y-1;k>=0;k-=1){

            if(tableroPlayer[x][k]==ficha_jugador and Fichas+1==(y-k) and Fichas!=0){
                return true;
                break;
            }
            else{
                if(tableroPlayer[x][k]==ficha_contrario) Fichas+=1;
            }
        }

    }

    else{
      return false;
    }
    return false;
}

bool player::verificarMovAbajo(int x, int y)
{
    int Fichas=0; // Para Contar la cantidad de fichas opuestas a las que el presenta un objeto de la clase (Jugador) para  verificar posible saduche en una casilla en especifico.

    if(y<6){
        for(int k=y+1;k<=7;k++){

            if(tableroPlayer[x][k]==ficha_jugador and Fichas+1==k-y and Fichas!=0){
                return true;
            }
            else{
                if(tableroPlayer[x][k]==ficha_contrario) Fichas+=1;
            }
        }

    }

    else{
      return false;
    }

    return false;
}

bool player::verificarMovDerecha(int x, int y)
{
    int Fichas=0;

    if(x<6){
        for(int k=x+1;k<=7;k++){

            if(tableroPlayer[k][y]==ficha_jugador and Fichas+1==k-x and Fichas!=0){
                return true;
                break;
            }
            else{
                if(tableroPlayer[k][y]==ficha_contrario) Fichas+=1;
            }
        }

    }

    else{
      return false;
    }
    return false;
}

bool player::verificarMovIzq(int x, int y)
{

    int Fichas=0;

    if(x>1){
        for(int k=x-1;k>=0;k--){

            if(tableroPlayer[k][y]==ficha_jugador and Fichas+1==x-k and Fichas!=0){
                return true;
            }
            else{
                if(tableroPlayer[k][y]==ficha_contrario) Fichas+=1;
            }
        }

    }

    else{
      return false;
    }
    return false;
}

bool player::verificarMovD1(int x, int y) //para verificar movimiento en la diagonal inferior izquierda
{
    int Fichas=0;
    int auxiliar_x=x;
    int auxiliar_y=y;


    if(auxiliar_x>1 and auxiliar_y<6){
        while (auxiliar_x>0 and auxiliar_y<7){
            auxiliar_x-=1;
            auxiliar_y+=1;

            if(tableroPlayer[auxiliar_x][auxiliar_y]==ficha_jugador and auxiliar_y-y-1==Fichas and Fichas!=0) return true;

            else{
                if(tableroPlayer[auxiliar_x][auxiliar_y]==ficha_contrario) Fichas+=1;
            }
        }
    }
    else return false;

    return false;

}

bool player::verificarMovD2(int x, int y) //para verificar movimiento en la diagonal inferior derecha
{

    int Fichas=0;
    int auxiliar_x=x;
    int auxiliar_y=y;

    while (auxiliar_x<7 and auxiliar_y<7){
        auxiliar_x+=1;
        auxiliar_y+=1;

        if(tableroPlayer[auxiliar_x][auxiliar_y]==ficha_jugador and auxiliar_x-x-1==Fichas and Fichas!=0) return true;

        else{
            if(tableroPlayer[auxiliar_x][auxiliar_y]==ficha_contrario) Fichas+=1;
        }
    }

    return false;

}

bool player::verificarMovD3(int x, int y)
{
    int Fichas=0;
    int auxiliar_x=x;
    int auxiliar_y=y;

    while (auxiliar_x<7 and auxiliar_y>0){
        auxiliar_x+=1;
        auxiliar_y-=1;

        if(tableroPlayer[auxiliar_x][auxiliar_y]==ficha_jugador and y-auxiliar_y-1==Fichas and Fichas!=0) return true;

        else{
            if(tableroPlayer[auxiliar_x][auxiliar_y]==ficha_contrario) Fichas+=1;
        }
    }
    return false;

}

bool player::verificarMovD4(int x, int y)
{

    int Fichas=0;
    int auxiliar_x=x;
    int auxiliar_y=y;

    while (auxiliar_x>0 and auxiliar_y>0){
        auxiliar_x-=1;
        auxiliar_y-=1;

        if(tableroPlayer[auxiliar_x][auxiliar_y]==ficha_jugador and x-auxiliar_x-1==Fichas and Fichas!=0) return true;

        else{
            if(tableroPlayer[auxiliar_x][auxiliar_y]==ficha_contrario) Fichas+=1;
        }
    }
    return false;
}



