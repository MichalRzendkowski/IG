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

    QWidget* wydatek_1 = ui->wydatek1;
    QWidget* wydatek_2 = ui->wydatek2;
    QWidget* wydatek_3 = ui->wydatek3;

    QWidget* wydatek_1_2 = ui->wydatek1_2;
    QWidget* wydatek_2_2 = ui->wydatek2_2;
    QWidget* wydatek_3_2 = ui->wydatek3_2;


    wydatek_1->setVisible(false);
    wydatek_2->setVisible(false);
    wydatek_3->setVisible(false);
    wydatek_1_2->setVisible(false);
    wydatek_2_2->setVisible(false);
    wydatek_3_2->setVisible(false);

    // QStackedWidget* stacked_widget = ui->stackedWidget;
    // stacked_widget->setVisible(false);

    // Wydatki
    connect(ui->buttonDodajWydatki, &QPushButton::clicked, [widgetNowyWydatek]{
        widgetNowyWydatek->setVisible(true);
    });

    connect(ui->buttonDodajWydatek, &QPushButton::clicked, [wydatek_1]{
        wydatek_1->setVisible(true);
    });

    connect(ui->buttonWydatkiClose, &QPushButton::clicked, [widgetNowyWydatek]{
        widgetNowyWydatek->setVisible(false);
    });

    // Sposób podziału
    connect(ui->comboBoxSposobPodzialu, QOverload<int>::of(&QComboBox::currentIndexChanged),
            ui->stackedWidget, &QStackedWidget::setCurrentIndex);

    // Czlonkowie
    connect(ui->buttonDodajCzlonkowie, &QPushButton::clicked, [wydatek_1_2]{
        wydatek_1_2->setVisible(true);
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
