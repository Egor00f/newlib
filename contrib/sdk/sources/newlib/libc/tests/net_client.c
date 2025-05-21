/* Код клиента на языке Си */

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    struct sockaddr_in stSockAddr;
    int i32Res;
    int i32SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (i32SocketFD == -1) {
        perror("Ошибка: невозможно создать сокет");
        return EXIT_FAILURE;
    }

    memset(&stSockAddr, 0, sizeof(stSockAddr));

    stSockAddr.sin_family = PF_INET;
    stSockAddr.sin_port = htons(1100);
    i32Res = inet_pton(PF_INET, "192.168.0.1", &stSockAddr.sin_addr);

    if (i32Res < 0) {
        perror("Ошибка: первый параметр не относится к категории корректных адресов");
        close(i32SocketFD);
        return EXIT_FAILURE;
    }
    else if (!i32Res) {
        perror("Ошибка: второй параметр не содержит корректного IP-адреса");
        close(i32SocketFD);
        return EXIT_FAILURE;
    }

    if (connect(i32SocketFD, (struct sockaddr*)&stSockAddr, sizeof(stSockAddr)) == -1) {
        perror("Ошибка: соединения");
        close(i32SocketFD);
        return EXIT_FAILURE;
    }

    /* выполнение операций чтения и записи ... */

    shutdown(i32SocketFD, SHUT_RDWR);

    return 0;
}
