//
//  Server.c
//  Server
//
//  Created by פנחס מנחם אפרים on 02/12/2022.
//

#include "Server.h"
#include <stdio.h>
#include <stdlib.h>


Server_t server_constructor(int domain,
                                 int service,
                                 int protocol,
                                 u_long interfase,
                                 int port,
                                 int backlog,
                                 void (*launch)(Server_t* server))
{
    Server_t server;
    
    server.domain = domain;
    server.service = service;
    server.interfase = interfase;
    server.port = port;
    server.backlog = backlog;
    
    server.address.sin_family = domain;
    server.address.sin_port = htons(port);
    server.address.sin_addr.s_addr = htonl(interfase);
    
    server.socket = socket(domain, service, protocol);
    if (server.socket == 0)
    {
        perror("Faild to conect with socket;\n");
        exit(1);
    }
    
    if (bind(server.socket, (struct sockaddr *)&server.address, sizeof(server.address)) < 0)
    {
        perror("Faild to blind socket;\n");
        exit(2);
    }
    
    if (listen(server.socket, server.backlog) < 0)
    {
        perror("Faild to start listening;\n");
        exit(3);
    }
    server.launch = launch;
    
    return server;
}
