#ifndef ESTADO_NEGOCIACION_H
#define ESTADO_NEGOCIACION_H

class EstadoNegociacion {
private:
    int rondaActual;
    int maxRondas;
    float ofertaActual;
    bool activa;

public:
    // Constructor
    EstadoNegociacion(float ofertaInicial, int maxRondas = 5);

    // Getters
    int getRondaActual() const;
    float getOfertaActual() const;
    bool estaActiva() const;

    // Acciones sobre el estado
    void setOfertaActual(float oferta);
    void siguienteRonda();
    void finalizarNegociacion();
};

#endif
