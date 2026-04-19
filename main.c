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
        scanf("%d", &opcion);
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
    scanf("%lf", &num1);
    printf("  Ingrese el segundo n%cmero: ", 163);
    scanf("%lf", &num2);
    limpiar_buffer();

    printf("\n  Seleccione la operaci%cn a realizar:\n", 162);
    printf("  [1] Suma\n");
    printf("  [2] Resta\n");
    printf("  [3] Multiplicaci%cn\n", 162);
    printf("  [4] Divisi%cn\n", 162);
    printf("  [5] Porcentaje\n");
    printf("  [6] Potencia\n");
    printf("  [7] Raiz Cuadrada\n");
    printf("  [8] Volver al Menu Principal\n");
    separador();
    printf("  Opci%cn: ", 162);
    scanf("%d", &operacion);
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
        printf("  Regresando al Menu Principal...\n");
        break;
    default:
        printf("  [!] Opci%cn no v%clida. Intente nuevamente.\n", 162, 160);
    }
    separador();
    system("pause"); /* Pausa antes de volver al menu */
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
    scanf("%lf", &angulo_grados);
    limpiar_buffer();

    /* Convertir a radianes */
    angulo_rad = angulo_grados * (PI / 180.0);

    printf("\n  Seleccione la funci%cn trigonom%ctrica:\n", 162, 130);
    printf("  [1] Seno (sin)\n");
    printf("  [2] Coseno (cos)\n");
    printf("  [3] Tangente (tan)\n");
    printf("  [4] Cotangente (cot)\n");
    printf("  [5] Secante (sec)\n");
    printf("  [6] Cosecante (csc)\n");
    printf("  [7] Volver al Menu Principal\n");
    separador();
    printf("  Opci%cn: ", 162);
    scanf("%d", &operacion);
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
        printf("  Regresando al Menu Principal...\n");
        break;
    default:
        printf("  [!] Opci%cn no v%clida. Intente nuevamente.\n", 162, 160);
    }
    separador();
    system("pause");
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
    scanf("%lf", &valor);
    limpiar_buffer();

    printf("\n  Seleccione la funci%cn hiperb%clica:\n", 162, 130);
    printf("  [1] Seno Hiperbolico    (sinh)\n");
    printf("  [2] Coseno Hiperbolico  (cosh)\n");
    printf("  [3] Tangente Hiperbolica (tanh)\n");
    printf("  [4] Cotangente Hiperbolica (coth)\n");
    printf("  [5] Secante Hiperbolica (sech)\n");
    printf("  [6] Cosecante Hiperbolica (csch)\n");
    printf("  [7] Volver al Menu Principal\n");
    separador();
    printf("  Opci%cn: ", 162);
    scanf("%d", &operacion);
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
        printf("  Regresando al Menu Principal...\n");
        break;
    default:
        printf("  [!] Opci%cn no v%clida. Intente nuevamente.\n", 162, 160);
    }
    separador();
    system("pause");
}

/* ================================================================================
   5. INSTRUCCIONES SI CONDICIONAL
   ================================================================================ */
void instrucciones_si_condicional()
{
    int numero;

    system("cls");
    separador();
    printf("               INSTRUCCIONES SI CONDICIONAL\n");
    separador();
    printf("  Ingrese un n%cmero entero: ", 163);
    scanf("%d", &numero);
    limpiar_buffer();

    printf("\n");
    separador();

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

    /* Condicion 2: Par o impar */
    if (numero % 2 == 0)
    {
        printf("  %c El n%cmero %d es PAR.\n", 251, 163, numero); /* 251 = ✓ */
    }
    else
    {
        printf("  %c El n%cmero %d es IMPAR.\n", 251, 163, numero); /* 251 = ✓ */
    }
    separador();
    system("pause");
}

/* ================================================================================
   6. INSTRUCCIONES REPETITIVAS
   ================================================================================ */
void instrucciones_repetitivas()
{
    int opcion;

    system("cls");
    separador();
    printf("                 INSTRUCCIONES REPETITIVAS\n");
    separador();
    printf("  Seleccione el tipo de bucle:\n");
    printf("  [1] Bucle FOR\n");
    printf("  [2] Bucle WHILE\n");
    printf("  [3] Bucle DO-WHILE\n");
    printf("  [4] Volver al Menu Principal\n");
    separador();
    printf("  Opci%cn: ", 162);
    scanf("%d", &opcion);
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
        printf("  Regresando al Menu Principal...\n");
        break;
    default:
        printf("  [!] Opci%cn no v%clida. Intente nuevamente.\n", 162, 160);
    }
    separador();
    system("pause");
}

