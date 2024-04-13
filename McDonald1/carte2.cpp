#include "carte2.h"
#include "template.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <iostream>

Carte2::Carte2(Template * parent, Model * m) : QWidget(parent)
{
    model = m;
    temp = parent;
    QHBoxLayout * mainLayout = new QHBoxLayout();
    QHBoxLayout * topLayout = new QHBoxLayout();
    topLayout->setSpacing(0);


    QPushButton * cardButton = new QPushButton("Card");
    ChangeButtonSize(cardButton);
    connect(cardButton, SIGNAL(clicked()), temp, SLOT(displayGoodbye()));

    QPushButton * cashButton = new QPushButton("Cash");
    ChangeButtonSize(cashButton);
    connect(cashButton, SIGNAL(clicked()), temp, SLOT(displayGoodbye()));

    mainLayout->addWidget(cardButton);
    mainLayout->addWidget(cashButton);
    setLayout(mainLayout);


}


void Carte2::paintEvent(QPaintEvent *){
}

