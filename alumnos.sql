-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 19-04-2026 a las 01:50:29
-- Versión del servidor: 10.4.32-MariaDB
-- Versión de PHP: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `nexusacademy`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `alumnos`
--

CREATE TABLE `alumnos` (
  `id` int(11) NOT NULL,
  `nombre` varchar(100) NOT NULL,
  `apellido` varchar(100) NOT NULL,
  `celular` varchar(20) NOT NULL,
  `nota_final` decimal(5,2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Volcado de datos para la tabla `alumnos`
--

INSERT INTO `alumnos` (`id`, `nombre`, `apellido`, `celular`, `nota_final`) VALUES
(1, 'Juan Marcos', 'Condori Mamani', '74158405', 95.50),
(2, 'Pablo Mateo', 'Apaza Bustillos', '67327531', 82.00),
(3, 'Alice Adriana', 'Soto Flores', '62781013', 74.25),
(4, 'Anthony Pepe', 'Rea Garcia', '72489544', 61.00),
(5, 'Rodrigo Oliver', 'Pérez Urbano', '62171598', 88.50),
(6, 'Cesar Pedro', 'Lopez Calle', '68322922', 45.00),
(7, 'Zoe Valeria', 'Jove Salvatierra', '70413950', 77.80),
(8, 'Camila Alejandra', 'Felipez Vargas', '71884711', 91.20),
(9, 'Dana Andrea', 'Misericordia Cortez', '74112622', 68.00),
(10, 'Ismael Lhider', 'Cruz Rivera', '75423473', 100.00),
(11, 'Eva Emily', 'Copa Saric', '78861272', 85.40),
(12, 'Omar Oscar', 'Aguilar Yatias', '68452374', 55.50),
(13, 'Ilsen Arlett', 'Chivas Machaca', '79407545', 99.00),
(14, 'Mike Andres', 'Quispe Espinoza', '76145615', 93.00),
(15, 'David Ángel', 'Gutiérrez Tancara', '74158064', 89.75);

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `alumnos`
--
ALTER TABLE `alumnos`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `alumnos`
--
ALTER TABLE `alumnos`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
