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
	m_menuBar->addMenu(tr("File"));
	m_window->setMenuBar(m_menuBar);

	m_mainWidget = new MainWidget();
	connect(m_mainWidget, SIGNAL(activateClientSignal()), this, SLOT(activateClient()));
	connect(m_mainWidget, SIGNAL(activateServerSignal()), this, SLOT(activateServer()));

	m_window->setCentralWidget(m_mainWidget);
	m_window->setFixedSize(m_window->sizeHint());
	m_window->show();
	return true;
}

void MainWindow::activateClient()
{
	m_clientWidget = new ClientWidget();
	m_window->setCentralWidget(m_clientWidget);	//setCentralWidget orphans m_mainWidget and qt automatically destroys it.
	m_window->setFixedSize(m_window->sizeHint());
}

void MainWindow::activateServer()
{
	m_serverWidget = new ServerWidget();
	m_window->setCentralWidget(m_serverWidget);
	m_window->setFixedSize(m_window->sizeHint());
}

MainWidget::MainWidget(QMainWindow* parent) : QWidget(parent)
{
	m_mainLayout = new QVBoxLayout();
	m_titleLayout = new QHBoxLayout();
	m_buttonLayout = new QHBoxLayout();
	m_mainLayout->addLayout(m_titleLayout);
	m_mainLayout->addLayout(m_buttonLayout);

	m_title = new QLabel();
	m_title->setText(tr("Choose device role"));
	m_titleLayout->addStretch();
	m_titleLayout->addWidget(m_title);
	m_titleLayout->addStretch();

	m_activateClientButton = new QPushButton();
	m_activateClientButton->setText(tr("&Client"));

	m_activateServerButton = new QPushButton();
	m_activateServerButton->setText(tr("&Server"));

	connect(m_activateClientButton, SIGNAL(clicked()), this, SLOT(activateClient()));
	connect(m_activateServerButton, SIGNAL(clicked()), this, SLOT(activateServer()));

	m_buttonLayout->addWidget(m_activateClientButton);
	m_buttonLayout->addWidget(m_activateServerButton);

	setLayout(m_mainLayout);
}

MainWidget::~MainWidget()
{

}

void MainWidget::activateClient()
{
	emit activateClientSignal();
}

void MainWidget::activateServer()
{
	emit activateServerSignal();
}