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

private:
	bool            init();

	QMainWindow*    m_window = nullptr;
	QMainWindow*	m_clientWindow = nullptr;
	QMainWindow*	m_serverWindow = nullptr;

	ServerWidget*	m_serverWidget = nullptr;
	ClientWidget*	m_clientWidget = nullptr;

	QMenuBar*		m_menuBar = nullptr;
};