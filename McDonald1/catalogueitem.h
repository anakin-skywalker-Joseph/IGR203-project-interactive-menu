#ifndef CATALOGUEITEM_H
#define CATALOGUEITEM_H

#include <QToolButton>
#include "plat.h"
#include "catalogue.h"
#include "template.h"
#include "model.h"

/*Cet classe est celle qui permet d'afficher les articles de la carte sous la forme de bouton rectangulaire
contenant une image de l'article et un label affichant son nom et son prix*/
class CatalogueItem : public QToolButton
{
    Q_OBJECT
public:
    explicit CatalogueItem(Template * parent = nullptr, Plat * plat = nullptr, bool _inMenu = false);
    virtual ~CatalogueItem() {}
    const Plat * getPlat() {return plat;}
    void setInMenu(bool b) {inMenu = b;}

signals:
    void detailRequis(Plat * p, int i);

public slots:
   void sendDetailSignal();

private:
    Plat* plat = nullptr;

    Model * model = nullptr;

    bool inMenu = false;
};

#endif // CATALOGUEITEM_H

