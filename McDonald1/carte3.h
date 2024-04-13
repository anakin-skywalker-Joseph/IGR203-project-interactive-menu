#ifndef CARTE3_H
#define CARTE3_H



#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "model.h"
#include "template.h"

/*Cette classe correspond a une vue qui affiche les boutons qui permettent de naviguer entre les
differentes categories de la carte ("entree", "plat", "dessert" etc.) a gauche et une zone centrale qui sera remplie
par une vue Catalogue pour les categories "entree", "plat", "dessert" et "boisson" et une Menu pour la categorie menue*/
class Carte3 : public QWidget
{
    Q_OBJECT
public:
    explicit Carte3(Template *parent = nullptr, Model * m = nullptr);
    void setCentralWidget(QWidget * w) {
        centralWidget =  w;
        centralWidget->setStyleSheet("background:transparent;");
    }
    void paintEvent(QPaintEvent *);

signals:

public slots:

private:
    /*Objet contenant les donnees necessaires a l'application*/
    Model * model = nullptr;

    /*Widget et layout centraux*/
    QWidget * centralWidget = nullptr;
    QLayout * centralLayout = nullptr;

    /*Widget parent*/
    Template * temp;

    void ChangeButtonSize(QPushButton * button, int length = 200, int hight = 80, int fontsize = 12){
        button->setFixedSize(length, hight);
        QFont font = button->font();
        font.setPointSize(fontsize);
        button->setFont(font);
    }
};

#endif // CARTE3_H
