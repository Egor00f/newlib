#ifndef _KSYS_SOCKET_H_
#define _KSYS_SOCKET_H_

#include <stddef.h>
#include <sys/ksys.h>

#include <bits/socket.h>

#define PORT(X) (X << 8)

#pragma pack(push, 1)
typedef struct ksys_sockaddr {
	uint16_t sin_family;
	uint16_t sin_port;
	uint32_t sin_addr;
	uint64_t sin_zero;
} ksys_sockaddr_t;

typedef struct ksys_optstruct {
	unsigned int level;
	unsigned int optionname;
	unsigned int optlenght;
	unsigned char options;
} ksys_optstruct_t;
#pragma pack(pop)

int _ksys_socket(int domain, int type, int protocol);
int _ksys_close(int socket);
int _ksys_bind(int socket, const ksys_sockaddr_t* address, int address_len);
int _ksys_listen(int socket, int backlog);
int _ksys_connect(int socket, const ksys_sockaddr_t* address, int socket_len);
int _ksys_accept(int socket, ksys_sockaddr_t* address, int address_len);
int _ksys_send(int socket, const void* message, size_t msg_len, int flag);
int _ksys_recv(int socket, void* buffer, size_t buff_len, int flag);
int _ksys_setsockopt(int socket, const ksys_optstruct_t* opt);
int _ksys_getsockopt(int socket, ksys_optstruct_t* opt);
int _ksys_socketpair(int* socket1, int* socket2);

#endif //_KSYS_SOCKET_H_
