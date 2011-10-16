#include <QApplication>
#include "Window.h"
#include <fcntl.h>

extern "C" void capture(void);
 
#define READ_PIPE       0
#define WRITE_PIPE      1

int pipe_fd[2];

int main(int argc, char *argv[])
{
	int ret;

	QApplication app(argc, argv);

	ret = pipe(pipe_fd);
	if (ret != 0) {
		perror("pipe:");
		exit(1);
	}

	ret = fcntl(pipe_fd[WRITE_PIPE], F_SETFL, O_NONBLOCK);

	if (ret == -1) {
		perror("fcntl F_SETFL O_NONBLOCK pipe_fd[WRITE_PIPE]:");
		exit(1);
	}


	Window win;
	win.show();
 
	return app.exec();
}

