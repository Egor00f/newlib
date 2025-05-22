#include <sys/socket.h>
#include <sys/ksys_socket.h>
#include <stdlib.h>

int socket(int family, int type, int protocol)
{
    return _ksys_socket(family, type, protocol);
}

int socketpair(int __domain, int __type, int __protocol, int __fds[2])
{
    return _ksys_socketpair(__fds, __fds + sizeof(int));
}


int shutdown(int sockfd, int how)
{
    return _ksys_close(sockfd);
}

int bind(int fd, struct sockaddr* umyaddr, int addrlen)
{
    return _ksys_bind(fd, (ksys_sockaddr_t*)umyaddr, addrlen);
}

int accept(int fd, struct sockaddr* addr, socklen_t addr_len)
{
    return _ksys_accept(fd, (ksys_sockaddr_t*)addr, addr_len);
}

int accept4(int fd, struct sockaddr* addr, socklen_t addr_len, int flags)
{
    return accept(fd, (ksys_sockaddr_t*)addr, addr_len);
}

int connect(int fd, const struct sockaddr* uservaddr, int addrlen)
{
    return _ksys_connect(fd, (ksys_sockaddr_t*)uservaddr, addrlen);
}

int listen(int fd, int backlog)
{
    return _ksys_listen(fd, backlog);
}

ssize_t recv(int sockfd, void* buff, size_t buff_len, int flags)
{
    return _ksys_recv(sockfd, buff, buff_len, flags);
}

ssize_t send(int sockfd, const void* buff, size_t buff_len, int flags)
{
    return _ksys_send(sockfd, buff, buff_len, flags);
}

int setsockopt(int sockfd, int level, int option, const void* value, socklen_t value_length)
{
    ksys_optstruct_t* opt = (ksys_optstruct_t*)malloc(sizeof(ksys_optstruct_t) + value_length);

    opt->level = level;
    opt->optionname = option;
    opt->optlenght = value_length;
    memset(opt->options, value, value_length);

    return _ksys_setsockopt(sockfd, opt);
}

int getsockopt(int sockfd, int level, int option, void* value, socklen_t value_length)
{
    ksys_optstruct_t* opt = (ksys_optstruct_t*)malloc(sizeof(ksys_optstruct_t) + value_length);

    opt->level = level;
    opt->optionname = option;

    int ret = _ksys_getsockopt(sockfd, opt);

    memset(value, opt->options, value_length);

    free(opt);

    return ret;
}

ssize_t sendto(int sockfd, const void* buff, size_t buff_len, int flags, struct sockaddr* addr, socklen_t addr_len)
{
    if (connect(sockfd, addr, addr_len) == 0)
    {
        return send(sockfd, buff, buff_len, flags);
    }

    return 0;
}

ssize_t recvfrom(int sockfd, void* buff, size_t buff_len, int flags, struct sockaddr* addr, socklen_t addr_len)
{
    if (connect(sockfd, addr, addr_len) == 0)
    {
        return send(sockfd, buff, buff_len, flags);
    }

    return 0;
}
