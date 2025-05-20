#ifndef _NETINET_IN_H
#define _NETINET_IN_H	1


#include <asm/byteorder.h>
#include <sys/socket.h>

typedef uint16_t in_port_t;

#define	IN_CLASSA(a)		((((in_addr_t)(a)) & 0x80000000) == 0)
#define	IN_CLASSA_NET		0xff000000
#define	IN_CLASSA_NSHIFT	24
#define	IN_CLASSA_HOST		(0xffffffff & ~IN_CLASSA_NET)
#define	IN_CLASSA_MAX		128

#define	IN_CLASSB(a)		((((in_addr_t)(a)) & 0xc0000000) == 0x80000000)
#define	IN_CLASSB_NET		0xffff0000
#define	IN_CLASSB_NSHIFT	16
#define	IN_CLASSB_HOST		(0xffffffff & ~IN_CLASSB_NET)
#define	IN_CLASSB_MAX		65536

#define	IN_CLASSC(a)		((((in_addr_t)(a)) & 0xe0000000) == 0xc0000000)
#define	IN_CLASSC_NET		0xffffff00
#define	IN_CLASSC_NSHIFT	8
#define	IN_CLASSC_HOST		(0xffffffff & ~IN_CLASSC_NET)

#define	IN_CLASSD(a)		((((in_addr_t)(a)) & 0xf0000000) == 0xe0000000)
#define	IN_MULTICAST(a)		IN_CLASSD(a)

#define	IN_EXPERIMENTAL(a)	((((in_addr_t)(a)) & 0xe0000000) == 0xe0000000)
#define	IN_BADCLASS(a)		((((in_addr_t)(a)) & 0xf0000000) == 0xf0000000)

/* Address to accept any incoming messages.  */
#define	INADDR_ANY		((in_addr_t) 0x00000000)
/* Address to send to all hosts.  */
#define	INADDR_BROADCAST	((in_addr_t) 0xffffffff)
/* Address indicating an error return.  */
#define	INADDR_NONE		((in_addr_t) 0xffffffff)
/* Dummy address for source of ICMPv6 errors converted to IPv4 (RFC
   7600).  */
#define	INADDR_DUMMY		((in_addr_t) 0xc0000008)

   /* Network number for local host loopback.  */
#define	IN_LOOPBACKNET		127
/* Address to loopback in software to local host.  */
#ifndef INADDR_LOOPBACK
# define INADDR_LOOPBACK	((in_addr_t) 0x7f000001) /* Inet 127.0.0.1.  */
#endif

/* Defines for Multicast INADDR.  */
#define INADDR_UNSPEC_GROUP	((in_addr_t) 0xe0000000) /* 224.0.0.0 */
#define INADDR_ALLHOSTS_GROUP	((in_addr_t) 0xe0000001) /* 224.0.0.1 */
#define INADDR_ALLRTRS_GROUP    ((in_addr_t) 0xe0000002) /* 224.0.0.2 */
#define INADDR_ALLSNOOPERS_GROUP ((in_addr_t) 0xe000006a) /* 224.0.0.106 */
#define INADDR_MAX_LOCAL_GROUP  ((in_addr_t) 0xe00000ff) /* 224.0.0.255 */

/* IPv6 address */
struct in6_addr
{
   union
   {
      uint8_t	u6_addr8[16];
      uint16_t u6_addr16[8];
      uint32_t u6_addr32[4];
   } in6_u;
#define s6_addr			in6_u.u6_addr8
#define s6_addr16		in6_u.u6_addr16
#define s6_addr32		in6_u.u6_addr32
};

extern const struct in6_addr in6addr_any;        /* :: */
extern const struct in6_addr in6addr_loopback;   /* ::1 */
#define IN6ADDR_ANY_INIT { { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } } }
#define IN6ADDR_LOOPBACK_INIT { { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 } } }

#define INET_ADDRSTRLEN 16
#define INET6_ADDRSTRLEN 46

/* Get the definition of the macro to define the common sockaddr members.  */
#include <bits/socket.h>


#if 1 /* defined __UCLIBC_HAS_IPV4__ */
/* Structure describing an Internet socket address.  */
struct sockaddr_in
{
   __SOCKADDR_COMMON(sin_);
   in_port_t sin_port;			/* Port number.  */
   struct in_addr sin_addr;		/* Internet address.  */

   /* Pad to size of `struct sockaddr'.  */
   unsigned char sin_zero[sizeof(struct sockaddr) - __SOCKADDR_COMMON_SIZE - sizeof(in_port_t) - sizeof(struct in_addr)];
};
#endif

/* Ditto, for IPv6.  */
struct sockaddr_in6
{
   __SOCKADDR_COMMON(sin6_);
   in_port_t sin6_port;	/* Transport layer port # */
   uint32_t sin6_flowinfo;	/* IPv6 flow information */
   struct in6_addr sin6_addr;	/* IPv6 address */
   uint32_t sin6_scope_id;	/* IPv6 scope-id */
};


/* IPv4 multicast request.  */
struct ip_mreq
{
   /* IP multicast address of group.  */
   struct in_addr imr_multiaddr;

   /* Local IP address of interface.  */
   struct in_addr imr_interface;
};

struct ip_mreq_source
{
   /* IP multicast address of group.  */
   struct in_addr imr_multiaddr;

   /* IP address of source.  */
   struct in_addr imr_interface;

   /* IP address of interface.  */
   struct in_addr imr_sourceaddr;
};

/* Likewise, for IPv6.  */
struct ipv6_mreq
{
   /* IPv6 multicast address of group */
   struct in6_addr ipv6mr_multiaddr;

   /* local interface */
   unsigned int ipv6mr_interface;
};


/* Multicast group request.  */
struct group_req
{
   /* Interface index.  */
   uint32_t gr_interface;

   /* Group address.  */
   struct sockaddr_storage gr_group;
};

struct group_source_req
{
   /* Interface index.  */
   uint32_t gsr_interface;

   /* Group address.  */
   struct sockaddr_storage gsr_group;

   /* Source address.  */
   struct sockaddr_storage gsr_source;
};


/* Full-state filter operations.  */
struct ip_msfilter
{
   /* IP multicast address of group.  */
   struct in_addr imsf_multiaddr;

   /* Local IP address of interface.  */
   struct in_addr imsf_interface;

   /* Filter mode.  */
   uint32_t imsf_fmode;

   /* Number of source addresses.  */
   uint32_t imsf_numsrc;
   /* Source addresses.  */
   struct in_addr imsf_slist[1];
};

#define IP_MSFILTER_SIZE(numsrc) (sizeof (struct ip_msfilter) \
				  - sizeof (struct in_addr)		      \
				  + (numsrc) * sizeof (struct in_addr))

struct group_filter
{
   /* Interface index.  */
   uint32_t gf_interface;

   /* Group address.  */
   struct sockaddr_storage gf_group;

   /* Filter mode.  */
   uint32_t gf_fmode;

   /* Number of source addresses.  */
   uint32_t gf_numsrc;
   /* Source addresses.  */
   struct sockaddr_storage gf_slist[1];
};

#define GROUP_FILTER_SIZE(numsrc) ( sizeof (struct group_filter) - sizeof (struct sockaddr_storage) + ( (numsrc) * sizeof (struct sockaddr_storage) ) )

#endif // _NETINET_IN_H
