#include "rachunek.h"
#include "ui_rachunek.h"

#include <QPushButton>
#include <QGridLayout>
#include <QWidget>

Rachunek::Rachunek(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Rachunek)
{
    ui->setupUi(this);

    QWidget *widgetNowyWydatek = ui->widgetNowyWydatek;
    QWidget *widgetNowyCzlonek = ui->widgetNowyCzlonek;
    QWidget *widgetRozlicz = ui->widgetRozlicz;

    widgetNowyWydatek->setVisible(false);
    widgetNowyCzlonek->setVisible(false);
    widgetRozlicz->setVisible(false);

    // Wydatki
    connect(ui->buttonDodajWydatki, &QPushButton::clicked, [widgetNowyWydatek]{
        widgetNowyWydatek->setVisible(true);
    });

    connect(ui->buttonDodajWydatek, &QPushButton::clicked, [widgetNowyWydatek]{
        widgetNowyWydatek->setVisible(false);
    });

    connect(ui->buttonWydatkiClose, &QPushButton::clicked, [widgetNowyWydatek]{
        widgetNowyWydatek->setVisible(false);
    });

    // Sposób podziału
    connect(ui->comboBoxSposobPodzialu, QOverload<int>::of(&QComboBox::currentIndexChanged),
            ui->stackedWidget, &QStackedWidget::setCurrentIndex);

    // Czlonkowie
    connect(ui->buttonDodajCzlonkowie, &QPushButton::clicked, [widgetNowyCzlonek]{
        widgetNowyCzlonek->setVisible(true);
    });

    connect(ui->buttonCzlonkowieClose, &QPushButton::clicked, [widgetNowyCzlonek]{
        widgetNowyCzlonek->setVisible(false);
    });

    connect(ui->buttonDodajCzlonek, &QPushButton::clicked, [widgetNowyCzlonek]{
        widgetNowyCzlonek->setVisible(false);
    });

    // Rozliczenia

    connect(ui->buttonDodajRozliczenia, &QPushButton::clicked, [widgetRozlicz]{
        widgetRozlicz->setVisible(true);
    });

    connect(ui->buttonRozliczeniaClose, &QPushButton::clicked, [widgetRozlicz]{
        widgetRozlicz->setVisible(false);
    });

    connect(ui->buttonRozlicz, &QPushButton::clicked, [widgetRozlicz]{
        widgetRozlicz->setVisible(false);
    });

    connect(ui->buttonBack, &QPushButton::clicked, this, &Rachunek::rachunekClose);
}

Rachunek::~Rachunek(){}
