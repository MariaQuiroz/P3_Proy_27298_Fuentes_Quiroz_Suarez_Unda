#ifndef ROL_H
#define ROL_H

#include <string>
#include <iostream>
using namespace std;

class Rol {
private:
    string nombre;
    double salarioBase; // limite inferior -visible para usuario
    double presupuestoMaxEmpresa; // limite superior -oculto para usuario
    double factorDemanda; // factor arbitrario, es entre 0.0 a 1.0

public:
    Rol(string n, double base, double max, double demanda)
        : nombre(n), salarioBase(base), presupuestoMaxEmpresa(max), factorDemanda(demanda) {}

    Rol() : nombre(""), salarioBase(0), presupuestoMaxEmpresa(0), factorDemanda(0) {}

    // Getters
    string getNombre() const { return nombre; }
    double getSalarioBase() const { return salarioBase; }
    double getPresupuestoMaxEmpresa() const { return presupuestoMaxEmpresa; }
    double getFactorDemanda() const { return factorDemanda; }

    void mostrarInfo() const { // mostrar info basica sin revelar datos ocultos
        cout << "Puesto: " << nombre << " | Salario Base: $" << salarioBase << endl;
    }
};

#endif
