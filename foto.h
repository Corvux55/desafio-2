#ifndef FOTO_H
#define FOTO_H
#include "Fecha.h"

class foto{
private:
    Fecha fechaCaptura;
    float tamañoMB;
    char* ruta;
    int likes;
public:
    foto();
    foto(const Fecha& f,float t, const char* r, int l);
    foto(const foto& otra);//crea una copia
    ~foto();

    Fecha obtenerFechaCaptura() const;
    float obtenerTamañoMB() const;
    char* obtenerRuta() const;
    int obtenerLikes() const;

    void darLike();
    void quitarLike();
    void mostrarRuta() const;
};

#endif // FOTO_H
