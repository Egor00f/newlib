#ifndef __SOCKET_PARAMS_H__
#define __SOCKET_PARAMS_H__

#include <bits/socket_type.h>

// Socket Types
#define SOCK_STREAM 1
#define SOCK_DGRAM  2
#define SOCK_RAW    3

// IP protocols
#define IPPROTO_IP  	0
#define IPPROTO_ICMP	1
#define IPPROTO_TCP 	6
#define IPPROTO_UDP 	17
#define IPPROTO_RAW 	255

// IP options
#define IP_TTL 2

// Address families
#define AF_UNSPEC	0
#define AF_LOCAL	1
#define AF_INET4	2       	// IPv4
#define AF_INET6	10	        // IPv6
#define AF_INET 	AF_INET4	// Default INET=IPv4
#define AF_UNIX 	AF_LOCAL

#define PF_UNSPEC	AF_UNSPEC
#define PF_LOCAL	AF_LOCAL
#define PF_INET4	AF_INET4
#define PF_INET6	AF_INET6
#define PF_INET     PF_INET4

// internal definition
#define AI_SUPPORTED 0x40F

// Socket flags for user calls
#define MSG_NOFLAG  	0
#define MSG_PEEK    	0x02
#define MSG_DONTWAIT	0x40

// Socket levels
#define SOL_SOCKET 0xffff

// Socket options
#define SO_BINDTODEVICE	(1 << 9)
#define SO_NONBLOCK 	(1 << 31)

#define IP_OPTIONS				   1
#define SO_DEBUG				   1
#define SO_ACCEPTCONN				   2
#define SO_REUSEADDR				   4
#define SO_KEEPALIVE				   8
#define SO_DONTROUTE				  16
#define SO_BROADCAST				  32
#define SO_USELOOPBACK				  64
#define SO_LINGER				 128
#define SO_OOBINLINE				 256

#define SO_DONTLINGER			 (u_int)(~SO_LINGER)

#define SO_SNDBUF			      0x1001
#define SO_RCVBUF			      0x1002
#define SO_SNDLOWAT			      0x1003
#define SO_RCVLOWAT			      0x1004
#define SO_SNDTIMEO			      0x1005
#define SO_RCVTIMEO			      0x1006
#define SO_ERROR			      0x1007
#define SO_TYPE 			      0x1008



#endif // __SOCKET_PARAMS_H__