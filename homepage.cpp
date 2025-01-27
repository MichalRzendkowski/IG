#include "homepage.h"
#include "ui_homepage.h"

#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomePage)
{
    ui->setupUi(this);

    QWidget *widgetNowyRachunek = ui->widgetNowyRachunek;

    widgetNowyRachunek->setVisible(false);

    connect(ui->buttonDodaj, &QPushButton::clicked, [widgetNowyRachunek]() {
        widgetNowyRachunek->setVisible(true);
    });

    connect(ui->buttonZamknij, &QPushButton::clicked, [widgetNowyRachunek]() {
        widgetNowyRachunek->setVisible(false);
    });

    connect(ui->buttonDolacz, &QPushButton::clicked, [this, widgetNowyRachunek]() {
        QMessageBox msgBox;
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setText("Nieprawidłowy kod");
        msgBox.exec();
    });

    connect(ui->buttonUtworz, &QPushButton::clicked, [this, widgetNowyRachunek]() {
        QMessageBox msgBox;
        msgBox.setStandardButtons(QMessageBox::Ok);

        if(ui->lineEditNazwa->text().isEmpty()){
            msgBox.setText("Podaj nazwę rachunku");
            msgBox.exec();
            return;
        }

        if(rachunki.length() == 6){
            msgBox.setText("Osiągnięto maksymalną liczbę rachunków");
            msgBox.exec();
            return;
        }

        this->rachunki.append(new WidgetRachunek(new Rachunek(this->ui->lineEditNazwa->text())));
        updateRachunki();
        widgetNowyRachunek->setVisible(false);
    });
}

void HomePage::updateRachunki(){
    delete ui->widgetRachunki->layout();
    QGridLayout* layout = new QGridLayout();
    layout->setAlignment({Qt::AlignLeft, Qt::AlignTop});
    ui->widgetRachunki->setLayout(layout);
    for(int i = 0; i < rachunki.size(); i++){
        layout->addWidget(rachunki[i], i/2, i%2);
        connect(rachunki[i], &QPushButton::clicked, [this, i](){
            emit rachunekOpen(rachunki[i]->getRachunek());
        });
    }
}

HomePage::~HomePage(){}
