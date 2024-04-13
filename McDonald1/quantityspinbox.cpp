#include "quantityspinbox.h"
#include <QBoxLayout>
#include "commandemodel.h"
#include <iostream>
#include <QMessageBox>

QuantitySpinBox::QuantitySpinBox(Model * m, Membre * memb, Plat * p, QString & infos) : QWidget()
{
       model = m;
       membre = memb;
       plat = p;
       commande_info = infos;
       QHBoxLayout * layout = new QHBoxLayout(this);
       quantity =  new QSpinBox();
       quantity->setValue(1);
       quantity->setMinimumHeight(50);
       quantity->setRange(0, 20);
       quantity->setSuffix(tr(" unite(s)"));
       layout->addWidget(quantity);
}

void QuantitySpinBox::validateQuantity(QString & infos) {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "Successfully add to list!",
                                  QMessageBox::Ok | QMessageBox::Cancel);
    if (reply == QMessageBox::Cancel) return;
    int nbUnite = quantity->value();
    if (!infos.isEmpty()){
        infos = "No " + infos;
    }
    if (nbUnite > 0) {
        CommandeModel * cm = new CommandeModel(plat->getLabel(), plat->getPrix(), nbUnite);
        model->addCommande(cm);
        cm->setInfos(infos);
    }
}
