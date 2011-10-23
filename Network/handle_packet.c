#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h> /*include net/ethernet.h*/
#include "sniff.h"

void handle_packet(u_char *user, const struct pcap_pkthdr *header, const u_char *packet){

	struct ether_header *e_hdr;
	struct ll_hosts *hosts;
	int is_new;
	int i;
 
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
			handle_ether(hosts, e_hdr);
			if (hosts->ptr_cur){
				/*for (i=0; i<ETHER_ADDR_LEN; i++){
					printf(&hosts->ptr_cur->mac_addr[i])};*/
				print_mac_address(hosts->ptr_cur->mac_addr);
				
				printf("\n");
			}
		}
		
	}  	
}

/* Handling the data from the ethernet frame */
void handle_ether(struct ll_hosts *hosts, struct ether_header *e_hdr){

	struct ll_hosts *temp;
	struct host *new_host = malloc(sizeof(struct host));

	memcpy(new_host->mac_addr, &e_hdr->ether_dhost, sizeof(u_char) * ETHER_ADDR_LEN );

	new_host->next = NULL;
	hosts->ptr_cur = new_host;

	//if (hosts == NULL){
	//	return new_host;
	//} 
	//else {
	
//	if (hosts){ 
//		temp = hosts;
//
//		while (temp->ptr_cu != NULL){
//			temp = temp->next;
//		}

//		temp->next = new_host;
	//	return hosts;		 
//	}
	//store the information for the new hosts
}

 void print_mac_address(u_char *addr) {
          int i;
          for (i = 0 ; i < ETHER_ADDR_LEN ; i++) {
                  printf("%02X", addr[i]);
                  if (i < ETHER_ADDR_LEN - 1)
                          printf(":");
          }
 }

