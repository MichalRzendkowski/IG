#include "widgetczlonkowie.h"
#include <QLabel>


WidgetCzlonkowie::WidgetCzlonkowie(QString userName, float amount, QWidget *parent) :
    Widget(userName, amount, parent) {
    QLabel *l1 = new QLabel(userName);
    l1->setFont(FONT);
    layout->addWidget(new QLabel(userName));
    layout->addWidget(new QLabel("Balans " + QString(amount > 0 ? "+" : "") + QString::number(amount)));
}
