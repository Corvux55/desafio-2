#include "foto.h"
#include <cstring>
#include <iostream>
using namespace std;

foto::foto():fechaCaptura(),tamañoMB(0.0f),likes(0){
    ruta = new char[1];
    ruta[0]= '\0';
}
foto::foto(const Fecha &f, float t, const char *r, int l):fechaCaptura(f),tamañoMB(t),likes(l){
    ruta = new char[strlen(r)+1];//reserva espacio para la ruta + \0
    strcpy(ruta,r);//copia la ruta
}
foto::foto(const foto &otra):fechaCaptura(otra.fechaCaptura),tamañoMB(otra.tamañoMB),likes(otra.likes){
    ruta = new char[strlen(otra.ruta)+1];
    strcpy(ruta,otra.ruta);
}
foto::~foto(){
    delete[] ruta;
}
Fecha foto::obtenerFechaCaptura() const {return fechaCaptura;} //getter
float foto::obtenerTamañoMB() const {return tamañoMB;}
char* foto::obtenerRuta() const {return ruta;}
int foto::obtenerLikes() const {return likes;}
void foto::darLike() {likes++;}
void foto::quitarLike(){if (likes>0) likes--;}
void foto::mostrarRuta() const{
    cout<<"Ruta: "<<ruta<<"| Likes: "<<likes<<endl;
}