#ifndef RACHUNEK_H
#define RACHUNEK_H

#include <QWidget>
#include "widgetwydatki.h"
#include "widgetczlonkowie.h"
#include "widgetrozliczenia.h"
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QSpinBox>

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
    void updateSposobRozliczenia();
    void setButtons();
    void setWidgets();
    void setWydatki();
    void updateWidgets();
    void setPodzialy();
    void addWydatek();
    void simplify();
    WidgetCzlonkowie* getCzlonek(QString name);

    Ui::Rachunek *ui;

    QList<QPair<QLabel*, QCheckBox*>> listPoRowno;
    QList<QPair<QLabel*, QSpinBox*>> listUdzialy;
    QList<QPair<QLabel*, QLineEdit*>> listKwoty;

    QList<WidgetWydatki*> wydatki = QList<WidgetWydatki*>();
    QList<WidgetCzlonkowie*> czlonkowie = QList<WidgetCzlonkowie*>();
    QList<WidgetRozliczenia*> rozliczenia = QList<WidgetRozliczenia*>();

    QWidget *widgetNowyWydatek;
    QWidget *widgetNowyCzlonek;
    QWidget *widgetRozlicz;
    QString name;
};

#endif // RACHUNEK_H
