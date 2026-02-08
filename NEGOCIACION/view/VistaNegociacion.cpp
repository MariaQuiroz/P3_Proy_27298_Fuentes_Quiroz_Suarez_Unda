#include "VistaNegociacion.h"
#include <iostream>

using namespace std;

void VistaNegociacion::mostrarInicio() {
    cout << "\n===== NEGOCIACIÓN =====\n";
}

void VistaNegociacion::mostrarOferta(float oferta, int ronda) {
    cout << "\nRonda " << ronda << endl;
    cout << "Oferta actual de la empresa: $" << oferta << endl;
}

void VistaNegociacion::mostrarOpciones() {
    cout << "\nSeleccione una opción:\n";
    cout << "1. Aceptar oferta\n";
    cout << "2. Rechazar oferta\n";
    cout << "3. Realizar contraoferta\n";
    cout << "4. Retirarse de la negociación\n";
}

int VistaNegociacion::leerDecision() {
    int opcion;
    cout << "Opción: ";
    cin >> opcion;
    return opcion;
}

float VistaNegociacion::leerContraoferta() {
    float contraoferta;
    cout << "Ingrese su contraoferta salarial: $";
    cin >> contraoferta;
    return contraoferta;
}

void VistaNegociacion::mostrarAcuerdo(float salarioFinal) {
    cout << "\nSE ALCANSO A UN ACUERDO\n";
    cout << "Salario final acordado: $" << salarioFinal << endl;
}

void VistaNegociacion::mostrarConflicto() {
    cout << "\nNO SE LOGRO UN ACUERDO, FINALIZA LA NEGOCIACION\n";
}
