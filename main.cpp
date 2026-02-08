#include <iostream>
#include <iomanip>

#include "GestorRoles.h"      
#include "PerfilTrabajador.h"

using namespace std;

int main() {
    // ==========================================
    // PARTE 1: GESTOR DE ROLES
    // ==========================================
    GestorRoles gestor;
    cout << "=== MODULO 1: SELECCION DE ROL ===" << endl;
    
    Rol rolSeleccionado = gestor.seleccionarRol();

    // ==========================================
    // PARTE 2: PERFIL DEL TRABAJADOR
    // ==========================================
    cout << "\n=== MODULO 2: CREACION DE PERFIL ===" << endl;
    
    PerfilTrabajador miPerfil;
    // Pedimos los datos al usuario
    miPerfil.ingresarExperiencia();
    miPerfil.ingresarEducacion();
    miPerfil.ingresarHabilidades();

    cout << "\n[Sistema]: Analizando perfil para el puesto de " << rolSeleccionado.getNombre() << "..." << endl;

    // CALCULAMOS EL VALOR
    double valorMercado = CalculadoraSalarial::calcularValorMercado(miPerfil, rolSeleccionado);


    // ==========================================
    // SALIDA PARA LA SIGUIENTE PERSONA
    // ==========================================
    cout << "\n--------------------------------------------------" << endl;
    cout << " RESULTADO DEL ANALISIS DE MERCADO" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << fixed << setprecision(2);
    cout << "Rol: " << rolSeleccionado.getNombre() << endl;
    cout << "Salario Base del Rol: $" << rolSeleccionado.getSalarioBase() << endl;
    cout << "Valor de Mercado del Candidato: $" << valorMercado << endl;
    cout << "--------------------------------------------------" << endl;
    

    return 0;
}