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
            std::cin.ignore();
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

    std::cin.clear();

    while (!numValido)
        {
         std::cin.clear();
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
                    std::cout << "Dato invalido, Ingrese de nuevo." << std::endl;
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

float Validaciones::validarFloat()
{
    std::string floatIngresado;
    bool floatValido = false;
    float numdecimal = 0.0f;

    while (!floatValido)
    {
        floatValido = true;

        std::getline(std::cin, floatIngresado);

        if (floatIngresado.empty())  ///empty() , verifica si el str esta Vacio.
        {
            floatValido = false;
        }
        int i = 0;
        int puntos = 0;

        while (floatIngresado[i] != '\0')
        {
            char c = floatIngresado[i];

            if (i == 0 && c == '.')  // Si ingresa sin querer el punto primero, lo toma como invalido
            {
                    floatValido = false;
            }
            else
             if (c == '.')
            {
                puntos++;
                if (puntos > 1)
                {
                    floatValido = false;
                }
            }
             else if(c < '0' || c > '9' || (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ')))
            {
                floatValido = false;
            }

            i++;
        }

        if (floatValido)
        {
            numdecimal = std::stof(floatIngresado); // stof significa string to float, convierte el numero de formato string a float de forma mas facil

            if (numdecimal <= 0)

             floatValido = false;

        }

        if (!floatValido)
        {
            std::cout << "Dato inválido, Ingrese de nuevo" << std::endl;
        }
    }

    return numdecimal;

}
