#include "tablero.h"

tablero::tablero()
{

}

tablero::tablero(char **cargarMatriz)
{
    MatTablero=cargarMatriz;
}


void tablero::actualizarTableroGeneral(int movX, int movY, char Ficha, char Fichacontrario)
{
    MatTablero[movX][movY]=Ficha;
    actualizarArriba(movX,movY,Ficha,Fichacontrario);
    actualizarAbajo(movX,movY,Ficha,Fichacontrario);
    actualizarIzq(movX,movY,Ficha,Fichacontrario);
    actualizarDerecha(movX,movY,Ficha,Fichacontrario);
    actualizarD1(movX,movY,Ficha,Fichacontrario);
    actualizarD2(movX,movY,Ficha,Fichacontrario);
    actualizarD3(movX,movY,Ficha,Fichacontrario);
    actualizarD4(movX,movY,Ficha,Fichacontrario);

}

void tablero::actualizarArriba(int movX, int movY, char Ficha, char Fichacontrario)
{
    MatTablero[movX][movY]=Ficha;

    int PY_contraria;
    bool sandwich=false;
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

void tablero::actualizarAbajo(int movX, int movY, char Ficha, char Fichacontrario)
{
    bool sandwich=false;
    int PY_contraria;
    int Fichas=0;

    if(movY<6){
        for(int k=movY+1;k<=7;k++){

            if(MatTablero[movX][k]==Ficha and Fichas+1==k-movY and Fichas!=0){
                sandwich=true;
                PY_contraria=k;
                break;
            }
            else{
                if(MatTablero[movX][k]==Fichacontrario) Fichas+=1;
            }
        }

    }

    else{
      sandwich= false;
    }

    //si hay sandwich en esa direecion modificar la matriz

    if(sandwich==true){
        for(int i=movY+1;i<PY_contraria;i++){
            MatTablero[movX][i]=Ficha;
        }
    }
}

void tablero::actualizarDerecha(int movX, int movY, char Ficha, char Fichacontrario)
{
    bool sandwich=false;
    int PX_contraria;
    int Fichas=0;

    if(movX<6){
        for(int k=movX+1;k<=7;k++){

            if(MatTablero[k][movY]==Ficha and Fichas+1==k-movX and Fichas!=0){
                sandwich=true;
                PX_contraria=k;
                break;
            }
            else{
                if(MatTablero[k][movY]==Fichacontrario) Fichas+=1;
            }
        }

    }

    else{
        sandwich=false;
    }


    if(sandwich==true){
        for(int i=movX+1;i<PX_contraria;i++){
            MatTablero[i][movY]=Ficha;
        }
    }

}

void tablero::actualizarIzq(int movX, int movY, char Ficha, char Fichacontrario)
{

    bool sandwich=false;
    int PX_contraria;
    int Fichas=0;

    if(movX>1){
        for(int k=movX-1;k>=0;k--){

            if(MatTablero[k][movY]==Ficha and Fichas+1==movX-k and Fichas!=0){
                sandwich=true;
                PX_contraria=k;
                break;
            }
            else{
                if(MatTablero[k][movY]==Fichacontrario) Fichas+=1;
            }
        }

    }

    else{
     sandwich=false;
    }

    if(sandwich==true){
        for(int i=movX-1;i>PX_contraria;i--){
            MatTablero[i][movY]=Ficha;
        }
    }

}

void tablero::actualizarD1(int movX, int movY, char Ficha, char Fichacontrario)
{

    bool sandwich=false;

    int Fichas=0;
    int auxiliar_x=movX;
    int auxiliar_y=movY;


    if(auxiliar_x>1 and auxiliar_y<6){
        while (auxiliar_x>0 and auxiliar_y<7){
            auxiliar_x-=1;
            auxiliar_y+=1;

            if(MatTablero[auxiliar_x][auxiliar_y]==Ficha and auxiliar_y-movY-1==Fichas and Fichas!=0){
                sandwich=true;
                break;
            }

            else{
                if(MatTablero[auxiliar_x][auxiliar_y]==Fichacontrario) Fichas+=1;
            }
        }
    }
    else{
        sandwich=false;
    }


    //actualizar tablero
    if(sandwich==true){
        auxiliar_x=movX-1;
        auxiliar_y=movY+1;
        for(int i=0;i<Fichas;i++){
            MatTablero[auxiliar_x][auxiliar_y]=Ficha;

            auxiliar_x-=1;
            auxiliar_y+=1;
        }
    }
}

void tablero::actualizarD2(int movX, int movY, char Ficha, char Fichacontrario)
{
    bool sandwich=false;
    int Fichas=0;
    int auxiliar_x=movX;
    int auxiliar_y=movY;

    while (auxiliar_x<7 and auxiliar_y<7){
        auxiliar_x+=1;
        auxiliar_y+=1;

        if(MatTablero[auxiliar_x][auxiliar_y]==Ficha and auxiliar_x-movX-1==Fichas and Fichas!=0){
            sandwich=true;
            break;
        }

        else{
            if(MatTablero[auxiliar_x][auxiliar_y]==Fichacontrario) Fichas+=1;
        }
    }

    //actualizar tablero
    if(sandwich==true){
        auxiliar_x=movX+1;
        auxiliar_y=movY+1;
        for(int i=0;i<Fichas;i++){
            MatTablero[auxiliar_x][auxiliar_y]=Ficha;

            auxiliar_x+=1;
            auxiliar_y+=1;
        }
    }

}

void tablero::actualizarD3(int movX, int movY, char Ficha, char Fichacontrario)
{
    bool sandwich=false;
    int Fichas=0;
    int auxiliar_x=movX;
    int auxiliar_y=movY;

    while (auxiliar_x<7 and auxiliar_y>0){
        auxiliar_x+=1;
        auxiliar_y-=1;

        if(MatTablero[auxiliar_x][auxiliar_y]==Ficha and movY-auxiliar_y-1==Fichas and Fichas!=0){
            sandwich=true;
            break;
        }

        else{
            if(MatTablero[auxiliar_x][auxiliar_y]==Fichacontrario) Fichas+=1;
        }
    }

    //actualizar tablero
    if(sandwich==true){
        auxiliar_x=movX+1;
        auxiliar_y=movY-1;
        for(int i=0;i<Fichas;i++){
            MatTablero[auxiliar_x][auxiliar_y]=Ficha;

            auxiliar_x+=1;
            auxiliar_y-=1;
        }
    }


}

void tablero::actualizarD4(int movX, int movY, char Ficha, char Fichacontrario)
{
    bool sandwich=false;
    int Fichas=0;
    int auxiliar_x=movX;
    int auxiliar_y=movY;

    while (auxiliar_x>0 and auxiliar_y>0){
        auxiliar_x-=1;
        auxiliar_y-=1;

        if(MatTablero[auxiliar_x][auxiliar_y]==Ficha and movX-auxiliar_x-1==Fichas and Fichas!=0){
            sandwich=true;
            break;
        }

        else{
            if(MatTablero[auxiliar_x][auxiliar_y]==Fichacontrario) Fichas+=1;
        }
    }

    //actualizar tablero
    if(sandwich==true){
        auxiliar_x=movX-1;
        auxiliar_y=movY-1;
        for(int i=0;i<Fichas;i++){
            MatTablero[auxiliar_x][auxiliar_y]=Ficha;

            auxiliar_x-=1;
            auxiliar_y-=1;
        }
    }


}

int tablero::saberCantidadFichas()
{
    cantidadFichas=0;
    for(int i=0;i<tamanio_tablero;i++){
        for(int j=0;j<tamanio_tablero;j++){
            if(MatTablero[j][i]=='*' or MatTablero[j][i]=='-') cantidadFichas+=1;
        }
    }
    return cantidadFichas;
}



void tablero::imprimirTablero()
{
    //siempre que cambie las dimensiones del tablero se deben organizar la cantidad de lineas horizontales que se imprimen en los cout.
    cout<<"---------------------------------"<<"\n";
    int fila=1;
    for(int i=0;i<tamanio_tablero;i++){
        for(int j=0;j<tamanio_tablero;j++){
            cout<<"| ";
            cout<<MatTablero[j][i]<<" ";
            if((j+1)%tamanio_tablero==0){
                cout<<"|"<<" "<<fila<<"\n";
                fila+=1;
                cout<<"---------------------------------"<<"\n";
            }

        }

    }

    cout<<"  A   B   C   D   E   F   G   H";
    cout<<"\n";
}

