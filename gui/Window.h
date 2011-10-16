#include <QApplication>
#include <QWidget>
#include <QTreeWidget>

class Window : public QWidget
{

public:
	Window();
	void addMachine(int num);

private:
	QTreeWidget *m_tree;

};
