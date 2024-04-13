#include "model.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QDir>
#include <QCoreApplication>
Model::Model(){
    Membre * farida = new Membre("Farida", 1);
    Famille * safi = new Famille("Safi", "password");
    safi->addMembre(farida);
    clients.push_back(safi);
    indiceFamilleCourante = 0;
    QString currentDir = QDir::currentPath();
    QString filename = "/../menu.json";
    QString filePath = currentDir + filename;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open the file" << filePath;
        return;
    }

    QString jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData.toUtf8());
    QJsonObject jsonObject = document.object();

    //Entrées
    QString nom, fichierImage, description;
    int id;
    double prix;
    Plat * e1 = nullptr;
    QJsonArray entree = jsonObject.value("sides").toArray();
    foreach (const QJsonValue &value, entree) {
        QJsonArray value_str = value.toArray();
        id = value_str.at(0).toInt();
        nom = value_str.at(1).toString();
        fichierImage = value_str.at(2).toString();
        prix = value_str.at(3).toDouble();
        description = value_str.at(4).toString();
        e1 = new Plat(id);
        e1->setLabel(nom);
        e1->setImageFile(fichierImage);
        e1->setPrix(prix);
        e1->setDescription(description);
        addSides(e1);
        carteEntiere.push_back(e1);
    }

    QJsonArray plat = jsonObject.value("burger").toArray();
    foreach (const QJsonValue &value, plat) {
        QJsonArray value_str = value.toArray();
        id = value_str.at(0).toInt();
        nom = value_str.at(1).toString();
        fichierImage = value_str.at(2).toString();
        prix = value_str.at(3).toDouble();
        description = value_str.at(4).toString();
        e1 = new Plat(id);
        e1->setLabel(nom);
        e1->setImageFile(fichierImage);
        e1->setPrix(prix);
        e1->setDescription(description);
        addBurger(e1);
        carteEntiere.push_back(e1);
    }

    QJsonArray dessert = jsonObject.value("desert").toArray();
    foreach (const QJsonValue &value, dessert) {
        QJsonArray value_str = value.toArray();
        id = value_str.at(0).toInt();
        nom = value_str.at(1).toString();
        fichierImage = value_str.at(2).toString();
        prix = value_str.at(3).toDouble();
        description = value_str.at(4).toString();
        e1 = new Plat(id);
        e1->setLabel(nom);
        e1->setImageFile(fichierImage);
        e1->setPrix(prix);
        e1->setDescription(description);
        addDessert(e1);
        carteEntiere.push_back(e1);
    }


    QJsonArray boisson = jsonObject.value("drink").toArray();
    foreach (const QJsonValue &value, boisson) {
        QJsonArray value_str = value.toArray();
        id = value_str.at(0).toInt();
        nom = value_str.at(1).toString();
        fichierImage = value_str.at(2).toString();
        prix = value_str.at(3).toDouble();
        description = value_str.at(4).toString();
        e1 = new Plat(id);
        e1->setLabel(nom);
        e1->setImageFile(fichierImage);
        e1->setPrix(prix);
        e1->setDescription(description);
        addBoisson(e1);
        carteEntiere.push_back(e1);
    }

//    //Menus
    MenuModel * m1 = new MenuModel("Combo 1", 15);
    m1->addMenuSides(carteSides[0]);
    m1->addMenuSides(carteSides[3]);
    m1->addMenuBurger(carteBurger[0]);
    m1->addMenuBurger(carteBurger[3]);
    m1->addMenuDessert(carteBoissons[0]);
    m1->addMenuDessert(carteBoissons[1]);
    addMenu(m1);

    MenuModel * m2 = new MenuModel("Combo 2", 18);
    m2->addMenuSides(carteSides[1]);
    m2->addMenuSides(carteSides[2]);
    m2->addMenuBurger(carteBurger[1]);
    m2->addMenuBurger(carteBurger[2]);
    m2->addMenuDessert(carteBoissons[0]);
    m2->addMenuDessert(carteBoissons[4]);
    addMenu(m2);

    MenuModel * m3 = new MenuModel("Combo 3", 20);
    m3->addMenuSides(carteSides[4]);
    m3->addMenuSides(carteSides[5]);
    m3->addMenuBurger(carteBurger[5]);
    m3->addMenuBurger(carteBurger[6]);
    m3->addMenuDessert(carteBoissons[2]);
    m3->addMenuDessert(carteBoissons[3]);
    addMenu(m3);

    for(unsigned int i = 0; i+3<carteEntiere.size(); i+=4){
        farida->addFavori(carteEntiere[i]);
        farida->addRecommendation(carteEntiere[i]);
    }
}

void Model::addDessert(Plat *dessert){
    carteDesserts.push_back(dessert);
}

void Model::addBurger(Plat * plat){
    carteBurger.push_back(plat);
}

void Model::addSides(Plat *entree){
    carteSides.push_back(entree);
}

void Model::addBoisson(Plat *boisson){
    carteBoissons.push_back(boisson);
}


void Model::addMenu(MenuModel *menu){
    carteMenus.push_back(menu);
}

std::vector<Plat*> Model::getSides(){
    if (is_filter()) {
        std::vector<Plat*> slice(carteSides.begin(), carteSides.begin() + 5);
        return slice;
    }
    return carteSides;
}

std::vector<Plat*> Model::getBoissons(){
    if (is_filter()) {
        std::vector<Plat*> slice(carteBoissons.begin(), carteBoissons.begin() + 3);
        return slice;
    }
    return carteBoissons;
}

std::vector<Plat*> Model::getBurger(){
    if (is_filter()) {
        std::vector<Plat*> slice(carteBurger.begin(), carteBurger.begin() + 6);
        return slice;
    }
    return carteBurger;
}

std::vector<Plat*> Model::getDesserts(){
    if (is_filter()) {
        std::vector<Plat*> slice(carteDesserts.begin(), carteDesserts.begin() + 3);
        return slice;
    }
    return carteDesserts;
}

std::vector<MenuModel*> Model::getMenus(){
    return carteMenus;
}

std::vector<Plat*>  Model::getCarteEntiere() {
    return carteEntiere;
}

QFont Model::getTitleFont(){
    return QFont("Helvetica", 30, QFont::Bold);
}

QFont Model::getAccueilButtonFont(){
    return QFont("Helvetica", 15, QFont::Bold);
}

QFont Model::getButtonFont(){
    return QFont("Helvetica", 20, QFont::Bold);
}

QFont Model::getTextFont(){
    return QFont("Helvetica", 15);
}

QFont Model::getPlatFont(){
    return QFont("Helvetica", 12);
}

std::vector<Famille*> Model::getClients(){
    return clients;
}

void Model::addFamille(Famille * famille){
    clients.push_back(famille);
}

int Model::getIndiceFamilleCourante(){
    return indiceFamilleCourante;
}

void Model::setIndiceFamilleCourante(int indice){
    indiceFamilleCourante = indice;
}

void Model::addCommande(CommandeModel * cm){
    listeCommandes.push_back(cm);
}

void Model::setTotal(float t){
    total = t;
}

void Model::calculateTotal(){
    total = 0;
    for(unsigned int i = 0; i < listeCommandes.size(); i++){
        CommandeModel * cm = listeCommandes[i];
        int quantity = cm->getNbUnites();
        total += cm->getItemPrice()*quantity;
    }
}

void Model::clear() {
    setConnected(false);
    listeCommandes.clear();

}
