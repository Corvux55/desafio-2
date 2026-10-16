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
    int capacidadMensajesEnviados;
    mensaje* mensajesRecibidos;
    int cantidadMensajesRecibidos;
    int capacidadMensajesRecibidos;

    char** solicitudesRecibidas; //nombres usuarios
    int cantidadSolicitudes;
    int capacidadSolicitudes;

    album* albumes;
    int cantidadAlbumes;
    int capacidadAlbumes;

    void redimensionarAmigos();
    void redimensionarMensajesEnviados();
    void redimensionarMensajesRecibidos();
    void redimensionarSolicitudes();
    void redimensionarAlbumes();
public:
    usuario();
    usuario(const char* nom, const Fecha& fn, const char* cor, const char* fp, const char* con, const char* ciu,const char* pai, const Fecha& fi);
    usuario(const usuario& otro);
    ~usuario();

    char* obtenerNombre() const;
    Fecha obtenerFechaNacimiento() const;
    char* obtenerCorreo() const;
    char* obtenerFotoPerfil() const;
    char* obtenerContraseña() const;
    char* obtenerCiudad() const;
    char* obtenerPais() const;
    Fecha obtenerFechaInscripcion() const;

    int obtenerCantidadAmigos() const;
    int obtenerCantidadMensajesEnviados() const;
    int obtenerCantidadMensajesRecibidos() const;
    int obtenerCantidadSolicitudes() const;
    int obtenerCantidadAlbumes() const;

    void agregarAmigo(usuario* u);
    bool esAmigo(usuario* u) const;
    usuario* obtenerAmigo(int indice) const;

    void agregarMensajeEnviado(const mensaje& m);
    void agregarMensajeRecibido(const mensaje& m);
    mensaje* obtenerMensajeEnviado(int indice) const;
    mensaje* obtenerMensajeRecibido(int indice) const;

    void agregarSolicitud(const char* nombreEmisor);
    char* obtenerSolicitud(int indice) const;
    void eliminarSolicitud(int indice);

    void agregarAlbum(const album& a);
    album* obtenerAlbum(int indice) const;
    album* buscarAlbum(const char* nombre) const;

    void mostrarAmigos() const;
    void mostrarAlbumes() const;
};

#endif // USUARIO_H
