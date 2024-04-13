#include "template.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSizePolicy>
#include <iostream>
#include "carte4.h"
#include "commande.h"
#include "carte.h"
#include "connexion.h"
#include "detail.h"
#include "carte2.h"
#include "carte3.h"
#include "recherche.h"
#include "inscription.h"
#include "espaceabo.h"
#include <QTimer>
#include <QPainter>
#include <QStackedLayout>
Template::Template(QWidget *parent, Model *m, Rubriques rub) : QWidget(parent)
{
    model = m;

    QWidget * mainWidget = new QWidget();
    //mainWidget->setMinimumSize(QSize(800, 600));
    mainWidget->setObjectName(QObject::tr("tata"));
    mainWidget->setStyleSheet("QWidget#tata{border-image: url(:/images/mc.png) 0 0 0 0 stretch stretch;} ");

    mainLayout = new QVBoxLayout(this);
    centralLayout = new QHBoxLayout() ;
    //Barre supérieure
    QHBoxLayout * topMenuLayout = new QHBoxLayout();

    QButtonGroup * topGroup = new QButtonGroup();
    topGroup->setExclusive(true);

    QString style = QString("QPushButton:checked{background-color: yellow;} QPushButton:pressed {background-color: yellow;}");

    aboButton = new QPushButton(tr("Your Profile"));
    topGroup->addButton(aboButton);
    aboButton->setCheckable(true);
    aboButton->setStyleSheet(style);
    rechercheButton = new QPushButton(tr("Filter"));
    undoButton = new QPushButton(tr("Undo"));
    topGroup->addButton(rechercheButton);
    rechercheButton->setCheckable(true);
    rechercheButton->setStyleSheet(style);

    aboButton->setFont(model->getButtonFont());
    rechercheButton->setFont(model->getButtonFont());

    topMenuLayout->addWidget(rechercheButton);
    topMenuLayout->addWidget(undoButton);
    topMenuLayout->addStretch();
    topMenuLayout->addWidget(aboButton);

    //Zone centrale
    switch (rub) {
    case CARTE:
        setCentralWidget(new Carte(this, model));
        setPreviousWidget(centralWidget,1);
        break;

    case CONNEXION:
        setCentralWidget(new Connexion(this, model));
        setPreviousWidget(centralWidget,0);
//        BackButton->hide();
//        rechercheButton->hide();
//        aboButton->hide();
//        undoButton->hide();
//        menuButton->show();
//        commandeButton->hide();
        break;

    default:
        centralWidget = new QWidget();
        break;
    }
    centralWidget->setMinimumSize(QSize(600, 400));
    centralLayout->addWidget(centralWidget);

    //Barre inférieure
    QHBoxLayout * bottomMenuLayout = new QHBoxLayout();

    BackButton = new QPushButton(tr("Go Back"));
    CancelButton = new QPushButton(tr("Cancel Order"));
    menuButton = new QPushButton(tr("Back to Menu"));
    commandeButton = new QPushButton(tr("Your Order"));

    BackButton->setFont(model->getButtonFont());
    CancelButton->setFont(model->getButtonFont());
    commandeButton->setFont(model->getButtonFont());
    menuButton->setFont(model->getButtonFont());

    bottomMenuLayout->addWidget(CancelButton);
    bottomMenuLayout->addWidget(BackButton);
    bottomMenuLayout->addWidget(menuButton);
    bottomMenuLayout->addWidget(commandeButton);
    menuButton->hide();
    //Layout général
    mainLayout->addLayout(topMenuLayout);
    mainWidget->setLayout(centralLayout);

    //mainLayout->addLayout(centralLayout);
    mainLayout->addWidget(mainWidget);
    mainLayout->addLayout(bottomMenuLayout);
    //Connection des boutons aux slots
    connect(aboButton, SIGNAL(clicked()), this, SLOT(displayEspaceAbo()));
    connect(rechercheButton, SIGNAL(clicked()), this, SLOT(displayRecherche()));
    connect(menuButton, SIGNAL(clicked()), this, SLOT(displayCarte()));
    connect(commandeButton, SIGNAL(clicked()), this, SLOT(displayCommande()));
    connect(BackButton, SIGNAL(clicked()), this, SLOT(retourCommande()));
    connect(CancelButton, SIGNAL(clicked()), this, SLOT(check_cancel()));
    connect(this, SIGNAL(cancel_yes()), parent, SLOT(backAccueil()));
    connect(undoButton, &QPushButton::clicked, [this]() {
        this->model->set_filter(false);
        this->displayCarte();
    });

    CancelButton->hide();

    switch (rub) {
    case CARTE:
        displayCarte();
        setPreviousWidget(centralWidget,1);
        break;

    case CONNEXION:
        displayEspaceAbo();
        setPreviousWidget(centralWidget,0);
        break;

    default:
        break;
    }
}

void Template::check_cancel() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel Order", "Are you sure you want to cancel the whole order?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) emit cancel_yes();
}


void Template::displayCarte() {
    centralLayout->removeWidget(centralWidget);
    centralWidget->hide();
    BackButton->hide();
    aboButton->show();
    commandeButton->show();
    rechercheButton->show();
    undoButton->show();
    menuButton->hide();
    CancelButton->show();
    setCentralWidget(new Carte(this,model));
    setPreviousWidget(centralWidget, 1);
    centralLayout->addWidget(centralWidget);
    update();
}

