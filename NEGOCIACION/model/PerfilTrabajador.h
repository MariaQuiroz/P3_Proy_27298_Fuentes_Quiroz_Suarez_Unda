#ifndef PERFILTRABAJADOR_H
#define PERFILTRABAJADOR_H

#include <iostream>
#include "Rol.h"

using namespace std;

enum NivelEducativo {
    SIN_TITULO = 1,
    BACHILLER,
    TECNOLOGO,
    TITULO_PROFESIONAL,
    POSTGRADO
};

// Clase para guardar datos del usuario
class PerfilTrabajador {
private:
    int aniosExperiencia;
    NivelEducativo educacion;
    int nivelHabilidad;

public:
    PerfilTrabajador();
    void ingresarExperiencia();
    void ingresarEducacion();
    void ingresarHabilidades();

    // Getters
    int obtenerAniosExperiencia() const;
    NivelEducativo obtenerEducacion() const;
    int obtenerNivelHabilidad() const;
};

class CalculadoraSalarial {
public:
    static double calcularValorMercado(const PerfilTrabajador& perfil, Rol rol);
};

#endif
