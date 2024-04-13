/*#ifndef PAYMENT_H
#define PAYMENT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "model.h"
#include "template.h"

class Payment : public QWidget
{
    Q_OBJECT
public:
    Payment(){};
    //explicit Payment(Template *parent = nullptr, Model * m = nullptr);
    void setCentralWidget(QWidget * w) {
        centralWidget =  w;
        centralWidget->setStyleSheet("background:transparent;");
    }
    void paintEvent(QPaintEvent *);

private:
    /*Objet contenant les donnees necessaires a l'application
    Model * model = nullptr;

    /*Widget et layout centraux
    QWidget * centralWidget = nullptr;
    QLayout * centralLayout = nullptr;

    /*Widget parent
    Template * temp;

};

#endif // PAYMENT_H*/
