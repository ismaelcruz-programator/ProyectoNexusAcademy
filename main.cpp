#include <winsock2.h>
#include <iostream>
#include <mysql.h>
#include <string>
#include <sstream>

using namespace std;

struct Alumno {
    int id;
    string nombre;
    string apellido;
    string celular;
    double nota_final;
};

void mostrarFicha(Alumno al) {
    cout << "ID: " << al.id << " | " << al.nombre << " " << al.apellido 
         << " | Nota: " << al.nota_final << " | Cel: " << al.celular << endl;
}

int main() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "", "nexusacademy", 3306, NULL, 0);

    if (!conectar) {
        cout << "Error de conexion." << endl;
        return 1;
    }

    int opcion;
    do {
        system("cls");
        cout << "==========================================" << endl;
        cout << "       SISTEMA NEXUS ACADEMY v1.0        " << endl;
        cout << "==========================================" << endl;
        cout << "1. Buscar Alumno por ID" << endl;
        cout << "2. Cuadro de Honor (Top 5)" << endl;
        cout << "3. Alumnos en Riesgo (< 51)" << endl;
        cout << "4. Actualizar Datos de Alumno" << endl; 
        cout << "0. Salir" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1 || opcion == 4) {
            int id_buscar;
            cout << "\nIngrese el ID: "; cin >> id_buscar;
            
            stringstream ss;
            ss << "SELECT * FROM alumnos WHERE id = " << id_buscar;
            mysql_query(conectar, ss.str().c_str());
            MYSQL_RES* res = mysql_store_result(conectar);
            MYSQL_ROW fila = mysql_fetch_row(res);
            
            if (fila) {
                Alumno al = {atoi(fila[0]), fila[1], fila[2], fila[3], atof(fila[4])};
                cout << "\n--- DATOS ACTUALES ---" << endl;
                mostrarFicha(al);

                if (opcion == 4) { 
                    int subOpcion;
                    cout << "\n¿Que desea modificar?" << endl;
                    cout << "1. Celular\n2. Nota Final\nSeleccione: ";
                    cin >> subOpcion;

                    string nuevoDato;
                    stringstream queryUpdate;
                    
                    if (subOpcion == 1) {
                        cout << "Ingrese nuevo celular: "; cin >> nuevoDato;
                        queryUpdate << "UPDATE alumnos SET celular = '" << nuevoDato << "' WHERE id = " << id_buscar;
                    } else if (subOpcion == 2) {
                        cout << "Ingrese nueva nota: "; cin >> nuevoDato;
                        queryUpdate << "UPDATE alumnos SET nota_final = " << nuevoDato << " WHERE id = " << id_buscar;
                    }

                    if (mysql_query(conectar, queryUpdate.str().c_str()) == 0) {
                        cout << "\n[OK] ¡Datos actualizados correctamente!" << endl;
                    } else {
                        cout << "\n[!] Error al actualizar." << endl;
                    }
                }
            } else {
                cout << "\n[!] Alumno no encontrado." << endl;
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
            mysql_query(conectar, "SELECT * FROM alumnos WHERE nota_final < 51");
            MYSQL_RES* res = mysql_store_result(conectar);
            MYSQL_ROW fila;
            while ((fila = mysql_fetch_row(res))) {
                Alumno al = {atoi(fila[0]), fila[1], fila[2], fila[3], atof(fila[4])};
                mostrarFicha(al);
            }
            mysql_free_result(res);
            cout << endl; system("pause");
        }

    } while (opcion != 0);

    mysql_close(conectar);
    return 0;
}