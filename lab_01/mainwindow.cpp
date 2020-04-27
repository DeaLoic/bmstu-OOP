#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

#include "error_code.h"
#include "target.h"
#include "point.h"
#include "draw.h"

errorCode DrawByTarget(target &targetToProcessing, Ui::MainWindow* ui);
errorCode ParseDouble(double &result, QString targetQString);
void ShowError(errorCode error);

MainWindow::MainWindow(QWidget *parent) :
      QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    target targetInit;
    FormTargetInit(targetInit);

    DrawByTarget(targetInit, ui);
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
        moveInfo move;
        FormMoveInfo(move, moveX, moveY, moveZ);

        target targetMove;
        FormTargetMove(targetMove, move);

        error = DrawByTarget(targetMove, ui);
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
        rotateInfo rotate;
        FormRotateInfo(rotate, rotateX, rotateY, rotateZ);

        target targetRotate;
        FormTargetRotate(targetRotate, rotate);

        error = DrawByTarget(targetRotate, ui);
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
        scaleInfo scale;
        FormScaleInfo(scale, scaleX, scaleY, scaleZ);

        target targetScale;
        FormTargetScale(targetScale, scale);

        error = DrawByTarget(targetScale, ui);
    }
    
    if (error != SUCCES)
    {
        ShowError(error);
    }
}

void MainWindow::on_actionOpen_triggered()
{
    target targetLoad;
    loadInfo load;
    FormLoadInfo(load, "cube.txt");
    FormTargetLoad(targetLoad, load);

    errorCode error = DrawByTarget(targetLoad, ui);

    if (error != SUCCES)
    {
        ShowError(error);
    }
}

errorCode DrawByTarget(target &targetToProcessing, Ui::MainWindow* ui)
{
    errorCode error = TargetProcessing(targetToProcessing);

    if (error == SUCCES)
    {
        drawInfo draw;
        QGraphicsView *graphicsView = ui->paintArea;
        FormDrawInfo(draw, graphicsView);

        target targetDraw;
        FormTargetDraw(targetDraw, draw);

        error = TargetProcessing(targetDraw);
    }

    return error;
}

errorCode ParseDouble(double &result, QString targetQString)
{
    bool isCorrect;
    result = targetQString.toDouble(&isCorrect);

    errorCode error = SUCCES;
    if (!isCorrect)
    {
        error = PARSE_ERROR;
    }

    return error;
}

void ShowError(errorCode error)
{
    QMessageBox::critical(NULL, "ERROR", GetErrorString(error));
}
