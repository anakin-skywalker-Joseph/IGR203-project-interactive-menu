#include "catalogueitem.h"

CatalogueItem::CatalogueItem(Template * temp, Plat * p, bool _inMenu) : QToolButton(){
    plat = p;
    inMenu = _inMenu;
    setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    setIcon(QIcon(plat->getImageFile()));
    setIconSize(QSize(200, 150));
    if (inMenu) {
        setText(plat->getLabel());
    }
    else {
        setText(QString("%1 \n %2 euros").arg(plat->getLabel()).arg(plat->getPrix()));
    }

    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum));
    setStyleSheet("color : black; background-color : #FFECB3  ;");
    connect(this, SIGNAL(clicked()), this, SLOT(sendDetailSignal()));
    connect(this, SIGNAL(detailRequis(Plat*,int)), temp, SLOT(displayDetail(Plat*,int)));
}



void CatalogueItem::sendDetailSignal() {
    if (!inMenu) emit detailRequis(plat,0);
    else emit detailRequis(plat,1);
}
