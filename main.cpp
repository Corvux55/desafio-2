#include <iostream>
#include "Fecha.h"
#include "foto.h"
#include "mensaje.h"
using namespace std;

int main() {

    // ============ PRUEBA FECHA ============
    cout << "=== PRUEBA FECHA ===" << endl;

    Fecha f1(15, 3, 2026);
    Fecha f2(20, 3, 2026);
    Fecha f3(15, 3, 2026);

    cout << "f1: " << f1.getDia() << "/" << f1.getMes() << "/" << f1.getAño() << endl;
    cout << "f2: " << f2.getDia() << "/" << f2.getMes() << "/" << f2.getAño() << endl;
    cout << "f1 < f2?  " << (f1 < f2 ? "Si" : "No") << endl;
    cout << "f1 == f3? " << (f1 == f3 ? "Si" : "No") << endl;
    cout << endl;

    // ============ PRUEBA FOTO ============
    cout << "=== PRUEBA FOTO ===" << endl;

    foto foto1(f1, 2.5f,
               "/users/udeabook_data/iuanito76/albums/Cartagena2026/Malecon2612.png",
               42);

    cout << "Foto creada:" << endl;
    foto1.mostrarRuta();

    foto1.darLike();
    cout << "Despues de darLike:" << endl;
    foto1.mostrarRuta();

    foto1.quitarLike();
    foto1.quitarLike();
    cout << "Despues de quitarLike x2:" << endl;
    foto1.mostrarRuta();

    foto foto2 = foto1;
    cout << "Copia de la foto:" << endl;
    foto2.mostrarRuta();

    cout << "Tamaño en MB: " << foto1.obtenerTamañoMB() << endl;
    cout << "Likes: " << foto1.obtenerLikes() << endl;
    cout << endl;

    // ============ PRUEBA MENSAJE ============
    cout << "=== PRUEBA MENSAJE ===" << endl;

    mensaje m1("iuanito76", "maria99", "Hola, como estas?", f1);

    cout << "Mensaje 1:" << endl;
    m1.mostrarMensaje();
    cout << "Leido? " << (m1.estaLeido() ? "Si" : "No") << endl;

    m1.marcarLeido();
    cout << "Despues de marcarLeido:" << endl;
    cout << "Leido? " << (m1.estaLeido() ? "Si" : "No") << endl;

    Fecha inicio(1, 3, 2026);
    Fecha fin(31, 3, 2026);
    cout << "Esta entre 1/3/2026 y 31/3/2026? "
         << (m1.rangoFechas(inicio, fin) ? "Si" : "No") << endl;

    mensaje m2 = m1;
    cout << "Copia del mensaje:" << endl;
    m2.mostrarMensaje();

    return 0;
}