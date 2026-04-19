# 🎓 Sistema de Gestión Académica - Nexus Academy

Este es un sistema de consola desarrollado en **C++** que interactúa con una base de datos **MySQL/MariaDB** para gestionar la información de alumnos, promedios y reportes de rendimiento.

## 📋 Requisitos Previos
1. **XAMPP**: Tener instalados y activos los módulos de Apache y MySQL (Puerto 3306).
2. **MinGW**: Compilador de C++ (g++) configurado en las variables de entorno.
3. **VS Code**: Con la extensión de C/C++ de Microsoft instalada.

## 🛠️ Configuración de la Base de Datos
1. Abrir **phpMyAdmin** (normalmente en `localhost/phpmyadmin`).
2. Crear una nueva base de datos llamada `nexusacademy`.
3. Importar el archivo `alumnos.sql` que se encuentra en la raíz de este repositorio para cargar la estructura y los datos de prueba.

## 🚀 Cómo Ejecutar el Proyecto
El proyecto está configurado para ser portable, incluyendo las librerías necesarias en las carpetas `/include` y `/lib`.

1. Abrir la carpeta del proyecto en **VS Code**.
2. Presionar `Ctrl + Shift + B` para compilar. Esto ejecutará el archivo `tasks.json` que vincula las librerías de MySQL.
3. Una vez finalizada la compilación, ejecutar el programa desde la terminal integrada:
   ```bash
   .\main.exe
