#include "usuario.h"
#include <cstring>
#include <iostream>
using namespace std;

usuario::usuario(): fechaNacimiento(), fechaInscripcion(),cantidadAmigos(0), capacidadAmigos(2),cantidadMensajesEnviados(0), capacidadMensajesEnviados(2),
    cantidadMensajesRecibidos(0), capacidadMensajesRecibidos(2),cantidadSolicitudes(0), capacidadSolicitudes(2),cantidadAlbumes(0), capacidadAlbumes(2){
    //cadenas vacias pa datos
    nombre= new char[1]; nombre[0]= '\0';
    correo= new char[1]; correo[0]='\0';
    fotoPerfil= new char[1]; fotoPerfil[0]='\0';
    contraseña= new char[1]; contraseña[0]='\0';
    ciudad= new char[1]; ciudad[0]='\0';
    pais= new char[1]; pais[0]='\0';

    //arreglos dinamicos
    amigos= new usuario*[capacidadAmigos];
    mensajesEnviados= new mensaje[capacidadMensajesEnviados];
    mensajesRecibidos= new mensaje[capacidadMensajesRecibidos];
    solicitudesRecibidas= new char*[capacidadSolicitudes];
    albumes= new album[capacidadAlbumes];
}
usuario::usuario(const char *nom, const Fecha &fn, const char *cor, const char *fp, const char *con, const char *ciu, const char *pai, const Fecha &fi):
    fechaNacimiento(fn), fechaInscripcion(fi), cantidadAmigos(0), capacidadAmigos(2), cantidadMensajesEnviados(0), capacidadMensajesEnviados(2), cantidadMensajesRecibidos(0),
    capacidadMensajesRecibidos(2),cantidadSolicitudes(0), capacidadSolicitudes(2), cantidadAlbumes(0), capacidadAlbumes(2){
    nombre=new char[strlen(nom)+1];strcpy(nombre,nom);
    correo=new char[strlen(cor)+1]; strcpy(correo,cor);
    fotoPerfil=new char[strlen(fp)+1];strcpy(fotoPerfil, fp);
    contraseña=new char[strlen(con)+1]; strcpy(contraseña,con);
    ciudad=new char[strlen(ciu)+1];strcpy(ciudad,ciu);
    pais=new char[strlen(pai)+1]; strcpy(pais,pai);

    amigos=new usuario*[capacidadAmigos];
    mensajesEnviados=new mensaje[capacidadMensajesEnviados];
    mensajesRecibidos=new mensaje[capacidadMensajesRecibidos];
    solicitudesRecibidas=new char*[capacidadSolicitudes];
    albumes=new album[capacidadAlbumes];
}
usuario::usuario(const usuario& otro): fechaNacimiento(otro.fechaNacimiento),fechaInscripcion(otro.fechaInscripcion),cantidadAmigos(otro.cantidadAmigos),capacidadAmigos(otro.capacidadAmigos),
    cantidadMensajesEnviados(otro.cantidadMensajesEnviados),capacidadMensajesEnviados(otro.capacidadMensajesEnviados),cantidadMensajesRecibidos(otro.cantidadMensajesRecibidos),
    capacidadMensajesRecibidos(otro.capacidadMensajesRecibidos),cantidadSolicitudes(otro.cantidadSolicitudes),capacidadSolicitudes(otro.capacidadSolicitudes),cantidadAlbumes(otro.cantidadAlbumes),
    capacidadAlbumes(otro.capacidadAlbumes){

    nombre= new char[strlen(otro.nombre) + 1]; strcpy(nombre, otro.nombre);
    correo= new char[strlen(otro.correo) + 1]; strcpy(correo, otro.correo);
    fotoPerfil= new char[strlen(otro.fotoPerfil) + 1]; strcpy(fotoPerfil, otro.fotoPerfil);
    contraseña= new char[strlen(otro.contraseña) + 1]; strcpy(contraseña, otro.contraseña);
    ciudad= new char[strlen(otro.ciudad) + 1]; strcpy(ciudad, otro.ciudad);
    pais= new char[strlen(otro.pais) + 1]; strcpy(pais, otro.pais);

    amigos= new usuario*[capacidadAmigos];
    for (int i= 0; i< cantidadAmigos; i++){
        amigos[i] = otro.amigos[i];
    }
    mensajesEnviados = new mensaje[capacidadMensajesEnviados];
    for (int i= 0; i< cantidadMensajesEnviados; i++){
        mensajesEnviados[i] = otro.mensajesEnviados[i];
    }
    mensajesRecibidos = new mensaje[capacidadMensajesRecibidos];
    for (int i= 0; i< cantidadMensajesRecibidos; i++){
        mensajesRecibidos[i] = otro.mensajesRecibidos[i];
    }
    solicitudesRecibidas = new char*[capacidadSolicitudes];
    for (int i= 0; i< cantidadSolicitudes; i++) {
        solicitudesRecibidas[i] = new char[strlen(otro.solicitudesRecibidas[i]) + 1];
        strcpy(solicitudesRecibidas[i], otro.solicitudesRecibidas[i]);
    }
    albumes = new album[capacidadAlbumes];
    for (int i = 0; i < cantidadAlbumes; i++){
        albumes[i] = otro.albumes[i];
    }
}
usuario::~usuario(){
    delete[] nombre;
    delete[] correo;
    delete[] fotoPerfil;
    delete[] contraseña;
    delete[] ciudad;
    delete[] pais;
    delete[] amigos;
    delete[] mensajesEnviados;
    delete[] mensajesRecibidos;
    for (int i = 0; i < cantidadSolicitudes; i++) {
        delete[] solicitudesRecibidas[i];   //cada nombre reservado
    }
    delete[] solicitudesRecibidas;
    delete[] albumes;
}
void usuario::redimensionarAmigos(){
    capacidadAmigos *= 2;
    usuario** nuevo = new usuario*[capacidadAmigos];
    for (int i= 0; i < cantidadAmigos; i++) {
        nuevo[i]= amigos[i];
    }
    delete[] amigos;
    amigos= nuevo;
}
void usuario::redimensionarMensajesEnviados(){
    capacidadMensajesEnviados *= 2;
    mensaje* nuevo= new mensaje[capacidadMensajesEnviados];
    for (int i= 0; i< cantidadMensajesEnviados; i++) {
        nuevo[i]= mensajesEnviados[i];
    }
    delete[] mensajesEnviados;
    mensajesEnviados = nuevo;
}
void usuario::redimensionarMensajesRecibidos(){
    capacidadMensajesRecibidos *= 2;
    mensaje* nuevo = new mensaje[capacidadMensajesRecibidos];
    for (int i= 0; i< cantidadMensajesRecibidos; i++) {
        nuevo[i] = mensajesRecibidos[i];
    }
    delete[] mensajesRecibidos;
    mensajesRecibidos = nuevo;
}
void usuario::redimensionarSolicitudes(){
    capacidadSolicitudes *= 2;
    char** nuevo = new char*[capacidadSolicitudes];
    for (int i= 0; i< cantidadSolicitudes;i++){
        nuevo[i] = solicitudesRecibidas[i]; //solo copia el puntero
    }
    delete[] solicitudesRecibidas;
    solicitudesRecibidas= nuevo;
}
void usuario::redimensionarAlbumes(){
    capacidadAlbumes *= 2;
    album* nuevo= new album[capacidadAlbumes];
    for (int i= 0; i< cantidadAlbumes; i++){
        nuevo[i] = albumes[i];
    }
    delete[] albumes;
    albumes= nuevo;
}
char* usuario::obtenerNombre() const {return nombre;}
Fecha usuario::obtenerFechaNacimiento() const {return fechaNacimiento;}
char* usuario::obtenerCorreo() const {return correo;}
char* usuario::obtenerFotoPerfil() const {return fotoPerfil;}
char* usuario::obtenerContraseña() const {return contraseña;}
char* usuario::obtenerCiudad() const {return ciudad;}
char* usuario::obtenerPais() const {return pais;}
Fecha usuario::obtenerFechaInscripcion() const {return fechaInscripcion;}
int usuario::obtenerCantidadAmigos() const {return cantidadAmigos;}
int usuario::obtenerCantidadMensajesEnviados() const {return cantidadMensajesEnviados;}
int usuario::obtenerCantidadMensajesRecibidos() const {return cantidadMensajesRecibidos;}
int usuario::obtenerCantidadSolicitudes() const {return cantidadSolicitudes;}
int usuario::obtenerCantidadAlbumes() const {return cantidadAlbumes;}

