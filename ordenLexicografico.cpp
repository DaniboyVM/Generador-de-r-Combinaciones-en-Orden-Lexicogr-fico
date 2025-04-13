#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <filesystem> // Para manejo de rutas




using namespace std;


int captura();
void generar_combinaciones(int A[], int n, int r, ofstream& csvFile);

int main() {
    int n, r, opc;
    cout<<"Generador de r-Combinaciones en Orden Lexicográfico"<<endl;
    cout << "Ingrese el tama\244o del conjunto (n): ";
    n = captura();
    while (n <= 0) {
        cout << "El tama\244o debe ser positivo!" << endl;
         n = captura();
    }

    cout << "Ingrese el tama\244o de las combinaciones (r): ";
    r = captura();
    while (r < 0 || r > n) {
        cout << "r debe estar entre 0 y " << n << endl;
         r = captura();
    }

    cout << "Como quieres llenar el conjunto?" << endl;
    cout << "1) automatico" << endl;
    cout << "2) manual" << endl;
    do {
        opc = captura();
    } while (opc < 1 || opc > 2);

    int* A = new int[n];

    if (opc == 1) {
        for (int i = 0; i < n; i++) {
            A[i] = i +1;
            cout << "Elemento " << i + 1 << ": " << A[i] << endl;
        }
    } else {
        cout<<"Solo se aceptan numeros"<<endl;
        cout << "Ingrese los " << n << " elementos ordenados del conjunto:\n";
        for (int i = 0; i < n; ++i) {
            cout << "Elemento " << i + 1 << ": ";
            A[i]=captura();
            for(int j = 0; j< i; ++j){
                while(A[j]==A[i]){
                    j=0;
                    cout<<"El numero ya esta en el conjunto, ingrese otro"<<endl;
                    cout << "Elemento " << i + 1 << ": ";
                    A[i]=captura();

                }
           }

        }
    }

    // Abrir archivo CSV
    ofstream csvFile("combinaciones.csv");
    if (!csvFile.is_open()) {
        cerr << "Error al crear el archivo combinaciones.csv" << endl;
        delete[] A;
        return 1;
    }

    //  encabezados
    csvFile << "Combinaciónes:, , conjunto: \n";  // Usar coma como separador

    cout << "\nGenerando combinaciones de tama\244o " << r << " en combinaciones.csv...\n";
    generar_combinaciones(A, n, r, csvFile);

    csvFile.close();
    delete[] A;

    cout << "Combinaciones guardadas en combinaciones.csv" << endl;
    return 0;
}

int captura() {
    int opc;
    do {
        if (cin.fail()) {
            cout << "ERROR, ingrese un dato valido: "<<endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
         cin >> opc;
    } while ( cin.fail());
    return opc;
}

void generar_combinaciones(int A[], int n, int r, ofstream& csvFile) {

    if (n < 1 || r < 0 || r > n) {
        cerr << "Parámetros inválidos!" << endl;
        return;
    }

    int* s = new int[r];
    int contador = 1;  // Contador de combinaciones

    // Inicializar primera combinación
    for (int i = 0; i < r; ++i) {
        s[i] = i;
    }

    // Escribir primera combinación en CSV
    contador++;
    csvFile << "\"";
    for (int i = 0; i < r; ++i) {
        csvFile << A[s[i]];
        if (i != r-1) csvFile << ", ";  // Separador con coma y espacio
    }
    csvFile << "\"";
    csvFile << "\ , ," ;
    csvFile << "\"";


    //Escribimos el conjunto
    for (int i = 0; i < n; ++i) {
        csvFile << ", " <<A[i];
    }

    csvFile << "\"\n";



    if (r == 0) {
        delete[] s;
        return;
    }

    while (true) {
        int m = r - 1;
        while (m >= 0 && s[m] == n - r + m) {
            m--;
        }

        if (m < 0) break;

        s[m]++;

        for (int j = m + 1; j < r; ++j) {
            s[j] = s[j - 1] + 1;
        }

        // Escribir combinación en CSV
        contador++;
        csvFile << "\"";
        for (int i = 0; i < r; ++i) {
            csvFile << A[s[i]];
            if (i != r-1) csvFile << ", ";  // Separador con coma y espacio
        }
        csvFile << "\"\n";
    }

    delete[] s;
    int combinaciones=1, divisor=1;
    for(int i=n; i>n-r; i--){
        combinaciones*=i;
    }
    for(int i=r; i>0; i--){
        divisor*=i;
    }
    combinaciones=combinaciones/divisor;
    // Mostrar resumen en consola
    cout << "Total de combinaciones generadas: " << (contador-1) << endl;
    cout<<  "Total de combinaciones teoricas C("<<n<<","<<r<<") = "<<combinaciones<<endl;
}

