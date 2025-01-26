#ifndef RACHUNEK_H
#define RACHUNEK_H

#include <QWidget>
#include "widget.h"
#include "widgetwydatki.h"
#include "widgetczlonkowie.h"
#include "widgetrozliczenia.h"
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class Rachunek; }
QT_END_NAMESPACE

class Rachunek : public QWidget
{
    Q_OBJECT

public:
    explicit Rachunek(QString name, QWidget *parent = nullptr);
    QString getName();
    ~Rachunek();

signals:
    void rachunekClose();

private:
    void setButtons();
    void setWidgets();
    void setWydatki();
    void updateWidgets();
    Ui::Rachunek *ui;
    QList<WidgetWydatki*> wydatki = QList<WidgetWydatki*>();
    QList<WidgetCzlonkowie*> czlonkowie = QList<WidgetCzlonkowie*>();
    QList<WidgetRozliczenia*> rozliczenia = QList<WidgetRozliczenia*>();
    QWidget *widgetNowyWydatek;
    QWidget *widgetNowyCzlonek;
    QWidget *widgetRozlicz;
    QString name;
};

#endif // RACHUNEK_H
