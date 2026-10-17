#ifndef REDSOCIAL_H
#define REDSOCIAL_H
#include "usuario.h"
#include <iostream>
using namespace std;

class RedSocial{
private:
    usuario** usuarios;
    int cantidadUsuarios;
    int capacidadUsuarios;
    usuario* usuarioActual;

    bool** matrizAmigos;
    bool matrizConstruida;
    long long interacuinesActuales;
    long long memoriaConsumida;
    void redimensionarUsuarios();
    void construirMatrizAdyacencia();
    void liberarMatrizAdyacencia();
    //cargar archivo txt con los datos
    void cargarUsuarios();
    void cargarALbumes();
    void cargarFotos();
    void cargarMensajes();
    void cargarAmistades();
    void cargarSolicitudes();

    void guardarUsuarios();
    void guardarAmistades();
    void guardarMensajes();
    void guardarAlbumes();
    void guardarSolicitudes();
public:
    RedSocial();
    ~RedSocial();

    void cargarDatos();
    void guardarDatos();
    bool iniciarSesion();
    void mostrarMenu();
    void mostrarMenuAmistades();
    void mostrarMenuMensajes();
    usuario* buscarUsuario(const char* nombre) const;
    int amigosEnComun(usuario* u1, usuario* u2) const;
    void mostrarMejoresAmigos();
    void actualizarMejoresAmigos();
    void enviarSolicitud();
    void aceptarSolicitud();
    void visitarPerfilAmigo();
    void abrirCarrusel(album& a);
    void verSugerencias();
    void enviarSolicitudSugenrencia(const char* nombre);
    void enviarMensaje();
    void leerNuevosMensajes();
    void buscarMensajePorFecha();
    void iniciarMedicion();
    void detenerMedicion(const char* nombreFuncionalidad);
    void contarIteracion();
    void sumarMemoria(long long bytes);
};

#endif // REDSOCIAL_H
