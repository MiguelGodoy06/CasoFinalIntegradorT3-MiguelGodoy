#include <iostream>

// Declaración de las funciones definidas en Labmain.cpp
void load_script();
void load_script(const char* filename, bool show_script = false);

int main() {
    // Llamada a la función load_script para probarla
    load_script();
    return 0;  // Indica que el programa terminó correctamente
}