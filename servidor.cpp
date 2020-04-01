#include <iostream>
#include<cstring>
#include "Respuesta.h"

using namespace std;

int main() {
    Respuesta resp = Respuesta(7200);
    int nbd = 0;
    int total = 0;
    int respuesta[2];
    struct mensaje *msg;

    while (1) {
        cout << "Esperando Respuesta:" << endl;
        msg = resp.getRequest();
        memcpy(&nbd, &msg->arguments, sizeof(int));
        total = total + nbd;
        cout << "Se recibio una transferencia por :" << nbd << "El total de la cuenta es" << total << endl;
        respuesta[0] = nbd;
        respuesta[1] = total;
        resp.sendReply((int *) respuesta);


    }

}

//(char *) num
