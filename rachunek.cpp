#include "rachunek.h"
#include "ui_rachunek.h"
#include "widgetczlonkowie.h"
#include "widgetwydatki.h"
#include "widgetrozliczenia.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>

Rachunek::Rachunek(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Rachunek)
{
    ui->setupUi(this);

    wydatki.append(new WidgetWydatki("Adam", 10, "Zakupy", QDate(2015, 12, 05)));
    wydatki.append(new WidgetWydatki("Kasia", 20, "Bar", QDate(2015, 11, 01)));

    czlonkowie.append(new WidgetCzlonkowie("Adam", -15));
    czlonkowie.append(new WidgetCzlonkowie("Kasia", 15));

    rozliczenia.append(new WidgetRozliczenia("Kasia", 2, "Adam", false));
    rozliczenia.append(new WidgetRozliczenia("Adam", 15, "Kasia", true));

    setWidgets();
    setButtons();
    updateWidgets();
}

void Rachunek::updateWidgets(){
    for(int i = 0; i < 3; i++){
        ui->tabWidget->widget(i)->setLayout(new QVBoxLayout());
        ui->tabWidget->widget(i)->layout()->setAlignment(Qt::AlignTop);
    }

    for(int i = 0; i < wydatki.size(); i++){
        ui->tabWidget->widget(0)->layout()->addWidget(wydatki[i]);
    }

    for(int i = 0; i < czlonkowie.size(); i++){
        ui->tabWidget->widget(1)->layout()->addWidget(czlonkowie[i]);
    }

    for(int i = 0; i < rozliczenia.size(); i++){
        ui->tabWidget->widget(2)->layout()->addWidget(rozliczenia[i]);
    }

}

void Rachunek::setWidgets(){
    this->widgetNowyWydatek = ui->widgetNowyWydatek;
    this->widgetNowyCzlonek = ui->widgetNowyCzlonek;
    this->widgetRozlicz     = ui->widgetRozlicz;

    widgetNowyWydatek->setVisible(false);
    widgetNowyCzlonek->setVisible(false);
    widgetRozlicz->setVisible(false);
}

void Rachunek::setButtons(){
    // Wydatki
    connect(ui->buttonDodajWydatki, &QPushButton::clicked, [this]{
        widgetNowyWydatek->setVisible(true);
    });

    connect(ui->buttonDodajWydatek, &QPushButton::clicked, [this]{
        widgetNowyWydatek->setVisible(false);
    });

    connect(ui->buttonWydatkiClose, &QPushButton::clicked, [this]{
        widgetNowyWydatek->setVisible(false);
    });

    // Sposób podziału
    connect(ui->comboBoxSposobPodzialu, QOverload<int>::of(&QComboBox::currentIndexChanged),
            ui->stackedWidget, &QStackedWidget::setCurrentIndex);

    // Czlonkowie
    connect(ui->buttonDodajCzlonkowie, &QPushButton::clicked, [this]{
        widgetNowyCzlonek->setVisible(true);
    });

    connect(ui->buttonCzlonkowieClose, &QPushButton::clicked, [this]{
        widgetNowyCzlonek->setVisible(false);
    });

    connect(ui->buttonDodajCzlonek, &QPushButton::clicked, [this]{
        widgetNowyCzlonek->setVisible(false);
    });

    // Rozliczenia
    connect(ui->buttonDodajRozliczenia, &QPushButton::clicked, [this]{
        widgetRozlicz->setVisible(true);
    });

    connect(ui->buttonRozliczeniaClose, &QPushButton::clicked, [this]{
        widgetRozlicz->setVisible(false);
    });

    connect(ui->buttonRozlicz, &QPushButton::clicked, [this]{
        widgetRozlicz->setVisible(false);
    });

    connect(ui->buttonBack, &QPushButton::clicked, this, &Rachunek::rachunekClose);
}

Rachunek::~Rachunek(){}
