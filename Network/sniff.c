#include <stdio.h>
#include <pcap.h>
#include <dnet.h>

#include "sniff.h"

int main(int argc, char *argv[])
{
	/* Setting up the device we want to sniff on */
	char errbuf[PCAP_ERRBUF_SIZE];	/* Error string from pcap */
	char *dev; 			/* The device to sniff on: en0, eth0... */
	bpf_u_int32 mask; 		/* Our netmask */
	bpf_u_int32 net; 		/* Our IP*/
	pcap_t *handle;			/* Session handle */
	struct pcap_pkthdr header;	/* The header that pcap gives us */
	const u_char *packet;		/* The actual packet */

	/* Define the device */
	//dev = pcap_lookupdev(errbuf);
	dev = argv[1];
	if (dev == NULL){
		fprintf(stderr, "Coulndt' find default device: %s\n", errbuf);
		return(1);
	}
	printf("Device= %s\n", dev);

	/* Find the properties for the device */
	if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1){
		fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
		net = 0;
		mask = 0;
	}
	fprintf(stderr, "net: %d - mask: %d\n", net, mask);
	
	/* Open the device for sniffing
	*  Promiscuous mode activated */
	handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
	if (handle == NULL){
		fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
		return(1);
	}
	
	fprintf(stderr, "handle got value\n" );
	pcap_loop(handle, -1, handle_packet, NULL);	

	/* Close the session */
	pcap_close(handle);
	return(0);
}
