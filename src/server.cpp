#include <iostream>
#include <string>
#ifdef _WIN32
    #include <WinSock2.h>
    #include <WS2tcpip.h>
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netdb.h>
    #include <unistd.h>
#endif
#pragma comment(lib, "Ws2_32.lib")

std::string getConnIP(struct sockaddr_in &addr) {
    struct sockaddr_in* pV4Addr = (struct sockaddr_in*)&addr;
    struct in_addr ipAddr = pV4Addr->sin_addr;
    char str[INET_ADDRSTRLEN];
    return inet_ntop(AF_INET, &ipAddr, str, INET_ADDRSTRLEN);
}

void initServer(int PORT) {
    int serverFd, conn;
    struct sockaddr_in addr;
    char buffer[1024] = {0};
    int addrlen = sizeof(addr);
    int opt = 1;

    serverFd = socket(AF_INET, SOCK_STREAM, 0);

    setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, (char *) &opt, sizeof(opt));

    // Binding socket to port
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    bind(serverFd, (struct sockaddr *)&addr, sizeof(addr));

    listen(serverFd, 3);
    std::cout << "[*] Listening on port " << PORT << std::endl;

    conn = accept(serverFd, (struct sockaddr *)&addr, (socklen_t*)&addrlen);
    std::string connIP = getConnIP(addr);
    std::cout << "New Incoming Connection from " << connIP << "\n\n";

    recv(conn, buffer, 1024, 0);
    std::string userMsg = connIP + ": " + buffer;

    std::cout << userMsg << std::endl;
    send(conn, userMsg.c_str(), userMsg.length(), 0);
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
