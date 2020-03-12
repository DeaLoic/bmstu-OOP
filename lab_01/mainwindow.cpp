#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

#include "error_code.h"
#include "target.h"
#include "point.h"
#include "draw.h"

errorCode Draw(QGraphicsView *drawScene, QPen pen);

MainWindow::MainWindow(QWidget *parent) :
      QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    target targetInit;
    FormTargetInit(targetInit);
    TargetProcessing(targetInit);

    QPen blackPen(QColor(0, 0, 0));
    Draw(ui->paintArea, blackPen);
}

MainWindow::~MainWindow()
{
    delete ui;

    target targetDelete;
    FormTargetDestruct(targetDelete);
    TargetProcessing(targetDelete);
}

void MainWindow::on_buttonMove_released()
{
    double moveX = ui->lineEditMoveX->text().toDouble();
    double moveY = ui->lineEditMoveY->text().toDouble();
    double moveZ = ui->lineEditMoveZ->text().toDouble();

    target targetMove;
    FormTargetMove(targetMove, moveX, moveY, moveZ);
    TargetProcessing(targetMove);

    QPen blackPen(QColor(0, 0, 0));
    Draw(ui->paintArea, blackPen);
}

void MainWindow::on_buttonRotate_released()
{
    double rotateX = ui->lineEditRotateX->text().toDouble();
    double rotateY = ui->lineEditRotateY->text().toDouble();
    double rotateZ = ui->lineEditRotateZ->text().toDouble();

    target targetRotate;
    FormTargetRotate(targetRotate, rotateX, rotateY, rotateZ);
    TargetProcessing(targetRotate);

    QPen blackPen(QColor(0, 0, 0));
    Draw(ui->paintArea, blackPen);
}

void MainWindow::on_buttonScale_released()
{
    double scaleX = ui->lineEditScaleX->text().toDouble();
    double scaleY = ui->lineEditScaleY->text().toDouble();
    double scaleZ = ui->lineEditScaleZ->text().toDouble();

    target targetScale;
    FormTargetScale(targetScale, scaleX, scaleY, scaleZ);
    TargetProcessing(targetScale);

    QPen blackPen(QColor(0, 0, 0));
    Draw(ui->paintArea, blackPen);
}

void MainWindow::on_actionOpen_triggered()
{

}

errorCode Draw(QGraphicsScene *drawScene, QPen pen)
{
    draw drawSetup;
    formDraw(drawSetup, drawScene, pen);

    target targetDraw;
    formTargetDraw(targetDraw, drawSetup);

    return targetProcessing(targetDraw);
}
