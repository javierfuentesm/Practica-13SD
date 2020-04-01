#include "Respuesta.h"
#include <cstring>
#include <iostream>

using namespace std;

PaqueteDatagrama p = PaqueteDatagrama(TAM_MAX_DATA);

Respuesta::Respuesta(int pl) {
    socketlocal = new SocketDatagrama(pl);
}

struct mensaje *Respuesta::getRequest(void) {
    int recibido = socketlocal->recibe(p);
    if (recibido == -1) {
        perror("Fallo al recibir");
    }

    struct mensaje *msgR = (struct mensaje *) p.obtieneDatos();

    return (struct mensaje *) p.obtieneDatos();
}

void Respuesta::sendReply(int *respuesta) {
    struct mensaje msg;
    msg.messageType = 1;
    msg.requestId = 1;
    msg.operationId = 1;
    memcpy(&msg.arguments, respuesta, sizeof(&respuesta));

    p.inicializaDatos((char *) &msg);
    cout << "\nDeposito exitoso" << endl;
    cout << "Cantidad" << p.obtieneDatos()<< endl;

    int enviado = socketlocal->envia(p);
    if (enviado == -1) {
        perror("Fallo al enviar");
    }
}
