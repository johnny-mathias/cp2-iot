-- phpMyAdmin SQL Dump
-- version 5.2.2
-- https://www.phpmyadmin.net/
--
-- Host: bohfgsmw2omrcmhhwnb8-mysql.services.clever-cloud.com:3306
-- Tempo de geração: 06/05/2026 às 01:44
-- Versão do servidor: 8.0.22-13
-- Versão do PHP: 8.2.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `bohfgsmw2omrcmhhwnb8`
--
CREATE DATABASE IF NOT EXISTS `bohfgsmw2omrcmhhwnb8` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `bohfgsmw2omrcmhhwnb8`;

-- --------------------------------------------------------

--
-- Estrutura para tabela `LEITURAS`
--

CREATE TABLE `LEITURAS` (
  `potenciometro` int NOT NULL,
  `ultrassonico` int NOT NULL,
  `DATA` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Despejando dados para a tabela `LEITURAS`
--

INSERT INTO `LEITURAS` (`potenciometro`, `ultrassonico`, `DATA`) VALUES
(25, 8, '2026-04-15'),
(10, 80, '2026-05-06'),
(10, 80, '2026-05-06'),
(10, 80, '2026-05-06'),
(10, 80, '2026-05-06'),
(100, 200, '2026-05-06'),
(150, 230, '2026-05-06'),
(200, 300, '2026-05-06');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
