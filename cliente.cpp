#include <iostream>
#include<cstring>
#include "Solicitud.h"

using namespace std;

int main(int argc, char* argv[]) {
	int num[2];
	int numRespuesta;
    num[0] = atoi(argv[2]);
    num[1] = atoi(argv[3]);
	Solicitud solicitud;
	cout<< num[0]<<endl;
	cout<<num[1]<<endl;
	memcpy(&numRespuesta,solicitud.doOperation(argv[1],7200,1,(char*)&num),2*sizeof(int));


	printf("Resultado:%d\n", numRespuesta);
	return 0;
}
