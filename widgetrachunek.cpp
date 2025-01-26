#include "widgetrachunek.h"
#include <QLabel>

WidgetRachunek::WidgetRachunek(Rachunek *rachunek, QWidget *parent) :
    QPushButton(parent), rachunek(rachunek){
    this->setFixedSize(QSize(180, 180));
    this->setFont(QFont("Tahoma", 30));
    this->setLayout(new QHBoxLayout());
    this->layout()->setAlignment(Qt::AlignCenter);
    this->layout()->addWidget(new QLabel(rachunek->getName()));
}

Rachunek* WidgetRachunek::getRachunek(){
    return rachunek;
}
