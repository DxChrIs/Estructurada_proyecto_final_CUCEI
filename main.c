/*
================================================================================
    *** PROYECTO FINAL - PROGRAMACION ESTRUCTURADA ***
    Alumno:   Christopher Daniel Ladron de Guevara Mace
    Profesor: Jaime Roberto Gomez Valdivia
================================================================================
    DESCRIPCION DEL PROYECTO:
    Menu interactivo que permite realizar las siguientes operaciones:
      1. Operaciones Basicas
      2. Funciones Trigonometricas
      3. Funciones Hiperbolicas
      4. Instrucciones Si Condicional
      5. Instrucciones Repetitivas
      6. Matrices
      7. Registros (Estructuras)
      8. Salir
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265358979323846

/* =============== PROTOTIPOS DE FUNCIONES =============== */
void menu();
void operaciones_basicas();
void funciones_trigonometricas();
void funciones_hiperbolicas();
void instrucciones_si_condicional();
void instrucciones_repetitivas();
void matrices();
void registros();

void separador();
void limpiar_buffer();
long determinante_recursivo(int n, int mat[n][n]);
void leer_entero_seguro(int *variable);
void leer_double_seguro(double *variable);

/* =============== FUNCION PRINCIPAL =============== */
int main()
{
    menu();
    printf("\n");
    separador();
    printf("Presione ENTER para salir...\n");
    getchar();
    return 0;
}

/* =============== FUNCIONES AUXILIARES =============== */
void separador()
{
    printf("================================================================================\n");
}

void limpiar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
/* Función para leer enteros de forma segura, evitando letras */
void leer_entero_seguro(int *variable)
{
    int status;
    do
    {
        status = scanf("%d", variable);
        limpiar_buffer();
        if (status != 1)
        {
            printf("  [!] ERROR: Entrada invalida. Por favor, ingrese un numero entero: ");
        }
    } while (status != 1);
}

/* Función para leer decimales (double) de forma segura, evitando letras */
void leer_double_seguro(double *variable)
{
    int status;
    do
    {
        status = scanf("%lf", variable);
        limpiar_buffer();
        if (status != 1)
        {
            printf("  [!] ERROR: Entrada invalida. Por favor, ingrese un numero: ");
        }
    } while (status != 1);
}

