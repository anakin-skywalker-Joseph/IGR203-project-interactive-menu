
#include "commande.h"
#include "template.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSizePolicy>
#include <iostream>
#include <QSpinBox>
#include <QLineEdit>
#include <QLabel>
#include <QFrame>
#include <QMessageBox>
#include "commandeitem.h"

Commande::Commande(Template *p, Model * model) : QWidget(p)
{
    m = model;
    parent = p;
    //Interface
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QFont font = QFont("Arial", 22);

    //top
    QHBoxLayout * topLayout = new QHBoxLayout();
    QLabel * title = new QLabel(tr("Your Order List"));
    title->setFont(font);
    title->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    QPushButton * backButton = new QPushButton();
    backButton->setIcon(QIcon(":/images/cross.png"));
    backButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

    topLayout->addWidget(title);
    topLayout->addWidget(backButton);
    mainLayout->addLayout(topLayout);
    mainLayout->addStretch(1);

    mainWidget = new QWidget(this);

    std::vector<CommandeModel*> commande = m->getCommandes();
    int nbOfCommands = commande.size();
    QGridLayout * grid = new QGridLayout();
    unsigned int j = 0;
    for (int i = 0; i < nbOfCommands; i++) {
        CommandeModel * commandeItem = commande[i];
        if(commandeItem->getNbUnites() > 0){
            grid->addWidget(new CommandeItem(this, commandeItem), j/3, j%3);
            j = j+1 ;
        }
    }
    grid->setHorizontalSpacing(30);
    mainWidget->setLayout(grid);


    centralLayout->addWidget(mainWidget);
    mainLayout->addLayout(centralLayout);
    QHBoxLayout * bottomLayout = new QHBoxLayout();
    sendButton = new QPushButton("Confirm Your Order");
    sendButton->setFont(font);
    m->calculateTotal();
    float totalPrice = m->getTotal();
    total = new QLabel(QString("%1 euros").arg(totalPrice));
    total->setFont(font);
    bottomLayout->addWidget(total);
    bottomLayout->addStretch(10);
    bottomLayout->addWidget(sendButton);

    mainLayout->addStretch(1);
    mainLayout->addLayout(bottomLayout);

    connect(backButton, SIGNAL(clicked()), parent, SLOT(retourCommande()));
    connect(sendButton, SIGNAL(clicked()), parent, SLOT(displayOrderPlace()));
}

void Commande::refresh() {
    mainWidget->hide();
    centralLayout->removeWidget(mainWidget);
    mainWidget = new QWidget();

    std::vector<CommandeModel*> commande = m->getCommandes();
    int nbOfCommands = commande.size();
    QGridLayout * grid = new QGridLayout();
    unsigned int j = 0;
    for (int i = 0; i < nbOfCommands; i++) {
        CommandeModel * commandeItem = commande[i];
        if(commandeItem->getNbUnites() > 0){
            grid->addWidget(new CommandeItem(this, commandeItem), j/3, j%3);
            j = j +1;
        }
    }
    grid->setHorizontalSpacing(30);
    mainWidget->setLayout(grid);

    centralLayout->addWidget(mainWidget);


}

void Commande::envoieCommande() {


    m->clear();

    QMessageBox msgBox(this);
    msgBox.setText("Implementation of Payment methods, Eat in/Take out etc..");
    msgBox.exec();
    parent->retourCommande();
}
