/*

    *** Proyecto Final - Programacion Estructurada ***
    Alumno: Christopher Daniel Ladrón de Guevara Mace
    Profesor: Jaime Roberto Gomez Valdivia

    Descripción del proyecto:
    El proyecto consiste en la elaboración de un menu interactivo al usuario y que permita realizar las siguientes funciones:
    1. Operaciones Basicas
    2. Funciones Trigonometricas
    3. Funciones Hiperbolicas
    4. Instrucciones Si condicional
    5. Instrucciones Repetitivas
    6. Matrices
    7. Registros
    8. Salir

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>

#define M_PI 3.14159265358979323846

void menu();
void operaciones_basicas();
void funciones_trigonometricas();
void funciones_hiperbolicas();
void instrucciones_si_condicional();
void instrucciones_repetitivas();
void matrices();
void registros();

int main(){
    menu();
    getch();
    return 0;
}

void menu(){
    int opcion;

    do{
        printf("Menu Principal\n");
        printf("1. Operaciones Basicas\n");
        printf("2. Funciones Trigonometricas\n");
        printf("3. Funciones Hiperbolicas\n");
        printf("4. Instrucciones Si condicional\n");
        printf("5. Instrucciones Repetitivas\n");
        printf("6. Matrices\n");
        printf("7. Registros\n");
        printf("8. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                // Llamar a la función de operaciones básicas
                operaciones_basicas();
                break;
            case 2:
                // Llamar a la función de funciones trigonométricas
                funciones_trigonometricas();
                break;
            case 3:
                // Llamar a la función de funciones hiperbólicas
                funciones_hiperbolicas();
                break;
            case 4:
                // Llamar a la función de instrucciones si condicional
                instrucciones_si_condicional();
                break;
            case 5:
                // Llamar a la función de instrucciones repetitivas
                instrucciones_repetitivas();
                break;
            case 6:
                // Llamar a la función de matrices
                break;
            case 7:
                // Llamar a la función de registros
                break;
            case 8:
                printf("Saliendo del programa...\nHasta Pronto!!\n");
                break;
            default:
                printf("Opcion no valida, por favor intente nuevamente.\n");
        }
    }while(opcion != 8);
}

void operaciones_basicas(){
    //Operaciones básicas: suma, resta, multiplicación, division, porcentaje, potencia, raiz cuadrada
    double num1, num2, resultado;
    int operacion;
    printf("Operaciones Basicas\n");
    printf("Ingrese el primer numero: ");
    scanf("%lf", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%lf", &num2);
    printf("Seleccione la operacion a realizar:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf("5. Porcentaje\n");
    printf("6. Potencia\n");
    printf("7. Raiz Cuadrada\n");
    printf("8. Volver al Menu Principal\n");
    printf("Opcion: ");
    scanf("%d", &operacion);

    switch(operacion){
        case 1:
            resultado = num1 + num2;
            printf("Resultado: %.2lf\n", resultado);
            break;
        case 2:
            resultado = num1 - num2;
            printf("Resultado: %.2lf\n", resultado);
            break;
        case 3:
            resultado = num1 * num2;
            printf("Resultado: %.2lf\n", resultado);
            break;
        case 4:
            if(num2 != 0){
                resultado = num1 / num2;
                printf("Resultado: %.2lf\n", resultado);
            }else{
                printf("Error: Division por cero no permitida.\n");
            }
            break;
        case 5:
            resultado = (num1 / num2) * 100;
            printf("Resultado: %.2lf%%\n", resultado);
            break;
        case 6:
            resultado = pow(num1, num2);
            printf("Resultado: %.2lf\n", resultado);
            break;
        case 7:
            if(num1 >= 0){
                resultado = sqrt(num1);
                printf("Raiz Cuadrada de %.2lf es: %.2lf\n", num1, resultado);
            }else{
                printf("Error: No se puede calcular la raiz cuadrada de un numero negativo.\n");
            }
            break;
        case 8:
            printf("Volviendo al Menu Principal...\n");
            break;
        default:
            printf("Opcion no valida, por favor intente nuevamente.\n");
    }
}

void funciones_trigonometricas(){
    // Funciones Trigonometricas: seno, coseno, tangente, cotangente, secante, cosecante
    double angulo, resultado;
    int operacion;
    printf("Funciones Trigonometricas\n");
    printf("Ingrese el angulo en grados: ");
    scanf("%lf", &angulo);
    // Convertir el angulo a radianes
    angulo = angulo * (M_PI / 180);
    printf("Seleccione la funcion trigonometrica a calcular:\n");
    printf("1. Seno\n");
    printf("2. Coseno\n");
    printf("3. Tangente\n");
    printf("4. Cotangente\n");
    printf("5. Secante\n");
    printf("6. Cosecante\n");
    printf("7. Volver al Menu Principal\n");
    printf("Opcion: ");
    scanf("%d", &operacion);

    switch(operacion){
        case 1:
            resultado = sin(angulo);
            printf("Seno(%.2lf) = %.2lf\n", angulo * (180 / M_PI), resultado);
            break;
        case 2:
            resultado = cos(angulo);
            printf("Coseno(%.2lf) = %.2lf\n", angulo * (180 / M_PI), resultado);
            break;
        case 3:
            resultado = tan(angulo);
            printf("Tangente(%.2lf) = %.2lf\n", angulo * (180 / M_PI), resultado);
            break;
        case 4:
            if(tan(angulo) != 0){
                resultado = 1 / tan(angulo);
                printf("Cotangente(%.2lf) = %.2lf\n", angulo * (180 / M_PI), resultado);
            }else{
                printf("Error: La cotangente no esta definida para este angulo.\n");
            }
            break;
        case 5:
            if(cos(angulo) != 0){
                resultado = 1 / cos(angulo);
                printf("Secante(%.2lf) = %.2lf\n", angulo * (180 / M_PI), resultado);
            }else{
                printf("Error: La secante no esta definida para este angulo.\n");
            }
            break;
        case 6:
            if(sin(angulo) != 0){
                resultado = 1 / sin(angulo);
                printf("Cosecante(%.2lf) = %.2lf\n", angulo * (180 / M_PI), resultado);
            }else{
                printf("Error: La cosecante no esta definida para este angulo.\n");
            }
            break;
        case 7:
            printf("Volviendo al Menu Principal...\n");
            break;
        default:
            printf("Opcion no valida, por favor intente nuevamente.\n");
    }
}

void funciones_hiperbolicas(){
    // Funciones Hiperbolicas: seno hiperbólico, coseno hiperbólico, tangente hiperbólica, cotangente hiperbólica, secante hiperbólica, cosecante hiperbólica
    double valor, resultado;
    int operacion;
    printf("Funciones Hiperbolicas\n");
    printf("Ingrese el valor: ");
    scanf("%lf", &valor);
    printf("Seleccione la funcion hiperbolica a calcular:\n");
    printf("1. Seno Hiperbolico\n");
    printf("2. Coseno Hiperbolico\n");
    printf("3. Tangente Hiperbolica\n");
    printf("4. Cotangente Hiperbolica\n");
    printf("5. Secante Hiperbolica\n");
    printf("6. Cosecante Hiperbolica\n");
    printf("7. Volver al Menu Principal\n");
    printf("Opcion: ");
    scanf("%d", &operacion);

    switch(operacion){
        case 1:
            resultado = sinh(valor);
            printf("Seno Hiperbolico(%.2lf) = %.2lf\n", valor, resultado);
            break;
        case 2:
            resultado = cosh(valor);
            printf("Coseno Hiperbolico(%.2lf) = %.2lf\n", valor, resultado);
            break;
        case 3:
            resultado = tanh(valor);
            printf("Tangente Hiperbolica(%.2lf) = %.2lf\n", valor, resultado);
            break;
        case 4:
            if(tanh(valor) != 0){
                resultado = 1 / tanh(valor);
                printf("Cotangente Hiperbolica(%.2lf) = %.2lf\n", valor, resultado);
            }else{
                printf("Error: La cotangente hiperbolica no esta definida para este valor.\n");
            }
            break;
        case 5:
            if(cosh(valor) != 0){
                resultado = 1 / cosh(valor);
                printf("Secante Hiperbolica(%.2lf) = %.2lf\n", valor, resultado);
            }else{
                printf("Error: La secante hiperbolica no esta definida para este valor.\n");
            }
            break;
        case 6:
            if(sinh(valor) != 0){
                resultado = 1 / sinh(valor);
                printf("Cosecante Hiperbolica(%.2lf) = %.2lf\n", valor, resultado);
            }else{
                printf("Error: La cosecante hiperbolica no esta definida para este valor.\n");
            }
            break;
        case 7:
            printf("Volviendo al Menu Principal...\n");
            break;
        default:
            printf("Opcion no valida, por favor intente nuevamente.\n");
    }
}

void instrucciones_si_condicional(){
    // Instrucciones Si condicional: if, else if, else
    int numero;
    printf("Instrucciones Si Condicional\n");
    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);

    if(numero > 0){
        printf("El numero %d es positivo.\n", numero);
    }else if(numero < 0){
        printf("El numero %d es negativo.\n", numero);
    }else{
        printf("El numero es cero.\n");
    }

    if(numero % 2 == 0){
        printf("El numero %d es par.\n", numero);
    }else{
        printf("El numero %d es impar.\n", numero);
    }
}

void instrucciones_repetitivas(){
    // Instrucciones Repetitivas: for, while, do-while
    int opcion;
    printf("Instrucciones Repetitivas\n");
    printf("Seleccione el tipo de bucle a utilizar:\n");
    printf("1. Bucle For\n");
    printf("2. Bucle While\n");
    printf("3. Bucle Do-While\n");
    printf("4. Volver al Menu Principal\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    switch(opcion){
        case 1:
            // Ejemplo de bucle for: Imprimir los primeros 10 numeros naturales
            printf("Bucle For: Numeros del 1 al 10\n");
            for(int i = 1; i <= 10; i++){
                printf("%d ", i);
            }
            printf("\n");
            break;
        case 2:
            // Ejemplo de bucle while: Imprimir los primeros 10 numeros naturales
            printf("Bucle While: Numeros del 1 al 10\n");
            int j = 1;
            while(j <= 10){
                printf("%d ", j);
                j++;
            }
            printf("\n");
            break;
        case 3:
            // Ejemplo de bucle do-while: Imprimir los primeros 10 numeros naturales
            printf("Bucle Do-While: Numeros del 1 al 10\n");
            int k = 1;
            do{
                printf("%d ", k);
                k++;
            }while(k <= 10);
            printf("\n");
            break;
        case 4:
            printf("Volviendo al Menu Principal...\n");
            break;
        default:
            printf("Opcion no valida, por favor intente nuevamente.\n");
    }
}

void matrices(){
    // Matrices: Operaciones basicas (Suma, resta, multiplicacion y division de matrices), ademas de calculo del determinante y la inversa de una matriz.
    
}