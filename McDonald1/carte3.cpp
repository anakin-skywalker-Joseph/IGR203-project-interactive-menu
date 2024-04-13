#include "carte3.h"
#include "template.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <iostream>

Carte3::Carte3(Template * parent, Model * m) : QWidget(parent)
{
    model = m;
    temp = parent;
    QHBoxLayout * mainLayout = new QHBoxLayout();
    QHBoxLayout * topLayout = new QHBoxLayout();
    topLayout->setSpacing(0);


    QPushButton * cardButton = new QPushButton("Take Away");
    ChangeButtonSize(cardButton);
    connect(cardButton, SIGNAL(clicked()), temp, SLOT(displayPayment()));

    QPushButton * cashButton = new QPushButton("Eat in");
    ChangeButtonSize(cashButton);
    connect(cashButton, SIGNAL(clicked()), temp, SLOT(displayPayment()));

    mainLayout->addWidget(cardButton);
    mainLayout->addWidget(cashButton);
    setLayout(mainLayout);


}


void Carte3::paintEvent(QPaintEvent *){
}

