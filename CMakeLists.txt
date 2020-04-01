cmake_minimum_required(VERSION 3.15)
project(Practica12)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Practica12
        cliente.cpp
        mensaje.h
        PaqueteDatagrama.cpp
        PaqueteDatagrama.h
        Respuesta.cpp
        Respuesta.h
        servidor.cpp
        SocketDatagrama.cpp
        SocketDatagrama.h
        Solicitud.cpp
        Solicitud.h)
