#ifndef CONTROLADOR_NEGOCIACION_H
#define CONTROLADOR_NEGOCIACION_H

#include "../model/EstadoNegociacion.h"
#include "../view/VistaNegociacion.h"

class ControladorNegociacion {
private:
    EstadoNegociacion estado;
    VistaNegociacion vista;

public:
    ControladorNegociacion(float ofertaInicial);
    void iniciarNegociacion();
};

#endif
