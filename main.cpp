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

int main() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    
    conectar = mysql_real_connect(conectar, "localhost", "root", "", "nexusacademy", 3306, NULL, 0);

    if (conectar) {
        int id_buscar;
        cout << "==========================================" << endl;
        cout << "   NEXUS ACADEMY - BUSCADOR DE ALUMNOS    " << endl;
        cout << "==========================================" << endl;
        cout << "Ingrese el ID o Legajo del alumno: ";
        cin >> id_buscar;

        
        stringstream ss;
        ss << "SELECT * FROM alumnos WHERE id = " << id_buscar;
        string query = ss.str();
        const char* q = query.c_str();

        
        if (mysql_query(conectar, q) == 0) {
            MYSQL_RES* resultado = mysql_store_result(conectar);
            MYSQL_ROW fila = mysql_fetch_row(resultado);

            if (fila) {
                Alumno al;
                al.id = atoi(fila[0]);       
                al.nombre = fila[1];
                al.apellido = fila[2];
                al.celular = fila[3];
                al.nota_final = atof(fila[4]); 

                
                cout << "\n>>> FICHA ENCONTRADA <<<" << endl;
                cout << "ID: " << al.id << endl;
                cout << "Nombre completo: " << al.nombre << " " << al.apellido << endl;
                cout << "Celular: " << al.celular << endl;
                cout << "Promedio: " << al.nota_final << endl;
                cout << "------------------------" << endl;
            } else {
                cout << "\n[!] No existe un alumno con el ID " << id_buscar << endl;
            }
            mysql_free_result(resultado);
        } else {
            cout << "Error al ejecutar la consulta SQL." << endl;
        }
    } else {
        cout << "Error: No se pudo conectar a la base de datos." << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}