#ifndef RACHUNEK_H
#define RACHUNEK_H

#include <QWidget>
#include "widget.h"
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class Rachunek; }
QT_END_NAMESPACE

class Rachunek : public QWidget
{
    Q_OBJECT

public:
    explicit Rachunek(QWidget *parent = nullptr);
    ~Rachunek();

signals:
    void rachunekClose();

private:
    void setButtons();
    void setWidgets();
    void setWydatki();
    void updateWidgets();
    Ui::Rachunek *ui;
    QList<Widget*> wydatki = QList<Widget*>();
    QList<Widget*> czlonkowie = QList<Widget*>();
    QList<Widget*> rozliczenia = QList<Widget*>();
    QWidget *widgetNowyWydatek;
    QWidget *widgetNowyCzlonek;
    QWidget *widgetRozlicz;
};

#endif // RACHUNEK_H
