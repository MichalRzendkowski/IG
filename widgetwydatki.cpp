#include "widgetwydatki.h"
#include <QLabel>

WidgetWydatki::WidgetWydatki(QString userName, float amount, QFont font, QString title, QDate date, QWidget *parent) :
    Widget(userName, amount, parent, font), title(title), date(date){
    layout->addWidget(new QLabel(title, this), 1);
    layout->addWidget(new QLabel(QString::number(amount) + " PLN", this), 1);
    layout->addWidget(new QLabel(userName, this), 1);
    layout->addWidget(new QLabel(date.toString(), this), 1);
}

void WidgetWydatki::setTitle(QString title){
    this->title = title;
}

void WidgetWydatki::setDate(QDate date){
    this->date = date;
}
