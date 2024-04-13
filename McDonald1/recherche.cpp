#include "recherche.h"
#include <QLineEdit>

Recherche::Recherche(Template *parent, Model * m) : QWidget(parent)
{
    model = m;
    QHBoxLayout * mainLayout = new QHBoxLayout();

    //Création de la colonne recherche
    QVBoxLayout * vlayout = new QVBoxLayout();

    QGroupBox * typeGroupBox = new QGroupBox(tr("Special Demand"));
    QVBoxLayout * typeLayout = new QVBoxLayout();

    QHBoxLayout * dishLayout = new QHBoxLayout();
    QPushButton * starterButton = new QPushButton(tr("No Spicy"));
    starterButton->setCheckable(true);
    starterButton->setStyleSheet(QString(" QPushButton:checked{background-color: grey;} QPushButton {background-color: orange;}"));
    QPushButton * mealButton = new QPushButton(tr("No Sugar"));
    mealButton->setCheckable(true);
    mealButton->setStyleSheet(QString(" QPushButton:checked{background-color: grey;} QPushButton {background-color: orange;}"));
    QPushButton * dessertsButton = new QPushButton(tr("Muslim"));
    dessertsButton ->setCheckable(true);
    dessertsButton->setStyleSheet(QString(" QPushButton:checked{background-color: grey;} QPushButton {background-color: orange;}"));
    dishLayout->addWidget(starterButton);
    dishLayout->addWidget(mealButton);
    dishLayout->addWidget(dessertsButton);

    QHBoxLayout * detailLayout = new QHBoxLayout();
    QPushButton * spicyButton = new QPushButton(tr("Vegan"));
    spicyButton->setCheckable(true);
    spicyButton->setStyleSheet(QString(" QPushButton:checked{background-color: grey;} QPushButton {background-color: orange;}"));
    QPushButton * vegButton = new QPushButton(tr("Vegetarien"));
    vegButton->setCheckable(true);
    vegButton->setStyleSheet(QString(" QPushButton:checked{background-color: grey;} QPushButton {background-color: orange;}"));
    detailLayout->addWidget(spicyButton);
    detailLayout->addWidget(vegButton);

    typeLayout->addLayout(dishLayout);
    typeLayout->addLayout(detailLayout);
    typeGroupBox->setLayout(typeLayout);

    //Groupe choix ingrédient
    QGroupBox * ingGroupBox = new QGroupBox(tr("Allergic Ingredients"));
    QGridLayout * ingLayout = new QGridLayout();

    QToolButton * ingred1Button = new QToolButton();
    ingred1Button->setText("Ingred 1");
    ingLayout->addWidget(ingred1Button);
    ingred1Button->setCheckable(true);
    ingred1Button->setStyleSheet(QString(" QToolButton:checked{background-color: grey;} QToolButton {background-color: pink;}"));

    QToolButton * ingred2Button = new QToolButton();
    ingred2Button->setText("Ingred 2");
    ingLayout->addWidget(ingred2Button);
    ingred2Button->setCheckable(true);
    ingred2Button->setStyleSheet(QString(" QToolButton:checked{background-color: grey;} QToolButton {background-color: pink;}"));

    QToolButton * ingred3Button = new QToolButton();
    ingred3Button->setText("Ingred 3");
    ingLayout->addWidget(ingred3Button);
    ingred3Button->setCheckable(true);
    ingred3Button->setStyleSheet(QString(" QToolButton:checked{background-color: grey;} QToolButton {background-color: pink;}"));


    QToolButton * ingred4Button = new QToolButton();
    ingred4Button->setText("Ingred 4");
    ingLayout->addWidget(ingred4Button);
    ingred4Button->setCheckable(true);
    ingred4Button->setStyleSheet(QString(" QToolButton:checked{background-color: grey;} QToolButton {background-color: pink;}"));

    QToolButton * ingred5Button = new QToolButton();
    ingred5Button->setText("Ingred 5");
    ingLayout->addWidget(ingred5Button);
    ingred5Button->setCheckable(true);
    ingred5Button->setStyleSheet(QString(" QToolButton:checked{background-color: grey;} QToolButton {background-color: pink;}"));

    QToolButton * ingred6Button = new QToolButton();
    ingred6Button->setText("Ingred 6");
    ingLayout->addWidget(ingred6Button);
    ingred6Button->setCheckable(true);
    ingred6Button->setStyleSheet(QString(" QToolButton:checked{background-color: grey;} QToolButton {background-color: pink;}"));

    ingGroupBox->setLayout(ingLayout);
    QPushButton * confirmButton = new QPushButton(tr("Confirm"));
    confirmButton->setStyleSheet("QPushButton { font-size: 16pt; }");
//    connect(confirmButton, SIGNAL(clicked()), parent, SLOT(displayCarte()));
    connect(confirmButton, &QPushButton::clicked, [parent, this]() {
        parent->displayCarte();
        this->model->set_filter(true);
    });

    vlayout->addWidget(new QLineEdit());
    vlayout->addWidget(typeGroupBox);
    vlayout->addWidget(ingGroupBox);
    vlayout->addSpacing(10);
    vlayout->addWidget(confirmButton);
    QFrame * buttonFrame = new QFrame();
    buttonFrame->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::MinimumExpanding);
    buttonFrame->setLayout(vlayout);

    //Zone centrale
//    centralLayout = new QHBoxLayout();
//    centralWidget = new Catalogue(this, parent,  model->getCarteEntiere());
//    centralWidget->setMinimumSize(QSize(300, 300));
//    centralLayout->addWidget(centralWidget);
//    centralWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
    mainLayout->addWidget(buttonFrame);
//    mainLayout->addLayout(centralLayout);

    setLayout(mainLayout);
}
