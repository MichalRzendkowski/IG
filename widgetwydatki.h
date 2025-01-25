#ifndef WIDGETWYDATKI_H
#define WIDGETWYDATKI_H

#include "widget.h"
#include <QDate>

class WidgetWydatki: public Widget
{
public:
    WidgetWydatki(QString userName, float amount = 0, QFont font = QFont("Tahoma", 20), QString title = NULL, QDate date = QDate(), QWidget *parent = nullptr);
    void setTitle(QString title);
    void setDate(QDate date);

private:
    QString title;
    QDate date;
};

#endif // WIDGETWYDATKI_H
