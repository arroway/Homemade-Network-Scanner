#include <QApplication>
#include <QWidget>
#include <QTreeWidget>

class Window : public QWidget
{

public:
	Window();
	void addMachine(int num);
	static void *listener(void *);
	int *pipe_fd;

private:
	QTreeWidget *m_tree;
};
