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

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Usage: ./sockClient <IP> <PORT>" << std::endl;

        return 1;
    }
    const char *IP = argv[1];
    int PORT = std::stoi(argv[2]);
    
    int sock;
    struct sockaddr_in servAddr;
    char buffer[1024] = {0};
    std::string userMsg;

    // Create socket file descriptor
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // Setup address struct
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(PORT);

    // Convert IP to binary
    if (inet_pton(AF_INET, IP, &servAddr.sin_addr) != 1) {
        std::cout << "[-] Invalid IP Address" << std::endl;
        
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0) {
        std::cout << "[-] Unable to connect" << std::endl;

        return 1;
    }
    
    std::cin >> userMsg;
    send(sock, userMsg.c_str(), userMsg.length(), 0);

    recv(sock, buffer, 1024, 0);
    std::cout << buffer << std::endl;

    return 0;
}
