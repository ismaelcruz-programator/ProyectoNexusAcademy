#include <winsock2.h>
#include <iostream>
#include <mysql.h>
#include <string>

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
        cout << "==========================================" << endl;
        cout << "   NEXUS ACADEMY - CONEXION EXITOSA       " << endl;
        cout << "==========================================" << endl;
        cout << " El sistema esta listo para gestionar alumnos." << endl;
    } else {
        cout << " Error de conexion. Asegurate de que XAMPP este encendido." << endl;
    }

    system("pause");
    return 0;
}