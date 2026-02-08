#include "GestorRoles.h"
#include <iostream>
#include <limits> // validar entradas numericas
using namespace std;

GestorRoles::GestorRoles() { // inicializa el conjunto de datos al crear el gestor
    inicializarRoles();
}

void GestorRoles::inicializarRoles() {
    // parametros: Puesto, Salario Base, Presupuesto Max (oculto), Factor Demanda
    rolesDisponibles.push_back(Rol("Conserje", 400.0, 600.0, 0.3));
    rolesDisponibles.push_back(Rol("Secretaria", 600.0, 800.0, 0.5));
    rolesDisponibles.push_back(Rol("Tecnico", 800.0, 1100.0, 0.7));
    rolesDisponibles.push_back(Rol("Ingeniero", 1200.0, 2000.0, 0.9));
}

void GestorRoles::mostrarMenu() const {
    cout << "\n=== SIMULADOR DE NEGOCIACION SALARIAL ===" << endl;
    cout << "Seleccione el puesto al que desea postular:" << endl;
    for (size_t i = 0; i < rolesDisponibles.size(); ++i) {
        cout << i + 1 << ". ";
        rolesDisponibles[i].mostrarInfo();
    }
    cout << "=========================================" << endl;
}

Rol GestorRoles::seleccionarRol() { // implementacion AFD para validacion
    int opcion = 0;
    bool esValido = false;

    while (!esValido) { // Bucle: estado de espera hasta recibir una entrada valida
        mostrarMenu();
        cout << "Ingrese el numero de su opcion (1 - " << rolesDisponibles.size() << "): ";

        if (!(cin >> opcion)) {
            cout << "[ERROR] Entrada no valida. Por favor ingrese un numero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');}
        else if (opcion >= 1 && opcion <= static_cast<int>(rolesDisponibles.size())) {
            esValido = true; // estado de Aceptacion
        }
        else {
            cout << "[ERROR] Opcion fuera de rango. Intente nuevamente." << endl;
        }
    }

    cout << "\n- Has postulado para: " << rolesDisponibles[opcion - 1].getNombre() << endl;

    return rolesDisponibles[opcion - 1];
}
