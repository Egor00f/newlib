#include <sys/ksys_socket.h>
#include <errno.h>

static void _conv_socket_err() {
    switch (errno)
    {
    case 1:  errno = ENOBUFS; break;
    case 2:  errno = EINPROGRESS; break;
    case 4:  errno = EOPNOTSUPP; break;
    case 6:  errno = EWOULDBLOCK; break;
    case 9:  errno = ENOTCONN; break;
    case 10: errno = EALREADY; break;
    case 11: errno = EINVAL; break;
    case 12: errno = EMSGSIZE; break;
    case 18: errno = ENOMEM; break;
    case 20: errno = EADDRINUSE; break;
    case 61: errno = ECONNREFUSED; break;
    case 52: errno = ECONNRESET; break;
    case 56: errno = EISCONN; break;
    case 60: errno = ETIMEDOUT; break;
    case 54: errno = ECONNABORTED; break;
    default: errno = 0; break;
    }
}

int _ksys_socket(int domain, int type, int protocol)
{
    int socket;

    asm_inline(
        "int $0x40"
        :"=b"(errno), "=a"(socket)
        : "a"(75), "b"(0), "c"(domain), "d"(type), "S"(protocol)
    );

    _conv_socket_err();

    return socket;
}

int _ksys_close(int socket)
{
    int status;

    asm_inline(
        "int $0x40"
        :"=b"(errno), "=a"(status)
        : "a"(75), "b"(1), "c"(socket)
    );

    _conv_socket_err();

    return status;
}

int _ksys_bind(int socket, const ksys_sockaddr_t* addres, int addres_len)
{
    int status;

    asm_inline(
        "int $0x40"
        :"=b"(errno), "=a"(status)
        : "a"(75), "b"(2), "c"(socket), "d"(addres), "S"(addres_len)
    );

    _conv_socket_err();

    return status;
}

int _ksys_listen(int socket, int backlog)
{
    int status;

    asm_inline(
        "int $0x40"
        :"=b"(errno), "=a"(status)
        : "a"(75), "b"(3), "c"(socket), "d"(backlog)
    );

    _conv_socket_err();

    return status;
}

int _ksys_connect(int socket, const ksys_sockaddr_t* address, int socket_len)
{
    int status;

    asm_inline(
        "int $0x40"
        :"=b"(errno), "=a"(status)
        : "a"(75), "b"(4), "c"(socket), "d"(address), "S"(socket_len)
    );

    _conv_socket_err();

    return status;
}

int _ksys_accept(int socket, ksys_sockaddr_t* address, int address_len)
{
    int new_socket;

    asm_inline(
        "int $0x40"
        :"=b"(errno), "=a"(new_socket)
        : "a"(75), "b"(5), "c"(socket), "d"(address), "S"(address_len)
    );

    _conv_socket_err();

    return new_socket;
}

int _ksys_send(int socket, const void* message, size_t msg_len, int flag)
{
    int status;

    asm_inline(
        "int $0x40"
        :"=b"(errno), "=a"(status)
        : "a"(75), "b"(6), "c"(socket), "d"(message), "S"(msg_len), "D"(flag)
    );

    _conv_socket_err();

    return status;
}

int _ksys_recv(int socket, void* buffer, size_t buff_len, int flag)
{
    int status;

    asm_inline(
        "int $0x40"
        :"=b"(errno), "=a"(status)
        : "a"(75), "b"(7), "c"(socket), "d"(buffer), "S"(buff_len), "D"(flag)
    );

    _conv_socket_err();

    return status;
}

int _ksys_setsockopt(int socket, const ksys_optstruct_t* opt)
{
    int status;

    asm_inline(
        "int $0x40"
        :"=b"(errno), "=a"(status)
        : "a"(75), "b"(8), "c"(socket), "d"(opt)
    );

    _conv_socket_err();

    return status;
}

int _ksys_getsockopt(int socket, ksys_optstruct_t* opt)
{
    int status;

    asm_inline(
        "int $0x40"
        :"=b"(errno), "=a"(status)
        : "a"(75), "b"(9), "c"(socket), "d"(opt)
    );

    _conv_socket_err();

    return status;
}

int _ksys_socketpair(int* socket1, int* socket2)
{
    int s1, s2;

    asm_inline(
        "int $0x40"
        : "=a"(s1), "=b"(s2)
        : "a"(75), "b"(10)
    );

    *socket1 = s1;
    *socket2 = s2;

    errno = s2;

    _conv_socket_err();

    return s1;
}
