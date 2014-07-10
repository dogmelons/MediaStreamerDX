/*===========================================
Client GUI for AudioDX The Best
Author: Kyle Easterling
Date: Today
===========================================*/

#include "ClientWidget.h"

ClientWidget::ClientWidget(QMainWindow* parent) : QWidget(parent)
{
	setupUi(this);
	IPLineEdit->setInputMask("000.000.000.000;_");
	connect(playButton, SIGNAL(clicked()), this, SLOT(toggleStreaming()));
	connect(stopButton, SIGNAL(clicked()), this, SLOT(toggleStreaming()));
}

ClientWidget::~ClientWidget()
{

}

void ClientWidget::toggleStreaming()
{
	bool isPlaying = playButton->isEnabled();
	playButton->setEnabled(!isPlaying);
	stopButton->setEnabled(isPlaying);
}