void Template::displayOrderPlace() {
    centralLayout->removeWidget(centralWidget);
    centralWidget->hide();
    BackButton->show();
    aboButton->hide();
    commandeButton->show();
    rechercheButton->hide();
    undoButton->hide();
    menuButton->hide();
    CancelButton->hide();
    setCentralWidget(new Carte3(this,model));
//    setPreviousWidget(centralWidget, 1);
    centralLayout->addWidget(centralWidget);
    update();
}

void Template::displayPayment() {
    centralLayout->removeWidget(centralWidget);
    centralWidget->hide();
    BackButton->show();
    aboButton->hide();
    commandeButton->show();
    rechercheButton->hide();
    undoButton->hide();
    menuButton->hide();
    CancelButton->hide();
    setCentralWidget(new Carte2(this,model));
//    setPreviousWidget(centralWidget, 1);
    centralLayout->addWidget(centralWidget);
    update();
}


void Template::displayGoodbye() {
    centralLayout->removeWidget(centralWidget);
    centralWidget->hide();
    BackButton->hide();
    aboButton->hide();
    commandeButton->hide();
    rechercheButton->hide();
    undoButton->hide();
    menuButton->hide();
    CancelButton->hide();
    setCentralWidget(new Carte4(this,model));
    setPreviousWidget(centralWidget, 1);
    centralLayout->addWidget(centralWidget);
    update();
}


void Template::displayRecherche() {
    centralLayout->removeWidget(centralWidget);
    centralWidget->hide();
    setCentralWidget(new Recherche(this,model));
    BackButton->show();
    rechercheButton->hide();
    commandeButton->hide();
    aboButton->hide();
    undoButton->hide();
    menuButton->hide();
    CancelButton->hide();
    //setPreviousWidget(centralWidget);
    centralLayout->addWidget(centralWidget);
    update();
}

void Template::displayEspaceAbo(std::string name) {
    centralLayout->removeWidget(centralWidget);
    centralWidget->hide();
    BackButton->hide();
    rechercheButton->hide();
    aboButton->hide();
    undoButton->hide();
    menuButton->show();
    CancelButton->hide();
    if(model->getConnected()){
        setCentralWidget(new EspaceAbo(this,model));
        setPreviousWidget(centralWidget, 2);
        commandeButton->show();

    }
    else{
        model->set_is_new(false);
        setCentralWidget(new Connexion(this,model));
        setPreviousWidget(centralWidget, 0);
        commandeButton->hide();
    }
    centralLayout->addWidget(centralWidget);
    update();
}

void Template::displayEspaceAbo_new(std::string name) {
    centralLayout->removeWidget(centralWidget);
    centralWidget->hide();
    BackButton->hide();
    rechercheButton->hide();
    aboButton->hide();
    undoButton->hide();
    menuButton->show();
    CancelButton->hide();
    model->set_is_new(true);
    setCentralWidget(new EspaceAbo(this,model));
    setPreviousWidget(centralWidget, 2);
    commandeButton->show();
    model->setConnected(true);
    model->setName(name);
    centralLayout->addWidget(centralWidget);
    update();
}

void Template::displayInscription(){
    centralLayout->removeWidget(centralWidget);
    centralWidget->hide();
    BackButton->show();
    rechercheButton->hide();
    commandeButton->hide();
    aboButton->hide();
    undoButton->hide();
    menuButton->show();
    CancelButton->hide();
    setCentralWidget(new Inscription(this,model));
    //setPreviousWidget(centralWidget);
    centralLayout->addWidget(centralWidget);
    update();
}


void Template::displayCommande() {
   centralLayout->removeWidget(centralWidget);
   centralWidget->hide();
   BackButton->show();
   rechercheButton->hide();
   commandeButton->hide();
   aboButton->hide();
   undoButton->hide();
   menuButton->hide();
   CancelButton->hide();
   setCentralWidget(new Commande(this, model));
   centralLayout->addWidget(centralWidget);
}


void Template::displayDetail(Plat* p, int is_menu) {
    centralLayout->removeWidget(centralWidget);
    centralWidget->hide();
    BackButton->show();
    rechercheButton->hide();
    commandeButton->show();
    aboButton->hide();
    undoButton->hide();
    menuButton->hide();
    CancelButton->hide();
    setCentralWidget(new Detail(this, model, p, is_menu));
    centralLayout->addWidget(centralWidget);
}

void Template::retourCommande() {
    centralLayout->removeWidget(centralWidget);
    centralWidget->hide();
    setCentralWidget(previousWidget);
    if (which_widget==1){  //menu
        BackButton->hide();
        rechercheButton->show();
        commandeButton->show();
        aboButton->show();
        undoButton->show();
        menuButton->hide();
        CancelButton->show();
    }
    else if (which_widget==0){   //login
        BackButton->hide();
        rechercheButton->hide();
        commandeButton->hide();
        aboButton->hide();
        undoButton->hide();
        menuButton->show();
        CancelButton->hide();
    }
    else{   //connected
        BackButton->hide();
        rechercheButton->hide();
        commandeButton->show();
        aboButton->hide();
        undoButton->hide();
        menuButton->show();
        CancelButton->hide();
    }
    centralLayout->addWidget(centralWidget);
    centralWidget->show();
    update();
}

void Template::paintEvent(QPaintEvent *){
}
