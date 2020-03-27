#include <iostream>
#include<cstring>
#include "Solicitud.h"

using namespace std;

int main(int argc, char *argv[]) {
    int num = 5;
    int numRespuesta;
    int contador = 0;
/*    num[0] = atoi(argv[2]);
    num[1] = atoi(argv[3]);*/
    int n = atoi(argv[2]);
    Solicitud solicitud;
    //  cout << num[0] << endl;
/*    cout << num[1] << endl;*/

    while (contador < n) {

        memcpy(&numRespuesta, solicitud.doOperation(argv[1], 7200, 1, (char *) &num), sizeof(int));
        printf("Resultado:%d\n", numRespuesta);
        contador++;

    }


    return 0;
}
