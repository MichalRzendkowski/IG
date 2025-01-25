#include "widgetczlonkowie.h"
#include <QLabel>


WidgetCzlonkowie::WidgetCzlonkowie(QString userName, float amount, QWidget *parent, QFont font) :
    Widget(userName, amount, parent, font) {
    layout->addWidget(new QLabel(userName));
    layout->addWidget(new QLabel("Balans " + QString(amount > 0 ? "+" : "") + QString::number(amount)));
}
