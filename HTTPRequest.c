//
//  HTTPRequest.c
//  Server
//
//  Created by פנחס מנחם אפרים on 29/01/2023.
//

#include "HTTPRequest.h"

#include <stdlib.h>
#include <string.h>

int method_select(char* method){
    if (strcmp(method, "GET") == 0){
        return GET;
    }
    else if (strcmp(method, "POST") == 0){
        return POST;
    }
    else if (strcmp(method, "PUT") == 0){
        return PUT;
    }
    else if (strcmp(method, "HEAD") == 0){
        return HEAD;
    }
    else if (strcmp(method, "PATCH") == 0){
        return PATCH;
    }
    else if (strcmp(method, "DELETE") == 0){
        return DELETE;
    }
    else if (strcmp(method, "CONTECT") == 0){
        return CONTECT;
    }
    else if (strcmp(method, "OPTIONS") == 0){
        return OPTIONS;
    }
    else if (strcmp(method, "TRACE") == 0){
        return TRACE;
    }
    return -1;
}
//"GET / HTTP/1.1\r\nHost: 127.0.0.1\r\nUpgrade-Insecure-Requests: 1\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nUser-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/16.3 Safari/605.1.15\r\nAccept-Language: he-IL,he;q=0.9\r\nAccept-Encoding: gzip, deflate\r\nConnection: keep-alive\r\n\r\n"
HTTPRequest_t http_request_constructor(char* request_string)
{
    HTTPRequest_t request;
    char requested[strlen(request_string)];
    printf("%s\n", request_string);
    strcpy(requested, request_string);
    for (int i = 0; i < strlen(requested) - 2; ++i) {
            if (requested[i] == '\r' && requested[i + 1] == '\n'){
            printf("%d    %c", i, requested[i]);
            requested[i + 1]  = '|';
        }
    }
    char* request_line = strtok(requested, "\n");
    char* header_fildes = strtok(NULL, "|");
    char* body = strtok(NULL, "|");
    

    char* method = strtok(request_line, " ");
    request.method = method_select(method);
    char* URI = strtok(NULL, " ");
    request.URI = URI;
    char* HTTPVersion = strtok(NULL, " ");
    HTTPVersion = strtok(HTTPVersion, "/");
    HTTPVersion = strtok(NULL, "/");
    request.HTTPVersion = (float)atof(HTTPVersion);
    
    return request;
}
