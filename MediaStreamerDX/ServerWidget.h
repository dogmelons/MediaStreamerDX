/*===========================================
Client GUI for AudioDX The Best
Author: Kyle Easterling
Date: Today
===========================================*/

#pragma once

#include "QtWidgets\qmainwindow.h"
#include "ui_ServerWidget.h"

class ServerWidget : public QWidget, public Ui::ServerWidget
{
	Q_OBJECT

public:
	ServerWidget(QMainWindow* parent = 0);
	~ServerWidget();

private slots:
	void toggleStreaming();
};