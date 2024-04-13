#ifndef CARTE4_H
#define CARTE4_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "model.h"
#include "qtimer.h"
#include "template.h"

/*Cette classe correspond a une vue qui affiche les boutons qui permettent de naviguer entre les
differentes categories de la carte ("entree", "plat", "dessert" etc.) a gauche et une zone centrale qui sera remplie
par une vue Catalogue pour les categories "entree", "plat", "dessert" et "boisson" et une Menu pour la categorie menue*/
class Carte4 : public QWidget
{
    Q_OBJECT
public:
    explicit Carte4(Template *parent = nullptr, Model * m = nullptr);
    void setCentralWidget(QWidget * w) {
        centralWidget =  w;
        centralWidget->setStyleSheet("background:transparent;");
    }
    void paintEvent(QPaintEvent *);

signals:

public slots:
    /*Rafraichit la vue pour afficher la rubrique désirée de la carte*/
    void cancel_();

private:
    /*Objet contenant les donnees necessaires a l'application*/
    Model * model = nullptr;

    /*Widget et layout centraux*/
    QWidget * centralWidget = nullptr;
    QLayout * centralLayout = nullptr;

    /*Widget parent*/
    Template * temp;

    QTimer timer{};

    void ChangeLabelSize(QLabel * label, int length = 500, int hight = 80, int fontsize = 16){
        label->setFixedSize(length, hight);
        QFont font = label->font();
        font.setPointSize(fontsize);
        label->setFont(font);
    }
};


#endif // CARTE4_H
