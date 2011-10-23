#ifndef __SNIFF_H__
#define __SNIFF_H__

#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>


/* Structure with the information about a host */

struct host{
	struct host *next;
	//When they are more data, we may create some structures
	//instead for each level
 	u_char			mac_addr[ETHER_ADDR_LEN];	/* MAC address of the host*/
	struct ip		ip_hdr;		/* IP header */
};

struct ll_hosts{
	struct host *ptr_start;
	struct host *ptr_cur;
};

/* Functions to manage linked lists*/
struct ll_hosts *ll_new(void);
int ll_browse_ether(struct ll_hosts *, void *);

void handle_packet(u_char *, const struct pcap_pkthdr *, const u_char * );
void handle_ether(struct ll_hosts *hosts, struct ether_header *e_hdr);

void print_mac_address(u_char *);
#endif
