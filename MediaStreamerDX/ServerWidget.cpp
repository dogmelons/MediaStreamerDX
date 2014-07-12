/*===========================================
Client GUI for AudioDX The Best
Author: Kyle Easterling
Date: Today
===========================================*/

#include "ServerWidget.h"

ServerWidget::ServerWidget(QMainWindow* parent) : QWidget(parent)
{
	setupUi(this);
	connect(playButton, SIGNAL(clicked()), this, SLOT(toggleStreaming()));
	connect(stopButton, SIGNAL(clicked()), this, SLOT(toggleStreaming()));
}

ServerWidget::~ServerWidget()
{

}

void ServerWidget::toggleStreaming()
{
	bool isPlaying = playButton->isEnabled();
	playButton->setEnabled(!isPlaying);
	stopButton->setEnabled(isPlaying);
}