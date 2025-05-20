#ifndef __IF_H__
#define __IF_H__

#include <sys/types.h>
#include <sys/socket.h>

/* Length of interface name.  */
#define IF_NAMESIZE	16

struct if_nameindex
{
    unsigned int if_index;	/* 1, 2, ... */
    char* if_name;		/* null terminated name: "eth0", ... */
};


struct ifaddr
{
    struct sockaddr ifa_addr;	/* Address of interface.  */
    union
    {
        struct sockaddr	ifu_broadaddr;
        struct sockaddr	ifu_dstaddr;
    } ifa_ifu;
    struct iface* ifa_ifp;	/* Back-pointer to interface.  */
    struct ifaddr* ifa_next;	/* Next address for interface.  */
};

struct ifreq
{
#define IFNAMSIZ        16
#define IFHWADDRLEN     6
    union
    {
        char    ifrn_name[IFNAMSIZ];            /* if name, e.g. "en0" */
    } ifr_ifrn;

    union {
        struct  sockaddr ifru_addr;
        struct  sockaddr ifru_broadaddr;
        struct  sockaddr ifru_netmask;
        struct  sockaddr ifru_hwaddr;
        short   ifru_flags;
        int     ifru_metric;
        int     ifru_mtu;
    } ifr_ifru;
};

#define ifr_name        ifr_ifrn.ifrn_name      /* interface name       */
#define ifr_addr        ifr_ifru.ifru_addr      /* address              */
#define ifr_broadaddr   ifr_ifru.ifru_broadaddr /* broadcast address    */
#define ifr_netmask     ifr_ifru.ifru_netmask   /* interface net mask   */
#define ifr_flags       ifr_ifru.ifru_flags     /* flags                */
#define ifr_hwaddr      ifr_ifru.ifru_hwaddr    /* MAC address          */
#define ifr_metric      ifr_ifru.ifru_metric    /* metric               */
#define ifr_mtu         ifr_ifru.ifru_mtu       /* mtu                  */


/*
 * Structure used in SIOCGIFCONF request.
 * Used to retrieve interface configuration
 * for machine (useful for programs which
 * must know all networks accessible).
 */

struct ifconf
{
    int     ifc_len;                        /* size of buffer       */
    union
    {
        caddr_t ifcu_buf;
        struct  ifreq* ifcu_req;
    } ifc_ifcu;
};


#endif // __IF_H__