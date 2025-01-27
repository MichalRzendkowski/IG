#ifndef WIDGETCZLONKOWIE_H
#define WIDGETCZLONKOWIE_H

#include "widget.h"
#include <QLabel>

class WidgetCzlonkowie : public Widget
{
public:
    WidgetCzlonkowie(QString userName, float amount = 0, QWidget *parent = nullptr);
    void setBalance(float amount);
    float getBalance();
    QString getName();

private:
    QLabel* labelBalans;
};

#endif // WIDGETCZLONKOWIE_H