/* ================================================================================
   7. MATRICES
   ================================================================================ */
void matrices()
{
    int filas_1, columnas_1;

    system("cls");
    separador();
    printf("                          MATRICES\n");
    separador();

    printf("  Tama%co de la Matriz 1 (filas columnas): ", 164);
    scanf("%d %d", &filas_1, &columnas_1);
    limpiar_buffer();

    int matriz_1[filas_1][columnas_1];
    printf("  Ingrese los elementos de la Matriz 1:\n");
    for (int i = 0; i < filas_1; i++)
    {
        for (int j = 0; j < columnas_1; j++)
        {
            printf("    Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz_1[i][j]);
        }
    }
    limpiar_buffer();

    printf("\n  Matriz 1:\n");
    for (int i = 0; i < filas_1; i++)
    {
        printf("  ");
        for (int j = 0; j < columnas_1; j++)
        {
            printf("%6d ", matriz_1[i][j]);
        }
        printf("\n");
    }

    int filas_2, columnas_2;
    printf("\n  Tama%co de la Matriz 2 (filas columnas): ", 164);
    scanf("%d %d", &filas_2, &columnas_2);
    limpiar_buffer();

    int matriz_2[filas_2][columnas_2];
    printf("  Ingrese los elementos de la Matriz 2:\n");
    for (int i = 0; i < filas_2; i++)
    {
        for (int j = 0; j < columnas_2; j++)
        {
            printf("    Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz_2[i][j]);
        }
    }
    limpiar_buffer();

    printf("\n  Matriz 2:\n");
    for (int i = 0; i < filas_2; i++)
    {
        printf("  ");
        for (int j = 0; j < columnas_2; j++)
        {
            printf("%6d ", matriz_2[i][j]);
        }
        printf("\n");
    }

    int opciones;
    printf("\n  Seleccione la operacion a realizar:\n");
    printf("  [1] Suma\n");
    printf("  [2] Resta\n");
    printf("  [3] Multiplicaci%cn\n", 162);
    printf("  [4] Determinante\n");
    printf("  [5] Volver al Menu Principal\n");
    separador();
    printf("  Opci%cn: ", 162);
    scanf("%d", &opciones);
    limpiar_buffer();

    printf("\n");
    separador();

    switch (opciones)
    {
    case 1:
        if (filas_1 == filas_2 && columnas_1 == columnas_2)
        {
            int resultado[filas_1][columnas_1];
            for (int i = 0; i < filas_1; i++)
            {
                for (int j = 0; j < columnas_1; j++)
                {
                    resultado[i][j] = matriz_1[i][j] + matriz_2[i][j];
                }
            }
            printf("  Resultado de la SUMA:\n");
            for (int i = 0; i < filas_1; i++)
            {
                printf("  ");
                for (int j = 0; j < columnas_1; j++)
                {
                    printf("%6d ", resultado[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("  [!] ERROR: Las matrices deben tener el mismo tama%co.\n", 164);
        }
        break;

    case 2:
        if (filas_1 == filas_2 && columnas_1 == columnas_2)
        {
            int resultado[filas_1][columnas_1];
            for (int i = 0; i < filas_1; i++)
            {
                for (int j = 0; j < columnas_1; j++)
                {
                    resultado[i][j] = matriz_1[i][j] - matriz_2[i][j];
                }
            }
            printf("  Resultado de la RESTA:\n");
            for (int i = 0; i < filas_1; i++)
            {
                printf("  ");
                for (int j = 0; j < columnas_1; j++)
                {
                    printf("%6d ", resultado[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("  [!] ERROR: Las matrices deben tener el mismo tama%co.\n", 164);
        }
        break;

    case 3:
        if (columnas_1 == filas_2)
        {
            int resultado[filas_1][columnas_2];
            for (int i = 0; i < filas_1; i++)
            {
                for (int j = 0; j < columnas_2; j++)
                {
                    resultado[i][j] = 0;
                    for (int k = 0; k < columnas_1; k++)
                    {
                        resultado[i][j] += matriz_1[i][k] * matriz_2[k][j];
                    }
                }
            }
            printf("  Resultado de la MULTIPLICACI%cN:\n", 224);
            for (int i = 0; i < filas_1; i++)
            {
                printf("  ");
                for (int j = 0; j < columnas_2; j++)
                {
                    printf("%6d ", resultado[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("  [!] ERROR: Numero de columnas de M1 debe ser igual a filas de M2.\n");
        }
        break;

    case 4:
    {
        int seleccion;
        printf("\n  %cQu%c determinante desea calcular?\n", 168, 130);
        printf("  [1] Matriz 1\n");
        printf("  [2] Matriz 2\n");
        printf("  Opci%cn: ", 162);
        scanf("%d", &seleccion);
        limpiar_buffer();

        if (seleccion == 1)
        {
            if (filas_1 == columnas_1)
            {
                long det = determinante_recursivo(filas_1, matriz_1);
                printf("\n  ================================================\n");
                printf("  Determinante de la Matriz 1 (%dx%d):\n", filas_1, columnas_1);
                printf("  det(M1) = %ld\n", det);
                printf("  ================================================\n");
            }
            else
            {
                printf("\n  [!] ERROR: La Matriz 1 no es cuadrada (%dx%d).\n", filas_1, columnas_1);
            }
        }
        else if (seleccion == 2)
        {
            if (filas_2 == columnas_2)
            {
                long det = determinante_recursivo(filas_2, matriz_2);
                printf("\n  ================================================\n");
                printf("  Determinante de la Matriz 2 (%dx%d):\n", filas_2, columnas_2);
                printf("  det(M2) = %ld\n", det);
                printf("  ================================================\n");
            }
            else
            {
                printf("\n  [!] ERROR: La Matriz 2 no es cuadrada (%dx%d).\n", filas_2, columnas_2);
            }
        }
        else
        {
            printf("\n  [!] ERROR: Selecci%cn no v%clida.\n", 162, 160);
        }
    }
        break;

    case 5:
        printf("  Regresando al Menu Principal...\n");
        break;

    default:
        printf("  [!] Opci%cn no v%clida. Intente nuevamente.\n", 162, 160);
    }
    separador();
    system("pause");
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

    struct Persona persona1;
    struct Empleado empleado1;

    system("cls");
    separador();
    printf("                   REGISTROS (ESTRUCTURAS)\n");
    separador();
    printf("  *** PARTE 1: Definici%cn de Estructura Simple (Persona) ***\n\n", 162);

    printf("  Ingrese el nombre de la persona: ");
    fgets(persona1.nombre, sizeof(persona1.nombre), stdin);
    persona1.nombre[strcspn(persona1.nombre, "\n")] = 0; /* Remover \n */

    printf("  Ingrese la edad de la persona: ");
    scanf("%d", &persona1.edad);
    printf("  Ingrese la altura de la persona (en metros): ");
    scanf("%f", &persona1.altura);
    limpiar_buffer();

    printf("\n  Informaci%cn de la Persona (Acceso Directo):\n", 162);
    printf("  ├─ Nombre : %s\n", persona1.nombre);
    printf("  ├─ Edad   : %d a%cos\n", persona1.edad, 164); /* anos sin tilde */
    printf("  └─ Altura : %.2f metros\n", persona1.altura);

    /* ACCESO A TRAVES DE PUNTEROS */
    printf("\n  Informaci%cn a traves de PUNTEROS:\n", 162);
    int *edad_ptr = &persona1.edad;
    printf("  ├─ Edad   : %d a%cos (puntero)\n", *edad_ptr, 164); /* anos sin tilde */

    char *nombre_ptr = persona1.nombre;
    printf("  ├─ Nombre : %s (puntero)\n", nombre_ptr);

    float *altura_ptr = &persona1.altura;
    printf("  └─ Altura : %.2f metros (puntero)\n", *altura_ptr);

    /* ESTRUCTURA ANIDADA */
    printf("\n  *** PARTE 2: Estructura Anidada (Empleado -> Persona) ***\n\n");

    printf("  Ingrese el nombre del empleado: ");
    fgets(empleado1.informacion_personal.nombre,
          sizeof(empleado1.informacion_personal.nombre), stdin);
    empleado1.informacion_personal.nombre[strcspn(empleado1.informacion_personal.nombre, "\n")] = 0;

    printf("  Ingrese la edad del empleado: ");
    scanf("%d", &empleado1.informacion_personal.edad);
    printf("  Ingrese la altura del empleado (en metros): ");
    scanf("%f", &empleado1.informacion_personal.altura);
    printf("  Ingrese el puesto laboral: ");
    limpiar_buffer();
    fgets(empleado1.puesto, sizeof(empleado1.puesto), stdin);
    empleado1.puesto[strcspn(empleado1.puesto, "\n")] = 0;

    printf("\n  Informacion del Empleado (Estructura Anidada):\n");
    printf("  ├─ Nombre  : %s\n", empleado1.informacion_personal.nombre);
    printf("  ├─ Edad    : %d a%cos\n", empleado1.informacion_personal.edad, 164); /* anos sin tilde */
    printf("  ├─ Altura  : %.2f metros\n", empleado1.informacion_personal.altura);
    printf("  └─ Puesto  : %s\n", empleado1.puesto);
    system("pause");
}