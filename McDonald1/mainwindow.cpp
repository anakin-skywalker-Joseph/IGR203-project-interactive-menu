#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "template.h"
#include "carte.h"
#include "catalogue.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    model = new Model();
    acc = new Accueil(this);

    QMainWindow::setCentralWidget(acc);
    setMinimumSize(1024, 740);

    setStyleSheet(" QMainWindow {background-color : white};QPushButton {color black; background-color :#FFCB60;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::mouseDoubleClickEvent(QMouseEvent *event){
    isFullScreen() ? showNormal() : showFullScreen();
}
/*
void MainWindow::on_action_Fullscreen_triggered()
{

}
*/
void MainWindow::displayCarte() {
    QMainWindow::setCentralWidget(new Template(this, model, Template::CARTE));
}

void MainWindow::displayEspaceAbo() {
    QMainWindow::setCentralWidget(new Template(this, model, Template::CONNEXION));
}

void MainWindow::backAccueil() {
    model->clear();
    Accueil * Acc = new Accueil(this);
    QMainWindow::setCentralWidget(Acc);
}
