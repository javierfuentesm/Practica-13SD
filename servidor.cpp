#include <iostream>
#include<cstring>
#include "Respuesta.h"

using namespace std;

int main() {
    Respuesta resp = Respuesta(7200);
    struct mensaje* msg;
    while(1){
      cout<< "Esperando Respuesta:"<<endl;
      int numeros[2];
      int numRespuesta;
      msg=resp.getRequest();
      //sscanf(msg->arguments, "%d %d", &a, &b);
        //memcpy((char*)a,msg->arguments, 2*sizeof(int));

          //memcpy((char*)b,msg->arguments, 2*sizeof(int));
        //strcpy(&numeros,&msg->arguments);
        memcpy(&numeros,&msg->arguments, 2*sizeof(int));
        cout<<"Datos recibidos:"<< numeros[0] << ","<<numeros[1]<<endl;
      numRespuesta = numeros[0]+numeros[1];
      cout<<numRespuesta<<endl;

        resp.sendReply((char*)&numRespuesta);
    }
}

//(char *) num
