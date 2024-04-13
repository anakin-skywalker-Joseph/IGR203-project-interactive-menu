#include "carte.h"
#include "catalogue.h"
#include "menu.h"
#include "template.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <iostream>

Carte::Carte(Template * parent, Model * m) : QWidget(parent)
{
    model = m;
    temp = parent;
    QHBoxLayout * mainLayout = new QHBoxLayout();
    QHBoxLayout * topLayout = new QHBoxLayout();
    topLayout->setSpacing(0);
    
    class CarteButton : public QPushButton
    {
    public:
        CarteButton(QString label, Model * m) : QPushButton(label){
            setMinimumSize(QSize(280, 70));
            setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum));
            setFont(m->getButtonFont());
            setCheckable(true);
            setStyleSheet("QPushButton:checked{background-color: yellow;} QPushButton:pressed {background-color: yellow;}");
        }
        virtual ~CarteButton() {}
    };

    QButtonGroup * group = new QButtonGroup();
    group->setExclusive(true);
    QPushButton * entreesButton = new CarteButton("Sides", model);
    ChangeButtonSize(entreesButton);
    group->addButton(entreesButton);
    QPushButton * platsButton = new CarteButton("Hamburger", model);
    ChangeButtonSize(platsButton);
    group->addButton(platsButton);
    QPushButton * dessertsButton = new CarteButton("Deserts", model);
    ChangeButtonSize(dessertsButton);
    group->addButton(dessertsButton);
    QPushButton * menusButton = new CarteButton("Combo", model);
    ChangeButtonSize(menusButton);
    menusButton->setChecked(true);
    group->addButton(menusButton);
    QPushButton * boissonsButton = new CarteButton("Drinks", model);
    ChangeButtonSize(boissonsButton);
    group->addButton(boissonsButton);

    QVBoxLayout * buttonLayout = new QVBoxLayout();

    buttonLayout->addWidget(menusButton);

    buttonLayout->addWidget(entreesButton);

    buttonLayout->addWidget(platsButton);

    buttonLayout->addWidget(dessertsButton);

    buttonLayout->addWidget(boissonsButton);

    //Zone centrale
    centralLayout = new QHBoxLayout();
    centralWidget = new Menu(nullptr, temp, model);
    centralWidget->setMinimumSize(QSize(300, 300));
    centralWidget->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    centralWidget->setStyleSheet("background:transparent;");
    centralLayout->addWidget(centralWidget);

    mainLayout->addLayout(buttonLayout);
    mainLayout->addLayout(centralLayout);
    setLayout(mainLayout);

    connect(entreesButton, SIGNAL(clicked()), this, SLOT(displaySides()));
    connect(platsButton, SIGNAL(clicked()), this, SLOT(displayBurgers()));
    connect(dessertsButton, SIGNAL(clicked()), this, SLOT(displayDesserts()));
    connect(menusButton, SIGNAL(clicked()), this, SLOT(displayMenus()));
    connect(boissonsButton, SIGNAL(clicked()), this, SLOT(displayBoissons()));
}

void Carte::displaySides() {
    centralWidget->hide();
    centralLayout->removeWidget(centralWidget);
    setCentralWidget(new Catalogue(nullptr, temp, model->getSides()));
    centralLayout->addWidget(centralWidget);
    update();
}

void Carte::displayBurgers() {
    centralWidget->hide();
    centralLayout->removeWidget(centralWidget);
    setCentralWidget(new Catalogue(nullptr, temp, model->getBurger()));
    centralLayout->addWidget(centralWidget);
    update();
}

void Carte::displayDesserts() {
    centralWidget->hide();
    centralLayout->removeWidget(centralWidget);
    setCentralWidget(new Catalogue(nullptr, temp, model->getDesserts()));
    centralLayout->addWidget(centralWidget);
    update();
}



void Carte::displayMenus() {
    centralWidget->hide();
    centralLayout->removeWidget(centralWidget);
    setCentralWidget(new Menu(nullptr, temp, model));
    centralLayout->addWidget(centralWidget);
    update();
}

void Carte::displayBoissons() {
    centralWidget->hide();
    centralLayout->removeWidget(centralWidget);
    setCentralWidget(new Catalogue(nullptr, temp, model->getBoissons()));
    centralLayout->addWidget(centralWidget);
    update();
}

void Carte::paintEvent(QPaintEvent *){
}

