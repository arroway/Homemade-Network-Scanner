#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "sniff.h"

struct ll_hosts *ll_new(void){
	
	struct ll_hosts *hosts = malloc(sizeof(struct ll_hosts *));

	if (hosts){
		struct host *first_host = malloc(sizeof(struct host *));

		if (first_host){
			//first_host.mac_addr = NULL;
			//first_host.ip_hdr = NULL;
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
