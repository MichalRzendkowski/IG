#include "widgetrozliczenia.h"
#include "widget.h"
#include <QLabel>

WidgetRozliczenia::WidgetRozliczenia(QString userName, float amount, QString userName2, bool rozliczony, QWidget *parent) :
    Widget(userName, amount, parent), userName2(userName2), rozliczony(rozliczony){
    layout->addWidget(new QLabel(userName));
    layout->addWidget(new QLabel(QString(rozliczony ? "zwraca" : "jest winny/a")));
    layout->addWidget(new QLabel(userName2));
    layout->addWidget(new QLabel(QString::number(amount) + " PLN"));
}

void WidgetRozliczenia::setUserName2(QString userName2){
    this->userName2 = userName2;
}
void WidgetRozliczenia::setRozliczony(bool rozliczony){
    this->rozliczony = rozliczony;

}
