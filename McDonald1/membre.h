#ifndef MEMBRE_H
#define MEMBRE_H
#include <QString>
#include <iostream>
#include <string>
#include <vector>
#include "plat.h"
#include "commandemodel.h"

/*Contient toutes les donnees necessaires pour representer un habitues*/
class Membre
{
private:
    QString name;
    int id;

    /*Listes des articles favoris*/
    std::vector<Plat*> * favoris;
    /*Listes des articles recommandes*/
    std::vector<Plat*> * recommendations;


public:
    Membre();
    QString getName();
    int getId();
    Membre(QString name, int id);
    std::vector<Plat*> * getFavoris();
    void addFavori(Plat * plat);
    std::vector<Plat*> * getRecommendations();
    void addRecommendation(Plat * plat);
};

#endif // MEMBRE_H
