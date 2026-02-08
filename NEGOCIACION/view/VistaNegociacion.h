#ifndef VISTA_NEGOCIACION_H
#define VISTA_NEGOCIACION_H

class VistaNegociacion {
public:
    void mostrarInicio();
    void mostrarOferta(float oferta, int ronda);
    void mostrarOpciones();
    int leerDecision();
    float leerContraoferta();
    void mostrarAcuerdo(float salarioFinal);
    void mostrarConflicto();
};

#endif
