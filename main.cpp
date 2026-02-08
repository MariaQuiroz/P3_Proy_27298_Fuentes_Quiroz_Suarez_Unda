#include <iostream>
#include "GestorRoles.h"
using namespace std;

int main() {
    GestorRoles gestor;

    cout << "-> Modulo 1: Configuracion Inicial..." << endl;

    Rol rolSeleccionado = gestor.seleccionarRol();

    cout << "\n--- DATOS DE SALIDA DEL MODULO (INTEGRACION) ---" << endl;
    cout << "Perfil:" << endl; //para modulo persona 2
    cout << " - Rol Base: " << rolSeleccionado.getNombre() << endl;
    cout << " - Demanda Calculada: " << rolSeleccionado.getFactorDemanda() << endl;

    cout << "Negociacion:" << endl; //para modulo persona 3
    cout << " - Piso de negociacion: $" << rolSeleccionado.getSalarioBase() << endl;
    cout << " - Techo de la empresa (OCULTO): $" << rolSeleccionado.getPresupuestoMaxEmpresa() << endl;

    cout << "\n[Modulo 1 finalizado correctamente]" << endl;

    return 0;
}
