#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "sniff.h"

/* Create a new linked list */
struct ll_hosts *ll_new(void){
	
	struct ll_hosts *hosts = malloc(sizeof(struct ll_hosts *));

	if (hosts){
		struct host *first_host = malloc(sizeof(struct host *));

		if (first_host){
			first_host->next = NULL;
			hosts->ptr_start = first_host;
			hosts->ptr_cur = NULL; 
		} else {
			perror("Not enough memory space\n");
			exit(EXIT_FAILURE);	
		}
	} else {
		perror("Not enough memory space\n");
		exit(EXIT_FAILURE);
	}
	return hosts;
}

/* Browse through the list if a host is already there */
int ll_browse_ether(struct ll_hosts *hosts, void *arg){
	
	struct host *tmp = hosts->ptr_start;
	
	while (tmp != NULL){
		if (memcmp(tmp->mac_addr, arg, (sizeof(u_char) * ETHER_ADDR_LEN))) 
			return(EXIT_SUCCESS);
		 else 
			tmp = tmp->next; 
	}
	return(EXIT_FAILURE);	
}
