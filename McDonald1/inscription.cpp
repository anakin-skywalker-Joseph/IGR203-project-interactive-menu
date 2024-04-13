#include "inscription.h"
#include<QString>
Inscription::Inscription(Template *parent, Model * m) : QWidget(parent)
{
    model = m;
    QVBoxLayout * layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignCenter);
    //layout->setMargin(100);
    QFormLayout * formLayout = new QFormLayout();
    nomCompteLineEdit = new QLineEdit();
    passwordLineEdit = new QLineEdit();
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    QPushButton * validerButton = new QPushButton("Create");

    validerButton->setFont(model->getButtonFont());

    formLayout->addRow(tr("&Your Name"),nomCompteLineEdit);
    formLayout->addRow(tr("&Password"),passwordLineEdit);
    layout->addLayout(formLayout);
    layout->addWidget(validerButton);
//    connect(validerButton,SIGNAL(clicked()), parent, SLOT(displayEspaceAbo_new()));
    connect(validerButton,&QPushButton::clicked,[this,parent](){
        std::string name = nomCompteLineEdit->text().toStdString();
        if (nomCompteLineEdit->text().isEmpty()) name = "Customer aaa";
        model->setName(name);
        parent->displayEspaceAbo_new(name);});
}

