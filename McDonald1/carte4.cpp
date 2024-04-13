#include "carte4.h"
#include <random>

Carte4::Carte4(Template * parent, Model * m) : QWidget(parent)
{

    model = m;
    temp = parent;
    QHBoxLayout * mainLayout = new QHBoxLayout();
    QHBoxLayout * topLayout = new QHBoxLayout();
    topLayout->setSpacing(0);

    std::default_random_engine  re(time(0));
    std::uniform_int_distribution<int> distrib{  0,  25  };

    std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    QString string("Thank you, your order number is ");// = QString();
    for  (int  i  =  0;  i  <  6;  i++)  {
           string.append(QString(alpha[distrib(re)]));
    }


    QLabel *label = new QLabel(string);
    ChangeLabelSize(label);

    mainLayout->addWidget(label);
    setLayout(mainLayout);

    connect(&timer, SIGNAL(timeout()), this, SLOT(cancel_()));
    timer.start(3000);


}

void Carte4::cancel_(){
emit temp->cancel_yes();
}

void Carte4::paintEvent(QPaintEvent *){
}

