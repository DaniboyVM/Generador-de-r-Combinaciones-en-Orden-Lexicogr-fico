# Generador-de-r-Combinaciones-en-Orden-Lexicografico

El ordenamiento lexicografico es un tipo de ordenamiento que se usa en los diccionarios. Compara los elementos carácter por carácter , siguiendo el orden alfabético o numérico según el tipo de dato.

Daniel ALberto Flores Preciado

El programa fue compilado utilizando el compilador predeterminado de Code::Blocks 20.03 de c++ (lanzado en marzo de 2020), GNU GCC (MinGW-w64).

El programa implementa un algoritmo eficiente para generar todas las r-combinaciones de un conjunto de n elementos en orden lexicográfico (orden numérico creciente).
n es el tamaño del conjunto (debe ser positivo).
r es el tamaño de las combinaciones (debe cumplir 0 ≤ r ≤ n).

Se asegura que n > 0 y que r esté en el rango [0, n].

Tiene una opcion para crear un conjunto de manera manual y se  verifica que los elementos del conjuntos sean unicos




El núcleo del programa está en la función generar_combinaciones, que utiliza un enfoque iterativo basado en índices para generar combinaciones sin repetición:

Pasos del Algoritmo:

~Inicialización:

Se crea un arreglo  de tamaño r para almacenar los índices de la combinación actual.

La primera combinación siempre es {0, 1, 2, ..., r-1} (índices de los primeros r elementos del conjunto).

~Generación de Combinaciones:

Bucle principal: Mientras existan combinaciones por generar:

Buscar el pivote:

Se encuentra el índice m más a la derecha que pueda incrementarse sin superar n - r + m.

Ejemplo: Para n=5, r=3, y combinación actual {0, 3, 4}, m=1 (porque s[1]=3 puede incrementarse a 4, pero s[2]=4 ya no puede incrementarse más).

Incrementar y ajustar:

Se incrementa s[m] en 1.

Los índices a la derecha de m se ajustan secuencialmente: s[j] = s[j-1] + 1 para j > m.

Esto genera la siguiente combinación en orden lexicográfico.

Asi mismo el programa genera un archivo .CSV, llamado combinaciones, en el cual se guarda el conjunto y todas las combinaciones de r. El archivo esta organizado por dos columnas, la primera que se registran todas las combinaciones en orden lexicografico que se hicieron y la segunda columna nos dice el conjunto universo en el cual se hacen las combinaciones.

El programa hace una doblee verificacion del conteo de combinaciones, una por la forma teorica de  C(n, r) = n! / (r! * (n-r)!). y la otra, que es por medio de un contador.



