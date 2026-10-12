#include "Fecha.h"
Fecha::Fecha():dia(1), mes(1), año(2000){}//constructor vacio
Fecha::Fecha(int d, int m, int a):dia(d),mes(m),año(a){}
Fecha::Fecha(const Fecha &otra):dia(otra.dia),mes(otra.mes),año(otra.año){}

int Fecha::getDia() const{return dia;}
int Fecha::getMes() const{return mes;}
int Fecha::getAño() const{return año;}

void Fecha::setDia(int d){dia=d;}
void Fecha::setMes(int m){mes=m;}
void Fecha::setAño(int a){año=a;}

//devuelve segun el signo si fecha es mayor o menor que otra, si devuelve cero son iguales
int Fecha::comparar(const Fecha &otra) const{
    if (año != otra.año) return año-otra.año;
    if (mes != otra.mes) return mes-otra.mes;
    return dia-otra.dia;
}
bool Fecha::esIgual(const Fecha &otra) const{
    return comparar(otra)==0;
}
bool Fecha::esMenor(const Fecha &otra) const{
    return comparar(otra)<0;
}
bool Fecha::esMayor(const Fecha &otra) const{
    return comparar(otra)>0;
}
bool Fecha::operator <(const Fecha& otra) const{
    return esMenor(otra);
}
bool Fecha::operator ==(const Fecha& otra) const{
    return esIgual(otra);
}
