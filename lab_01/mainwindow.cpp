#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

#include "error_code.h"
#include "target.h"

errorCode Draw();

MainWindow::MainWindow(QWidget *parent) :
      QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    target targetInit;
    formTargetInit(targetInit);
    TargetProcessing(targetInit);
    Draw();

}

MainWindow::~MainWindow()
{
    delete ui;

    target targetDelete;
    FormTargetDelete(targetDelete);
    TargetProcessing(targetDelete);
}

void MainWindow::on_buttonMove_released()
{
    QMessageBox q;
    q.setText("Hello world");
    q.exec();

    float moveX = ui->lineEditMoveX->text().toFloat();
    float moveY = ui->lineEditMoveY->text().toFloat();
    float moveZ = ui->lineEditMoveZ->text().toFloat();

    target targetMove;
    FormTargetMove(targetMove, moveX, moveY, moveZ);
    TargetProcessing(targetMove);
    Draw();
}

void MainWindow::on_buttonRotate_released()
{
    QMessageBox q;
    q.setText("Rotate world");
    q.exec();

    float rotateX = ui->lineEditRotateX->text().toFloat();
    float rotateY = ui->lineEditRotateY->text().toFloat();
    float rotateZ = ui->lineEditRotateZ->text().toFloat();

    target targetRotate;
    FormTargetRotate(targetRotate, rotateX, rotateY, rotateZ);
    TargetProcessing(targetRotate);
    Draw();
}

void MainWindow::on_buttonScale_released()
{
    QMessageBox q;
    q.setText("ZooM world");
    q.exec();

    float scaleX = ui->lineEditScaleX->text().toFloat();
    float scaleY = ui->lineEditScaleY->text().toFloat();
    float scaleZ = ui->lineEditScaleZ->text().toFloat();

    target targetScale;
    FormTargetScale(targetScale, scaleX, scaleY, scaleZ);
    TargetProcessing(targetScale);
    Draw();
}

void MainWindow::on_actionOpen_triggered()
{
    QMessageBox q;
    q.setText("Open world");
    q.exec();
}

errorCode Draw()
{
    draw drawArea;
    formDraw(drawArea);

    target targetDraw;
    formTargetDraw(targetDraw, drawArea);

    return targetProcessing(targetDraw);
}
