#include <iostream>
#include <unistd.h>
#include <netdb.h>

void initServer(int PORT) {
    int serverFd, conn;
    struct sockaddr_in addr;
    char buffer[1024] = {0};
    int addrlen = sizeof(addr);
    int opt = 1;

    serverFd = socket(AF_INET, SOCK_STREAM, 0);

    setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    // Binding socket to port
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    bind(serverFd, (struct sockaddr *)&addr, sizeof(addr));

    listen(serverFd, 3);
    std::cout << "[*] Listening on port " << PORT << std::endl;

    conn = accept(serverFd, (struct sockaddr *)&addr, (socklen_t*)&addrlen);
    std::cout << "[+] New Incoming Connection..." << std::endl;

    read(conn, buffer, 1024);
    std::cout << buffer << std::endl;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./sockServer <PORT>" << std::endl;

        return 1;
    }
    int PORT = std::stoi(argv[1]);

    initServer(PORT);

    return 0;
}
