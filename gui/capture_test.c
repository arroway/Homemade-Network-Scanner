/*
 *  This is a fake capture source file
 *  It allows to test the GUI while developping it
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern int pipe_fd[2];
#define READ_PIPE       0
#define WRITE_PIPE      1

void *capture_thread(void *arg) {
	ssize_t size;
	int index = 0;

	printf("Test capture thread : RUNNING...\n");

	/* sending a few integers to GUI */
	for ( ; index < 4 ; ++index) {
		size = write(pipe_fd[WRITE_PIPE], &index, sizeof(index));

		if (size == 0) {
			printf("capture_thread: wrote nothing, maybe pipe is full\n");
			exit(1);
		} else if (size == -1) {
			perror("capture_thread:");
			exit(1);
		} else {
			printf("capture_thread: integer %d written to pipe\n", index);
		}
	}

	return NULL;
}
