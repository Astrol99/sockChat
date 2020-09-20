#include <iostream>
#include <unistd.h>
#include <netdb.h>

void initServer(int *PORT) {
    //int serverFd = socket(AF_INET, SOCK_STREAM, 0);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./server <PORT>" << std::endl;

        return 1;
    }
    int PORT = std::stoi(argv[1]);

    initServer(&PORT);

    return 0;
}