void usuario::agregarAmigo(usuario* u){
    if (cantidadAmigos == capacidadAmigos){
        redimensionarAmigos(); // aumenta si esta lleno
    }
    amigos[cantidadAmigos] = u; //guarda el puntero al otro usuario
    cantidadAmigos++;
}
bool usuario::esAmigo(usuario* u) const{
    for (int i= 0; i < cantidadAmigos; i++){
        if (amigos[i] == u){ //compara punteros(usuarios)
            return true;
        }
    }
    return false;
}
usuario* usuario::obtenerAmigo(int indice) const {
    if (indice < 0 || indice >= cantidadAmigos){
        return nullptr; //indice invalido
    }
    return amigos[indice]; //devuelve el puntero
}
void usuario::agregarMensajeEnviado(const mensaje& m){
    if(cantidadMensajesEnviados == capacidadMensajesEnviados){
        redimensionarMensajesEnviados();//aumenta
    }
    mensajesEnviados[cantidadMensajesEnviados]= m; //copia el mensaje
    cantidadMensajesEnviados++;
}
void usuario::agregarMensajeRecibido(const mensaje& m){
    if(cantidadMensajesRecibidos == capacidadMensajesRecibidos){
        redimensionarMensajesRecibidos();
    }
    mensajesRecibidos[cantidadMensajesRecibidos] = m;
    cantidadMensajesRecibidos++;
}
mensaje* usuario::obtenerMensajeEnviado(int indice) const{
    if(indice< 0 || indice >= cantidadMensajesEnviados){
        return nullptr;
    }
    return &mensajesEnviados[indice];
}
mensaje* usuario::obtenerMensajeRecibido(int indice) const{
    if(indice< 0 || indice >= cantidadMensajesRecibidos){
        return nullptr;
    }
    return &mensajesRecibidos[indice];
}
void usuario::agregarSolicitud(const char* nombreEmisor){
    if(cantidadSolicitudes == capacidadSolicitudes){
        redimensionarSolicitudes();
    }
    //reserva memoria para copiar el nombre del emisor
    solicitudesRecibidas[cantidadSolicitudes] = new char[strlen(nombreEmisor) + 1];strcpy(solicitudesRecibidas[cantidadSolicitudes], nombreEmisor);
    cantidadSolicitudes++;
}
char* usuario::obtenerSolicitud(int indice) const{
    if(indice< 0 || indice >= cantidadSolicitudes){
        return nullptr;
    }
    return solicitudesRecibidas[indice]; //devuelve el nombre
}
void usuario::eliminarSolicitud(int indice){
    if(indice< 0 || indice >= cantidadSolicitudes){
        return;
    }
    delete[] solicitudesRecibidas[indice];
    //mueve los siguientes un lugar hacia atras
    for (int i= indice; i< cantidadSolicitudes - 1; i++){
        solicitudesRecibidas[i] = solicitudesRecibidas[i + 1];
    }
    solicitudesRecibidas[cantidadSolicitudes - 1] = nullptr;//la ultima posicion queda duplicada, se pone en nullptr
    cantidadSolicitudes--;
}
void usuario::agregarAlbum(const album& a){
    if (cantidadAlbumes == capacidadAlbumes){
        redimensionarAlbumes();
    }
    albumes[cantidadAlbumes] = a;//copia album
    cantidadAlbumes++;
}
album* usuario::obtenerAlbum(int indice) const{
    if (indice< 0 || indice >= cantidadAlbumes){
        return nullptr;
    }
    return &albumes[indice];
}
album* usuario::buscarAlbum(const char* nombre) const{
    for (int i= 0; i< cantidadAlbumes; i++){
        if (strcmp(albumes[i].obtenerNombre(), nombre) == 0){
            return &albumes[i];
        }
    }
    return nullptr;
}
void usuario::mostrarAmigos() const{
    if (cantidadAmigos == 0){
        cout<< " (no tiene amigos)"<< endl;
        return;
    }
    for (int i= 0; i< cantidadAmigos; i++){
        cout<< " " << (i+ 1) << ". " << amigos[i]->obtenerNombre()<< endl;
    }
}
void usuario::mostrarAlbumes() const{
    if (cantidadAlbumes == 0){
        cout << " (no tiene albumes)" <<endl;
        return;
    }
    for (int i = 0; i < cantidadAlbumes; i++){
        cout << " "<< (i + 1)<< ". " << albumes[i].obtenerNombre()
        << " [" << albumes[i].obtenerPrivacidad() << "]"
        << " (" << albumes[i].obtenerCantidadFotos() << " fotos)" << endl;
    }
}