#include "espaceabo.h"

EspaceAbo::EspaceAbo(Template * t, Model * m) : QWidget(t)
{
    model = m;
    temp = t;
    Membre * membreCourant = model->getClients()[model->getIndiceFamilleCourante()]->getMembres()->at(0);
    int indice = m->getIndiceFamilleCourante();
    Famille * famille = model->getClients()[indice];

    QVBoxLayout * layout = new QVBoxLayout(this);
    QHBoxLayout * topVerticalLayout = new QHBoxLayout();
    QVBoxLayout * bottomVerticalLayout = new QVBoxLayout();

    QString welcome = QString::fromStdString( "Hi "+model->getName()+"!");
    QLabel * customer = new QLabel(welcome);
    customer->setStyleSheet("QLabel { color : black; }");
    QFont font0 = customer->font();
    font0.setPointSize(12);
    font0.setBold(true);
    customer->setFont(font0);

    QPushButton * deconnexionButton = new QPushButton("Disconnect");
    deconnexionButton->setMinimumSize(QSize(60, 30));
    deconnexionButton->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    deconnexionButton->setFont(QFont("Helvetica", 10, QFont::Bold));
    deconnexionButton->setCheckable(true);
    deconnexionButton->setStyleSheet("color:white; background-color: orange;");
    topVerticalLayout->addWidget(customer);
    topVerticalLayout->addStretch(1);
    topVerticalLayout->addWidget(deconnexionButton);


    QVBoxLayout * platsFavorisWithLabelLayout = new QVBoxLayout();
    QLabel * platsFavorisLabel = new QLabel("Your Ordering History:");
    platsFavorisLabel->setStyleSheet("QLabel { color : blue; }");
    QFont font = platsFavorisLabel->font();
    font.setPointSize(10);
    font.setBold(true);
    platsFavorisLabel->setFont(font);

    QWidget * platsFavorisContentWidget = new QWidget();
    QScrollArea * platsFavorisScrollArea = new QScrollArea;
    platsFavorisScrollArea->setAlignment(Qt::AlignCenter);
    platsFavorisScrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    platsFavorisScrollArea->setHorizontalScrollBarPolicy( Qt::ScrollBarAsNeeded);
    platsFavorisScrollArea->setMinimumHeight(185);
    platsFavorisScrollArea->setMaximumHeight(250);
    QHBoxLayout * platsFavorisLayout = new QHBoxLayout();
    platsFavorisLayout->setSpacing(10);
    std::vector<Plat*>* favoris = model->getClients()[model->getIndiceFamilleCourante()]->getMembres()->at(0)->getFavoris();
    if (!model->is_new()){
    for(unsigned int i = 0; i<favoris->size();i++){
        CatalogueItem * item = new CatalogueItem(temp, favoris->at(i));
        platsFavorisLayout->addWidget(item);
    }
    }
    platsFavorisContentWidget->setLayout(platsFavorisLayout);
    platsFavorisScrollArea->setWidget(platsFavorisContentWidget);

    platsFavorisWithLabelLayout->addWidget(platsFavorisLabel);
    platsFavorisWithLabelLayout->addWidget(platsFavorisScrollArea);

    QVBoxLayout * recommandationsWithLabelLayout = new QVBoxLayout();
    QLabel * recommandationsLabel = new QLabel("Special Discount for You: ");
    recommandationsLabel->setStyleSheet("QLabel { color : red; }");
    QFont font1 = recommandationsLabel->font();
    font1.setPointSize(10);
    font1.setBold(true);
    recommandationsLabel->setFont(font);

    QWidget * recommandationsContentWidget = new QWidget();
    QScrollArea * recommandationsScrollArea = new QScrollArea();
    recommandationsScrollArea->setAlignment(Qt::AlignCenter);
    recommandationsScrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    recommandationsScrollArea->setHorizontalScrollBarPolicy( Qt::ScrollBarAsNeeded);
    recommandationsScrollArea->setMinimumHeight(185);
    recommandationsScrollArea->setMaximumHeight(250);
    QHBoxLayout * recommandationsLayout = new QHBoxLayout();
    recommandationsLayout->setSpacing(10);

    std::vector<Plat*>* recommandations = membreCourant->getRecommendations();
    for(unsigned int i = 0; i<recommandations->size();i++){
        CatalogueItem * item = new CatalogueItem(temp, favoris->at(i));
        recommandationsLayout->addWidget(item);
    }
    recommandationsContentWidget->setLayout(recommandationsLayout);
    recommandationsScrollArea->setWidget(recommandationsContentWidget);

    recommandationsWithLabelLayout->addWidget(recommandationsLabel);
    recommandationsWithLabelLayout->addWidget(recommandationsScrollArea);

    bottomVerticalLayout->addLayout(platsFavorisWithLabelLayout);
    bottomVerticalLayout->addSpacing(4);
    bottomVerticalLayout->addLayout(recommandationsWithLabelLayout);
    bottomVerticalLayout->addSpacing(4);

    layout->addLayout(topVerticalLayout);
    layout->addLayout(bottomVerticalLayout);

    connect(deconnexionButton,SIGNAL(clicked()),this,SLOT(disconnect()));
}

void EspaceAbo::disconnect(){
    model->setConnected(false);
    model->clear();
    temp->displayEspaceAbo();
}