/* Función recursiva para Determinante N x N (Método de Cofactores) */
long determinante_recursivo(int n, int mat[n][n])
{
    long det = 0;

    // Caso base: Matriz 1x1
    if (n == 1)
        return mat[0][0];

    // Caso base: Matriz 2x2 (Optimización)
    if (n == 2)
    {
        return (long)(mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
    }

    // Matriz temporal para los cofactores (también dinámica)
    int submatriz[n - 1][n - 1];

    for (int x = 0; x < n; x++)
    {
        int subi = 0;
        for (int i = 1; i < n; i++)
        {
            int subj = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == x)
                    continue; // Saltamos la columna del pivote
                submatriz[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
        }
        // Aplicamos la fórmula: signo * elemento * determinante de submatriz
        det += (x % 2 == 0 ? 1 : -1) * (long)mat[0][x] * determinante_recursivo(n - 1, submatriz);
    }
    return det;
}

/* ================================================================================
   1. MENU PRINCIPAL
   ================================================================================ */
void menu()
{
    int opcion;

    do
    {
        system("cls"); /* Limpiar pantalla */
        printf("\n");
        separador();
        printf("                      MENU PRINCIPAL\n");
        separador();
        printf("  [1] Operaciones B%csicas\n", 160);
        printf("  [2] Funciones Trigonom%ctricas\n", 130);
        printf("  [3] Funciones Hiperb%clicas\n", 162);
        printf("  [4] Instrucciones Si Condicional\n");
        printf("  [5] Instrucciones Repetitivas\n");
        printf("  [6] Matrices\n");
        printf("  [7] Registros (Estructuras)\n");
        printf("  [8] Salir\n");
        separador();
        printf("  Seleccione una opci%cn: ", 162);
        leer_entero_seguro(&opcion);
        limpiar_buffer();

        switch (opcion)
        {
        case 1:
            operaciones_basicas();
            break;
        case 2:
            funciones_trigonometricas();
            break;
        case 3:
            funciones_hiperbolicas();
            break;
        case 4:
            instrucciones_si_condicional();
            break;
        case 5:
            instrucciones_repetitivas();
            break;
        case 6:
            matrices();
            break;
        case 7:
            registros();
            break;
        case 8:
            separador();
            printf("  Saliendo del programa...\n");
            printf("  %cHasta pronto!\n", 168); /* 168 = ! invertido, o usa 33 para ! normal */
            separador();
            break;
        default:
            printf("\n  [!] Opci%cn no v%clida. Intente nuevamente.\n", 162, 160);
            system("pause"); /* Pausa para ver el mensaje */
        }
    } while (opcion != 8);
}

/* ================================================================================
   2. OPERACIONES BASICAS
   ================================================================================ */
void operaciones_basicas()
{
    double num1, num2, resultado;
    int operacion;

    system("cls");
    separador();
    printf("                   OPERACIONES BASICAS\n");
    separador();
    printf("  Ingrese el primer n%cmero : ", 163);
    leer_double_seguro(&num1);
    printf("  Ingrese el segundo n%cmero: ", 163);
    leer_double_seguro(&num2);
    limpiar_buffer();

    do{
        system("cls");
        separador();
        printf("                   OPERACIONES BASICAS\n");
        separador();
        printf("\n  Seleccione la operaci%cn a realizar:\n", 162);
        printf("  [1] Suma\n");
        printf("  [2] Resta\n");
        printf("  [3] Multiplicaci%cn\n", 162);
        printf("  [4] Divisi%cn\n", 162);
        printf("  [5] Porcentaje\n");
        printf("  [6] Potencia\n");
        printf("  [7] Raiz Cuadrada\n");
        printf("  [8] Ingresar nuevos numeros\n");
        printf("  [9] Volver al Menu Principal\n");
        separador();
        printf("  Opci%cn: ", 162);
        leer_entero_seguro(&operacion);
        limpiar_buffer();

        printf("\n");
        separador();

        switch (operacion)
        {
        case 1:
            resultado = num1 + num2;
            printf("  Suma: %.2lf + %.2lf = %.2lf\n", num1, num2, resultado);
            break;
        case 2:
            resultado = num1 - num2;
            printf("  Resta: %.2lf - %.2lf = %.2lf\n", num1, num2, resultado);
            break;
        case 3:
            resultado = num1 * num2;
            printf("  Multiplicaci%cn: %.2lf %c %.2lf = %.2lf\n", 162, num1, 120, num2, resultado); /* 120 = 'x' */
            break;
        case 4:
            if (num2 != 0)
            {
                resultado = num1 / num2;
                printf("  Divisi%cn: %.2lf %c %.2lf = %.2lf\n", 162, num1, 47, num2, resultado); /* 47 = '/' */
            }
            else
            {
                printf("  [!] ERROR: Divisi%cn por cero no permitida.\n", 162);
            }
            break;
        case 5:
            if (num2 != 0)
            {
                resultado = (num1 / num2) * 100;
                printf("  Porcentaje: %.2lf es el %.2lf%% de %.2lf\n", num1, resultado, num2);
            }
            else
            {
                printf("  [!] ERROR: No se puede dividir por cero para calcular porcentaje.\n");
            }
            break;
        case 6:
            resultado = pow(num1, num2);
            printf("  Potencia: %.2lf ^ %.2lf = %.2lf\n", num1, num2, resultado);
            break;
        case 7:
            if (num1 >= 0)
            {
                resultado = sqrt(num1);
                printf("  Raiz Cuadrada: raiz(%.2lf) = %.2lf\n", num1, resultado);
            }
            else
            {
                printf("  [!] ERROR: No se puede calcular la raiz cuadrada de un numero negativo.\n");
            }
            break;
        case 8:
            printf("  Ingresando nuevos n%cmeros...\n", 163);
            printf("  Ingrese el primer n%cmero : ", 163);
            leer_double_seguro(&num1);
            printf("  Ingrese el segundo n%cmero: ", 163);
            leer_double_seguro(&num2);
            limpiar_buffer();
            break;
        case 9:
            printf("  Regresando al Menu Principal...\n");
            return;
        default:
            printf("  [!] Opci%cn no v%clida. Intente nuevamente.\n", 162, 160);
        }
        separador();
        system("pause"); /* Pausa antes de volver al menu */
    }while(operacion != 9);
}

/* ================================================================================
   3. FUNCIONES TRIGONOMETRICAS
   ================================================================================ */
void funciones_trigonometricas()
{
    double angulo_grados, angulo_rad, resultado;
    int operacion;

    system("cls");
    separador();
    printf("                  FUNCIONES TRIGONOM%cTRICAS\n", 144);
    separador();
    printf("  Ingrese el %cngulo en grados: ", 160);
    leer_double_seguro(&angulo_grados);
    limpiar_buffer();

    /* Convertir a radianes */
    angulo_rad = angulo_grados * (PI / 180.0);

    do{
        system("cls");
        separador();
        printf("                  FUNCIONES TRIGONOM%cTRICAS\n", 144);
        separador();
        printf("\n  Seleccione la funci%cn trigonom%ctrica:\n", 162, 130);
        printf("  [1] Seno (sin)\n");
        printf("  [2] Coseno (cos)\n");
        printf("  [3] Tangente (tan)\n");
        printf("  [4] Cotangente (cot)\n");
        printf("  [5] Secante (sec)\n");
        printf("  [6] Cosecante (csc)\n");
        printf("  [7] Ingresar nuevos %cngulos\n", 160);
        printf("  [8] Volver al Menu Principal\n");
        separador();
        printf("  Opci%cn: ", 162);
        leer_entero_seguro(&operacion);
        limpiar_buffer();

        printf("\n");
        separador();

        switch (operacion)
        {
        case 1:
            resultado = sin(angulo_rad);
            printf("  sen(%.2lf%c) = %.6lf\n", angulo_grados, 248, resultado); /* 248 = ° */
            break;
        case 2:
            resultado = cos(angulo_rad);
            printf("  cos(%.2lf%c) = %.6lf\n", angulo_grados, 248, resultado); /* 248 = ° */
            break;
        case 3:
            resultado = tan(angulo_rad);
            printf("  tan(%.2lf%c) = %.6lf\n", angulo_grados, 248, resultado); /* 248 = ° */
            break;
        case 4:
            if (fabs(tan(angulo_rad)) > 1e-9)
            {
                resultado = 1.0 / tan(angulo_rad);
                printf("  cot(%.2lf%c) = %.6lf\n", angulo_grados, 248, resultado); /* 248 = ° */
            }
            else
            {
                printf("  [!] ERROR: Cotangente no definida para %.2lf%c.\n", angulo_grados, 248); /* 248 = ° */
            }
            break;
        case 5:
            if (fabs(cos(angulo_rad)) > 1e-9)
            {
                resultado = 1.0 / cos(angulo_rad);
                printf("  sec(%.2lf%c) = %.6lf\n", angulo_grados, 248, resultado); /* 248 = ° */
            }
            else
            {
                printf("  [!] ERROR: Secante no definida para %.2lf%c.\n", angulo_grados, 248); /* 248 = ° */
            }
            break;
        case 6:
            if (fabs(sin(angulo_rad)) > 1e-9)
            {
                resultado = 1.0 / sin(angulo_rad);
                printf("  csc(%.2lf%c) = %.6lf\n", angulo_grados, 248, resultado); /* 248 = ° */
            }
            else
            {
                printf("  [!] ERROR: Cosecante no definida para %.2lf%c.\n", angulo_grados, 248); /* 248 = ° */
            }
            break;
        case 7:
            printf("  Ingresando nuevos %cngulos...\n", 160);
            printf("  Ingrese el %cngulo en grados: ", 160);
            leer_double_seguro(&angulo_grados);
            limpiar_buffer();
                /* Convertir a radianes */
            angulo_rad = angulo_grados * (PI / 180.0); 
            break;
        case 8:
            printf("  Regresando al Menu Principal...\n");
            return;
        default:
            printf("  [!] Opci%cn no v%clida. Intente nuevamente.\n", 162, 160);
        }
        separador();
        system("pause");
    }while(operacion != 8);
}

/* ================================================================================
   4. FUNCIONES HIPERBOLICAS
   ================================================================================ */
void funciones_hiperbolicas()
{
    double valor, resultado;
    int operacion;

    system("cls");
    separador();
    printf("                   FUNCIONES HIPERBOLICAS\n");
    separador();
    printf("  Ingrese el valor: ");
    leer_double_seguro(&valor);
    limpiar_buffer();

    do{
        system("cls");
        separador();
        printf("                   FUNCIONES HIPERBOLICAS\n");
        separador();
        printf("\n  Seleccione la funci%cn hiperb%clica:\n", 162, 130);
        printf("  [1] Seno Hiperbolico    (sinh)\n");
        printf("  [2] Coseno Hiperbolico  (cosh)\n");
        printf("  [3] Tangente Hiperbolica (tanh)\n");
        printf("  [4] Cotangente Hiperbolica (coth)\n");
        printf("  [5] Secante Hiperbolica (sech)\n");
        printf("  [6] Cosecante Hiperbolica (csch)\n");
        printf("  [7] Ingresar nuevo valor\n");
        printf("  [8] Volver al Menu Principal\n");
        separador();
        printf("  Opci%cn: ", 162);
        leer_entero_seguro(&operacion);
        limpiar_buffer();

        printf("\n");
        separador();

        switch (operacion)
        {
        case 1:
            resultado = sinh(valor);
            printf("  sinh(%.4lf) = %.6lf\n", valor, resultado);
            break;
        case 2:
            resultado = cosh(valor);
            printf("  cosh(%.4lf) = %.6lf\n", valor, resultado);
            break;
        case 3:
            resultado = tanh(valor);
            printf("  tanh(%.4lf) = %.6lf\n", valor, resultado);
            break;
        case 4:
            if (fabs(tanh(valor)) > 1e-9)
            {
                resultado = 1.0 / tanh(valor);
                printf("  coth(%.4lf) = %.6lf\n", valor, resultado);
            }
            else
            {
                printf("  [!] ERROR: Cotangente hiperbolica no definida para x = 0.\n");
            }
            break;
        case 5:
            resultado = 1.0 / cosh(valor);
            printf("  sech(%.4lf) = %.6lf\n", valor, resultado);
            break;
        case 6:
            if (fabs(sinh(valor)) > 1e-9)
            {
                resultado = 1.0 / sinh(valor);
                printf("  csch(%.4lf) = %.6lf\n", valor, resultado);
            }
            else
            {
                printf("  [!] ERROR: Cosecante hiperbolica no definida para x = 0.\n");
            }
            break;
        case 7:
            printf("  Ingresando nuevo valor...\n");
            printf("  Ingrese el valor: ");
            leer_double_seguro(&valor);
            limpiar_buffer();
            break;
        case 8:
            printf("  Regresando al Menu Principal...\n");
            return;
        default:
            printf("  [!] Opci%cn no v%clida. Intente nuevamente.\n", 162, 160);
        }
        separador();
        system("pause");
    }while(operacion != 8);
}

/* ================================================================================
   5. INSTRUCCIONES SI CONDICIONAL
   ================================================================================ */
void instrucciones_si_condicional()
{
    int numero, operacion, otro_numero, otro_numero_2, otro_numero_3;

    do{
        system("cls");
        separador();
        printf("               INSTRUCCIONES SI CONDICIONAL\n");
        separador();
        printf("\n  Seleccione la operacion SI condicional:\n");
        printf("  [1] Numero positivo y negativo\n");
        printf("  [2] Numero par o impar\n");
        printf("  [3] Numero mayor que otro\n");
        printf("  [4] Rango de numeros (1-100)\n");
        printf("  [5] Numero igual a otro\n");
        printf("  [6] Numero diferente de otro\n");
        printf("  [7] Volver al Menu Principal\n");
        separador();
        printf("  Opci%cn: ", 162);
        leer_entero_seguro(&operacion);
        limpiar_buffer();

        printf("\n");
        separador();

        switch(operacion){
            case 1:
                printf("  Ingrese un n%cmero entero: ", 163);
                leer_entero_seguro(&numero);
                limpiar_buffer();
                /* Condicion 1: Positivo, negativo o cero */
                if (numero > 0)
                {
                    printf("  %c El n%cmero %d es POSITIVO.\n", 251, 163, numero); /* 251 = ✓ */
                }
                else if (numero < 0)
                {
                    printf("  %c El n%cmero %d es NEGATIVO.\n", 251, 163, numero); /* 251 = ✓ */
                }
                else
                {
                    printf("  %c El n%cmero ingresado es CERO.\n", 251, 163); /* 251 = ✓ */
                }
                break;
            case 2:
                printf("  Ingrese un n%cmero entero: ", 163);
                leer_entero_seguro(&numero);
                limpiar_buffer();
                /* Condicion 2: Par o impar */
                if (numero % 2 == 0)
                {
                    printf("  %c El n%cmero %d es PAR.\n", 251, 163, numero); /* 251 = ✓ */
                }
                else
                {
                    printf("  %c El n%cmero %d es IMPAR.\n", 251, 163, numero); /* 251 = ✓ */
                }
                break;
            case 3:
                printf("  Ingrese un n%cmero entero: ", 163);
                leer_entero_seguro(&numero);
                limpiar_buffer();
                printf("  Ingrese otro n%cmero entero para comparar: ", 163);
                leer_entero_seguro(&otro_numero);
                if (numero > otro_numero)
                {
                    printf("  %c El n%cmero %d es MAYOR que %d.\n", 251, 163, numero, otro_numero); /* 251 = ✓ */
                }
                else if (numero < otro_numero)
                {
                    printf("  %c El n%cmero %d es MENOR que %d.\n", 251, 163, numero, otro_numero); /* 251 = ✓ */
                }
                else
                {
                    printf("  %c El n%cmero %d es IGUAL a %d.\n", 251, 163, numero, otro_numero); /* 251 = ✓ */
                }
                break;
            case 4:
                printf("  Ingrese un n%cmero entero: ", 163);
                leer_entero_seguro(&numero);
                limpiar_buffer();
                if (numero >= 1 && numero <= 100)
                {
                    printf("  %c El n%cmero %d est%c en el rango (1-100).\n", 251, 163, numero, 160); /* 251 = ✓ */
                }
                else
                {
                    printf("  %c El n%cmero %d no est%c en el rango (1-100).\n", 251, 163, numero, 160); /* 251 = ✓ */
                }
                break;
            case 5:
                printf("  Ingrese un n%cmero entero: ", 163);
                leer_entero_seguro(&numero);
                limpiar_buffer();
                printf("  Ingrese otro n%cmero entero para comparar: ", 163);
                leer_entero_seguro(&otro_numero_2);
                if (numero == otro_numero_2)
                {
                    printf("  %c El n%cmero %d es IGUAL a %d.\n", 251, 163, numero, otro_numero_2); /* 251 = ✓ */
                }
                else
                {
                    printf("  %c El n%cmero %d es DIFERENTE de %d.\n", 251, 163, numero, otro_numero_2); /* 251 = ✓ */
                }
                break;
            case 6:
                printf("  Ingrese un n%cmero entero: ", 163);
                leer_entero_seguro(&numero);
                limpiar_buffer();
                printf("  Ingrese otro n%cmero entero para comparar: ", 163);
                leer_entero_seguro(&otro_numero_3);
                if (numero != otro_numero_3)
                {
                    printf("  %c El n%cmero %d es DIFERENTE de %d.\n", 251, 163, numero, otro_numero_3); /* 251 = ✓ */
                }
                else
                {
                    printf("  %c El n%cmero %d es IGUAL a %d.\n", 251, 163, numero, otro_numero_3); /* 251 = ✓ */
                }
                break;
            case 7:
                printf("  Regresando al Menu Principal...\n");
                return;
            default:
                printf("  [!] Opci%cn no v%clida. Intente nuevamente.\n", 162, 160);
        }
        separador();
        system("pause");
    }while(operacion != 7);
}

/* ================================================================================
   6. INSTRUCCIONES REPETITIVAS
   ================================================================================ */
void instrucciones_repetitivas()
{
    int opcion;

    do{
        system("cls");
        separador();
        printf("                 INSTRUCCIONES REPETITIVAS\n");
        separador();
        printf("  Seleccione el tipo de bucle:\n");
        printf("  [1] Bucle FOR\n");
        printf("  [2] Bucle WHILE\n");
        printf("  [3] Bucle DO-WHILE\n");
        printf("  [4] Tabla de multiplicar\n");
        printf("  [5] Factorial\n");
        printf("  [6] Volver al Menu Principal\n");
        separador();
        printf("  Opci%cn: ", 162);
        leer_entero_seguro(&opcion);
        limpiar_buffer();

        printf("\n");
        separador();

        switch (opcion)
        {
        case 1:
            printf("  Bucle FOR -> Numeros del 1 al 10:\n  ");
            for (int i = 1; i <= 10; i++)
            {
                printf("%d ", i);
            }
            printf("\n");
            break;
        case 2:
        {
            printf("  Bucle WHILE -> Numeros del 1 al 10:\n  ");
            int j = 1;
            while (j <= 10)
            {
                printf("%d ", j);
                j++;
            }
            printf("\n");
            break;
        }
        case 3:
        {
            printf("  Bucle DO-WHILE -> Numeros del 1 al 10:\n  ");
            int k = 1;
            do
            {
                printf("%d ", k);
                k++;
            } while (k <= 10);
            printf("\n");
            break;
        }
        case 4:
            system("cls");
            separador();
            printf("           EJERCICIO 1: TABLA DE MULTIPLICAR (FOR)\n");
            separador();

            int numero;
            printf("  Ingrese un n%cmero para su tabla de multiplicar: ", 163);
            leer_entero_seguro(&numero);
            limpiar_buffer();

            printf("\n  Tabla de multiplicar del %d:\n\n", numero);

            /* BUCLE FOR - Itera 10 veces */
            for (int i = 1; i <= 10; i++)
            {
                printf("  %d x %d = %d\n", numero, i, numero * i);
            }

            printf("\n");
            break;
        case 5:
            system("cls");
            separador();
            printf("           EJERCICIO 2: FACTORIAL (FOR)\n");
            separador();

            int num;
            printf("  Ingrese un n%cmero para calcular su factorial (maximo 10): ", 163);
            leer_entero_seguro(&num);
            limpiar_buffer();

            long long factorial = 1;
            for (int i = 1; i <= num; i++)
            {
                factorial *= i;
            }

            printf("\n  El factorial de %d es: %lld\n", num, factorial);
            break;
        case 6:
            printf("  Regresando al Menu Principal...\n");
            break;
        default:
            printf("  [!] Opci%cn no v%clida. Intente nuevamente.\n", 162, 160);
        }
        separador();
        system("pause");
    }while(opcion != 6);
}

/* ================================================================================
   7. MATRICES
   ================================================================================ */
void matrices()
{
    int filas, columnas;
    int operacion;

    system("cls");
    separador();
    printf("                          MATRICES\n");
    separador();

    printf("  Tama%co de la Matriz (filas columnas): ", 164);
    scanf("%d %d", &filas, &columnas);
    limpiar_buffer();

    // Validar dimensiones
    if (filas <= 0 || columnas <= 0)
    {
        printf("  [!] ERROR: Dimensiones inv%clidas.\n", 160);
        system("pause");
        return;
    }

    int matriz[filas][columnas];

    printf("  Ingrese los elementos de la Matriz:\n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("    Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    limpiar_buffer();

    do
    {
        system("cls");
        separador();
        printf("                          MATRICES\n");
        separador();

        printf("\n  Matriz Actual (%d x %d):\n", filas, columnas);
        for (int i = 0; i < filas; i++)
        {
            printf("  ");
            for (int j = 0; j < columnas; j++)
            {
                printf("%6d ", matriz[i][j]);
            }
            printf("\n");
        }

        printf("\n  Seleccione la operaci%cn a realizar:\n", 162);
        printf("  [1] Sumar con otra matriz\n");
        printf("  [2] Restar otra matriz\n");
        printf("  [3] Multiplicar por otra matriz\n");
        printf("  [4] Calcular determinante\n");
        printf("  [5] Modificar un elemento\n");
        printf("  [6] Ingresar nueva matriz\n");
        printf("  [7] Volver al Menu Principal\n");
        separador();
        printf("  Opci%cn: ", 162);
        leer_entero_seguro(&operacion);
        limpiar_buffer();

        printf("\n");
        separador();

        switch (operacion)
        {
        case 1:
        {
            int filas_2, columnas_2;
            printf("  Tama%co de la segunda matriz (filas columnas): ", 164);
            leer_entero_seguro(&filas_2);
            leer_entero_seguro(&columnas_2);
            limpiar_buffer();

            if (filas != filas_2 || columnas != columnas_2)
            {
                printf("  [!] ERROR: Las matrices deben tener el mismo tama%co.\n", 164);
                break;
            }

            int matriz_2[filas_2][columnas_2];
            printf("  Ingrese los elementos de la segunda matriz:\n");
            for (int i = 0; i < filas_2; i++)
            {
                for (int j = 0; j < columnas_2; j++)
                {
                    printf("    Elemento [%d][%d]: ", i, j);
                    scanf("%d", &matriz_2[i][j]);
                }
            }
            limpiar_buffer();

            int resultado[filas][columnas];
            for (int i = 0; i < filas; i++)
            {
                for (int j = 0; j < columnas; j++)
                {
                    resultado[i][j] = matriz[i][j] + matriz_2[i][j];
                }
            }

            printf("  Resultado de la SUMA:\n");
            for (int i = 0; i < filas; i++)
            {
                printf("  ");
                for (int j = 0; j < columnas; j++)
                {
                    printf("%6d ", resultado[i][j]);
                }
                printf("\n");
            }
            break;
        }

        case 2:
        {
            int filas_2, columnas_2;
            printf("  Tama%co de la segunda matriz (filas columnas): ", 164);
            leer_entero_seguro(&filas_2);
            leer_entero_seguro(&columnas_2);
            limpiar_buffer();

            if (filas != filas_2 || columnas != columnas_2)
            {
                printf("  [!] ERROR: Las matrices deben tener el mismo tama%co.\n", 164);
                break;
            }

            int matriz_2[filas_2][columnas_2];
            printf("  Ingrese los elementos de la segunda matriz:\n");
            for (int i = 0; i < filas_2; i++)
            {
                for (int j = 0; j < columnas_2; j++)
                {
                    printf("    Elemento [%d][%d]: ", i, j);
                    scanf("%d", &matriz_2[i][j]);
                }
            }
            limpiar_buffer();

            int resultado[filas][columnas];
            for (int i = 0; i < filas; i++)
            {
                for (int j = 0; j < columnas; j++)
                {
                    resultado[i][j] = matriz[i][j] - matriz_2[i][j];
                }
            }

            printf("  Resultado de la RESTA:\n");
            for (int i = 0; i < filas; i++)
            {
                printf("  ");
                for (int j = 0; j < columnas; j++)
                {
                    printf("%6d ", resultado[i][j]);
                }
                printf("\n");
            }
            break;
        }

        case 3:
        {
            int filas_2, columnas_2;
            printf("  Tama%co de la segunda matriz (filas columnas): ", 164);
            leer_entero_seguro(&filas_2);
            leer_entero_seguro(&columnas_2);
            limpiar_buffer();

            if (columnas != filas_2)
            {
                printf("  [!] ERROR: Columnas de M1 (%d) debe ser igual a filas de M2 (%d).\n", columnas, filas_2);
                break;
            }

            int matriz_2[filas_2][columnas_2];
            printf("  Ingrese los elementos de la segunda matriz:\n");
            for (int i = 0; i < filas_2; i++)
            {
                for (int j = 0; j < columnas_2; j++)
                {
                    printf("    Elemento [%d][%d]: ", i, j);
                    scanf("%d", &matriz_2[i][j]);
                }
            }
            limpiar_buffer();

            int resultado[filas][columnas_2];
            for (int i = 0; i < filas; i++)
            {
                for (int j = 0; j < columnas_2; j++)
                {
                    resultado[i][j] = 0;
                    for (int k = 0; k < columnas; k++)
                    {
                        resultado[i][j] += matriz[i][k] * matriz_2[k][j];
                    }
                }
            }

            printf("  Resultado de la MULTIPLICACI%cN (%d x %d):\n", 224, filas, columnas_2);
            for (int i = 0; i < filas; i++)
            {
                printf("  ");
                for (int j = 0; j < columnas_2; j++)
                {
                    printf("%6d ", resultado[i][j]);
                }
                printf("\n");
            }
            break;
        }

        case 4:
        {
            if (filas != columnas)
            {
                printf("  [!] ERROR: La matriz debe ser cuadrada (%dx%d) para calcular determinante.\n", filas, columnas);
                break;
            }

            long det = determinante_recursivo(filas, matriz);
            printf("\n  ================================================\n");
            printf("  Determinante de la Matriz (%dx%d):\n", filas, columnas);
            printf("  det(M) = %ld\n", det);
            printf("  ================================================\n");
            break;
        }

        case 5:
        {
            int fila, columna, nuevo_valor;
            printf("  Ingrese la posici%cn a modificar (fila columna): ", 162);
            leer_entero_seguro(&fila);
            leer_entero_seguro(&columna);
            limpiar_buffer();

            if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas)
            {
                printf("  [!] ERROR: Posici%cn inv%clida.\n", 162, 160);
                break;
            }

            printf("  Valor actual en [%d][%d]: %d\n", fila, columna, matriz[fila][columna]);
            printf("  Ingrese el nuevo valor: ");
            leer_entero_seguro(&nuevo_valor);
            limpiar_buffer();

            matriz[fila][columna] = nuevo_valor;
            printf("  %c Elemento actualizado correctamente.\n", 251);
            break;
        }

        case 6:
        {
            printf("  Ingresando nueva matriz...\n");
            printf("  Tama%co de la Matriz (filas columnas): ", 164);
            leer_entero_seguro(&filas);
            leer_entero_seguro(&columnas);
            limpiar_buffer();

            if (filas <= 0 || columnas <= 0)
            {
                printf("  [!] ERROR: Dimensiones inv%clidas.\n", 160);
                system("pause");
                return;
            }

            printf("  Ingrese los elementos de la nueva Matriz:\n");
            for (int i = 0; i < filas; i++)
            {
                for (int j = 0; j < columnas; j++)
                {
                    printf("    Elemento [%d][%d]: ", i, j);
                    scanf("%d", &matriz[i][j]);
                }
            }
            limpiar_buffer();
            break;
        }

        case 7:
            printf("  Regresando al Menu Principal...\n");
            return;

        default:
            printf("  [!] Opci%cn no v%clida. Intente nuevamente.\n", 162, 160);
        }
        separador();
        system("pause");
    } while (operacion != 7);
}

/* ================================================================================
   8. REGISTROS (ESTRUCTURAS)
   ================================================================================ */
void registros()
{
    struct Persona
    {
        char nombre[50];
        int edad;
        float altura;
    };

    struct Empleado
    {
        struct Persona informacion_personal;
        char puesto[50];
    };
    
    int opcion;
    struct Persona personas_global[100];
    struct Empleado empleados_global[100];
    int contador_personas_global = 0;
    int contador_empleados_global = 0;

    do
    {
        system("cls");
        separador();
        printf("                  REGISTROS (ESTRUCTURAS)\n");
        separador();
        printf("\n  Seleccione una opci%cn:\n", 162);
        printf("  [1] Guardar Personas en Archivo\n");
        printf("  [2] Guardar Empleados en Archivo\n");
        printf("  [3] Registrar Nueva Persona\n");
        printf("  [4] Registrar Nuevo Empleado\n");
        printf("  [5] Mostrar Personas Registradas\n");
        printf("  [6] Mostrar Empleados Registrados\n");
        printf("  [7] Volver al Menu Principal\n");
        separador();
        printf("  Ingrese su opci%cn: ", 162);
        leer_entero_seguro(&opcion);
        limpiar_buffer();

        printf("\n");
        separador();

        switch (opcion)
        {
        case 1:
            /* Guardar Personas en Archivo */
            if (contador_personas_global == 0)
            {
                printf("  [!] No hay personas registradas para guardar.\n");
                break;
            }

            FILE *fptr1;
            fptr1 = fopen("personas.txt", "w"); /* Archivo en directorio actual */

            if (fptr1 == NULL)
            {
                printf("  [!] Error: No se pudo crear el archivo 'personas.txt'.\n");
                printf("     Verifica que tengas permisos de escritura en el directorio actual.\n");
                break;
            }

            /* Escribir encabezado */
            fprintf(fptr1, "════════════════════════════════════════════════════════════\n");
            fprintf(fptr1, "                    REGISTRO DE PERSONAS\n");
            fprintf(fptr1, "════════════════════════════════════════════════════════════\n\n");
            fprintf(fptr1, "Total de personas registradas: %d\n\n", contador_personas_global);

            /* Escribir datos de cada persona */
            for (int i = 0; i < contador_personas_global; i++)
            {
                fprintf(fptr1, "PERSONA #%d\n", i + 1);
                fprintf(fptr1, "├─ Nombre : %s\n", personas_global[i].nombre);
                fprintf(fptr1, "├─ Edad   : %d años\n", personas_global[i].edad);
                fprintf(fptr1, "└─ Altura : %.2f metros\n\n", personas_global[i].altura);
            }

            fprintf(fptr1, "════════════════════════════════════════════════════════════\n");

            fclose(fptr1);

            printf("  %c Archivo 'personas.txt' guardado exitosamente.\n", 251);
            printf("     Ubicaci%cn: directorio actual\n", 162);
            break;

        case 2:
            /* Guardar Empleados en Archivo */
            if (contador_empleados_global == 0)
            {
                printf("  [!] No hay empleados registrados para guardar.\n");
                break;
            }

            FILE *fptr2;
            fptr2 = fopen("empleados.txt", "w"); /* Archivo en directorio actual */

            if (fptr2 == NULL)
            {
                printf("  [!] Error: No se pudo crear el archivo 'empleados.txt'.\n");
                printf("     Verifica que tengas permisos de escritura en el directorio actual.\n");
                break;
            }

            /* Escribir encabezado */
            fprintf(fptr2, "════════════════════════════════════════════════════════════\n");
            fprintf(fptr2, "                   REGISTRO DE EMPLEADOS\n");
            fprintf(fptr2, "════════════════════════════════════════════════════════════\n\n");
            fprintf(fptr2, "Total de empleados registrados: %d\n\n", contador_empleados_global);

            /* Escribir datos de cada empleado */
            for (int i = 0; i < contador_empleados_global; i++)
            {
                fprintf(fptr2, "EMPLEADO #%d\n", i + 1);
                fprintf(fptr2, "├─ Nombre  : %s\n", empleados_global[i].informacion_personal.nombre);
                fprintf(fptr2, "├─ Edad    : %d años\n", empleados_global[i].informacion_personal.edad);
                fprintf(fptr2, "├─ Altura  : %.2f metros\n", empleados_global[i].informacion_personal.altura);
                fprintf(fptr2, "└─ Puesto  : %s\n\n", empleados_global[i].puesto);
            }

            fprintf(fptr2, "════════════════════════════════════════════════════════════\n");

            fclose(fptr2);

            printf("  %c Archivo 'empleados.txt' guardado exitosamente.\n", 251);
            printf("     Ubicaci%cn: directorio actual\n", 162);
            break;

        case 3:
            if (contador_personas_global >= 100)
            {
                printf("  [!] Capacidad m%cxima de personas alcanzada (100).\n", 160);
                break;
            }

            system("cls");
            separador();
            printf("            REGISTRAR NUEVA PERSONA\n");
            separador();

            printf("  Ingrese el nombre de la persona: ");
            fgets(personas_global[contador_personas_global].nombre, sizeof(personas_global[contador_personas_global].nombre), stdin);
            personas_global[contador_personas_global].nombre[strcspn(personas_global[contador_personas_global].nombre, "\n")] = 0;

            printf("  Ingrese la edad de la persona: ");
            scanf("%d", &personas_global[contador_personas_global].edad);

            printf("  Ingrese la altura de la persona (en metros): ");
            scanf("%f", &personas_global[contador_personas_global].altura);
            limpiar_buffer();

            printf("\n  %c Persona registrada exitosamente.\n\n", 251);
            printf("  Información guardada:\n");
            printf("  ├─ Nombre : %s\n", personas_global[contador_personas_global].nombre);
            printf("  ├─ Edad   : %d años\n", personas_global[contador_personas_global].edad);
            printf("  └─ Altura : %.2f metros\n", personas_global[contador_personas_global].altura);

            contador_personas_global++;
            break;

        case 4:
            if (contador_empleados_global >= 100)
            {
                printf("  [!] Capacidad m%cxima de empleados alcanzada (100).\n", 160);
                break;
            }

            system("cls");
            separador();
            printf("         REGISTRAR NUEVO EMPLEADO\n");
            separador();

            printf("  Ingrese el nombre del empleado: ");
            fgets(empleados_global[contador_empleados_global].informacion_personal.nombre,
                  sizeof(empleados_global[contador_empleados_global].informacion_personal.nombre), stdin);
            empleados_global[contador_empleados_global].informacion_personal.nombre[strcspn(empleados_global[contador_empleados_global].informacion_personal.nombre, "\n")] = 0;

            printf("  Ingrese la edad del empleado: ");
            scanf("%d", &empleados_global[contador_empleados_global].informacion_personal.edad);

            printf("  Ingrese la altura del empleado (en metros): ");
            scanf("%f", &empleados_global[contador_empleados_global].informacion_personal.altura);

            printf("  Ingrese el puesto laboral: ");
            limpiar_buffer();
            fgets(empleados_global[contador_empleados_global].puesto, sizeof(empleados_global[contador_empleados_global].puesto), stdin);
            empleados_global[contador_empleados_global].puesto[strcspn(empleados_global[contador_empleados_global].puesto, "\n")] = 0;

            printf("\n  %c Empleado registrado exitosamente.\n\n", 251);
            printf("  Información guardada:\n");
            printf("  ├─ Nombre  : %s\n", empleados_global[contador_empleados_global].informacion_personal.nombre);
            printf("  ├─ Edad    : %d años\n", empleados_global[contador_empleados_global].informacion_personal.edad);
            printf("  ├─ Altura  : %.2f metros\n", empleados_global[contador_empleados_global].informacion_personal.altura);
            printf("  └─ Puesto  : %s\n", empleados_global[contador_empleados_global].puesto);

            contador_empleados_global++;
            break;

        case 5:
            system("cls");
            separador();
            printf("             LISTADO DE PERSONAS REGISTRADAS\n");
            separador();

            if (contador_personas_global == 0)
            {
                printf("  [!] No hay personas registradas.\n");
                printf("\n");
                break;
            }

            printf("  Total de personas: %d/100\n\n", contador_personas_global);

            for (int i = 0; i < contador_personas_global; i++)
            {
                printf("  PERSONA #%d\n", i + 1);
                printf("  ├─ Nombre : %s\n", personas_global[i].nombre);
                printf("  ├─ Edad   : %d años\n", personas_global[i].edad);
                printf("  └─ Altura : %.2f metros\n\n", personas_global[i].altura);
            }

            break;

        case 6:
            system("cls");
            separador();
            printf("             LISTADO DE EMPLEADOS REGISTRADOS\n");
            separador();

            if (contador_empleados_global == 0)
            {
                printf("  [!] No hay empleados registrados.\n");
                printf("\n");
                break;
            }

            printf("  Total de empleados: %d/100\n\n", contador_empleados_global);

            for (int i = 0; i < contador_empleados_global; i++)
            {
                printf("  EMPLEADO #%d\n", i + 1);
                printf("  ├─ Nombre  : %s\n", empleados_global[i].informacion_personal.nombre);
                printf("  ├─ Edad    : %d años\n", empleados_global[i].informacion_personal.edad);
                printf("  ├─ Altura  : %.2f metros\n", empleados_global[i].informacion_personal.altura);
                printf("  └─ Puesto  : %s\n\n", empleados_global[i].puesto);
            }

            break;

        case 7:
            printf("  Regresando al Menu Principal...\n");
            return;

        default:
            printf("  [!] Opci%cn no v%clida. Intente nuevamente.\n", 162, 160);
        }
        separador();
        system("pause");
    } while (opcion != 7);
}