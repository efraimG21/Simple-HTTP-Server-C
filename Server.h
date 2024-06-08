//
//  Server.h
//  Server
//
//  Created by פנחס מנחם אפרים on 02/12/2022.
//

#ifndef Server_h
#define Server_h

#include <sys/socket.h>
#include <netinet/in.h>

typedef struct Server{
    int domain;
    int service;
    u_long interfase;
    int port;
    int backlog;
    
    struct sockaddr_in address;
    
    int socket;
    
    void (*launch)(struct Server* server);
} Server_t;

Server_t server_constructor(int domain,
                                 int service,
                                 int protocol,
                                 u_long interfase,
                                 int port,
                                 int backlog,
                                 void (*launch)(Server_t* server));
#endif /* Server_h */

