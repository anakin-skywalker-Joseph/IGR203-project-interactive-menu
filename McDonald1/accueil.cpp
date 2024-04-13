#include "accueil.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

Accueil::Accueil(QWidget *parent, Model * m) : QWidget(parent)
{
    model = m ;

    QVBoxLayout * mainLayout = new QVBoxLayout();

    QHBoxLayout * topLayout = new QHBoxLayout();
    topLayout->setSpacing(0);

    QPushButton * frButton = new QPushButton("Fr");
    frButton->setIcon(QIcon(":/images/france.jpg"));
    frButton->setMinimumSize(QSize(50, 40));
    QPushButton * engButton = new QPushButton("Eng");
    engButton->setIcon(QIcon(":/images/angleterre.jpg"));
    engButton->setMinimumSize(QSize(50, 40));
    QPushButton * chButton = new QPushButton("Ch");
    chButton->setIcon(QIcon(":/images/chine.png"));
    chButton->setMinimumSize(QSize(50, 40));

    QSizePolicy langSizePolicy = QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    frButton->setSizePolicy(langSizePolicy);
    engButton->setSizePolicy(langSizePolicy);
    chButton->setSizePolicy(langSizePolicy);

    topLayout->addWidget(frButton);
    topLayout->addWidget(engButton);
    topLayout->addWidget(chButton);
    topLayout->addStretch();

    mainWidget->setMinimumSize(QSize(600, 400));
    mainWidget->setObjectName(QObject::tr("tata"));
    mainWidget->setStyleSheet("QWidget#tata{border-image: url(:/images/welcome.png) 0 0 0 0 stretch stretch;} ");

    DirectButton = new QPushButton("Order Directly");
    DirectButton->setFixedSize(300, 100);
    QFont font = DirectButton->font();
    font.setPointSize(12);
    DirectButton->setFont(font);

    logButton = new QPushButton("Login");
    logButton->setFixedSize(300, 100);
    QFont font1 = logButton->font();
    font1.setPointSize(12);
    logButton->setFont(font1);

    buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch(5);
    buttonLayout->addWidget(logButton);
    buttonLayout->addWidget(DirectButton);
    buttonLayout->addStretch(6);
    buttonLayout->setSpacing(40);

    mainLayout->addLayout(topLayout);
    mainLayout->addStretch(3);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch(1);

    mainWidget->setLayout(mainLayout);

    QVBoxLayout * centralLayout = new QVBoxLayout();
    centralLayout->addWidget(mainWidget);
    setLayout(centralLayout);

    connect(logButton, SIGNAL(clicked()), parent, SLOT(displayEspaceAbo()));
    connect(DirectButton, SIGNAL(clicked()), parent, SLOT(displayCarte()));

    connect(engButton, SIGNAL(clicked()), this, SLOT(changeLangueEN()));
    connect(frButton, SIGNAL(clicked()), this, SLOT(changeLangueFR()));
    connect(chButton, SIGNAL(clicked()), this, SLOT(changeLangueCH()));
}

void Accueil::changeLangueFR(){
     DirectButton->setText("Commande Directe");
     logButton->setText("Se Connecter");
}

void Accueil::changeLangueEN(){
    DirectButton->setText("Order Directly");
    logButton->setText("Login");
}

void Accueil::changeLangueCH(){
    DirectButton->setText("直接点单");
    logButton->setText("登录");
}
