#include <winsock2.h>
#include <iostream>
#include <mysql.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// REQUERIMIENTO PROFE: Struct para espejar la tabla
struct Alumno {
    int id;
    string nombre;
    string apellido;
    string celular;
    double nota_final;
};

// Función auxiliar para imprimir los datos de forma ordenada
void mostrarFicha(Alumno al) {
    cout << "ID: " << al.id << " | " << al.nombre << " " << al.apellido 
         << " | Nota: " << al.nota_final << " | Cel: " << al.celular << endl;
}

int main() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "", "nexusacademy", 3306, NULL, 0);

    if (!conectar) {
        cout << "Error: No se pudo conectar a la base de datos." << endl;
        return 1;
    }

    int opcion;
    do {
        system("cls"); 
        cout << "==========================================" << endl;
        cout << "       SISTEMA NEXUS ACADEMY v1.0        " << endl;
        cout << "==========================================" << endl;
        cout << "1. Buscar Alumno por ID" << endl;
        cout << "2. Cuadro de Honor (Top 5 Mejores Notas)" << endl;
        cout << "3. Alumnos en Riesgo (Notas menores a 51)" << endl;
        cout << "0. Salir" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            int id_buscar;
            cout << "\nIngrese el ID a buscar: "; cin >> id_buscar;
            
            stringstream ss;
            ss << "SELECT * FROM alumnos WHERE id = " << id_buscar;
            mysql_query(conectar, ss.str().c_str());
            
            MYSQL_RES* res = mysql_store_result(conectar);
            MYSQL_ROW fila = mysql_fetch_row(res);
            
            if (fila) {
                Alumno al = {atoi(fila[0]), fila[1], fila[2], fila[3], atof(fila[4])};
                cout << "\n--- RESULTADO DE BUSQUEDA ---" << endl;
                mostrarFicha(al);
            } else {
                cout << "\n[!] No se encontro el alumno." << endl;
            }
            mysql_free_result(res);
            cout << endl; system("pause");

        } else if (opcion == 2) {
            cout << "\n--- CUADRO DE HONOR (TOP 5) ---" << endl;
            mysql_query(conectar, "SELECT * FROM alumnos ORDER BY nota_final DESC LIMIT 5");
            MYSQL_RES* res = mysql_store_result(conectar);
            MYSQL_ROW fila;
            while ((fila = mysql_fetch_row(res))) {
                Alumno al = {atoi(fila[0]), fila[1], fila[2], fila[3], atof(fila[4])};
                mostrarFicha(al);
            }
            mysql_free_result(res);
            cout << endl; system("pause");

        } else if (opcion == 3) {
            cout << "\n--- ALUMNOS EN RIESGO (NOTAS < 51) ---" << endl;
            // AJUSTE: Ahora busca a los que tienen menos de 51
            mysql_query(conectar, "SELECT * FROM alumnos WHERE nota_final < 51");
            MYSQL_RES* res = mysql_store_result(conectar);
            MYSQL_ROW fila;
            int contador = 0;
            while ((fila = mysql_fetch_row(res))) {
                Alumno al = {atoi(fila[0]), fila[1], fila[2], fila[3], atof(fila[4])};
                mostrarFicha(al);
                contador++;
            }
            if(contador == 0) cout << "No hay alumnos reprobados. ¡Excelente!" << endl;
            mysql_free_result(res);
            cout << endl; system("pause");
        }

    } while (opcion != 0);

    mysql_close(conectar);
    return 0;
}