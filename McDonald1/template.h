//Arthur
#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <QHBoxLayout>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QPushButton>
#include "model.h"
#include "accueil.h"
#include<string>

/*Cette classe est le widget qui dans lequel sont affichees les differentes rubriques de la carte en son centre.
Il affiche en haut des boutons permettant de naviguer entre les differentes widgets*/
class Template : public QWidget
{
    Q_OBJECT
public:
    enum Rubriques{CARTE = 0, ESPACEABO, CONNEXION, INSCRIPTION};
    explicit Template(QWidget *parent = nullptr, Model *m =nullptr, Rubriques rub = CARTE);
    QWidget * getCentralWidget();
    void setCentralWidget(QWidget * w) {
        centralWidget =  w;
        //centralWidget->setObjectName("tito");
        //centralWidget->setStyleSheet("QWidget#tito{border-image: url(:/images/mc.png) 0 0 0 0 stretch stretch;} ");
    }
    void setPreviousWidget(QWidget * w, int which){
        previousWidget = w;
        which_widget = which;
    }
    void paintEvent(QPaintEvent *);

signals:
    void cancel_yes();

public slots:
    void displayCarte();
    void displayEspaceAbo(std::string name="");
    void displayEspaceAbo_new(std::string name="");
    void displayInscription();
    void displayRecherche();
    void displayCommande();
    void displayPayment();
    void displayOrderPlace();
    void displayGoodbye();
    void displayDetail(Plat* p, int is_menu=0);
    void check_cancel();
    void retourCommande();

private :
    /*Widget precedemment affiche au centre*/
    QVBoxLayout * mainLayout = nullptr;
    QWidget * previousWidget = nullptr;
    int which_widget = 1;
    Accueil * accueil = new Accueil(this);
    /*Widget actuellement affiche au centre*/
    QWidget * centralWidget = nullptr;
    QHBoxLayout * centralLayout = new QHBoxLayout() ;
    Model *model = nullptr;
    QPushButton * BackButton;
    QPushButton * rechercheButton;
    QPushButton * undoButton;
    QPushButton * menuButton;
    QPushButton * aboButton;
    QPushButton * commandeButton;
    QPushButton * CancelButton;
};

#endif // TEMPLATE_H
