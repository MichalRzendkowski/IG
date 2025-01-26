#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QGridLayout>
#include "widgetrachunek.h"
#include "rachunek.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HomePage; }
QT_END_NAMESPACE

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    void updateRachunki();
    ~HomePage();

signals:
    void rachunekOpen(Rachunek *rachunek);

private:
    QList<WidgetRachunek*> rachunki = QList<WidgetRachunek*>();
    Ui::HomePage *ui;
};

#endif // HOMEPAGE_H
