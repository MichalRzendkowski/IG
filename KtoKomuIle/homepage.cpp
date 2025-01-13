#include "homepage.h"
#include "ui_homepage.h"

#include <QPushButton>
#include <QGridLayout>



HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomePage)
{
    ui->setupUi(this);

    QWidget *widgetNowyRachunek = ui->widgetNowyRachunek;

    QPushButton* przycisk = ui->buttonRachunek3;
    przycisk->setVisible(false);

    widgetNowyRachunek->setVisible(false);

    connect(ui->buttonDodaj, &QPushButton::clicked, [widgetNowyRachunek]() {
        widgetNowyRachunek->setVisible(true);
    });

    connect(ui->buttonZamknij, &QPushButton::clicked, [widgetNowyRachunek]() {
        widgetNowyRachunek->setVisible(false);
    });

    connect(ui->buttonDolacz, &QPushButton::clicked, [widgetNowyRachunek]() {
        widgetNowyRachunek->setVisible(false);
    });

    connect(ui->buttonUtworz, &QPushButton::clicked, [widgetNowyRachunek, przycisk]() {
        widgetNowyRachunek->setVisible(false);
        przycisk->setVisible(true);
    });

    connect(ui->buttonRachunek3, &QPushButton::clicked, this, &HomePage::rachunekOpen);

    // connect(ui->buttonRachunek1, &QPushButton::clicked, this, &HomePage::rachunekOpen);

    // connect(ui->buttonRachunek2, &QPushButton::clicked, this, &HomePage::rachunekOpen);
}

HomePage::~HomePage(){}
