#include "Window.h"
#include <QLabel>
#include <QTreeWidgetItem>

const char *machines[] = {"machine1", "machine2", "machine3"};

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

