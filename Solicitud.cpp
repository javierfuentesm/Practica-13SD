#include <iostream>
#include <cstring>
#include "Solicitud.h"

using namespace std;

Solicitud::Solicitud() {
    socketlocal = new SocketDatagrama(0);
}


char *
Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments) {//Usuario cliente (puerto variable)
    int enviado, recibido;
    cout << "doOperation" << endl;
    cout << arguments[0] << endl;

    struct mensaje msg;
    msg.messageType = 0;
    msg.requestId = 0;
    msg.operationId = operationId;
    memcpy(msg.arguments, arguments, sizeof(struct mensaje *));
    PaqueteDatagrama p = PaqueteDatagrama((char *) &msg, TAM_MAX_DATA, IP, puerto);
 /*   cout << "Datos enviados" << endl;
    cout << "IP: " << p.obtieneDireccion() << endl;
    cout << "Puerto: " << p.obtienePuerto() << endl;*/
    enviado = socketlocal->envia(p);
    if (enviado == -1) {
        perror("Fallo al enviar");
    }
    PaqueteDatagrama pRes = PaqueteDatagrama(4000);

    recibido = socketlocal->recibeTimeout(pRes, 2, 500);
    int contador = 1;

    while (contador < 7 && recibido == -1) {
        socketlocal->envia(p);
        recibido = socketlocal->recibeTimeout(pRes, 2, 500);
        cout << "Intento número : " << contador << ' ';
        contador++;

    }

    if (contador == 7) {
        cout << "Fallo al enviar" << endl;
        exit(0);
    } else {

        cout << "Datos recibidos" << endl;
        cout << "IP: " << pRes.obtieneDireccion() << endl;
        cout << "Puerto: " << pRes.obtienePuerto() << endl;

        struct mensaje *msgR = (struct mensaje *) pRes.obtieneDatos();

        return (char *) msgR->arguments;
    }


}
