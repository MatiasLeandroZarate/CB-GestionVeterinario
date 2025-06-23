#pragma once
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cctype>
#include "FuncionesGlobales.h"

class Validaciones{
private:
public:
    int validarNumero();
	bool validarBool();
	std::string validarLetra();
	std::string validarNUMenString();
	float validarFloat();
	std::string validarTexto();
};
