#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "model.h"
#include <QMainWindow>
#include "accueil.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots :
    inline const Model * getModel() {return model;}
    void displayCarte();
    void displayEspaceAbo();
    void backAccueil();
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    Ui::MainWindow *ui;
    Model * model = nullptr;
    Accueil* acc;
};

#endif // MAINWINDOW_H
