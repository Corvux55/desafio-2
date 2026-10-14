#ifndef MENSAJE_H
#define MENSAJE_H
#include "Fecha.h"

class mensaje{
private:
    char* emisor;
    char* receptor;
    char* texto;
    Fecha fechaEnvio;
    bool leido;
public:
    mensaje();
    mensaje(const char* em, const char* re, const char* tx, const Fecha& f);
    mensaje(const mensaje& otro); //copia del constructor
    ~mensaje();
    char* obtenerEmisor() const;
    char* obtenerReceptor() const;
    char* obtenerTexto() const;
    Fecha obtenerFecha() const;
    bool estaLeido() const;
    void marcarLeido();
    void mostrarMensaje() const;
    bool rangoFechas(const Fecha& inicio, const Fecha& fin) const;
};

#endif // MENSAJE_H
