#include "menu.h"
#include <QGroupBox>
#include <QMessageBox>

Menu::Menu(QWidget *parent, Template * t, Model * model) : QWidget(parent)
{
    temp = t;
    this->model = model;
    menuList = model->getMenus();
    unsigned int sizeMenu = menuList.size();
    std::cout << sizeMenu << std::endl;

    currentMenu = menuList[0];
    currentIndex = 0;

    QVBoxLayout * mainLayout = new QVBoxLayout(this);

    //Partie en-tête du menu
    QHBoxLayout * menu = new QHBoxLayout();
    menu->setAlignment(Qt::AlignCenter);

    QToolButton * flecheG = new QToolButton();
    flecheG->setIcon(QIcon(":/images/left.png"));

    QToolButton * flecheD = new QToolButton();
    flecheD->setIcon(QIcon(":/images/right.png"));

    menuLabel = new QLabel(QString("%1 (%2 euros)").arg(currentMenu->getName()).arg(currentMenu->getPrix()));
    menuLabel->setFont(QFont("Arial", 16));

    menu->addWidget(flecheG);
    menu->addWidget(menuLabel);
    menu->addWidget(flecheD);

    mainLayout->addLayout(menu);

    //Partie contenu du menu
    columns = new QHBoxLayout();
    sidesColumn = newColonne(currentMenu->getMenuSides(), "Sides");
    burgerColumn = newColonne(currentMenu->getMenuBurger(), "Burger");
    boissonColumn = newColonne(currentMenu->getMenuDesserts(), "Drink");

    columns->addWidget(sidesColumn);
    columns->addWidget(burgerColumn);
    columns->addWidget(boissonColumn);

    mainLayout->addLayout(columns);

    QHBoxLayout * choiceLayout = new QHBoxLayout();
    QPushButton * choiceButton = new QPushButton(tr("Confirm Your Combo"));
    choiceLayout->setAlignment(Qt::AlignCenter);
    choiceButton->setFont(model->getButtonFont());
    choiceButton->setStyleSheet("QPushButton {"
                          "  background-color: yellow;"
                          "}"
                          "QPushButton:pressed {"
                          "  background-color: orange;"
                          "}");
    choiceLayout->addWidget(choiceButton);

    mainLayout->addLayout(choiceLayout);

    connect(flecheD, SIGNAL(clicked()), this, SLOT(nextMenu()));
    connect(flecheG, SIGNAL(clicked()), this, SLOT(previousMenu()));
    connect(choiceButton,SIGNAL(clicked()), this, SLOT(validateMenu()));
}

QGroupBox * Menu::newColonne(std::vector<Plat *> liste, QString nom){
    QGroupBox * newColonne = new QGroupBox(nom);
    QVBoxLayout * colonne = new QVBoxLayout();
    colonne->addStretch(5);
    QButtonGroup * group = new QButtonGroup();
    group->setExclusive(true);

    for(unsigned int i = 0; i < liste.size(); i++){
        Plat * plat = liste[i];
        CatalogueItem * item = new CatalogueItem(temp, plat, true);
        item->setCheckable(true);
        item->setStyleSheet(QString(" QToolButton:checked{background-color: pink;} QToolButton:pressed {background-color: pink;}"));
        group->addButton(item);
        colonne->addWidget(item);
        colonne->addStretch(5);
    }
    colonne->setAlignment(Qt::AlignCenter);
    newColonne->setLayout(colonne);
    return newColonne;
}

void Menu::nextMenu(){
    int nbOfMenus = menuList.size();
    currentIndex = (currentIndex + 1) % nbOfMenus;
    currentMenu = menuList[currentIndex];
    menuLabel->setText(QString("%1 (%2 euros)").arg(currentMenu->getName()).arg(currentMenu->getPrix()));

    columns->removeWidget(sidesColumn);
    sidesColumn->hide();
    sidesColumn = newColonne(currentMenu->getMenuSides(), "Sides");
    columns->addWidget(sidesColumn);

    columns->removeWidget(burgerColumn);
    burgerColumn->hide();
    burgerColumn = newColonne(currentMenu->getMenuBurger(), "Burger");
    columns->addWidget(burgerColumn);

    columns->removeWidget(boissonColumn);
    boissonColumn->hide();
    boissonColumn = newColonne(currentMenu->getMenuDesserts(), "Drink");
    columns->addWidget(boissonColumn);
}

void Menu::previousMenu(){
    int nbOfMenus = menuList.size();
    if(currentIndex == 0){
        currentIndex = nbOfMenus - 1;
    }
    else{
        currentIndex = (currentIndex - 1) % nbOfMenus;
    }
    currentMenu = menuList[currentIndex];
    menuLabel->setText(QString("%1 (%2 euros)").arg(currentMenu->getName()).arg(currentMenu->getPrix()));

    columns->removeWidget(sidesColumn);
    sidesColumn->hide();
    sidesColumn = newColonne(currentMenu->getMenuSides(), "Sides");
    columns->addWidget(sidesColumn);

    columns->removeWidget(burgerColumn);
    burgerColumn->hide();
    burgerColumn = newColonne(currentMenu->getMenuBurger(), "Burger");
    columns->addWidget(burgerColumn);

    columns->removeWidget(boissonColumn);
    boissonColumn->hide();
    boissonColumn = newColonne(currentMenu->getMenuDesserts(), "Drink");
    columns->addWidget(boissonColumn);
}

void Menu::validateMenu() {
    QMessageBox::StandardButton reply1;
    reply1 = QMessageBox::question(nullptr, "Confirm", "Successfully add to list!",QMessageBox::Ok | QMessageBox::Cancel);
    if (reply1 == QMessageBox::Cancel) return;
    model->addCommande(new CommandeModel(currentMenu->getName(), currentMenu->getPrix(), 1));
}
