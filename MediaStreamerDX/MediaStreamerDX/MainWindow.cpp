/*===========================================
Main GUI for AudioDX The Best
Author: Kyle Easterling
Date: Today
===========================================*/

#include "MainWindow.h"
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets\qtabwidget.h>

MainWindow::MainWindow(int argc, char* argv[]) : QApplication(argc, argv)
{
	init();
}

MainWindow::~MainWindow()
{
	// OS will clean up everything...
}

bool MainWindow::init()
{
	m_window = new QMainWindow();
	m_menuBar = new QMenuBar();
	m_menuBar->addMenu(tr("File"));		//more menus/actions can be added as needed
	m_window->setMenuBar(m_menuBar);

	QTabWidget* tabWidget = new QTabWidget();
	m_clientWidget = new ClientWidget();
	m_serverWidget = new ServerWidget();
	tabWidget->addTab(m_clientWidget, "Client");
	tabWidget->addTab(m_serverWidget, "Server");

	m_window->setCentralWidget(tabWidget);
	m_window->show();
	return true;
}