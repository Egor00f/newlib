#ifndef SYS_SOCKET_H
#define SYS_SOCKET_H	1

#include <stddef.h>
#include <sys/types.h>
#include <bits/socket.h>
#include <bits/sockaddr.h>

typedef int socklen_t;
# define __socklen_t_defined

typedef uint16_t sa_family_t;

typedef uint32_t in_addr_t;

struct in_addr
{
	in_addr_t s_addr;
};

struct sockaddr
{
	sa_family_t	sa_family;
	char    	sa_data[14];
};

struct msghdr
{
	void* msg_name;	// Optional address.
	socklen_t	msg_namelen;	// Size of address.
	struct iovec* msg_iov;	// Scatter / gather array.
	int     	msg_iovlen;	// Members in msg_iov.
	void* msg_control;	// Ancillary data; see below.
	socklen_t	msg_controllen;	// Ancillary data buffer len.
	int     	msg_flags;	// Flags on received message.
};

struct linger {
	uint16_t	l_onoff;	/* Linger active */
	uint16_t	l_linger;	/* How long to linger for */
};

struct mmsghdr
{
	struct msghdr	msghdr;
	unsigned int	msg_len;
};

struct cmsghdr
{
	socklen_t	cmsg_len;	//Data byte count, including the cmsghdr.
	int     	cmsg_level;	//Originating protocol.
	int     	cmsg_type;	//Protocol - specific type.
};

/* Structure large enough to hold any socket address (with the historical
   exception of AF_UNIX).  We reserve 128 bytes.  */
#if ULONG_MAX > 0xffffffff
# define __ss_aligntype	__uint64_t
#else
# define __ss_aligntype	__uint32_t
#endif
#define _SS_SIZE	128
#define _SS_PADSIZE	(_SS_SIZE - (2 * sizeof (__ss_aligntype)))

struct sockaddr_storage
{
	__SOCKADDR_COMMON(ss_);	/* Address family, etc.  */
	__ss_aligntype __ss_align;	/* Force desired alignment.  */
	char __ss_padding[_SS_PADSIZE];
};

/* The following constants should be used for the second parameter of
   `shutdown'.  */
enum
{
	SHUT_RD = 0,		/* No more receptions.  */
#define SHUT_RD		SHUT_RD
	SHUT_WR,		/* No more transmissions.  */
#define SHUT_WR		SHUT_WR
	SHUT_RDWR		/* No more receptions or transmissions.  */
#define SHUT_RDWR	SHUT_RDWR
};


int socket(int family, int type, int protocol);
int socketpair(int __domain, int __type, int __protocol, int __fds[2]);
int bind(int sockfd, struct sockaddr* umyaddr, int addrlen);
int setsockopt(int sockfd, int level, int option, const void* value, socklen_t value_length);
int getsockopt(int sockfd, int level, int option, void* value, socklen_t value_length);
int accept(int sockfd, struct sockaddr* addr, socklen_t addr_len);
int accept4(int sockfd, struct sockaddr* addr, socklen_t addr_len, int flags);
int connect(int sockfd, const struct sockaddr* uservaddr, int addrlen);
int listen(int sockfd, int backlog);
int shutdown(int sockfd, int how);

int getsockname(int sockfd, struct sockaddr* usockaddr, int* usockaddr_len);
int getpeername(int sockfd, struct sockaddr* usockaddr, int* usockaddr_len);

ssize_t recv(int sockfd, void* buff, size_t buff_len, int flags);
ssize_t send(int sockfd, const void* buff, size_t buff_len, int flags);
ssize_t sendto(int sockfd, const void* buff, size_t buff_len, int flags, struct sockaddr* addr, socklen_t addr_len);
ssize_t recvfrom(int sockfd, void* buff, size_t buff_len, int flags, struct sockaddr* addr, socklen_t addr_len);

int recvmmsg(int sockfd, struct mmsghdr* msgs, unsigned int msg_count, int flags, const struct timespec* timeout);
ssize_t recvmsg(int sockfd, struct msghdr* msg, int flags);
int sendmmsg(int sockfd, struct mmsghdr* msgs, int msgs_count, int flags);
int sendmsg(int sockfd, struct msghdr* msg, int flags);

#endif /* SYS_SOCKET_H */
