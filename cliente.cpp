#include <iostream>
#include<cstring>
#include "Solicitud.h"
#include <time.h>

using namespace std;

int main(int argc, char *argv[]) {
    int numRespuesta[2];
    int contador = 0;

    int n = atoi(argv[2]);
    Solicitud solicitud;

        srand(time(NULL));

    while (contador < n) {
        int transacciones = 1 + rand() % 9;
        cout << transacciones<<endl;
        memcpy(&numRespuesta, solicitud.doOperation(argv[1], 7200, 1, (char *) &transacciones), 2*sizeof(int));
/*
        printf("Deposito de %d total %d " ,numRespuesta[0],numRespuesta[1]);
*/
        cout << "Deposito de"<< numRespuesta[0] << "total de " <<numRespuesta[1]<<endl;
        contador++;

    }


    return 0;
}
