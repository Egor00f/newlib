#ifndef _ARPA_INET_H
#define	_ARPA_INET_H	1

#include <netinet/in.h>
#include <kolibri_network.h>

#ifndef __socklen_t_defined
typedef int socklen_t;
# define __socklen_t_defined
#endif

__BEGIN_DECLS


/* Return the local host address part of the Internet address in IN.  */
in_addr_t inet_lnaof(struct in_addr __in) __THROW;

/* Make Internet host address in network byte order by combining the
   network number NET with the local address HOST.  */
struct in_addr inet_makeaddr(in_addr_t __net, in_addr_t __host) __THROW;

/* Return network number part of the Internet address IN.  */
in_addr_t inet_netof(struct in_addr __in) __THROW;

/* Extract the network number in network byte order from the address
   in numbers-and-dots natation starting at CP.  */
in_addr_t inet_network(const char* __cp) __THROW;

/* Convert from presentation format of an Internet number in buffer
   starting at CP to the binary network format and store result for
   interface type AF in buffer starting at BUF.  */
int inet_pton(int __af, const char* __restrict __cp, void* __restrict __buf) __THROW;

/* Convert a Internet address in binary network format for interface
   type AF in buffer starting at CP to presentation form and place
   result in buffer of length LEN astarting at BUF.  */
const char* inet_ntop(int __af, const void* __restrict __cp, char* __restrict __buf, socklen_t __len) __THROW;

__END_DECLS

#ifndef _ISOMAC
/* Declare functions with security checks.
   This needs to be included unconditionally as these definition are needed even
   when fortification is disabled in inet/arpa/inet.h.  */
#include <bits/inet-fortified-decl.h>

#endif
#endif