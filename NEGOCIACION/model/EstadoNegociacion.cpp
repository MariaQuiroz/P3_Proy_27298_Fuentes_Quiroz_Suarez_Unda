#include "EstadoNegociacion.h"

// Constructor
EstadoNegociacion::EstadoNegociacion(float ofertaInicial, int maxRondas) {
    this->rondaActual = 1;
    this->maxRondas = maxRondas;
    this->ofertaActual = ofertaInicial;
    this->activa = true;
}

// Getters
int EstadoNegociacion::getRondaActual() const {
    return rondaActual;
}

float EstadoNegociacion::getOfertaActual() const {
    return ofertaActual;
}

bool EstadoNegociacion::estaActiva() const {
    return activa;
}

// Acciones
void EstadoNegociacion::setOfertaActual(float oferta) {
    ofertaActual = oferta;
}

void EstadoNegociacion::siguienteRonda() {
    rondaActual++;
    if (rondaActual > maxRondas) {
        activa = false;
    }
}

void EstadoNegociacion::finalizarNegociacion() {
    activa = false;
}
