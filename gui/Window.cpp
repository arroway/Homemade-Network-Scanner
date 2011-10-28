#include "Window.h"
#include <QLabel>
#include <QTreeWidgetItem>

const char *machines[] = {"machine0", "machine1", "machine2", "machine3"};

#define READ_PIPE       0
#define WRITE_PIPE      1

/* This is the listener thread */
void *Window::listener(void *obj)
{
	Window *win = (Window *)obj;
	printf("Listener thread : RUNNING...\n");
	ssize_t new_size;
	size_t size;
	int integer;
	
	while (1) {
		size = 0;
		do {
			new_size = read(win->pipe_fd[READ_PIPE], &integer, sizeof(integer));

			if (new_size == 0) {
				printf("End of file\n");
				exit(1);
			} else if (new_size == -1) {
				perror("read from pipe:");
				exit(1);
			}
			size += new_size;
		} while (size < sizeof(integer));

		printf("listener_thread: integer %d read from pipe\n", integer);
		win->addMachine(integer);
	}

	return obj;
}

void Window::addMachine(int num)
{
	if (num < 4 && num >= 0) {
		QTreeWidgetItem *new_machine = new QTreeWidgetItem(m_tree, 0);
		QString name(machines[num]);
		new_machine->setText(0, name);
		printf("adding machine number %d (%s) to machine list\n", num, machines[num]);
	}
}
 
Window::Window() : QWidget()
{
    setFixedSize(300, 150);
 
    // Construction du QTreeWidget
    m_tree = new QTreeWidget(this);

    m_tree->setColumnCount(1);
    m_tree->setHeaderLabel("Liste des machines : ");
    m_tree->show();
}

