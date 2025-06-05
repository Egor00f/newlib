#ifndef __NETDB_H__
#define __NETDB_H__

#include <stdint.h>

struct	hostent
{
	char* h_name;	// Official name of the host.
	char** h_aliases;	// A pointer to an array of pointers to alternative host names, terminated by a null pointer.
	int	h_addrtype;	// Address type.
	int	h_length;	// The length, in bytes, of the address.
	char** h_addr_list;	// A pointer to an array of pointers to network addresses(in network byte order) for the host, terminated by a null pointer.
};

struct netent
{
	char* n_name;	// Official, fully - qualified(including the domain) name of the host.
	char** n_aliases;	// A pointer to an array of pointers to alternative network names, terminated by a null pointer.
	int	n_addrtype;	// The address type of the network.
	uint32_t	n_net;	// The network number, in host byte order.
};

struct protoent
{
	char* p_name;	// Official name of the protocol.
	char** p_aliases;	// A pointer to an array of pointers to alternative protocol names, terminated by a null pointer.
	int	p_proto;	// The protocol number.
};

struct servent
{
	char* s_name;	// Official name of the service.
	char** s_aliases;	// A pointer to an array of pointers to alternative service names, terminated by a null pointer.
	int	s_port;	// A value which, when converted to uint16_t, yields the port number in network byte order at which the service resides.
	char* s_proto;	// The name of the protocol to use when contacting the service.
};


struct rpcent
{
	char* r_name;		/* Name of server for this rpc program.  */
	char** r_aliases;	/* Alias list.  */
	int r_number;		/* RPC program number.  */
};

/* Absolute file name for network data base files.  */
#define	_PATH_HEQUIV		"/sys/etc/hosts.equiv"
#define	_PATH_HOSTS		"/sys/etc/hosts"
#define	_PATH_NETWORKS		"/sys/etc/networks"
#define	_PATH_NSSWITCH_CONF	"/sys/etc/nsswitch.conf"
#define	_PATH_PROTOCOLS		"/sys/etc/protocols"
#define	_PATH_SERVICES		"/sys/etc/services"

#define	NETDB_INTERNAL	-1	/* See errno.  */
#define	NETDB_SUCCESS	0	/* No problem.  */
#define	HOST_NOT_FOUND	1	/* Authoritative Answer Host not found.  */
#define	TRY_AGAIN	2	/* Non-Authoritative Host not found,
				   or SERVERFAIL.  */
#define	NO_RECOVERY	3	/* Non recoverable errors, FORMERR, REFUSED,
				   NOTIMP.  */
#define	NO_DATA		4	/* Valid name, no data record of requested
				   type.  */
#define	NO_ADDRESS	NO_DATA	/* No address, look for MX record.  */


void	endhostent(void);
void	endnetent(void);
void	endprotoent(void);
void	endservent(void);
void	endrpcent(void);
struct hostent* gethostbyaddr(const char*, int, int);
struct hostent* gethostbyname(const char*);
struct hostent* gethostent(void);
struct netent* getnetbyaddr(long, int); /* u_long? */
struct netent* getnetbyname(const char*);
struct netent* getnetent(void);
struct protoent* getprotobyname(const char*);
struct protoent* getprotobynumber(int);
struct protoent* getprotoent(void);
struct servent* getservbyname(const char*, const char*);
struct servent* getservbyport(int, const char*);
struct servent* getservent(void);
struct rpcent* getrpcbyname(const char* __name);
struct rpcent* getrpcbynumber(int __number);
struct rpcent* getrpcent(void);
const char* hstrerror(int);
void	herror(const char*);
void	sethostent(int);
void	setnetent(int);
void	setprotoent(int);
void	setservent(int);
void	setrpcent(int);
int		rcmd(char**, unsigned short, const char*, const char*, const char*, int*);
int		rexec(char**, unsigned short, char*, char*, char*, int*);
int		rresvport(int*);

#endif // __NETDB_H__
