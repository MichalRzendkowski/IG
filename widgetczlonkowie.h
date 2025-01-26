#ifndef WIDGETCZLONKOWIE_H
#define WIDGETCZLONKOWIE_H

#include "widget.h"

class WidgetCzlonkowie : public Widget
{
public:
    WidgetCzlonkowie(QString userName, float amount = 0, QWidget *parent = nullptr);
    void setBalance(float amount);
    QString getName();
};

#endif // WIDGETCZLONKOWIE_H
