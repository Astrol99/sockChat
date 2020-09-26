#include <iostream>
#include <unistd.h>
#include <netdb.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Usage: ./sockClient <IP> <PORT>" << std::endl;

        return 1;
    }
    
    return 0;
}