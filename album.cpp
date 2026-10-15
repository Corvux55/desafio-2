#include "album.h"
#include <cstring>
#include <iostream>
using namespace std;

album::album(): cantidadFotos(0),capacidadFotos(2){
    nombre= new char[1]; nombre[0] ='\0';//nombre vacio
    ruta =new char[1]; ruta[0]='\n';
    privacidad = new char[8];
    strcpy(privacidad,"privado");
    fotos = new foto[capacidadFotos];
}
album::album(const char *n, const char *r, const char *p):cantidadFotos(0),capacidadFotos(2){
    nombre=new char[strlen(n)+1];strcpy(nombre,n);
    ruta= new char[strlen(r)+1];strcpy(ruta,r);
    privacidad =new char[strlen(p)+1]; strcpy(privacidad,p);
    fotos=new foto[capacidadFotos];
}
album::album(const album &otro):cantidadFotos(otro.cantidadFotos),capacidadFotos(otro.capacidadFotos){
    nombre = new char[strlen(otro.nombre)+1];strcpy(nombre,otro.nombre);
    ruta=new char[strlen(otro.ruta)+1];strcpy(ruta,otro.ruta);
    privacidad= new char[strlen(otro.privacidad)+1];strcpy(privacidad,otro.privacidad);
    fotos=new foto[capacidadFotos];for(int i=0;i<cantidadFotos;i++){
        fotos[i]=otro.fotos[i];//copia del arreglo de fotos
    }
}
album::~album(){
    delete[] nombre;
    delete[] ruta;
    delete[] privacidad;
    delete[] fotos;
}
void album::redimensionar(){
    capacidadFotos *=2; //duplicamos capacidad
    foto* nuevo =new foto[capacidadFotos];for(int i=0;i<cantidadFotos;i++){
        nuevo[i]=fotos[i];
    }
    delete[] fotos;
    fotos=nuevo;
}
char* album::obtenerNombre() const {return nombre;}
char* album::obtenerRuta() const {return ruta;}
char* album::obtenerPrivacidad() const {return privacidad;}
int album::obtenerCantidadFotos() const {return cantidadFotos;}

void album::agregarFoto(const foto &f){
    if(cantidadFotos==capacidadFotos){
        redimensionar();
    }
    fotos[cantidadFotos] =f;
    cantidadFotos++;
}
foto* album::obtenerFoto(int indice) const{
    if(indice<0 || indice>= cantidadFotos){
        return nullptr;//puntero nulo
    }
    return &fotos[indice];
}
void album::mostrarFotos() const{
    for(int i=0;i<cantidadFotos;i++){
        fotos[i].mostrarRuta();
    }
}
bool album::visiblePara(const char *rol) const{
    if(strcmp(privacidad, "publico") ==0) return true;
    if(strcmp(rol,"dueño")==0) return true;
    if(strcmp(privacidad,"amigos")==0 && strcmp(rol,"amigo")==0) return true;
    return false;
}