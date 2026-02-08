#ifndef GESTORROLES_H
#define GESTORROLES_H

#include <vector>
#include "Rol.h"
using namespace std;

class GestorRoles {
private:
    vector<Rol> rolesDisponibles; // conjunto de roles
    void inicializarRoles(); // cargar datos iniciales

public:
    GestorRoles();
    void mostrarMenu() const; // estado q0: mostrar opciones al usuario
    Rol seleccionarRol(); // transiciones y validacion

};

#endif
