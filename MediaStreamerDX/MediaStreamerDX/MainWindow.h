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

	QMainWindow*    m_window;
	QMainWindow*	m_clientWindow;
	QMainWindow*	m_serverWindow;

	MainWidget*		m_mainWidget;
	ServerWidget*	m_serverWidget;
	ClientWidget*	m_clientWidget;

	QMenuBar*		m_menuBar;
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
	QLabel*			m_title;
	QPushButton*	m_activateClientButton;
	QPushButton*	m_activateServerButton;
	QVBoxLayout*	m_mainLayout;
	QHBoxLayout*	m_titleLayout;
	QHBoxLayout*	m_buttonLayout;
};