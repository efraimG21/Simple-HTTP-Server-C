//
//  main.c
//  Server
//
//  Created by פנחס מנחם אפרים on 02/12/2022.
// gcc Server.c Server.h main.c


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <strings.h> // bzero()
#include <sys/socket.h>

#include "Server.h"
#include "HTTPRequest.h"

void launch(Server_t* server);

int main(void)
{
    Server_t server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 10, launch);
    server.launch(&server);
    return 0;
}


void launch(Server_t* server)
{
    char buffer[30000];
    char* hello = "HTTP/1.1 200 OK\nGMT\nServer: Apache/2.2.14 (Win32)\nLast-Modified: Wed, 05 Nov 2001 19:15:56 GMT\nContent-Type: text/html\nConnection: Closed\n\n<!DOCTYPE html><html><head><style>body {background-color: lightblue;}h1 {color: blue;text-align: center;}p {font-family: verdana;font-size: 20px;}</style></head><body><h1>My First CSS Example</h1><p>This is a paragraph.</p></body></html>";
    int addres_length = sizeof(server->address);
    int new_socket;
    
    while (true)
    {
        printf("\n=== WAITING FOR CONNECTION ===\n");
        new_socket = accept(server->socket, (struct sockaddr*)&server->address, (socklen_t*)&addres_length);
        read(new_socket, buffer, 30000);
        http_request_constructor(buffer);
        printf("%s\n",buffer);
        write(new_socket, hello, strlen(hello));
        close(new_socket);
    }
}
