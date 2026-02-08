#include "PerfilTrabajador.h"
#include <limits>

PerfilTrabajador::PerfilTrabajador() : aniosExperiencia(0), educacion(SIN_TITULO), nivelHabilidad(50) {}

void PerfilTrabajador::ingresarExperiencia() {
    do {
        cout << "\n>> Ingrese sus anios de experiencia (0-50): ";
        cin >> aniosExperiencia;
        if (aniosExperiencia < 0 || aniosExperiencia > 50) cout << "Dato no valido.\n";
    } while (aniosExperiencia < 0 || aniosExperiencia > 50);
}

void PerfilTrabajador::ingresarEducacion() {
    int opcion;
    cout << "\n>> Nivel Educativo:\n 1.Sin Titulo\n 2.Bachiller\n 3.Tecnologo\n 4.Profesional\n 5.Postgrado\n Opcion: ";
    cin >> opcion;
    if (opcion >= 1 && opcion <= 5) educacion = static_cast<NivelEducativo>(opcion);
    else educacion = SIN_TITULO;
}

void PerfilTrabajador::ingresarHabilidades() {
    cout << "\n>> Nivel de habilidad practica (0-100): ";
    cin >> nivelHabilidad;
    if(nivelHabilidad > 100) nivelHabilidad = 100;
    if(nivelHabilidad < 0) nivelHabilidad = 0;
}

int PerfilTrabajador::obtenerAniosExperiencia() const { return aniosExperiencia; }
NivelEducativo PerfilTrabajador::obtenerEducacion() const { return educacion; }
int PerfilTrabajador::obtenerNivelHabilidad() const { return nivelHabilidad; }


// --- IMPLEMENTACIÓN: CalculadoraSalarial ---

double CalculadoraSalarial::calcularValorMercado(const PerfilTrabajador& perfil, Rol rol) {

    double valorBase = rol.getSalarioBase();

    double multipExperiencia = 1.0 + (perfil.obtenerAniosExperiencia() * 0.03);

    double bonoEducacion = 0.0;
    switch (perfil.obtenerEducacion()) {
        case SIN_TITULO:         bonoEducacion = 0.0; break;
        case BACHILLER:          bonoEducacion = 50.0; break;
        case TECNOLOGO:          bonoEducacion = 150.0; break;
        case TITULO_PROFESIONAL: bonoEducacion = 300.0; break;
        case POSTGRADO:          bonoEducacion = 600.0; break;
    }

    double plusDemanda = valorBase * (rol.getFactorDemanda() * 0.1);

    // CÁLCULO FINAL
    double valorFinal = (valorBase * multipExperiencia) + bonoEducacion + plusDemanda;

    if (perfil.obtenerNivelHabilidad() > 80) {
        valorFinal += 50.0;
    }

    return valorFinal;
}
