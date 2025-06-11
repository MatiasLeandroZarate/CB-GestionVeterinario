#include "Validaciones.h"
#include <string>


std::string Validaciones::validarLetra()
{
    std::string str;
    bool strValido = false;

    while (!strValido)
        {
            int i = 0;
            strValido = true;

            std::getline(std::cin, str);

            if(str.empty())  ///empty() , verifica si el str esta Vacio.
                {
                strValido = false;
                }

            while (str[i])
                {
                    char c = str[i];
                    if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' '))
                        {
                            strValido = false;
                        }
                    i++;
                }

            if (!strValido)
                {
                    std::cout << "Dato Invalido, Ingresar Nuevamente." << std::endl;
                }
        }
    return str;
}
int Validaciones::validarNumero()
{
    std::string numIngresado;
    bool numValido = false;
    int Num;

    while (!numValido)
        {
         std::getline(std::cin, numIngresado);
         numValido = true;
         int i = 0;

         if(numIngresado.empty())  ///empty() , verifica si el str esta Vacio.
            {
             numValido = false;
            }

          while (numIngresado[i] != '\0')  // Validacion de que todos los caracteres sean numeros y no letras o caracteres
              {
              if (numIngresado[i] < '0' || numIngresado[i] > '9')
                 {
                    numValido = false;
                }
                    i++;
                }

            if (numValido)
                {
                 Num = 0;
                 i = 0;
                 while (numIngresado[i] != '\0')
                 {
                          Num = Num * 10 + (numIngresado[i] - '0');
                            i++;
                        }
                }

            if (!numValido)
                {
                    std::cout << "Dato inválido, Ingrese de nuevo." << std::endl;
                }
        }
    return Num;
}

std::string Validaciones::validarNUMenString()
{
    std::string str;
    bool strValido = false;

    while (!strValido)
        {
            int i = 0;
            strValido = true;

            std::getline(std::cin, str);
            if(str.empty())  ///empty() , verifica si el str esta Vacio.
                {
                strValido = false;
                }

                while (str[i])
                    {
                        char c = str[i];
                        if (!((c >= '0' && c <= '9') || c == ' ' ))
                            {
                                strValido = false;
                            }
                        i++;
                    }
            if (!strValido)
                {
                    std::cout << "Dato Invalido, Ingresar Nuevamente." << std::endl;
                }
        }
    return str;
}

bool Validaciones::validarBool()
{
    std::string numIngresado;
    bool numValido = false;
    int Num;

    while (!numValido)
        {
            std::getline(std::cin, numIngresado);
            numValido = true;
            int i = 0;

            if(numIngresado.empty())  ///empty() , verifica si el str esta Vacio.
                {
                numValido = false;
                }

            while (numIngresado[i] != '\0')  // Validacion de que todos los caracteres sean numeros y no letras o caracteres
                {
                    if (numIngresado[i] < '0' || numIngresado[i] > '1')
                        {
                            numValido = false;
                        }
                    i++;
                }

            if (numValido)
                {
                    Num = 0;
                    i = 0;
                    while (numIngresado[i] != '\0')
                        {
                            Num = Num * 10 + (numIngresado[i] - '0');
                            i++;
                        }
                }

            if (!numValido)
                {
                    std::cout << "Dato inválido, Ingrese de nuevo." << std::endl;
                }
        }
    return Num;
}
