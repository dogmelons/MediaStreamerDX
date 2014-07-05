/*===========================================
Client GUI for AudioDX The Best
Author: Kyle Easterling
Date: Today
===========================================*/

#pragma once

#include "QtWidgets\qmainwindow.h"
#include "ui_ClientWidget.h"

class ClientWidget : public QWidget, public Ui::ClientWidget
{
	Q_OBJECT

public:
	ClientWidget(QMainWindow* parent = 0);
	~ClientWidget();

private slots:
	void toggleStreaming();
};