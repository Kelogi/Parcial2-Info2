#include "tablero.h"

tablero::tablero()
{

}

void tablero::Actualizartablero(int MovX, int MovY, char ficha)
{
}

void tablero::actualizarArriba(int movX, int movY, char Ficha, char Fichacontrario)
{
    int PY_contraria;
    bool sandwich;
    int Fichas=0;
    if(movY>1){
        for(int k=movY-1;k>=0;k-=1){

            if(MatTablero[movX][k]==Ficha and Fichas+1==(movY-k) and Fichas!=0){
                sandwich=true;
                PY_contraria=k;
                break;
            }
            else{
                if(MatTablero[movX][k]==Fichacontrario) Fichas+=1;
            }
        }
        sandwich=false;

    }

    else{
      sandwich=false;
    }

    //si hay sandwich en esa direccion modificar la matriz.
    if(sandwich==true){
        for(int i=movY-1;i>PY_contraria;i--){
            MatTablero[movX][i]=Ficha;
        }

    }

}
