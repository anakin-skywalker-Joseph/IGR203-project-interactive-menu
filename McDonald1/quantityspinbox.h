#ifndef QUANTITYSPINBOX_H
#define QUANTITYSPINBOX_H

#include <QWidget>
#include "membre.h"
#include "model.h"
#include <QSpinBox>
#include "plat.h"
#include <QLineEdit>

/*Correspond au spin box permettant d'attribuer l'article commande dans la vue detail*/
class QuantitySpinBox : public QWidget
{
    Q_OBJECT
private:
    Membre * membre = nullptr;
    Model * model = nullptr;
    QSpinBox * quantity =nullptr;
    Plat * plat = nullptr;
    QString commande_info = "";

public:
    QuantitySpinBox(Model * m, Membre * memb, Plat * p, QString & infos);
    virtual ~QuantitySpinBox() {}

signals:

public slots:
    void validateQuantity(QString & infos);
};

#endif // QUANTITYSPINBOX_H
