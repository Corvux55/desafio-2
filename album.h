#ifndef ALBUM_H
#define ALBUM_H
#include "foto.h"
class album{
private:
    char* nombre;
    char* ruta;
    char* privacidad;
    foto* fotos; //arreglo dinamico de fotos
    int cantidadFotos;
    int capacidadFotos;
    void redimensionar();
public:
    album();
    album(const char*n, const char* r, const char* p);
    album(const album& otro);
    ~album();
    char* obtenerNombre() const;
    char* obtenerRuta() const;
    char* obtenerPrivacidad() const;
    int obtenerCantidadFotos() const;

    //se agrego esta parte que no estaba en diagrama(se nos olvido agregarlo)
    void agregarFoto(const foto& f);

    foto* obtenerFoto(int indice) const;
    void mostrarFotos() const;
    bool visiblePara(const char* rol) const;
};

#endif // ALBUM_H
