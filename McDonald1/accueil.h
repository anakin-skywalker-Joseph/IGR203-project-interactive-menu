//Arthur
#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QPixmap>
#include <QWidget>
#include "model.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
class Accueil : public QWidget
{
    Q_OBJECT
public:
    explicit Accueil(QWidget *parent = nullptr, Model * m = nullptr);
    Model * model= nullptr;

signals:

public slots:

    void changeLangueFR();
    void changeLangueEN();
    void changeLangueCH();


private :
    /*Widget central*/
    QWidget * mainWidget = new QWidget();
    QHBoxLayout * buttonLayout;
    /*QLabel qui contient l'image du titre de l'écran d'accueil*/

    QPushButton * DirectButton ;
    QPushButton * logButton ;
};

#endif // ACCUEIL_H
