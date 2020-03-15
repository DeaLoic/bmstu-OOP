#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

#include "error_code.h"
#include "target.h"
#include "point.h"
#include "draw.h"

errorCode DrawByTarget(QGraphicsView *drawScene, target targetToProcessing);
errorCode ParseDouble(double &result, QString targetQString);
void ShowError(errorCode error);

MainWindow::MainWindow(QWidget *parent) :
      QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    target targetInit;
    FormTargetInit(targetInit);

    DrawByTarget(ui->paintArea, targetInit);
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
    errorCode error = SUCCES;
    double moveX, moveY, moveZ;
    if (ParseDouble(moveX, ui->lineEditMoveX->text()) != SUCCES ||
        ParseDouble(moveY, ui->lineEditMoveY->text()) != SUCCES ||
        ParseDouble(moveZ, ui->lineEditMoveZ->text()) != SUCCES)
    {
        error = PARSE_ERROR;
    }
    else
    {
        target targetMove;
        FormTargetMove(targetMove, moveX, moveY, moveZ);

        error = DrawByTarget(ui->paintArea, targetMove);
    }
    
    if (error != SUCCES)
    {
        ShowError(error);
    }
}

void MainWindow::on_buttonRotate_released()
{
    errorCode error = SUCCES;
    double rotateX, rotateY, rotateZ;
    if (ParseDouble(rotateX, ui->lineEditRotateX->text()) != SUCCES ||
        ParseDouble(rotateY, ui->lineEditRotateY->text()) != SUCCES ||
        ParseDouble(rotateZ, ui->lineEditRotateZ->text()) != SUCCES)
    {
        error = PARSE_ERROR;
    }
    else
    {
        target targetRotate;
        FormTargetRotate(targetRotate, rotateX, rotateY, rotateZ);

        error = DrawByTarget(ui->paintArea, targetRotate);
    }
    
    if (error != SUCCES)
    {
        ShowError(error);
    }
}

void MainWindow::on_buttonScale_released()
{
    errorCode error = SUCCES;
    double scaleX, scaleY, scaleZ;
    if (ParseDouble(scaleX, ui->lineEditScaleX->text()) != SUCCES ||
        ParseDouble(scaleY, ui->lineEditScaleY->text()) != SUCCES ||
        ParseDouble(scaleZ, ui->lineEditScaleZ->text()) != SUCCES)
    {
        error = PARSE_ERROR;
    }
    else
    {
        target targetScale;
        FormTargetScale(targetScale, scaleX, scaleY, scaleZ);

        error = DrawByTarget(ui->paintArea, targetScale);
    }
    
    if (error != SUCCES)
    {
        ShowError(error);
    }
}

void MainWindow::on_actionOpen_triggered()
{

}

errorCode DrawByTarget(QGraphicsView *drawArea, target targetToProcessing)
{
    errorCode error = TargetProcessing(targetToProcessing);

    if (error == SUCCES)
    {
        draw drawSetup;
        formDraw(drawSetup, drawArea);

        target targetDraw;
        formTargetDraw(targetDraw, drawSetup);

        error = targetProcessing(targetDraw);
    }

    return error;
}