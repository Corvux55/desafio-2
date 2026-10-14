#include "mensaje.h"
#include <cstring>
#include <iostream>
using namespace std;

mensaje::mensaje():fechaEnvio(), leido(false){
    emisor = new char[1]; emisor[0]= '\0';
    receptor = new char[1]; receptor[0]= '\0';
    texto = new char[1]; texto[0]='\0';
}
mensaje::mensaje(const char *em, const char *re, const char *tx, const Fecha &f):fechaEnvio(f), leido(false){
    emisor = new char[strlen(em)+1]; strcpy(emisor,em);
    receptor = new char[strlen(re)+1];strcpy(receptor, re);
    texto= new char[strlen(tx)+1];strcpy(texto,tx);
}
//copia de constructor
mensaje::mensaje(const mensaje &otro):fechaEnvio(otro.fechaEnvio),leido(otro.leido){
    emisor = new char[strlen(otro.emisor)+1]; strcpy(emisor,otro.emisor);
    receptor = new char[strlen(otro.receptor)+1];strcpy(receptor, otro.receptor);
    texto= new char[strlen(otro.texto)+1];strcpy(texto,otro.texto);
}
mensaje::~mensaje(){
    delete[] emisor;
    delete[] receptor;
    delete[] texto;
}
char* mensaje::obtenerEmisor() const {return emisor;}
char* mensaje::obtenerReceptor() const {return receptor;}
char* mensaje::obtenerTexto() const {return texto;}
Fecha mensaje::obtenerFecha() const {return fechaEnvio;}
bool mensaje::estaLeido() const {return leido;}//cambia de estado
void mensaje::marcarLeido(){
    leido = true;
}
void mensaje::mostrarMensaje() const{
    cout<< "De: "<<emisor<< " | Fecha: "<<fechaEnvio.getDia()<<"/"<<fechaEnvio.getMes()<<"/"<<fechaEnvio.getAño()<<" | "<< texto<<endl;
}
bool mensaje::rangoFechas(const Fecha &inicio, const Fecha &fin) const{
    return !fechaEnvio.esMenor(inicio) && !fechaEnvio.esMayor(fin);
}