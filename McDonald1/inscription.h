//Julien
#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QWidget>
#include <QLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QToolButton>
#include <QPushButton>
#include <QScrollArea>
#include <iostream>

#include "model.h"
#include "template.h"

class Inscription : public QWidget
{
    Q_OBJECT
private:
    Model* model;
    QLineEdit * nomCompteLineEdit;
    QLineEdit * passwordLineEdit;

public:
    explicit Inscription(Template *parent = nullptr, Model * m = nullptr);
};

#endif // INSCRIPTION_H
