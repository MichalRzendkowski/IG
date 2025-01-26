#include "rachunek.h"
#include "ui_rachunek.h"
#include "widgetczlonkowie.h"
#include "widgetwydatki.h"
#include "widgetrozliczenia.h"

#include <QMessageBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>

Rachunek::Rachunek(QString name, QWidget *parent)
    : QWidget(parent), name(name), ui(new Ui::Rachunek)
{
    ui->setupUi(this);
    ui->labelNazwa->setText(name);

    setWidgets();
    setButtons();
    updateWidgets();
}

void Rachunek::updateWidgets(){

    QList<QLabel *> Labels = ui->tabWidget->widget(2)->findChildren<QLabel *>();
    foreach(QLabel * child, Labels)
    {
        if(child->text() == "Uproszczone należności" || child->text() == "Historia rozliczeń" || child->text() == "brak")
        delete child;
    }

    for(int i = 0; i < 3; i++){
        delete ui->tabWidget->widget(i)->layout();
        ui->tabWidget->widget(i)->setLayout(new QVBoxLayout());
        ui->tabWidget->widget(i)->layout()->setAlignment({Qt::AlignTop, Qt::AlignCenter});
    }

    for(int i = 0; i < wydatki.size(); i++){
        ui->tabWidget->widget(0)->layout()->addWidget(wydatki[i]);
        wydatki[i]->lower();
    }

    ui->comboBoxKtoZaplacil->clear();
    ui->comboBoxKomuOddaje->clear();
    ui->comboBoxKtoOddaje->clear();

    for(int i = 0; i < czlonkowie.size(); i++){
        ui->tabWidget->widget(1)->layout()->addWidget(czlonkowie[i]);
        czlonkowie[i]->lower();
        ui->comboBoxKtoZaplacil->addItem(czlonkowie[i]->getName());
        ui->comboBoxKomuOddaje->addItem(czlonkowie[i]->getName());
        ui->comboBoxKtoOddaje->addItem(czlonkowie[i]->getName());
    }

    auto l1 = new QLabel("Uproszczone należności");
    ui->tabWidget->widget(2)->layout()->addWidget(l1);
    l1->lower();
    l1->setFont(QFont("Tahoma", 20, QFont::Bold));
    int c = 0;
    for(int i = 0; i < rozliczenia.size(); i++){
        if(!rozliczenia[i]->getRozliczony()){
            ui->tabWidget->widget(2)->layout()->addWidget(rozliczenia[i]);
            rozliczenia[i]->lower();
            c++;
        }
    }

    if(c == 0){
        auto lb = new QLabel("brak");
        ui->tabWidget->widget(2)->layout()->addWidget(lb);
        lb->lower();
    }

    auto l2 = new QLabel("Historia rozliczeń");
    ui->tabWidget->widget(2)->layout()->addWidget(l2);
    l2->setFont(QFont("Tahoma", 20, QFont::Bold));
    l2->lower();
    c = 0;
    for(int i = 0; i < rozliczenia.size(); i++){
        if(rozliczenia[i]->getRozliczony()){
            ui->tabWidget->widget(2)->layout()->addWidget(rozliczenia[i]);
            rozliczenia[i]->lower();
            c++;
        }
    }
    if(c == 0){
        auto lb = new QLabel("brak");
        ui->tabWidget->widget(2)->layout()->addWidget(lb);
        lb->lower();
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
        QMessageBox msgBox;
        msgBox.setStandardButtons(QMessageBox::Ok);

        if(czlonkowie.empty()){
            msgBox.setText("Brak członków w rachunku");
            msgBox.exec();
            return;
        }

        if(ui->nazwa->text().isEmpty()){
            msgBox.setText("Podaj nazwę wydatku");
            msgBox.exec();
            return;
        }

        if(ui->nazwa_2->text().isEmpty()){
            msgBox.setText("Podaj kwotę wydatku");
            msgBox.exec();
            return;
        }

        bool isNumeric = false;
        ui->nazwa_2->text().toDouble(&isNumeric);
        if(!isNumeric){
            msgBox.setText("Nieprawidłowa kwota wydatku");
            msgBox.exec();
            return;
        }

        wydatki.append(new WidgetWydatki(ui->comboBoxKtoZaplacil->currentText(), ui->nazwa_2->text().toFloat(), ui->nazwa->text(), ui->dateEdit->date()));
        updateWidgets();
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
        QMessageBox msgBox;
        msgBox.setStandardButtons(QMessageBox::Ok);

        if(ui->lineEdit_2->text().isEmpty()){
            msgBox.setText("Podaj imię członka");
            msgBox.exec();
            return;
        }

        for(int i = 0; i < czlonkowie.length(); i++){
            if(ui->lineEdit_2->text() == czlonkowie[i]->getName()){
                msgBox.setText("Członek o takim imieniu już istnieje");
                msgBox.exec();
                return;
            }
        }

        czlonkowie.append(new WidgetCzlonkowie(ui->lineEdit_2->text()));
        updateWidgets();
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
        QMessageBox msgBox;
        msgBox.setStandardButtons(QMessageBox::Ok);

        if(czlonkowie.empty()){
            msgBox.setText("Brak członków w rachunku");
            msgBox.exec();
            return;
        }

        if(ui->lineEditKwota->text().isEmpty()){
            msgBox.setText("Wpisz kwotę");
            msgBox.exec();
            return;
        }

        if(ui->comboBoxKomuOddaje->currentText() == ui->comboBoxKtoOddaje->currentText()){
            msgBox.setText("Nie można rozliczyć się z samym sobą");
            msgBox.exec();
            return;
        }

        rozliczenia.append(new WidgetRozliczenia(ui->comboBoxKomuOddaje->currentText(), ui->lineEditKwota->text().toFloat(), ui->comboBoxKtoOddaje->currentText(), true));
        updateWidgets();
        widgetRozlicz->setVisible(false);
    });

    connect(ui->buttonBack, &QPushButton::clicked, this, &Rachunek::rachunekClose);
}

QString Rachunek::getName(){
    return name;
}

Rachunek::~Rachunek(){}
