#ifndef WIDGETCZLONKOWIE_H
#define WIDGETCZLONKOWIE_H

#include "widget.h"

class WidgetCzlonkowie : public Widget
{
public:
    WidgetCzlonkowie(QString userName, float amount = 0, QWidget *parent = nullptr, QFont font = QFont("Tahoma", 20));
    void setBalance(float amount);
};

#endif // WIDGETCZLONKOWIE_H
