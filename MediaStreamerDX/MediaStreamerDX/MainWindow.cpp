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
	QIcon windowIcon;
	windowIcon.addFile("resources/windowIcon.png");
	m_window->setWindowIcon(windowIcon);
	m_menuBar = new QMenuBar();
	m_menuBar->addMenu(tr("File"));		//more menus/actions can be added as needed
	m_window->setMenuBar(m_menuBar);

	QTabWidget* tabWidget = new QTabWidget();
	m_clientWidget = new ClientWidget();
	m_serverWidget = new ServerWidget();

	//this is bad and I should feel bad, but QTabWidget should feel worse
	//for sucking so much and not having an option for this.
	tabWidget->addTab(m_clientWidget, "       Client      ");
	tabWidget->addTab(m_serverWidget, "       Server       ");
	tabWidget->setUsesScrollButtons(false);

	//this is also bad, but using size hint for tabWidget and m_window makes there be a little 
	//space between the right side and bottom of the tabWidget and m_window, which looks bad.
	//I could use sizeHint() and subtract a number of pixels for width and height for m_window
	//which would leave tabWidget alone, but the spaces in those shitty tabs above mean I have to
	//adjust tabWidget's pixels too because otherwise the tabs over/undershoot and look bad...fuck QTabWidget.
	tabWidget->setFixedSize(QSize(188 , 237));	
	m_window->setFixedSize(QSize(185, 236));

	m_window->setCentralWidget(tabWidget);	
	m_window->show();
	return true;
}