#ifndef WIDGETROZLICZENIA_H
#define WIDGETROZLICZENIA_H

#include "widget.h"
#include <QDate>

class WidgetRozliczenia: public Widget
{
public:
    WidgetRozliczenia(QString userName, float amount = 0, QString userName2 = NULL, bool rozliczony = false, QWidget *parent = nullptr);
    void setUserName2(QString title);
    void setRozliczony(bool rozliczony);

private:
    QString userName2;
    bool rozliczony;
};

#endif // WIDGETROZLICZENIA_H
