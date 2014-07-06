/*===========================================
Main GUI for AudioDX The Best
Author: Kyle Easterling
Date: Today
===========================================*/

#pragma once

#include <QtWidgets/qapplication.h>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlineedit.h>
#include "ServerWidget.h"
#include "ClientWidget.h"

class MainWidget;
class QLabel;
class QHBoxLayout;
class QVBoxLayout;

class MainWindow : public QApplication
{
	Q_OBJECT

public:
	MainWindow(int argc, char* argv[]);
	~MainWindow();

public slots:
	void			activateServer();
	void			activateClient();

private:
	bool            init();

	QMainWindow*    m_window = nullptr;
	QMainWindow*	m_clientWindow = nullptr;
	QMainWindow*	m_serverWindow = nullptr;

	MainWidget*		m_mainWidget = nullptr;
	ServerWidget*	m_serverWidget = nullptr;
	ClientWidget*	m_clientWidget = nullptr;

	QMenuBar*		m_menuBar = nullptr;
};


//widget that occupies the central widget slot of Main Window
class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QMainWindow* parent = 0);
	~MainWidget();

signals:
	void activateClientSignal();
	void activateServerSignal();

protected slots:
	void activateClient();
	void activateServer();

private:
	QLabel*			m_title	= nullptr;
	QPushButton*	m_activateClientButton = nullptr;
	QPushButton*	m_activateServerButton = nullptr;
	QVBoxLayout*	m_mainLayout = nullptr;
	QHBoxLayout*	m_titleLayout = nullptr;
	QHBoxLayout*	m_buttonLayout = nullptr;
};