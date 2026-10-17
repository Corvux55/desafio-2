#include <iostream>
#include "usuario.h"
#include "mensaje.h"
#include "album.h"
#include "foto.h"
#include "RedSocial.h"
using namespace std;

//por falta de tiempo solo probaremos los modulos ya terminados
int main(){
    cout << "PRUEBA DE MODULOS - UDE@BOOK" << endl;

    cout << "1. MODULO FECHA" << endl;
    Fecha hoy(17, 10, 2026);
    Fecha fnac(1, 1, 2001);
    Fecha finsc(1, 1, 2026);
    cout<< "Fecha de hoy: " <<hoy.getDia()<< "/"<<hoy.getMes() <<"/" << hoy.getAño()<< endl;
    cout<< "Fecha nacimiento: "<< fnac.getDia()<<"/"<< fnac.getMes()<<"/" << fnac.getAño() << endl;
    cout<< endl;

    cout<< "2. MODULO USUARIO Y AMIGOS"<< endl;
    usuario* u1 = new usuario("juanito", fnac, "juanito@udea.edu.co", "/users/.../profile.png", "123", "Medellin", "Colombia", finsc);
    usuario* u2 = new usuario("maria", fnac, "maria@udea.edu.co", "/users/.../profile.png", "456", "Bogota", "Colombia", finsc);
    usuario* u3 = new usuario("carlos", fnac, "carlos@udea.edu.co", "/users/.../profile.png", "789", "Cali", "Colombia", finsc); // <-- Agregamos a Carlos

    cout << "Se crearon los usuarios: "<< u1->obtenerNombre()<<" y " << u2->obtenerNombre()<< endl;

    // Haciendolos amigos
    u1->agregarAmigo(u2);
    u2->agregarAmigo(u1);
    cout<< "Ahora son amigos."<< endl;
    cout<< "Amigos de "<< u1->obtenerNombre()<< ":" << endl;
    u1->mostrarAmigos();
    cout << endl;

    cout<< "3. MODULO ALBUM Y FOTOS"<< endl;
    album a1("Cartagena2026", "/users/.../albums/Cartagena/", "amigos");

    foto f1(hoy, 2.5f, "/users/.../Cartagena/Malecon.png", 10);
    foto f2(hoy, 3.1f, "/users/.../Cartagena/Bocagrande.png", 20);
    foto f3(hoy, 1.8f, "/users/.../Cartagena/Castillo.png", 15);
    a1.agregarFoto(f1);
    a1.agregarFoto(f2);
    a1.agregarFoto(f3);

    u1->agregarAlbum(a1);
    cout<<"Album agregado a "<< u1->obtenerNombre()<<":"<< endl;
    u1->mostrarAlbumes();
    cout << endl;

    cout<< "4. MODULO MENSAJES"<< endl;
    mensaje m1("juanito", "maria", "Hola Maria, como estas?", hoy);
    u1->agregarMensajeEnviado(m1);
    u2->agregarMensajeRecibido(m1);
    cout<<"Mensaje enviado de "<< u1->obtenerNombre()<< " a "<< u2->obtenerNombre()<< endl;

    cout << "Maria revisa su bandeja de entrada:" << endl;
    int cant = u2->obtenerCantidadMensajesRecibidos();
    for(int i = 0; i < cant; i++) {
        u2->obtenerMensajeRecibido(i)->mostrarMensaje();
    }
    cout<< endl;

    cout<< "5. PRUEBA SOLICITUDES"<< endl;
    u2->agregarSolicitud("carlos");
    cout<< "Solicitudes pendientes de Maria: "<< u2->obtenerCantidadSolicitudes()<< endl;
    cout<< "1. "<< u2->obtenerSolicitud(0)<< endl;

    cout<< "\n Maria acepto la solicitud de Carlos..." << endl;
    u2->agregarAmigo(u3);
    u3->agregarAmigo(u2);

    u2->eliminarSolicitud(0);

    cout<< "Solicitud aceptada. Ahora son amigos." << endl;
    cout<< "Solicitudes de Maria ahora: "<< u2->obtenerCantidadSolicitudes() << endl;
    cout<< "Amigos de Maria ahora:"<< endl;
    u2->mostrarAmigos();
    cout<< endl;

    cout<<"6. MODULO REDSOCIAL (CARRUSEL) ---" << endl;
    RedSocial miRed;

    album* albumDeJuanito = u1->obtenerAlbum(0);
    if (albumDeJuanito != nullptr) {
        miRed.abrirCarrusel(*albumDeJuanito);
    }

    cout<< "LIMPIEZA DE MEMORIA"<< endl;
    delete u1;
    delete u2;
    delete u3;
    cout<<"Memoria liberada correctamente." << endl;
    cout<< "FIN DE LA DEMOSTRACION"<< endl;
    return 0;
}