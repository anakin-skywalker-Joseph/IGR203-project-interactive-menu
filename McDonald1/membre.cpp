#include "membre.h"

Membre::Membre()
{

}

Membre::Membre(QString name, int id){
    this->name = name;
    this->id = id;
    this->favoris = new std::vector<Plat*>();
    this->recommendations = new std::vector<Plat*>();
}


int Membre::getId(){
    return id;
}

QString Membre::getName(){
    return name;
}

void Membre::addFavori(Plat *plat){
    favoris->push_back(plat);
}

std::vector<Plat*> * Membre::getFavoris(){
    return favoris;
}

void Membre::addRecommendation(Plat *plat){
    recommendations->push_back(plat);
}

std::vector<Plat*> * Membre::getRecommendations(){
    return recommendations;
}
