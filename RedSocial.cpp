#include "RedSocial.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

RedSocial::RedSocial(){
    capacidadUsuarios=2;
    cantidadUsuarios=0;
    usuarioActual = nullptr;
    usuarios = new usuario*[capacidadUsuarios];
    matrizAmigos= nullptr;
    matrizConstruida= false;
    interacuinesActuales=0;
    memoriaConsumida=0;
}
RedSocial::~RedSocial(){
    for(int i = 0; i < cantidadUsuarios; i++){
        delete usuarios[i];
    }
    delete[] usuarios;
    liberarMatrizAdyacencia();//esta generando error
}
void RedSocial::redimensionarUsuarios(){
    capacidadUsuarios *=2;
    usuario** nuevo= new usuario*[capacidadUsuarios];
    for(int i=0; i<cantidadUsuarios; i++){
        nuevo[i]= usuarios[i];
    }
    delete[] usuarios;
    usuarios= nuevo;
}
usuario* RedSocial::buscarUsuario(const char *nombre) const{
    for(int i=0; i< cantidadUsuarios; i++){
        if(strcmp(usuarios[i]->obtenerNombre(),nombre)==0){
            return usuarios[i];
        }
    }
    return nullptr;
}
bool RedSocial::iniciarSesion(){
    char nombre[50],contra[50];
    cout <<"\n INICIAR SESION \n Usuario: ";
    cin >> nombre;
    cout <<"Contraseña: ";
    cin >> contra;
    usuario* u= buscarUsuario(nombre);
    if(u != nullptr && strcmp(u->obtenerContraseña(),contra)==0){
        usuarioActual=u;
        cout<<"\n Bienvanido "<<nombre<<endl;
        return true;
    }
    cout<<"\n Error: Datos incorrectos."<<endl;
    return false;
}
/* generan error (buscar solucion despues)
void RedSocial::mostrarMenu(){
    int opcion=0;
    while(opcion !=7){
        cout<<"MENU UDE@BOOK \n Usuario: "<<usuarioActual->obtenerNombre()<<endl;
        cout<<"1. Ver mis amigos\n";
        cout<<"2. Administrar amistades \n";
        cout<<"3. Visitar perfil de amigo \n";
        cout<<"4. Ver sugenrencias \n";
        cout<<"5. Administar mensajes\n";
        cout<<"6. Ver mis albumes\n";
        cout<<"7. Cerrar sesion\n";
        cout<< "opcion: ";
        cin>>opcion;

        switch (opcion) {
        case 1:
            cout<<"Mis Amigos \n";
            usuarioActual->mostrarAmigos();
            break;
        case 2:
            mostrarMenuAmistades();
            break;
        case 3:
            visitarPerfilAmigo();
            break;
        case 4:
            verSugerencias();
            break;
        case 5:
            mostrarMenuMensajes();
            break;
        case 6:
            usuarioActual->mostrarAlbumes();
            break;
        case 7:
            cout<<"Cerrando sesion...";
            usuarioActual = nullptr;
            break;
        default:
            cout<<"opcion invalida. \n";
            break;
        }
    }
}
void RedSocial::mostrarMenuMensajes(){
    int opc=0;
    while (opc !=4){
        cout<< "MENSAJES \n";
        cout<<"1. Enviar mensaje. \n 2. Leer mensaje. \n 3. Buscar por fecha. \n 4. volver. \n Opcion: ";
        cin>>opc;
        if(opc==1) enviarMensaje();
        else if (opc ==2) leerNuevosMensajes();
        else if (opc ==3) buscarMensajePorFecha();
    }
}
*/

//por falta de tiempo pondre este para probar carrusel
void RedSocial::abrirCarrusel(album& a){
    int cantidad = a.obtenerCantidadFotos();
    if(cantidad == 0){
        cout << "El album esta vacio." << endl;
        return;
    }
    int indice = 0;
    bool salir = false;
    while(!salir){
        foto* actual = a.obtenerFoto(indice);
        cout<< "\n Viendo foto " << (indice + 1) << " de " << cantidad << endl;
        actual->mostrarRuta();
        cout<< "Opciones: [s]iguiente, [p]revia, [l]ike, [q]uitar like, [x]salir"<< endl;
        cout<< "Tu opcion: ";
        char opc;
        cin>> opc;
        switch (opc){
        case 's': indice = (indice + 1) % cantidad; break;
        case 'p': indice = (indice - 1 + cantidad) % cantidad; break;
        case 'l': actual->darLike(); break;
        case 'q': actual->quitarLike(); break;
        case 'x': salir = true; break;
        }
    }
}
void RedSocial::liberarMatrizAdyacencia(){}//solucion momentaria pa que copile