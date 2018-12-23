//
// Created by yael on 12/20/18.
//

#include "Server.h"
#include <iostream>
#include "OpenServerCommand.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>

using namespace std;

Server::Server(int port) {
    this->port = port;
}

void Server::setPort(int p) {
    this->port = p;
}

void Server::openSock() {
    int clilen;
    struct sockaddr_in serv_addr, cli_addr;

    /* First call to socket() function */
    this->serverSockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (this->serverSockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    //portno = 5001;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(this->port);

    cout <<this->port << endl;

    cout <<"bind" << endl;
    /* Now bind the host address using bind() call.*/
    if (bind(this->serverSockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    cout <<"finish bind" << endl;

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(this->serverSockfd,5);
    clilen = sizeof(cli_addr);

    cout <<"accept" << endl;
    /* Accept actual connection from the client */
    cliSockfd = accept(this->serverSockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    cout <<"finish accept" << endl;
    if (cliSockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    cout <<"finish accept" << endl;
}

//TODO:sleep
void Server::readData(int cliSock) {
    char buffer[BUFFER_SIZE];
    int  n;
    while (true) {
        // If connection is established then start communicating *//*
        bzero(buffer, (BUFFER_SIZE - 1));
        n = read(cliSock, buffer, (BUFFER_SIZE - 1));

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Here is the message: %s\n", buffer);
    }
}

int Server::getCliSock() {
    return this->cliSockfd;
}

vector<string> names = {"/instrumentation/airspeed-indicator/indicated-speed-kt",
                        "/instrumentation/altimeter/indicated-altitude-ft",
                        "/instrumentation/altimeter/pressure-alt-ft",
                        "/instrumentation/attitude-indicator/indicated-pitch-deg",
                        "/instrumentation/attitude-indicator/indicated-roll-deg",
                        "/instrumentation/attitude-indicator/internal-pitch-deg",
                        "/instrumentation/attitude-indicator/internal-roll-deg",
                        "/instrumentation/encoder/indicated-altitude-ft",
                        "/instrumentation/encoder/pressure-alt-ft",
                        "/instrumentation/gps/indicated-altitude-ft",
                        "/instrumentation/gps/indicated-ground-speed-kt",
                        "/instrumentation/gps/indicated-vertical-speed",
                        "/instrumentation/heading-indicator/indicated-heading-deg",
                        "/instrumentation/magnetic-compass/indicated-heading-deg",
                        "/instrumentation/slip-skid-ball/indicated-slip-skid",
                        "/instrumentation/turn-indicator/indicated-turn-rate",
                        "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
                        "/controls/flight/aileron","/controls/flight/elevator",
                        "/controls/flight/rudder","/controls/flight/flaps",
                        "/controls/engines/engine/throttle",
                        "/engines/engine/rpm"};