#include <stdio.h>
#include <pcap.h>
#include <dnet.h>
#include "sniff.h"

void handle_packet(u_char *user, const struct pcap_pkthdr *header, const u_char *packet){
	
	printf("Got a packet with length of [%d]\n", header->len);
        lhosts->mac_addr = packet;
	
	return;
}
