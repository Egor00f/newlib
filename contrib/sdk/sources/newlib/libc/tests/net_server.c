#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    int s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);




    shutdown(s, 0);

    return 0;
}
