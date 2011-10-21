#include <stdio.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h> /*include net/ethernet.h*/
#include "sniff.h"

void handle_packet(u_char *user, const struct pcap_pkthdr *header, const u_char *packet){

	struct ether_header *e_hdr;
	struct ll_hosts *hosts;
	int is_new;
 
	printf("Got a packet with length of [%d]\n", header->len);

	/* Create the linked list for each new host detected on the network */

	hosts = ll_new();

	/* Getting ethernet header */
        e_hdr = (struct ether_header *) packet;
	
	/* Testing what type of packet we have 
	 * IP or ARP Protocoles
	 * if not, we don't care of the packet
	 * - Don't forget that bytes order differs between network & host */
	
	if ((ntohs(e_hdr->ether_type) == ETHERTYPE_IP ) || 
	    (ntohs(e_hdr->ether_type) == ETHERTYPE_ARP)){

		printf("under test\n");
		is_new = !(ll_browse_ether(hosts, &e_hdr->ether_dhost));

		if (is_new){
			printf("new host\n");
			//void handle_ether();
		}
		
	}  	
}

/* Handling the data from the ethernet frame */
/*int handle_ether(struct ether_header *e_hdr){

	//store the information for the new hosts
}

*/
