#ifndef USUARIO_H
#define USUARIO_H
#include "Fecha.h"
#include "mensaje.h"
#include "album.h"

class usuario{
private:
    char* nombre;
    Fecha fechaNacimiento;
    char* correo;
    char* ciudad;
    char* fotoPerfil;
    char* contraseña;
    char* pais;
    Fecha fechaInscripcion;

    usuario** amigos; //arreglo dinamico de punteros a amigos
    int cantidadAmigos;
    int capacidadAmigos;

    mensaje* mensajesEnviados;
    int cantidadMensajesEnviados;
    int capacidadMEnsajesEnviados;
    mensaje* mensajesRecibidos;
    int cantidadMensajesRecibidos;
    int capacidadMensajesRecibidos;

    char** solicidudesRecibidas; //nombres usuarios
    int cantidadSolicitudes;
    int capacidadSolicitudes;

    album* albumes;
    int cantidadAlbumes;
    int capacidadAlbumes;

    void redimensionarAmigos();
    void redimensionarMensajesEnviados();
    void redimensionarMensajesRecibidis();
    void redimensionaeSolicitudes();
    void redimensionarAlbumes();
public:

};

#endif // USUARIO_H
