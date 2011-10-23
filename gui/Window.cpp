#include "Window.h"
#include <QLabel>
#include <QTreeWidgetItem>

const char *machines[] = {"machine1", "machine2", "machine3"};

#define READ_PIPE       0
#define WRITE_PIPE      1

/* This is the listener thread */
void *Window::listener(void *obj)
{
	Window *win = (Window *)obj;
	printf("Listener thread : RUNNING...\n");
	ssize_t new_size;
	ssize_t size;
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
	}

	return obj;
}

void Window::addMachine(int num)
{
	
}
 
Window::Window() : QWidget()
{
    setFixedSize(300, 150);
 
    // Construction du QTreeWidget
    m_tree = new QTreeWidget(this);

    QTreeWidgetItem *test = new QTreeWidgetItem(m_tree, 0);
    test->setText(0, "machine1");
    QTreeWidgetItem *test2 = new QTreeWidgetItem(m_tree, 0);
    test2->setText(0, "machine2");

    m_tree->setColumnCount(1);
    m_tree->setHeaderLabel("Liste des machines : ");
    m_tree->show();
}

