#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
      QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonMove_released()
{
    QMessageBox q;
    q.setText("Hello world");
    q.exec();
}

void MainWindow::on_buttonRotate_released()
{
    QMessageBox q;
    q.setText("Rotate world");
    q.exec();
}

void MainWindow::on_buttonScale_released()
{
    QMessageBox q;
    q.setText("ZooM world");
    q.exec();
}

void MainWindow::on_actionOpen_triggered()
{
    QMessageBox q;
    q.setText("Open world");
    q.exec();
}
