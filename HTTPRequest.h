//
//  HTTPRequest.h
//  Server
//
//  Created by פנחס מנחם אפרים on 29/01/2023.
//

#ifndef HTTPRequest_h
#define HTTPRequest_h

#include <stdio.h>

enum HTTPrequest{
    GET,
    POST,
    PUT,
    HEAD,
    PATCH,
    DELETE,
    CONTECT,
    OPTIONS,
    TRACE,
};

typedef struct HTTPRequest{
    int method;
    char* URI;
    float HTTPVersion;
}HTTPRequest_t;

struct HTTPRequest http_request_constructor(char* request_string);

#endif /* HTTPRequest_h */
