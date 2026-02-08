#include "ControladorNegociacion.h"
#include <iostream>


using namespace std;

ControladorNegociacion::ControladorNegociacion(float ofertaInicial)
    : estado(ofertaInicial) {
}

void ControladorNegociacion::iniciarNegociacion() {
    vista.mostrarInicio();

    while (estado.estaActiva()) {
        vista.mostrarOferta(
            estado.getOfertaActual(),
            estado.getRondaActual()
        );

        vista.mostrarOpciones();
        int decision = vista.leerDecision();

        switch (decision) {

            // ACEPTAR
            case 1:
                vista.mostrarAcuerdo(estado.getOfertaActual());
                estado.finalizarNegociacion();
                break;

            // RECHAZAR
            case 2:
                estado.siguienteRonda();
                break;

            // CONTRAOFERTA
            case 3: {
                float contraoferta = vista.leerContraoferta();

                // Lógica simple de respuesta de la empresa
                float nuevaOferta = 
                    (estado.getOfertaActual() + contraoferta) / 2;

                estado.setOfertaActual(nuevaOferta);
                estado.siguienteRonda();
                break;
            }

            // RETIRARSE
            case 4:
                vista.mostrarConflicto();
                estado.finalizarNegociacion();
                break;

            default:
                cout << "Opción inválida. Intente nuevamente.\n";
                break;
        }
    }
}
