#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	connect(ui->pushButton_login, SIGNAL(clicked()),
		this, SLOT(slotLogin())
	);
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::slotLogin() {
	ui->lineEdit_username->setText("tralala");
}
