#include "labmain.h"
#include <iostream>
#include <fstream>   // Biblioteca para manejo de archivos
#include <string>
using namespace std;

// Función que carga un script desde un archivo
void load_script(const char* filename, bool show_script = false) {
    ifstream file(filename);  // Abre el archivo para lectura
    if (!file.is_open()) {  // Verifica si el archivo se abrió correctamente
        cerr << "Error: No se pudo abrir el archivo " << filename << std::endl;
        return;  // Sale de la función si no se pudo abrir el archivo
    }

    std::string line;  // Variable para almacenar cada línea del archivo
    while (getline(file, line)) {  // Lee el archivo línea por línea
        if (file.bad()) {  // Verifica si hubo un error de lectura
            cerr << "Error: Se produjo un error de lectura en el archivo " << filename << std::endl;
            break;  // Sale del bucle si hubo un error de lectura
        }
        if (show_script) {  // Si show_script es verdadero, muestra la línea en la consola
            cout << line << endl;
        }
        // Aquí puedes agregar la lógica para aplicar la coloración sintáctica
    }

    file.close();  // Cierra el archivo
}

// Función que pide al usuario el nombre de un archivo y lo carga
void load_script() {
    string filename;  // Variable para almacenar el nombre del archivo
    cout << "Introduce el nombre del archivo: ";
    cin >> filename;  // Lee el nombre del archivo desde la entrada estándar
    load_script(filename.c_str(), true);  // Llama a la otra función load_script con el nombre del archivo
}

// Función principal del programa
int main() {
    load_script();  // Llama a la función load_script para probarla
    return 0;  // Indica que el programa terminó correctamente
}