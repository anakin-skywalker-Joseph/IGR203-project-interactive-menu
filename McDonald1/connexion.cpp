#include "connexion.h"

Connexion::Connexion(Template *parent, Model * m) : QWidget(parent)
{
    model = m;
    QVBoxLayout * layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignCenter);
    //layout->setMargin(100);
    layout->setSpacing(20);
    QFormLayout *formLayout = new QFormLayout();
    formLayout->setSpacing(10);
    familleLineEdit = new QLineEdit();
    passwordLineEdit = new QLineEdit();
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    familleLineEdit->setFont(model->getButtonFont());
    passwordLineEdit->setFont(model->getButtonFont());
    formLayout->addRow(tr("&Username:"), familleLineEdit);
    formLayout->addRow(tr("&Password:"),passwordLineEdit);
    layout->addLayout(formLayout);

    QVBoxLayout * connexionLayout = new QVBoxLayout();
    QPushButton * connexionButton = new QPushButton("Connect");

//    feedbackLabel = new QLabel();
//    feedbackLabel->setAlignment(Qt::AlignCenter);
    connexionLayout->addWidget(connexionButton);
    connexionLayout->setAlignment(Qt::AlignCenter);
//    connexionLayout->addWidget(feedbackLabel);

    QPushButton * creerCompteButton = new QPushButton("Create Account");
    connexionButton->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    creerCompteButton->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    creerCompteButton->setFont(model->getButtonFont());
    connexionButton->setFont(model->getButtonFont());
    layout->addLayout(connexionLayout);

    QHBoxLayout * creeCompteLayout = new QHBoxLayout();
    creeCompteLayout->addWidget(creerCompteButton);
    creeCompteLayout->setAlignment(Qt::AlignCenter);
    layout->addLayout(creeCompteLayout);

    QPushButton * menuButton = new QPushButton("Order Directly");
    menuButton->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    menuButton->setFont(model->getButtonFont());
    QHBoxLayout * menuLayout = new QHBoxLayout();
    menuLayout->addWidget(menuButton);
    menuLayout->setAlignment(Qt::AlignCenter);
    layout->addLayout(menuLayout);

    QWidget * centralWidget = new QWidget();
    centralWidget->setObjectName("tutu");
    centralWidget->setStyleSheet("QWidget#tutu{border-image: url(:/images/mclog.png) 0 0 0 0 stretch stretch;} ");

    centralWidget->setLayout(layout);

    QHBoxLayout * mainLayout = new QHBoxLayout();
    mainLayout->addWidget(centralWidget);
    setLayout(mainLayout);

    connect(creerCompteButton,SIGNAL(clicked()),parent,SLOT(displayInscription()));
    connect(connexionButton,SIGNAL(clicked()),this,SLOT(verifierIdentifiants()));
    connect(menuButton,SIGNAL(clicked()),parent,SLOT(displayCarte()));
    connect(this,SIGNAL(identifiantsCorrects()),parent,SLOT(displayEspaceAbo()));
    connect(this,&Connexion::identifiantsCorrects,[this,parent](){
        std::string name = familleLineEdit->text().toStdString();
        if (familleLineEdit->text().isEmpty()) name = "Customer aaa";
        parent->displayEspaceAbo(name);});
}


void Connexion::verifierIdentifiants(){
    model->setConnected(true);
    model->setIndiceFamilleCourante(0);
    std::string name = familleLineEdit->text().toStdString();
    if (familleLineEdit->text().isEmpty()) name = "Customer aaa";
    model->setName(name);
    emit(identifiantsCorrects());
}



