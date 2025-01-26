#ifndef WIDGETRACHUNEK_H
#define WIDGETRACHUNEK_H
#include <QPushButton>
#include "rachunek.h"

class WidgetRachunek : public QPushButton
{
public:
    WidgetRachunek(Rachunek *rachunek, QWidget *parent = nullptr);
    Rachunek* getRachunek();

private:
    Rachunek *rachunek;
};

#endif // WIDGETRACHUNEK_H
