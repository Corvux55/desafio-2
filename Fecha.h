#ifndef FECHA_H
#define FECHA_H

class Fecha{
private:
    int dia;
    int mes;
    int año;
public:
    Fecha();
    Fecha(int d, int m, int a);
    Fecha(const Fecha& otra);
    //van a devolver las fechas
    int getDia() const;
    int getMes() const;
    int getAño() const;
    //cambiar las fechas
    void setDia(int d);
    void setMes(int m);
    void setAño(int a);

    int comparar(const Fecha& otra) const;
    bool esIgual(const Fecha& otra) const;
    bool esMenor(const Fecha& otra) const;
    bool esMayor(const Fecha& otra) const;
    bool operator<(const Fecha& otra) const; //permite escribir fecha1<fecha2
    bool operator==(const Fecha& otra) const;
};

#endif // FECHA_H
