#include <iostream>
#include <unistd.h>
#include <netdb.h>

void initServer(int PORT) {
    int serverFd, conn;
    struct sockaddr_in addr;

    serverFd = socket(AF_INET, SOCK_STREAM, 0);

    // Binding socket to port
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    bind(serverFd, (struct sockaddr *)&addr, sizeof(addr));

    listen(serverFd, 3);

    conn = accept(serverFd, (struct sockaddr *)&addr, (socklen_t*)sizeof(addr));

    char buffer[1024] = {0};
    read(conn, buffer, 1024);
    std::cout << buffer << std::endl;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./server <PORT>" << std::endl;

        return 1;
    }
    int PORT = std::stoi(argv[1]);

    initServer(PORT);

    return 0;
}
