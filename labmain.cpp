#include <iostream>
#include <fstream>
#include <string>

// Implementación de la función que carga un script desde un archivo
void load_script(const char* filename, bool show_script = false) {
    std::ifstream file(filename);  // Abre el archivo para lectura
    if (!file.is_open()) {  // Verifica si el archivo se abrió correctamente
        std::cerr << "Error: No se pudo abrir el archivo " << filename << std::endl;
        return;  // Sale de la función si no se pudo abrir el archivo
    }

    std::string line;  // Variable para almacenar cada línea del archivo
    while (std::getline(file, line)) {  // Lee el archivo línea por línea
        if (file.bad()) {  // Verifica si hubo un error de lectura
            std::cerr << "Error: Se produjo un error de lectura en el archivo " << filename << std::endl;
            break;  // Sale del bucle si hubo un error de lectura
        }
        if (show_script) {  // Si show_script es verdadero, muestra la línea en la consola
            std::cout << line << std::endl;
        }
        // Aquí puedes agregar la lógica para aplicar la coloración sintáctica
    }

    file.close();  // Cierra el archivo
}

// Implementación de la función que pide al usuario el nombre de un archivo y lo carga
void load_script() {
    std::string filename;  // Variable para almacenar el nombre del archivo
    std::cout << "Introduce el nombre del archivo: ";
    std::cin >> filename;  // Lee el nombre del archivo desde la entrada estándar
    load_script(filename.c_str(), true);  // Llama a la otra función load_script con el nombre del archivo
}