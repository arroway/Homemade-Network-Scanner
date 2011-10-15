#ifndef __SNIFF_H__
#define __SNIFF_H__

#include <pcap.h>
#include <dnet.h>


/* Structure with the information about a host*/
struct host {
	struct host *next;
	eth_addr_t	mac_addr;	/* MAC address of the host*/
	ip_addr_t	ip_addr;		/* IP address */
					/* Host name */
};

typedef struct host* lhosts; 

/* List containing the data about the machines on the network */

void handle_packet(u_char *, const struct pcap_pkthdr *, const u_char * );

#endif
