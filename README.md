
# Simple HTTP Server

This repository contains the source code for a simple HTTP server written in C. The server listens for incoming HTTP requests, processes them, and responds with a basic HTML page.

## Features

- Handles basic HTTP GET requests.
- Responds with a static HTML page.
- Custom server and HTTP request handling structures.
- Error handling for socket operations.

## Getting Started

### Prerequisites

- A C compiler (e.g., `gcc`).
- Basic understanding of C programming and socket programming.
- UNIX-like operating system (Linux, macOS, etc.).

### Building the Server

To build the server, run the following command in your terminal:

```sh
gcc Server.c HTTPRequest.c main.c -o server
```

This command compiles the source files and creates an executable named `server`.

### Running the Server

After building the server, you can run it with:

```sh
./server
```

The server will start listening on port `8080` for incoming HTTP requests. You can test it by opening a web browser and navigating to `http://localhost:8080`.

### Directory Structure

```
.
├── main.c
├── Server.c
├── Server.h
├── HTTPRequest.c
├── HTTPRequest.h
├── README.md
```

- **`main.c`**: The entry point for the server application.
- **`Server.c`**: Implementation of the server-related functions.
- **`Server.h`**: Header file for the server-related declarations.
- **`HTTPRequest.c`**: Implementation of the HTTP request parsing functions.
- **`HTTPRequest.h`**: Header file for the HTTP request-related declarations.

### Code Overview

#### `main.c`

Sets up the server and starts listening for connections.

#### `Server.c` and `Server.h`

Defines the `Server_t` structure and the server constructor function. Handles socket creation, binding, and listening.

#### `HTTPRequest.c` and `HTTPRequest.h`

Defines the `HTTPRequest_t` structure and the function to parse incoming HTTP requests.

### Customization

You can customize the response HTML in the `launch` function within `main.c`:

```c
const char* response = "HTTP/1.1 200 OK\n"
                       "Server: CustomServer\n"
                       "Content-Type: text/html\n"
                       "Connection: Closed\n\n"
                       "<!DOCTYPE html><html><head><style>body {background-color: lightblue;}h1 {color: blue;text-align: center;}p {font-family: verdana;font-size: 20px;}</style></head><body><h1>My First CSS Example</h1><p>This is a paragraph.</p></body></html>";
```

### Error Handling

The server includes basic error handling for:
- Socket creation failure
- Binding failure
- Listening failure
- Accepting connections failure

### Debugging

To enable debugging information, ensure that the `printf` statements in the code are active. This will print request details to the console, which can help in debugging.

## Contributing

Feel free to contribute to the project by opening issues or pull requests.


Feel free to customize the content as needed for your project. If you have any specific requirements or if you'd like further modifications, please let me know!


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

