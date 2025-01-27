#include "widgetczlonkowie.h"
#include <QLabel>


WidgetCzlonkowie::WidgetCzlonkowie(QString userName, float amount, QWidget *parent) :
    Widget(userName, amount, parent) {
    QLabel *l1 = new QLabel(userName);
    //l1->setFont(FONT);
    layout->addWidget(new QLabel(userName));
    labelBalans = new QLabel("Balans " + QString(amount > 0 ? "+" : "") + QString::number(amount));
    layout->addWidget(labelBalans);
}

QString WidgetCzlonkowie::getName(){
    return userName;
}

float WidgetCzlonkowie::getBalance(){
    return amount;
}

void WidgetCzlonkowie::setBalance(float amount){
    this->amount = amount;
    labelBalans->setText("Balans " + QString(amount > 0 ? "+" : "") + QString::number(amount));
}
